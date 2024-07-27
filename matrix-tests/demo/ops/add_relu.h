#ifndef _ADD_RELU_H_
#define _ADD_RELU_H_

#include "tensor.h"
#include <riscv_matrix.h>

void add_relu(Tensor *dist, Tensor *src1, Tensor *src2) {
  float *src1_ptr = (float *)src1->data;
  float *src2_ptr = (float *)src2->data;
  float *dist_ptr = (float *)dist->data;
  const int M = dist->shape[1] * dist->shape[2];
  const int N = dist->shape[0] * dist->shape[3];
  int tile_m, tile_n;
  msettype(E32, M1, BA);
  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);
    for (int n = 0; n < N; n += tile_n) {
      tile_n = msettilen(N - n);
      mfloat32m1_t zero;
      zero = mfsub_mm(zero, zero);
      int offset = m * N + n;
      mfloat32m1_t tr0 = mlce32_m1(src1_ptr + offset, N * sizeof(float));
      mfloat32m1_t tr1 = mlce32_m1(src2_ptr + offset, N * sizeof(float));
      tr0 = mfadd_mm(tr0, tr1);
      tr0 = mfmax_mm(tr0, zero);
      msce32_m(tr0, dist_ptr + offset, N * sizeof(float));
    }
  }
}

#endif // _ADD_RELU_H_