#include "utils.h"
#include <riscv_matrix.h>
#include <riscv_vector.h>

const int8_t i8_src[] = {72, 28, -48, 105, 2, -30, 43, 42, 116, 45, -44, -117};
const int8_t i8_tp[] = {72, 2, 116, 28, -30, 45, -48, 43, -44, 105, 42, -117};
const uint8_t u8_src[] = {170, 211, 235, 231, 230, 223,
                          133, 75,  210, 137, 70,  154};
const uint8_t u8_tp[] = {170, 230, 210, 211, 223, 137,
                         235, 133, 70,  231, 75,  154};
const int16_t i16_src[] = {13015,  -27251, -10031, 12491,  11271,  -27702,
                           18785,  23398,  -30365, -21015, 10409,  -18130,
                           -21735, -25313, 32630,  32189,  -24303, 19851,
                           -10230, 23594,  -28635, 18965,  24947,  -24004};
const int16_t i16_tp[] = {13015,  -30365, -24303, -27251, -21015, 19851,
                          -10031, 10409,  -10230, 12491,  -18130, 23594,
                          11271,  -21735, -28635, -27702, -25313, 18965,
                          18785,  32630,  24947,  23398,  32189,  -24004};
const uint16_t u16_src[] = {55640, 538,   40304, 40031, 62241, 5940,
                            2313,  57672, 49207, 52291, 30563, 3181,
                            33377, 41231, 65108, 31040, 9412,  37945,
                            19976, 46482, 47842, 62756, 20942, 834};
const uint16_t u16_tp[] = {55640, 49207, 9412,  538,   52291, 37945,
                           40304, 30563, 19976, 40031, 3181,  46482,
                           62241, 33377, 47842, 5940,  41231, 62756,
                           2313,  65108, 20942, 57672, 31040, 834};
const fp16_t fp16_src[] = {1.759, 0.6367, 6.094, -6.176,  7.23,    -7.54,
                           -9.45, 0.4045, -8.43, -0.788,  0.5728,  -3.564,
                           -9.28, 2.854,  -8.1,  -0.1815, 2.172,   8.516,
                           -5.71, -8.12,  0.56,  3.645,   -0.9565, 7.54};
const fp16_t fp16_tp[] = {1.759, -8.43,  2.172,   0.6367, -0.788,  8.516,
                          6.094, 0.5728, -5.71,   -6.176, -3.564,  -8.12,
                          7.23,  -9.28,  0.56,    -7.54,  2.854,   3.645,
                          -9.45, -8.1,   -0.9565, 0.4045, -0.1815, 7.54};
const int32_t i32_src[] = {-1732549712, 1413194808, -1102230118, 873874877};
const int32_t i32_tp[] = {-1732549712, -1102230118, 1413194808, 873874877};
const uint32_t u32_src[] = {1335702441, 4272652708, 568611071, 4171997907};
const uint32_t u32_tp[] = {1335702441, 568611071, 4272652708, 4171997907};
const fp32_t fp32_src[] = {9.9882805e+37, -3.5149981e+37, -6.3455582e+37,
                           3.1793206e+38};
const fp32_t fp32_tp[] = {9.9882805e+37, -6.3455582e+37, -3.5149981e+37,
                          3.1793206e+38};
const int64_t i64_src[] = {-8417271268987442642, -1879025287220832052,
                           -1183382539417299212, 1758814168129350781};
const int64_t i64_tp[] = {-8417271268987442642, -1183382539417299212,
                          -1879025287220832052, 1758814168129350781};
const uint64_t u64_src[] = {7856990993946654551, 8470409526266691293,
                            7915616516307113191, 6276829843910054413};
const uint64_t u64_tp[] = {7856990993946654551, 7915616516307113191,
                           8470409526266691293, 6276829843910054413};
const fp64_t fp64_src[] = {-3.15249280e+38, 2.01157722e+38, 8.26035674e+37,
                           -1.69735933e+38};
const fp64_t fp64_tp[] = {-3.15249280e+38, 8.26035674e+37, 2.01157722e+38,
                          -1.69735933e+38};
// M2
const int8_t i8_src_m2[] = {
    -82,  -49, 106,  80,  -82, -25,  -32,  -31, -98,  -105, 34,   70,   -47,
    44,   12,  -10,  85,  -83, -93,  -105, 108, 73,   94,   -95,  -64,  27,
    37,   -5,  -127, 65,  117, 117,  -45,  6,   10,   -111, 78,   -122, 42,
    44,   1,   -14,  -39, 11,  65,   31,   16,  -17,  -61,  -37,  63,   -10,
    -108, 38,  20,   -9,  87,  -108, 80,   -51, -118, -99,  -104, -51};
const uint8_t u8_src_m2[] = {
    93,  113, 61,  100, 56,  232, 101, 61,  82,  88,  142, 28,  229,
    205, 4,   144, 23,  121, 247, 17,  83,  113, 29,  2,   211, 45,
    66,  98,  143, 47,  91,  39,  253, 172, 28,  218, 142, 7,   8,
    20,  78,  153, 143, 30,  149, 177, 63,  253, 240, 241, 45,  18,
    174, 95,  176, 196, 88,  16,  16,  152, 26,  177, 236, 177};
// M4
const int8_t i8_src_m4[] = {
    -79,  49,  90,  -16,  27,   -117, -75,  60,   1,    73,   69,   -76,  -101,
    32,   31,  90,  7,    -120, 30,   -127, 89,   -82,  -115, 83,   -47,  49,
    -55,  -78, -58, 79,   31,   -38,  -76,  -108, 47,   -23,  7,    36,   64,
    9,    -74, 81,  -44,  -16,  91,   -71,  58,   -110, 44,   67,   -109, 51,
    56,   -69, 67,  -72,  43,   -81,  12,   -21,  110,  -10,  -31,  76,   14,
    -22,  -28, -82, 64,   100,  -118, 65,   64,   -127, 126,  63,   122,  -107,
    62,   -82, 92,  -18,  -63,  -123, -98,  -67,  120,  111,  -110, 73,   95,
    105,  108, -16, -100, 51,   -38,  -78,  -120, 13,   73,   -110, -21,  -12,
    -108, 5,   -84, -73,  17,   17,   -84,  -100, -95,  -54,  96,   22,   -125,
    122,  -54, -68, 75,   22,   21,   -106, -2,   -117, -91,  96};
const uint8_t u8_src_m4[] = {
    209, 219, 43,  157, 160, 38,  120, 251, 207, 44,  251, 95,  174, 52,  78,
    20,  89,  21,  61,  180, 150, 224, 251, 58,  46,  97,  127, 15,  53,  233,
    143, 5,   143, 155, 165, 25,  148, 130, 243, 210, 242, 1,   229, 148, 211,
    240, 95,  80,  43,  73,  227, 84,  167, 0,   150, 95,  249, 214, 64,  219,
    161, 0,   188, 236, 181, 2,   167, 207, 108, 4,   41,  195, 84,  153, 2,
    197, 126, 123, 128, 96,  67,  205, 120, 111, 211, 139, 239, 44,  134, 209,
    97,  177, 2,   164, 102, 215, 7,   72,  140, 69,  83,  4,   189, 150, 67,
    69,  64,  191, 4,   40,  94,  232, 224, 215, 210, 187, 0,   120, 243, 46,
    121, 158, 202, 195, 136, 93,  194, 62};

static void test_mlae8v_and_msae8v() {
  // M1
  msettype(E8, M1, BA);
  // int8_t
  msettilemi(3);
  msettileki(4);
  vint8m1_t i8_v1 = mlae8_v(i8_src, 4 * sizeof(int8_t));
  msae8_v(i8_v1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MLAE8.V & MSAE8.V INT8   M1");
  // uint8_t
  msettilemi(3);
  msettileki(4);
  vuint8m1_t u8_v1 = mlae8_v(u8_src, 4 * sizeof(uint8_t));
  msae8_v(u8_v1, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MLAE8.V & MSAE8.V UINT8  M1");
}

static void test_mlbe8v_and_msbe8v() {
  msettype(E8, M1, BA);
  // int8_t
  msettileki(3);
  msettileni(4);
  vint8m1_t i8_v1 = mlbe8_v(i8_src, 4 * sizeof(int8_t));
  msbe8_v(i8_v1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MLBE8.V & MSBE8.V INT8  ");
  // uint8_t
  msettileki(3);
  msettileni(4);
  vuint8m1_t u8_v1 = mlbe8_v(u8_src, 4 * sizeof(uint8_t));
  msbe8_v(u8_v1, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MLBE8.V & MSBE8.V UINT8 ");
}

static void test_mlce8v_and_msce8v() {
  msettype(E8, M1, BA);
  // int8_t
  msettilemi(3);
  msettileni(4);
  vint8m1_t i8_v1 = mlce8_v(i8_src, 4 * sizeof(int8_t));
  msce8_v(i8_v1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MLCE8.V & MSCE8.V INT8  ");
  // uint8_t
  msettilemi(3);
  msettileni(4);
  vuint8m1_t u8_v1 = mlce8_v(u8_src, 4 * sizeof(uint8_t));
  msce8_v(u8_v1, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MLCE8.V & MSCE8.V UINT8 ");
}

static void test_mlae16v_and_msae16v() {
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  // int16_t
  vint16m1_t i16_v1 = mlae16_v(i16_src, 8 * sizeof(int16_t));
  msae16_v(i16_v1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MLAE16.V & MSAE16.V INT16 ");
  // uint16_t
  vuint16m1_t u16_v1 = mlae16_v(u16_src, 8 * sizeof(uint16_t));
  msae16_v(u16_v1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MLAE16.V & MSAE16.V UINT16");
  // fp16_t
  vfloat16m1_t fp16_v1 = mlae16_v(fp16_src, 8 * sizeof(fp16_t));
  msae16_v(fp16_v1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MLAE16.V & MSAE16.V FP16  ");
}

static void test_mlbe16v_and_msbe16v() {
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  // int16_t
  vint16m1_t i16_v1 = mlbe16_v(i16_src, 8 * sizeof(int16_t));
  msbe16_v(i16_v1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MLBE16.V & MSBE16.V INT16 ");
  // uint16_t
  vuint16m1_t u16_v1 = mlbe16_v(u16_src, 8 * sizeof(uint16_t));
  msbe16_v(u16_v1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MLBE16.V & MSBE16.V UINT16");
  // fp16_t
  vfloat16m1_t fp16_v1 = mlbe16_v(fp16_src, 8 * sizeof(fp16_t));
  msbe16_v(fp16_v1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MLBE16.V & MSBE16.V FP16  ");
}

static void test_mlce16v_and_msce16v() {
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  // int16_t
  vint16m1_t i16_v1 = mlce16_v(i16_src, 8 * sizeof(int16_t));
  msce16_v(i16_v1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MLCE16.V & MSCE16.V INT16 ");
  // uint16_t
  vuint16m1_t u16_v1 = mlce16_v(u16_src, 8 * sizeof(uint16_t));
  msce16_v(u16_v1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MLCE16.V & MSCE16.V UINT16");
  // fp16_t
  vfloat16m1_t fp16_v1 = mlce16_v(fp16_src, 8 * sizeof(fp16_t));
  msce16_v(fp16_v1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MLCE16.V & MSCE16.V FP16  ");
}

static void test_mlae32v_and_msae32v() {
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  // int32_t
  vint32m1_t i32_v1 = mlae32_v(i32_src, 2 * sizeof(int32_t));
  msae32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MLAE32.V & MSAE32.V INT32 ");
  // uint32_t
  vuint32m1_t u32_v1 = mlae32_v(u32_src, 2 * sizeof(uint32_t));
  msae32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MLAE32.V & MSAE32.V UINT32");
  // fp32_t
  vfloat32m1_t fp32_v1 = mlae32_v(fp32_src, 2 * sizeof(fp32_t));
  msae32_v(fp32_v1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MLAE32.V & MSAE32.V FP32  ");
}

static void test_mlbe32v_and_msbe32v() {
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  // int32_t
  vint32m1_t i32_v1 = mlbe32_v(i32_src, 2 * sizeof(int32_t));
  msbe32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MLAE32.V & MSAE32.V INT32 ");
  // uint32_t
  vuint32m1_t u32_v1 = mlbe32_v(u32_src, 2 * sizeof(uint32_t));
  msbe32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MLAE32.V & MSAE32.V UINT32");
  // fp32_t
  vfloat32m1_t fp32_v1 = mlbe32_v(fp32_src, 2 * sizeof(fp32_t));
  msbe32_v(fp32_v1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MLAE32.V & MSAE32.V FP32  ");
}

static void test_mlce32v_and_msce32v() {
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  // int32_t
  vint32m1_t i32_v1 = mlce32_v(i32_src, 2 * sizeof(int32_t));
  msce32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MLAE32.V & MSAE32.V INT32 ");
  // uint32_t
  vuint32m1_t u32_v1 = mlce32_v(u32_src, 2 * sizeof(uint32_t));
  msce32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MLAE32.V & MSAE32.V UINT32");
  // fp32_t
  vfloat32m1_t fp32_v1 = mlce32_v(fp32_src, 2 * sizeof(fp32_t));
  msce32_v(fp32_v1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MLAE32.V & MSAE32.V FP32  ");
}

static void test_mlae64v_and_msae64v() {
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  // int64_t
  vint64m1_t i64_v1 = mlae64_v(i64_src, 2 * sizeof(int64_t));
  msae64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MLAE64.V & MSAE64.V INT64 ");
  // uint64_t
  vuint64m1_t u64_v1 = mlae64_v(u64_src, 2 * sizeof(uint64_t));
  msae64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MLAE64.V & MSAE64.V UINT64");
  // fp64_t
  vfloat64m1_t fp64_v1 = mlae64_v(fp64_src, 2 * sizeof(fp64_t));
  msae64_v(fp64_v1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MLAE64.V & MSAE64.V FP64  ");
}

static void test_mlbe64v_and_msbe64v() {
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  // int64_t
  vint64m1_t i64_v1 = mlbe64_v(i64_src, 2 * sizeof(int64_t));
  msbe64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MLBE64.V & MSBE64.V INT64 ");
  // uint64_t
  vuint64m1_t u64_v1 = mlbe64_v(u64_src, 2 * sizeof(uint64_t));
  msbe64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MLBE64.V & MSBE64.V UINT64");
  // fp64_t
  vfloat64m1_t fp64_v1 = mlbe64_v(fp64_src, 2 * sizeof(fp64_t));
  msbe64_v(fp64_v1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MLAE64.V & MSAE64.V FP64  ");
}

static void test_mlce64v_and_msce64v() {
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  // int64_t
  vint64m1_t i64_v1 = mlce64_v(i64_src, 2 * sizeof(int64_t));
  msce64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MLCE64.V & MSCE64.V INT64 ");
  // uint64_t
  vuint64m1_t u64_v1 = mlce64_v(u64_src, 2 * sizeof(uint64_t));
  msce64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MLCE64.V & MSCE64.V UINT64");
  // fp64_t
  vfloat64m1_t fp64_v1 = mlce64_v(fp64_src, 2 * sizeof(fp64_t));
  msce64_v(fp64_v1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MLCE64.V & MSCE64.V FP64  ");
}

static void test_mmvar_v_m() {
  // M1
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(4);
  vsetvl_e8m1(12);
  mint8m1_t i8_m1 = mlae8_m1(i8_src, 4 * sizeof(int8_t));
  vint8m1_t i8_v1 = mmvar_v_m(i8_m1, 0);
  msae8_v(i8_v1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVAR.V.M INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(4);
  vsetvl_e8m1(12);
  muint8m1_t u8_m1 = mlae8_m1(u8_src, 4 * sizeof(int8_t));
  vuint8m1_t u8_v1 = mmvar_v_m(u8_m1, 0);
  msae8_v(u8_v1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVAR.V.M UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m8(24);
  mint16m1_t i16_m1 = mlae16_m1(i16_src, 8 * sizeof(int16_t));
  vint16m1_t i16_v1 = mmvar_v_m(i16_m1, 0);
  msae16_v(i16_v1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVAR.V.M INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m8(24);
  muint16m1_t u16_m1 = mlae16_m1(u16_src, 8 * sizeof(uint16_t));
  vuint16m1_t u16_v1 = mmvar_v_m(u16_m1, 0);
  msae16_v(u16_v1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVAR.V.M UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m8(24);
  mfloat16m1_t fp16_m1 = mlae16_m1(fp16_src, 8 * sizeof(fp16_t));
  vfloat16m1_t fp16_v1 = mmvar_v_m(fp16_m1, 0);
  msae16_v(fp16_v1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVAR.V.M FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m1(4);
  mint32m1_t i32_m1 = mlae32_m1(i32_src, 2 * sizeof(int32_t));
  vint32m1_t i32_v1 = mmvar_v_m(i32_m1, 0);
  msae32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVAR.V.M INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m1(4);
  muint32m1_t u32_m1 = mlae32_m1(u32_src, 2 * sizeof(uint32_t));
  vuint32m1_t u32_v1 = mmvar_v_m(u32_m1, 0);
  msae32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVAR.V.M UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m1(4);
  mfloat32m1_t fp32_m1 = mlae32_m1(fp32_src, 2 * sizeof(uint32_t));
  vfloat32m1_t fp32_v1 = mmvar_v_m(fp32_m1, 0);
  msae32_v(fp32_v1, fp32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVAR.V.M FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  mint64m1_t i64_m1 = mlae64_m1(i64_src, 2 * sizeof(int64_t));
  vint64m1_t i64_v1 = mmvar_v_m(i64_m1, 0);
  msae64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVAR.V.M INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  muint64m1_t u64_m1 = mlae64_m1(u64_src, 2 * sizeof(uint64_t));
  vuint64m1_t u64_v1 = mmvar_v_m(u64_m1, 0);
  msae64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVAR.V.M UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  mfloat64m1_t fp64_m1 = mlae64_m1(fp64_src, 2 * sizeof(uint64_t));
  vfloat64m1_t fp64_v1 = mmvar_v_m(fp64_m1, 0);
  msae64_v(fp64_v1, fp64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVAR.V.M FP64  ");
}

static void test_mmvbr_v_m() {
  // int8
  msettype(E8, M1, BA);
  msettileki(3);
  msettileni(4);
  vsetvl_e8m1(12);
  mint8m1_t i8_m1 = mlbe8_m1(i8_src, 4 * sizeof(int8_t));
  vint8m1_t i8_v1 = mmvbr_v_m(i8_m1, 0);
  msbe8_v(i8_v1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVBR.V.M INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettileki(3);
  msettileni(4);
  vsetvl_e8m1(12);
  muint8m1_t u8_m1 = mlbe8_m1(u8_src, 4 * sizeof(int8_t));
  vuint8m1_t u8_v1 = mmvbr_v_m(u8_m1, 0);
  msbe8_v(u8_v1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVBR.V.M UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m8(24);
  mint16m1_t i16_m1 = mlbe16_m1(i16_src, 8 * sizeof(int16_t));
  vint16m1_t i16_v1 = mmvbr_v_m(i16_m1, 0);
  msbe16_v(i16_v1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVBR.V.M INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m8(24);
  muint16m1_t u16_m1 = mlbe16_m1(u16_src, 8 * sizeof(uint16_t));
  vuint16m1_t u16_v1 = mmvbr_v_m(u16_m1, 0);
  msbe16_v(u16_v1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVBR.V.M UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m8(24);
  mfloat16m1_t fp16_m1 = mlbe16_m1(fp16_src, 8 * sizeof(fp16_t));
  vfloat16m1_t fp16_v1 = mmvbr_v_m(fp16_m1, 0);
  msbe16_v(fp16_v1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVBR.V.M FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m1(4);
  mint32m1_t i32_m1 = mlbe32_m1(i32_src, 2 * sizeof(int32_t));
  vint32m1_t i32_v1 = mmvbr_v_m(i32_m1, 0);
  msbe32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVBR.V.M INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m1(4);
  muint32m1_t u32_m1 = mlbe32_m1(u32_src, 2 * sizeof(uint32_t));
  vuint32m1_t u32_v1 = mmvbr_v_m(u32_m1, 0);
  msbe32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVBR.V.M UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m1(4);
  mfloat32m1_t fp32_m1 = mlbe32_m1(fp32_src, 2 * sizeof(uint32_t));
  vfloat32m1_t fp32_v1 = mmvbr_v_m(fp32_m1, 0);
  msbe32_v(fp32_v1, fp32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVBR.V.M FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  mint64m1_t i64_m1 = mlbe64_m1(i64_src, 2 * sizeof(int64_t));
  vint64m1_t i64_v1 = mmvbr_v_m(i64_m1, 0);
  msbe64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVBR.V.M INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  muint64m1_t u64_m1 = mlbe64_m1(u64_src, 2 * sizeof(uint64_t));
  vuint64m1_t u64_v1 = mmvbr_v_m(u64_m1, 0);
  msbe64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVBR.V.M UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  mfloat64m1_t fp64_m1 = mlbe64_m1(fp64_src, 2 * sizeof(uint64_t));
  vfloat64m1_t fp64_v1 = mmvbr_v_m(fp64_m1, 0);
  msbe64_v(fp64_v1, fp64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVBR.V.M FP64  ");
}

static void test_mmvcr_v_m() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileni(4);
  vsetvl_e8m1(12);
  mint8m1_t i8_m1 = mlce8_m1(i8_src, 4 * sizeof(int8_t));
  vint8m1_t i8_v1 = mmvcr_v_m(i8_m1, 0);
  msce8_v(i8_v1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVCR.V.M INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileni(4);
  vsetvl_e8m1(12);
  muint8m1_t u8_m1 = mlce8_m1(u8_src, 4 * sizeof(int8_t));
  vuint8m1_t u8_v1 = mmvcr_v_m(u8_m1, 0);
  msce8_v(u8_v1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVCR.V.M UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m8(24);
  mint16m1_t i16_m1 = mlce16_m1(i16_src, 8 * sizeof(int16_t));
  vint16m1_t i16_v1 = mmvcr_v_m(i16_m1, 0);
  msce16_v(i16_v1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVCR.V.M INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m8(24);
  muint16m1_t u16_m1 = mlce16_m1(u16_src, 8 * sizeof(uint16_t));
  vuint16m1_t u16_v1 = mmvcr_v_m(u16_m1, 0);
  msce16_v(u16_v1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVCR.V.M UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m8(24);
  mfloat16m1_t fp16_m1 = mlce16_m1(fp16_src, 8 * sizeof(fp16_t));
  vfloat16m1_t fp16_v1 = mmvcr_v_m(fp16_m1, 0);
  msce16_v(fp16_v1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVCR.V.M FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m1(4);
  mint32m1_t i32_m1 = mlce32_m1(i32_src, 2 * sizeof(int32_t));
  vint32m1_t i32_v1 = mmvcr_v_m(i32_m1, 0);
  msce32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVCR.V.M INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m1(4);
  muint32m1_t u32_m1 = mlce32_m1(u32_src, 2 * sizeof(uint32_t));
  vuint32m1_t u32_v1 = mmvcr_v_m(u32_m1, 0);
  msce32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVCR.V.M UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m1(4);
  mfloat32m1_t fp32_m1 = mlce32_m1(fp32_src, 2 * sizeof(uint32_t));
  vfloat32m1_t fp32_v1 = mmvcr_v_m(fp32_m1, 0);
  msce32_v(fp32_v1, fp32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVCR.V.M FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  mint64m1_t i64_m1 = mlce64_m1(i64_src, 2 * sizeof(int64_t));
  vint64m1_t i64_v1 = mmvcr_v_m(i64_m1, 0);
  msce64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVCR.V.M INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  muint64m1_t u64_m1 = mlce64_m1(u64_src, 2 * sizeof(uint64_t));
  vuint64m1_t u64_v1 = mmvcr_v_m(u64_m1, 0);
  msce64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVCR.V.M UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  mfloat64m1_t fp64_m1 = mlce64_m1(fp64_src, 2 * sizeof(uint64_t));
  vfloat64m1_t fp64_v1 = mmvcr_v_m(fp64_m1, 0);
  msce64_v(fp64_v1, fp64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVCR.V.M FP64  ");
}

static void test_mmvar_m_v() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(4);
  vsetvl_e8m1(12);
  vint8m1_t i8_v1 = mlae8_v(i8_src, 4 * sizeof(int8_t));
  mint8m1_t i8_m1 = mmvar_m_v(i8_v1, 0);
  msae8_m(i8_m1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVAR.M.V INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(4);
  vsetvl_e8m1(12);
  vuint8m1_t u8_v1 = mlae8_v(u8_src, 4 * sizeof(int8_t));
  muint8m1_t u8_m1 = mmvar_m_v(u8_v1, 0);
  msae8_m(u8_m1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MMVAR.M.V UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m2(24);
  vint16m1_t i16_v1 = mlae16_v(i16_src, 8 * sizeof(int16_t));
  mint16m1_t i16_m1 = mmvar_m_v(i16_v1, 0);
  msae16_m(i16_m1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVAR.M.V INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m2(24);
  vuint16m1_t u16_v1 = mlae16_v(u16_src, 8 * sizeof(uint16_t));
  muint16m1_t u16_m1 = mmvar_m_v(u16_v1, 0);
  msae16_m(u16_m1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVAR.M.V UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m2(24);
  vfloat16m1_t fp16_v1 = mlae16_v(fp16_src, 8 * sizeof(fp16_t));
  mfloat16m1_t fp16_m1 = mmvar_m_v(fp16_v1, 0);
  msae16_m(fp16_m1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVAR.M.V FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m1(4);
  vint32m1_t i32_v1 = mlae32_v(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_m1 = mmvar_m_v(i32_v1, 0);
  msae32_m(i32_m1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVAR.M.V INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m2(4);
  vuint32m1_t u32_v1 = mlae32_v(u32_src, 2 * sizeof(uint32_t));
  muint32m1_t u32_m1 = mmvar_m_v(u32_v1, 0);
  msae32_m(u32_m1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVAR.M.V UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m2(4);
  vfloat32m1_t fp32_v1 = mlae32_v(fp32_src, 2 * sizeof(fp32_t));
  mfloat32m1_t fp32_m1 = mmvar_m_v(fp32_v1, 0);
  msae32_m(fp32_m1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVAR.M.V FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  vint64m1_t i64_v1 = mlae64_v(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_m1 = mmvar_m_v(i64_v1, 0);
  msae64_m(i64_m1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVAR.M.V INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  vuint64m1_t u64_v1 = mlae64_v(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_m1 = mmvar_m_v(u64_v1, 0);
  msae64_m(u64_m1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVAR.M.V UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  vfloat64m1_t fp64_v1 = mlae64_v(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_m1 = mmvar_m_v(fp64_v1, 0);
  msae64_m(fp64_m1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVAR.M.V FP64  ");
}

static void test_mmvbr_m_v() {
  // int8
  msettype(E8, M1, BA);
  msettileki(3);
  msettileni(4);
  vsetvl_e8m1(12);
  vint8m1_t i8_v1 = mlbe8_v(i8_src, 4 * sizeof(int8_t));
  mint8m1_t i8_m1 = mmvbr_m_v(i8_v1, 0);
  msbe8_m(i8_m1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVBR.M.V INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettileki(3);
  msettileni(4);
  vsetvl_e8m1(12);
  vuint8m1_t u8_v1 = mlbe8_v(u8_src, 4 * sizeof(int8_t));
  muint8m1_t u8_m1 = mmvbr_m_v(u8_v1, 0);
  msbe8_m(u8_m1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MMVBR.M.V UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m2(24);
  vint16m1_t i16_v1 = mlbe16_v(i16_src, 8 * sizeof(int16_t));
  mint16m1_t i16_m1 = mmvbr_m_v(i16_v1, 0);
  msbe16_m(i16_m1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVBR.M.V INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m2(24);
  vuint16m1_t u16_v1 = mlbe16_v(u16_src, 8 * sizeof(uint16_t));
  muint16m1_t u16_m1 = mmvbr_m_v(u16_v1, 0);
  msbe16_m(u16_m1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVBR.M.V UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m2(24);
  vfloat16m1_t fp16_v1 = mlbe16_v(fp16_src, 8 * sizeof(fp16_t));
  mfloat16m1_t fp16_m1 = mmvbr_m_v(fp16_v1, 0);
  msbe16_m(fp16_m1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVBR.M.V FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m1(4);
  vint32m1_t i32_v1 = mlbe32_v(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_m1 = mmvbr_m_v(i32_v1, 0);
  msbe32_m(i32_m1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVBR.M.V INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m2(4);
  vuint32m1_t u32_v1 = mlbe32_v(u32_src, 2 * sizeof(uint32_t));
  muint32m1_t u32_m1 = mmvbr_m_v(u32_v1, 0);
  msbe32_m(u32_m1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVBR.M.V UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m2(4);
  vfloat32m1_t fp32_v1 = mlbe32_v(fp32_src, 2 * sizeof(fp32_t));
  mfloat32m1_t fp32_m1 = mmvbr_m_v(fp32_v1, 0);
  msbe32_m(fp32_m1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVBR.M.V FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vint64m1_t i64_v1 = mlbe64_v(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_m1 = mmvbr_m_v(i64_v1, 0);
  msbe64_m(i64_m1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVBR.M.V INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vuint64m1_t u64_v1 = mlbe64_v(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_m1 = mmvbr_m_v(u64_v1, 0);
  msbe64_m(u64_m1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVBR.M.V UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vfloat64m1_t fp64_v1 = mlbe64_v(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_m1 = mmvbr_m_v(fp64_v1, 0);
  msbe64_m(fp64_m1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVBR.M.V FP64  ");
}

static void test_mmvcr_m_v() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileni(4);
  vsetvl_e8m1(12);
  vint8m1_t i8_v1 = mlce8_v(i8_src, 4 * sizeof(int8_t));
  mint8m1_t i8_m1 = mmvcr_m_v(i8_v1, 0);
  msce8_m(i8_m1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVCR.M.V INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileni(4);
  vsetvl_e8m1(12);
  vuint8m1_t u8_v1 = mlce8_v(u8_src, 4 * sizeof(int8_t));
  muint8m1_t u8_m1 = mmvcr_m_v(u8_v1, 0);
  msce8_m(u8_m1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MMVCR.M.V UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m2(24);
  vint16m1_t i16_v1 = mlce16_v(i16_src, 8 * sizeof(int16_t));
  mint16m1_t i16_m1 = mmvcr_m_v(i16_v1, 0);
  msce16_m(i16_m1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVCR.M.V INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m2(24);
  vuint16m1_t u16_v1 = mlce16_v(u16_src, 8 * sizeof(uint16_t));
  muint16m1_t u16_m1 = mmvcr_m_v(u16_v1, 0);
  msce16_m(u16_m1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVCR.M.V UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m2(24);
  vfloat16m1_t fp16_v1 = mlce16_v(fp16_src, 8 * sizeof(fp16_t));
  mfloat16m1_t fp16_m1 = mmvcr_m_v(fp16_v1, 0);
  msce16_m(fp16_m1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVCR.M.V FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m1(4);
  vint32m1_t i32_v1 = mlce32_v(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_m1 = mmvcr_m_v(i32_v1, 0);
  msce32_m(i32_m1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVCR.M.V INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m2(4);
  vuint32m1_t u32_v1 = mlce32_v(u32_src, 2 * sizeof(uint32_t));
  muint32m1_t u32_m1 = mmvcr_m_v(u32_v1, 0);
  msce32_m(u32_m1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVCR.M.V UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m2(4);
  vfloat32m1_t fp32_v1 = mlce32_v(fp32_src, 2 * sizeof(fp32_t));
  mfloat32m1_t fp32_m1 = mmvcr_m_v(fp32_v1, 0);
  msce32_m(fp32_m1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVCR.M.V FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vint64m1_t i64_v1 = mlce64_v(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_m1 = mmvcr_m_v(i64_v1, 0);
  msce64_m(i64_m1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVCR.M.V INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vuint64m1_t u64_v1 = mlce64_v(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_m1 = mmvcr_m_v(u64_v1, 0);
  msce64_m(u64_m1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVCR.M.V UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vfloat64m1_t fp64_v1 = mlce64_v(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_m1 = mmvcr_m_v(fp64_v1, 0);
  msce64_m(fp64_m1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVCR.M.V FP64  ");
}

static void test_mmvac_v_m() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(4);
  vsetvl_e8m1(12);
  mint8m1_t i8_m1 = mlae8_m1(i8_src, 4 * sizeof(int8_t));
  vint8m1_t i8_v1 = mmvac_v_m(i8_m1, 0);
  msettilemi(4);
  msettileki(3);
  msae8_v(i8_v1, i8_buffer, 3 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_tp, i8_buffer, 12, "MMVAC.V.M INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(4);
  vsetvl_e8m1(12);
  muint8m1_t u8_m1 = mlae8_m1(u8_src, 4 * sizeof(int8_t));
  vuint8m1_t u8_v1 = mmvac_v_m(u8_m1, 0);
  msettilemi(4);
  msettileki(3);
  msae8_v(u8_v1, u8_buffer, 3 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_tp, u8_buffer, 12, "MMVAC.V.M UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m8(24);
  mint16m1_t i16_m1 = mlae16_m1(i16_src, 8 * sizeof(int16_t));
  vint16m1_t i16_v1 = mmvac_v_m(i16_m1, 0);
  msettilemi(8);
  msettileki(3);
  msae16_v(i16_v1, i16_buffer, 3 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_tp, i16_buffer, 24, "MMVAC.V.M INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m8(24);
  muint16m1_t u16_m1 = mlae16_m1(u16_src, 8 * sizeof(uint16_t));
  vuint16m1_t u16_v1 = mmvac_v_m(u16_m1, 0);
  msettilemi(8);
  msettileki(3);
  msae16_v(u16_v1, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_tp, u16_buffer, 24, "MMVAC.V.M UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(8);
  vsetvl_e16m8(24);
  mfloat16m1_t fp16_m1 = mlae16_m1(fp16_src, 8 * sizeof(fp16_t));
  vfloat16m1_t fp16_v1 = mmvac_v_m(fp16_m1, 0);
  msettilemi(8);
  msettileki(3);
  msae16_v(fp16_v1, fp16_buffer, 3 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_tp, fp16_buffer, 24, "MMVAC.V.M FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m1(4);
  mint32m1_t i32_m1 = mlae32_m1(i32_src, 2 * sizeof(int32_t));
  vint32m1_t i32_v1 = mmvac_v_m(i32_m1, 0);
  msae32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_tp, i32_buffer, 4, "MMVAC.V.M INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m1(4);
  muint32m1_t u32_m1 = mlae32_m1(u32_src, 2 * sizeof(uint32_t));
  vuint32m1_t u32_v1 = mmvac_v_m(u32_m1, 0);
  msae32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_tp, u32_buffer, 4, "MMVAC.V.M UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m1(4);
  mfloat32m1_t fp32_m1 = mlae32_m1(fp32_src, 2 * sizeof(uint32_t));
  vfloat32m1_t fp32_v1 = mmvac_v_m(fp32_m1, 0);
  msae32_v(fp32_v1, fp32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_tp, fp32_buffer, 4, "MMVAC.V.M FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  mint64m1_t i64_m1 = mlae64_m1(i64_src, 2 * sizeof(int64_t));
  vint64m1_t i64_v1 = mmvac_v_m(i64_m1, 0);
  msae64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_tp, i64_buffer, 4, "MMVAC.V.M INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  muint64m1_t u64_m1 = mlae64_m1(u64_src, 2 * sizeof(uint64_t));
  vuint64m1_t u64_v1 = mmvac_v_m(u64_m1, 0);
  msae64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_tp, u64_buffer, 4, "MMVAC.V.M UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  mfloat64m1_t fp64_m2 = mlae64_m1(fp64_src, 2 * sizeof(uint64_t));
  vfloat64m1_t fp64_v2 = mmvac_v_m(fp64_m2, 0);
  msae64_v(fp64_v2, fp64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_tp, fp64_buffer, 4, "MMVAC.V.M FP64  ");
}

static void test_mmvbc_v_m() {
  // int8
  msettype(E8, M1, BA);
  msettileki(3);
  msettileni(4);
  vsetvl_e8m1(12);
  mint8m1_t i8_m1 = mlbe8_m1(i8_src, 4 * sizeof(int8_t));
  vint8m1_t i8_v1 = mmvbc_v_m(i8_m1, 0);
  msettileki(4);
  msettileni(3);
  msbe8_v(i8_v1, i8_buffer, 3 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_tp, i8_buffer, 12, "MMVBC.V.M INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettileki(3);
  msettileni(4);
  vsetvl_e8m1(12);
  muint8m1_t u8_m1 = mlbe8_m1(u8_src, 4 * sizeof(int8_t));
  vuint8m1_t u8_v1 = mmvbc_v_m(u8_m1, 0);
  msettileki(4);
  msettileni(3);
  msbe8_v(u8_v1, u8_buffer, 3 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_tp, u8_buffer, 12, "MMVBC.V.M UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m8(24);
  mint16m1_t i16_m1 = mlbe16_m1(i16_src, 8 * sizeof(int16_t));
  vint16m1_t i16_v1 = mmvbc_v_m(i16_m1, 0);
  msettileki(8);
  msettileni(3);
  msbe16_v(i16_v1, i16_buffer, 3 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_tp, i16_buffer, 24, "MMVBC.V.M INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m8(24);
  muint16m1_t u16_m1 = mlbe16_m1(u16_src, 8 * sizeof(uint16_t));
  vuint16m1_t u16_v1 = mmvbc_v_m(u16_m1, 0);
  msettileki(8);
  msettileni(3);
  msbe16_v(u16_v1, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_tp, u16_buffer, 24, "MMVBC.V.M UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(8);
  vsetvl_e16m8(24);
  mfloat16m1_t fp16_m1 = mlbe16_m1(fp16_src, 8 * sizeof(fp16_t));
  vfloat16m1_t fp16_v1 = mmvbc_v_m(fp16_m1, 0);
  msettileki(8);
  msettileni(3);
  msbe16_v(fp16_v1, fp16_buffer, 3 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_tp, fp16_buffer, 24, "MMVBC.V.M FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m1(4);
  mint32m1_t i32_m1 = mlbe32_m1(i32_src, 2 * sizeof(int32_t));
  vint32m1_t i32_v1 = mmvbc_v_m(i32_m1, 0);
  msbe32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_tp, i32_buffer, 4, "MMVBC.V.M INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m1(4);
  muint32m1_t u32_m1 = mlbe32_m1(u32_src, 2 * sizeof(uint32_t));
  vuint32m1_t u32_v1 = mmvbc_v_m(u32_m1, 0);
  msbe32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_tp, u32_buffer, 4, "MMVBC.V.M UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m1(4);
  mfloat32m1_t fp32_m1 = mlbe32_m1(fp32_src, 2 * sizeof(uint32_t));
  vfloat32m1_t fp32_v1 = mmvbc_v_m(fp32_m1, 0);
  msbe32_v(fp32_v1, fp32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_tp, fp32_buffer, 4, "MMVBC.V.M FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  mint64m1_t i64_m1 = mlbe64_m1(i64_src, 2 * sizeof(int64_t));
  vint64m1_t i64_v1 = mmvbc_v_m(i64_m1, 0);
  msbe64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_tp, i64_buffer, 4, "MMVBC.V.M INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  muint64m1_t u64_m1 = mlbe64_m1(u64_src, 2 * sizeof(uint64_t));
  vuint64m1_t u64_v1 = mmvbc_v_m(u64_m1, 0);
  msbe64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_tp, u64_buffer, 4, "MMVBC.V.M UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  mfloat64m1_t fp64_m2 = mlbe64_m1(fp64_src, 2 * sizeof(uint64_t));
  vfloat64m1_t fp64_v2 = mmvbc_v_m(fp64_m2, 0);
  msbe64_v(fp64_v2, fp64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_tp, fp64_buffer, 4, "MMVBC.V.M FP64  ");
}

static void test_mmvcc_v_m() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileni(4);
  vsetvl_e8m1(12);
  mint8m1_t i8_m1 = mlce8_m1(i8_src, 4 * sizeof(int8_t));
  vint8m1_t i8_v1 = mmvcc_v_m(i8_m1, 0);
  msettilemi(4);
  msettileni(3);
  msce8_v(i8_v1, i8_buffer, 3 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_tp, i8_buffer, 12, "MMVCC.V.M INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileni(4);
  vsetvl_e8m1(12);
  muint8m1_t u8_m1 = mlce8_m1(u8_src, 4 * sizeof(int8_t));
  vuint8m1_t u8_v1 = mmvcc_v_m(u8_m1, 0);
  msettilemi(4);
  msettileni(3);
  msce8_v(u8_v1, u8_buffer, 3 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_tp, u8_buffer, 12, "MMVCC.V.M UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m8(24);
  mint16m1_t i16_m1 = mlce16_m1(i16_src, 8 * sizeof(int16_t));
  vint16m1_t i16_v1 = mmvcc_v_m(i16_m1, 0);
  msettilemi(8);
  msettileni(3);
  msce16_v(i16_v1, i16_buffer, 3 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_tp, i16_buffer, 24, "MMVCC.V.M INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m8(24);
  muint16m1_t u16_m1 = mlce16_m1(u16_src, 8 * sizeof(uint16_t));
  vuint16m1_t u16_v1 = mmvcc_v_m(u16_m1, 0);
  msettilemi(8);
  msettileni(3);
  msce16_v(u16_v1, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_tp, u16_buffer, 24, "MMVCC.V.M UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  vsetvl_e16m8(24);
  mfloat16m1_t fp16_m1 = mlce16_m1(fp16_src, 8 * sizeof(fp16_t));
  vfloat16m1_t fp16_v1 = mmvcc_v_m(fp16_m1, 0);
  msettilemi(8);
  msettileni(3);
  msce16_v(fp16_v1, fp16_buffer, 3 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_tp, fp16_buffer, 24, "MMVCC.V.M FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m1(4);
  mint32m1_t i32_m1 = mlce32_m1(i32_src, 2 * sizeof(int32_t));
  vint32m1_t i32_v1 = mmvcc_v_m(i32_m1, 0);
  msce32_v(i32_v1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_tp, i32_buffer, 4, "MMVCC.V.M INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m1(4);
  muint32m1_t u32_m1 = mlce32_m1(u32_src, 2 * sizeof(uint32_t));
  vuint32m1_t u32_v1 = mmvcc_v_m(u32_m1, 0);
  msce32_v(u32_v1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_tp, u32_buffer, 4, "MMVCC.V.M UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m1(4);
  mfloat32m1_t fp32_m1 = mlce32_m1(fp32_src, 2 * sizeof(uint32_t));
  vfloat32m1_t fp32_v1 = mmvcc_v_m(fp32_m1, 0);
  msce32_v(fp32_v1, fp32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_tp, fp32_buffer, 4, "MMVCC.V.M FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  mint64m1_t i64_m1 = mlce64_m1(i64_src, 2 * sizeof(int64_t));
  vint64m1_t i64_v1 = mmvcc_v_m(i64_m1, 0);
  msce64_v(i64_v1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_tp, i64_buffer, 4, "MMVCC.V.M INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  muint64m1_t u64_m1 = mlce64_m1(u64_src, 2 * sizeof(uint64_t));
  vuint64m1_t u64_v1 = mmvcc_v_m(u64_m1, 0);
  msce64_v(u64_v1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_tp, u64_buffer, 4, "MMVCC.V.M UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  mfloat64m1_t fp64_m2 = mlce64_m1(fp64_src, 2 * sizeof(uint64_t));
  vfloat64m1_t fp64_v2 = mmvcc_v_m(fp64_m2, 0);
  msce64_v(fp64_v2, fp64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_tp, fp64_buffer, 4, "MMVCC.V.M FP64  ");
}

static void test_mmvac_m_v() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(4);
  msettileki(3);
  vsetvl_e8m1(12);
  vint8m1_t i8_v1 = mlae8_v(i8_tp, 3 * sizeof(int8_t));
  msettilemi(3);
  msettileki(4);
  mint8m1_t i8_m1 = mmvac_m_v(i8_v1, 0);
  msae8_m(i8_m1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVAC.M.V INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(4);
  msettileki(3);
  vsetvl_e8m1(12);
  vuint8m1_t u8_v1 = mlae8_v(u8_tp, 3 * sizeof(int8_t));
  msettilemi(3);
  msettileki(4);
  muint8m1_t u8_m1 = mmvac_m_v(u8_v1, 0);
  msae8_m(u8_m1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MMVAC.M.V UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(8);
  msettileki(3);
  vsetvl_e16m2(24);
  vint16m1_t i16_v1 = mlae16_v(i16_tp, 3 * sizeof(int16_t));
  msettilemi(3);
  msettileki(8);
  mint16m1_t i16_m1 = mmvac_m_v(i16_v1, 0);
  msae16_m(i16_m1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVAC.M.V INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(8);
  msettileki(3);
  vsetvl_e16m2(24);
  vuint16m1_t u16_v1 = mlae16_v(u16_tp, 3 * sizeof(uint16_t));
  msettilemi(3);
  msettileki(8);
  muint16m1_t u16_m1 = mmvac_m_v(u16_v1, 0);
  msae16_m(u16_m1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVAC.M.V UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(8);
  msettileki(3);
  vsetvl_e16m2(24);
  vfloat16m1_t fp16_v1 = mlae16_v(fp16_tp, 3 * sizeof(fp16_t));
  msettilemi(3);
  msettileki(8);
  mfloat16m1_t fp16_m1 = mmvac_m_v(fp16_v1, 0);
  msae16_m(fp16_m1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVAC.M.V FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m1(4);
  vint32m1_t i32_v1 = mlae32_v(i32_tp, 2 * sizeof(int32_t));
  mint32m1_t i32_m1 = mmvac_m_v(i32_v1, 0);
  msae32_m(i32_m1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVAC.M.V INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m2(4);
  vuint32m1_t u32_v1 = mlae32_v(u32_tp, 2 * sizeof(uint32_t));
  muint32m1_t u32_m1 = mmvac_m_v(u32_v1, 0);
  msae32_m(u32_m1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVAC.M.V UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e32m2(4);
  vfloat32m1_t fp32_v1 = mlae32_v(fp32_tp, 2 * sizeof(fp32_t));
  mfloat32m1_t fp32_m1 = mmvac_m_v(fp32_v1, 0);
  msae32_m(fp32_m1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVAC.M.V FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  vint64m1_t i64_v1 = mlae64_v(i64_tp, 2 * sizeof(int64_t));
  mint64m1_t i64_m1 = mmvac_m_v(i64_v1, 0);
  msae64_m(i64_m1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVAC.M.V INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  vuint64m1_t u64_v1 = mlae64_v(u64_tp, 2 * sizeof(uint64_t));
  muint64m1_t u64_m1 = mmvac_m_v(u64_v1, 0);
  msae64_m(u64_m1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVAC.M.V UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileki(2);
  vsetvl_e64m2(4);
  vfloat64m1_t fp64_v1 = mlae64_v(fp64_tp, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_m1 = mmvac_m_v(fp64_v1, 0);
  msae64_m(fp64_m1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVAC.M.V FP64  ");
}

static void test_mmvbc_m_v() {
  // int8
  msettype(E8, M1, BA);
  msettileki(4);
  msettileni(3);
  vsetvl_e8m1(12);
  vint8m1_t i8_v1 = mlbe8_v(i8_tp, 3 * sizeof(int8_t));
  msettileki(3);
  msettileni(4);
  mint8m1_t i8_m1 = mmvbc_m_v(i8_v1, 0);
  msbe8_m(i8_m1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVBC.M.V INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettileki(4);
  msettileni(3);
  vsetvl_e8m1(12);
  vuint8m1_t u8_v1 = mlbe8_v(u8_tp, 3 * sizeof(int8_t));
  msettileki(3);
  msettileni(4);
  muint8m1_t u8_m1 = mmvbc_m_v(u8_v1, 0);
  msbe8_m(u8_m1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MMVBC.M.V UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettileki(8);
  msettileni(3);
  vsetvl_e16m2(24);
  vint16m1_t i16_v1 = mlbe16_v(i16_tp, 3 * sizeof(int16_t));
  msettileki(3);
  msettileni(8);
  mint16m1_t i16_m1 = mmvbc_m_v(i16_v1, 0);
  msbe16_m(i16_m1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVBC.M.V INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettileki(8);
  msettileni(3);
  vsetvl_e16m2(24);
  vuint16m1_t u16_v1 = mlbe16_v(u16_tp, 3 * sizeof(uint16_t));
  msettileki(3);
  msettileni(8);
  muint16m1_t u16_m1 = mmvbc_m_v(u16_v1, 0);
  msbe16_m(u16_m1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVBC.M.V UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettileki(8);
  msettileni(3);
  vsetvl_e16m2(24);
  vfloat16m1_t fp16_v1 = mlbe16_v(fp16_tp, 3 * sizeof(fp16_t));
  msettileki(3);
  msettileni(8);
  mfloat16m1_t fp16_m1 = mmvbc_m_v(fp16_v1, 0);
  msbe16_m(fp16_m1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVBC.M.V FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m1(4);
  vint32m1_t i32_v1 = mlbe32_v(i32_tp, 2 * sizeof(int32_t));
  mint32m1_t i32_m1 = mmvbc_m_v(i32_v1, 0);
  msbe32_m(i32_m1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVBC.M.V INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m2(4);
  vuint32m1_t u32_v1 = mlbe32_v(u32_tp, 2 * sizeof(uint32_t));
  muint32m1_t u32_m1 = mmvbc_m_v(u32_v1, 0);
  msbe32_m(u32_m1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVBC.M.V UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e32m2(4);
  vfloat32m1_t fp32_v1 = mlbe32_v(fp32_tp, 2 * sizeof(fp32_t));
  mfloat32m1_t fp32_m1 = mmvbc_m_v(fp32_v1, 0);
  msbe32_m(fp32_m1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVBC.M.V FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vint64m1_t i64_v1 = mlbe64_v(i64_tp, 2 * sizeof(int64_t));
  mint64m1_t i64_m1 = mmvbc_m_v(i64_v1, 0);
  msbe64_m(i64_m1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVBC.M.V INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vuint64m1_t u64_v1 = mlbe64_v(u64_tp, 2 * sizeof(uint64_t));
  muint64m1_t u64_m1 = mmvbc_m_v(u64_v1, 0);
  msbe64_m(u64_m1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVBC.M.V UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettileki(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vfloat64m1_t fp64_v1 = mlbe64_v(fp64_tp, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_m1 = mmvbc_m_v(fp64_v1, 0);
  msbe64_m(fp64_m1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVBC.M.V FP64  ");
}

static void test_mmvcc_m_v() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(4);
  msettileni(3);
  vsetvl_e8m1(12);
  vint8m1_t i8_v1 = mlce8_v(i8_tp, 3 * sizeof(int8_t));
  msettilemi(3);
  msettileni(4);
  mint8m1_t i8_m1 = mmvcc_m_v(i8_v1, 0);
  msce8_m(i8_m1, i8_buffer, 4 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVCC.M.V INT8  ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(4);
  msettileni(3);
  vsetvl_e8m1(12);
  vuint8m1_t u8_v1 = mlce8_v(u8_tp, 3 * sizeof(int8_t));
  msettilemi(3);
  msettileni(4);
  muint8m1_t u8_m1 = mmvcc_m_v(u8_v1, 0);
  msce8_m(u8_m1, u8_buffer, 4 * sizeof(int8_t));
  EXCEPT_U8_ARRAY_EQ(u8_src, u8_buffer, 12, "MMVCC.M.V UINT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(8);
  msettileni(3);
  vsetvl_e16m2(24);
  vint16m1_t i16_v1 = mlce16_v(i16_tp, 3 * sizeof(int16_t));
  msettilemi(3);
  msettileni(8);
  mint16m1_t i16_m1 = mmvcc_m_v(i16_v1, 0);
  msce16_m(i16_m1, i16_buffer, 8 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_src, i16_buffer, 24, "MMVCC.M.V INT16 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(8);
  msettileni(3);
  vsetvl_e16m2(24);
  vuint16m1_t u16_v1 = mlce16_v(u16_tp, 3 * sizeof(uint16_t));
  msettilemi(3);
  msettileni(8);
  muint16m1_t u16_m1 = mmvcc_m_v(u16_v1, 0);
  msce16_m(u16_m1, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_src, u16_buffer, 24, "MMVCC.M.V UINT16");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(8);
  msettileni(3);
  vsetvl_e16m2(24);
  vfloat16m1_t fp16_v1 = mlce16_v(fp16_tp, 3 * sizeof(fp16_t));
  msettilemi(3);
  msettileni(8);
  mfloat16m1_t fp16_m1 = mmvcc_m_v(fp16_v1, 0);
  msce16_m(fp16_m1, fp16_buffer, 8 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_src, fp16_buffer, 24, "MMVCC.M.V FP16  ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m1(4);
  vint32m1_t i32_v1 = mlce32_v(i32_tp, 2 * sizeof(int32_t));
  mint32m1_t i32_m1 = mmvcc_m_v(i32_v1, 0);
  msce32_m(i32_m1, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_src, i32_buffer, 4, "MMVCC.M.V INT32 ");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m2(4);
  vuint32m1_t u32_v1 = mlce32_v(u32_tp, 2 * sizeof(uint32_t));
  muint32m1_t u32_m1 = mmvcc_m_v(u32_v1, 0);
  msce32_m(u32_m1, u32_buffer, 2 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_src, u32_buffer, 4, "MMVCC.M.V UINT32");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e32m2(4);
  vfloat32m1_t fp32_v1 = mlce32_v(fp32_tp, 2 * sizeof(fp32_t));
  mfloat32m1_t fp32_m1 = mmvcc_m_v(fp32_v1, 0);
  msce32_m(fp32_m1, fp32_buffer, 2 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_src, fp32_buffer, 4, "MMVCC.M.V FP32  ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vint64m1_t i64_v1 = mlce64_v(i64_tp, 2 * sizeof(int64_t));
  mint64m1_t i64_m1 = mmvcc_m_v(i64_v1, 0);
  msce64_m(i64_m1, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_src, i64_buffer, 4, "MMVCC.M.V INT64 ");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vuint64m1_t u64_v1 = mlce64_v(u64_tp, 2 * sizeof(uint64_t));
  muint64m1_t u64_m1 = mmvcc_m_v(u64_v1, 0);
  msce64_m(u64_m1, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_src, u64_buffer, 4, "MMVCC.M.V UINT64");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  vsetvl_e64m2(4);
  vfloat64m1_t fp64_v1 = mlce64_v(fp64_tp, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_m1 = mmvcc_m_v(fp64_v1, 0);
  msce64_m(fp64_m1, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_src, fp64_buffer, 4, "MMVCC.M.V FP64  ");
}

int main() {
  test_mlae8v_and_msae8v();
  test_mlbe8v_and_msbe8v();
  test_mlce8v_and_msce8v();
  test_mlae16v_and_msae16v();
  test_mlbe16v_and_msbe16v();
  test_mlce16v_and_msce16v();
  test_mlae32v_and_msae32v();
  test_mlbe32v_and_msbe32v();
  test_mlce32v_and_msce32v();
  test_mlae64v_and_msae64v();
  test_mlbe64v_and_msbe64v();
  test_mlce64v_and_msce64v();
  test_mmvar_v_m();
  test_mmvbr_v_m();
  test_mmvcr_v_m();
  test_mmvar_m_v();
  test_mmvbr_m_v();
  test_mmvcr_m_v();
  test_mmvac_v_m();
  test_mmvbc_v_m();
  test_mmvcc_v_m();
  test_mmvac_m_v();
  test_mmvbc_m_v();
  test_mmvcc_m_v();
  return 0;
}