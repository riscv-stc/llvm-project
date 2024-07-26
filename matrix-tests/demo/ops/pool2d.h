#ifndef MATRIX_TESTS_DEMO_OPS_POOL_H_
#define MATRIX_TESTS_DEMO_OPS_POOL_H_

#include "../tensor.h"
#include "config.h"
#include <riscv_matrix.h>

void maxpool2d(Tensor *dst, Tensor *src, int kernel_size, int stride,
               int padding, int dilation) {
  const int outh = dst->shape[0];
  const int outw = dst->shape[1];
  const int M = outh * outw;
  const int N = dst->shape[2];
  int tile_m, tile_n;
  msettype(E32, M1, BA);
  msetoutsh(outh << 16 | outw,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(src->shape[0] << 16 | src->shape[1],
           padding << 24 | padding << 16 | padding << 8 | padding);

  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);
    int outh_pos = m / outw;
    int outw_pos = m % outw;

    for (int n = 0; n < N; n += tile_n) {
      tile_n = msettilen(N - n);

      mfloat32m1_t out = mlce32_m1((float *)dst->data + m * dst->shape[2] + n,
                                   dst->shape[2] * sizeof(float));
      out = mfmv_s_f(out, 0xFF800000, 0);
      out = mbcce_m(out);
      for (int ki = 0; ki < kernel_size; ki++) {
        int inh_pos = outh_pos * stride - padding + ki * dilation;
        for (int wi = 0; wi < kernel_size; wi++) {
          int inw_pos = outw_pos * stride - padding + wi * dilation;
          float *fmap = (float *)src->data +
                        inh_pos * src->shape[1] * src->shape[2] +
                        inw_pos * src->shape[2];
          mfloat32m1_t tr0 = mlufce32_m(fmap, src->shape[2] * sizeof(float));
          out = mfmax_mm(out, tr0);
        }
      }
      msce32_m(out, (float *)dst->data + m * dst->shape[2] + n,
               dst->shape[2] * sizeof(float));
    }
  }
}

void avgpool2d(Tensor *dst, Tensor *src, int kernel_size, int stride,
               int padding, int dilation) {
  const int outh = dst->shape[0];
  const int outw = dst->shape[1];
  const int M = outh * outw;
  const int N = dst->shape[2];
  int tile_m, tile_n;
  msettype(E32, M1, BA);
  msetoutsh(outh << 16 | outw,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(src->shape[0] << 16 | src->shape[1],
           padding << 24 | padding << 16 | padding << 8 | padding);
  mfloat32m1_t div;
  mfmv_s_f(div, kernel_size * kernel_size, 0);
  mbcce_m(div);
  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);
    int outh_pos = m / outw;
    int outw_pos = m % outw;
    for (int n = 0; n < N; n += tile_n) {
      tile_n = msettilen(N - n);
      mfloat32m1_t out = mlce32_m1((float *)dst->data + m * dst->shape[2] + n,
                                   dst->shape[2] * sizeof(float));
      for (int ki = 0; ki < kernel_size; ki++) {
        int inh_pos = outh_pos * stride - padding + ki * dilation;
        for (int wi = 0; wi < kernel_size; wi++) {
          int inw_pos = outw_pos * stride - padding + wi * dilation;
          msetsk(inh_pos << 16 | inw_pos, (wi * dilation) << 16 | outw_pos);
          float *fmap = (float *)src->data +
                        inh_pos * src->shape[1] * src->shape[2] +
                        inw_pos * src->shape[2];
          mfloat32m1_t tr0 = mlufce32_m(fmap, src->shape[2] * sizeof(float));
          out = mfadd_mm(out, tr0);
        }
      }
      out = mfdiv_mm(out, div);
      msce32_m(out, (float *)dst->data + m * dst->shape[2] + n,
               dst->shape[2] * sizeof(float));
    }
  }
}

#endif // MATRIX_TESTS_DEMO_OPS_POOL_H_