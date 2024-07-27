#ifndef _MATMUL_H_
#define _MATMUL_H_

#include "tensor.h"
#include <riscv_matrix.h>

void matmul(Tensor *dist, Tensor *src1, Tensor *src2) {
  float *dist_ptr = (float *)dist->data;
  float *src1_ptr = (float *)src1->data;
  float *src2_ptr = (float *)src2->data;
  const int M = src1->shape[1];
  const int K = src1->shape[2];
  const int N = src2->shape[2];
  int tile_m, tile_k, tile_n;
  msettype(E32, M1, BA);

  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);

    for (int n = 0; n < N; n += tile_n) {
      tile_n = msettilen(N - n);
      mfloat32m1_t out = mlce32_m1(dist_ptr + m * M + n, N * sizeof(float));
      
      for (int k = 0; k < K; k += tile_k) {
        tile_k = msettilek(K - k);
        mfloat32m1_t tr0 = mlae32_m1(src1_ptr + m * K + k, K * sizeof(float));
        mfloat32m1_t tr1 = mlbe32_m1(src2_ptr + k * N + n, N * sizeof(float));
        out = mfma_mm(out, tr0, tr1);
      }
      msce32_m(out, dist_ptr + m * M + n, N * sizeof(float));
    }
  }
}

#endif