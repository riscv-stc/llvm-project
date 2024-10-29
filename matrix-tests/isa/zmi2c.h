#ifndef MATRIX_TESTS_ISA_ZMI2C_H_
#define MATRIX_TESTS_ISA_ZMI2C_H_

#include "utils.h"
#include "riscv_matrix.h"

static void test_mlufa_m_msfda_m_i8() {
  const int8_t i8_src[] = {-1, 0, 1, 2};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I8();
  msettilemi(4);
  msettileki(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint8_t tr0 = mlufa_m(i8_src, cin * sizeof(int8_t));
  msa_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "MLUFA I8");
  msfda_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "MSFDA I8");
}

static void test_mlufa_m_msfda_m_u8() {
  const uint8_t u8_src[] = {1, 2, 3, 4};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I8();
  msettilemi(4);
  msettileki(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint8_t tr1 = mlufa_m(u8_src, cin * sizeof(uint8_t));
  msa_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "MLUFAE U8");
  msfda_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "MLUFAE U8");
}

static void test_mlufa_m_msfda_m_i16() {
  const int16_t i16_src[] = {20504,  -395,  29852, -16672,
                             -11454, -2232, 1856,  474};
  const int16_t i16_ans[] = {20504, -395, 29852, -16672};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I16();
  msettilemi(1);
  msettileki(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint16_t tr0 = mlufa_m(i16_src, cin * sizeof(int16_t));
  msa_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFA I16");
  msfda_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDA I16");
}

static void test_mlufa_m_msfda_m_u16() {
  const uint16_t u16_src[] = {20857, 41559, 24879, 11631,
                              5146,  6351,  13363, 16201};
  const uint16_t u16_ans[] = {20857, 41559, 24879, 11631};;
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I16();
  msettilemi(1);
  msettileki(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint16_t tr1 = mlufa_m(u16_src, cin * sizeof(uint16_t));
  msa_m(tr1, u16_buffer, cin * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFA U16");
  msfda_m(tr1, u16_buffer, cin * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDA U16");
}

static void test_mlufa_m_msfda_m_f16() {
  const fp16_t fp16_src[] = {7.56538647, 9.87196012,  8.27317843, -9.27718783,
                             6.57169182, -5.42505187, 8.42640724, 0.18009302};
  const fp16_t fp16_ans[] = {7.56538647, 9.87196012, 8.27317843, -9.27718783};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F16();
  msettilemi(1);
  msettileki(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mfloat16_t tr2 = mlufa_m(fp16_src, cin * sizeof(fp16_t));
  msa_m(tr2, f16_buffer, cin * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(fp16_ans, f16_buffer, 4, " MLUFA F16");
  msfda_m(tr2, f16_buffer, cin * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(fp16_src, f16_buffer, 4, " MSFDA F16");
}

static void test_mlufa_m_msfda_m_i32() {
  const int32_t i32_src[] = {0, 1, 2, 3};
  const int32_t i32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I32();
  msettilemi(1);
  msettileki(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mint32_t tr0 = mlufa_m(i32_src, cin * sizeof(float));
  msa_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 4, "MLUFA I32");
  msfda_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MSFDA I32");
}

static void test_mlufa_m_msfda_m_u32() {
  const uint32_t u32_src[] = {0, 1, 2, 3};
  const uint32_t u32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I32();
  msettilemi(1);
  msettileki(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  muint32_t tr1 = mlufa_m(u32_src, cin * sizeof(float));
  msa_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 4, "MLUFA U32");
  msfda_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MSFDA U32");
}

static void test_mlufa_m_msfda_m_f32() {
  const float fp32_src[] = {0, 1, 2, 3};
  const float fp32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F32();
  msettilemi(1);
  msettileki(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mfloat32_t tr2 = mlufa_m(fp32_src, cin * sizeof(float));
  msa_m(tr2, f32_buffer, cin * sizeof(float));
  EXCEPT_F32_ARRAY_LAX_EQ(fp32_ans, f32_buffer, 4, "MLUFA F32");
  msfda_m(tr2, f32_buffer, cin * sizeof(float));
  EXCEPT_F32_ARRAY_LAX_EQ(fp32_src, f32_buffer, 4, "MSFDA F32");
}

static void test_mlufa_m_msfda_m_i64() {
  const int64_t i64_src[] = {-1, 0, 1, 2};
  const int64_t i64_ans[] = {-1, 0, 1, 2};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I64();
  msettilemi(4);
  msettileki(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64_t tr0 = mlufa_m(i64_src, cin * sizeof(int64_t));
  msa_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, "MLUFA I64");
  msfda_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MSFDA I64");
}

static void test_mlufa_m_msfda_m_u64() {
  const uint64_t u64_src[] = {0, 1, 2, 3};
  const uint64_t u64_ans[] = {0, 1, 2, 3};
  const fp64_t fp64_src[] = {0, 1, 2, 3};
  const fp64_t fp64_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I64();
  msettilemi(4);
  msettileki(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint64_t tr1 = mlufa_m(u64_src, cin * sizeof(uint64_t));
  msa_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 4, "MLUFA U64");
  msfda_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MSFDA U64");
}

static void test_mlufa_m_msfda_m_f64() {
  const uint64_t u64_src[] = {0, 1, 2, 3};
  const uint64_t u64_ans[] = {0, 1, 2, 3};
  const fp64_t fp64_src[] = {0, 1, 2, 3};
  const fp64_t fp64_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F64();
  msettilemi(4);
  msettileki(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mfloat64_t tr2 = mlufa_m(fp64_src, cin * sizeof(fp64_t));
  msa_m(tr2, f64_buffer, cin * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(fp64_ans, f64_buffer, 4, "MLUFA F64");
  msfda_m(tr2, f64_buffer, cin * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(fp64_src, f64_buffer, 4, "MSFDA F64");
}

static void test_mlufa_m_msfda_m() {
  test_mlufa_m_msfda_m_i8();
  test_mlufa_m_msfda_m_u8();
  test_mlufa_m_msfda_m_i16();
  test_mlufa_m_msfda_m_u16();
  test_mlufa_m_msfda_m_f16();
  test_mlufa_m_msfda_m_i32();
  test_mlufa_m_msfda_m_u32();
  test_mlufa_m_msfda_m_f32();
  test_mlufa_m_msfda_m_i64();
  test_mlufa_m_msfda_m_u64();
  test_mlufa_m_msfda_m_f64();
}

static void test_mlufb_m_msfdb_m_i8() {
  const int8_t i8_src[] = {-1, 0, 1, 2};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I8();
  msettileki(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint8_t tr0 = mlufb_m(i8_src, cin * sizeof(int8_t));
  msb_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "MLUFB I8");
  msfdb_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "MSFDB I8");
}

static void test_mlufb_m_msfdb_m_u8() {
  const uint8_t u8_src[] = {1, 2, 3, 4};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I8();
  msettileki(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint8_t tr1 = mlufb_m(u8_src, cin * sizeof(uint8_t));
  msb_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "MLUFBE U8");
  msfdb_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "MLUFBE U8");
}

static void test_mlufb_m_msfdb_m_i16() {
  const int16_t i16_src[] = {20504,  -395,  29852, -16672,
                             -11454, -2232, 1856,  474};
  const int16_t i16_ans[] = {20504, -395, 29852, -16672};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I16();
  msettileki(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint16_t tr0 = mlufb_m(i16_src, cin * sizeof(int16_t));
  msb_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFB I16");
  msfdb_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDB I16");
}

static void test_mlufb_m_msfdb_m_u16() {
  const uint16_t u16_src[] = {20857, 41559, 24879, 11631,
                              5146,  6351,  13363, 16201};
  const uint16_t u16_ans[] = {20857, 41559, 24879, 11631};;
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I16();
  msettileki(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint16_t tr1 = mlufb_m(u16_src, cin * sizeof(uint16_t));
  msb_m(tr1, u16_buffer, cin * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFB U16");
  msfdb_m(tr1, u16_buffer, cin * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDB U16");
}

static void test_mlufb_m_msfdb_m_f16() {
  const fp16_t fp16_src[] = {7.56538647, 9.87196012,  8.27317843, -9.27718783,
                             6.57169182, -5.42505187, 8.42640724, 0.18009302};
  const fp16_t fp16_ans[] = {7.56538647, 9.87196012, 8.27317843, -9.27718783};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F16();
  msettileki(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mfloat16_t tr2 = mlufb_m(fp16_src, cin * sizeof(fp16_t));
  msb_m(tr2, f16_buffer, cin * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(fp16_ans, f16_buffer, 4, " MLUFB F16");
  msfdb_m(tr2, f16_buffer, cin * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(fp16_src, f16_buffer, 4, " MSFDB F16");
}

static void test_mlufb_m_msfdb_m_i32() {
  const int32_t i32_src[] = {0, 1, 2, 3};
  const int32_t i32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I32();
  msettileki(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mint32_t tr0 = mlufb_m(i32_src, cin * sizeof(float));
  msb_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 4, "MLUFB I32");
  msfdb_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MSFDB I32");
}

static void test_mlufb_m_msfdb_m_u32() {
  const uint32_t u32_src[] = {0, 1, 2, 3};
  const uint32_t u32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I32();
  msettileki(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  muint32_t tr1 = mlufb_m(u32_src, cin * sizeof(float));
  msb_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 4, "MLUFB U32");
  msfdb_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MSFDB U32");
}

static void test_mlufb_m_msfdb_m_f32() {
  const float fp32_src[] = {0, 1, 2, 3};
  const float fp32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F32();
  msettileki(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mfloat32_t tr2 = mlufb_m(fp32_src, cin * sizeof(float));
  msb_m(tr2, f32_buffer, cin * sizeof(float));
  EXCEPT_F32_ARRAY_LAX_EQ(fp32_ans, f32_buffer, 4, "MLUFB F32");
  msfdb_m(tr2, f32_buffer, cin * sizeof(float));
  EXCEPT_F32_ARRAY_LAX_EQ(fp32_src, f32_buffer, 4, "MSFDB F32");
}

static void test_mlufb_m_msfdb_m_i64() {
  const int64_t i64_src[] = {-1, 0, 1, 2};
  const int64_t i64_ans[] = {-1, 0, 1, 2};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I64();
  msettileki(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64_t tr0 = mlufb_m(i64_src, cin * sizeof(int64_t));
  msb_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, "MLUFB I64");
  msfdb_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MSFDB I64");
}

static void test_mlufb_m_msfdb_m_u64() {
  const uint64_t u64_src[] = {0, 1, 2, 3};
  const uint64_t u64_ans[] = {0, 1, 2, 3};
  const fp64_t fp64_src[] = {0, 1, 2, 3};
  const fp64_t fp64_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I64();
  msettileki(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint64_t tr1 = mlufb_m(u64_src, cin * sizeof(uint64_t));
  msb_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 4, "MLUFB U64");
  msfdb_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MSFDB U64");
}

static void test_mlufb_m_msfdb_m_f64() {
  const uint64_t u64_src[] = {0, 1, 2, 3};
  const uint64_t u64_ans[] = {0, 1, 2, 3};
  const fp64_t fp64_src[] = {0, 1, 2, 3};
  const fp64_t fp64_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F64();
  msettileki(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mfloat64_t tr2 = mlufb_m(fp64_src, cin * sizeof(fp64_t));
  msb_m(tr2, f64_buffer, cin * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(fp64_ans, f64_buffer, 4, "MLUFB F64");
  msfdb_m(tr2, f64_buffer, cin * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(fp64_src, f64_buffer, 4, "MSFDB F64");
}

static void test_mlufb_m_msfdb_m() {
  test_mlufb_m_msfdb_m_i8();
  test_mlufb_m_msfdb_m_u8();
  test_mlufb_m_msfdb_m_i16();
  test_mlufb_m_msfdb_m_u16();
  test_mlufb_m_msfdb_m_f16();
  test_mlufb_m_msfdb_m_i32();
  test_mlufb_m_msfdb_m_u32();
  test_mlufb_m_msfdb_m_f32();
  test_mlufb_m_msfdb_m_i64();
  test_mlufb_m_msfdb_m_u64();
  test_mlufb_m_msfdb_m_f64();
}

static void test_mlufc_m_msfdc_m_i8() {
  const int8_t i8_src[] = {-1, 0, 1, 2};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I8();
  msettilemi(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint8_t tr0 = mlufc_m(i8_src, cin * sizeof(int8_t));
  msc_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "MLUFC I8");
  msfdc_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "MSFDC I8");
}

static void test_mlufc_m_msfdc_m_u8() {
  const uint8_t u8_src[] = {1, 2, 3, 4};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I8();
  msettilemi(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint8_t tr1 = mlufc_m(u8_src, cin * sizeof(uint8_t));
  msc_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "MLUFCE U8");
  msfdc_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "MLUFCE U8");
}

static void test_mlufc_m_msfdc_m_i16() {
  const int16_t i16_src[] = {20504,  -395,  29852, -16672,
                             -11454, -2232, 1856,  474};
  const int16_t i16_ans[] = {20504, -395, 29852, -16672};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I16();
  msettilemi(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint16_t tr0 = mlufc_m(i16_src, cin * sizeof(int16_t));
  msc_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFC I16");
  msfdc_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDC I16");
}

static void test_mlufc_m_msfdc_m_u16() {
  const uint16_t u16_src[] = {20857, 41559, 24879, 11631,
                              5146,  6351,  13363, 16201};
  const uint16_t u16_ans[] = {20857, 41559, 24879, 11631};;
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I16();
  msettilemi(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint16_t tr1 = mlufc_m(u16_src, cin * sizeof(uint16_t));
  msc_m(tr1, u16_buffer, cin * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFC U16");
  msfdc_m(tr1, u16_buffer, cin * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDC U16");
}

static void test_mlufc_m_msfdc_m_f16() {
  const fp16_t fp16_src[] = {7.56538647, 9.87196012,  8.27317843, -9.27718783,
                             6.57169182, -5.42505187, 8.42640724, 0.18009302};
  const fp16_t fp16_ans[] = {7.56538647, 9.87196012, 8.27317843, -9.27718783};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F16();
  msettilemi(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mfloat16_t tr2 = mlufc_m(fp16_src, cin * sizeof(fp16_t));
  msc_m(tr2, f16_buffer, cin * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(fp16_ans, f16_buffer, 4, " MLUFC F16");
  msfdc_m(tr2, f16_buffer, cin * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(fp16_src, f16_buffer, 4, " MSFDC F16");
}

static void test_mlufc_m_msfdc_m_i32() {
  const int32_t i32_src[] = {0, 1, 2, 3};
  const int32_t i32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I32();
  msettilemi(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mint32_t tr0 = mlufc_m(i32_src, cin * sizeof(float));
  msc_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 4, "MLUFC I32");
  msfdc_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MSFDC I32");
}

static void test_mlufc_m_msfdc_m_u32() {
  const uint32_t u32_src[] = {0, 1, 2, 3};
  const uint32_t u32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I32();
  msettilemi(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  muint32_t tr1 = mlufc_m(u32_src, cin * sizeof(float));
  msc_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 4, "MLUFC U32");
  msfdc_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MSFDC U32");
}

static void test_mlufc_m_msfdc_m_f32() {
  const float fp32_src[] = {0, 1, 2, 3};
  const float fp32_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F32();
  msettilemi(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mfloat32_t tr2 = mlufc_m(fp32_src, cin * sizeof(float));
  msc_m(tr2, f32_buffer, cin * sizeof(float));
  EXCEPT_F32_ARRAY_LAX_EQ(fp32_ans, f32_buffer, 4, "MLUFC F32");
  msfdc_m(tr2, f32_buffer, cin * sizeof(float));
  EXCEPT_F32_ARRAY_LAX_EQ(fp32_src, f32_buffer, 4, "MSFDC F32");
}

static void test_mlufc_m_msfdc_m_i64() {
  const int64_t i64_src[] = {-1, 0, 1, 2};
  const int64_t i64_ans[] = {-1, 0, 1, 2};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I64();
  msettilemi(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64_t tr0 = mlufc_m(i64_src, cin * sizeof(int64_t));
  msc_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, "MLUFC I64");
  msfdc_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MSFDC I64");
}

static void test_mlufc_m_msfdc_m_u64() {
  const uint64_t u64_src[] = {0, 1, 2, 3};
  const uint64_t u64_ans[] = {0, 1, 2, 3};
  const fp64_t fp64_src[] = {0, 1, 2, 3};
  const fp64_t fp64_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_I64();
  msettilemi(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  muint64_t tr1 = mlufc_m(u64_src, cin * sizeof(uint64_t));
  msc_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 4, "MLUFC U64");
  msfdc_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MSFDC U64");
}

static void test_mlufc_m_msfdc_m_f64() {
  const uint64_t u64_src[] = {0, 1, 2, 3};
  const uint64_t u64_ans[] = {0, 1, 2, 3};
  const fp64_t fp64_src[] = {0, 1, 2, 3};
  const fp64_t fp64_ans[] = {0, 1, 2, 3};
  int cin = 1;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 1;
  int padding = 0;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  SET_MBA0_F64();
  msettilemi(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mfloat64_t tr2 = mlufc_m(fp64_src, cin * sizeof(fp64_t));
  msc_m(tr2, f64_buffer, cin * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(fp64_ans, f64_buffer, 4, "MLUFC F64");
  msfdc_m(tr2, f64_buffer, cin * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(fp64_src, f64_buffer, 4, "MSFDC F64");
}

static void test_mlufc_m_msfdc_m() {
  test_mlufc_m_msfdc_m_i8();
  test_mlufc_m_msfdc_m_u8();
  test_mlufc_m_msfdc_m_i16();
  test_mlufc_m_msfdc_m_u16();
  test_mlufc_m_msfdc_m_f16();
  test_mlufc_m_msfdc_m_i32();
  test_mlufc_m_msfdc_m_u32();
  test_mlufc_m_msfdc_m_f32();
  test_mlufc_m_msfdc_m_i64();
  test_mlufc_m_msfdc_m_u64();
  test_mlufc_m_msfdc_m_f64();
}

static void test_zmi2c() {
  test_mlufa_m_msfda_m();
  test_mlufb_m_msfdb_m();
  test_mlufc_m_msfdc_m();
}

#endif // !MATRIX_TESTS_ISA_ZMI2C_H_