#ifndef MATRIX_TESTS_DEMO_OPS_ADD_H_
#define MATRIX_TESTS_DEMO_OPS_ADD_H_

#include "../tensor.h"
#include <riscv_matrix.h>

void add(Tensor *dist, Tensor *src1, Tensor *src2) {
  const int M = src1->shape[2];
  const int N = src1->shape[0] * src2->shape[1];
  int tile_m, tile_n;
  msettype(E32, M1, BA);

  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);

    for (int n = 0; n < N; n += tile_m) {
      tile_n = msettilen(N - n);
      int offset = m * N + n;
      mfloat32m1_t tr0 =
          mlce32_m1((float *)src1->data + offset, N * sizeof(float));
      mfloat32m1_t tr1 =
          mlce32_m1((float *)src2->data + offset, N * sizeof(float));
      mfloat32m1_t out = mfadd_mm(tr0, tr1);
      msce32_m(out, (float *)dist->data + offset, N * sizeof(float));
    }
  }
}

#endif // MATRIX_TESTS_DEMO_OPS_ADD_H_