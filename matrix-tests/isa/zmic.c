#include "utils.h"
#include <riscv_matrix.h>

static void test_mlufae8_and_msfdae8() {
  const int8_t i8_src[] = {1, 4, 2, 3, 3, 2, -4, -1};
  const int8_t i8_ans[] = {1, 4, 2, 3, 0, 0, 3, 2, -4, -1};
  const uint8_t u8_src[] = {59, 117, 250, 100, 215, 38, 174, 35};
  const uint8_t u8_ans[] = {59, 117, 250, 100, 0, 0, 215, 38, 174, 35};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 1;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  msettype(E8, M1, BA);
  msettilemi(5);
  msettileki(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 1);
  msetpadval(0);
  mint8m1_t tr0 = mlufae8_m(i8_src, 2 * sizeof(int8_t));
  msae8_m(tr0, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 10, "  MLUFAE INT8  ");
  msfdae8_m(tr0, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 8, "  MSFDAE INT8  ");
  muint8m1_t tr1 = mlufae8_m(u8_src, 2 * sizeof(uint8_t));
  msae8_m(tr1, u8_buffer, 2 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 10, "  MLUFAE UINT8 ");
  msfdae8_m(tr1, u8_buffer, 2 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 8, "  MSFDAE UINT8 ");
}

static void test_mlufbe8_and_msfdbe8() {
  const int8_t i8_src[] = {1, 4, 2, 3, 3, 2, -4, -1};
  const int8_t i8_ans[] = {1, 4, 2, 3, 0, 0, 3, 2, -4, -1};
  const uint8_t u8_src[] = {59, 117, 250, 100, 215, 38, 174, 35};
  const uint8_t u8_ans[] = {59, 117, 250, 100, 0, 0, 215, 38, 174, 35};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 1;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  msettype(E8, M1, BA);
  msettileki(5);
  msettileni(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 1);
  msetpadval(0);
  mint8m1_t tr0 = mlufbe8_m(i8_src, 2 * sizeof(int8_t));
  msbe8_m(tr0, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 10, "  MLUFBE INT8  ");
  msfdbe8_m(tr0, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 8, "  MSFDBE INT8  ");
  muint8m1_t tr1 = mlufbe8_m(u8_src, 2 * sizeof(uint8_t));
  msbe8_m(tr1, u8_buffer, 2 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 10, "  MLUFBE UINT8 ");
  msfdbe8_m(tr1, u8_buffer, 2 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 8, "  MSFDBE UINT8 ");
}

static void test_mlufce8_and_msfdce8() {
  const int8_t i8_src[] = {1, 4, 2, 3, 3, 2, -4, -1};
  const int8_t i8_ans[] = {1, 4, 2, 3, 0, 0, 3, 2, -4, -1};
  const uint8_t u8_src[] = {59, 117, 250, 100, 215, 38, 174, 35};
  const uint8_t u8_ans[] = {59, 117, 250, 100, 0, 0, 215, 38, 174, 35};
  int cin = 2;
  int hin = 2;
  int win = 2;
  int stride = 1;
  int kernel = 2;
  int padding = 1;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  msettype(E8, M1, BA);
  msettilemi(5);
  msettileni(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 1);
  msetpadval(0);
  mint8m1_t tr0 = mlufce8_m(i8_src, 2 * sizeof(int8_t));
  msce8_m(tr0, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 8, "  MLUFCE INT8  ");
  msfdce8_m(tr0, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 8, " MSFDCE INT8  ");
  muint8m1_t tr1 = mlufce8_m(u8_src, 2 * sizeof(uint8_t));
  msce8_m(tr1, u8_buffer, 2 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, " MLUFCE UINT8 ");
  msfdce8_m(tr1, u8_buffer, 2 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 8, " MSFDCE UINT8 ");
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
  mint16m1_t tr0 = mlufae16_m(i16_src, 2 * sizeof(int16_t));
  msae16_m(tr0, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFAE INT16 ");
  msfdae16_m(tr0, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDAE INT16 ");
  muint16m1_t tr1 = mlufae16_m(u16_src, 2 * sizeof(uint16_t));
  msae16_m(tr1, u16_buffer, 2 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFAE UINT16");
  msfdae16_m(tr1, u16_buffer, 2 * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDAE UINT16");
  mfloat16m1_t tr2 = mlufae16_m(fp16_src, 2 * sizeof(fp16_t));
  msae16_m(tr2, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, " MLUFAE FP16  ");
  msfdae16_m(tr2, fp16_buffer, 2 * sizeof(fp16_t));
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
  mint16m1_t tr0 = mlufbe16_m(i16_src, 2 * sizeof(int16_t));
  msbe16_m(tr0, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFBE INT16 ");
  msfdbe16_m(tr0, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDBE INT16 ");
  muint16m1_t tr1 = mlufbe16_m(u16_src, 2 * sizeof(uint16_t));
  msbe16_m(tr1, u16_buffer, 2 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFBE UINT16");
  msfdbe16_m(tr1, u16_buffer, 2 * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDBE UINT16");
  mfloat16m1_t tr2 = mlufbe16_m(fp16_src, 2 * sizeof(fp16_t));
  msbe16_m(tr2, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, " MLUFBE FP16  ");
  msfdbe16_m(tr2, fp16_buffer, 2 * sizeof(fp16_t));
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
  mint16m1_t tr0 = mlufce16_m(i16_src, 2 * sizeof(int16_t));
  msce16_m(tr0, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 4, " MLUFCE INT16 ");
  msfdce16_m(tr0, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 4, " MSFDCE INT16 ");
  muint16m1_t tr1 = mlufce16_m(u16_src, 2 * sizeof(uint16_t));
  msce16_m(tr1, u16_buffer, 2 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 4, " MLUFCE UINT16");
  msfdce16_m(tr1, u16_buffer, 2 * sizeof(int16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 4, " MSFDCE UINT16");
  mfloat16m1_t tr2 = mlufce16_m(fp16_src, 2 * sizeof(fp16_t));
  msce16_m(tr2, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, " MLUFCE FP16  ");
  msfdce16_m(tr2, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 4, " MSFDCE FP16  ");
}

static void test_mlufae32_and_msfdae32() {
  const int32_t i32_src[] = {-1011514960, -608940596, -1955188614, 1215601751,
                             1758987289,  1018582771, 196092308,   -857928427,
                             -608346822,  1257147028, 2126582638,  -1984378241,
                             1695858147,  1559026476, -187207916,  -1587314937,
                             16546724,    1431634982};
  const int32_t i32_ans[] = {-1011514960, -608940596, 0, 0, 0, 0, 0, 0};
  const uint32_t u32_src[] = {
      3481342707, 2536570961, 1781685356, 150767366,  3057678400, 3124803055,
      725284010,  3973538069, 193683095,  1244331673, 3476878762, 564179168,
      3619386066, 4188860653, 2076889243, 3481289610, 2797821875, 398934166};
  const uint32_t u32_ans[] = {3481342707, 2536570961, 0, 0, 0, 0, 0, 0};
  const fp32_t fp32_src[] = {
      -85.50063, -27.643047, 75.64646,  57.768234, -0.47777668, -97.49874,
      -28.6624,  -51.437984, -90.26317, 85.97493,  -55.18999,   -4.563402,
      37.233936, 0.38199654, 66.17687,  5.8068004, -99.614044,  -59.338123};
  const fp32_t fp32_ans[] = {-85.50063, -27.643047};
  int cin = 2;
  int hin = 3;
  int win = 3;
  int stride = 3;
  int kernel = 2;
  int padding = 1;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileki(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 1 << 16 | 0);
  msetpadval(0);
  mint32m1_t tr0 = mlufae32_m(i32_src, 2 * sizeof(int32_t));
  msae32_m(tr0, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 8, " MLUFAE INT32 ");
  // msfdae32_m(tr0, i32_buffer, 2 * sizeof(int32_t));
  // EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 8, " MSFDAE INT32 ");
  muint32m1_t tr1 = mlufae32_m(u32_src, 2 * sizeof(uint32_t));
  msae32_m(tr1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 8, " MLUFAE UINT32");
  // msfdae32_m(tr1, u32_buffer, 2 * sizeof(uint32_t));
  // EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 8, " MSFDAE UINT32");
  mfloat32m1_t tr2 = mlufae32_m(fp32_src, 2 * sizeof(fp32_t));
  msae32_m(tr2, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(u32_ans, u32_buffer, 8, " MLUFAE FP32  ");
  // msfdae32_m(tr2, fp32_buffer, 2 * sizeof(fp32_t));
  // EXCEPT_U32_ARRAY_EQ(fp32_src, fp32_buffer, 8, " MSFDAE FP32  ");
}

static void test_mlufbe32_m() {
  const int32_t i32_src[] = {-1011514960, -608940596, -1955188614, 1215601751,
                             1758987289,  1018582771, 196092308,   -857928427,
                             -608346822,  1257147028, 2126582638,  -1984378241,
                             1695858147,  1559026476, -187207916,  -1587314937,
                             16546724,    1431634982};
  const int32_t i32_ans[] = {-1011514960, -608940596, 0, 0, 0, 0, 0, 0};
  const uint32_t u32_src[] = {
      3481342707, 2536570961, 1781685356, 150767366,  3057678400, 3124803055,
      725284010,  3973538069, 193683095,  1244331673, 3476878762, 564179168,
      3619386066, 4188860653, 2076889243, 3481289610, 2797821875, 398934166};
  const uint32_t u32_ans[] = {3481342707, 2536570961, 0, 0, 0, 0, 0, 0};
  const fp32_t fp32_src[] = {
      -85.50063, -27.643047, 75.64646,  57.768234, -0.47777668, -97.49874,
      -28.6624,  -51.437984, -90.26317, 85.97493,  -55.18999,   -4.563402,
      37.233936, 0.38199654, 66.17687,  5.8068004, -99.614044,  -59.338123};
  const fp32_t fp32_ans[] = {-85.50063, -27.643047};
  int cin = 2;
  int hin = 3;
  int win = 3;
  int stride = 3;
  int kernel = 2;
  int padding = 1;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  msettype(E32, M1, BA);
  msettileki(4);
  msettileni(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 1 << 16 | 0);
  msetpadval(0);
  mint32m1_t tr0 = mlufbe32_m(i32_src, 2 * sizeof(int32_t));
  msbe32_m(tr0, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 8, " MLUFBE INT32 ");
  muint32m1_t tr1 = mlufbe32_m(u32_src, 2 * sizeof(uint32_t));
  msbe32_m(tr1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 8, " MLUFBE UINT32");
  mfloat32m1_t tr2 = mlufbe32_m(fp32_src, 2 * sizeof(fp32_t));
  msbe32_m(tr2, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(u32_ans, u32_buffer, 8, " MLUFBE FP32  ");
}

static void test_mlufce32_m() {
  const int32_t i32_src[] = {-1011514960, -608940596, -1955188614, 1215601751,
                             1758987289,  1018582771, 196092308,   -857928427,
                             -608346822,  1257147028, 2126582638,  -1984378241,
                             1695858147,  1559026476, -187207916,  -1587314937,
                             16546724,    1431634982};
  const int32_t i32_ans[] = {-1011514960, -608940596, 0, 0, 0, 0, 0, 0};
  const uint32_t u32_src[] = {
      3481342707, 2536570961, 1781685356, 150767366,  3057678400, 3124803055,
      725284010,  3973538069, 193683095,  1244331673, 3476878762, 564179168,
      3619386066, 4188860653, 2076889243, 3481289610, 2797821875, 398934166};
  const uint32_t u32_ans[] = {3481342707, 2536570961, 0, 0, 0, 0, 0, 0};
  const fp32_t fp32_src[] = {
      -85.50063, -27.643047, 75.64646,  57.768234, -0.47777668, -97.49874,
      -28.6624,  -51.437984, -90.26317, 85.97493,  -55.18999,   -4.563402,
      37.233936, 0.38199654, 66.17687,  5.8068004, -99.614044,  -59.338123};
  const fp32_t fp32_ans[] = {-85.50063, -27.643047};
  int cin = 2;
  int hin = 3;
  int win = 3;
  int stride = 3;
  int kernel = 2;
  int padding = 1;
  int dilation = 1;
  int hout = (hin + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  int wout = (win + 2 * padding - dilation * (kernel - 1) - 1) / stride + 1;
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileni(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 1 << 16 | 0);
  msetpadval(0);
  mint32m1_t tr0 = mlufce32_m(i32_src, 2 * sizeof(int32_t));
  msce32_m(tr0, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 8, " MLUFCE INT32 ");
  muint32m1_t tr1 = mlufce32_m(u32_src, 2 * sizeof(uint32_t));
  msce32_m(tr1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 8, " MLUFCE UINT32");
  mfloat32m1_t tr2 = mlufce32_m(fp32_src, 2 * sizeof(fp32_t));
  msce32_m(tr2, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(u32_ans, u32_buffer, 8, " MLUFCE FP32  ");
}

static void test_mlufae64_m() {
  const int64_t i64_src[] = {
      1810234924286097575,  5777438739432264746, 5366783726337619945,
      6378777233346605247,  1810318069902139821, 8796885364473194518,
      -5642293984507834832, 5104280633708681801, -4800751275659895455,
      9179309469019791062,  7470436746611390747, -1456032160410975872};
  const int64_t i64_ans[] = {1810234924286097575,  5777438739432264746,
                             6378777233346605247,  1810318069902139821,
                             -5642293984507834832, 5104280633708681801,
                             9179309469019791062,  7470436746611390747};
  const uint64_t u64_src[] = {
      2728367756266265540, 950291898973406416,  414874977102652455,
      1984218656456326638, 4523515723708795106, 1507960239061584921,
      2408390952439860267, 3833623027303404799, 1667166434859123669,
      2133360978494444756, 3653368420845691346, 547479940520203382};
  const uint64_t u64_ans[] = {
      2728367756266265540, 950291898973406416,  1984218656456326638,
      4523515723708795106, 2408390952439860267, 3833623027303404799,
      2133360978494444756, 3653368420845691346,
  };
  const fp64_t fp64_src[] = {-46.25069359, 14.34329742,  87.41173497,
                             -59.91195849, 62.84882827,  64.50529488,
                             -22.18173162, -15.60072566, -73.46470126,
                             47.64390773,  17.41286384,  -60.03675914};
  const fp64_t fp64_ans[] = {-46.25069359, 14.34329742,  -59.91195849,
                             62.84882827,  -22.18173162, -15.60072566,
                             47.64390773,  17.41286384};
  int cin = 3;
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
  msettileki(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64m1_t tr0 = mlufae64_m(i64_src, 3 * sizeof(int64_t));
  msae64_m(tr0, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 8, " MLUFAE INT64 ");
  muint64m1_t tr1 = mlufae64_m(u64_src, 3 * sizeof(uint64_t));
  msae64_m(tr1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 8, " MLUFAE UINT64");
  mfloat64m1_t tr2 = mlufae64_m(fp64_src, 3 * sizeof(fp64_t));
  msae64_m(tr2, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 8, " MLUFAE FP64  ");
}

static void test_mlufbe64_m() {
  const int64_t i64_src[] = {
      1810234924286097575,  5777438739432264746, 5366783726337619945,
      6378777233346605247,  1810318069902139821, 8796885364473194518,
      -5642293984507834832, 5104280633708681801, -4800751275659895455,
      9179309469019791062,  7470436746611390747, -1456032160410975872};
  const int64_t i64_ans[] = {1810234924286097575,  5777438739432264746,
                             6378777233346605247,  1810318069902139821,
                             -5642293984507834832, 5104280633708681801,
                             9179309469019791062,  7470436746611390747};
  const uint64_t u64_src[] = {
      2728367756266265540, 950291898973406416,  414874977102652455,
      1984218656456326638, 4523515723708795106, 1507960239061584921,
      2408390952439860267, 3833623027303404799, 1667166434859123669,
      2133360978494444756, 3653368420845691346, 547479940520203382};
  const uint64_t u64_ans[] = {
      2728367756266265540, 950291898973406416,  1984218656456326638,
      4523515723708795106, 2408390952439860267, 3833623027303404799,
      2133360978494444756, 3653368420845691346,
  };
  const fp64_t fp64_src[] = {-46.25069359, 14.34329742,  87.41173497,
                             -59.91195849, 62.84882827,  64.50529488,
                             -22.18173162, -15.60072566, -73.46470126,
                             47.64390773,  17.41286384,  -60.03675914};
  const fp64_t fp64_ans[] = {-46.25069359, 14.34329742,  -59.91195849,
                             62.84882827,  -22.18173162, -15.60072566,
                             47.64390773,  17.41286384};
  int cin = 3;
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
  msettileni(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64m1_t tr0 = mlufbe64_m(i64_src, 3 * sizeof(int64_t));
  msbe64_m(tr0, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 8, " MLUFBE INT64 ");
  muint64m1_t tr1 = mlufbe64_m(u64_src, 3 * sizeof(uint64_t));
  msbe64_m(tr1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 8, " MLUFBE UINT64");
  mfloat64m1_t tr2 = mlufbe64_m(fp64_src, 3 * sizeof(fp64_t));
  msbe64_m(tr2, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 8, " MLUFBE FP64  ");
}

static void test_mlufce64_m() {
  const int64_t i64_src[] = {
      1810234924286097575,  5777438739432264746, 5366783726337619945,
      6378777233346605247,  1810318069902139821, 8796885364473194518,
      -5642293984507834832, 5104280633708681801, -4800751275659895455,
      9179309469019791062,  7470436746611390747, -1456032160410975872};
  const int64_t i64_ans[] = {1810234924286097575,  5777438739432264746,
                             6378777233346605247,  1810318069902139821,
                             -5642293984507834832, 5104280633708681801,
                             9179309469019791062,  7470436746611390747};
  const uint64_t u64_src[] = {
      2728367756266265540, 950291898973406416,  414874977102652455,
      1984218656456326638, 4523515723708795106, 1507960239061584921,
      2408390952439860267, 3833623027303404799, 1667166434859123669,
      2133360978494444756, 3653368420845691346, 547479940520203382};
  const uint64_t u64_ans[] = {
      2728367756266265540, 950291898973406416,  1984218656456326638,
      4523515723708795106, 2408390952439860267, 3833623027303404799,
      2133360978494444756, 3653368420845691346,
  };
  const fp64_t fp64_src[] = {-46.25069359, 14.34329742,  87.41173497,
                             -59.91195849, 62.84882827,  64.50529488,
                             -22.18173162, -15.60072566, -73.46470126,
                             47.64390773,  17.41286384,  -60.03675914};
  const fp64_t fp64_ans[] = {-46.25069359, 14.34329742,  -59.91195849,
                             62.84882827,  -22.18173162, -15.60072566,
                             47.64390773,  17.41286384};
  int cin = 3;
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
  msettileni(2);
  msetoutsh(hout << 16 | wout,
            dilation << 24 | dilation << 16 | stride << 8 | stride);
  msetinsh(hin << 16 | win,
           padding << 24 | padding << 16 | padding << 8 | padding);
  msetsk(0 << 16 | 0 & 0xffff, 0 << 16 | 0);
  msetpadval(0);
  mint64m1_t tr0 = mlufce64_m(i64_src, 3 * sizeof(int64_t));
  msce64_m(tr0, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 8, " MLUFCE INT64 ");
  muint64m1_t tr1 = mlufce64_m(u64_src, 3 * sizeof(uint64_t));
  msce64_m(tr1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 8, " MLUFCE UINT64");
  mfloat64m1_t tr2 = mlufce64_m(fp64_src, 3 * sizeof(fp64_t));
  msce64_m(tr2, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 8, " MLUFCE FP64  ");
}

int main() {
  // test_mlufae8_and_msfdae8();
  // test_mlufbe8_and_msfdbe8();
  // test_mlufce8_and_msfdce8();
  // test_mlufae16_and_msfdae16();
  // test_mlufbe16_and_msfdbe16();
  // test_mlufce16_and_msfdce16();
  // test_mlufae32_and_msfdae32();
  // test_mlufae32_m();
  // test_mlufbe32_m();
  // test_mlufce32_m();
  // test_mlufae64_m();
  // test_mlufbe64_m();
  // test_mlufce64_m();
  return 0;
}