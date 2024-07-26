#ifndef MATRIX_TESTS_DEMO_OPS_MATMUL_H_
#define MATRIX_TESTS_DEMO_OPS_MATMUL_H_

#include "../tensor.h"
#include <riscv_matrix.h>

void matmul(Tensor *dist, Tensor *src1, Tensor *src2) {
  const int M = src1->shape[0];
  const int K = src1->shape[1];
  const int N = src2->shape[2];
  msettype(E32, M1, BA);
  int tile_m, tile_k, tile_n;

  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);

    for (int n = 0; n < N; n += tile_n) {
      tile_n = msettilen(N - n);

      mfloat32m1_t out =
          mlce32_m1((float *)dist->data + m * N + n, N * sizeof(float));
      out = mfsub_mm(out, out);
      for (int k = 0; k < K; k += tile_k) {
        tile_k = msettilek(K - k);

        mfloat32m1_t tr0 =
            mlae32_m1((float *)src1->data + m * K + k, K * sizeof(float));
        mfloat32m1_t tr1 =
            mlbe32_m1((float *)src2->data + k * N + n, N * sizeof(float));
        out = mfma_mm(out, tr0, tr1);
      }
      msce32_m(out, (float *)dist->data + m * N + n, N * sizeof(float));
    }
  }
}

#endif // !MATRIX_TESTS_DEMO_OPS_MATMUL_H_