#include "utils.h"
#include <riscv_matrix.h>

static void test_mmau_mm() {
  // M1
  // uint8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(7);
  msettileni(4);
  const uint8_t u8_src1[] = {3, 4, 1, 3, 0, 1, 4, 0, 1, 2, 2,
                             0, 4, 2, 0, 0, 2, 0, 1, 1, 2};
  const uint8_t u8_src2[] = {0, 2, 2, 3, 0, 4, 2, 2, 4, 3, 2, 2, 0, 1,
                             0, 4, 2, 2, 4, 2, 4, 1, 0, 1, 2, 3, 4, 0};
  const uint8_t u8_src3[] = {1, 4, 2, 2, 4, 2, 0, 2, 1, 4, 3, 4};
  const uint8_t u8_ans[] = {17, 45, 34, 34, 32, 24, 14, 20, 19, 19, 19, 11};
  muint8m1_t u8_td = mlce8_m1(u8_src3, 4 * sizeof(uint8_t));
  muint8m1_t u8_ts1 = mlae8_m1(u8_src1, 7 * sizeof(uint8_t));
  muint8m1_t u8_ts2 = mlbe8_m1(u8_src2, 4 * sizeof(uint8_t));
  muint8m1_t u8_out = mmau_mm(u8_td, u8_ts1, u8_ts2);
  msce8_m(u8_out, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 12, " MMAU.MM  UINT8   M1");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(5);
  msettileni(3);
  const uint16_t u16_src1[] = {2, 79, 29, 50, 58, 32, 23, 32, 46, 4};
  const uint16_t u16_src2[] = {9, 86, 69, 38, 22, 6,  19, 37,
                               3, 92, 52, 52, 98, 76, 91};
  const uint16_t u16_src3[] = {2, 1, 29, 16, 17, 69};
  const uint16_t u16_ans[] = {13857, 9992, 8606, 6410, 7155, 5267};
  muint16m1_t u16_td = mlce16_m1(u16_src3, 3 * sizeof(uint16_t));
  muint16m1_t u16_ts1 = mlae16_m1(u16_src1, 5 * sizeof(uint16_t));
  muint16m1_t u16_ts2 = mlbe16_m1(u16_src2, 3 * sizeof(uint16_t));
  muint16m1_t u16_out = mmau_mm(u16_td, u16_ts1, u16_ts2);
  msce16_m(u16_out, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 6, " MMAU.MM  UINT16  M1");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(3);
  msettileni(2);
  const uint32_t u32_src1[] = {898, 834, 163, 871, 173, 215};
  const uint32_t u32_src2[] = {33, 391, 586, 268, 103, 861};
  const uint32_t u32_src3[] = {585, 140, 624, 787};
  const uint32_t u32_ans[] = {535732, 715113, 152890, 572827};
  muint32m1_t u32_td = mlce32_m1(u32_src3, 2 * sizeof(uint32_t));
  muint32m1_t u32_ts1 = mlae32_m1(u32_src1, 3 * sizeof(uint32_t));
  muint32m1_t u32_ts2 = mlbe32_m1(u32_src2, 2 * sizeof(uint32_t));
  muint32m1_t u32_out = mmau_mm(u32_td, u32_ts1, u32_ts2);
  msce32_m(u32_out, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 4, " MMAU.MM  UINT32  M1");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  msettileni(2);
  const uint64_t u64_src1[] = {1732, 3451, 7004, 764};
  const uint64_t u64_src2[] = {3796, 3713, 3906, 5726};
  const uint64_t u64_src3[] = {8572, 4687, 6102, 6769};
  const uint64_t u64_ans[] = {20062850, 26196029, 29577470, 30387285};
  muint64m1_t u64_td = mlce64_m1(u64_src3, 2 * sizeof(uint64_t));
  muint64m1_t u64_ts1 = mlae64_m1(u64_src1, 2 * sizeof(uint64_t));
  muint64m1_t u64_ts2 = mlbe64_m1(u64_src2, 2 * sizeof(uint64_t));
  muint64m1_t u64_out = mmau_mm(u64_td, u64_ts1, u64_ts2);
  msce64_m(u64_out, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 4, " MMAU.MM  UINT64  M1");
}

static void test_mma_mm() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(7);
  msettileni(4);
  const int8_t i8_src1[] = {4,  0,  -2, 1,  -4, 0, -1, 3,  -5, 2, -5,
                            -3, -4, 2,  -3, -5, 2, 4,  -3, 4,  3};
  const int8_t i8_src2[] = {3,  2, -4, -2, 2,  -4, -5, -3, 3, -4,
                            -1, 4, 4,  0,  -5, -5, -3, -2, 2, 1,
                            1,  0, -4, -3, 0,  1,  -2, 2};
  const int8_t i8_src3[] = {1, 1, 0, -1, 1, -1, 4, 4, -3, -2, -4, 3};
  const int8_t i8_ans[] = {23, 24, -25, -28, -9, 25, 46, 59, 13, 13, -17, 3};
  mint8m1_t i8_td = mlce8_m1(i8_src3, 4 * sizeof(int8_t));
  mint8m1_t i8_ts1 = mlae8_m1(i8_src1, 7 * sizeof(int8_t));
  mint8m1_t i8_ts2 = mlbe8_m1(i8_src2, 4 * sizeof(int8_t));
  mint8m1_t i8_out = mma_mm(i8_td, i8_ts1, i8_ts2);
  msce8_m(i8_out, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 12, " MMA.MM   INT8    M1");
  // int16
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(5);
  msettileni(3);
  const int16_t i16_src1[] = {-3, -13, 19, -5, 1, 1, -18, 12, -5, -2};
  const int16_t i16_src2[] = {6,   -14, -15, 10, 6, -4, -4, 6,
                              -17, -4,  7,   -7, 0, 11, -6};
  const int16_t i16_src3[] = {12, 9, 0, -1, 1, 7};
  const int16_t i16_ans[] = {-192, 63, -197, -203, -106, -93};
  mint16m1_t i16_td = mlce16_m1(i16_src3, 3 * sizeof(int16_t));
  mint16m1_t i16_ts1 = mlae16_m1(i16_src1, 5 * sizeof(int16_t));
  mint16m1_t i16_ts2 = mlbe16_m1(i16_src2, 3 * sizeof(int16_t));
  mint16m1_t i16_out = mma_mm(i16_td, i16_ts1, i16_ts2);
  msce16_m(i16_out, i16_buffer, 3 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MMA.MM   INT16   M1");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(3);
  msettileni(2);
  const int32_t i32_src1[] = {703, -645, -610, 702, 33, -406};
  const int32_t i32_src2[] = {315, 420, -384, 183, -592, -941};
  const int32_t i32_src3[] = {-735, 102, 60, 208};
  const int32_t i32_ans[] = {829510, 751337, 448870, 683133};
  mint32m1_t i32_td = mlce32_m1(i32_src3, 2 * sizeof(int32_t));
  mint32m1_t i32_ts1 = mlae32_m1(i32_src1, 3 * sizeof(int32_t));
  mint32m1_t i32_ts2 = mlbe32_m1(i32_src2, 2 * sizeof(int32_t));
  mint32m1_t i32_out = mma_mm(i32_td, i32_ts1, i32_ts2);
  msce32_m(i32_out, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 4, "MMA.MM   INT32   M1");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  msettileni(2);
  const int64_t i64_src1[] = {6094, -5077, 9486, 2805};
  const int64_t i64_src2[] = {-1636, 2086, 2957, 395};
  const int64_t i64_src3[] = {7508, -1992, -8203, 6284};
  const int64_t i64_ans[] = {-24974965, 10704677, -7232914, 20902055};
  mint64m1_t i64_td = mlce64_m1(i64_src3, 2 * sizeof(int64_t));
  mint64m1_t i64_ts1 = mlae64_m1(i64_src1, 2 * sizeof(int64_t));
  mint64m1_t i64_ts2 = mlbe64_m1(i64_src2, 2 * sizeof(int64_t));
  mint64m1_t i64_out = mma_mm(i64_td, i64_ts1, i64_ts2);
  msce64_m(i64_out, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, "MMA.MM   INT64   M1");
}

static void test_mfma_mm() {
  // M1
  // FP16
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(4);
  msettileni(3);
  const fp16_t fp16_src1[] = {0.51023126, -0.00394513, 0.16965401, -1.4689436,
                              -0.4005377, -0.08451383, -0.2710746, 2.2667677};
  const fp16_t fp16_src2[] = {-0.747585,  1.670036,   1.0217261,   -2.0697482,
                              0.7502159,  1.3919928,  -0.19126661, -1.2411383,
                              -1.9375901, -3.2388709, -1.1455771,  -1.5930234};
  const fp16_t fp16_src3[] = {-0.8344538, 2.0236545,  0.9149896,
                              0.43444654, -1.0935922, 0.50777227};
  const fp16_t fp16_ans[] = {3.5175397, 4.345023,   3.4421563,
                             -6.381116, -4.0862246, -3.104893};
  mfloat16m1_t fp16_td = mlce16_m1(fp16_src3, 3 * sizeof(fp16_t));
  mfloat16m1_t fp16_ts1 = mlae16_m1(fp16_src1, 4 * sizeof(fp16_t));
  mfloat16m1_t fp16_ts2 = mlbe16_m1(fp16_src2, 3 * sizeof(fp16_t));
  mfloat16m1_t fp16_out = mfma_mm(fp16_td, fp16_ts1, fp16_ts2);
  msce16_m(fp16_out, fp16_buffer, 3 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_LAX_EQ(fp16_ans, fp16_buffer, 6, "MFMA.MM  FP16    M1");
  // FP32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(4);
  msettileni(3);
  const fp32_t fp32_src1[] = {0.51023126, -0.00394513, 0.16965401, -1.4689436,
                              -0.4005377, -0.08451383, -0.2710746, 2.2667677};
  const fp32_t fp32_src2[] = {-0.747585,  1.670036,   1.0217261,   -2.0697482,
                              0.7502159,  1.3919928,  -0.19126661, -1.2411383,
                              -1.9375901, -3.2388709, -1.1455771,  -1.5930234};
  const fp32_t fp32_src3[] = {-0.8344538, 2.0236545,  0.9149896,
                              0.43444654, -1.0935922, 0.50777227};
  const fp32_t fp32_ans[] = {3.5175397, 4.345023,   3.4421563,
                             -6.381116, -4.0862246, -3.104893};
  mfloat32m1_t fp32_td = mlce32_m1(fp32_src3, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_ts1 = mlae32_m1(fp32_src1, 4 * sizeof(fp32_t));
  mfloat32m1_t fp32_ts2 = mlbe32_m1(fp32_src2, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_out = mfma_mm(fp32_td, fp32_ts1, fp32_ts2);
  msce32_m(fp32_out, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_LAX_EQ(fp32_ans, fp32_buffer, 6, "MFMA.MM  FP32    M1");
  // FP64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  msettileni(2);
  const fp64_t fp64_src1[] = {6.0217805,   6.41612583, -4.4896673,
                              -3.03642184, 0.51972111, -5.69775867};
  const fp64_t fp64_src2[] = {-3.44609258, -6.00144306, 1.73407218, 2.65178666};
  const fp64_t fp64_src3[] = {3.56528444, 6.07608404, 5.96818513,
                              -9.6548981, 3.10374158, -1.6868003};
  const fp64_t fp64_ans[] = {-6.06030333, -13.04909195, 16.17461964,
                             9.23764167,  -8.5675903,   -19.91511736};
  mfloat64m1_t fp64_td = mlce64_m1(fp64_src3, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_ts1 = mlae64_m1(fp64_src1, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_ts2 = mlbe64_m1(fp64_src2, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_out = mfma_mm(fp64_td, fp64_ts1, fp64_ts2);
  msce64_m(fp64_out, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_LAX_EQ(fp64_ans, fp64_buffer, 6, "MFMA.MM  FP64    M1");
}

static void test_msma_mm() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(5);
  msettileni(16);
  const int8_t i8_src1[] = {-6, -89, 75, -12, 122, 65, 109, 30, -72, 88};
  const int8_t i8_src2[] = {
      -105, 16,  -21,  69,  -61,  -3,  80,  25,   56,  -91,  -41, -92,
      93,   -92, -61,  -26, 6,    46,  -54, -126, -47, -121, -58, -105,
      45,   -28, -76,  64,  11,   91,  -97, 71,   36,  -58,  -71, 60,
      -104, 1,   78,   106, -106, 122, -34, -29,  104, -118, 8,   -44,
      120,  118, -71,  73,  0,    99,  41,  -41,  -9,  -96,  -20, 97,
      -98,  97,  31,   42,  23,   122, 96,  29,   47,  18,   45,  68,
      4,    5,   -111, 52,  88,   113, -62, 124};
  const int8_t i8_src3[] = {-104, 19,   1,   -30, -35, -70, 34,   -48,
                            -42,  -43,  84,  53,  35,  -97, 28,   122,
                            -115, -114, 122, 55,  11,  -82, 25,   99,
                            -15,  -107, 78,  43,  8,   98,  -113, 4};
  const int8_t i8_ans[] = {127, 127, 127,  127, 127, 127, 127,  127,
                           127, 127, -128, 127, 127, 127, -128, 127,
                           127, 127, 127,  127, 127, 127, 127,  127,
                           127, 127, -128, 127, 127, 127, -128, 127};
  mint8m1_t i8_ts1 = mlae8_m1(i8_src1, 5 * sizeof(int8_t));
  mint8m1_t i8_ts2 = mlbe8_m1(i8_src2, 16 * sizeof(int8_t));
  mint8m1_t i8_td = mlce8_m1(i8_src3, 16 * sizeof(int8_t));
  mint8m1_t i8_out = msma_mm(i8_td, i8_ts1, i8_ts2);
  msce8_m(i8_out, i8_buffer, 16 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 32, "MSMA.MM  INT8    M1");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(4);
  msettileni(8);
  const int16_t i16_src1[] = {8520,   11725, -23469, -23197, 27260, -14610,
                              -22535, -7532, -4753,  17449,  11242, -7799};
  const int16_t i16_src2[] = {
      22756,  141,    -10861, 27259, 31577,  15441, 7905,   -2562,
      3363,   -26266, 22677,  15478, 25820,  19527, -15314, 18728,
      9332,   20250,  -7883,  19163, -14266, -8424, -10079, 29671,
      -15931, 27861,  22272,  15428, -5916,  -8463, -16746, -14923};
  const int16_t i16_src3[] = {-23520, 4042,  -24461, -17410, 28662,  -31958,
                              -23823, -2686, 18227,  3694,   18985,  15803,
                              -1991,  -3425, -31127, 9464,   -15359, 29288,
                              7298,   19514, -12027, 4230,   -11230, -12336};
  const int16_t i16_ans[] = {32767,  -32768, -32768, -32768, 32767,  32767,
                             32767,  32767,  32767,  -32768, -32768, -32768,
                             32767,  32767,  32767,  32767,  32767,  -32768,
                             -32768, -32768, 32767,  32767,  32767,  32767};
  mint16m1_t i16_ts1 = mlae16_m1(i16_src1, 4 * sizeof(int16_t));
  mint16m1_t i16_ts2 = mlbe16_m1(i16_src2, 8 * sizeof(int16_t));
  mint16m1_t i16_td = mlce16_m1(i16_src3, 8 * sizeof(int16_t));
  mint16m1_t i16_out = msma_mm(i16_td, i16_ts1, i16_ts2);
  msce16_m(i16_out, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 24, "MSMA.MM  INT16   M1");
  // int32
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileki(3);
  msettileni(4);
  const int32_t i32_src1[] = {2147483647,  2147483647,  2147483647,
                              -2147483647, -2147483648, -2147483648,
                              -2147483648, -2147483648, -2147483647,
                              2147483647,  2147483647,  2147483647};
  const int32_t i32_src2[] = {-2147483648, -2147483648, 2147483647, 2147483647,
                              -2147483648, -2147483648, 2147483647, 2147483647,
                              -2147483648, -2147483648, 2147483647, 2147483647};
  const int32_t i32_src3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -0, 0, 0, 0};
  const int32_t i32_ans[] = {-2147483648, -2147483648, 2147483647,  2147483647,
                             2147483647,  2147483647,  -2147483648, -2147483648,
                             2147483647,  2147483647,  -2147483648, -2147483648,
                             -2147483648, -2147483648, 2147483647,  2147483647};
  mint32m1_t i32_ts1 = mlae32_m1(i32_src1, 3 * sizeof(int32_t));
  mint32m1_t i32_ts2 = mlbe32_m1(i32_src2, 4 * sizeof(int32_t));
  mint32m1_t i32_td = mlce32_m1(i32_src3, 4 * sizeof(int32_t));
  mint32m1_t i32_out = msma_mm(i32_td, i32_ts1, i32_ts2);
  msce32_m(i32_out, i32_buffer, 4 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 16, "MSMA.MM  INT32   M1");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  msettileni(2);
  const int64_t i64_src1[] = {-9223372036854775808, -9223372036854775808,
                              -9223372036854775808, -9223372036854775808};
  const int64_t i64_src2[] = {9223372036854775807, 9223372036854775807,
                              9223372036854775807, 9223372036854775807};
  const int64_t i64_src3[] = {0, 0, 0, 0};
  const int64_t i64_ans[] = {-9223372036854775808, -9223372036854775808,
                             -9223372036854775808, -9223372036854775808};
  mint64m1_t i64_ts1 = mlae64_m1(i64_src1, 2 * sizeof(int64_t));
  mint64m1_t i64_ts2 = mlbe64_m1(i64_src2, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mlce64_m1(i64_src3, 2 * sizeof(int64_t));
  mint64m1_t i64_out = msma_mm(i64_td, i64_ts1, i64_ts2);
  msce64_m(i64_out, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, "MSMA.MM  INT64   M1");
}

static void test_msmau_mm() {
  // M1
  // uint8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(5);
  msettileni(16);
  const uint8_t u8_src1[] = {167, 90, 76, 110, 33, 130, 61, 189, 6, 237};
  const uint8_t u8_src2[] = {
      104, 165, 34,  78,  96,  246, 136, 84,  90,  232, 181, 188, 242, 99,
      29,  253, 69,  14,  185, 21,  227, 105, 59,  238, 143, 18,  63,  204,
      179, 14,  77,  224, 86,  248, 183, 86,  116, 161, 134, 127, 209, 98,
      154, 247, 79,  49,  106, 251, 237, 13,  14,  55,  32,  98,  243, 222,
      43,  189, 125, 235, 116, 172, 20,  8,   118, 135, 132, 193, 86,  36,
      228, 63,  123, 150, 192, 131, 248, 205, 18,  244};
  const uint8_t u8_src3[] = {238, 247, 28,  199, 178, 238, 80,  37,
                             51,  172, 163, 37,  49,  107, 42,  61,
                             209, 229, 28,  120, 8,   108, 130, 248,
                             12,  238, 6,   75,  115, 111, 145, 159};
  const uint8_t u8_ans[] = {255, 255, 255, 255, 255, 255, 255, 255,
                            255, 255, 255, 255, 255, 255, 255, 255,
                            255, 255, 255, 255, 255, 255, 255, 255,
                            255, 255, 255, 255, 255, 255, 255, 255};
  muint8m1_t u8_ts1 = mlae8_m1(u8_src1, 5 * sizeof(uint8_t));
  muint8m1_t u8_ts2 = mlbe8_m1(u8_src2, 16 * sizeof(uint8_t));
  muint8m1_t u8_td = mlce8_m1(u8_src3, 16 * sizeof(uint8_t));
  muint8m1_t u8_out = msmau_mm(u8_td, u8_ts1, u8_ts2);
  msce8_m(u8_out, u8_buffer, 16 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 32, "MSMAU.MM UINT8   M1");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(4);
  msettileni(8);
  const uint16_t u16_src1[] = {7366,  53030, 45082, 60978, 31687, 38800,
                               11794, 12570, 35238, 30300, 24100, 47305};
  const uint16_t u16_src2[] = {55134, 28835, 8335,  23782, 50927, 6214,  36345,
                               16295, 13751, 5692,  6346,  46137, 47047, 41251,
                               49229, 13700, 42936, 15985, 7625,  34791, 35146,
                               39644, 58132, 43162, 16613, 37709, 17131, 29657,
                               42442, 50956, 21940, 32761};
  const uint16_t u16_src3[] = {45916, 23872, 30457, 5373,  51529, 4605,
                               25989, 16450, 58618, 9512,  10667, 13965,
                               54328, 20762, 63211, 63516, 24329, 58340,
                               11880, 34095, 244,   28480, 35438, 17537};
  const uint16_t u16_ans[] = {65535, 65535, 65535, 65535, 65535, 65535,
                              65535, 65535, 65535, 65535, 65535, 65535,
                              65535, 65535, 65535, 65535, 65535, 65535,
                              65535, 65535, 65535, 65535, 65535, 65535};
  muint16m1_t u16_ts1 = mlae16_m1(u16_src1, 4 * sizeof(uint16_t));
  muint16m1_t u16_ts2 = mlbe16_m1(u16_src2, 8 * sizeof(uint16_t));
  muint16m1_t u16_td = mlce16_m1(u16_src3, 8 * sizeof(uint16_t));
  muint16m1_t u16_out = msmau_mm(u16_td, u16_ts1, u16_ts2);
  msce16_m(u16_out, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 24, "MSMAU.MM UINT16  M1");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileki(3);
  msettileni(4);
  const uint32_t u32_src1[] = {23392923, 18613985, 30466815, 31087072,
                               12746001, 31354251, 4277260,  1897430,
                               21620355, 14125054, 25975494, 31210910};
  const uint32_t u32_src2[] = {18356760, 16000079, 6041137,  12357014,
                               11162720, 28689552, 13649745, 12237511,
                               11504430, 18914158, 6509167,  20297004};
  const uint32_t u32_src3[] = {15230290, 3043292,  7556065,  25546210,
                               23477855, 2320106,  33335393, 33271680,
                               27904640, 17151704, 11489893, 23656586,
                               358760,   435965,   5413889,  33137};
  const uint32_t u32_ans[] = {4294967295, 4294967295, 4294967295, 4294967295,
                              4294967295, 4294967295, 4294967295, 4294967295,
                              4294967295, 4294967295, 4294967295, 4294967295,
                              4294967295, 4294967295, 4294967295, 4294967295};
  muint32m1_t u32_ts1 = mlae32_m1(u32_src1, 3 * sizeof(uint32_t));
  muint32m1_t u32_ts2 = mlbe32_m1(u32_src2, 4 * sizeof(uint32_t));
  muint32m1_t u32_td = mlce32_m1(u32_src3, 4 * sizeof(uint32_t));
  muint32m1_t u32_out = msmau_mm(u32_td, u32_ts1, u32_ts2);
  msce32_m(u32_out, u32_buffer, 4 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 12, "MSMAU.MM UINT32  M1");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  msettileni(2);
  const uint64_t u64_src1[] = {8713174841848956649, 8755531486730793654,
                               5176515351019222675, 5774468089738620850};
  const uint64_t u64_src2[] = {7214255850794356040, 6090603982965597079,
                               7131445361576919785, 7067103509498471038};
  const uint64_t u64_src3[] = {9148851286252262273, 4646592160763786056,
                               4841124635626772978, 5867868792544060716};
  const uint64_t u64_ans[] = {18446744073709551615U, 18446744073709551615U,
                              18446744073709551615U, 18446744073709551615U};
  muint64m1_t u64_ts1 = mlae64_m1(u64_src1, 2 * sizeof(uint64_t));
  muint64m1_t u64_ts2 = mlbe64_m1(u64_src2, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mlce64_m1(u64_src3, 2 * sizeof(uint64_t));
  muint64m1_t u64_out = msmau_mm(u64_td, u64_ts1, u64_ts2);
  msce64_m(u64_out, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 2 * 2, "MSMAU.MM UINT64  M1");
}

static void test_mwmau_mm() {
  const uint8_t u8_rs1_m1[] = {3, 18, 5, 17, 12, 0,  19, 11,
                               4, 12, 7, 16, 8,  15, 11, 17};
  const uint8_t u8_rs2_m1[] = {
      18, 3,  3,  18, 19, 18, 16, 17, 17, 11, 11, 9,  17, 19, 5,  1,
      11, 3,  5,  9,  19, 6,  19, 16, 9,  6,  6,  18, 12, 16, 4,  0,
      9,  12, 0,  11, 8,  14, 11, 2,  1,  15, 18, 13, 16, 11, 2,  14,
      8,  8,  16, 15, 8,  14, 18, 13, 14, 17, 0,  16, 10, 0,  11, 0,
      2,  15, 13, 2,  3,  18, 5,  17, 19, 4,  12, 9,  9,  18, 19, 14,
      4,  4,  4,  9,  2,  17, 2,  0,  16, 18, 18, 7,  7,  0,  7,  15,
      14, 9,  19, 7,  10, 10, 14, 4,  9,  6,  18, 8,  10, 2,  0,  0,
      6,  11, 11, 7,  19, 13, 5,  9,  3,  19, 16, 0,  5,  12, 0,  8};
  const uint16_t u16_rs3_m2[] = {13, 14, 13, 16, 9,  6, 11, 12, 10, 9, 2,
                                 1,  5,  9,  10, 12, 6, 4,  2,  16, 3, 9,
                                 3,  1,  18, 4,  18, 6, 10, 3,  12, 2};
  const uint16_t u16_ans_m2[] = {802, 745,  1022, 776, 1019, 1025, 1143, 961,
                                 898, 885,  895,  949, 875,  795,  522,  341,
                                 733, 730,  890,  860, 978,  1205, 969,  816,
                                 967, 1188, 1096, 870, 866,  718,  527,  577};
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(16);
  muint8m1_t u8_ts1_m1 = mlae8_m1(u8_rs1_m1, 8 * sizeof(uint8_t));
  muint8m1_t u8_ts2_m1 = mlbe8_m1(u8_rs2_m1, 16 * sizeof(uint8_t));
  msettype(E16, M2, BA);
  msettileni(16);
  muint16m2_t u16_td_m2 = mlce16_m2(u16_rs3_m2, 16 * sizeof(uint16_t));
  msettype(E8, M1, BA);
  msettileni(16);
  muint16m2_t u16_out_m2 = mwmau_mm(u16_td_m2, u8_ts1_m1, u8_ts2_m1);
  msettype(E16, M2, BA);
  msettileni(16);
  msce16_m(u16_out_m2, u16_buffer, 16 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans_m2, u16_buffer, 2 * 16, "MWMAU.MM UINT8   M1");

  const uint16_t u16_rs1_m1[] = {43,  569, 620, 175, 11,  293, 579, 340,
                                 311, 445, 329, 104, 634, 337, 569, 210};
  const uint16_t u16_rs2_m1[] = {
      192, 537, 442, 142, 476, 457, 557, 564, 152, 501, 411, 106, 599,
      617, 93,  35,  126, 320, 649, 105, 470, 338, 321, 112, 449, 148,
      10,  542, 18,  472, 424, 370, 514, 106, 321, 631, 481, 189, 31,
      74,  296, 389, 372, 608, 590, 167, 297, 147, 512, 424, 419, 376,
      489, 643, 621, 274, 478, 414, 598, 584, 628, 354, 213, 150};
  const uint32_t u32_rs3_m2[] = {165, 573, 15,  442, 442, 239, 269, 189,
                                 28,  31,  208, 623, 292, 237, 261, 118};
  const uint32_t u32_ans_m2[] = {
      802954,  1034432, 1215458, 828161,  1331103, 1206790, 869698, 432077,
      1032866, 1037148, 1227995, 1124402, 1485290, 1193531, 882400, 550286};
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(8);
  muint16m1_t u16_ts1_m1 = mlae16_m1(u16_rs1_m1, 8 * sizeof(uint16_t));
  muint16m1_t u16_ts2_m1 = mlbe16_m1(u16_rs2_m1, 8 * sizeof(uint16_t));
  msettype(E32, M2, BA);
  msettileni(8);
  muint32m2_t u32_td_m2 = mlce32_m2(u32_rs3_m2, 8 * sizeof(uint32_t));
  msettype(E16, M1, BA);
  msettileni(8);
  muint32m2_t u32_out_m2 = mwmau_mm(u32_td_m2, u16_ts1_m1, u16_ts2_m1);
  msettype(E32, M2, BA);
  msettileni(8);
  msce32_m(u32_out_m2, u32_buffer, 8 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans_m2, u32_buffer, 2 * 8, "MWMAU.MM UINT16  M1");
}

static test_mqmau_mm() {
  const uint8_t u8_rs1_m1[] = {124, 238, 11, 155, 19, 186, 216, 79,
                               80,  146, 52, 12,  1,  156, 202, 136};
  const uint8_t u8_rs2_m1[] = {
      135, 65,  117, 83,  73,  186, 247, 31,  245, 11,  0,   118, 50,  39,  188,
      142, 153, 109, 18,  174, 20,  121, 3,   10,  44,  124, 15,  42,  163, 128,
      49,  171, 49,  56,  9,   137, 42,  174, 44,  162, 85,  124, 72,  67,  241,
      60,  17,  187, 217, 39,  149, 78,  155, 251, 216, 158, 185, 170, 137, 104,
      136, 198, 217, 230, 49,  240, 136, 225, 59,  161, 128, 64,  57,  74,  251,
      254, 52,  97,  253, 237, 204, 171, 56,  92,  240, 76,  177, 86,  160, 145,
      61,  174, 143, 198, 184, 31,  13,  122, 12,  81,  222, 60,  245, 120, 201,
      194, 172, 176, 131, 184, 27,  100, 144, 97,  200, 121, 53,  162, 52,  188,
      155, 237, 77,  21,  139, 27,  48,  234};
  const uint32_t u32_rs3_m4[] = {242, 247, 212, 179, 165, 5,   252, 35,
                                 108, 106, 134, 9,   83,  133, 141, 20,
                                 70,  235, 237, 24,  71,  217, 57,  73,
                                 232, 246, 24,  240, 250, 66,  79,  177};
  const uint32_t u32_ans_m4[] = {
      140629, 111291, 73590, 113922, 136364, 135639, 157940, 90515,
      157074, 147699, 85081, 118359, 135671, 147331, 117592, 146388,
      92443,  89481,  52977, 87523,  102426, 90992,  109437, 77621,
      119595, 121832, 62585, 86350,  109938, 99195,  66700,  106084};
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(16);
  muint8m1_t u8_ts1_m1 = mlae8_m1(u8_rs1_m1, 8 * sizeof(uint8_t));
  muint8m1_t u8_ts2_m1 = mlbe8_m1(u8_rs2_m1, 16 * sizeof(uint8_t));
  msettype(E32, M4, BA);
  msettileni(16);
  muint32m4_t u32_td_m4 = mlce32_m4(u32_rs3_m4, 16 * sizeof(uint32_t));
  msettype(E8, M1, BA);
  msettileni(16);
  muint32m4_t u32_out_m4 = mqmau_mm(u32_td_m4, u8_ts1_m1, u8_ts2_m1);
  msettype(E32, M4, BA);
  msettileni(16);
  msce32_m(u32_out_m4, u32_buffer, 16 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans_m4, u32_buffer, 2 * 16, "MQMAU.MM UINT8   M1");

  const uint16_t u16_rs1_m1[] = {4041, 4957, 3840, 1857, 5116, 6181,
                                 3205, 4170, 2008, 290,  3561, 10,
                                 3701, 640,  5935, 3615};
  const uint16_t u16_rs2_m1[] = {
      1575, 44,   3597, 6484, 2945, 2183, 2811, 2662, 40,   2107, 411,
      5037, 2104, 4223, 3945, 4255, 1054, 1944, 4090, 1788, 4691, 1160,
      5737, 2662, 436,  513,  1186, 3911, 6374, 99,   2076, 4712, 4989,
      886,  815,  1878, 2650, 1441, 2307, 1220, 3060, 1109, 3437, 3076,
      6461, 992,  4008, 3260, 4408, 4737, 1423, 3060, 8,    5161, 4684,
      3973, 5726, 4456, 4742, 2595, 5664, 1212, 3219, 1897};
  const uint64_t u64_rs3_m4[] = {5951, 4212, 3174, 5740, 2588, 3782,
                                 3525, 4994, 3778, 4153, 332,  3638,
                                 5408, 4090, 820,  5745};
  const uint64_t u64_ans_m4[] = {93868462,  64195126, 84232472,  114553694,
                                 129320180, 69495692, 121814863, 97861970,
                                 74219291,  55842630, 52722478,  57351561,
                                 57763049,  50723910, 77779127,  53150523};
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(8);
  muint16m1_t u16_ts1_m1 = mlae16_m1(u16_rs1_m1, 8 * sizeof(uint16_t));
  muint16m1_t u16_ts2_m1 = mlbe16_m1(u16_rs2_m1, 8 * sizeof(uint16_t));
  msettype(E64, M4, BA);
  msettileni(8);
  muint64m4_t u64_td_m4 = mlce64_m4(u64_rs3_m4, 8 * sizeof(uint64_t));
  msettype(E16, M1, BA);
  msettileni(8);
  muint64m4_t u64_out_m4 = mqmau_mm(u64_td_m4, u16_ts1_m1, u16_ts2_m1);
  msettype(E64, M4, BA);
  msettileni(8);
  msce64_m(u64_out_m4, u64_buffer, 8 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans_m4, u64_buffer, 2 * 8, "MQMAU.MM UINT16  M1");
}

static void test_mswmau_mm() {
  // M1
  const uint8_t u8_rs1_m1[] = {8823,  53758, 32841, 4666,  7145,  23089,
                               27218, 26710, 34782, 12875, 10230, 52284,
                               13461, 42313, 2775,  28427};
  const uint8_t u8_rs2_m1[] = {
      20850, 14523, 19046, 30353, 54535, 19933, 55526, 51238, 2504,  55210,
      41798, 22077, 28309, 52141, 6436,  44847, 53268, 3347,  24443, 31116,
      36120, 28099, 63419, 11899, 6986,  47736, 31961, 43367, 21271, 42646,
      52080, 3754,  57775, 22280, 63862, 13634, 50178, 15107, 23786, 62327,
      31481, 11589, 61147, 43554, 1908,  33267, 65132, 59578, 5838,  60936,
      35604, 3146,  24947, 65487, 21423, 54014, 59702, 7663,  33852, 63441,
      8014,  63508, 47736, 17864, 25164, 49309, 53484, 34267, 4786,  39339,
      29371, 20768, 44139, 62251, 22484, 54645, 11531, 41009, 59792, 29617,
      58223, 10053, 25046, 15248, 12692, 29173, 31004, 30932, 10707, 29787,
      11631, 52677, 9004,  44491, 48997, 8651,  32033, 12551, 35076, 58803,
      40504, 55033, 35950, 17666, 32664, 52528, 51039, 12045, 18137, 40183,
      36807, 46394, 11399, 45255, 14115, 39822, 48716, 5346,  27105, 37925,
      20981, 47771, 29343, 20375, 23549, 32544, 436,   52889};
  const uint16_t u16_rs3_m2[] = {
      54667, 6605,  29254, 29363, 24360, 31346, 24761, 29879,
      46447, 60002, 35644, 55369, 46058, 14163, 4445,  3431,
      38298, 58984, 37947, 14559, 25051, 50916, 4561,  23235,
      35458, 43734, 5893,  34699, 57816, 14554, 5858,  9223};
  const uint16_t u16_ans_m2[] = {
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535};
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(16);
  muint8m1_t u8_ts1_m1 = mlae8_m1(u8_rs1_m1, 8 * sizeof(uint8_t));
  muint8m1_t u8_ts2_m1 = mlbe8_m1(u8_rs2_m1, 16 * sizeof(uint8_t));
  msettype(E16, M2, BA);
  msettileni(16);
  muint16m2_t u16_td_m2 = mlce16_m2(u16_rs3_m2, 16 * sizeof(uint16_t));
  msettype(E8, M1, BA);
  msettileni(16);
  muint16m2_t u16_out_m2 = mswmau_mm(u16_td_m2, u8_ts1_m1, u8_ts2_m1);
  msettype(E16, M2, BA);
  msettileni(16);
  msce16_m(u16_out_m2, u16_buffer, 16 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans_m2, u16_buffer, 2 * 16, "MSWMAU.MM UINT8  M1");

  const uint16_t u16_rs1_m1[] = {55472, 28446, 43661, 56818, 26503, 12331,
                                 30374, 23804, 56491, 44348, 4056,  45121,
                                 22543, 33176, 22593, 14249};
  const uint16_t u16_rs2_m1[] = {
      45637, 15714, 33592, 58494, 5034,  10178, 28597, 14768, 52512, 56056,
      2063,  47223, 47801, 5403,  52348, 37846, 17896, 52536, 45817, 57557,
      55129, 36152, 22186, 150,   58055, 17653, 51351, 46637, 57548, 21317,
      38742, 62533, 21317, 44161, 37285, 34059, 12680, 36649, 32703, 15927,
      32799, 8336,  51555, 63677, 10913, 47187, 33122, 61659, 38784, 286,
      23511, 22341, 32755, 2007,  51251, 52455, 23874, 51549, 21954, 32421,
      5086,  20880, 65482, 23335};
  const uint32_t u32_rs3_m2[] = {31545, 22040, 47400, 57891, 22132, 51931,
                                 6056,  25319, 47825, 63503, 42530, 56505,
                                 3919,  63136, 53008, 17994};
  const uint32_t u32_ans_m2[] = {
      4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295,
      4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295,
      4294967295, 4294967295, 4294967295, 4294967295};
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(8);
  muint16m1_t u16_ts1_m1 = mlae16_m1(u16_rs1_m1, 8 * sizeof(uint16_t));
  muint16m1_t u16_ts2_m1 = mlbe16_m1(u16_rs2_m1, 8 * sizeof(uint16_t));
  msettype(E32, M2, BA);
  msettileni(8);
  muint32m2_t u32_td_m2 = mlce32_m2(u32_rs3_m2, 8 * sizeof(uint32_t));
  msettype(E16, M1, BA);
  msettileni(8);
  muint32m2_t u32_out_m2 = mswmau_mm(u32_td_m2, u16_ts1_m1, u16_ts2_m1);
  msettype(E32, M2, BA);
  msettileni(8);
  msce32_m(u32_out_m2, u32_buffer, 8 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans_m2, u32_buffer, 2 * 8, "MSWMAU.MM UINT16 M1");

  const uint32_t u32_rs1_m1[] = {4294967295, 4294967295, 4294967295,
                                 4294967295, 4294967295, 4294967295,
                                 4294967295, 4294967295};
  const uint32_t u32_rs2_m1[] = {
      4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295,
      4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295,
      4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t u64_rs3_m2[] = {4294967295, 4294967295, 4294967295,
                                 4294967295, 4294967295, 4294967295,
                                 4294967295, 4294967295};
  const uint64_t u64_ans_m2[] = {18446744073709551615, 18446744073709551615,
                                 18446744073709551615, 18446744073709551615,
                                 18446744073709551615, 18446744073709551615,
                                 18446744073709551615, 18446744073709551615};
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(4);
  msettileni(4);
  muint32m1_t u32_ts1_m1 = mlae32_m1(u32_rs1_m1, 4 * sizeof(uint32_t));
  muint32m1_t u32_ts2_m1 = mlbe32_m1(u32_rs2_m1, 4 * sizeof(uint32_t));
  msettype(E64, M2, BA);
  msettileni(4);
  muint64m2_t u64_td_m2 = mlce64_m2(u64_rs3_m2, 4 * sizeof(uint64_t));
  msettype(E32, M1, BA);
  msettileni(4);
  muint64m2_t u64_out_m2 = mswmau_mm(u64_td_m2, u32_ts1_m1, u32_ts2_m1);
  msettype(E64, M2, BA);
  msettileni(4);
  msce64_m(u64_out_m2, u64_buffer, 4 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans_m2, u64_buffer, 2 * 4, "MSWMAU.MM UINT32 M1");
}

static void test_msqmau_mm() {
  const uint8_t u8_src1_m1[] = {130, 126, 93, 235, 105, 44,  27,  144,
                                8,   90,  93, 116, 14,  190, 106, 83};
  const uint8_t u8_src2_m1[] = {
      90,  131, 113, 146, 38,  197, 62,  9,   66,  81,  75,  39,  195, 32,  158,
      235, 131, 37,  9,   15,  168, 65,  243, 244, 115, 213, 58,  35,  85,  248,
      161, 70,  117, 1,   151, 108, 50,  160, 22,  180, 98,  39,  233, 193, 122,
      137, 160, 77,  248, 152, 141, 50,  39,  198, 77,  115, 183, 186, 69,  150,
      177, 169, 179, 120, 178, 179, 169, 130, 224, 166, 122, 97,  141, 152, 64,
      1,   17,  112, 89,  164, 227, 85,  235, 158, 91,  89,  17,  251, 209, 112,
      254, 154, 82,  187, 43,  154, 199, 143, 121, 136, 115, 162, 70,  204, 175,
      152, 28,  249, 234, 106, 147, 100, 246, 117, 121, 41,  190, 116, 119, 154,
      95,  36,  73,  19,  199, 126, 211, 215};
  const uint32_t u32_src3_m4[] = {239, 0,   75,  4,   176, 113, 254, 10,
                                  136, 212, 107, 52,  192, 164, 10,  176,
                                  5,   47,  116, 223, 207, 53,  51,  83,
                                  149, 149, 78,  137, 213, 55,  224, 190};
  const uint32_t u32_ans_m4[] = {
      167081, 100749, 111853, 72846, 98088,  137747, 91657,  124602,
      117731, 115093, 84213,  79071, 129560, 129022, 143371, 132563,
      139298, 65675,  102114, 68244, 73191,  91361,  55630,  135649,
      109488, 87678,  93754,  96193, 98440,  113768, 94133,  89452};
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(16);
  muint8m1_t u8_ts1_m1 = mlae8_m1(u8_src1_m1, 8 * sizeof(uint8_t));
  muint8m1_t u8_ts2_m1 = mlbe8_m1(u8_src2_m1, 16 * sizeof(uint8_t));
  msettype(E32, M4, BA);
  msettileni(16);
  muint32m4_t u32_td_m4 = mlce32_m4(u32_src3_m4, 16 * sizeof(uint32_t));
  msettype(E8, M1, BA);
  msettileni(16);
  muint32m4_t u32_out_m4 = msqmau_mm(u32_td_m4, u8_ts1_m1, u8_ts2_m1);
  msettype(E32, M4, BA);
  msettileni(16);
  msce32_m(u32_out_m4, u32_buffer, 16 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans_m4, u32_buffer, 2 * 16, "MSWMAU.MM UINT8  M1");

  const uint16_t u16_src1_m1[] = {21496, 12599, 49211, 47954, 25116, 29011,
                                  30328, 20326, 49137, 42689, 48147, 59515,
                                  35153, 49614, 1743,  11058};
  const uint16_t u16_src2_m1[] = {
      51748, 21425, 3694,  18295, 55552, 6831,  12074, 9417,  50545, 33963,
      14780, 11036, 34153, 18780, 38055, 56705, 43825, 31755, 21388, 18896,
      47243, 36295, 19209, 8784,  29306, 56221, 57023, 28503, 38841, 12531,
      13475, 47413, 17690, 45402, 59407, 50518, 36625, 12427, 24551, 17865,
      2975,  42506, 63535, 63373, 36721, 45131, 32377, 38897, 31003, 12567,
      51450, 45293, 22166, 27640, 6481,  25587, 58545, 45291, 61181, 53435,
      40476, 28252, 37515, 44608};
  const uint64_t u64_src3_m4[] = {36247, 62761, 21125, 32886, 65235, 9690,
                                  35491, 63416, 31503, 37140, 42228, 9026,
                                  42540, 58806, 62617, 41724};
  const uint64_t u64_ans_m4[] = {
      7972094128,  8822406577,  10191867082, 8396158793,
      9292113316,  5804410950,  4845505110,  6882672920,
      10025564408, 11605186021, 11242766216, 9566105207,
      12369462682, 6667253804,  6840224032,  9223870049};
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(8);
  muint16m1_t u16_ts1_m1 = mlae16_m1(u16_src1_m1, 8 * sizeof(uint16_t));
  muint16m1_t u16_ts2_m1 = mlbe16_m1(u16_src2_m1, 8 * sizeof(uint16_t));
  msettype(E64, M4, BA);
  msettileni(8);
  muint64m4_t u64_td_m4 = mlce64_m4(u64_src3_m4, 8 * sizeof(uint64_t));
  msettype(E16, M1, BA);
  msettileni(8);
  muint64m4_t u64_out_m4 = msqmau_mm(u64_td_m4, u16_ts1_m1, u16_ts2_m1);
  msettype(E64, M4, BA);
  msettileni(8);
  msce64_m(u64_out_m4, u64_buffer, 8 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans_m4, u64_buffer, 2 * 8, "MSWMAU.MM UINT16 M1");
}

static void test_mswma_mm() {
  // M1
  const int8_t i8_rs1_m1[] = {-24, 16,  -48, -85, -123, -125, 22,  -48,
                              19,  -93, -83, 48,  10,   -87,  -30, 18};
  const int8_t i8_rs2_m1[] = {
      -41,  -37,  92,   123,  -93, -113, -71,  -26, 98,   94,  123, -25,  -7,
      16,   104,  27,   34,   23,  -80,  -97,  44,  -23,  -15, -77, -85,  72,
      108,  -25,  -88,  -39,  -9,  -2,   46,   -33, 64,   -38, 30,  -122, 91,
      38,   44,   105,  107,  16,  -108, -39,  36,  108,  -58, -14, 102,  125,
      95,   35,   -28,  51,   -59, 105,  -70,  -99, 83,   -42, -15, -26,  -3,
      82,   37,   -97,  -87,  -17, -124, 111,  122, -74,  65,  -27, -67,  -78,
      52,   -117, -117, 112,  79,  -72,  -125, -29, -78,  -77, 7,   32,   -108,
      -124, -32,  99,   -9,   33,  -106, -70,  25,  21,   95,  -31, 69,   -120,
      -78,  75,   -70,  -42,  99,  -66,  115,  35,  -104, 67,  -87, 14,   -107,
      -6,   114,  110,  -115, -85, 85,   -41,  -15, 53,   114, 58};
  const int16_t i16_rs3_m2[] = {112, -6,  -59, 125,  -7,  -69, 2,    69,
                                45,  -40, -49, -49,  19,  -11, -106, 121,
                                89,  106, -59, -100, -3,  -86, -2,   -100,
                                4,   83,  35,  105,  -29, -49, -6,   -87};
  const int16_t i16_ans_m2[] = {
      22016,  -24818, -24989, 7541,  26966, 10478, 20526,  -18646,
      -12841, -4277,  -574,   27663, 12047, -2354, -11412, 4719,
      1003,   -6287,  -106,   25328, 1437,  14887, -3325,  19250,
      4168,   -15806, -6237,  6915,  19844, -1356, -996,   -13647};
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(16);
  mint8m1_t i8_ts1_m1 = mlae8_m1(i8_rs1_m1, 8 * sizeof(int8_t));
  mint8m1_t i8_ts2_m1 = mlbe8_m1(i8_rs2_m1, 16 * sizeof(int8_t));
  msettype(E16, M2, BA);
  msettileni(16);
  mint16m2_t i16_td_m2 = mlce16_m2(i16_rs3_m2, 16 * sizeof(int16_t));
  msettype(E8, M1, BA);
  msettileni(16);
  mint16m2_t i16_oit_m2 = mswma_mm(i16_td_m2, i8_ts1_m1, i8_ts2_m1);
  msettype(E16, M2, BA);
  msettileni(16);
  msce16_m(i16_oit_m2, i16_buffer, 16 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans_m2, i16_buffer, 2 * 16, "MSWMA.MM INT8    M1");

  const int16_t i16_rs1_m1[] = {22133, -12795, 11021,  8341,   -18734, -26392,
                                10770, -5670,  -25191, -10725, 20734,  -4986,
                                -7016, 16985,  13560,  -25486};
  const int16_t i16_rs2_m1[] = {
      6546,   27974,  10599,  9910,   23082,  2879,   20978,  -32156,
      4001,   -2427,  28262,  10982,  3666,   -24670, -16691, -17286,
      -6645,  816,    -30825, 23229,  -29809, 21111,  -1611,  -5237,
      26259,  -11204, -26381, -25433, -19256, 15197,  9740,   -10993,
      -17833, 6858,   -28224, 1931,   -13509, 10980,  -30978, 6570,
      -19477, 15398,  -12856, 3435,   8876,   -1814,  30593,  25206,
      18407,  15158,  9922,   -9020,  -21646, 16129,  -22112, -27283,
      14558,  7998,   -23318, -28295, 25453,  -28317, 19765,  -5704};
  const int32_t i32_rs3_m2[] = {25709, -12572, 23474,  -10123, -11301, -5223,
                                17307, -21064, -9607,  -5676,  -12291, 23726,
                                940,   21017,  -16766, -29721};
  const int32_t i32_ans_m2[] = {
      1203327242,  148771219,   420349573,  59138749,   -383806866, 915233330,
      164088841,   -1689780394, -803652207, -390762293, -369226242, 884648739,
      -1839501876, 1386574942,  -498034460, 1099075019};
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(8);
  mint16m1_t i16_ts1_m1 = mlae16_m1(i16_rs1_m1, 8 * sizeof(int16_t));
  mint16m1_t i16_ts2_m1 = mlbe16_m1(i16_rs2_m1, 8 * sizeof(int16_t));
  msettype(E32, M2, BA);
  msettileni(8);
  mint32m2_t i32_td_m2 = mlce32_m2(i32_rs3_m2, 8 * sizeof(int32_t));
  msettype(E16, M1, BA);
  msettileni(8);
  mint32m2_t i32_oit_m2 = mswma_mm(i32_td_m2, i16_ts1_m1, i16_ts2_m1);
  msettype(E32, M2, BA);
  msettileni(8);
  msce32_m(i32_oit_m2, i32_buffer, 8 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans_m2, i32_buffer, 2 * 8, "MSWMA.MM INT16   M1");

  const int32_t i32_rs1_m1[] = {9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807};
  const int32_t i32_rs2_m1[] = {
      9223372036854775807, 9223372036854775807, 9223372036854775807,
      9223372036854775807, 9223372036854775807, 9223372036854775807,
      9223372036854775807, 9223372036854775807, 9223372036854775807,
      9223372036854775807, 9223372036854775807, 9223372036854775807,
      9223372036854775807, 9223372036854775807, 9223372036854775807,
      9223372036854775807};
  const int64_t i64_rs3_m2[] = {9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807};
  const int64_t i64_ans_m2[] = {9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807,
                                9223372036854775807, 9223372036854775807};
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(4);
  msettileni(4);
  mint32m1_t i32_ts1_m1 = mlae32_m1(i32_rs1_m1, 4 * sizeof(int32_t));
  mint32m1_t i32_ts2_m1 = mlbe32_m1(i32_rs2_m1, 4 * sizeof(int32_t));
  msettype(E64, M2, BA);
  msettileni(4);
  mint64m2_t i64_td_m2 = mlce64_m2(i64_rs3_m2, 4 * sizeof(int64_t));
  msettype(E32, M1, BA);
  msettileni(4);
  mint64m2_t i64_oit_m2 = mswma_mm(i64_td_m2, i32_ts1_m1, i32_ts2_m1);
  msettype(E64, M2, BA);
  msettileni(4);
  msce64_m(i64_oit_m2, i64_buffer, 4 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans_m2, i64_buffer, 2 * 4, "MSWMA.MM INT32   M1");
}

static void test_msqma_mm() {
  const int8_t i8_src1_m1[] = {17, -115, -76, -35, -74, 2,  -116, -122,
                               34, 29,   65,  -81, -49, 60, 119,  -31};
  const int8_t i8_src2_m1[] = {
      126,  -3,   -100, -65,  61,   -109, -113, -37,  45,  -46, -109, 62,   90,
      -92,  18,   -98,  -16,  -120, 28,   -82,  121,  -58, 12,  -63,  73,   -35,
      -44,  8,    -98,  25,   -87,  72,   -76,  29,   -64, -4,  -104, -105, 85,
      -119, 108,  71,   -31,  13,   -34,  -118, 107,  50,  108, -18,  81,   69,
      -31,  -22,  -101, 25,   -75,  -127, 69,   -87,  100, -23, -20,  -40,  84,
      -14,  6,    49,   19,   91,   -43,  90,   47,   -81, 121, 99,   -75,  -31,
      -52,  0,    60,   -83,  -70,  70,   -82,  -27,  -55, 0,   -95,  -51,  63,
      -52,  30,   -63,  123,  32,   -80,  74,   -109, -65, -81, 46,   -3,   67,
      -64,  66,   80,   -100, -83,  -35,  -91,  17,   12,  -60, -53,  29,   37,
      13,   -106, 60,   -60,  25,   -45,  -122, 108,  -64, -52, -114};
  const int32_t i32_src3_m4[] = {-30, -92, 111,  -34, -46,  124, 107,  56,
                                 119, 74,  -127, 123, 81,   -84, 31,   4,
                                 97,  -89, 58,   7,   -54,  -84, -123, -40,
                                 -70, 72,  55,   5,   -123, 59,  35,   21};
  const int32_t i32_ans_m4[] = {
      7668,   11689, 15746,  6696,   -623,   -19,    10233, -6911,
      -2018,  -2448, -9597,  21368,  14027,  19286,  23904, -342,
      -20179, 6044,  -29073, -17265, -15357, -11523, 11825, -11182,
      2913,   20383, -3765,  -5852,  -17965, -12593, 7410,  12744};
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(16);
  mint8m1_t i8_ts1_m1 = mlae8_m1(i8_src1_m1, 8 * sizeof(int8_t));
  mint8m1_t i8_ts2_m1 = mlbe8_m1(i8_src2_m1, 16 * sizeof(int8_t));
  msettype(E32, M4, BA);
  msettileni(16);
  mint32m4_t i32_td_m4 = mlce32_m4(i32_src3_m4, 16 * sizeof(int32_t));
  msettype(E8, M1, BA);
  msettileni(16);
  mint32m4_t i32_oit_m4 = msqma_mm(i32_td_m4, i8_ts1_m1, i8_ts2_m1);
  msettype(E32, M4, BA);
  msettileni(16);
  msce32_m(i32_oit_m4, i32_buffer, 16 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans_m4, i32_buffer, 2 * 16, "MSWMA.MM INT8    M1");

  const int16_t i16_src1_m1[] = {-31177, -12246, -32553, 11744, 13455,  30305,
                                 10637,  -20671, 22933,  -5546, -21239, 3816,
                                 -16974, -27555, -27566, 11902};
  const int16_t i16_src2_m1[] = {
      16316,  -24194, 7552,   6201,   -13629, -479,   -6440,  12390,
      30364,  -4329,  21696,  -16015, 16578,  19886,  -25650, 9721,
      -27141, 12319,  -21636, 1359,   14763,  -969,   -31027, 25441,
      26024,  30258,  -28221, 15782,  5119,   26128,  -10506, 9263,
      -28671, -24505, -2349,  29420,  24210,  30540,  32098,  28011,
      12970,  11242,  22416,  1090,   30539,  -5175,  -24464, 5385,
      360,    25097,  9811,   -3924,  6733,   -27596, 3583,   20151,
      25809,  23900,  9843,   -24604, 25037,  31322,  -30807, 4416};
  const int64_t i64_src3_m4[] = {875,   -24456, -15534, 20855, -2189, 23325,
                                 -726,  12175,  -26553, 17808, -4576, -18363,
                                 24553, -6708,  -7191,  10093};
  const int64_t i64_ans_m4[] = {
      -213754746,  545508285,  420341869,  1039644495, 606741592,  -577084148,
      1766949459,  -561566941, 1308032976, -978184815, -326404502, -451709183,
      -1838542334, 756722613,  277290922,  -1401522117};
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(8);
  mint16m1_t i16_ts1_m1 = mlae16_m1(i16_src1_m1, 8 * sizeof(int16_t));
  mint16m1_t i16_ts2_m1 = mlbe16_m1(i16_src2_m1, 8 * sizeof(int16_t));
  msettype(E64, M4, BA);
  msettileni(8);
  mint64m4_t i64_td_m4 = mlce64_m4(i64_src3_m4, 8 * sizeof(int64_t));
  msettype(E16, M1, BA);
  msettileni(8);
  mint64m4_t i64_oit_m4 = msqma_mm(i64_td_m4, i16_ts1_m1, i16_ts2_m1);
  msettype(E64, M4, BA);
  msettileni(8);
  msce64_m(i64_oit_m4, i64_buffer, 8 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans_m4, i64_buffer, 2 * 8, "MSWMA.MM INT16   M1");
}

static void test_mfwma_mm() {
  // M1
  // fp16
  const fp16_t fp16_rs1_m1[] = {-6.234, 0.4563, -6.62,  -5.984, -9.336, 7.035,
                                -6.758, 5.52,   -9.61,  9.79,   -5.516, -3.635,
                                -7.844, 2.146,  0.1259, 7.258};
  const fp16_t fp16_rs2_m1[] = {
      7.55,   -3.225, -5.277, -3.412, 1.429,  -1.342, -7.203, -9.27,
      7.77,   3.402,  -2.676, 5.168,  7.27,   -2.098, 6.668,  -7.36,
      7.695,  1.13,   5.723,  -9.41,  -1.973, -2.428, 9.82,   7.7,
      8.195,  -6.375, -4.508, -3.027, 2.629,  1.643,  2.547,  -7.555,
      1.464,  2.943,  1.194,  -6.4,   -9.05,  9.68,   -6.434, -6.426,
      -9.07,  7.99,   7.48,   1.852,  2.36,   -5.785, 3.7,    -3.227,
      -9.266, 4.715,  -9.945, 8.66,   -5.344, 6.117,  1.991,  3.562,
      2.72,   4.848,  1.527,  -9.3,   -2.639, 5.574,  -5.6,   -5.516};
  const fp32_t fp32_rs3_m2[] = {5.207, -2.873, 1.734, 2.857,  2.94,  2.248,
                                5.957, -4.883, -8.48, 0.5586, -8.56, 3.395,
                                7.227, -6.34,  7.49,  -2.918};
  const fp32_t fp32_ans_m2[] = {-138.125, 73.0625,  139.625,   69.875,
                                117.3125, -125.75,  15.359375, 26.59375,
                                -89.625,  111.625,  17.296875, 137.375,
                                122.1875, -53.6875, 96.5625,   3.0390625};
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(8);
  msettileni(8);
  mfloat16m1_t fp16_ts1_m1 = mlae16_m1(fp16_rs1_m1, 8 * sizeof(fp16_t));
  mfloat16m1_t fp16_ts2_m1 = mlbe16_m1(fp16_rs2_m1, 8 * sizeof(fp16_t));
  msettype(E32, M2, BA);
  msettileni(8);
  mfloat32m2_t fp32_td_m2 = mlce32_m2(fp32_rs3_m2, 8 * sizeof(fp32_t));
  msettype(E16, M1, BA);
  msettileni(8);
  mfloat32m2_t fp32_out_m2 = mfwma_mm(fp32_td_m2, fp16_ts1_m1, fp16_ts2_m1);
  msettype(E32, M2, BA);
  msettileni(8);
  msce32_m(fp32_out_m2, fp32_buffer, 8 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_LAX_EQ(fp32_ans_m2, fp32_buffer, 2 * 8,
                           "MFWMA.MM FP16    M1");
  // fp32
  const fp32_t fp32_rs1_m1[] = {92.40257,  -19.18781, 91.70403, 29.908648,
                                30.354364, 83.99179,  47.5756,  36.594406};
  const fp32_t fp32_rs2_m1[] = {78.52678,   -10.693922, -10.4567,   -9.441509,
                                80.08538,   93.41074,   10.5526705, 6.582024,
                                -12.083717, 17.942686,  24.076122,  84.74022,
                                -45.96785,  33.41252,   -2.0401752, 87.230286};
  const fp64_t fp64_rs3_m2[] = {93.12308558,  77.10079973, 94.94893373,
                                -14.42535347, 37.4117059,  -4.42112442,
                                35.19518775,  -84.36858976};
  const fp64_t fp64_ans_m2[] = {3329.57427303, -58.65283672,  1073.09888264,
                                9366.8203032,  6890.50033361, 9593.05315962,
                                1674.90337429, 7405.58390732};
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(4);
  msettileni(4);
  mfloat32m1_t fp32_ts1_m1 = mlae32_m1(fp32_rs1_m1, 4 * sizeof(fp32_t));
  mfloat32m1_t fp32_ts2_m1 = mlbe32_m1(fp32_rs2_m1, 4 * sizeof(fp32_t));
  msettype(E64, M2, BA);
  msettileni(4);
  mfloat64m2_t fp64_td_m2 = mlce64_m2(fp64_rs3_m2, 4 * sizeof(fp64_t));
  msettype(E32, M1, BA);
  msettileni(4);
  mfloat64m2_t fp64_out_m2 = mfwma_mm(fp64_td_m2, fp32_ts1_m1, fp32_ts2_m1);
  msettype(E64, M2, BA);
  msettileni(4);
  msce64_m(fp64_out_m2, fp64_buffer, 4 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_LAX_EQ(fp64_ans_m2, fp64_buffer, 2 * 4,
                           "MFWMA.MM FP32    M1");
}

int main() {
  test_mmau_mm();
  test_mma_mm();
  test_mfma_mm();
  test_msma_mm();
  test_msmau_mm();
  test_mwmau_mm();
  test_mqmau_mm();
  test_mswmau_mm();
  test_msqmau_mm();
  test_mswma_mm();
  test_msqma_mm();
  test_mfwma_mm();
  return 0;
}