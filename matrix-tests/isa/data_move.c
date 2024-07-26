#include "utils.h"
#include <riscv_matrix.h>

// Broadcast the first row to fill the whole matrix
static void test_mbcar_m() {
  // M1
  // int8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -89, -93, -89};
  mint8m1_t i8_ts1 = mlae8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbcar_m(i8_ts1);
  msae8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "  MBCAR INT8   M1");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, -30160, 24455, -30160, 24455, -30160};
  mint16m1_t i16_ts1 = mlae16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbcar_m(i16_ts1);
  msae16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "  MBCAR INT16  M1");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileki(1);
  const int32_t i32_src[] = {246897081, -1926070292};
  const int32_t i32_ans[] = {246897081, 246897081};
  mint32m1_t i32_ts1 = mlae32_m1(i32_src, 1 * sizeof(int32_t));
  mint32m1_t i32_td = mbcar_m(i32_ts1);
  msae32_m(i32_td, i32_buffer, 1 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "  MBCAR INT32  M1");
  // int64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, -8148777892508189639,
                             6434836983883769530, -8148777892508189639,
                             6434836983883769530, -8148777892508189639};
  mint64m1_t i64_ts1 = mlae64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbcar_m(i64_ts1);
  msae64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "  MBCAR INT64  M1");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 0u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 218u, 216u, 222u, 0u, 218u, 216u, 222u};
  muint8m1_t u8_ts1 = mlae8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbcar_m(u8_ts1);
  msae8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "  MBCAR UINT8  M1");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(5);
  msettileki(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 9091u,  8049u,  42743u, 9091u,
                              8049u,  42743u, 9091u,  8049u,  42743u,
                              9091u,  8049u,  42743u, 9091u,  8049u};
  muint16m1_t u16_ts1 = mlae16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbcar_m(u16_ts1);
  msae16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "  MBCAR UINT16 M1");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(5);
  msettileki(1);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlae32_m1(u32_src, 1 * sizeof(uint32_t));
  muint32m1_t u32_td = mbcar_m(u32_ts1);
  msae32_m(u32_td, u32_buffer, 1 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "  MBCAR UINT32 M1");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 4875585649773384250u,
                              14537392746491786892u, 4875585649773384250u,
                              14537392746491786892u, 4875585649773384250u};
  muint64m1_t u64_ts1 = mlae64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbcar_m(u64_ts1);
  msae64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "  MBCAR UINT64 M1");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(2);
  const fp16_t fp16_src[] = {1.417, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {1.417, -0.611, 1.417, -0.611};
  mfloat16m1_t fp16_ts1 = mlae16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbcar_m(fp16_ts1);
  msae16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, " MBCAR FP16   M1");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileki(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f,  0.25072205f, 0.552841f,   0.2876706f,
                             0.25072205f, 0.552841f,   0.2876706f,  0.25072205f,
                             0.552841f,   0.2876706f,  0.25072205f, 0.552841f};
  mfloat32m1_t fp32_ts1 = mlae32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbcar_m(fp32_ts1);
  msae32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, " MBCAR FP32   M1");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {0.25951296,  -0.22276918, 0.25951296,
                             -0.22276918, 0.25951296,  -0.22276918};
  mfloat64m1_t fp64_ts1 = mlae64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbcar_m(fp64_ts1);
  msae64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, " MBCAR FP64   M1");
}

static void test_mbcbr_m() {
  // int8
  msettype(E8, M1, BA);
  msettileki(2);
  msettileni(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -89, -93, -89};
  mint8m1_t i8_ts1 = mlbe8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbcbr_m(i8_ts1);
  msbe8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "MBCBR INT8  ");
  // int16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, -30160, 24455, -30160, 24455, -30160};
  mint16m1_t i16_ts1 = mlbe16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbcbr_m(i16_ts1);
  msbe16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MBCBR INT16 ");
  // int32
  msettype(E32, M1, BA);
  msettileki(2);
  msettileni(1);
  const int32_t i32_src[] = {246897081, -1926070292};
  const int32_t i32_ans[] = {246897081, 246897081};
  mint32m1_t i32_ts1 = mlbe32_m1(i32_src, 1 * sizeof(int32_t));
  mint32m1_t i32_td = mbcbr_m(i32_ts1);
  msbe32_m(i32_td, i32_buffer, 1 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "MBCBR INT32 ");
  // int64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, -8148777892508189639,
                             6434836983883769530, -8148777892508189639,
                             6434836983883769530, -8148777892508189639};
  mint64m1_t i64_ts1 = mlbe64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbcbr_m(i64_ts1);
  msbe64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "MBCBR INT64 ");
  // uint8
  msettype(E8, M1, BA);
  msettileki(2);
  msettileni(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 0u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 218u, 216u, 222u, 0u, 218u, 216u, 222u};
  muint8m1_t u8_ts1 = mlbe8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbcbr_m(u8_ts1);
  msbe8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "MBCBR UINT8 ");
  // uint16
  msettype(E16, M1, BA);
  msettileki(5);
  msettileni(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 9091u,  8049u,  42743u, 9091u,
                              8049u,  42743u, 9091u,  8049u,  42743u,
                              9091u,  8049u,  42743u, 9091u,  8049u};
  muint16m1_t u16_ts1 = mlbe16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbcbr_m(u16_ts1);
  msbe16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "MBCBR UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettileki(5);
  msettileni(1);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlbe32_m1(u32_src, 1 * sizeof(uint32_t));
  muint32m1_t u32_td = mbcbr_m(u32_ts1);
  msbe32_m(u32_td, u32_buffer, 1 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "MBCBR UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 4875585649773384250u,
                              14537392746491786892u, 4875585649773384250u,
                              14537392746491786892u, 4875585649773384250u};
  muint64m1_t u64_ts1 = mlbe64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbcbr_m(u64_ts1);
  msbe64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "MBCBR UINT64");
  // fp16
  msettype(E16, M1, BA);
  msettileki(2);
  msettileni(2);
  const fp16_t fp16_src[] = {1.417, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {1.417, -0.611, 1.417, -0.611};
  mfloat16m1_t fp16_ts1 = mlbe16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbcbr_m(fp16_ts1);
  msbe16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, "MBCBR FP16  ");
  // fp32
  msettype(E32, M1, BA);
  msettileki(4);
  msettileni(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f,  0.25072205f, 0.552841f,   0.2876706f,
                             0.25072205f, 0.552841f,   0.2876706f,  0.25072205f,
                             0.552841f,   0.2876706f,  0.25072205f, 0.552841f};
  mfloat32m1_t fp32_ts1 = mlbe32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbcbr_m(fp32_ts1);
  msbe32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, "MBCBR FP32  ");
  // fp64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {0.25951296,  -0.22276918, 0.25951296,
                             -0.22276918, 0.25951296,  -0.22276918};
  mfloat64m1_t fp64_ts1 = mlbe64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbcbr_m(fp64_ts1);
  msbe64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, "MBCBR FP64  ");
}

static void test_mbccr_m() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileni(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -89, -93, -89};
  mint8m1_t i8_ts1 = mlce8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbccr_m(i8_ts1);
  msce8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "MBCCR INT8  ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, -30160, 24455, -30160, 24455, -30160};
  mint16m1_t i16_ts1 = mlce16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbccr_m(i16_ts1);
  msce16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MBCCR INT16 ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(1);
  const int32_t i32_src[] = {246897081, -1926070292};
  const int32_t i32_ans[] = {246897081, 246897081};
  mint32m1_t i32_ts1 = mlce32_m1(i32_src, 1 * sizeof(int32_t));
  mint32m1_t i32_td = mbccr_m(i32_ts1);
  msce32_m(i32_td, i32_buffer, 1 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "MBCCR INT32 ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileni(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, -8148777892508189639,
                             6434836983883769530, -8148777892508189639,
                             6434836983883769530, -8148777892508189639};
  mint64m1_t i64_ts1 = mlce64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbccr_m(i64_ts1);
  msce64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "MBCCR INT64 ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileni(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 0u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 218u, 216u, 222u, 0u, 218u, 216u, 222u};
  muint8m1_t u8_ts1 = mlce8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbccr_m(u8_ts1);
  msce8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "MBCCR UINT8 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(5);
  msettileni(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 9091u,  8049u,  42743u, 9091u,
                              8049u,  42743u, 9091u,  8049u,  42743u,
                              9091u,  8049u,  42743u, 9091u,  8049u};
  muint16m1_t u16_ts1 = mlce16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbccr_m(u16_ts1);
  msce16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "MBCCR UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(5);
  msettileni(1);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlce32_m1(u32_src, 1 * sizeof(uint32_t));
  muint32m1_t u32_td = mbccr_m(u32_ts1);
  msce32_m(u32_td, u32_buffer, 1 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "MBCCR UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileni(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 4875585649773384250u,
                              14537392746491786892u, 4875585649773384250u,
                              14537392746491786892u, 4875585649773384250u};
  muint64m1_t u64_ts1 = mlce64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbccr_m(u64_ts1);
  msce64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "MBCCR UINT64");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileni(2);
  const fp16_t fp16_src[] = {1.417, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {1.417, -0.611, 1.417, -0.611};
  mfloat16m1_t fp16_ts1 = mlce16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbccr_m(fp16_ts1);
  msce16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, "MBCCR FP16  ");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileni(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f,  0.25072205f, 0.552841f,   0.2876706f,
                             0.25072205f, 0.552841f,   0.2876706f,  0.25072205f,
                             0.552841f,   0.2876706f,  0.25072205f, 0.552841f};
  mfloat32m1_t fp32_ts1 = mlce32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbccr_m(fp32_ts1);
  msce32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, "MBCCR FP32  ");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileni(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {
      0.25951296, -0.22276918, 0.25951296, -0.22276918, 0.25951296, -0.22276918,
  };
  mfloat64m1_t fp64_ts1 = mlce64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbccr_m(fp64_ts1);
  msce64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, "MBCCR FP64  ");
}

// Broadcast the first column to fill the whole matrix
static void test_mbcac_m() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -93, 121, 121};
  mint8m1_t i8_ts1 = mlae8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbcac_m(i8_ts1);
  msae8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "MBCAC INT8  ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, 24455, -20540, -20540, -20540, -20540};
  mint16m1_t i16_ts1 = mlae16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbcac_m(i16_ts1);
  msae16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MBCAC INT16 ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileki(2);
  const int32_t i32_src[] = {246897081, -1926070292};
  const int32_t i32_ans[] = {246897081, 246897081};
  mint32m1_t i32_ts1 = mlae32_m1(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_td = mbcac_m(i32_ts1);
  msae32_m(i32_td, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "MBCAC INT32 ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, 6434836983883769530,
                             5511953749517690378, 5511953749517690378,
                             5511953749517690378, 5511953749517690378};
  mint64m1_t i64_ts1 = mlae64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbcac_m(i64_ts1);
  msae64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "MBCAC INT64 ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 218u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 0u, 0u, 0u, 218u, 218u, 218u, 218u};
  muint8m1_t u8_ts1 = mlae8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbcac_m(u8_ts1);
  msae8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "MBCAC UINT8 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(5);
  msettileki(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 42743u, 42743u, 55208u, 55208u,
                              55208u, 8049u,  8049u,  8049u,  55208u,
                              55208u, 55208u, 8049u,  8049u,  8049u};
  muint16m1_t u16_ts1 = mlae16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbcac_m(u16_ts1);
  msae16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "MBCAC UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileki(5);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlae32_m1(u32_src, 5 * sizeof(uint32_t));
  muint32m1_t u32_td = mbcac_m(u32_ts1);
  msae32_m(u32_td, u32_buffer, 5 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "MBCAC UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 14537392746491786892u,
                              15478644212105236565u, 15478644212105236565u,
                              2453739374649178682u,  2453739374649178682u};
  muint64m1_t u64_ts1 = mlae64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbcac_m(u64_ts1);
  msae64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "MBCAC UINT64");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(2);
  const fp16_t fp16_src[] = {1.417, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {1.417, 1.417, 0.852, 0.852};
  mfloat16m1_t fp16_ts1 = mlae16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbcac_m(fp16_ts1);
  msae16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, "MBCAC FP16  ");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileki(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f,  0.2876706f,  0.2876706f,
                             -1.4288656f, -1.4288656f, -1.4288656f,
                             0.552841f,   0.552841f,   0.552841f,
                             -1.4288656f, -1.4288656f, -1.4288656f};
  mfloat32m1_t fp32_ts1 = mlae32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbcac_m(fp32_ts1);
  msae32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, "MBCAC FP32  ");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {0.25951296, 0.25951296, 0.00402457,
                             0.00402457, 0.25951296, 0.25951296};
  mfloat64m1_t fp64_ts1 = mlae64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbcac_m(fp64_ts1);
  msae64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, "MBCAC FP64  ");
}

static void test_mbcbc_m() {
  // int8
  msettype(E8, M1, BA);
  msettileki(2);
  msettileni(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -93, 121, 121};
  mint8m1_t i8_ts1 = mlbe8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbcbc_m(i8_ts1);
  msbe8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "MBCBC INT8  ");
  // int16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, 24455, -20540, -20540, -20540, -20540};
  mint16m1_t i16_ts1 = mlbe16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbcbc_m(i16_ts1);
  msbe16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MBCBC INT16 ");
  // int32
  msettype(E32, M1, BA);
  msettileki(1);
  msettileni(2);
  const int32_t i32_src[] = {246897081, -1926070292};
  const int32_t i32_ans[] = {246897081, 246897081};
  mint32m1_t i32_ts1 = mlbe32_m1(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_td = mbcbc_m(i32_ts1);
  msbe32_m(i32_td, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "MBCBC INT32 ");
  // int64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, 6434836983883769530,
                             5511953749517690378, 5511953749517690378,
                             5511953749517690378, 5511953749517690378};
  mint64m1_t i64_ts1 = mlbe64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbcbc_m(i64_ts1);
  msbe64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "MBCBC INT64 ");
  // uint8
  msettype(E8, M1, BA);
  msettileki(2);
  msettileni(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 218u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 0u, 0u, 0u, 218u, 218u, 218u, 218u};
  muint8m1_t u8_ts1 = mlbe8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbcbc_m(u8_ts1);
  msbe8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "MBCBC UINT8 ");
  // uint16
  msettype(E16, M1, BA);
  msettileki(5);
  msettileni(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 42743u, 42743u, 55208u, 55208u,
                              55208u, 8049u,  8049u,  8049u,  55208u,
                              55208u, 55208u, 8049u,  8049u,  8049u};
  muint16m1_t u16_ts1 = mlbe16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbcbc_m(u16_ts1);
  msbe16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "MBCBC UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettileki(1);
  msettileni(5);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlbe32_m1(u32_src, 5 * sizeof(uint32_t));
  muint32m1_t u32_td = mbcbc_m(u32_ts1);
  msbe32_m(u32_td, u32_buffer, 5 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "MBCBC UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 14537392746491786892u,
                              15478644212105236565u, 15478644212105236565u,
                              2453739374649178682u,  2453739374649178682u};
  muint64m1_t u64_ts1 = mlbe64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbcbc_m(u64_ts1);
  msbe64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "MBCBC UINT64");
  // fp16
  msettype(E16, M1, BA);
  msettileki(2);
  msettileni(2);
  const fp16_t fp16_src[] = {1.417, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {1.417, 1.417, 0.852, 0.852};
  mfloat16m1_t fp16_ts1 = mlbe16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbcbc_m(fp16_ts1);
  msbe16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, "MBCBC FP16  ");
  // fp32
  msettype(E32, M1, BA);
  msettileki(4);
  msettileni(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f,  0.2876706f,  0.2876706f,
                             -1.4288656f, -1.4288656f, -1.4288656f,
                             0.552841f,   0.552841f,   0.552841f,
                             -1.4288656f, -1.4288656f, -1.4288656f};
  mfloat32m1_t fp32_ts1 = mlbe32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbcbc_m(fp32_ts1);
  msbe32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, "MBCBC FP32  ");
  // fp64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {0.25951296, 0.25951296, 0.00402457,
                             0.00402457, 0.25951296, 0.25951296};
  mfloat64m1_t fp64_ts1 = mlbe64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbcbc_m(fp64_ts1);
  msbe64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, "MBCBC FP64  ");
}

static void test_mbccc_m() {
  // int8
  msettype(E8, M1, BA);
  msettileki(2);
  msettileni(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -93, 121, 121};
  mint8m1_t i8_ts1 = mlbe8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbcbc_m(i8_ts1);
  msbe8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "MBCCC INT8  ");
  // int16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, 24455, -20540, -20540, -20540, -20540};
  mint16m1_t i16_ts1 = mlbe16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbcbc_m(i16_ts1);
  msbe16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MBCCC INT16 ");
  // int32
  msettype(E32, M1, BA);
  msettileki(1);
  msettileni(2);
  const int32_t i32_src[] = {246897081, -1926070292};
  const int32_t i32_ans[] = {246897081, 246897081};
  mint32m1_t i32_ts1 = mlbe32_m1(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_td = mbcbc_m(i32_ts1);
  msbe32_m(i32_td, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "MBCCC INT32 ");
  // int64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, 6434836983883769530,
                             5511953749517690378, 5511953749517690378,
                             5511953749517690378, 5511953749517690378};
  mint64m1_t i64_ts1 = mlbe64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbcbc_m(i64_ts1);
  msbe64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "MBCCC INT64 ");
  // uint8
  msettype(E8, M1, BA);
  msettileki(2);
  msettileni(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 218u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 0u, 0u, 0u, 218u, 218u, 218u, 218u};
  muint8m1_t u8_ts1 = mlbe8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbcbc_m(u8_ts1);
  msbe8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "MBCCC UINT8 ");
  // uint16
  msettype(E16, M1, BA);
  msettileki(5);
  msettileni(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 42743u, 42743u, 55208u, 55208u,
                              55208u, 8049u,  8049u,  8049u,  55208u,
                              55208u, 55208u, 8049u,  8049u,  8049u};
  muint16m1_t u16_ts1 = mlbe16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbcbc_m(u16_ts1);
  msbe16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "MBCCC UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettileki(1);
  msettileni(5);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlbe32_m1(u32_src, 5 * sizeof(uint32_t));
  muint32m1_t u32_td = mbcbc_m(u32_ts1);
  msbe32_m(u32_td, u32_buffer, 5 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "MBCCC UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 14537392746491786892u,
                              15478644212105236565u, 15478644212105236565u,
                              2453739374649178682u,  2453739374649178682u};
  muint64m1_t u64_ts1 = mlbe64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbcbc_m(u64_ts1);
  msbe64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "MBCCC UINT64");
  // fp16
  msettype(E16, M1, BA);
  msettileki(2);
  msettileni(2);
  const fp16_t fp16_src[] = {1.417, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {1.417, 1.417, 0.852, 0.852};
  mfloat16m1_t fp16_ts1 = mlbe16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbcbc_m(fp16_ts1);
  msbe16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, "MBCCC FP16  ");
  // fp32
  msettype(E32, M1, BA);
  msettileki(4);
  msettileni(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f,  0.2876706f,  0.2876706f,
                             -1.4288656f, -1.4288656f, -1.4288656f,
                             0.552841f,   0.552841f,   0.552841f,
                             -1.4288656f, -1.4288656f, -1.4288656f};
  mfloat32m1_t fp32_ts1 = mlbe32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbcbc_m(fp32_ts1);
  msbe32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, "MBCCC FP32  ");
  // fp64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {0.25951296, 0.25951296, 0.00402457,
                             0.00402457, 0.25951296, 0.25951296};
  mfloat64m1_t fp64_ts1 = mlbe64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbcbc_m(fp64_ts1);
  msbe64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, "MBCCC FP64  ");
}

// Broadcast the first element to fill the whole matrix
static void test_mbcae_m() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -93, -93, -93};
  mint8m1_t i8_ts1 = mlae8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbcae_m(i8_ts1);
  msae8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "MBCAE INT8  ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileki(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, 24455, 24455, 24455, 24455, 24455};
  mint16m1_t i16_ts1 = mlae16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbcae_m(i16_ts1);
  msae16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MBCAE INT16 ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileki(2);
  const int32_t i32_src[] = {-1926070292, 246897081};
  const int32_t i32_ans[] = {-1926070292, -1926070292};
  mint32m1_t i32_ts1 = mlae32_m1(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_td = mbcae_m(i32_ts1);
  msae32_m(i32_td, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "MBCAE INT32 ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, 6434836983883769530,
                             6434836983883769530, 6434836983883769530,
                             6434836983883769530, 6434836983883769530};
  mint64m1_t i64_ts1 = mlae64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbcae_m(i64_ts1);
  msae64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "MBCAE INT64 ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileki(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 218u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};
  muint8m1_t u8_ts1 = mlae8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbcae_m(u8_ts1);
  msae8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "MBCAE UINT8 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(5);
  msettileki(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 42743u, 42743u, 42743u, 42743u,
                              42743u, 42743u, 42743u, 42743u, 42743u,
                              42743u, 42743u, 42743u, 42743u, 42743u};
  muint16m1_t u16_ts1 = mlae16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbcae_m(u16_ts1);
  msae16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "MBCAE UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileki(5);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlae32_m1(u32_src, 5 * sizeof(uint32_t));
  muint32m1_t u32_td = mbcae_m(u32_ts1);
  msae32_m(u32_td, u32_buffer, 5 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "MBCAE UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 14537392746491786892u,
                              14537392746491786892u, 14537392746491786892u,
                              14537392746491786892u, 14537392746491786892u};
  muint64m1_t u64_ts1 = mlae64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbcae_m(u64_ts1);
  msae64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "MBCAE UINT64");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileki(2);
  const fp16_t fp16_src[] = {-0.611, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {-0.611, -0.611, -0.611, -0.611};
  mfloat16m1_t fp16_ts1 = mlae16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbcae_m(fp16_ts1);
  msae16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, "MBCAE FP16  ");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileki(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f,
                             0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f,
                             0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f};
  mfloat32m1_t fp32_ts1 = mlae32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbcae_m(fp32_ts1);
  msae32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, "MBCAE FP32  ");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileki(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {0.25951296, 0.25951296, 0.25951296,
                             0.25951296, 0.25951296, 0.25951296};
  mfloat64m1_t fp64_ts1 = mlae64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbcae_m(fp64_ts1);
  msae64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, "MBCAE FP64  ");
}

static void test_mbcbe_m() {
  // int8
  msettype(E8, M1, BA);
  msettileki(2);
  msettileni(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -93, -93, -93};
  mint8m1_t i8_ts1 = mlbe8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbcbe_m(i8_ts1);
  msbe8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "MBCBE INT8  ");
  // int16
  msettype(E16, M1, BA);
  msettileki(3);
  msettileni(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, 24455, 24455, 24455, 24455, 24455};
  mint16m1_t i16_ts1 = mlbe16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbcbe_m(i16_ts1);
  msbe16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MBCBE INT16 ");
  // int32
  msettype(E32, M1, BA);
  msettileki(1);
  msettileni(2);
  const int32_t i32_src[] = {-1926070292, 246897081};
  const int32_t i32_ans[] = {-1926070292, -1926070292};
  mint32m1_t i32_ts1 = mlbe32_m1(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_td = mbcbe_m(i32_ts1);
  msbe32_m(i32_td, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "MBCBE INT32 ");
  // int64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, 6434836983883769530,
                             6434836983883769530, 6434836983883769530,
                             6434836983883769530, 6434836983883769530};
  mint64m1_t i64_ts1 = mlbe64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbcbe_m(i64_ts1);
  msbe64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "MBCBE INT64 ");
  // uint8
  msettype(E8, M1, BA);
  msettileki(2);
  msettileni(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 218u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};
  muint8m1_t u8_ts1 = mlbe8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbcbe_m(u8_ts1);
  msbe8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "MBCBE UINT8 ");
  // uint16
  msettype(E16, M1, BA);
  msettileki(5);
  msettileni(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 42743u, 42743u, 42743u, 42743u,
                              42743u, 42743u, 42743u, 42743u, 42743u,
                              42743u, 42743u, 42743u, 42743u, 42743u};
  muint16m1_t u16_ts1 = mlbe16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbcbe_m(u16_ts1);
  msbe16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "MBCBE UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettileki(1);
  msettileni(5);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlbe32_m1(u32_src, 5 * sizeof(uint32_t));
  muint32m1_t u32_td = mbcbe_m(u32_ts1);
  msbe32_m(u32_td, u32_buffer, 5 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "MBCBE UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 14537392746491786892u,
                              14537392746491786892u, 14537392746491786892u,
                              14537392746491786892u, 14537392746491786892u};
  muint64m1_t u64_ts1 = mlbe64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbcbe_m(u64_ts1);
  msbe64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "MBCBE UINT64");
  // fp16
  msettype(E16, M1, BA);
  msettileki(2);
  msettileni(2);
  const fp16_t fp16_src[] = {-0.611, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {-0.611, -0.611, -0.611, -0.611};
  mfloat16m1_t fp16_ts1 = mlbe16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbcbe_m(fp16_ts1);
  msbe16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, "MBCBE FP16  ");
  // fp32
  msettype(E32, M1, BA);
  msettileki(4);
  msettileni(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f,
                             0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f,
                             0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f};
  mfloat32m1_t fp32_ts1 = mlbe32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbcbe_m(fp32_ts1);
  msbe32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, "MBCBE FP32  ");
  // fp64
  msettype(E64, M1, BA);
  msettileki(3);
  msettileni(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {0.25951296, 0.25951296, 0.25951296,
                             0.25951296, 0.25951296, 0.25951296};
  mfloat64m1_t fp64_ts1 = mlbe64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbcbe_m(fp64_ts1);
  msbe64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, "MBCBE FP64  ");
}

static void test_mbcce_m() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileni(2);
  const int8_t i8_src[] = {-93, -89, 121, -123};
  const int8_t i8_ans[] = {-93, -93, -93, -93};
  mint8m1_t i8_ts1 = mlce8_m1(i8_src, 2 * sizeof(int8_t));
  mint8m1_t i8_td = mbcce_m(i8_ts1);
  msce8_m(i8_td, i8_buffer, 2 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 4, "MBCCE INT8  ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(2);
  const int16_t i16_src[] = {24455, -30160, -20540, 20710, -20540, 20710};
  const int16_t i16_ans[] = {24455, 24455, 24455, 24455, 24455, 24455};
  mint16m1_t i16_ts1 = mlce16_m1(i16_src, 2 * sizeof(int16_t));
  mint16m1_t i16_td = mbcce_m(i16_ts1);
  msce16_m(i16_td, i16_buffer, 2 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 6, "MBCCE INT16 ");
  // int32
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileni(2);
  const int32_t i32_src[] = {-1926070292, 246897081};
  const int32_t i32_ans[] = {-1926070292, -1926070292};
  mint32m1_t i32_ts1 = mlce32_m1(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_td = mbcce_m(i32_ts1);
  msce32_m(i32_td, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 2, "MBCCE INT32 ");
  // int64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileni(2);
  const int64_t i64_src[] = {6434836983883769530, -8148777892508189639,
                             5511953749517690378, -630744233100753856,
                             5511953749517690378, -630744233100753856};
  const int64_t i64_ans[] = {6434836983883769530, 6434836983883769530,
                             6434836983883769530, 6434836983883769530,
                             6434836983883769530, 6434836983883769530};
  mint64m1_t i64_ts1 = mlce64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_td = mbcce_m(i64_ts1);
  msce64_m(i64_td, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 6, "MBCCE INT64 ");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileni(4);
  const uint8_t u8_src[] = {0u, 218u, 216u, 222u, 218u, 0u, 0u, 0u};
  const uint8_t u8_ans[] = {0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};
  muint8m1_t u8_ts1 = mlce8_m1(u8_src, 4 * sizeof(uint8_t));
  muint8m1_t u8_td = mbcce_m(u8_ts1);
  msce8_m(u8_td, u8_buffer, 4 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 8, "MBCCE UINT8 ");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(5);
  msettileni(3);
  const uint16_t u16_src[] = {42743u, 9091u,  8049u,  55208u, 8049u,
                              55208u, 8049u,  55208u, 8049u,  55208u,
                              8049u,  55208u, 8049u,  55208u, 8049u};
  const uint16_t u16_ans[] = {42743u, 42743u, 42743u, 42743u, 42743u,
                              42743u, 42743u, 42743u, 42743u, 42743u,
                              42743u, 42743u, 42743u, 42743u, 42743u};
  muint16m1_t u16_ts1 = mlce16_m1(u16_src, 3 * sizeof(uint16_t));
  muint16m1_t u16_td = mbcce_m(u16_ts1);
  msce16_m(u16_td, u16_buffer, 3 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 15, "MBCCE UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileni(5);
  const uint32_t u32_src[] = {1671532100u, 537437091u, 281802786u, 1841142291u,
                              1841142291u};
  const uint32_t u32_ans[] = {1671532100u, 1671532100u, 1671532100u,
                              1671532100u, 1671532100u};
  muint32m1_t u32_ts1 = mlce32_m1(u32_src, 1 * sizeof(uint32_t));
  muint32m1_t u32_td = mbcce_m(u32_ts1);
  msce32_m(u32_td, u32_buffer, 1 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 5, "MBCCE UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileni(2);
  const uint64_t u64_src[] = {14537392746491786892u, 4875585649773384250u,
                              15478644212105236565u, 11381168778312796626u,
                              2453739374649178682u,  15478644212105236565u};
  const uint64_t u64_ans[] = {14537392746491786892u, 14537392746491786892u,
                              14537392746491786892u, 14537392746491786892u,
                              14537392746491786892u, 14537392746491786892u};
  muint64m1_t u64_ts1 = mlce64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_td = mbcce_m(u64_ts1);
  msce64_m(u64_td, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 6, "MBCCE UINT64");
  // fp16
  msettype(E16, M1, BA);
  msettilemi(2);
  msettileni(2);
  const fp16_t fp16_src[] = {-0.611, -0.611, 0.852, 0.4038};
  const fp16_t fp16_ans[] = {-0.611, -0.611, -0.611, -0.611};
  mfloat16m1_t fp16_ts1 = mlce16_m1(fp16_src, 2 * sizeof(fp16_t));
  mfloat16m1_t fp16_td = mbcce_m(fp16_ts1);
  msce16_m(fp16_td, fp16_buffer, 2 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 4, "MBCCE FP16  ");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(4);
  msettileni(3);
  const fp32_t fp32_src[] = {0.2876706f, 0.25072205f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f,
                             0.552841f,  -1.4288656f, 0.552841f, -1.4288656f};
  const fp32_t fp32_ans[] = {0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f,
                             0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f,
                             0.2876706f, 0.2876706f, 0.2876706f, 0.2876706f};
  mfloat32m1_t fp32_ts1 = mlce32_m1(fp32_src, 3 * sizeof(fp32_t));
  mfloat32m1_t fp32_td = mbcce_m(fp32_ts1);
  msce32_m(fp32_td, fp32_buffer, 3 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 12, "MBCCE FP32  ");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(3);
  msettileni(2);
  const fp64_t fp64_src[] = {0.25951296, -0.22276918, 0.00402457,
                             0.49142913, 0.25951296,  -0.22276918};
  const fp64_t fp64_ans[] = {0.25951296, 0.25951296, 0.25951296,
                             0.25951296, 0.25951296, 0.25951296};
  mfloat64m1_t fp64_ts1 = mlce64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_td = mbcce_m(fp64_ts1);
  msce64_m(fp64_td, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 6, "MBCCE FP64  ");
}

static void test_mmv_x_s() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileni(3);
  const int8_t i8_src[] = {-2, 0, 0, 0, 0, 0, 0, 0, 0};
  mint8m1_t i8_ts = mlce8_m1(i8_src, 3 * sizeof(int8_t));
  int8_t i8_rd = mmv_x_s(i8_ts, 0);
  EXCEPT_I8_SCALAR_EQ(-2, i8_rd, "MMV.X.S INT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(3);
  const int16_t i16_src[] = {0, 0, -200, 0, 0, 0, 0, 0, 0};
  mint16m1_t i16_ts = mlce16_m1(i16_src, 3 * sizeof(int16_t));
  int16_t i16_rd = mmv_x_s(i16_ts, (2 << 16) + 0);
  EXCEPT_I16_SCALAR_EQ(-200, i16_rd, "MMV.X.S INT16");
  // int16
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  const int32_t i32_src[] = {0, 0, 0, -123456};
  mint32m1_t i32_ts = mlce32_m1(i32_src, 2 * sizeof(int32_t));
  int32_t i32_rd = mmv_x_s(i32_ts, (1 << 16) + 1);
  EXCEPT_I16_SCALAR_EQ(-123456, i32_rd, "MMV.X.S INT32");
  // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  const int64_t i64_src[] = {-148971193621062913, -58239145215775087,
                             -84356269946099806, 152190707032328961};
  mint64m1_t i64_ts = mlce64_m1(i64_src, 2 * sizeof(int64_t));
  int64_t i64_rd = mmv_x_s(i64_ts, (0 << 16) + 1);
  EXCEPT_I16_SCALAR_EQ(-84356269946099806, i64_rd, "MMV.X.S INT64");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileni(16);
  const uint8_t u8_src[] = {19, 33, 47, 42, 18, 7,  33, 1,  41, 12, 47,
                            17, 32, 32, 38, 43, 47, 34, 33, 42, 10, 45,
                            3,  44, 4,  8,  14, 19, 19, 34, 4,  10};
  muint8m1_t u8_ts = mlce8_m1(u8_src, 16 * sizeof(uint8_t));
  uint8_t u8_rd = mmv_x_s(u8_ts, (1 << 16) + 0);
  EXCEPT_U8_SCALAR_EQ(33, u8_rd, "MMV.X.S UINT8");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  const uint16_t u16_src[] = {344,  151,  2471, 826,  2738, 2656, 1659, 891,
                              333,  2638, 2742, 2443, 1692, 2205, 1646, 2014,
                              1620, 1820, 1379, 1655, 894,  2043, 1467, 1095};
  muint16m1_t u16_ts = mlce16_m1(u16_src, 8 * sizeof(uint16_t));
  uint16_t u16_rd = mmv_x_s(u16_ts, (5 << 16) + 2);
  EXCEPT_U16_SCALAR_EQ(2043, u16_rd, "MMV.X.S UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(4);
  const uint32_t u32_src[] = {52338693, 108093270, 79881692,  120283666,
                              1161047,  115316564, 136804339, 32185597};
  muint32m1_t u32_ts = mlce32_m1(u32_src, 4 * sizeof(uint32_t));
  uint32_t u32_rd = mmv_x_s(u32_ts, (2 << 16) + 0);
  EXCEPT_U32_SCALAR_EQ(79881692, u32_rd, "MMV.X.S UINT32");
  // uint32
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  const uint64_t u64_src[] = {148971193621062913, 58239145215775087,
                              84356269946099806, 152190707032328961};
  muint64m1_t u64_ts = mlce64_m1(u64_src, 2 * sizeof(uint64_t));
  uint64_t u64_rd = mmv_x_s(u64_ts, (1 << 16) + 1);
  EXCEPT_U32_SCALAR_EQ(152190707032328961, u64_rd, "MMV.X.S UINT64");
}

static void test_mfmv_f_s() {
  // fp16
  msettype(E16, M1, BA);
  msettilemi(5);
  msettileni(5);
  const fp16_t fp16_src[] = {1.019,  1.987,   0.1902,  -0.75,   0.8774,
                             -1.611, -0.5605, -1.137,  -0.1353, 0.75,
                             0.377,  0.2708,  -0.637,  -2.654,  0.978,
                             -0.255, 2.057,   -0.9307, -0.6304, 0.2708,
                             0.706,  -2.465,  -0.1676, 0.647,   0.406};
  mfloat16m1_t fp16_ts = mlce16_m1(fp16_src, 5 * sizeof(fp16_t));
  fp16_t fp16_rd = mfmv_f_s(fp16_ts, (3 << 16) + 3);
  EXCEPT_FP16_SCALAR_EQ(-0.6304, fp16_rd, "MFMV.F.S FP16 ");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileni(4);
  const fp32_t fp32_src[] = {0.15733461, 0.1379579, -0.74867827, 0.19663455};
  mfloat32m1_t fp32_ts = mlce32_m1(fp32_src, 4 * sizeof(fp32_t));
  fp32_t fp32_rd = mfmv_f_s(fp32_ts, (2 << 16) + 0);
  EXCEPT_FP32_SCALAR_EQ(-0.74867827, fp32_rd, "MFMV.F.S FP32 ");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(4);
  msettileni(2);
  const fp64_t fp64_src[] = {-0.23718395, 1.02168045, -0.42744556, -1.36404197,
                             0.18804299,  0.62549579, -0.4737774,  -0.37355439};
  mfloat64m1_t fp64_ts = mlce64_m1(fp64_src, 2 * sizeof(fp64_t));
  fp64_t fp64_rd = mfmv_f_s(fp64_ts, (1 << 16) + 2);
  EXCEPT_FP64_SCALAR_EQ(0.62549579, fp64_rd, "MFMV.F.S FP64 ");
}

static void test_mmv_s_x() {
  // int8
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileni(3);
  const int8_t i8_src[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  const int8_t i8_ans[] = {-2, 0, 0, 0, 0, 0, 0, 0, 0};
  mint8m1_t i8_ts = mlce8_m1(i8_src, 3 * sizeof(int8_t));
  mint8m1_t i8_out = mmv_s_x(i8_ts, -2, (0 << 16) + 0);
  msce8_m(i8_out, i8_buffer, 3 * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(i8_ans, i8_buffer, 9, "MMV.S.X INT8 ");
  // int16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(3);
  const int16_t i16_src[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  const int16_t i16_ans[] = {0, 0, -200, 0, 0, 0, 0, 0, 0};
  mint16m1_t i16_ts = mlce16_m1(i16_src, 3 * sizeof(int16_t));
  mint16m1_t i16_out = mmv_s_x(i16_ts, -200, (2 << 16) + 0);
  msce16_m(i16_out, i16_buffer, 3 * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(i16_ans, i16_buffer, 9, "MMV.S.X INT16");
  // int16
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  const int32_t i32_src[] = {0, 0, 0, 0};
  const int32_t i32_ans[] = {0, 0, 0, -123456};
  mint32m1_t i32_ts = mlce32_m1(i32_src, 2 * sizeof(int32_t));
  mint32m1_t i32_out = mmv_s_x(i32_ts, -123456, (1 << 16) + 1);
  msce32_m(i32_out, i32_buffer, 2 * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(i32_ans, i32_buffer, 4, "MMV.S.X INT32");
  // // int64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  const int64_t i64_src[] = {-148971193621062913, -58239145215775087, 0,
                             152190707032328961};
  const int64_t i64_ans[] = {-148971193621062913, -58239145215775087,
                             -84356269946099806, 152190707032328961};
  mint64m1_t i64_ts = mlce64_m1(i64_src, 2 * sizeof(int64_t));
  mint64m1_t i64_out = mmv_s_x(i64_ts, -84356269946099806, (0 << 16) + 1);
  msce64_m(i64_out, i64_buffer, 2 * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(i64_ans, i64_buffer, 4, "MMV.S.X INT64");
  // uint8
  msettype(E8, M1, BA);
  msettilemi(2);
  msettileni(16);
  const uint8_t u8_src[] = {19, 0,  47, 42, 18, 7,  33, 1,  41, 12, 47,
                            17, 32, 32, 38, 43, 47, 34, 33, 42, 10, 45,
                            3,  44, 4,  8,  14, 19, 19, 34, 4,  10};
  const uint8_t u8_ans[] = {19, 33, 47, 42, 18, 7,  33, 1,  41, 12, 47,
                            17, 32, 32, 38, 43, 47, 34, 33, 42, 10, 45,
                            3,  44, 4,  8,  14, 19, 19, 34, 4,  10};
  muint8m1_t u8_ts = mlce8_m1(u8_src, 16 * sizeof(uint8_t));
  muint8m1_t u8_out = mmv_s_x(u8_ts, 33, (1 << 16) + 0);
  msce8_m(u8_out, u8_buffer, 16 * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(u8_ans, u8_buffer, 32, "MMV.S.X UINT8");
  // uint16
  msettype(E16, M1, BA);
  msettilemi(3);
  msettileni(8);
  const uint16_t u16_src[] = {344,  151,  2471, 826,  2738, 2656, 1659, 891,
                              333,  2638, 2742, 2443, 1692, 2205, 1646, 2014,
                              1620, 1820, 1379, 1655, 894,  0,    1467, 1095};
  const uint16_t u16_ans[] = {344,  151,  2471, 826,  2738, 2656, 1659, 891,
                              333,  2638, 2742, 2443, 1692, 2205, 1646, 2014,
                              1620, 1820, 1379, 1655, 894,  2043, 1467, 1095};
  muint16m1_t u16_ts = mlce16_m1(u16_src, 8 * sizeof(uint16_t));
  muint16m1_t u16_out = mmv_s_x(u16_ts, 2043, (5 << 16) + 2);
  msce16_m(u16_out, u16_buffer, 8 * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(u16_ans, u16_buffer, 24, "MMV.S.X UINT16");
  // uint32
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(4);
  const uint32_t u32_src[] = {52338693, 108093270, 0,         120283666,
                              1161047,  115316564, 136804339, 32185597};
  const uint32_t u32_ans[] = {52338693, 108093270, 79881692,  120283666,
                              1161047,  115316564, 136804339, 32185597};
  muint32m1_t u32_ts = mlce32_m1(u32_src, 4 * sizeof(uint32_t));
  muint32m1_t u32_out = mmv_s_x(u32_ts, 79881692, (2 << 16) + 0);
  msce32_m(u32_out, u32_buffer, 4 * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(u32_ans, u32_buffer, 8, "MMV.S.X UINT32");
  // uint64
  msettype(E64, M1, BA);
  msettilemi(2);
  msettileni(2);
  const uint64_t u64_src[] = {148971193621062913, 58239145215775087,
                              84356269946099806, 0};
  const uint64_t u64_ans[] = {148971193621062913, 58239145215775087,
                              84356269946099806, 152190707032328961};
  muint64m1_t u64_ts = mlce64_m1(u64_src, 2 * sizeof(uint64_t));
  muint64m1_t u64_out = mmv_s_x(u64_ts, 152190707032328961, (1 << 16) + 1);
  msce64_m(u64_out, u64_buffer, 2 * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(u64_ans, u64_buffer, 4, "MMV.S.X UINT64");
}

static void test_mfmv_s_f() {
  // fp16
  msettype(E16, M1, BA);
  msettilemi(5);
  msettileni(5);
  const fp16_t fp16_src[] = {
      1.019, 1.987,  0.1902, -0.75,  0.8774,  -1.611, -0.5605, -1.137, -0.1353,
      0.75,  0.377,  0.2708, -0.637, -2.654,  0.978,  -0.255,  2.057,  -0.9307,
      0,     0.2708, 0.706,  -2.465, -0.1676, 0.647,  0.406};
  const fp16_t fp16_ans[] = {1.019,  1.987,   0.1902,  -0.75,   0.8774,
                             -1.611, -0.5605, -1.137,  -0.1353, 0.75,
                             0.377,  0.2708,  -0.637,  -2.654,  0.978,
                             -0.255, 2.057,   -0.9307, -0.6304, 0.2708,
                             0.706,  -2.465,  -0.1676, 0.647,   0.406};
  mfloat16m1_t fp16_ts = mlce16_m1(fp16_src, 5 * sizeof(fp16_t));
  mfloat16m1_t fp16_out = mfmv_s_f(fp16_ts, -0.6304, (3 << 16) + 3);
  msce16_m(fp16_out, fp16_buffer, 5 * sizeof(fp16_t));
  EXCEPT_FP16_ARRAY_EQ(fp16_ans, fp16_buffer, 25, "MFMV.S.F FP16");
  // fp32
  msettype(E32, M1, BA);
  msettilemi(1);
  msettileni(4);
  const fp32_t fp32_src[] = {0.15733461, 0.1379579, 0, 0.19663455};
  const fp32_t fp32_ans[] = {0.15733461, 0.1379579, -0.74867827, 0.19663455};
  mfloat32m1_t fp32_ts = mlce32_m1(fp32_src, 4 * sizeof(fp32_t));
  mfloat32m1_t fp32_out = mfmv_s_f(fp32_ts, -0.74867827, (2 << 16) + 0);
  msce32_m(fp32_out, fp32_buffer, 4 * sizeof(fp32_t));
  EXCEPT_FP32_ARRAY_EQ(fp32_ans, fp32_buffer, 4, "MFMV.S.F FP32");
  // fp64
  msettype(E64, M1, BA);
  msettilemi(4);
  msettileni(2);
  const fp64_t fp64_src[] = {-0.23718395, 1.02168045, -0.42744556, -1.36404197,
                             0.18804299,  0,          -0.4737774,  -0.37355439};
  const fp64_t fp64_ans[] = {-0.23718395, 1.02168045, -0.42744556, -1.36404197,
                             0.18804299,  0.62549579, -0.4737774,  -0.37355439};
  mfloat64m1_t fp64_ts = mlce64_m1(fp64_src, 2 * sizeof(fp64_t));
  mfloat64m1_t fp64_out = mfmv_s_f(fp64_ts, 0.62549579, (1 << 16) + 2);
  msce64_m(fp64_out, fp64_buffer, 2 * sizeof(fp64_t));
  EXCEPT_FP64_ARRAY_EQ(fp64_ans, fp64_buffer, 8, "MFMV.S.F FP64");
}

int main() {
  test_mmv_x_s();
  test_mfmv_f_s();
  test_mmv_s_x();
  test_mfmv_s_f();
  test_mbcar_m();
  test_mbcbr_m();
  test_mbccr_m();
  test_mbcac_m();
  test_mbcbc_m();
  test_mbccc_m();
  test_mbcae_m();
  test_mbcbe_m();
  test_mbcce_m();
  return 0;
}