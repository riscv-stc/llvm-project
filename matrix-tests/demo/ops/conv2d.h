#ifndef MATRIX_TESTS_DEMO_OPS_CONV2D_H_
#define MATRIX_TESTS_DEMO_OPS_CONV2D_H_

#include "../tensor.h"
#include "./config.h"
#include <riscv_matrix.h>
#include <stdio.h>

void conv2d(Tensor *dist, Tensor *src1, Tensor *src2, Conv2dConfig cfg) {
  const int M = cfg.out_shape[0] * cfg.out_shape[1];
  const int K = cfg.kernel_size[0] * cfg.kernel_size[1] * cfg.in_shape[2];
  const int N = cfg.out_shape[2];
  int tile_m, tile_k, tile_n;
  msetoutsh(cfg.out_shape[0] << 16 | cfg.out_shape[1],
            cfg.dilation[0] << 24 | cfg.dilation[1] << 16 | cfg.stride[0] << 8 |
                cfg.stride[1]);
  msetinsh(cfg.in_shape[0] << 16 | cfg.in_shape[1],
           cfg.padding[0] << 24 | cfg.padding[1] << 16 | cfg.padding[2] << 8 |
               cfg.padding[3]);
  for (int m = 0; m < M; m += tile_m) {
    tile_m = msettilem(M - m);
    int hout_pos = m / cfg.out_shape[1];
    int wout_pos = m % cfg.out_shape[1];

    for (int n = 0; n < N; n += tile_n) {
      tile_n = msettilen(N - n);
      mfloat32m1_t acc =
          mlce32_m1((float *)dist->data + m * cfg.out_shape[2] + n,
                    cfg.out_shape[2] * sizeof(float));

      for (int kh = 0; kh < cfg.kernel_size[0]; kh++) {
        int hin_pos =
            hout_pos * cfg.stride[0] - cfg.padding[0] + kh * cfg.dilation[0];

        for (int kw = 0; kw < cfg.kernel_size[1]; kw++) {
          int win_pos =
              wout_pos * cfg.stride[1] - cfg.padding[1] + kw * cfg.dilation[1];
          msetsk(hin_pos << 16 | win_pos,
                 (kw * cfg.dilation[1]) << 16 | wout_pos);
          float *fmap = (float *)src1->data +
                        hin_pos * cfg.in_shape[1] * cfg.in_shape[2] +
                        win_pos * cfg.in_shape[2];
          float *weight =
              (float *)src2->data +
              kh * cfg.kernel_size[1] * cfg.in_shape[2] * cfg.out_shape[2] +
              kw * cfg.in_shape[2] * cfg.out_shape[2] + n;

          for (int kc = 0; kc < cfg.in_shape[2]; kc += tile_k) {
            tile_k = msettilek(cfg.in_shape[2] - kc);
            mfloat32m1_t tr0 =
                mlufae32_m(fmap + kc, cfg.in_shape[2] * sizeof(float));
            mfloat32m1_t tr1 = mlbe32_m1(weight + kc * cfg.out_shape[2],
                                         cfg.out_shape[2] * sizeof(float));
            acc = mfma_mm(acc, tr0, tr1);
          }
        }
      }
      msce32_m(acc, (float *)dist->data + m * cfg.out_shape[2] + n,
               cfg.out_shape[2] * sizeof(float));
    }
  }
}

#endif // MATRIX_TESTS_DEMO_OPS_CONV2D_H_