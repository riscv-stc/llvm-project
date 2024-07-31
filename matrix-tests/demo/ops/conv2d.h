#ifndef _CONV2D_H_
#define _CONV2D_H_

#include "config.h"
#include "tensor.h"
#include <riscv_matrix.h>

void conv2d(Tensor *dist, Tensor *src1, Tensor *src2, Conv2dConfig *cfg) {
  float *src1_ptr = (float *)src1->data;
  float *dist_ptr = (float *)dist->data;
  float *src2_ptr = (float *)src2->data;
  int sh = cfg->stride[0], sw = cfg->stride[1];
  int dh = cfg->dilation[0], dw = cfg->dilation[1];
  int pt = cfg->padding[0], pb = cfg->padding[1], pl = cfg->padding[2],
      pr = cfg->padding[3];
  int kh = cfg->kernel_size[0], kw = cfg->kernel_size[1];
  int inh = src1->shape[1], inw = src1->shape[2], inc = src1->shape[3];
  int outh = dist->shape[1], outw = dist->shape[2], outc = dist->shape[3];
  const int M = outh * outw;
  const int K = inc * kh * kw;
  const int N = dist->shape[3];
  int tile_m, tile_k, tile_n;
  msettype(E32, M1, BA);
  msetoutsh(outh << 16 | outw, dh << 24 | dw << 16 | sh << 8 | sw);
  msetinsh(inh << 16 | inw, pt << 24 | pb << 16 | pl << 8 | pr);
  msetpadval(0);

  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);
    int outh_pos = m / outw;
    int outw_pos = m % outw;

    for (int n = 0; n < N; n += tile_n) {
      tile_n = msettilen(N - n);
      mfloat32m1_t out;
      out = mfsub_mm(out, out);

      for (int hi = 0; hi < kh; hi++) {
        int inh_pos = outh_pos * sh - pt + hi * dh;

        for (int wi = 0; wi < kw; wi++) {
          int inw_pos = outw_pos * sw - pl + wi * dw;
          msetsk(inh_pos << 16 | (inw_pos & 0xFFFF),
                 (wi * dw) << 16 | outw_pos);
          float *fmap = src1_ptr + inh_pos * inw * inc + inw_pos * inc;
          float *weight =
              src2_ptr + hi * kw * inc * outc + wi * inc * outc + n;

          for (int ci = 0; ci < inc; ci += tile_k) {
            tile_k = msettilek(inc - ci);
            mfloat32m1_t tr0 = mlufae32_m(fmap + ci, inc * sizeof(float));
            mfloat32m1_t tr1 =
                mlbe32_m1(weight + ci * outc, outc * sizeof(float));
            out = mfma_mm(out, tr0, tr1);
          }
        }
      }
      msce32_m(out, dist_ptr + m * N + n, N * sizeof(float));
    }
  }
}

#endif // _CONV2D_H_