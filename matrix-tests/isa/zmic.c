#include "utils.h"
#include <riscv_matrix.h>

static void test_mlufae8_and_msfdae8() {
  const int8_t i8_src[] = {-1, 0, 1, 2};
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
  msettype(E8, M1, BA);
  msettilemi(4);
  msettileki(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint8m1_t tr0 = mlufae8_m(i8_src, cin * sizeof(int8_t));
  msae8_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "  MLUFAE INT8  ");
  msfdae8_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "  MLUFAE INT8  ");
  muint8m1_t tr1 = mlufae8_m(u8_src, cin * sizeof(uint8_t));
  msae8_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "  MLUFAE UINT8 ");
  msfdae8_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "  MLUFAE UINT8 ");
}

static void test_mlufbe8_and_msfdbe8() {
  const int8_t i8_src[] = {-1, 0, 1, 2};
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
  msettype(E8, M1, BA);
  msettileki(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint8m1_t tr0 = mlufbe8_m(i8_src, cin * sizeof(int8_t));
  msbe8_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "  MLUFAE INT8  ");
  msfdbe8_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "  MLUFAE INT8  ");
  muint8m1_t tr1 = mlufbe8_m(u8_src, cin * sizeof(uint8_t));
  msbe8_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "  MLUFAE UINT8 ");
  msfdbe8_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "  MLUFAE INT8  ");
}

static void test_mlufce8_and_msfdce8() {
  const int8_t i8_src[] = {-1, 0, 1, 2};
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
  msettype(E8, M1, BA);
  msettilemi(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint8m1_t tr0 = mlufce8_m(i8_src, cin * sizeof(int8_t));
  msce8_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "  MLUFAE INT8  ");
  msfdce8_m(tr0, i8_buffer, cin * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 4, "  MLUFAE INT8  ");
  muint8m1_t tr1 = mlufce8_m(u8_src, cin * sizeof(uint8_t));
  msce8_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "  MLUFAE UINT8 ");
  msfdce8_m(tr1, u8_buffer, cin * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 4, "  MLUFAE INT8  ");
}

static void test_mlufae16_and_msfdae16() {
  const int16_t i16_src[] = {20504,  -395,  29852, -16672,
                             -11454, -2232, 1856,  474};
  const int16_t i16_ans[] = {20504, -395, 29852, -16672};
  const uint16_t u16_src[] = {20857, 41559, 24879, 11631,
                              5146,  6351,  13363, 16201};
  const uint16_t u16_ans[] = {20857, 41559, 24879, 11631};
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
  msettype(E16, M1, BA);
  msettilemi(1);
  msettileki(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint16m1_t tr0 = mlufae16_m(i16_src, cin * sizeof(int16_t));
  msae16_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFAE INT16 ");
  msfdae16_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDAE INT16 ");
  muint16m1_t tr1 = mlufae16_m(u16_src, cin * sizeof(uint16_t));
  msae16_m(tr1, u16_buffer, cin * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFAE UINT16");
  msfdae16_m(tr1, u16_buffer, cin * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDAE UINT16");
  mfloat16m1_t tr2 = mlufae16_m(fp16_src, cin * sizeof(fp16_t));
  msae16_m(tr2, fp16_buffer, cin * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, " MLUFAE FP16  ");
  msfdae16_m(tr2, fp16_buffer, cin * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 4, " MSFDAE FP16  ");
}

static void test_mlufbe16_and_msfdbe16() {
  const int16_t i16_src[] = {20504,  -395,  29852, -16672,
                             -11454, -2232, 1856,  474};
  const int16_t i16_ans[] = {20504, -395, 29852, -16672};
  const uint16_t u16_src[] = {20857, 41559, 24879, 11631,
                              5146,  6351,  13363, 16201};
  const uint16_t u16_ans[] = {20857, 41559, 24879, 11631};
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
  msettype(E16, M1, BA);
  msettileki(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint16m1_t tr0 = mlufbe16_m(i16_src, cin * sizeof(int16_t));
  msbe16_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFBE INT16 ");
  msfdbe16_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDBE INT16 ");
  muint16m1_t tr1 = mlufbe16_m(u16_src, cin * sizeof(uint16_t));
  msbe16_m(tr1, u16_buffer, cin * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFBE UINT16");
  msfdbe16_m(tr1, u16_buffer, cin * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDBE UINT16");
  mfloat16m1_t tr2 = mlufbe16_m(fp16_src, cin * sizeof(fp16_t));
  msbe16_m(tr2, fp16_buffer, cin * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, " MLUFBE FP16  ");
  msfdbe16_m(tr2, fp16_buffer, cin * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 4, " MSFDBE FP16  ");
}

static void test_mlufce16_and_msfdce16() {
  const int16_t i16_src[] = {20504,  -395,  29852, -16672,
                             -11454, -2232, 1856,  474};
  const int16_t i16_ans[] = {20504, -395, 29852, -16672};
  const uint16_t u16_src[] = {20857, 41559, 24879, 11631,
                              5146,  6351,  13363, 16201};
  const uint16_t u16_ans[] = {20857, 41559, 24879, 11631};
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
  msettype(E16, M1, BA);
  msettilemi(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint16m1_t tr0 = mlufce16_m(i16_src, cin * sizeof(int16_t));
  msce16_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFCE INT16 ");
  msfdce16_m(tr0, i16_buffer, cin * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDCE INT16 ");
  muint16m1_t tr1 = mlufce16_m(u16_src, cin * sizeof(uint16_t));
  msce16_m(tr1, u16_buffer, cin * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFCE UINT16");
  msfdce16_m(tr1, u16_buffer, cin * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDCE UINT16");
  mfloat16m1_t tr2 = mlufce16_m(fp16_src, cin * sizeof(fp16_t));
  msce16_m(tr2, fp16_buffer, cin * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, " MLUFCE FP16  ");
  msfdce16_m(tr2, fp16_buffer, cin * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 4, " MSFDCE FP16  ");
}

static void test_mlufae32_and_msfdae32() {
  const int32_t i32_src[] = {0, 1, 2, 3};
  const int32_t i32_ans[] = {0, 1, 2, 3};
  const uint32_t u32_src[] = {0, 1, 2, 3};
  const uint32_t u32_ans[] = {0, 1, 2, 3};
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
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileki(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mint32m1_t tr0 = mlufae32_m(i32_src, cin * sizeof(float));
  msae32_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 4, " MLUFAE INT32 ");
  msfdae32_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, " MSFDAE INT32 ");
  muint32m1_t tr1 = mlufae32_m(u32_src, cin * sizeof(float));
  msae32_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 4, " MLUFAE UINT32");
  msfdae32_m(tr0, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, " MSFDAE UINT32");
  mfloat32m1_t tr2 = mlufae32_m(fp32_src, cin * sizeof(float));
  msae32_m(tr2, fp32_buffer, cin * sizeof(float));
  EXCEPT_FP32_ARRAY_LAX_EQ(fp32_ans, fp32_buffer, 4, " MLUFAE FP32  ");
  msfdae32_m(tr2, fp32_buffer, cin * sizeof(float));
  EXCEPT_FP32_ARRAY_LAX_EQ(fp32_src, fp32_buffer, 4, " MSFDAE FP32  ");
}

static void test_mlufbe32_and_msfdbe32() {
  const int32_t i32_src[] = {0, 1, 2, 3};
  const int32_t i32_ans[] = {0, 1, 2, 3};
  const uint32_t u32_src[] = {0, 1, 2, 3};
  const uint32_t u32_ans[] = {0, 1, 2, 3};
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
  msettype(E32, M1, BA);
  msettileki(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mint32m1_t tr0 = mlufbe32_m(i32_src, cin * sizeof(float));
  msbe32_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 4, " MLUFBE INT32 ");
  msfdbe32_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, " MSFDBE INT32 ");
  muint32m1_t tr1 = mlufbe32_m(u32_src, cin * sizeof(float));
  msbe32_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 4, " MLUFBE UINT32");
  msfdbe32_m(tr0, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, " MSFDBE UINT32");
  mfloat32m1_t tr2 = mlufbe32_m(fp32_src, cin * sizeof(float));
  msbe32_m(tr2, fp32_buffer, cin * sizeof(float));
  EXCEPT_FP32_ARRAY_LAX_EQ(fp32_ans, fp32_buffer, 4, " MLUFBE FP32  ");
  msfdbe32_m(tr2, fp32_buffer, cin * sizeof(float));
  EXCEPT_FP32_ARRAY_LAX_EQ(fp32_src, fp32_buffer, 4, " MSFDBE FP32  ");
}

static void test_mlufce32_and_msfdce32() {
  const int32_t i32_src[] = {0, 1, 2, 3};
  const int32_t i32_ans[] = {0, 1, 2, 3};
  const uint32_t u32_src[] = {0, 1, 2, 3};
  const uint32_t u32_ans[] = {0, 1, 2, 3};
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
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileni(4);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | (0 & 0xffff), 0 << 16 | 0);
  msetpadval(0);
  mint32m1_t tr0 = mlufce32_m(i32_src, cin * sizeof(float));
  msce32_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 4, " MLUFCE INT32 ");
  msfdce32_m(tr0, i32_buffer, cin * sizeof(float));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, " MSFDCE INT32 ");
  muint32m1_t tr1 = mlufce32_m(u32_src, cin * sizeof(float));
  msce32_m(tr1, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 4, " MLUFCE UINT32");
  msfdce32_m(tr0, u32_buffer, cin * sizeof(float));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, " MSFDCE UINT32");
  mfloat32m1_t tr2 = mlufce32_m(fp32_src, cin * sizeof(float));
  msce32_m(tr2, fp32_buffer, cin * sizeof(float));
  EXCEPT_FP32_ARRAY_LAX_EQ(fp32_ans, fp32_buffer, 4, " MLUFCE FP32  ");
  msfdce32_m(tr2, fp32_buffer, cin * sizeof(float));
  EXCEPT_FP32_ARRAY_LAX_EQ(fp32_src, fp32_buffer, 4, " MSFDCE FP32  ");
}

static void test_mlufae64_and_msfdae64() {
  const int64_t i64_src[] = {-1, 0, 1, 2};
  const int64_t i64_ans[] = {-1, 0, 1, 2};
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
  msettype(E64, M1, BA);
  msettilemi(4);
  msettileki(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64m1_t tr0 = mlufae64_m(i64_src, cin * sizeof(int64_t));
  msae64_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, " MLUFAE INT64 ");
  msfdae64_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, " MLUFAE INT64 ");
  muint64m1_t tr1 = mlufae64_m(u64_src, cin * sizeof(uint64_t));
  msae64_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 4, " MLUFAE UINT64");
  msfdae64_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, " MLUFAE UINT64");
  mfloat64m1_t tr2 = mlufae64_m(fp64_src, cin * sizeof(fp64_t));
  msae64_m(tr2, fp64_buffer, cin * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 4, " MLUFAE FP64  ");
  msfdae64_m(tr2, fp64_buffer, cin * sizeof(int64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, " MLUFAE FP64  ");
}

static void test_mlufbe64_and_msfdbe64() {
  const int64_t i64_src[] = {-1, 0, 1, 2};
  const int64_t i64_ans[] = {-1, 0, 1, 2};
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
  msettype(E64, M1, BA);
  msettileki(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64m1_t tr0 = mlufbe64_m(i64_src, cin * sizeof(int64_t));
  msbe64_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, " MLUFAE INT64 ");
  msfdbe64_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, " MLUFAE INT64 ");
  muint64m1_t tr1 = mlufbe64_m(u64_src, cin * sizeof(uint64_t));
  msbe64_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 4, " MLUFAE UINT64");
  msfdbe64_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, " MLUFAE UINT64");
  mfloat64m1_t tr2 = mlufbe64_m(fp64_src, cin * sizeof(fp64_t));
  msbe64_m(tr2, fp64_buffer, cin * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 4, " MLUFAE FP64  ");
  msfdbe64_m(tr2, fp64_buffer, cin * sizeof(int64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, " MLUFAE FP64  ");
}

static void test_mlufce64_and_msfdce64() {
  const int64_t i64_src[] = {-1, 0, 1, 2};
  const int64_t i64_ans[] = {-1, 0, 1, 2};
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
  msettype(E64, M1, BA);
  msettilemi(4);
  msettileni(1);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64m1_t tr0 = mlufce64_m(i64_src, cin * sizeof(int64_t));
  msce64_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, " MLUFAE INT64 ");
  msfdce64_m(tr0, i64_buffer, cin * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, " MLUFAE INT64 ");
  muint64m1_t tr1 = mlufce64_m(u64_src, cin * sizeof(uint64_t));
  msce64_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 4, " MLUFAE UINT64");
  msfdce64_m(tr1, u64_buffer, cin * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, " MLUFAE UINT64");
  mfloat64m1_t tr2 = mlufce64_m(fp64_src, cin * sizeof(fp64_t));
  msce64_m(tr2, fp64_buffer, cin * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 4, " MLUFAE FP64  ");
  msfdce64_m(tr2, fp64_buffer, cin * sizeof(int64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, " MLUFAE FP64  ");
}

int main() {
  test_mlufae8_and_msfdae8();
  test_mlufbe8_and_msfdbe8();
  test_mlufce8_and_msfdce8();
  test_mlufae16_and_msfdae16();
  test_mlufbe16_and_msfdbe16();
  test_mlufce16_and_msfdce16();
  test_mlufae32_and_msfdae32();
  test_mlufbe32_and_msfdbe32();
  test_mlufce32_and_msfdce32();
  test_mlufae64_and_msfdae64();
  test_mlufbe64_and_msfdbe64();
  test_mlufce64_and_msfdce64();
  return 0;
}