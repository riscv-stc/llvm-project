#ifndef MATRIX_TESTS_DEMO_OPS_RELU_H_
#define MATRIX_TESTS_DEMO_OPS_RELU_H_

#include "../tensor.h"
#include <riscv_matrix.h>

void relu(Tensor *dst, Tensor *src) {
  const int M = src->shape[2];
  const int N = src->shape[0] * src->shape[1];
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
      mfloat32m1_t tr0 =
          mlce32_m1((float *)src->data + offset, N * sizeof(float));
      mfloat32m1_t out = mfmax_mm(tr0, zero);
      msce32_m(out, (float *)dst->data + offset, N * sizeof(float));
    }
  }
}

#endif // MATRIX_TESTS_DEMO_OPS_RELU_H_