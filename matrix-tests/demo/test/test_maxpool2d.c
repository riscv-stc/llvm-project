#include "../../isa/utils.h"
#include "../ops/pool2d.h"
#include "../ops/tensor.h"
#include <riscv_matrix.h>

static void test_maxpool2d1() {
  float src[] = {1, 10, 2, 11, 3, 12, 4, 13, 5, 14, 6, 15, 7, 16, 8, 17, 9, 18};
  float ans[] = {5, 14, 6, 15, 8, 17, 9, 18};
  const int B = 1;
  const int C = 2;
  const int H = 3;
  const int W = 3;
  float dst[2 * 2 * 2];
  create_conv2d_default_config(cfg, 1, 0, 1, 2);
  create_tensor4d(maxpool_src, (void *)src, B, H, W, C);
  create_tensor4d(maxpool_dst, (void *)dst, B, 2, 2, C);
  create_tensor4d(maxpool_ans, (void *)ans, B, 2, 2, C);
  maxpool2d(&maxpool_dst, &maxpool_src, &cfg);
  float *dst_ptr = (float *)maxpool_dst.data;
  float *ans_ptr = (float *)maxpool_ans.data;
  EXCEPT_FP32_ARRAY_LAX_EQ(ans_ptr, dst_ptr, 2 * 2 * C,
                           "MAXPOOL2D [1, 3, 3, 2]");
  // DUMP_MATRIX(dst_ptr, 4, 2, "%f");
}

static void test_maxpool2d2() {
  float src[] = {1, 4, 7, 3, 6, 2, 5, 8, 2, 5, 3, 6, 9, 1, 4,
                 3, 6, 9, 1, 4, 2, 5, 8, 2, 5, 1, 4, 7, 3, 6,
                 1, 4, 7, 3, 6, 2, 5, 8, 2, 5, 3, 6, 9, 1, 4};
  float ans[] = {3, 6, 9, 3, 6, 3, 6, 9, 3, 6, 3, 6, 9, 3, 6, 3, 6, 9, 3, 6};
  const int B = 1;
  const int C = 5;
  const int H = 3;
  const int W = 3;
  float dst[5 * 2 * 2];
  create_conv2d_default_config(cfg, 1, 0, 1, 2);
  create_tensor4d(maxpool_src, (void *)src, B, H, W, C);
  create_tensor4d(maxpool_dst, (void *)dst, B, 2, 2, C);
  create_tensor4d(maxpool_ans, (void *)ans, B, 2, 2, C);
  maxpool2d(&maxpool_dst, &maxpool_src, &cfg);
  float *dst_ptr = (float *)maxpool_dst.data;
  float *ans_ptr = (float *)maxpool_ans.data;
  EXCEPT_FP32_ARRAY_EQ(ans_ptr, dst_ptr, 2 * 2 * C, "MAXPOOL2D [1, 3, 3, 5]");
  // DUMP_MATRIX(dst_ptr, 4, 2, "%f");
}

static void test_maxpool2d3() {
  float src[] = {
      -0.2103, -0.2210, -1.4064, -1.1645, -1.0232, -0.2137, -0.4982, -1.2809,
      -1.5399, 0.1602,  0.1875,  -1.0158, -0.8094, 0.3949,  -0.3722, -0.2243,
      -0.0843, -1.4810, -0.0532, -0.5196, -0.4359, 1.0230,  0.1461,  0.7530,
      -0.1546, 1.2846,  0.7966,  0.1769,  -0.6762, -2.2925, 0.6487,  -0.7795,
      -0.3407, 0.3610,  -0.4004, -0.4338, -0.1093, -0.0990, -1.0139, 1.3749,
      -1.6291, -0.9360, -2.0373, -2.0263, -0.3252, 0.8941,  -0.9177, -0.2073,
      0.9816,  -0.4920, -0.1477, -0.3476, 0.7657,  -0.9636, -0.0283, -0.7289,
      -1.6282, -0.5718, 1.5560,  -0.0167, -0.5005, 0.2220,  0.0796,  -1.7243,
      0.5999,  -1.0904, -1.0896, -0.1803, -0.3502, -0.6318, 0.3076,  -0.4914,
      1.0582,  -0.5793, 0.8485,  1.6891,  -0.9809, 0.2153,  0.4924,  -0.0391,
      0.6046,  -0.5121, -1.1099, -0.9082, -0.7399, 0.1464,  0.3237,  0.8447,
      -2.0983, 0.4334,  -0.6096, -0.5172, 0.9732,  1.0369,  0.2731,  2.5031,
      0.3400,  0.8780,  1.3560,  -0.8102, 0.2907,  -0.6553, 0.6188,  0.8675,
      -0.3937, 0.9072,  0.7801,  0.1339,  1.6452,  -1.1202, -2.2051, -1.0998,
      -1.1876, -0.2591, 0.5141,  -1.0222, -1.0577, 0.9677,  -1.7426, -0.3770,
      0.6887,  -0.1122, -1.0095, -0.7160, -0.4659, -0.3936, -1.0140, 1.0432,
      0.1411,  0.1608,  1.0441,  -0.8608, 0.8724,  0.4388,  -0.2814, 0.6843,
      0.1241,  1.2795,  -0.1069, 1.3695,  0.0534,  -2.0336, 0.2287,  0.8117,
      0.6680,  -0.6851, -0.1728, 0.5015,  -0.4971, -0.0028};
  float ans[] = {1.6452, 0.8780, 1.3560, 1.6891, 0.7801, 2.5031, 1.6452, 1.2846,
                 1.3560, 1.6891, 1.5560, 2.5031, 1.6452, 1.2846, 1.3560, 1.6891,
                 1.5560, 0.7530, 1.6452, 1.3695, 1.3560, 1.6891, 1.0441, 2.5031,
                 1.6452, 1.3695, 1.3560, 1.6891, 1.5560, 2.5031, 1.6452, 1.3695,
                 1.3560, 1.6891, 1.5560, 1.2795, 1.6452, 1.3695, 1.3560, 1.6891,
                 1.0441, 2.5031, 1.6452, 1.3695, 1.3560, 1.6891, 1.5560, 2.5031,
                 1.6452, 1.3695, 1.3560, 1.6891, 1.5560, 1.2795};
  const int B = 1;
  const int C = 6;
  const int H = 5;
  const int W = 5;
  float dst[6 * 3 * 3];
  create_conv2d_default_config(cfg, 1, 1, 1, 5);
  create_tensor4d(maxpool_src, (void *)src, B, H, W, C);
  create_tensor4d(maxpool_dst, (void *)dst, B, 3, 3, C);
  create_tensor4d(maxpool_ans, (void *)ans, B, 3, 3, C);
  maxpool2d(&maxpool_dst, &maxpool_src, &cfg);
  float *dst_ptr = (float *)maxpool_dst.data;
  float *ans_ptr = (float *)maxpool_ans.data;
  EXCEPT_FP32_ARRAY_EQ(ans_ptr, dst_ptr, 3 * 3 * C, "MAXPOOL2D [1, 5, 5, 6]");
}

int main() {
  test_maxpool2d1();
  test_maxpool2d2();
  test_maxpool2d3();
  return 0;
}