#ifndef _RELU_H_
#define _RELU_H_

#include "../../isa/utils.h"
#include "tensor.h"
#include <riscv_matrix.h>

void relu(Tensor *dst, Tensor *src) {
  float *src_ptr = (float *)src->data;
  float *dst_ptr = (float *)dst->data;
  const int M = dst->shape[1] * dst->shape[2];
  const int N = dst->shape[0] * dst->shape[3];
  int tile_m, tile_n;
  msettype(E32, M1, BA);

  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);
    for (int n = 0; n < N; n += tile_n) {
      tile_n = msettilen(N - n);
      mfloat32m1_t zero;
      zero = mfmv_s_f(zero, 0, 0);
      zero = mbcce_m(zero);
      int offset = m * N + n;
      mfloat32m1_t tr0 = mlce32_m1(src_ptr + offset, N * sizeof(float));
      mfloat32m1_t out = mfmax_mm(tr0, zero);
      msce32_m(out, dst_ptr + offset, N * sizeof(float));
    }
  }
}

#endif // _RELU_H_