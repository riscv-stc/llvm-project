#ifndef MATRIX_TESTS_ISA_CVT_H_
#define MATRIX_TESTS_ISA_CVT_H_

#include "riscv_matrix.h"
#include "utils.h"

static void test_mcvt_x_xu_mm_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  const uint8_t src[] = {18, 5, 21, 7,  17, 8,  23, 22, 17, 0,  10, 16, 12,
                         19, 8, 3,  23, 8,  0,  0,  10, 8,  16, 15, 22, 21,
                         3,  7, 12, 3,  16, 24, 14, 0,  9,  9,  18, 20, 7,
                         13, 4, 15, 15, 20, 11, 13, 18, 24, 5,  1,  14, 16,
                         11, 7, 16, 20, 4,  12, 8,  13, 19, 24, 12, 16};
  const int8_t ans[] = {18, 5, 21, 7,  17, 8,  23, 22, 17, 0,  10, 16, 12,
                        19, 8, 3,  23, 8,  0,  0,  10, 8,  16, 15, 22, 21,
                        3,  7, 12, 3,  16, 24, 14, 0,  9,  9,  18, 20, 7,
                        13, 4, 15, 15, 20, 11, 13, 18, 24, 5,  1,  14, 16,
                        11, 7, 16, 20, 4,  12, 8,  13, 19, 24, 12, 16};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, stride);
  mint8_t md = mcvt_x_xu_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MCVT_X_XU_MM U8");
}

static void test_mcvt_b_ub_mm() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  const uint8_t src[] = {18, 5, 21, 7,  17, 8,  23, 22, 17, 0,  10, 16, 12,
                         19, 8, 3,  23, 8,  0,  0,  10, 8,  16, 15, 22, 21,
                         3,  7, 12, 3,  16, 24, 14, 0,  9,  9,  18, 20, 7,
                         13, 4, 15, 15, 20, 11, 13, 18, 24, 5,  1,  14, 16,
                         11, 7, 16, 20, 4,  12, 8,  13, 19, 24, 12, 16};
  const int8_t ans[] = {18, 5, 21, 7,  17, 8,  23, 22, 17, 0,  10, 16, 12,
                        19, 8, 3,  23, 8,  0,  0,  10, 8,  16, 15, 22, 21,
                        3,  7, 12, 3,  16, 24, 14, 0,  9,  9,  18, 20, 7,
                        13, 4, 15, 15, 20, 11, 13, 18, 24, 5,  1,  14, 16,
                        11, 7, 16, 20, 4,  12, 8,  13, 19, 24, 12, 16};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, stride);
  mint8_t md = mcvt_b_ub_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MCVT_B_UB_MM");
}

static void test_mcvt_x_xu_mm_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  const uint16_t src[] = {
      1234, 915,  2851, 982,  3084, 2065, 4250, 6484, 6165, 173,  6061,
      6113, 624,  4718, 4728, 2834, 1308, 523,  2047, 1340, 3831, 3287,
      468,  3333, 83,   2191, 5643, 3296, 3010, 6017, 52,   1981, 554,
      2680, 3531, 2585, 479,  3646, 288,  3966, 582,  212,  6389, 6104,
      2368, 3520, 3802, 4774, 4561, 4673, 1351, 5013, 3665, 5466, 2492,
      3484, 3869, 1608, 407,  5165, 2092, 4350, 5031, 1545};
  const int16_t ans[] = {
      1234, 915,  2851, 982,  3084, 2065, 4250, 6484, 6165, 173,  6061,
      6113, 624,  4718, 4728, 2834, 1308, 523,  2047, 1340, 3831, 3287,
      468,  3333, 83,   2191, 5643, 3296, 3010, 6017, 52,   1981, 554,
      2680, 3531, 2585, 479,  3646, 288,  3966, 582,  212,  6389, 6104,
      2368, 3520, 3802, 4774, 4561, 4673, 1351, 5013, 3665, 5466, 2492,
      3484, 3869, 1608, 407,  5165, 2092, 4350, 5031, 1545};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, stride);
  mint16_t md = mcvt_x_xu_m(ms);
  msc_m(md, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MCVT_X_XU_MM U16");
}

static void test_mcvt_h_uh_mm() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  const uint16_t src[] = {
      1234, 915,  2851, 982,  3084, 2065, 4250, 6484, 6165, 173,  6061,
      6113, 624,  4718, 4728, 2834, 1308, 523,  2047, 1340, 3831, 3287,
      468,  3333, 83,   2191, 5643, 3296, 3010, 6017, 52,   1981, 554,
      2680, 3531, 2585, 479,  3646, 288,  3966, 582,  212,  6389, 6104,
      2368, 3520, 3802, 4774, 4561, 4673, 1351, 5013, 3665, 5466, 2492,
      3484, 3869, 1608, 407,  5165, 2092, 4350, 5031, 1545};
  const int16_t ans[] = {
      1234, 915,  2851, 982,  3084, 2065, 4250, 6484, 6165, 173,  6061,
      6113, 624,  4718, 4728, 2834, 1308, 523,  2047, 1340, 3831, 3287,
      468,  3333, 83,   2191, 5643, 3296, 3010, 6017, 52,   1981, 554,
      2680, 3531, 2585, 479,  3646, 288,  3966, 582,  212,  6389, 6104,
      2368, 3520, 3802, 4774, 4561, 4673, 1351, 5013, 3665, 5466, 2492,
      3484, 3869, 1608, 407,  5165, 2092, 4350, 5031, 1545};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, stride);
  mint16_t md = mcvt_h_uh_m(ms);
  msc_m(md, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MCVT_H_UH_MM");
}

static void test_mcvt_x_xu_mm_u32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  const uint32_t src[] = {399160588, 47165147,  227730475, 32108358,
                          283907070, 10035257,  57388348,  328861114,
                          199969923, 185030541, 6612120,   68572625,
                          240388159, 353147102, 236155464, 260125918};
  const int32_t ans[] = {399160588, 47165147,  227730475, 32108358,
                         283907070, 10035257,  57388348,  328861114,
                         199969923, 185030541, 6612120,   68572625,
                         240388159, 353147102, 236155464, 260125918};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, stride);
  mint32_t md = mcvt_x_xu_m(ms);
  msc_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MCVT_X_XU_MM U32");
}

static void test_mcvt_w_uw_mm() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  const uint32_t src[] = {399160588, 47165147,  227730475, 32108358,
                          283907070, 10035257,  57388348,  328861114,
                          199969923, 185030541, 6612120,   68572625,
                          240388159, 353147102, 236155464, 260125918};
  const int32_t ans[] = {399160588, 47165147,  227730475, 32108358,
                         283907070, 10035257,  57388348,  328861114,
                         199969923, 185030541, 6612120,   68572625,
                         240388159, 353147102, 236155464, 260125918};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, stride);
  mint32_t md = mcvt_w_uw_m(ms);
  msc_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MCVT_W_UW_MM");
}

static void test_mcvt_x_xu_mm_u64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  const uint64_t src[] = {601601336887543914, 448326321320327304,
                          653790694205957067, 670404976798575524};
  const int64_t ans[] = {601601336887543914, 448326321320327304,
                         653790694205957067, 670404976798575524};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, stride);
  mint64_t md = mcvt_x_xu_m(ms);
  msc_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MCVT_X_XU_MM U64");
}

static void test_mcvt_dw_udw_mm() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  const uint64_t src[] = {601601336887543914, 448326321320327304,
                          653790694205957067, 670404976798575524};
  const int64_t ans[] = {601601336887543914, 448326321320327304,
                         653790694205957067, 670404976798575524};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, stride);
  mint64_t md = mcvt_dw_udw_m(ms);
  msc_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MCVT_D_UD_MM");
}

static void test_mcvt_x_xu_mm() {
  test_mcvt_x_xu_mm_u8();
  test_mcvt_b_ub_mm();
  test_mcvt_x_xu_mm_u16();
  test_mcvt_h_uh_mm();
  test_mcvt_x_xu_mm_u32();
  test_mcvt_w_uw_mm();
  test_mcvt_x_xu_mm_u64();
  test_mcvt_dw_udw_mm();
}

static void test_mcvt_xu_x_mm_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  const int8_t src[] = {18, 5, 21, 7,  17, 8,  23, 22, 17, 0,  10, 16, 12,
                        19, 8, 3,  23, 8,  0,  0,  10, 8,  16, 15, 22, 21,
                        3,  7, 12, 3,  16, 24, 14, 0,  9,  9,  18, 20, 7,
                        13, 4, 15, 15, 20, 11, 13, 18, 24, 5,  1,  14, 16,
                        11, 7, 16, 20, 4,  12, 8,  13, 19, 24, 12, 16};
  const uint8_t ans[] = {18, 5, 21, 7,  17, 8,  23, 22, 17, 0,  10, 16, 12,
                         19, 8, 3,  23, 8,  0,  0,  10, 8,  16, 15, 22, 21,
                         3,  7, 12, 3,  16, 24, 14, 0,  9,  9,  18, 20, 7,
                         13, 4, 15, 15, 20, 11, 13, 18, 24, 5,  1,  14, 16,
                         11, 7, 16, 20, 4,  12, 8,  13, 19, 24, 12, 16};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, stride);
  muint8_t md = mcvt_xu_x_m(ms);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MCVT_XU_X_MM I8");
}

static void test_mcvt_ub_b_mm() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  const int8_t src[] = {18, 5, 21, 7,  17, 8,  23, 22, 17, 0,  10, 16, 12,
                        19, 8, 3,  23, 8,  0,  0,  10, 8,  16, 15, 22, 21,
                        3,  7, 12, 3,  16, 24, 14, 0,  9,  9,  18, 20, 7,
                        13, 4, 15, 15, 20, 11, 13, 18, 24, 5,  1,  14, 16,
                        11, 7, 16, 20, 4,  12, 8,  13, 19, 24, 12, 16};
  const uint8_t ans[] = {18, 5, 21, 7,  17, 8,  23, 22, 17, 0,  10, 16, 12,
                         19, 8, 3,  23, 8,  0,  0,  10, 8,  16, 15, 22, 21,
                         3,  7, 12, 3,  16, 24, 14, 0,  9,  9,  18, 20, 7,
                         13, 4, 15, 15, 20, 11, 13, 18, 24, 5,  1,  14, 16,
                         11, 7, 16, 20, 4,  12, 8,  13, 19, 24, 12, 16};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, stride);
  muint8_t md = mcvt_ub_b_m(ms);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MCVT_UB_B_MM");
}

static void test_mcvt_xu_x_mm_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  const int16_t src[] = {
      1234, 915,  2851, 982,  3084, 2065, 4250, 6484, 6165, 173,  6061,
      6113, 624,  4718, 4728, 2834, 1308, 523,  2047, 1340, 3831, 3287,
      468,  3333, 83,   2191, 5643, 3296, 3010, 6017, 52,   1981, 554,
      2680, 3531, 2585, 479,  3646, 288,  3966, 582,  212,  6389, 6104,
      2368, 3520, 3802, 4774, 4561, 4673, 1351, 5013, 3665, 5466, 2492,
      3484, 3869, 1608, 407,  5165, 2092, 4350, 5031, 1545};
  const uint16_t ans[] = {
      1234, 915,  2851, 982,  3084, 2065, 4250, 6484, 6165, 173,  6061,
      6113, 624,  4718, 4728, 2834, 1308, 523,  2047, 1340, 3831, 3287,
      468,  3333, 83,   2191, 5643, 3296, 3010, 6017, 52,   1981, 554,
      2680, 3531, 2585, 479,  3646, 288,  3966, 582,  212,  6389, 6104,
      2368, 3520, 3802, 4774, 4561, 4673, 1351, 5013, 3665, 5466, 2492,
      3484, 3869, 1608, 407,  5165, 2092, 4350, 5031, 1545};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, stride);
  muint16_t md = mcvt_xu_x_m(ms);
  msc_m(md, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MCVT_XU_X_MM I16");
}

static void test_mcvt_uh_h_mm() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  const int16_t src[] = {
      1234, 915,  2851, 982,  3084, 2065, 4250, 6484, 6165, 173,  6061,
      6113, 624,  4718, 4728, 2834, 1308, 523,  2047, 1340, 3831, 3287,
      468,  3333, 83,   2191, 5643, 3296, 3010, 6017, 52,   1981, 554,
      2680, 3531, 2585, 479,  3646, 288,  3966, 582,  212,  6389, 6104,
      2368, 3520, 3802, 4774, 4561, 4673, 1351, 5013, 3665, 5466, 2492,
      3484, 3869, 1608, 407,  5165, 2092, 4350, 5031, 1545};
  const uint16_t ans[] = {
      1234, 915,  2851, 982,  3084, 2065, 4250, 6484, 6165, 173,  6061,
      6113, 624,  4718, 4728, 2834, 1308, 523,  2047, 1340, 3831, 3287,
      468,  3333, 83,   2191, 5643, 3296, 3010, 6017, 52,   1981, 554,
      2680, 3531, 2585, 479,  3646, 288,  3966, 582,  212,  6389, 6104,
      2368, 3520, 3802, 4774, 4561, 4673, 1351, 5013, 3665, 5466, 2492,
      3484, 3869, 1608, 407,  5165, 2092, 4350, 5031, 1545};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, stride);
  muint16_t md = mcvt_uh_h_m(ms);
  msc_m(md, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MCVT_UH_H_MM");
}

static void test_mcvt_xu_x_mm_i32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  const int32_t src[] = {399160588, 47165147,  227730475, 32108358,
                         283907070, 10035257,  57388348,  328861114,
                         199969923, 185030541, 6612120,   68572625,
                         240388159, 353147102, 236155464, 260125918};
  const uint32_t ans[] = {399160588, 47165147,  227730475, 32108358,
                          283907070, 10035257,  57388348,  328861114,
                          199969923, 185030541, 6612120,   68572625,
                          240388159, 353147102, 236155464, 260125918};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, stride);
  muint32_t md = mcvt_xu_x_m(ms);
  msc_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MCVT_XU_X_MM I32");
}

static void test_mcvt_uw_w_mm() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  const int32_t src[] = {399160588, 47165147,  227730475, 32108358,
                         283907070, 10035257,  57388348,  328861114,
                         199969923, 185030541, 6612120,   68572625,
                         240388159, 353147102, 236155464, 260125918};
  const uint32_t ans[] = {399160588, 47165147,  227730475, 32108358,
                          283907070, 10035257,  57388348,  328861114,
                          199969923, 185030541, 6612120,   68572625,
                          240388159, 353147102, 236155464, 260125918};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, stride);
  muint32_t md = mcvt_uw_w_m(ms);
  msc_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MCVT_UW_W_MM");
}

static void test_mcvt_xu_x_mm_i64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  const int64_t src[] = {601601336887543914, 448326321320327304,
                         653790694205957067, 670404976798575524};
  const uint64_t ans[] = {601601336887543914, 448326321320327304,
                          653790694205957067, 670404976798575524};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, stride);
  muint64_t md = mcvt_xu_x_m(ms);
  msc_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MCVT_XU_X_MM I64");
}

static void test_mcvt_udw_dw_mm() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  const int64_t src[] = {601601336887543914, 448326321320327304,
                         653790694205957067, 670404976798575524};
  const uint64_t ans[] = {601601336887543914, 448326321320327304,
                          653790694205957067, 670404976798575524};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, stride);
  muint64_t md = mcvt_udw_dw_m(ms);
  msc_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MCVT_UDW_DW_MM");
}

static void test_mcvt_xu_x_mm() {
  test_mcvt_xu_x_mm_i8();
  test_mcvt_ub_b_mm();
  test_mcvt_xu_x_mm_i16();
  test_mcvt_uh_h_mm();
  test_mcvt_xu_x_mm_i32();
  test_mcvt_uw_w_mm();
  test_mcvt_xu_x_mm_i64();
  test_mcvt_udw_dw_mm();
}

static void test_mwcvtu_xw_x_m_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const uint8_t src[] = {12, 8,  12, 16, 3,  8,  13, 5,  19, 19, 10, 22, 24,
                         0,  15, 22, 3,  7,  14, 3,  21, 8,  3,  15, 23, 15,
                         4,  20, 3,  14, 21, 2,  11, 2,  1,  13, 6,  18, 15,
                         22, 4,  21, 5,  0,  16, 21, 24, 21, 1,  12, 15, 14,
                         15, 23, 11, 4,  17, 18, 3,  10, 3,  23, 22, 11};
  const uint16_t ans[] = {12, 8,  12, 16, 3,  8,  13, 5,  19, 19, 10, 22, 24,
                          0,  15, 22, 3,  7,  14, 3,  21, 8,  3,  15, 23, 15,
                          4,  20, 3,  14, 21, 2,  11, 2,  1,  13, 6,  18, 15,
                          22, 4,  21, 5,  0,  16, 21, 24, 21, 1,  12, 15, 14,
                          15, 23, 11, 4,  17, 18, 3,  10, 3,  23, 22, 11};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, N * sizeof(uint8_t));
  muint16_t md = mwcvtu_xw_x_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MWCVTU_XW_X_M U8");
}

static void test_mwcvtu_h_b_m() {
  const size_t M = 8;
  const size_t N = 8;
  const uint8_t src[] = {12, 8,  12, 16, 3,  8,  13, 5,  19, 19, 10, 22, 24,
                         0,  15, 22, 3,  7,  14, 3,  21, 8,  3,  15, 23, 15,
                         4,  20, 3,  14, 21, 2,  11, 2,  1,  13, 6,  18, 15,
                         22, 4,  21, 5,  0,  16, 21, 24, 21, 1,  12, 15, 14,
                         15, 23, 11, 4,  17, 18, 3,  10, 3,  23, 22, 11};
  const uint16_t ans[] = {12, 8,  12, 16, 3,  8,  13, 5,  19, 19, 10, 22, 24,
                          0,  15, 22, 3,  7,  14, 3,  21, 8,  3,  15, 23, 15,
                          4,  20, 3,  14, 21, 2,  11, 2,  1,  13, 6,  18, 15,
                          22, 4,  21, 5,  0,  16, 21, 24, 21, 1,  12, 15, 14,
                          15, 23, 11, 4,  17, 18, 3,  10, 3,  23, 22, 11};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, N * sizeof(uint8_t));
  muint16_t md = mwcvtu_h_b_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MWCVTU_H_B_M");
}

static void test_mwcvtu_xw_x_m_u16() {
  const size_t M = 4;
  const size_t N = 4;
  const uint16_t src[] = {5284, 2914, 4269, 1926, 3088, 4791, 2460, 88,
                          1619, 4506, 141,  927,  618,  1957, 3851, 3236};
  const uint32_t ans[] = {5284, 2914, 4269, 1926, 3088, 4791, 2460, 88,
                          1619, 4506, 141,  927,  618,  1957, 3851, 3236};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, N * sizeof(uint16_t));
  muint32_t md = mwcvtu_xw_x_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MWCVTU_XW_X_M U16");
}

static void test_mwcvtu_w_h_m() {
  const size_t M = 4;
  const size_t N = 4;
  const uint16_t src[] = {5284, 2914, 4269, 1926, 3088, 4791, 2460, 88,
                          1619, 4506, 141,  927,  618,  1957, 3851, 3236};
  const uint32_t ans[] = {5284, 2914, 4269, 1926, 3088, 4791, 2460, 88,
                          1619, 4506, 141,  927,  618,  1957, 3851, 3236};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, N * sizeof(uint16_t));
  muint32_t md = mwcvtu_w_h_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MWCVTU_W_H_M");
}

static void test_mwcvtu_xw_x_m_u32() {
  const size_t M = 2;
  const size_t N = 2;
  const uint32_t src[] = {268138953, 30026089, 112520442, 385905210};
  const uint64_t ans[] = {268138953, 30026089, 112520442, 385905210};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  muint64_t md = mwcvtu_xw_x_m(ms);
  SET_MBA0_I64();
  msc_m(md, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MWCVTU_XW_X_M U32");
}

static void test_mwcvtu_dw_w_m() {
  const size_t M = 2;
  const size_t N = 2;
  const uint32_t src[] = {268138953, 30026089, 112520442, 385905210};
  const uint64_t ans[] = {268138953, 30026089, 112520442, 385905210};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  muint64_t md = mwcvtu_dw_w_m(ms);
  SET_MBA0_I64();
  msc_m(md, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MWCVTU_DW_W_M");
}

static void test_mwcvtu_xu_x_m() {
  test_mwcvtu_xw_x_m_u8();
  test_mwcvtu_h_b_m();
  test_mwcvtu_xw_x_m_u16();
  test_mwcvtu_w_h_m();
  test_mwcvtu_xw_x_m_u32();
  test_mwcvtu_dw_w_m();
}

static void test_mwcvtu_xq_x_m_u8() {
  const size_t M = 4;
  const size_t N = 4;
  const uint8_t src[] = {11,  142, 18,  229, 191, 90,  5,   86,
                         231, 65,  124, 17,  216, 217, 196, 175};
  const uint32_t ans[] = {11,  142, 18,  229, 191, 90,  5,   86,
                          231, 65,  124, 17,  216, 217, 196, 175};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, N * sizeof(uint8_t));
  muint32_t md = mwcvtu_xq_x_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MWCVTU_XQ_X_M U8");
}

static void test_mwcvtu_w_b_m() {
  const size_t M = 4;
  const size_t N = 4;
  const uint8_t src[] = {11,  142, 18,  229, 191, 90,  5,   86,
                         231, 65,  124, 17,  216, 217, 196, 175};
  const uint32_t ans[] = {11,  142, 18,  229, 191, 90,  5,   86,
                          231, 65,  124, 17,  216, 217, 196, 175};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, N * sizeof(uint8_t));
  muint32_t md = mwcvtu_w_b_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MWCVTU_W_B_M");
}

static void test_mwcvtu_xq_x_m() {
  test_mwcvtu_xq_x_m_u8();
  test_mwcvtu_w_b_m();
}

static void test_mwcvt_xw_x_m_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const int8_t src[] = {
      -101, -88,  -73,  9,   75,   5,   42,   40,  99,   -6,   -17,  -105, -29,
      28,   -107, -55,  45,  100,  -87, 65,   -71, 119,  82,   -23,  89,   41,
      -108, 100,  16,   -94, 32,   2,   18,   16,  -122, -120, -120, -121, -11,
      -110, -6,   -114, -5,  6,    80,  -119, 26,  -7,   -60,  56,   -68,  -11,
      69,   -72,  -14,  -15, -113, 122, 124,  77,  21,   -69,  18,   -79};
  const int16_t ans[] = {
      -101, -88,  -73,  9,   75,   5,   42,   40,  99,   -6,   -17,  -105, -29,
      28,   -107, -55,  45,  100,  -87, 65,   -71, 119,  82,   -23,  89,   41,
      -108, 100,  16,   -94, 32,   2,   18,   16,  -122, -120, -120, -121, -11,
      -110, -6,   -114, -5,  6,    80,  -119, 26,  -7,   -60,  56,   -68,  -11,
      69,   -72,  -14,  -15, -113, 122, 124,  77,  21,   -69,  18,   -79};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, N * sizeof(int8_t));
  mint16_t md = mwcvt_xw_x_m(ms);
  SET_MBA0_I16();
  msc_m(md, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MWCVT_XW_X_M I8");
}

static void test_mwcvt_h_b_m() {
  const size_t M = 8;
  const size_t N = 8;
  const int8_t src[] = {
      -101, -88,  -73,  9,   75,   5,   42,   40,  99,   -6,   -17,  -105, -29,
      28,   -107, -55,  45,  100,  -87, 65,   -71, 119,  82,   -23,  89,   41,
      -108, 100,  16,   -94, 32,   2,   18,   16,  -122, -120, -120, -121, -11,
      -110, -6,   -114, -5,  6,    80,  -119, 26,  -7,   -60,  56,   -68,  -11,
      69,   -72,  -14,  -15, -113, 122, 124,  77,  21,   -69,  18,   -79};
  const int16_t ans[] = {
      -101, -88,  -73,  9,   75,   5,   42,   40,  99,   -6,   -17,  -105, -29,
      28,   -107, -55,  45,  100,  -87, 65,   -71, 119,  82,   -23,  89,   41,
      -108, 100,  16,   -94, 32,   2,   18,   16,  -122, -120, -120, -121, -11,
      -110, -6,   -114, -5,  6,    80,  -119, 26,  -7,   -60,  56,   -68,  -11,
      69,   -72,  -14,  -15, -113, 122, 124,  77,  21,   -69,  18,   -79};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, N * sizeof(int8_t));
  mint16_t md = mwcvt_h_b_m(ms);
  SET_MBA0_I16();
  msc_m(md, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MWCVT_H_B_M");
}

static void test_mwcvt_xw_x_m_i16() {
  const size_t M = 4;
  const size_t N = 4;
  const int16_t src[] = {-30680, 24429,  -4190,  20824, 9362, 27793,
                         -18757, -7854,  -32722, 28880, 9038, 10789,
                         -26877, -25328, 21066,  20844};
  const int32_t ans[] = {-30680, 24429,  -4190,  20824, 9362, 27793,
                         -18757, -7854,  -32722, 28880, 9038, 10789,
                         -26877, -25328, 21066,  20844};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, N * sizeof(int16_t));
  mint32_t md = mwcvt_xw_x_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MWCVT_XW_X_M I16");
}

static void test_mwcvt_w_h_m() {
  const size_t M = 4;
  const size_t N = 4;
  const int16_t src[] = {-30680, 24429,  -4190,  20824, 9362, 27793,
                         -18757, -7854,  -32722, 28880, 9038, 10789,
                         -26877, -25328, 21066,  20844};
  const int32_t ans[] = {-30680, 24429,  -4190,  20824, 9362, 27793,
                         -18757, -7854,  -32722, 28880, 9038, 10789,
                         -26877, -25328, 21066,  20844};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, N * sizeof(int16_t));
  mint32_t md = mwcvt_w_h_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MWCVT_W_H_M");
}

static void test_mwcvt_xw_x_m_i32() {
  const size_t M = 2;
  const size_t N = 2;
  const int32_t src[] = {-1240923130, -120773641, 1104741238, -30229560};
  const int64_t ans[] = {-1240923130, -120773641, 1104741238, -30229560};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  mint64_t md = mwcvt_xw_x_m(ms);
  SET_MBA0_I64();
  msc_m(md, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MWCVT_XW_X_M I32");
}

static void test_mwcvt_dw_w_m() {
  const size_t M = 2;
  const size_t N = 2;
  const int32_t src[] = {-1240923130, -120773641, 1104741238, -30229560};
  const int64_t ans[] = {-1240923130, -120773641, 1104741238, -30229560};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  mint64_t md = mwcvt_dw_w_m(ms);
  SET_MBA0_I64();
  msc_m(md, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MWCVT_DW_W_M");
}

static void test_mwcvt_xw_x_m() {
  test_mwcvt_xw_x_m_i8();
  test_mwcvt_h_b_m();
  test_mwcvt_xw_x_m_i16();
  test_mwcvt_w_h_m();
  test_mwcvt_xw_x_m_i32();
  test_mwcvt_dw_w_m();
}

static void test_mwcvt_xq_x_m_i8() {
  const size_t M = 4;
  const size_t N = 4;
  const int8_t src[] = {112, 76, -43,  -52, 37,   37,  -81, -111,
                        -93, 87, -121, 108, -116, -11, -72, -43};
  const int32_t ans[] = {112, 76, -43,  -52, 37,   37,  -81, -111,
                         -93, 87, -121, 108, -116, -11, -72, -43};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, N * sizeof(int8_t));
  mint32_t md = mwcvt_xq_x_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MWCVT_XQ_X_M I8");
}

static void test_mwcvt_w_b_m() {
  const size_t M = 4;
  const size_t N = 4;
  const int8_t src[] = {112, 76, -43,  -52, 37,   37,  -81, -111,
                        -93, 87, -121, 108, -116, -11, -72, -43};
  const int32_t ans[] = {112, 76, -43,  -52, 37,   37,  -81, -111,
                         -93, 87, -121, 108, -116, -11, -72, -43};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, N * sizeof(int8_t));
  mint32_t md = mwcvt_w_b_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MWCVT_W_B_M");
}

static void test_mwcvt_xq_x_m() {
  test_mwcvt_xq_x_m_i8();
  test_mwcvt_w_b_m();
}

static void test_mncvtu_x_xw_m_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const uint16_t src[] = {12, 8,  12, 16, 3,  8,  13, 5,  19, 19, 10, 22, 24,
                          0,  15, 22, 3,  7,  14, 3,  21, 8,  3,  15, 23, 15,
                          4,  20, 3,  14, 21, 2,  11, 2,  1,  13, 6,  18, 15,
                          22, 4,  21, 5,  0,  16, 21, 24, 21, 1,  12, 15, 14,
                          15, 23, 11, 4,  17, 18, 3,  10, 3,  23, 22, 11};
  const uint8_t ans[] = {12, 8,  12, 16, 3,  8,  13, 5,  19, 19, 10, 22, 24,
                         0,  15, 22, 3,  7,  14, 3,  21, 8,  3,  15, 23, 15,
                         4,  20, 3,  14, 21, 2,  11, 2,  1,  13, 6,  18, 15,
                         22, 4,  21, 5,  0,  16, 21, 24, 21, 1,  12, 15, 14,
                         15, 23, 11, 4,  17, 18, 3,  10, 3,  23, 22, 11};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, N * sizeof(uint16_t));
  muint8_t md = mncvtu_x_xw_m(ms);
  SET_MBA0_I8();
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MNCVTU_X_XW_M U8");
}

static void test_mncvtu_b_h_m() {
  const size_t M = 8;
  const size_t N = 8;
  const uint16_t src[] = {12, 8,  12, 16, 3,  8,  13, 5,  19, 19, 10, 22, 24,
                          0,  15, 22, 3,  7,  14, 3,  21, 8,  3,  15, 23, 15,
                          4,  20, 3,  14, 21, 2,  11, 2,  1,  13, 6,  18, 15,
                          22, 4,  21, 5,  0,  16, 21, 24, 21, 1,  12, 15, 14,
                          15, 23, 11, 4,  17, 18, 3,  10, 3,  23, 22, 11};
  const uint8_t ans[] = {12, 8,  12, 16, 3,  8,  13, 5,  19, 19, 10, 22, 24,
                         0,  15, 22, 3,  7,  14, 3,  21, 8,  3,  15, 23, 15,
                         4,  20, 3,  14, 21, 2,  11, 2,  1,  13, 6,  18, 15,
                         22, 4,  21, 5,  0,  16, 21, 24, 21, 1,  12, 15, 14,
                         15, 23, 11, 4,  17, 18, 3,  10, 3,  23, 22, 11};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, N * sizeof(uint16_t));
  muint8_t md = mncvtu_b_h_m(ms);
  SET_MBA0_I8();
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MNCVTU_B_H_M U8");
}

static void test_mncvtu_x_xw_m_u32() {
  const size_t M = 4;
  const size_t N = 4;
  const uint32_t src[] = {5284, 2914, 4269, 1926, 3088, 4791, 2460, 88,
                          1619, 4506, 141,  927,  618,  1957, 3851, 3236};
  const uint16_t ans[] = {5284, 2914, 4269, 1926, 3088, 4791, 2460, 88,
                          1619, 4506, 141,  927,  618,  1957, 3851, 3236};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  muint16_t md = mncvtu_x_xw_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MNCVTU_X_XW_M U32");
}

static void test_mncvtu_h_w_m() {
  const size_t M = 4;
  const size_t N = 4;
  const uint32_t src[] = {5284, 2914, 4269, 1926, 3088, 4791, 2460, 88,
                          1619, 4506, 141,  927,  618,  1957, 3851, 3236};
  const uint16_t ans[] = {5284, 2914, 4269, 1926, 3088, 4791, 2460, 88,
                          1619, 4506, 141,  927,  618,  1957, 3851, 3236};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  muint16_t md = mncvtu_h_w_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MNCVTU_H_W_M");
}

static void test_mncvtu_x_xw_m_u64() {
  const size_t M = 2;
  const size_t N = 2;
  const uint64_t src[] = {268138953, 30026089, 112520442, 385905210};
  const uint32_t ans[] = {268138953, 30026089, 112520442, 385905210};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, N * sizeof(uint64_t));
  muint32_t md = mncvtu_x_xw_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MNCVTU_X_XW_M U64");
}

static void test_mncvtu_w_dw_m() {
  const size_t M = 2;
  const size_t N = 2;
  const uint64_t src[] = {268138953, 30026089, 112520442, 385905210};
  const uint32_t ans[] = {268138953, 30026089, 112520442, 385905210};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, N * sizeof(uint64_t));
  muint32_t md = mncvtu_w_dw_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MNCVTU_W_DW_M");
}

static void test_mncvtu_x_xw_m() {
  test_mncvtu_x_xw_m_u16();
  test_mncvtu_b_h_m();
  test_mncvtu_x_xw_m_u32();
  test_mncvtu_h_w_m();
  test_mncvtu_x_xw_m_u64();
  test_mncvtu_w_dw_m();
}

static void test_mncvtu_x_xq_m_u32() {
  const size_t M = 4;
  const size_t N = 4;
  const uint32_t src[] = {11,  142, 18,  229, 191, 90,  5,   86,
                          231, 65,  124, 17,  216, 217, 196, 175};
  const uint8_t ans[] = {11,  142, 18,  229, 191, 90,  5,   86,
                         231, 65,  124, 17,  216, 217, 196, 175};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  muint8_t md = mncvtu_x_xq_m(ms);
  SET_MBA0_I8();
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MNCVTU_X_XQ_M U32");
}

static void test_mncvtu_b_w_m() {
  const size_t M = 4;
  const size_t N = 4;
  const uint32_t src[] = {11,  142, 18,  229, 191, 90,  5,   86,
                          231, 65,  124, 17,  216, 217, 196, 175};
  const uint8_t ans[] = {11,  142, 18,  229, 191, 90,  5,   86,
                         231, 65,  124, 17,  216, 217, 196, 175};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  muint8_t md = mncvtu_b_w_m(ms);
  SET_MBA0_I8();
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MNCVTU_B_W_M");
}

static void test_mncvtu_x_xq_m() {
  test_mncvtu_x_xq_m_u32();
  test_mncvtu_b_w_m();
}

static void test_mncvt_x_xw_m_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const int16_t src[] = {
      -114, 92,  -103, 77,   100,  -106, -99, 39,  73,   81,  0,   69,  -4,
      -15,  29,  15,   -95,  -40,  -62,  103, 49,  49,   -34, -36, -4,  -122,
      103,  44,  94,   -119, 50,   46,   75,  -9,  -48,  116, 50,  79,  125,
      90,   -51, 116,  -44,  -92,  -36,  -36, -69, 62,   63,  36,  104, 80,
      -16,  -47, 8,    -99,  -111, -30,  -62, 86,  -127, -92, 99,  -113};
  const int8_t ans[] = {
      -114, 92,  -103, 77,   100,  -106, -99, 39,  73,   81,  0,   69,  -4,
      -15,  29,  15,   -95,  -40,  -62,  103, 49,  49,   -34, -36, -4,  -122,
      103,  44,  94,   -119, 50,   46,   75,  -9,  -48,  116, 50,  79,  125,
      90,   -51, 116,  -44,  -92,  -36,  -36, -69, 62,   63,  36,  104, 80,
      -16,  -47, 8,    -99,  -111, -30,  -62, 86,  -127, -92, 99,  -113};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, N * sizeof(int16_t));
  mint8_t md = mncvt_x_xw_m(ms);
  SET_MBA0_I8();
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MNCVT_X_XW_M I8");
}

static void test_mncvt_b_h_m() {
  const size_t M = 8;
  const size_t N = 8;
  const int16_t src[] = {
      -114, 92,  -103, 77,   100,  -106, -99, 39,  73,   81,  0,   69,  -4,
      -15,  29,  15,   -95,  -40,  -62,  103, 49,  49,   -34, -36, -4,  -122,
      103,  44,  94,   -119, 50,   46,   75,  -9,  -48,  116, 50,  79,  125,
      90,   -51, 116,  -44,  -92,  -36,  -36, -69, 62,   63,  36,  104, 80,
      -16,  -47, 8,    -99,  -111, -30,  -62, 86,  -127, -92, 99,  -113};
  const int8_t ans[] = {
      -114, 92,  -103, 77,   100,  -106, -99, 39,  73,   81,  0,   69,  -4,
      -15,  29,  15,   -95,  -40,  -62,  103, 49,  49,   -34, -36, -4,  -122,
      103,  44,  94,   -119, 50,   46,   75,  -9,  -48,  116, 50,  79,  125,
      90,   -51, 116,  -44,  -92,  -36,  -36, -69, 62,   63,  36,  104, 80,
      -16,  -47, 8,    -99,  -111, -30,  -62, 86,  -127, -92, 99,  -113};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, N * sizeof(int16_t));
  mint8_t md = mncvt_b_h_m(ms);
  SET_MBA0_I8();
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MNCVT_B_H_M I8");
}

static void test_mncvt_x_xw_m_i32() {
  const size_t M = 4;
  const size_t N = 4;
  const int32_t src[] = {32561, 8438,   -26260, 2856,  -19132, -2978,
                         14090, -15623, 4905,   18078, -5926,  19598,
                         6341,  27497,  21686,  -11326};
  const int16_t ans[] = {32561, 8438,   -26260, 2856,  -19132, -2978,
                         14090, -15623, 4905,   18078, -5926,  19598,
                         6341,  27497,  21686,  -11326};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  mint16_t md = mncvt_x_xw_m(ms);
  SET_MBA0_I16();
  msc_m(md, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MNCVT_X_XW_M I16");
}

static void test_mncvt_h_w_m() {
  const size_t M = 4;
  const size_t N = 4;
  const int32_t src[] = {32561, 8438,   -26260, 2856,  -19132, -2978,
                         14090, -15623, 4905,   18078, -5926,  19598,
                         6341,  27497,  21686,  -11326};
  const int16_t ans[] = {32561, 8438,   -26260, 2856,  -19132, -2978,
                         14090, -15623, 4905,   18078, -5926,  19598,
                         6341,  27497,  21686,  -11326};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  mint16_t md = mncvt_h_w_m(ms);
  SET_MBA0_I16();
  msc_m(md, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MNCVT_H_W_M");
}

static void test_mncvt_x_xw_m_i64() {
  const size_t M = 2;
  const size_t N = 2;
  const int64_t src[] = {126349448, -137082959, -554819163, 1072102062};
  const int32_t ans[] = {126349448, -137082959, -554819163, 1072102062};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, N * sizeof(int64_t));
  mint32_t md = mncvt_x_xw_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MNCVT_X_XW_M I64");
}

static void test_mncvt_w_dw_m() {
  const size_t M = 2;
  const size_t N = 2;
  const int64_t src[] = {126349448, -137082959, -554819163, 1072102062};
  const int32_t ans[] = {126349448, -137082959, -554819163, 1072102062};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, N * sizeof(int64_t));
  mint32_t md = mncvt_w_dw_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MNCVT_W_DW_M");
}

static void test_mncvt_x_xw_m() {
  test_mncvt_x_xw_m_i16();
  test_mncvt_b_h_m();
  test_mncvt_x_xw_m_i32();
  test_mncvt_h_w_m();
  test_mncvt_x_xw_m_i64();
  test_mncvt_w_dw_m();
}

static void test_mncvt_x_xq_m_i32() {
  const size_t M = 4;
  const size_t N = 4;
  const int32_t src[] = {-31, 27,  0,   -1, -117, -89, -49, -39,
                         27,  -52, -74, -8, -80,  -34, 114, 43};
  const int8_t ans[] = {-31, 27,  0,   -1, -117, -89, -49, -39,
                        27,  -52, -74, -8, -80,  -34, 114, 43};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  mint8_t md = mncvt_x_xq_m(ms);
  SET_MBA0_I8();
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MNCVT_X_XQ_M I32");
}

static void test_mncvt_b_w_m() {
  const size_t M = 4;
  const size_t N = 4;
  const int32_t src[] = {-31, 27,  0,   -1, -117, -89, -49, -39,
                         27,  -52, -74, -8, -80,  -34, 114, 43};
  const int8_t ans[] = {-31, 27,  0,   -1, -117, -89, -49, -39,
                        27,  -52, -74, -8, -80,  -34, 114, 43};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  mint8_t md = mncvt_b_w_m(ms);
  SET_MBA0_I8();
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MNCVT_B_W_M");
}

static void test_mncvt_x_xq_m() {
  test_mncvt_x_xq_m_i32();
  test_mncvt_b_w_m();
}

static void test_mfwcvt_fw_f_m_f16() {
  const size_t M = 4;
  const size_t N = 4;
  const fp16_t src[] = {-5.977, -0.625, 9.4,    -5.92, 7.574, 6.527,
                        -8.49,  -3.236, -0.802, 7.445, 9.9,   2.037,
                        -3.27,  -5.832, -7.395, 6.2};
  const fp32_t ans[] = {-5.9765625, -0.625,     9.3984375,  -5.921875,
                        7.5742188,  6.5273438,  -8.4921875, -3.2363281,
                        -0.8017578, 7.4453125,  9.8984375,  2.0371094,
                        -3.2695312, -5.8320312, -7.3945312, 6.1992188};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  SET_MBA0_F16F32();
  mfloat32_t md = mfwcvt_fw_f_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVT_FW_F_M F16");
}

static void test_mfwcvt_f_hf_m() {
  const size_t M = 4;
  const size_t N = 4;
  const fp16_t src[] = {-5.977, -0.625, 9.4,    -5.92, 7.574, 6.527,
                        -8.49,  -3.236, -0.802, 7.445, 9.9,   2.037,
                        -3.27,  -5.832, -7.395, 6.2};
  const fp32_t ans[] = {-5.9765625, -0.625,     9.3984375,  -5.921875,
                        7.5742188,  6.5273438,  -8.4921875, -3.2363281,
                        -0.8017578, 7.4453125,  9.8984375,  2.0371094,
                        -3.2695312, -5.8320312, -7.3945312, 6.1992188};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  SET_MBA0_F16F32();
  mfloat32_t md = mfwcvt_f_hf_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVT_F_HF_M");
}

static void test_mfwcvt_fw_f_m_f32() {
  const size_t M = 2;
  const size_t N = 2;
  const fp32_t src[] = {2.8509452, -4.681304, -0.8099796, -5.9195175};
  const fp64_t ans[] = {2.85094523, -4.68130398, -0.80997962, -5.91951752};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  SET_MBA0_F32F64();
  mfloat64_t md = mfwcvt_fw_f_m(ms);
  SET_MBA0_F64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFWCVT_FW_F_M F32");
}

static void test_mfwcvt_d_f_m() {
  const size_t M = 2;
  const size_t N = 2;
  const fp32_t src[] = {2.8509452, -4.681304, -0.8099796, -5.9195175};
  const fp64_t ans[] = {2.85094523, -4.68130398, -0.80997962, -5.91951752};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  SET_MBA0_F32F64();
  mfloat64_t md = mfwcvt_d_f_m(ms);
  SET_MBA0_F64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFWCVT_D_F_M");
}

static void test_mfwcvt_fw_f_m() {
  test_mfwcvt_fw_f_m_f16();
  test_mfwcvt_f_hf_m();
  test_mfwcvt_fw_f_m_f32();
  test_mfwcvt_d_f_m();
}

static void test_mfncvt_f_fw_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {5.7890763, 8.184729,   8.007646,  9.454458,
                             8.628189,  9.514302,   2.2347643, 5.6848106,
                             1.5889733, 0.15968712, 8.053196,  -1.8102956,
                             -1.191435, 5.9232635,  -9.275991, 8.376175};
  const fp16_t ans[M * N] = {5.79,   8.19,  8.01,  9.45,   8.625, 9.516,
                             2.234,  5.684, 1.589, 0.1597, 8.055, -1.811,
                             -1.191, 5.92,  -9.27, 8.375};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x2);
  msettypehi(0x5);
  mfloat16_t md = mfncvt_f_fw_m(ms);
  SET_MBA0_F16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFNCVT_F_FW_M F32");
}

static void test_mfncvt_hf_f_m() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {5.7890763, 8.184729,   8.007646,  9.454458,
                             8.628189,  9.514302,   2.2347643, 5.6848106,
                             1.5889733, 0.15968712, 8.053196,  -1.8102956,
                             -1.191435, 5.9232635,  -9.275991, 8.376175};
  const fp16_t ans[M * N] = {5.79,   8.19,  8.01,  9.45,   8.625, 9.516,
                             2.234,  5.684, 1.589, 0.1597, 8.055, -1.811,
                             -1.191, 5.92,  -9.27, 8.375};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x2);
  msettypehi(0x5);
  mfloat16_t md = mfncvt_hf_f_m(ms);
  SET_MBA0_F16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFNCVT_HF_F_M");
}

static void test_mfncvt_f_fw_m_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {8.05565967, -8.58338394, -7.658707, 2.21663383};
  const fp32_t ans[M * N] = {8.055659, -8.583384, -7.658707, 2.2166338};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  msettypei(0x3);
  msettypehi(0x14);
  mfloat32_t md = mfncvt_f_fw_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFNCVT_F_FW_M F64");
}

static void test_mfncvt_f_d_m() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {8.05565967, -8.58338394, -7.658707, 2.21663383};
  const fp32_t ans[M * N] = {8.055659, -8.583384, -7.658707, 2.2166338};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  msettypei(0x3);
  msettypehi(0x14);
  mfloat32_t md = mfncvt_f_d_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFNCVT_F_D_M");
}

static void test_mfncvt_f_fw_m() {
  test_mfncvt_f_fw_m_f32();
  test_mfncvt_hf_f_m();
  test_mfncvt_f_fw_m_f64();
  test_mfncvt_f_d_m();
}

static void test_mfcvtu_f_x_m_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const uint16_t src[M * N] = {
      515, 263, 309, 182, 603, 439, 328, 281, 608, 75,  184, 334, 287,
      202, 453, 322, 427, 79,  647, 444, 520, 253, 483, 536, 614, 303,
      590, 361, 455, 139, 466, 637, 173, 125, 151, 82,  24,  104, 631,
      601, 463, 266, 427, 111, 525, 543, 399, 431, 488, 24,  557, 647,
      376, 444, 137, 552, 336, 345, 320, 442, 548, 119, 231, 296};
  const fp16_t ans[M * N] = {
      515., 263., 309., 182., 603., 439., 328., 281., 608., 75.,  184.,
      334., 287., 202., 453., 322., 427., 79.,  647., 444., 520., 253.,
      483., 536., 614., 303., 590., 361., 455., 139., 466., 637., 173.,
      125., 151., 82.,  24.,  104., 631., 601., 463., 266., 427., 111.,
      525., 543., 399., 431., 488., 24.,  557., 647., 376., 444., 137.,
      552., 336., 345., 320., 442., 548., 119., 231., 296.};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, N * sizeof(uint16_t));
  SET_MBA0_F16I16();
  mfloat16_t md = mfcvtu_f_x_m(ms);
  SET_MBA0_I16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFCVTU_F_X_M U16");
}

static void test_mfcvtu_hf_h_m() {
  const size_t M = 8;
  const size_t N = 8;
  const uint16_t src[M * N] = {
      515, 263, 309, 182, 603, 439, 328, 281, 608, 75,  184, 334, 287,
      202, 453, 322, 427, 79,  647, 444, 520, 253, 483, 536, 614, 303,
      590, 361, 455, 139, 466, 637, 173, 125, 151, 82,  24,  104, 631,
      601, 463, 266, 427, 111, 525, 543, 399, 431, 488, 24,  557, 647,
      376, 444, 137, 552, 336, 345, 320, 442, 548, 119, 231, 296};
  const fp16_t ans[M * N] = {
      515., 263., 309., 182., 603., 439., 328., 281., 608., 75.,  184.,
      334., 287., 202., 453., 322., 427., 79.,  647., 444., 520., 253.,
      483., 536., 614., 303., 590., 361., 455., 139., 466., 637., 173.,
      125., 151., 82.,  24.,  104., 631., 601., 463., 266., 427., 111.,
      525., 543., 399., 431., 488., 24.,  557., 647., 376., 444., 137.,
      552., 336., 345., 320., 442., 548., 119., 231., 296.};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, N * sizeof(uint16_t));
  SET_MBA0_F16I16();
  mfloat16_t md = mfcvtu_hf_h_m(ms);
  SET_MBA0_I16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFCVTU_HF_H_M");
}

static void test_mfcvtu_f_x_m_u32() {
  const size_t M = 4;
  const size_t N = 4;
  const uint32_t src[M * N] = {9140637,  34187540, 1798381,  16856700,
                               42758607, 31985571, 26498075, 594677,
                               26815740, 24307850, 4395831,  24794490,
                               39885504, 31640997, 16915489, 40953684};
  const fp32_t ans[M * N] = {9140637.,  34187540., 1798381.,  16856700.,
                             42758608., 31985572., 26498076., 594677.,
                             26815740., 24307850., 4395831.,  24794490.,
                             39885504., 31640996., 16915488., 40953684.};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  SET_MBA0_F32I32();
  mfloat32_t md = mfcvtu_f_x_m(ms);
  SET_MBA0_I32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFCVTU_F_X_M U32");
}

static void test_mfcvtu_f_w_m() {
  const size_t M = 4;
  const size_t N = 4;
  const uint32_t src[M * N] = {9140637,  34187540, 1798381,  16856700,
                               42758607, 31985571, 26498075, 594677,
                               26815740, 24307850, 4395831,  24794490,
                               39885504, 31640997, 16915489, 40953684};
  const fp32_t ans[M * N] = {9140637.,  34187540., 1798381.,  16856700.,
                             42758608., 31985572., 26498076., 594677.,
                             26815740., 24307850., 4395831.,  24794490.,
                             39885504., 31640996., 16915488., 40953684.};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  SET_MBA0_F32I32();
  mfloat32_t md = mfcvtu_f_w_m(ms);
  SET_MBA0_I32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFCVTU_F_W_M");
}

static void test_mfcvtu_f_x_m_u64() {
  const size_t M = 2;
  const size_t N = 2;
  const uint64_t src[M * N] = {63341086384475288, 21883693986688246,
                               183319118430459969, 142279137668842118};
  const fp64_t ans[M * N] = {63341086384475288, 21883693986688246,
                             183319118430459969, 142279137668842118};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, N * sizeof(uint64_t));
  SET_MBA0_F64I64();
  mfloat64_t md = mfcvtu_f_x_m(ms);
  SET_MBA0_I64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFCVTU_F_X_M U64");
}

static void test_mfcvtu_d_dw_m() {
  const size_t M = 2;
  const size_t N = 2;
  const uint64_t src[M * N] = {63341086384475288, 21883693986688246,
                               183319118430459969, 142279137668842118};
  const fp64_t ans[M * N] = {63341086384475288, 21883693986688246,
                             183319118430459969, 142279137668842118};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, N * sizeof(uint64_t));
  SET_MBA0_F64I64();
  mfloat64_t md = mfcvtu_d_dw_m(ms);
  SET_MBA0_I64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFCVTU_D_DW_M");
}

static void test_mfcvtu_f_x_m() {
  test_mfcvtu_f_x_m_u16();
  test_mfcvtu_hf_h_m();
  test_mfcvtu_f_x_m_u32();
  test_mfcvtu_f_w_m();
  test_mfcvtu_f_x_m_u64();
  test_mfcvtu_d_dw_m();
}

static void test_mfcvt_f_x_m_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const int16_t src[M * N] = {
      28,  10, -1,  22, 5,   31, 24, -22, 2,  2,  -13, 29, 13, 14,  23,  -6,
      20,  -8, -27, 25, 21,  18, -4, 3,   28, -4, -16, 26, 5,  -10, -30, 7,
      16,  4,  -19, 21, -10, 12, 21, 9,   7,  7,  -15, 22, 17, -2,  -23, -28,
      -22, 15, 12,  18, 16,  -9, 11, 7,   -7, 28, -30, 18, 28, -29, -11, 7};
  const fp16_t ans[M * N] = {
      28.,  10., -1., 22.,  5.,   31.,  24.,  -22., 2.,   2.,   -13., 29., 13.,
      14.,  23., -6., 20.,  -8.,  -27., 25.,  21.,  18.,  -4.,  3.,   28., -4.,
      -16., 26., 5.,  -10., -30., 7.,   16.,  4.,   -19., 21.,  -10., 12., 21.,
      9.,   7.,  7.,  -15., 22.,  17.,  -2.,  -23., -28., -22., 15.,  12., 18.,
      16.,  -9., 11., 7.,   -7.,  28.,  -30., 18.,  28.,  -29., -11., 7.};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, N * sizeof(int16_t));
  SET_MBA0_F16I16();
  mfloat16_t md = mfcvt_f_x_m(ms);
  SET_MBA0_I16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFCVT_F_X_M I16");
}

static void test_mfcvt_hf_h_m() {
  const size_t M = 8;
  const size_t N = 8;
  const int16_t src[M * N] = {
      28,  10, -1,  22, 5,   31, 24, -22, 2,  2,  -13, 29, 13, 14,  23,  -6,
      20,  -8, -27, 25, 21,  18, -4, 3,   28, -4, -16, 26, 5,  -10, -30, 7,
      16,  4,  -19, 21, -10, 12, 21, 9,   7,  7,  -15, 22, 17, -2,  -23, -28,
      -22, 15, 12,  18, 16,  -9, 11, 7,   -7, 28, -30, 18, 28, -29, -11, 7};
  const fp16_t ans[M * N] = {
      28.,  10., -1., 22.,  5.,   31.,  24.,  -22., 2.,   2.,   -13., 29., 13.,
      14.,  23., -6., 20.,  -8.,  -27., 25.,  21.,  18.,  -4.,  3.,   28., -4.,
      -16., 26., 5.,  -10., -30., 7.,   16.,  4.,   -19., 21.,  -10., 12., 21.,
      9.,   7.,  7.,  -15., 22.,  17.,  -2.,  -23., -28., -22., 15.,  12., 18.,
      16.,  -9., 11., 7.,   -7.,  28.,  -30., 18.,  28.,  -29., -11., 7.};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, N * sizeof(int16_t));
  SET_MBA0_F16I16();
  mfloat16_t md = mfcvt_hf_h_m(ms);
  SET_MBA0_I16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFCVT_HF_H_M");
}

static void test_mfcvt_f_x_m_i32() {
  const size_t M = 4;
  const size_t N = 4;
  const int32_t src[M * N] = {6952514,   -4006579, 5606980,   -8678697,
                              2891339,   -5780478, -367080,   -8485659,
                              -11931673, -5088219, -16366061, 11789956,
                              14726974,  5509832,  20897407,  9463808};
  const fp32_t ans[M * N] = {6952514.,   -4006579., 5606980.,   -8678697.,
                             2891339.,   -5780478., -367080.,   -8485659.,
                             -11931673., -5088219., -16366061., 11789956.,
                             14726974.,  5509832.,  20897408.,  9463808.};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  SET_MBA0_F32I32();
  mfloat32_t md = mfcvt_f_x_m(ms);
  SET_MBA0_I32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFCVT_F_X_M I32");
}

static void test_mfcvt_f_w_m() {
  const size_t M = 4;
  const size_t N = 4;
  const int32_t src[M * N] = {6952514,   -4006579, 5606980,   -8678697,
                              2891339,   -5780478, -367080,   -8485659,
                              -11931673, -5088219, -16366061, 11789956,
                              14726974,  5509832,  20897407,  9463808};
  const fp32_t ans[M * N] = {6952514.,   -4006579., 5606980.,   -8678697.,
                             2891339.,   -5780478., -367080.,   -8485659.,
                             -11931673., -5088219., -16366061., 11789956.,
                             14726974.,  5509832.,  20897408.,  9463808.};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  SET_MBA0_F32I32();
  mfloat32_t md = mfcvt_f_w_m(ms);
  SET_MBA0_I32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFCVT_F_W_M");
}

static void test_mfcvt_f_x_m_i64() {
  const size_t M = 2;
  const size_t N = 2;
  const int64_t src[M * N] = {-2916, 1613, 344, -2580};
  const fp64_t ans[M * N] = {-2916., 1613., 344., -2580.};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, N * sizeof(int64_t));
  SET_MBA0_F64I64();
  mfloat64_t md = mfcvt_f_x_m(ms);
  SET_MBA0_I64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFCVT_F_X_M I64");
}

static void test_mfcvt_d_dw_m() {
  const size_t M = 2;
  const size_t N = 2;
  const int64_t src[M * N] = {-2916, 1613, 344, -2580};
  const fp64_t ans[M * N] = {-2916., 1613., 344., -2580.};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, N * sizeof(int64_t));
  SET_MBA0_F64I64();
  mfloat64_t md = mfcvt_d_dw_m(ms);
  SET_MBA0_I64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFCVT_D_DW_M");
}

static void test_mfcvt_f_x_m() {
  test_mfcvt_f_x_m_i16();
  test_mfcvt_hf_h_m();
  test_mfcvt_f_x_m_i32();
  test_mfcvt_f_w_m();
  test_mfcvt_f_x_m_i64();
  test_mfcvt_d_dw_m();
}

static void test_mfwcvt_fw_x_m_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const int8_t src[M * N] = {
      8,   2,   -7, -7, 7,  -12, 0,  6, 7,  -7, 2,  -12, -2,  -12, 5,  -6,
      -11, -6,  -6, -5, -7, 9,   -8, 9, -5, -6, -9, 5,   3,   -1,  3,  -11,
      3,   -9,  3,  -7, -1, 6,   -1, 3, -2, -6, -5, -5,  3,   3,   -8, 8,
      7,   -12, 10, 6,  7,  5,   -4, 6, 9,  -6, 0,  -1,  -12, -11, 7,  9};
  const fp16_t ans[M * N] = {
      8.,   2.,  -7., -7.,  7.,  -12., 0.,  6.,  7.,   -7.,  2.,   -12., -2.,
      -12., 5.,  -6., -11., -6., -6.,  -5., -7., 9.,   -8.,  9.,   -5.,  -6.,
      -9.,  5.,  3.,  -1.,  3.,  -11., 3.,  -9., 3.,   -7.,  -1.,  6.,   -1.,
      3.,   -2., -6., -5.,  -5., 3.,   3.,  -8., 8.,   7.,   -12., 10.,  6.,
      7.,   5.,  -4., 6.,   9.,  -6.,  0.,  -1., -12., -11., 7.,   9.};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, N * sizeof(int8_t));
  SET_MBA0_F16I8();
  mfloat16_t md = mfwcvt_fw_x_m(ms);
  SET_MBA0_F16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFWCVT_FW_X_M I8");
}

static void test_mfwcvt_hf_b_m() {
  const size_t M = 8;
  const size_t N = 8;
  const int8_t src[M * N] = {
      8,   2,   -7, -7, 7,  -12, 0,  6, 7,  -7, 2,  -12, -2,  -12, 5,  -6,
      -11, -6,  -6, -5, -7, 9,   -8, 9, -5, -6, -9, 5,   3,   -1,  3,  -11,
      3,   -9,  3,  -7, -1, 6,   -1, 3, -2, -6, -5, -5,  3,   3,   -8, 8,
      7,   -12, 10, 6,  7,  5,   -4, 6, 9,  -6, 0,  -1,  -12, -11, 7,  9};
  const fp16_t ans[M * N] = {
      8.,   2.,  -7., -7.,  7.,  -12., 0.,  6.,  7.,   -7.,  2.,   -12., -2.,
      -12., 5.,  -6., -11., -6., -6.,  -5., -7., 9.,   -8.,  9.,   -5.,  -6.,
      -9.,  5.,  3.,  -1.,  3.,  -11., 3.,  -9., 3.,   -7.,  -1.,  6.,   -1.,
      3.,   -2., -6., -5.,  -5., 3.,   3.,  -8., 8.,   7.,   -12., 10.,  6.,
      7.,   5.,  -4., 6.,   9.,  -6.,  0.,  -1., -12., -11., 7.,   9.};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, N * sizeof(int8_t));
  SET_MBA0_F16I8();
  mfloat16_t md = mfwcvt_hf_b_m(ms);
  SET_MBA0_F16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFWCVT_HF_B_M I8");
}

static void test_mfwcvt_fw_x_m_i16() {
  const size_t M = 4;
  const size_t N = 4;
  const int16_t src[M * N] = {-799, 2919, -1207, -229, -914,  -2458,
                              -797, 92,   -2181, 939,  -3232, -3242,
                              2626, 1148, -519,  2894};
  const fp32_t ans[M * N] = {-799., 2919., -1207., -229., -914.,  -2458.,
                             -797., 92.,   -2181., 939.,  -3232., -3242.,
                             2626., 1148., -519.,  2894.};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, N * sizeof(int16_t));
  SET_MBA0_F32I16();
  mfloat32_t md = mfwcvt_fw_x_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVT_FW_X_M I16");
}

static void test_mfwcvt_f_h_m() {
  const size_t M = 4;
  const size_t N = 4;
  const int16_t src[M * N] = {-799, 2919, -1207, -229, -914,  -2458,
                              -797, 92,   -2181, 939,  -3232, -3242,
                              2626, 1148, -519,  2894};
  const fp32_t ans[M * N] = {-799., 2919., -1207., -229., -914.,  -2458.,
                             -797., 92.,   -2181., 939.,  -3232., -3242.,
                             2626., 1148., -519.,  2894.};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, N * sizeof(int16_t));
  SET_MBA0_F32I16();
  mfloat32_t md = mfwcvt_f_h_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVT_F_H_M");
}

static void test_mfwcvt_fw_x_m_i32() {
  const size_t M = 2;
  const size_t N = 2;
  const int32_t src[M * N] = {-1403915435, -430088063, 1715248988, -70734638};
  const fp64_t ans[M * N] = {-1403915435, -430088063, 1715248988, -70734638};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  SET_MBA0_F64I32();
  mfloat64_t md = mfwcvt_fw_x_m(ms);
  SET_MBA0_F64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFWCVT_FW_X_M I32");
}

static void test_mfwcvt_d_w_m() {
  const size_t M = 2;
  const size_t N = 2;
  const int32_t src[M * N] = {-1403915435, -430088063, 1715248988, -70734638};
  const fp64_t ans[M * N] = {-1403915435, -430088063, 1715248988, -70734638};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, N * sizeof(int32_t));
  SET_MBA0_F64I32();
  mfloat64_t md = mfwcvt_d_w_m(ms);
  SET_MBA0_F64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFWCVT_D_W_M");
}

static void test_mfwcvt_fw_x_m() {
  test_mfwcvt_fw_x_m_i8();
  test_mfwcvt_hf_b_m();
  test_mfwcvt_fw_x_m_i16();
  test_mfwcvt_f_h_m();
  test_mfwcvt_fw_x_m_i32();
  test_mfwcvt_d_w_m();
}

static void test_mfwcvt_fq_x_m_i8() {
  const size_t M = 4;
  const size_t N = 4;
  const int8_t src[M * N] = {-101, -44, 112, 4,   80, 29,  9,  45,
                             -93,  35,  -62, 101, 23, -28, 33, -80};
  const fp32_t ans[M * N] = {-101, -44, 112, 4,   80, 29,  9,  45,
                             -93,  35,  -62, 101, 23, -28, 33, -80};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, N * sizeof(int8_t));
  SET_MBA0_F32I8();
  mfloat32_t md = mfwcvt_fq_x_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVT_FQ_X_M I8");
}

static void test_mfwcvt_f_b_m() {
  const size_t M = 4;
  const size_t N = 4;
  const int8_t src[M * N] = {-101, -44, 112, 4,   80, 29,  9,  45,
                             -93,  35,  -62, 101, 23, -28, 33, -80};
  const fp32_t ans[M * N] = {-101, -44, 112, 4,   80, 29,  9,  45,
                             -93,  35,  -62, 101, 23, -28, 33, -80};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, N * sizeof(int8_t));
  SET_MBA0_F32I8();
  mfloat32_t md = mfwcvt_f_b_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVT_F_B_M");
}

static void test_mfwcvt_fq_x_m() {
  test_mfwcvt_fq_x_m_i8();
  test_mfwcvt_f_b_m();
}

static void test_mfwcvtu_fw_x_m_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const uint8_t src[M * N] = {
      6,   248, 3,   252, 0, 4,   7, 252, 3,   255, 247, 254, 3,
      8,   250, 3,   255, 1, 253, 2, 247, 6,   4,   249, 5,   3,
      1,   7,   7,   3,   4, 0,   0, 0,   250, 2,   250, 253, 9,
      3,   5,   250, 248, 4, 249, 0, 0,   255, 4,   249, 2,   7,
      252, 5,   248, 6,   2, 255, 4, 7,   253, 250, 3,   0};
  const fp16_t ans[M * N] = {
      6,   248, 3,   252, 0, 4,   7, 252, 3,   255, 247, 254, 3,
      8,   250, 3,   255, 1, 253, 2, 247, 6,   4,   249, 5,   3,
      1,   7,   7,   3,   4, 0,   0, 0,   250, 2,   250, 253, 9,
      3,   5,   250, 248, 4, 249, 0, 0,   255, 4,   249, 2,   7,
      252, 5,   248, 6,   2, 255, 4, 7,   253, 250, 3,   0};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, N * sizeof(uint8_t));
  SET_MBA0_F16I8();
  mfloat16_t md = mfwcvtu_fw_x_m(ms);
  SET_MBA0_F16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFWCVTU_FW_X_M U8");
}

static void test_mfwcvtu_hf_b_m() {
  const size_t M = 8;
  const size_t N = 8;
  const uint8_t src[M * N] = {
      6,   248, 3,   252, 0, 4,   7, 252, 3,   255, 247, 254, 3,
      8,   250, 3,   255, 1, 253, 2, 247, 6,   4,   249, 5,   3,
      1,   7,   7,   3,   4, 0,   0, 0,   250, 2,   250, 253, 9,
      3,   5,   250, 248, 4, 249, 0, 0,   255, 4,   249, 2,   7,
      252, 5,   248, 6,   2, 255, 4, 7,   253, 250, 3,   0};
  const fp16_t ans[M * N] = {
      6,   248, 3,   252, 0, 4,   7, 252, 3,   255, 247, 254, 3,
      8,   250, 3,   255, 1, 253, 2, 247, 6,   4,   249, 5,   3,
      1,   7,   7,   3,   4, 0,   0, 0,   250, 2,   250, 253, 9,
      3,   5,   250, 248, 4, 249, 0, 0,   255, 4,   249, 2,   7,
      252, 5,   248, 6,   2, 255, 4, 7,   253, 250, 3,   0};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, N * sizeof(uint8_t));
  SET_MBA0_F16I8();
  mfloat16_t md = mfwcvtu_hf_b_m(ms);
  SET_MBA0_F16();
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(ans, f16_buffer, M * N, "MFWCVTU_HF_B_M");
}

static void test_mfwcvtu_fw_x_m_u16() {
  const size_t M = 4;
  const size_t N = 4;
  const uint16_t src[M * N] = {607, 265, 252, 620, 122, 584, 541, 293,
                               34,  525, 73,  503, 628, 147, 260, 34};
  const fp32_t ans[M * N] = {607, 265, 252, 620, 122, 584, 541, 293,
                             34,  525, 73,  503, 628, 147, 260, 34};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, N * sizeof(uint16_t));
  SET_MBA0_F32I16();
  mfloat32_t md = mfwcvtu_fw_x_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVTU_FW_X_M U16");
}

static void test_mfwcvtu_f_h_m() {
  const size_t M = 4;
  const size_t N = 4;
  const uint16_t src[M * N] = {607, 265, 252, 620, 122, 584, 541, 293,
                               34,  525, 73,  503, 628, 147, 260, 34};
  const fp32_t ans[M * N] = {607, 265, 252, 620, 122, 584, 541, 293,
                             34,  525, 73,  503, 628, 147, 260, 34};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, N * sizeof(uint16_t));
  SET_MBA0_F32I16();
  mfloat32_t md = mfwcvtu_f_h_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVTU_F_H_M");
}

static void test_mfwcvtu_fw_x_m_u32() {
  const size_t M = 2;
  const size_t N = 2;
  const uint32_t src[M * N] = {22844586, 8506634, 15051826, 9473121};
  const fp64_t ans[M * N] = {22844586, 8506634, 15051826, 9473121};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  SET_MBA0_F64I32();
  mfloat64_t md = mfwcvtu_fw_x_m(ms);
  SET_MBA0_F64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFWCVTU_FW_X_M U32");
}

static void test_mfwcvtu_d_w_m() {
  const size_t M = 2;
  const size_t N = 2;
  const uint32_t src[M * N] = {22844586, 8506634, 15051826, 9473121};
  const fp64_t ans[M * N] = {22844586, 8506634, 15051826, 9473121};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, N * sizeof(uint32_t));
  SET_MBA0_F64I32();
  mfloat64_t md = mfwcvtu_d_w_m(ms);
  SET_MBA0_F64();
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(ans, f64_buffer, M * N, "MFWCVTU_D_W_M");
}

static void test_mfwcvtu_fw_x_m() {
  test_mfwcvtu_fw_x_m_u8();
  test_mfwcvtu_hf_b_m();
  test_mfwcvtu_fw_x_m_u16();
  test_mfwcvtu_f_h_m();
  test_mfwcvtu_fw_x_m_u32();
  test_mfwcvtu_d_w_m();
}

static void test_mfwcvtu_fq_x_m_u8() {
  const size_t M = 4;
  const size_t N = 4;
  const uint8_t src[M * N] = {47,  95,  79,  135, 37, 87, 187, 224,
                              128, 161, 117, 123, 37, 99, 109, 14};
  const fp32_t ans[M * N] = {47,  95,  79,  135, 37, 87, 187, 224,
                             128, 161, 117, 123, 37, 99, 109, 14};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, N * sizeof(uint8_t));
  SET_MBA0_F32I8();
  mfloat32_t md = mfwcvtu_fq_x_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVTU_FQ_X_M U8");
}

static void test_mfwcvtu_f_b_m() {
  const size_t M = 4;
  const size_t N = 4;
  const uint8_t src[M * N] = {47,  95,  79,  135, 37, 87, 187, 224,
                              128, 161, 117, 123, 37, 99, 109, 14};
  const fp32_t ans[M * N] = {47,  95,  79,  135, 37, 87, 187, 224,
                             128, 161, 117, 123, 37, 99, 109, 14};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, N * sizeof(uint8_t));
  SET_MBA0_F32I8();
  mfloat32_t md = mfwcvtu_f_b_m(ms);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(ans, f32_buffer, M * N, "MFWCVTU_F_B_M");
}

static void test_mfwcvtu_fq_x_m() {
  test_mfwcvtu_fq_x_m_u8();
  test_mfwcvtu_f_b_m();
}

static void test_mfcvtu_x_f_m_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const fp16_t src[M * N] = {
      0.9775, 1.2705, 4.633, 5.137, 2.37,   9.29,   0.9023, 1.987, 7.59,  8.64,
      3.002,  8.11,   1.514, 4.98,  6.477,  0.575,  2.758,  9.07,  2.83,  9.016,
      1.365,  9.07,   5.76,  1.677, 1.367,  2.049,  4.31,   4.67,  8.98,  2.848,
      2.652,  2.91,   5.383, 3.225, 1.86,   0.4753, 7.543,  7.13,  5.82,  6.043,
      7.527,  1.048,  3.375, 6.37,  0.6313, 4.414,  7.145,  0.588, 1.892, 2.748,
      8.31,   6.13,   9.695, 1.173, 7.16,   8.54,   8.47,   6.76,  3.,    7.062,
      0.5024, 4.57,   2.34,  1.622};
  const uint16_t ans[M * N] = {1, 1, 5, 5, 2,  9, 1, 2, 8, 9, 3, 8, 2, 5, 6, 1,
                               3, 9, 3, 9, 1,  9, 6, 2, 1, 2, 4, 5, 9, 3, 3, 3,
                               5, 3, 2, 0, 8,  7, 6, 6, 8, 1, 3, 6, 1, 4, 7, 1,
                               2, 3, 8, 6, 10, 1, 7, 9, 8, 7, 3, 7, 1, 5, 2, 2};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  SET_MBA0_F16I16();
  muint16_t md = mfcvtu_x_f_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MFCVTU_X_F_M F16");
}

static void test_mfcvtu_h_hf_m() {
  const size_t M = 8;
  const size_t N = 8;
  const fp16_t src[M * N] = {
      0.9775, 1.2705, 4.633, 5.137, 2.37,   9.29,   0.9023, 1.987, 7.59,  8.64,
      3.002,  8.11,   1.514, 4.98,  6.477,  0.575,  2.758,  9.07,  2.83,  9.016,
      1.365,  9.07,   5.76,  1.677, 1.367,  2.049,  4.31,   4.67,  8.98,  2.848,
      2.652,  2.91,   5.383, 3.225, 1.86,   0.4753, 7.543,  7.13,  5.82,  6.043,
      7.527,  1.048,  3.375, 6.37,  0.6313, 4.414,  7.145,  0.588, 1.892, 2.748,
      8.31,   6.13,   9.695, 1.173, 7.16,   8.54,   8.47,   6.76,  3.,    7.062,
      0.5024, 4.57,   2.34,  1.622};
  const uint16_t ans[M * N] = {1, 1, 5, 5, 2,  9, 1, 2, 8, 9, 3, 8, 2, 5, 6, 1,
                               3, 9, 3, 9, 1,  9, 6, 2, 1, 2, 4, 5, 9, 3, 3, 3,
                               5, 3, 2, 0, 8,  7, 6, 6, 8, 1, 3, 6, 1, 4, 7, 1,
                               2, 3, 8, 6, 10, 1, 7, 9, 8, 7, 3, 7, 1, 5, 2, 2};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  SET_MBA0_F16I16();
  muint16_t md = mfcvtu_h_hf_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MFCVTU_H_HF_M");
}

static void test_mfcvtu_x_f_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {4.9607625, 8.043694,  2.6162393, 9.962387,
                             9.042594,  6.5776205, 9.4609785, 6.8592386,
                             4.0537996, 4.2809386, 3.422903,  2.500067,
                             4.729094,  5.7243137, 8.124815,  1.6493384};
  const uint32_t ans[M * N] = {5, 8, 3, 10, 9, 7, 9, 7, 4, 4, 3, 3, 5, 6, 8, 2};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  SET_MBA0_F32I32();
  muint32_t md = mfcvtu_x_f_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MFCVTU_X_F_M F32");
}

static void test_mfcvtu_w_f_m() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {4.9607625, 8.043694,  2.6162393, 9.962387,
                             9.042594,  6.5776205, 9.4609785, 6.8592386,
                             4.0537996, 4.2809386, 3.422903,  2.500067,
                             4.729094,  5.7243137, 8.124815,  1.6493384};
  const uint32_t ans[M * N] = {5, 8, 3, 10, 9, 7, 9, 7, 4, 4, 3, 3, 5, 6, 8, 2};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  SET_MBA0_F32I32();
  muint32_t md = mfcvtu_w_f_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MFCVTU_W_F_M");
}

static void test_mfcvtu_x_f_m_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {6.88659, 4.8711348, 4.8035145, 7.4982452};
  const uint64_t ans[M * N] = {7, 5, 5, 7};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  SET_MBA0_F64I64();
  muint64_t md = mfcvtu_x_f_m(ms);
  SET_MBA0_I64();
  msc_m(md, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MFCVTU_X_F_M F64");
}

static void test_mfcvtu_dw_d_m() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {6.88659, 4.8711348, 4.8035145, 7.4982452};
  const uint64_t ans[M * N] = {7, 5, 5, 7};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  SET_MBA0_F64I64();
  muint64_t md = mfcvtu_dw_d_m(ms);
  SET_MBA0_I64();
  msc_m(md, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MFCVTU_DW_D_M");
}

static void test_mfcvtu_x_f_m() {
  test_mfcvtu_x_f_m_f16();
  test_mfcvtu_h_hf_m();
  test_mfcvtu_x_f_m_f32();
  test_mfcvtu_w_f_m();
  test_mfcvtu_x_f_m_f64();
  test_mfcvtu_dw_d_m();
}

static void test_mfcvt_x_f_m_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const fp16_t src[M * N] = {
      5.33,    -8.83,  6.31,    -4.918, 7.285,  0.564,   5.008,    -4.195,
      -0.5356, 6.64,   -5.707,  2.979,  8.055,  -3.328,  1.113,    2.7,
      3.633,   -1.828, 1.427,   -4.773, 2.352,  0.5137,  -0.09735, 6.234,
      9.03,    1.315,  -2.043,  -6.773, 4.754,  9.664,   -4.824,   5.06,
      -1.475,  7.14,   1.056,   -4.348, -5.777, -2.021,  8.77,     5.113,
      7.934,   8.13,   -1.054,  -9.44,  -1.216, -0.3599, 0.9497,   -4.688,
      -2.293,  -6.543, -1.7295, -9.164, -3.295, -0.7256, -8.85,    7.883,
      -4.54,   -3.402, 4.375,   0.7324, 0.1254, -7.707,  -0.4468,  -4.184};
  const int16_t ans[M * N] = {
      5,  -9, 6,  -5, 7,  1,  5,  -4, -1, 7,  -6, 3,  8,  -3, 1,  3,
      4,  -2, 1,  -5, 2,  1,  0,  6,  9,  1,  -2, -7, 5,  10, -5, 5,
      -1, 7,  1,  -4, -6, -2, 9,  5,  8,  8,  -1, -9, -1, 0,  1,  -5,
      -2, -7, -2, -9, -3, -1, -9, 8,  -5, -3, 4,  1,  0,  -8, 0,  -4};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  SET_MBA0_F16I16();
  mint16_t md = mfcvt_x_f_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MFCVT_X_F_M F16");
}

static void test_mfcvt_h_hf_m() {
  const size_t M = 8;
  const size_t N = 8;
  const fp16_t src[M * N] = {
      5.33,    -8.83,  6.31,    -4.918, 7.285,  0.564,   5.008,    -4.195,
      -0.5356, 6.64,   -5.707,  2.979,  8.055,  -3.328,  1.113,    2.7,
      3.633,   -1.828, 1.427,   -4.773, 2.352,  0.5137,  -0.09735, 6.234,
      9.03,    1.315,  -2.043,  -6.773, 4.754,  9.664,   -4.824,   5.06,
      -1.475,  7.14,   1.056,   -4.348, -5.777, -2.021,  8.77,     5.113,
      7.934,   8.13,   -1.054,  -9.44,  -1.216, -0.3599, 0.9497,   -4.688,
      -2.293,  -6.543, -1.7295, -9.164, -3.295, -0.7256, -8.85,    7.883,
      -4.54,   -3.402, 4.375,   0.7324, 0.1254, -7.707,  -0.4468,  -4.184};
  const int16_t ans[M * N] = {
      5,  -9, 6,  -5, 7,  1,  5,  -4, -1, 7,  -6, 3,  8,  -3, 1,  3,
      4,  -2, 1,  -5, 2,  1,  0,  6,  9,  1,  -2, -7, 5,  10, -5, 5,
      -1, 7,  1,  -4, -6, -2, 9,  5,  8,  8,  -1, -9, -1, 0,  1,  -5,
      -2, -7, -2, -9, -3, -1, -9, 8,  -5, -3, 4,  1,  0,  -8, 0,  -4};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  SET_MBA0_F16I16();
  mint16_t md = mfcvt_h_hf_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MFCVT_H_HF_M");
}

static void test_mfcvt_x_f_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {-8.512157, 9.457457,  -8.25793,  4.237046,
                             6.4241366, 2.333718,  -9.766037, -2.0582533,
                             -5.927909, -8.181698, -6.601572, 9.821599,
                             3.0587585, 2.2532656, 7.5209403, -0.16786414};
  const int32_t ans[M * N] = {-9, 9,  -8, 4,  6, 2, -10, -2,
                              -6, -8, -7, 10, 3, 2, 8,   0};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  SET_MBA0_F32I32();
  mint32_t md = mfcvt_x_f_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(int32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MFCVT_X_F_M F32");
}

static void test_mfcvt_w_f_m() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {-8.512157, 9.457457,  -8.25793,  4.237046,
                             6.4241366, 2.333718,  -9.766037, -2.0582533,
                             -5.927909, -8.181698, -6.601572, 9.821599,
                             3.0587585, 2.2532656, 7.5209403, -0.16786414};
  const int32_t ans[M * N] = {-9, 9,  -8, 4,  6, 2, -10, -2,
                              -6, -8, -7, 10, 3, 2, 8,   0};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  SET_MBA0_F32I32();
  mint32_t md = mfcvt_w_f_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(int32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MFCVT_W_F_M");
}

static void test_mfcvt_x_f_m_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {-7.79726008, 9.45063363, -6.9689971, -6.00294621};
  const int64_t ans[M * N] = {-8, 9, -7, -6};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  SET_MBA0_F64I64();
  mint64_t md = mfcvt_x_f_m(ms);
  SET_MBA0_I64();
  msc_m(md, u64_buffer, N * sizeof(int64_t));
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MFCVT_X_F_M F64");
}

static void test_mfcvt_dw_d_m() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {-7.79726008, 9.45063363, -6.9689971, -6.00294621};
  const int64_t ans[M * N] = {-8, 9, -7, -6};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  SET_MBA0_F64I64();
  mint64_t md = mfcvt_dw_d_m(ms);
  SET_MBA0_I64();
  msc_m(md, u64_buffer, N * sizeof(int64_t));
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MFCVT_DW_D_M");
}

static void test_mfcvt_x_f_m() {
  test_mfcvt_x_f_m_f16();
  test_mfcvt_h_hf_m();
  test_mfcvt_x_f_m_f32();
  test_mfcvt_w_f_m();
  test_mfcvt_x_f_m_f64();
  test_mfcvt_dw_d_m();
}

static void test_mfwcvtu_xw_f_m_f16() {
  const size_t M = 4;
  const size_t N = 4;
  const fp16_t src[M * N] = {7.13,   4.68,  8.43,  3.02, 8.695, 0.9355,
                             2.496,  8.84,  3.822, 5.2,  6.5,   6.36,
                             0.1969, 6.242, 4.68,  6.547};
  const uint32_t ans[M * N] = {7, 5, 8, 3, 9, 1, 2, 9, 4, 5, 6, 6, 0, 6, 5, 7};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  msettypei(0x41);
  msettypehi(0x1);
  muint32_t md = mfwcvtu_xw_f_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MFWCVTU_XW_F_M F16");
}

static void test_mfwcvtu_w_hf_m() {
  const size_t M = 4;
  const size_t N = 4;
  const fp16_t src[M * N] = {7.13,   4.68,  8.43,  3.02, 8.695, 0.9355,
                             2.496,  8.84,  3.822, 5.2,  6.5,   6.36,
                             0.1969, 6.242, 4.68,  6.547};
  const uint32_t ans[M * N] = {7, 5, 8, 3, 9, 1, 2, 9, 4, 5, 6, 6, 0, 6, 5, 7};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  msettypei(0x41);
  msettypehi(0x1);
  muint32_t md = mfwcvtu_w_hf_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MFWCVTU_W_HF_M");
}

static void test_mfwcvtu_xw_f_m_f32() {
  const size_t M = 2;
  const size_t N = 2;
  const fp32_t src[M * N] = {28.177113, 90.92333, 70.984406, 75.43896};
  const uint64_t ans[M * N] = {28, 91, 71, 75};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x82);
  msettypehi(0x4);
  muint64_t md = mfwcvtu_xw_f_m(ms);
  SET_MBA0_I64();
  msc_m(md, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MFWCVTU_XW_F_M F32");
}

static void test_mfwcvtu_dw_f_m() {
  const size_t M = 2;
  const size_t N = 2;
  const fp32_t src[M * N] = {28.177113, 90.92333, 70.984406, 75.43896};
  const uint64_t ans[M * N] = {28, 91, 71, 75};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x82);
  msettypehi(0x4);
  muint64_t md = mfwcvtu_dw_f_m(ms);
  SET_MBA0_I64();
  msc_m(md, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MFWCVTU_DW_F_M");
}

static void test_mfwcvtu_xw_f_m() {
  test_mfwcvtu_xw_f_m_f16();
  test_mfwcvtu_w_hf_m();
  test_mfwcvtu_xw_f_m_f32();
  test_mfwcvtu_dw_f_m();
}

static void test_mfwcvt_xw_f_m_f16() {
  const size_t M = 4;
  const size_t N = 4;
  const fp16_t src[M * N] = {
      23.34, 93.44,  63.66, -63.47, -97.06, 37.94,  81.75,  -35.7, -4.566,
      3.557, 71.2,   21.14, 69.56,  -20.72, -69.8,  -81.44, 49.22, -1.897,
      71.25, -84.94, 22.14, -0.287, -52.16, -17.77, 15.93};
  const int32_t ans[M * N] = {23, 93,  64, -63, -97, 38,  82,  -36, -5,
                              4,  71,  21, 70,  -21, -70, -81, 49,  -2,
                              71, -85, 22, 0,   -52, -18, 16};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  msettypei(0x41);
  msettypehi(0x1);
  mint32_t md = mfwcvt_xw_f_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MFWCVT_XW_F_M F16");
}

static void test_mfwcvt_w_hf_m() {
  const size_t M = 4;
  const size_t N = 4;
  const fp16_t src[M * N] = {
      23.34, 93.44,  63.66, -63.47, -97.06, 37.94,  81.75,  -35.7, -4.566,
      3.557, 71.2,   21.14, 69.56,  -20.72, -69.8,  -81.44, 49.22, -1.897,
      71.25, -84.94, 22.14, -0.287, -52.16, -17.77, 15.93};
  const int32_t ans[M * N] = {23, 93,  64, -63, -97, 38,  82,  -36, -5,
                              4,  71,  21, 70,  -21, -70, -81, 49,  -2,
                              71, -85, 22, 0,   -52, -18, 16};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  msettypei(0x41);
  msettypehi(0x1);
  mint32_t md = mfwcvt_w_hf_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MFWCVT_W_HF_M");
}

static void test_mfwcvt_xw_f_m_f32() {
  const size_t M = 2;
  const size_t N = 2;
  const fp32_t src[M * N] = {-50.83718, 37.150524, -52.40851, -14.075596};
  const int64_t ans[M * N] = {-51, 37, -52, -14};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x82);
  msettypehi(0x4);
  mint64_t md = mfwcvt_xw_f_m(ms);
  SET_MBA0_I64();
  msc_m(md, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MFWCVT_XW_F_M F32");
}

static void test_mfwcvt_dw_f_m() {
  const size_t M = 2;
  const size_t N = 2;
  const fp32_t src[M * N] = {-50.83718, 37.150524, -52.40851, -14.075596};
  const int64_t ans[M * N] = {-51, 37, -52, -14};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x82);
  msettypehi(0x4);
  mint64_t md = mfwcvt_dw_f_m(ms);
  SET_MBA0_I64();
  msc_m(md, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MFWCVT_DW_F_M");
}

static void test_mfwcvt_xw_f_m() {
  test_mfwcvt_xw_f_m_f16();
  test_mfwcvt_w_hf_m();
  test_mfwcvt_xw_f_m_f32();
  test_mfwcvt_dw_f_m();
}

static void test_mfncvtu_x_fw_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const fp16_t src[M * N] = {
      71.44, 91.4,  21.72, 93.1,  86.5,  8.586, 36.72, 42.06, 97.94, 91.7,
      82.5,  73.1,  69.06, 27.95, 75.75, 20.78, 5.477, 47.88, 70.25, 52.56,
      58.9,  13.5,  18.33, 15.82, 25.84, 98.7,  70.6,  76.94, 34.,   81.2,
      18.84, 91.3,  64.75, 23.48, 26.64, 97.5,  27.31, 47.8,  73.,   40.,
      89.7,  82.7,  92.1,  81.06, 47.62, 61.72, 38.72, 50.84, 46.8,  71.75,
      96.6,  7.883, 78.25, 57.47, 51.4,  17.3,  35.22, 50.,   26.53, 6.52,
      3.547, 94.2,  14.59, 69.9};
  const uint8_t ans[M * N] = {
      71, 91, 22, 93, 86, 9,  37, 42, 98, 92, 82, 73, 69, 28, 76, 21,
      5,  48, 70, 53, 59, 14, 18, 16, 26, 99, 71, 77, 34, 81, 19, 91,
      65, 23, 27, 98, 27, 48, 73, 40, 90, 83, 92, 81, 48, 62, 39, 51,
      47, 72, 97, 8,  78, 57, 51, 17, 35, 50, 27, 7,  4,  94, 15, 70};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  msettypei(0x11);
  msettypehi(0x1);
  muint8_t md = mfncvtu_x_fw_m(ms);
  SET_MBA0_I8();
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MFNCVTU_X_FW_M F16");
}

static void test_mfncvtu_b_hf() {
  const size_t M = 8;
  const size_t N = 8;
  const fp16_t src[M * N] = {
      71.44, 91.4,  21.72, 93.1,  86.5,  8.586, 36.72, 42.06, 97.94, 91.7,
      82.5,  73.1,  69.06, 27.95, 75.75, 20.78, 5.477, 47.88, 70.25, 52.56,
      58.9,  13.5,  18.33, 15.82, 25.84, 98.7,  70.6,  76.94, 34.,   81.2,
      18.84, 91.3,  64.75, 23.48, 26.64, 97.5,  27.31, 47.8,  73.,   40.,
      89.7,  82.7,  92.1,  81.06, 47.62, 61.72, 38.72, 50.84, 46.8,  71.75,
      96.6,  7.883, 78.25, 57.47, 51.4,  17.3,  35.22, 50.,   26.53, 6.52,
      3.547, 94.2,  14.59, 69.9};
  const uint8_t ans[M * N] = {
      71, 91, 22, 93, 86, 9,  37, 42, 98, 92, 82, 73, 69, 28, 76, 21,
      5,  48, 70, 53, 59, 14, 18, 16, 26, 99, 71, 77, 34, 81, 19, 91,
      65, 23, 27, 98, 27, 48, 73, 40, 90, 83, 92, 81, 48, 62, 39, 51,
      47, 72, 97, 8,  78, 57, 51, 17, 35, 50, 27, 7,  4,  94, 15, 70};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  msettypei(0x11);
  msettypehi(0x1);
  muint8_t md = mfncvtu_b_hf_m(ms);
  SET_MBA0_I8();
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MFNCVTU_B_HF_M");
}

static void test_mfncvtu_x_fw_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {44.12, 24.7,  16.38, 20.17, 89.3,   25.45,
                             39.47, 24.88, 27.73, 24.2,  15.484, 0.7036,
                             89.8,  94.25, 84.4,  36.25};
  const uint16_t ans[M * N] = {44, 25, 16, 20, 89, 25, 39, 25,
                               28, 24, 15, 1,  90, 94, 84, 36};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x22);
  msettypehi(0x4);
  muint16_t md = mfncvtu_x_fw_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MFNCVTU_X_FW_M F32");
}

static void test_mfncvtu_h_f() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {44.12, 24.7,  16.38, 20.17, 89.3,   25.45,
                             39.47, 24.88, 27.73, 24.2,  15.484, 0.7036,
                             89.8,  94.25, 84.4,  36.25};
  const uint16_t ans[M * N] = {44, 25, 16, 20, 89, 25, 39, 25,
                               28, 24, 15, 1,  90, 94, 84, 36};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x22);
  msettypehi(0x4);
  muint16_t md = mfncvtu_h_f_m(ms);
  SET_MBA0_I16();
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MFNCVTU_H_F_M");
}

static void test_mfncvtu_x_fw_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {48.4, 79.8, 10.625, 9.46};
  const uint32_t ans[M * N] = {48, 80, 11, 9};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  msettypei(0x43);
  msettypehi(0x10);
  muint32_t md = mfncvtu_x_fw_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MFNCVTU_X_FW_M F64");
}

static void test_mfncvtu_w_d() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {48.4, 79.8, 10.625, 9.46};
  const uint32_t ans[M * N] = {48, 80, 11, 9};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  msettypei(0x43);
  msettypehi(0x10);
  muint32_t md = mfncvtu_w_d_m(ms);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MFNCVTU_W_D_M");
}

static void test_mfncvtu_x_fw() {
  test_mfncvtu_x_fw_f16();
  test_mfncvtu_b_hf();
  test_mfncvtu_x_fw_f32();
  test_mfncvtu_h_f();
  test_mfncvtu_x_fw_f64();
  test_mfncvtu_w_d();
}

static void test_mfncvtu_x_fq_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {17.726198, 13.14702,  16.021738, 38.334526,
                             21.896717, 33.407013, 84.70619,  53.706272,
                             84.83878,  74.49762,  3.0108328, 10.992341,
                             3.8677173, 91.30418,  19.809296, 71.62177};
  const uint8_t ans[M * N] = {18, 13, 16, 38, 22, 33, 85, 54,
                              85, 74, 3,  11, 4,  91, 20, 72};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x12);
  msettypehi(0x4);
  muint8_t md = mfncvtu_x_fq_m(ms);
  SET_MBA0_I8();
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MFNCVTU_X_FQ_M F32");
}

static void test_mfncvtu_b_f_m() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {17.726198, 13.14702,  16.021738, 38.334526,
                             21.896717, 33.407013, 84.70619,  53.706272,
                             84.83878,  74.49762,  3.0108328, 10.992341,
                             3.8677173, 91.30418,  19.809296, 71.62177};
  const uint8_t ans[M * N] = {18, 13, 16, 38, 22, 33, 85, 54,
                              85, 74, 3,  11, 4,  91, 20, 72};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x12);
  msettypehi(0x4);
  muint8_t md = mfncvtu_b_f_m(ms);
  SET_MBA0_I8();
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MFNCVTU_B_F_M");
}

static void test_mfncvtu_x_fq_m() {
  test_mfncvtu_x_fq_m_f32();
  test_mfncvtu_b_f_m();
}

static void test_mfncvt_x_fw_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const fp16_t src[M * N] = {
      71.44, 91.4,  21.72, 93.1,  86.5,  8.586, 36.72, 42.06, 97.94, 91.7,
      82.5,  73.1,  69.06, 27.95, 75.75, 20.78, 5.477, 47.88, 70.25, 52.56,
      58.9,  13.5,  18.33, 15.82, 25.84, 98.7,  70.6,  76.94, 34.,   81.2,
      18.84, 91.3,  64.75, 23.48, 26.64, 97.5,  27.31, 47.8,  73.,   40.,
      89.7,  82.7,  92.1,  81.06, 47.62, 61.72, 38.72, 50.84, 46.8,  71.75,
      96.6,  7.883, 78.25, 57.47, 51.4,  17.3,  35.22, 50.,   26.53, 6.52,
      3.547, 94.2,  14.59, 69.9};
  const int8_t ans[M * N] = {
      71, 91, 22, 93, 86, 9,  37, 42, 98, 92, 82, 73, 69, 28, 76, 21,
      5,  48, 70, 53, 59, 14, 18, 16, 26, 99, 71, 77, 34, 81, 19, 91,
      65, 23, 27, 98, 27, 48, 73, 40, 90, 83, 92, 81, 48, 62, 39, 51,
      47, 72, 97, 8,  78, 57, 51, 17, 35, 50, 27, 7,  4,  94, 15, 70};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  msettypei(0x11);
  msettypehi(0x1);
  mint8_t md = mfncvt_x_fw_m(ms);
  SET_MBA0_I8();
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MFNCVT_X_FW_M F16");
}

static void test_mfncvt_b_hf() {
  const size_t M = 8;
  const size_t N = 8;
  const fp16_t src[M * N] = {
      71.44, 91.4,  21.72, 93.1,  86.5,  8.586, 36.72, 42.06, 97.94, 91.7,
      82.5,  73.1,  69.06, 27.95, 75.75, 20.78, 5.477, 47.88, 70.25, 52.56,
      58.9,  13.5,  18.33, 15.82, 25.84, 98.7,  70.6,  76.94, 34.,   81.2,
      18.84, 91.3,  64.75, 23.48, 26.64, 97.5,  27.31, 47.8,  73.,   40.,
      89.7,  82.7,  92.1,  81.06, 47.62, 61.72, 38.72, 50.84, 46.8,  71.75,
      96.6,  7.883, 78.25, 57.47, 51.4,  17.3,  35.22, 50.,   26.53, 6.52,
      3.547, 94.2,  14.59, 69.9};
  const int8_t ans[M * N] = {
      71, 91, 22, 93, 86, 9,  37, 42, 98, 92, 82, 73, 69, 28, 76, 21,
      5,  48, 70, 53, 59, 14, 18, 16, 26, 99, 71, 77, 34, 81, 19, 91,
      65, 23, 27, 98, 27, 48, 73, 40, 90, 83, 92, 81, 48, 62, 39, 51,
      47, 72, 97, 8,  78, 57, 51, 17, 35, 50, 27, 7,  4,  94, 15, 70};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, N * sizeof(fp16_t));
  msettypei(0x11);
  msettypehi(0x1);
  mint8_t md = mfncvt_b_hf_m(ms);
  SET_MBA0_I8();
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MFNCVT_B_HF_M");
}

static void test_mfncvt_x_fw_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {44.12, 24.7,  16.38, 20.17, 89.3,   25.45,
                             39.47, 24.88, 27.73, 24.2,  15.484, 0.7036,
                             89.8,  94.25, 84.4,  36.25};
  const int16_t ans[M * N] = {44, 25, 16, 20, 89, 25, 39, 25,
                               28, 24, 15, 1,  90, 94, 84, 36};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x22);
  msettypehi(0x4);
  mint16_t md = mfncvt_x_fw_m(ms);
  SET_MBA0_I16();
  msc_m(md, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MFNCVT_X_FW_M F32");
}

static void test_mfncvt_h_f() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {44.12, 24.7,  16.38, 20.17, 89.3,   25.45,
                             39.47, 24.88, 27.73, 24.2,  15.484, 0.7036,
                             89.8,  94.25, 84.4,  36.25};
  const int16_t ans[M * N] = {44, 25, 16, 20, 89, 25, 39, 25,
                               28, 24, 15, 1,  90, 94, 84, 36};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x22);
  msettypehi(0x4);
  mint16_t md = mfncvt_h_f_m(ms);
  SET_MBA0_I16();
  msc_m(md, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MFNCVT_H_F_M");
}

static void test_mfncvt_x_fw_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {48.4, 79.8, 10.625, 9.46};
  const int32_t ans[M * N] = {48, 80, 11, 9};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  msettypei(0x43);
  msettypehi(0x10);
  mint32_t md = mfncvt_x_fw_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MFNCVT_X_FW_M F64");
}

static void test_mfncvt_w_d() {
  const size_t M = 2;
  const size_t N = 2;
  const fp64_t src[M * N] = {48.4, 79.8, 10.625, 9.46};
  const int32_t ans[M * N] = {48, 80, 11, 9};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, N * sizeof(fp64_t));
  msettypei(0x43);
  msettypehi(0x10);
  mint32_t md = mfncvt_w_d_m(ms);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MFNCVT_W_D_M");
}

static void test_mfncvt_x_fw_m() {
  test_mfncvt_x_fw_f16();
  test_mfncvt_b_hf();
  test_mfncvt_x_fw_f32();
  test_mfncvt_h_f();
  test_mfncvt_x_fw_f64();
  test_mfncvt_w_d();
}

static void test_mfncvt_x_fq_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {17.726198, 13.14702,  16.021738, 38.334526,
                             21.896717, 33.407013, 84.70619,  53.706272,
                             84.83878,  74.49762,  3.0108328, 10.992341,
                             3.8677173, 91.30418,  19.809296, 71.62177};
  const int8_t ans[M * N] = {18, 13, 16, 38, 22, 33, 85, 54,
                              85, 74, 3,  11, 4,  91, 20, 72};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x12);
  msettypehi(0x4);
  mint8_t md = mfncvt_x_fq_m(ms);
  SET_MBA0_I8();
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MFNCVT_X_FQ_M F32");
}

static void test_mfncvt_b_f_m() {
  const size_t M = 4;
  const size_t N = 4;
  const fp32_t src[M * N] = {17.726198, 13.14702,  16.021738, 38.334526,
                             21.896717, 33.407013, 84.70619,  53.706272,
                             84.83878,  74.49762,  3.0108328, 10.992341,
                             3.8677173, 91.30418,  19.809296, 71.62177};
  const int8_t ans[M * N] = {18, 13, 16, 38, 22, 33, 85, 54,
                              85, 74, 3,  11, 4,  91, 20, 72};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, N * sizeof(fp32_t));
  msettypei(0x12);
  msettypehi(0x4);
  mint8_t md = mfncvt_b_f_m(ms);
  SET_MBA0_I8();
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MFNCVT_B_F_M");
}

static void test_mfncvt_x_fq_m() {
  test_mfncvt_x_fq_m_f32();
  test_mfncvt_b_f_m();
}


static void test_cvt() {
  test_mcvt_x_xu_mm();
  test_mcvt_xu_x_mm();
  test_mwcvtu_xu_x_m();
  test_mwcvtu_xq_x_m();
  test_mwcvt_xw_x_m();
  test_mwcvt_xq_x_m();
  test_mncvtu_x_xw_m();
  test_mncvtu_x_xq_m();
  test_mncvt_x_xw_m();
  test_mncvt_x_xq_m();
  test_mfwcvt_fw_f_m();
  test_mfncvt_f_fw_m();
  test_mfcvtu_f_x_m();
  test_mfcvt_f_x_m();
  test_mfwcvt_fw_x_m();
  test_mfwcvt_fq_x_m();
  test_mfwcvtu_fw_x_m();
  test_mfwcvtu_fq_x_m();
  test_mfcvtu_x_f_m();
  test_mfcvt_x_f_m();
  test_mfwcvtu_xw_f_m();
  test_mfwcvt_xw_f_m();
  test_mfncvtu_x_fw();
  test_mfncvtu_x_fq_m();
  test_mfncvt_x_fw_m();
  test_mfncvt_x_fq_m();
}

#endif // !MATRIX_TESTS_ISA_CVT_H_