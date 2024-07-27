#ifndef _POOL2D_H_
#define _POOL2D_H_

#include "config.h"
#include "tensor.h"
#include <riscv_matrix.h>

void maxpool2d(Tensor *dst, Tensor *src, Pool2dConfig *cfg) {
  float *fmap = (float *)src->data;
  float *dist = (float *)dst->data;
  int sh = cfg->stride[0], sw = cfg->stride[1];
  int dh = cfg->dilation[0], dw = cfg->dilation[1];
  int pt = cfg->padding[0], pb = cfg->padding[1], pl = cfg->padding[2],
      pr = cfg->padding[3];
  int kh = cfg->kernel_size[0], kw = cfg->kernel_size[1];
  int inh = src->shape[1], inw = src->shape[2], inc = src->shape[3];
  int outh = dst->shape[1], outw = dst->shape[2], outc = dst->shape[3];
  const int M = outh * outw;
  const int N = outc;
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
      out = mfmv_s_f(out, -100, 0);
      out = mbcce_m(out);
      for (int hi = 0; hi < kh; ++hi) {
        int inh_pos = outh_pos * sh - pt + hi * dh;

        for (int wi = 0; wi < kw; ++wi) {
          int inw_pos = outw_pos * sw - pl + wi * dw;
          msetsk(inh_pos << 16 | (inw_pos & 0xffff),
                 (wi * dw) << 16 | outw_pos);
          mfloat32m1_t tr0 =
              mlufce32_m(fmap + inh_pos * inw * inc + inw_pos * inc + n,
                         inc * sizeof(float));
          out = mfmax_mm(out, tr0);
        }
      }
      msce32_m(out, dist + m * N + n, N * sizeof(float));
    }
  }
}

void avgpool2d(Tensor *dst, Tensor *src, Pool2dConfig *cfg) {
  float *fmap = (float *)src->data;
  float *dist = (float *)dst->data;
  int sh = cfg->stride[0], sw = cfg->stride[1];
  int dh = cfg->dilation[0], dw = cfg->dilation[1];
  int pt = cfg->padding[0], pb = cfg->padding[1], pl = cfg->padding[2],
      pr = cfg->padding[3];
  int kh = cfg->kernel_size[0], kw = cfg->kernel_size[1];
  int inh = src->shape[1], inw = src->shape[2], inc = src->shape[3];
  int outh = dst->shape[1], outw = dst->shape[2], outc = dst->shape[3];
  const int M = outh * outw;
  const int N = outc;
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
      mfloat32m1_t dividend;
      dividend = mfmv_s_f(dividend, kh * kw, 0);
      dividend = mbcce_m(dividend);

      for (int hi = 0; hi < kh; ++hi) {
        int inh_pos = outh_pos * sh - pt + hi * dh;

        for (int wi = 0; wi < kw; ++wi) {
          int inw_pos = outw_pos * sw - pl + wi * dw;
          msetsk(inh_pos << 16 | (inw_pos & 0xffff),
                 (wi * dw) << 16 | outw_pos);
          mfloat32m1_t tr0 =
              mlufce32_m(fmap + inh_pos * inw * inc + inw_pos * inc + n,
                         inc * sizeof(float));
          out = mfadd_mm(out, tr0);
        }
      }
      out = mfdiv_mm(out, dividend);
      msce32_m(out, dist + m * N + n, N * sizeof(float));
    }
  }
}
#endif // _POOL2D_H_