#include "load_store.h"
#include "riscv_matrix.h"
#include "riscv_vector.h"
#include "utils.h"

extern const int8_t ls_i8_src[];
extern const uint8_t ls_u8_src[];
extern const int16_t ls_i16_src[];
extern const uint16_t ls_u16_src[];
extern const fp16_t ls_f16_src[];
extern const int32_t ls_i32_src[];
extern const uint32_t ls_u32_src[];
extern const fp32_t ls_f32_src[];
extern const int64_t ls_i64_src[];
extern const uint64_t ls_u64_src[];
extern const fp64_t ls_f64_src[];

static void test_mmv_x_t_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  mint8_t md = mla_m(ls_i8_src, K * sizeof(int8_t));
  int8_t rd = mmv_x_t(md, idx);
  EXCEPT_I8_SCALAR_EQ(ls_i8_src[i * K + j], rd, "MMV_X_T i8");
}

static void test_mmv_x_t_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  muint8_t md = mla_m(ls_u8_src, K * sizeof(uint8_t));
  uint8_t rd = mmv_x_t(md, idx);
  EXCEPT_U8_SCALAR_EQ(ls_u8_src[i * K + j], rd, "MMV_X_T U8");
}

static void test_mmv_x_t_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  mint16_t md = mla_m(ls_i16_src, K * sizeof(int16_t));
  int16_t rd = mmv_x_t(md, idx);
  EXCEPT_I16_SCALAR_EQ(ls_i16_src[i * K + j], rd, "MMV_X_T I16");
}

static void test_mmv_x_t_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  muint16_t md = mla_m(ls_u16_src, K * sizeof(uint16_t));
  uint16_t rd = mmv_x_t(md, idx);
  EXCEPT_U16_SCALAR_EQ(ls_u16_src[i * K + j], rd, "MMV_X_T U16");
}

static void test_mmv_x_t_i32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  mint32_t md = mla_m(ls_i32_src, K * sizeof(int32_t));
  int32_t rd = mmv_x_t(md, idx);
  EXCEPT_I32_SCALAR_EQ(ls_i32_src[i * K + j], rd, "MMV_X_T I32");
}

static void test_mmv_x_t_u32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  muint32_t md = mla_m(ls_u32_src, K * sizeof(uint32_t));
  uint32_t rd = mmv_x_t(md, idx);
  EXCEPT_U32_SCALAR_EQ(ls_u32_src[i * K + j], rd, "MMV_X_T U32");
}

static void test_mmv_x_t_i64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  mint64_t md = mla_m(ls_i64_src, K * sizeof(int64_t));
  int64_t rd = mmv_x_t(md, idx);
  EXCEPT_I64_SCALAR_EQ(ls_i64_src[i * K + j], rd, "MMV_X_T I64");
}

static void test_mmv_x_t_u64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  muint64_t md = mla_m(ls_u64_src, K * sizeof(uint64_t));
  uint64_t rd = mmv_x_t(md, idx);
  EXCEPT_U64_SCALAR_EQ(ls_u64_src[i * K + j], rd, "MMV_X_T U64");
}

static void test_mmv_t_x_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  mint8_t md = mla_m(ls_i8_src, K * sizeof(int8_t));
  md = mmv_t_x(md, rs, idx);
  msa_m(md, i8_buffer, K * sizeof(int8_t));
  EXCEPT_I8_SCALAR_EQ(rs, i8_buffer[i * K + j], "MMV_T_X I8");
}

static void test_mmv_t_x_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  muint8_t md = mla_m(ls_u8_src, K * sizeof(uint8_t));
  md = mmv_t_x(md, rs, idx);
  msa_m(md, u8_buffer, K * sizeof(uint8_t));
  EXCEPT_U8_SCALAR_EQ(rs, u8_buffer[i * K + j], "MMV_T_X U8");
}

static void test_mmv_t_x_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  mint16_t md = mla_m(ls_i16_src, K * sizeof(int16_t));
  md = mmv_t_x(md, rs, idx);
  msa_m(md, i16_buffer, K * sizeof(int16_t));
  EXCEPT_I16_SCALAR_EQ(rs, i16_buffer[i * K + j], "MMV_T_X I16");
}

static void test_mmv_t_x_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  muint16_t md = mla_m(ls_u16_src, K * sizeof(uint16_t));
  md = mmv_t_x(md, rs, idx);
  msa_m(md, u16_buffer, K * sizeof(uint16_t));
  EXCEPT_U16_SCALAR_EQ(rs, u16_buffer[i * K + j], "MMV_T_X U16");
}

static void test_mmv_t_x_i32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  mint32_t md = mla_m(ls_i32_src, K * sizeof(int32_t));
  md = mmv_t_x(md, rs, idx);
  msa_m(md, i32_buffer, K * sizeof(int32_t));
  EXCEPT_I32_SCALAR_EQ(rs, i32_buffer[i * K + j], "MMV_T_X I32");
}

static void test_mmv_t_x_u32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  muint32_t md = mla_m(ls_u32_src, K * sizeof(uint32_t));
  md = mmv_t_x(md, rs, idx);
  msa_m(md, u32_buffer, K * sizeof(uint32_t));
  EXCEPT_U32_SCALAR_EQ(rs, u32_buffer[i * K + j], "MMV_T_X U32");
}

static void test_mmv_t_x_i64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  mint64_t md = mla_m(ls_i64_src, K * sizeof(int64_t));
  md = mmv_t_x(md, rs, idx);
  msa_m(md, i64_buffer, K * sizeof(int64_t));
  EXCEPT_I64_SCALAR_EQ(rs, i64_buffer[i * K + j], "MMV_T_X I64");
}

static void test_mmv_t_x_u64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  muint64_t md = mla_m(ls_u64_src, K * sizeof(uint64_t));
  md = mmv_t_x(md, rs, idx);
  msa_m(md, u64_buffer, K * sizeof(uint64_t));
  EXCEPT_U64_SCALAR_EQ(rs, u64_buffer[i * K + j], "MMV_T_X U64");
}

static void test_mmv_x_a_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t md = mlc_m(ls_i8_src, N * sizeof(int8_t));
  int8_t rd = mmv_x_a(md, idx);
  EXCEPT_I8_SCALAR_EQ(ls_i8_src[i * N + j], rd, "MMV_X_A i8");
}

static void test_mmv_x_a_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t md = mlc_m(ls_u8_src, N * sizeof(uint8_t));
  uint8_t rd = mmv_x_a(md, idx);
  EXCEPT_U8_SCALAR_EQ(ls_u8_src[i * N + j], rd, "MMV_X_A U8");
}

static void test_mmv_x_a_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t md = mlc_m(ls_i16_src, N * sizeof(int16_t));
  int16_t rd = mmv_x_a(md, idx);
  EXCEPT_I16_SCALAR_EQ(ls_i16_src[i * N + j], rd, "MMV_X_A I16");
}

static void test_mmv_x_a_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t md = mlc_m(ls_u16_src, N * sizeof(uint16_t));
  uint16_t rd = mmv_x_a(md, idx);
  EXCEPT_U16_SCALAR_EQ(ls_u16_src[i * N + j], rd, "MMV_X_A U16");
}

static void test_mmv_x_a_i32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t md = mlc_m(ls_i32_src, N * sizeof(int32_t));
  int32_t rd = mmv_x_a(md, idx);
  EXCEPT_I32_SCALAR_EQ(ls_i32_src[i * N + j], rd, "MMV_X_A I32");
}

static void test_mmv_x_a_u32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t md = mlc_m(ls_u32_src, N * sizeof(uint32_t));
  uint32_t rd = mmv_x_a(md, idx);
  EXCEPT_U32_SCALAR_EQ(ls_u32_src[i * N + j], rd, "MMV_X_A U32");
}

static void test_mmv_x_a_i64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t md = mlc_m(ls_i64_src, N * sizeof(int64_t));
  int64_t rd = mmv_x_a(md, idx);
  EXCEPT_I64_SCALAR_EQ(ls_i64_src[i * N + j], rd, "MMV_X_A I64");
}

static void test_mmv_x_a_u64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t md = mlc_m(ls_u64_src, N * sizeof(uint64_t));
  uint64_t rd = mmv_x_a(md, idx);
  EXCEPT_U64_SCALAR_EQ(ls_u64_src[i * N + j], rd, "MMV_X_A U64");
}

static void test_mmv_a_x_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t md = mlc_m(ls_i8_src, N * sizeof(int8_t));
  md = mmv_a_x(md, rs, idx);
  msc_m(md, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_SCALAR_EQ(rs, i8_buffer[i * N + j], "MMV_A_X I8");
}

static void test_mmv_a_x_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t md = mlc_m(ls_u8_src, N * sizeof(uint8_t));
  md = mmv_a_x(md, rs, idx);
  msc_m(md, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_SCALAR_EQ(rs, u8_buffer[i * N + j], "MMV_A_X U8");
}

static void test_mmv_a_x_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t md = mlc_m(ls_i16_src, N * sizeof(int16_t));
  md = mmv_a_x(md, rs, idx);
  msc_m(md, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_SCALAR_EQ(rs, i16_buffer[i * N + j], "MMV_A_X I16");
}

static void test_mmv_a_x_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t md = mlc_m(ls_u16_src, N * sizeof(uint16_t));
  md = mmv_a_x(md, rs, idx);
  msc_m(md, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_SCALAR_EQ(rs, u16_buffer[i * N + j], "MMV_A_X U16");
}

static void test_mmv_a_x_i32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t md = mlc_m(ls_i32_src, N * sizeof(int32_t));
  md = mmv_a_x(md, rs, idx);
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_SCALAR_EQ(rs, i32_buffer[i * N + j], "MMV_A_X I32");
}

static void test_mmv_a_x_u32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t md = mlc_m(ls_u32_src, N * sizeof(uint32_t));
  md = mmv_a_x(md, rs, idx);
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_SCALAR_EQ(rs, u32_buffer[i * N + j], "MMV_A_X U32");
}

static void test_mmv_a_x_i64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t md = mlc_m(ls_i64_src, N * sizeof(int64_t));
  md = mmv_a_x(md, rs, idx);
  msc_m(md, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_SCALAR_EQ(rs, i64_buffer[i * N + j], "MMV_A_X I64");
}

static void test_mmv_a_x_u64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  int8_t rs = 0;
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t md = mlc_m(ls_u64_src, N * sizeof(uint64_t));
  md = mmv_a_x(md, rs, idx);
  msc_m(md, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_SCALAR_EQ(rs, u64_buffer[i * N + j], "MMV_A_X U64");
}

static void test_mfmv_f_t_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  mfloat16_t ms = mla_m(ls_f16_src, K * sizeof(fp16_t));
  fp16_t rd = mfmv_f_t(ms, idx);
  EXCEPT_F16_SCALAR_EQ(ls_f16_src[i * K + j], rd, "MFMV_F_T F16");
}

static void test_mfmv_f_t_f32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  mfloat32_t ms = mla_m(ls_f32_src, K * sizeof(fp32_t));
  fp32_t rd = mfmv_f_t(ms, idx);
  EXCEPT_F32_SCALAR_EQ(ls_f32_src[i * K + j], rd, "MFMV_F_T F32");
}

static void test_mfmv_f_t_f64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  mfloat64_t ms = mla_m(ls_f64_src, K * sizeof(fp64_t));
  fp64_t rd = mfmv_f_t(ms, idx);
  EXCEPT_F64_SCALAR_EQ(ls_f64_src[i * K + j], rd, "MFMV_F_T F64");
}

static void test_mfmv_t_f_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  fp16_t rs = 0.0;
  mfloat16_t ms = mla_m(ls_f16_src, K * sizeof(fp16_t));
  mfloat16_t md = mfmv_t_f(ms, rs, idx);
  msa_m(md, f16_buffer, K * sizeof(fp16_t));
  EXCEPT_F16_SCALAR_EQ(f16_buffer[i * K + j], rs, "MFMV_T_F F16");
}

static void test_mfmv_t_f_f32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t i = 0;
  const size_t j = 0;
  const size_t idx = j << 16 | i;
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  fp32_t rs = 0.0;
  mfloat32_t ms = mla_m(ls_f32_src, K * sizeof(fp32_t));
  mfloat32_t md = mfmv_t_f(ms, rs, idx);
  msa_m(md, f32_buffer, K * sizeof(fp32_t));
  EXCEPT_F32_SCALAR_EQ(rs, f32_buffer[i * K + j], "MFMV_T_F F32");
}

static void test_mfmv_t_f_f64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t i = 0;
  const size_t j = 0;
  const size_t idx = j << 16 | i;
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  fp64_t rs = 0.0;
  mfloat64_t ms = mla_m(ls_f64_src, K * sizeof(fp64_t));
  mfloat64_t md = mfmv_t_f(ms, rs, idx);
  msa_m(md, f64_buffer, K * sizeof(fp64_t));
  EXCEPT_F64_SCALAR_EQ(rs, f64_buffer[i * K + j], "MFMV_T_F F64");
}

static void test_mfmv_f_a_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(ls_f16_src, N * sizeof(fp16_t));
  fp16_t rd = mfmv_f_a(ms, idx);
  EXCEPT_F16_SCALAR_EQ(ls_f16_src[i * N + j], rd, "MFMV_F_A F16");
}

static void test_mfmv_f_a_f32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(ls_f32_src, N * sizeof(fp32_t));
  fp32_t rd = mfmv_f_a(ms, idx);
  EXCEPT_F32_SCALAR_EQ(ls_f32_src[i * N + j], rd, "MFMV_F_A F32");
}

static void test_mfmv_f_a_f64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(ls_f64_src, N * sizeof(fp64_t));
  fp64_t rd = mfmv_f_a(ms, idx);
  EXCEPT_F64_SCALAR_EQ(ls_f64_src[i * N + j], rd, "MFMV_F_A F64");
}

static void test_mfmv_a_f_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t i = 1;
  const size_t j = 1;
  const size_t idx = j << 16 | i;
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  fp16_t rs = 0.0;
  mfloat16_t ms = mlc_m(ls_f16_src, N * sizeof(fp16_t));
  mfloat16_t md = mfmv_a_f(ms, rs, idx);
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_SCALAR_EQ(f16_buffer[i * N + j], rs, "MFMV_A_F F16");
}

static void test_mfmv_a_f_f32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t i = 0;
  const size_t j = 0;
  const size_t idx = j << 16 | i;
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  fp32_t rs = 0.0;
  mfloat32_t ms = mlc_m(ls_f32_src, N * sizeof(fp32_t));
  mfloat32_t md = mfmv_a_f(ms, rs, idx);
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_SCALAR_EQ(rs, f32_buffer[i * N + j], "MFMV_A_F F32");
}

static void test_mfmv_a_f_f64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t i = 0;
  const size_t j = 0;
  const size_t idx = j << 16 | i;
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  fp64_t rs = 0.0;
  mfloat64_t ms = mlc_m(ls_f64_src, N * sizeof(fp64_t));
  mfloat64_t md = mfmv_a_f(ms, rs, idx);
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_SCALAR_EQ(rs, f64_buffer[i * N + j], "MFMV_A_F F64");
}

static void test_mbcar_m_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int8_t);
  const int8_t src[] = {
      -16,  92,  67,   97,   110,  -101, -94,  -120, 59,  -69,  74,  -31,  47,
      -70,  -79, -102, -106, 102,  -71,  -36,  69,   -82, 56,   -62, -123, -111,
      -54,  -10, -66,  65,   -114, 70,   -91,  -101, 32,  -2,   54,  -78,  -84,
      -111, -55, 21,   -125, 110,  -82,  116,  -52,  115, 53,   -19, -43,  -90,
      66,   -43, 68,   -91,  -22,  71,   -105, -22,  53,  -117, 99,  -102};
  const int8_t ans[] = {-16, 92,   67,  97,   110, -101, -94, -120, -16, 92,
                        67,  97,   110, -101, -94, -120, -16, 92,   67,  97,
                        110, -101, -94, -120, -16, 92,   67,  97,   110, -101,
                        -94, -120, -16, 92,   67,  97,   110, -101, -94, -120,
                        -16, 92,   67,  97,   110, -101, -94, -120, -16, 92,
                        67,  97,   110, -101, -94, -120, -16, 92,   67,  97,
                        110, -101, -94, -120};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  mint8_t ms = mla_m(src, stride);
  mint8_t md = mbcar_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAR_M I8");
}

static void test_mbcar_m_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int16_t);
  const int16_t src[] = {
      15201,  -2831,  -6147,  -6633,  -32109, -11225, -14860, 17339,
      28688,  6535,   17494,  6808,   19992,  31211,  28099,  4190,
      -21248, 8753,   -10582, 2583,   -13635, -18992, -15439, 6183,
      -24237, 25564,  -16502, -22020, -4233,  26059,  18253,  -27407,
      -15449, 30269,  16085,  9062,   -27516, -24120, 22893,  -25381,
      4429,   -9466,  9869,   31759,  -6344,  -18625, 12694,  29455,
      10151,  -21830, -24131, 22570,  548,    -15236, 23724,  27166,
      -24634, -18747, -11976, 28516,  -24009, -29320, -30766, -22612};
  const int16_t ans[] = {
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  mint16_t ms = mla_m(src, stride);
  mint16_t md = mbcar_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAR_M I16");
}

static void test_mbcar_m_i32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t stride = K * sizeof(int32_t);
  const int32_t src[] = {51,  -84, -60, -69,  90, 64,  108, -33, 41,  -128, 104,
                         -91, -50, -21, -108, 96, -50, 12,  0,   79,  76,   71,
                         -11, -42, 125, -19,  45, -90, -65, -72, -31, -48};
  const int32_t ans[] = {51,  -84, -60, -69, 51,  -84, -60, -69, 51,  -84, -60,
                         -69, 51,  -84, -60, -69, 51,  -84, -60, -69, 51,  -84,
                         -60, -69, 51,  -84, -60, -69, 51,  -84, -60, -69};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  mint32_t ms = mla_m(src, stride);
  mint32_t md = mbcar_m(ms);
  msa_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * K, "MBCAR_M I32");
}

static void test_mbcar_m_i64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t stride = K * sizeof(int64_t);
  const int64_t src[] = {
      -288638290585882465,  8414534375980690514,  5002374321994383021,
      7660761451024244961,  2905743593751978506,  3257976101533724818,
      5635219952005465293,  -3827488192872744063, 7801927937995075119,
      5525483314066061961,  -4903133312877549309, 5606667384026231531,
      -1656829462281398960, -3523114794377170454, 915704963740964058,
      1904000330114378145};
  const int64_t ans[] = {
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514, -288638290585882465, 8414534375980690514,
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514, -288638290585882465, 8414534375980690514,
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  mint64_t ms = mla_m(src, stride);
  mint64_t md = mbcar_m(ms);
  msa_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * K, "MBCAR_M I64");
}

static void test_mbcbr_m_i8() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  const int8_t src[] = {
      -16,  92,  67,   97,   110,  -101, -94,  -120, 59,  -69,  74,  -31,  47,
      -70,  -79, -102, -106, 102,  -71,  -36,  69,   -82, 56,   -62, -123, -111,
      -54,  -10, -66,  65,   -114, 70,   -91,  -101, 32,  -2,   54,  -78,  -84,
      -111, -55, 21,   -125, 110,  -82,  116,  -52,  115, 53,   -19, -43,  -90,
      66,   -43, 68,   -91,  -22,  71,   -105, -22,  53,  -117, 99,  -102};
  const int8_t ans[] = {-16, 92,   67,  97,   110, -101, -94, -120, -16, 92,
                        67,  97,   110, -101, -94, -120, -16, 92,   67,  97,
                        110, -101, -94, -120, -16, 92,   67,  97,   110, -101,
                        -94, -120, -16, 92,   67,  97,   110, -101, -94, -120,
                        -16, 92,   67,  97,   110, -101, -94, -120, -16, 92,
                        67,  97,   110, -101, -94, -120, -16, 92,   67,  97,
                        110, -101, -94, -120};
  SET_MBA0_I8();
  msettilek(K);
  msettilen(N);
  mint8_t ms = mlb_m(src, stride);
  mint8_t md = mbcbr_m(ms);
  msb_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, K * N, "MBCBR_M I8");
}

static void test_mbcbr_m_i16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  const int16_t src[] = {
      15201,  -2831,  -6147,  -6633,  -32109, -11225, -14860, 17339,
      28688,  6535,   17494,  6808,   19992,  31211,  28099,  4190,
      -21248, 8753,   -10582, 2583,   -13635, -18992, -15439, 6183,
      -24237, 25564,  -16502, -22020, -4233,  26059,  18253,  -27407,
      -15449, 30269,  16085,  9062,   -27516, -24120, 22893,  -25381,
      4429,   -9466,  9869,   31759,  -6344,  -18625, 12694,  29455,
      10151,  -21830, -24131, 22570,  548,    -15236, 23724,  27166,
      -24634, -18747, -11976, 28516,  -24009, -29320, -30766, -22612};
  const int16_t ans[] = {
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339};
  SET_MBA0_I16();
  msettilek(K);
  msettilen(N);
  mint16_t ms = mlb_m(src, stride);
  mint16_t md = mbcbr_m(ms);
  msb_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, K * N, "MBCBR_M I16");
}

static void test_mbcbr_m_i32() {
  const size_t K = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  const int32_t src[] = {51,  -84, -60, -69,  90, 64,  108, -33, 41,  -128, 104,
                         -91, -50, -21, -108, 96, -50, 12,  0,   79,  76,   71,
                         -11, -42, 125, -19,  45, -90, -65, -72, -31, -48};
  const int32_t ans[] = {51,  -84, -60, -69, 51,  -84, -60, -69, 51,  -84, -60,
                         -69, 51,  -84, -60, -69, 51,  -84, -60, -69, 51,  -84,
                         -60, -69, 51,  -84, -60, -69, 51,  -84, -60, -69};
  SET_MBA0_I32();
  msettilek(K);
  msettilen(N);
  mint32_t ms = mlb_m(src, stride);
  mint32_t md = mbcbr_m(ms);
  msb_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, K * N, "MBCBR_M I32");
}

static void test_mbcbr_m_i64() {
  const size_t K = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  const int64_t src[] = {
      -288638290585882465,  8414534375980690514,  5002374321994383021,
      7660761451024244961,  2905743593751978506,  3257976101533724818,
      5635219952005465293,  -3827488192872744063, 7801927937995075119,
      5525483314066061961,  -4903133312877549309, 5606667384026231531,
      -1656829462281398960, -3523114794377170454, 915704963740964058,
      1904000330114378145};
  const int64_t ans[] = {
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514, -288638290585882465, 8414534375980690514,
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514, -288638290585882465, 8414534375980690514,
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514};
  SET_MBA0_I64();
  msettilek(K);
  msettilen(N);
  mint64_t ms = mlb_m(src, stride);
  mint64_t md = mbcbr_m(ms);
  msb_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, K * N, "MBCBR_M I64");
}

static void test_mbccr_m_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  const int8_t src[] = {
      -16,  92,  67,   97,   110,  -101, -94,  -120, 59,  -69,  74,  -31,  47,
      -70,  -79, -102, -106, 102,  -71,  -36,  69,   -82, 56,   -62, -123, -111,
      -54,  -10, -66,  65,   -114, 70,   -91,  -101, 32,  -2,   54,  -78,  -84,
      -111, -55, 21,   -125, 110,  -82,  116,  -52,  115, 53,   -19, -43,  -90,
      66,   -43, 68,   -91,  -22,  71,   -105, -22,  53,  -117, 99,  -102};
  const int8_t ans[] = {-16, 92,   67,  97,   110, -101, -94, -120, -16, 92,
                        67,  97,   110, -101, -94, -120, -16, 92,   67,  97,
                        110, -101, -94, -120, -16, 92,   67,  97,   110, -101,
                        -94, -120, -16, 92,   67,  97,   110, -101, -94, -120,
                        -16, 92,   67,  97,   110, -101, -94, -120, -16, 92,
                        67,  97,   110, -101, -94, -120, -16, 92,   67,  97,
                        110, -101, -94, -120};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, stride);
  mint8_t md = mbccr_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCR_M I8");
}

static void test_mbccr_m_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  const int16_t src[] = {
      15201,  -2831,  -6147,  -6633,  -32109, -11225, -14860, 17339,
      28688,  6535,   17494,  6808,   19992,  31211,  28099,  4190,
      -21248, 8753,   -10582, 2583,   -13635, -18992, -15439, 6183,
      -24237, 25564,  -16502, -22020, -4233,  26059,  18253,  -27407,
      -15449, 30269,  16085,  9062,   -27516, -24120, 22893,  -25381,
      4429,   -9466,  9869,   31759,  -6344,  -18625, 12694,  29455,
      10151,  -21830, -24131, 22570,  548,    -15236, 23724,  27166,
      -24634, -18747, -11976, 28516,  -24009, -29320, -30766, -22612};
  const int16_t ans[] = {
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339,
      15201, -2831, -6147, -6633, -32109, -11225, -14860, 17339};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, stride);
  mint16_t md = mbccr_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCR_M I16");
}

static void test_mbccr_m_i32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  const int32_t src[] = {51,  -84, -60, -69,  90, 64,  108, -33, 41,  -128, 104,
                         -91, -50, -21, -108, 96, -50, 12,  0,   79,  76,   71,
                         -11, -42, 125, -19,  45, -90, -65, -72, -31, -48};
  const int32_t ans[] = {51,  -84, -60, -69, 51,  -84, -60, -69, 51,  -84, -60,
                         -69, 51,  -84, -60, -69, 51,  -84, -60, -69, 51,  -84,
                         -60, -69, 51,  -84, -60, -69, 51,  -84, -60, -69};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, stride);
  mint32_t md = mbccr_m(ms);
  msc_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MBCCR_M I32");
}

static void test_mbccr_m_i64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  const int64_t src[] = {
      -288638290585882465,  8414534375980690514,  5002374321994383021,
      7660761451024244961,  2905743593751978506,  3257976101533724818,
      5635219952005465293,  -3827488192872744063, 7801927937995075119,
      5525483314066061961,  -4903133312877549309, 5606667384026231531,
      -1656829462281398960, -3523114794377170454, 915704963740964058,
      1904000330114378145};
  const int64_t ans[] = {
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514, -288638290585882465, 8414534375980690514,
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514, -288638290585882465, 8414534375980690514,
      -288638290585882465, 8414534375980690514, -288638290585882465,
      8414534375980690514};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, stride);
  mint64_t md = mbccr_m(ms);
  msc_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MBCCR_M I64");
}

static void test_mbcar_m_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint8_t);
  const uint8_t src[] = {133, 67,  188, 240, 149, 99,  74,  155, 35,  139, 72,
                         20,  21,  91,  249, 127, 0,   67,  31,  62,  231, 71,
                         177, 117, 85,  183, 44,  215, 211, 10,  210, 86,  239,
                         228, 201, 62,  171, 162, 101, 33,  76,  86,  142, 41,
                         83,  63,  119, 10,  54,  219, 218, 228, 184, 157, 194,
                         59,  186, 189, 114, 186, 223, 108, 30,  151};
  const uint8_t ans[] = {
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  muint8_t ms = mla_m(src, stride);
  muint8_t md = mbcar_m(ms);
  msa_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * K, "MBCAR_M U8");
}

static void test_mbcar_m_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint16_t);
  const uint16_t src[] = {
      1871,  64117, 62734, 9297,  34140, 19873, 25012, 37719, 23522, 36431,
      18171, 32208, 4451,  47495, 63000, 24,    60901, 64880, 24482, 7889,
      59925, 41041, 43290, 8057,  57222, 669,   21107, 41952, 54240, 15091,
      65504, 49143, 22685, 56337, 16152, 56526, 7947,  13017, 58922, 16451,
      46517, 63047, 39926, 65353, 62195, 19322, 15699, 12638, 7256,  36942,
      53137, 52697, 30136, 45794, 3982,  4120,  34018, 944,   25140, 57497,
      46416, 32268, 9622,  41890};
  const uint16_t ans[] = {1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  muint16_t ms = mla_m(src, stride);
  muint16_t md = mbcar_m(ms);
  msa_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, M * K, "MBCAR_M U16");
}

static void test_mbcar_m_u32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t stride = K * sizeof(uint32_t);
  const uint32_t src[] = {
      104379910,  3019007360, 438798631,  1841583368, 1592927650, 941522289,
      1886382805, 2783564960, 3692430469, 1852682804, 3178010475, 3277374684,
      3748316551, 2609733232, 3459291143, 2946899571, 2219844739, 2372224847,
      1571077476, 222650655,  3525439780, 3549862802, 3360162577, 663877024,
      2354742351, 3729951427, 976076110,  4033555232, 4171633750, 3027486024,
      3888997953, 2173874754};
  const uint32_t ans[] = {
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368, 104379910, 3019007360, 438798631, 1841583368,
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368, 104379910, 3019007360, 438798631, 1841583368,
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  muint32_t ms = mla_m(src, stride);
  muint32_t md = mbcar_m(ms);
  msa_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * K, "MBCAR_M U32");
}

static void test_mbcar_m_u64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t stride = K * sizeof(uint64_t);
  const uint64_t src[] = {
      16347387788243600761, 15073635922616989291, 14391479479577944355,
      2058821884535156258,  4463241850410397957,  3169148459009399821,
      12153685519839682343, 8197704767014005803,  103217090143275429,
      3555615660525631887,  10341798841844766871, 1632229831863916592,
      86107908927148041,    2288898801364535644,  10668287436207437854,
      8931633472857564474};
  const uint64_t ans[] = {
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291, 16347387788243600761, 15073635922616989291,
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291, 16347387788243600761, 15073635922616989291,
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  muint64_t ms = mla_m(src, stride);
  muint64_t md = mbcar_m(ms);
  msa_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * K, "MBCAR_M U64");
}

static void test_mbcbr_m_u8() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  const uint8_t src[] = {133, 67,  188, 240, 149, 99,  74,  155, 35,  139, 72,
                         20,  21,  91,  249, 127, 0,   67,  31,  62,  231, 71,
                         177, 117, 85,  183, 44,  215, 211, 10,  210, 86,  239,
                         228, 201, 62,  171, 162, 101, 33,  76,  86,  142, 41,
                         83,  63,  119, 10,  54,  219, 218, 228, 184, 157, 194,
                         59,  186, 189, 114, 186, 223, 108, 30,  151};
  const uint8_t ans[] = {
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155};
  SET_MBA0_I8();
  msettilek(K);
  msettilen(N);
  muint8_t ms = mlb_m(src, stride);
  muint8_t md = mbcbr_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBR_M U8");
}

static void test_mbcbr_m_u16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  const uint16_t src[] = {
      1871,  64117, 62734, 9297,  34140, 19873, 25012, 37719, 23522, 36431,
      18171, 32208, 4451,  47495, 63000, 24,    60901, 64880, 24482, 7889,
      59925, 41041, 43290, 8057,  57222, 669,   21107, 41952, 54240, 15091,
      65504, 49143, 22685, 56337, 16152, 56526, 7947,  13017, 58922, 16451,
      46517, 63047, 39926, 65353, 62195, 19322, 15699, 12638, 7256,  36942,
      53137, 52697, 30136, 45794, 3982,  4120,  34018, 944,   25140, 57497,
      46416, 32268, 9622,  41890};
  const uint16_t ans[] = {1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719};
  ;
  SET_MBA0_I16();
  msettilek(K);
  msettilen(N);
  muint16_t ms = mlb_m(src, stride);
  muint16_t md = mbcbr_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBR_M U16");
}

static void test_mbcbr_m_u32() {
  const size_t K = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  const uint32_t src[] = {
      104379910,  3019007360, 438798631,  1841583368, 1592927650, 941522289,
      1886382805, 2783564960, 3692430469, 1852682804, 3178010475, 3277374684,
      3748316551, 2609733232, 3459291143, 2946899571, 2219844739, 2372224847,
      1571077476, 222650655,  3525439780, 3549862802, 3360162577, 663877024,
      2354742351, 3729951427, 976076110,  4033555232, 4171633750, 3027486024,
      3888997953, 2173874754};
  const uint32_t ans[] = {
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368, 104379910, 3019007360, 438798631, 1841583368,
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368, 104379910, 3019007360, 438798631, 1841583368,
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368};
  SET_MBA0_I32();
  msettilek(K);
  msettilen(N);
  muint32_t ms = mlb_m(src, stride);
  muint32_t md = mbcbr_m(ms);
  msb_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, K * N, "MBCBR_M U32");
}

static void test_mbcbr_m_u64() {
  const size_t K = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  const uint64_t src[] = {
      16347387788243600761, 15073635922616989291, 14391479479577944355,
      2058821884535156258,  4463241850410397957,  3169148459009399821,
      12153685519839682343, 8197704767014005803,  103217090143275429,
      3555615660525631887,  10341798841844766871, 1632229831863916592,
      86107908927148041,    2288898801364535644,  10668287436207437854,
      8931633472857564474};
  const uint64_t ans[] = {
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291, 16347387788243600761, 15073635922616989291,
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291, 16347387788243600761, 15073635922616989291,
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291};
  SET_MBA0_I64();
  msettilek(K);
  msettilen(N);
  muint64_t ms = mlb_m(src, stride);
  muint64_t md = mbcbr_m(ms);
  msb_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, K * N, "MBCBR_M U64");
}

static void test_mbccr_m_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  const uint8_t src[] = {133, 67,  188, 240, 149, 99,  74,  155, 35,  139, 72,
                         20,  21,  91,  249, 127, 0,   67,  31,  62,  231, 71,
                         177, 117, 85,  183, 44,  215, 211, 10,  210, 86,  239,
                         228, 201, 62,  171, 162, 101, 33,  76,  86,  142, 41,
                         83,  63,  119, 10,  54,  219, 218, 228, 184, 157, 194,
                         59,  186, 189, 114, 186, 223, 108, 30,  151};
  const uint8_t ans[] = {
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155,
      133, 67, 188, 240, 149, 99, 74, 155, 133, 67, 188, 240, 149, 99, 74, 155};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, stride);
  muint8_t md = mbccr_m(ms);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MBCCR_M U8");
}

static void test_mbccr_m_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  const uint16_t src[] = {
      1871,  64117, 62734, 9297,  34140, 19873, 25012, 37719, 23522, 36431,
      18171, 32208, 4451,  47495, 63000, 24,    60901, 64880, 24482, 7889,
      59925, 41041, 43290, 8057,  57222, 669,   21107, 41952, 54240, 15091,
      65504, 49143, 22685, 56337, 16152, 56526, 7947,  13017, 58922, 16451,
      46517, 63047, 39926, 65353, 62195, 19322, 15699, 12638, 7256,  36942,
      53137, 52697, 30136, 45794, 3982,  4120,  34018, 944,   25140, 57497,
      46416, 32268, 9622,  41890};
  const uint16_t ans[] = {1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719,
                          1871, 64117, 62734, 9297, 34140, 19873, 25012, 37719};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, stride);
  muint16_t md = mbccr_m(ms);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, M * N, "MBCCR_M U16");
}

static void test_mbccr_m_u32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  const uint32_t src[] = {
      104379910,  3019007360, 438798631,  1841583368, 1592927650, 941522289,
      1886382805, 2783564960, 3692430469, 1852682804, 3178010475, 3277374684,
      3748316551, 2609733232, 3459291143, 2946899571, 2219844739, 2372224847,
      1571077476, 222650655,  3525439780, 3549862802, 3360162577, 663877024,
      2354742351, 3729951427, 976076110,  4033555232, 4171633750, 3027486024,
      3888997953, 2173874754};
  const uint32_t ans[] = {
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368, 104379910, 3019007360, 438798631, 1841583368,
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368, 104379910, 3019007360, 438798631, 1841583368,
      104379910, 3019007360, 438798631, 1841583368, 104379910, 3019007360,
      438798631, 1841583368};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, stride);
  muint32_t md = mbccr_m(ms);
  msc_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MBCCR_M U32");
}

static void test_mbccr_m_u64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  const uint64_t src[] = {
      16347387788243600761, 15073635922616989291, 14391479479577944355,
      2058821884535156258,  4463241850410397957,  3169148459009399821,
      12153685519839682343, 8197704767014005803,  103217090143275429,
      3555615660525631887,  10341798841844766871, 1632229831863916592,
      86107908927148041,    2288898801364535644,  10668287436207437854,
      8931633472857564474};
  const uint64_t ans[] = {
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291, 16347387788243600761, 15073635922616989291,
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291, 16347387788243600761, 15073635922616989291,
      16347387788243600761, 15073635922616989291, 16347387788243600761,
      15073635922616989291};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, stride);
  muint64_t md = mbccr_m(ms);
  msc_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MBCCR_M U64");
}

static void test_mbcac_m_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int8_t);
  const int8_t src[] = {
      20,  -115, 86,   60,  -121, -65, 13,   23,  -42,  -98,  55,   -10,  -14,
      -33, 50,   -77,  -39, 43,   48,  78,   -65, -103, -5,   -106, 12,   -30,
      -4,  22,   26,   -33, -54,  -52, -91,  42,  -90,  7,    94,   10,   96,
      -23, 90,   30,   -74, 58,   97,  -105, 90,  116,  51,   65,   -116, -124,
      -22, -88,  -108, 87,  124,  -89, 105,  -35, 120,  -110, 35,   -12};
  const int8_t ans[] = {20,  20,  20,  20,  20,  20,  20,  20,  -42, -42, -42,
                        -42, -42, -42, -42, -42, -39, -39, -39, -39, -39, -39,
                        -39, -39, 12,  12,  12,  12,  12,  12,  12,  12,  -91,
                        -91, -91, -91, -91, -91, -91, -91, 90,  90,  90,  90,
                        90,  90,  90,  90,  51,  51,  51,  51,  51,  51,  51,
                        51,  124, 124, 124, 124, 124, 124, 124, 124};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  mint8_t ms = mla_m(src, stride);
  mint8_t md = mbcac_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAC_M I8");
}

static void test_mbcac_m_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int16_t);
  const int16_t src[] = {
      -7690,  12558,  3183,   22604,  -18273, -24291, -11966, -21854,
      18805,  2152,   1483,   9481,   -26302, 28770,  -15463, 15424,
      -5700,  -8134,  29987,  -32219, -6094,  -2298,  -1439,  -32391,
      -16360, 15326,  12646,  -29096, 23807,  -2382,  -21707, -26034,
      -14132, -30965, -26743, -13183, -15103, 11217,  -30362, 11997,
      1654,   27224,  -7659,  -25918, 28302,  -5578,  3459,   18050,
      23571,  7084,   -26377, 12233,  -21415, 9957,   -10436, 8196,
      -4200,  22627,  23802,  18424,  -27237, -15616, -26594, 25201};
  const int16_t ans[] = {
      -7690,  -7690,  -7690,  -7690,  -7690,  -7690,  -7690,  -7690,
      18805,  18805,  18805,  18805,  18805,  18805,  18805,  18805,
      -5700,  -5700,  -5700,  -5700,  -5700,  -5700,  -5700,  -5700,
      -16360, -16360, -16360, -16360, -16360, -16360, -16360, -16360,
      -14132, -14132, -14132, -14132, -14132, -14132, -14132, -14132,
      1654,   1654,   1654,   1654,   1654,   1654,   1654,   1654,
      23571,  23571,  23571,  23571,  23571,  23571,  23571,  23571,
      -4200,  -4200,  -4200,  -4200,  -4200,  -4200,  -4200,  -4200};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  mint16_t ms = mla_m(src, stride);
  mint16_t md = mbcac_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAC_M I16");
}

static void test_mbcac_m_i32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t stride = K * sizeof(int32_t);
  const int32_t src[] = {-321975821,  -1322719428, -148101083,  146474221,
                         -709424178,  -180831403,  1706139401,  -592368167,
                         -619246133,  -361371894,  1140928762,  393851099,
                         -424570052,  -1986063133, 1254576220,  1164878830,
                         -1415721121, 64367728,    1510138117,  -415184507,
                         1104532329,  -741631750,  -746788405,  251747543,
                         -1739147860, 132851041,   -1789308330, 249961789,
                         1386472565,  421331619,   950860384,   -2132772987};
  const int32_t ans[] = {-321975821,  -321975821,  -321975821,  -321975821,
                         -709424178,  -709424178,  -709424178,  -709424178,
                         -619246133,  -619246133,  -619246133,  -619246133,
                         -424570052,  -424570052,  -424570052,  -424570052,
                         -1415721121, -1415721121, -1415721121, -1415721121,
                         1104532329,  1104532329,  1104532329,  1104532329,
                         -1739147860, -1739147860, -1739147860, -1739147860,
                         1386472565,  1386472565,  1386472565,  1386472565};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  mint32_t ms = mla_m(src, stride);
  mint32_t md = mbcac_m(ms);
  msa_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * K, "MBCAC_M I32");
}

static void test_mbcac_m_i64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t stride = K * sizeof(int64_t);
  const int64_t src[] = {
      617372944194097219,   -221734813008626796,  -6524972372728999902,
      -7653602329922623019, 4848327024677531751,  -3820871660896525210,
      2464751792809672044,  4260720898238469872,  1337459136955060167,
      -231891009581926996,  -5001537806982991133, -1164931353671369986,
      -8191568821119924594, -8828993539181073541, -6817507502146717071,
      -1850975531126208740};
  const int64_t ans[] = {
      617372944194097219,   617372944194097219,   -6524972372728999902,
      -6524972372728999902, 4848327024677531751,  4848327024677531751,
      2464751792809672044,  2464751792809672044,  1337459136955060167,
      1337459136955060167,  -5001537806982991133, -5001537806982991133,
      -8191568821119924594, -8191568821119924594, -6817507502146717071,
      -6817507502146717071};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  mint64_t ms = mla_m(src, stride);
  mint64_t md = mbcac_m(ms);
  msa_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * K, "MBCAC_M I64");
}

static void test_mbcbc_m_i8() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  const int8_t src[] = {
      20,  -115, 86,   60,  -121, -65, 13,   23,  -42,  -98,  55,   -10,  -14,
      -33, 50,   -77,  -39, 43,   48,  78,   -65, -103, -5,   -106, 12,   -30,
      -4,  22,   26,   -33, -54,  -52, -91,  42,  -90,  7,    94,   10,   96,
      -23, 90,   30,   -74, 58,   97,  -105, 90,  116,  51,   65,   -116, -124,
      -22, -88,  -108, 87,  124,  -89, 105,  -35, 120,  -110, 35,   -12};
  const int8_t ans[] = {20,  20,  20,  20,  20,  20,  20,  20,  -42, -42, -42,
                        -42, -42, -42, -42, -42, -39, -39, -39, -39, -39, -39,
                        -39, -39, 12,  12,  12,  12,  12,  12,  12,  12,  -91,
                        -91, -91, -91, -91, -91, -91, -91, 90,  90,  90,  90,
                        90,  90,  90,  90,  51,  51,  51,  51,  51,  51,  51,
                        51,  124, 124, 124, 124, 124, 124, 124, 124};
  SET_MBA0_I8();
  msettilek(K);
  msettilen(N);
  mint8_t ms = mlb_m(src, stride);
  mint8_t md = mbcbc_m(ms);
  msb_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, K * N, "MBCBC_M I8");
}

static void test_mbcbc_m_i16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  const int16_t src[] = {
      -7690,  12558,  3183,   22604,  -18273, -24291, -11966, -21854,
      18805,  2152,   1483,   9481,   -26302, 28770,  -15463, 15424,
      -5700,  -8134,  29987,  -32219, -6094,  -2298,  -1439,  -32391,
      -16360, 15326,  12646,  -29096, 23807,  -2382,  -21707, -26034,
      -14132, -30965, -26743, -13183, -15103, 11217,  -30362, 11997,
      1654,   27224,  -7659,  -25918, 28302,  -5578,  3459,   18050,
      23571,  7084,   -26377, 12233,  -21415, 9957,   -10436, 8196,
      -4200,  22627,  23802,  18424,  -27237, -15616, -26594, 25201};
  const int16_t ans[] = {
      -7690,  -7690,  -7690,  -7690,  -7690,  -7690,  -7690,  -7690,
      18805,  18805,  18805,  18805,  18805,  18805,  18805,  18805,
      -5700,  -5700,  -5700,  -5700,  -5700,  -5700,  -5700,  -5700,
      -16360, -16360, -16360, -16360, -16360, -16360, -16360, -16360,
      -14132, -14132, -14132, -14132, -14132, -14132, -14132, -14132,
      1654,   1654,   1654,   1654,   1654,   1654,   1654,   1654,
      23571,  23571,  23571,  23571,  23571,  23571,  23571,  23571,
      -4200,  -4200,  -4200,  -4200,  -4200,  -4200,  -4200,  -4200};
  SET_MBA0_I16();
  msettilek(K);
  msettilen(N);
  mint16_t ms = mlb_m(src, stride);
  mint16_t md = mbcbc_m(ms);
  msb_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, K * N, "MBCBC_M I16");
}

static void test_mbcbc_m_i32() {
  const size_t K = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  const int32_t src[] = {-321975821,  -1322719428, -148101083,  146474221,
                         -709424178,  -180831403,  1706139401,  -592368167,
                         -619246133,  -361371894,  1140928762,  393851099,
                         -424570052,  -1986063133, 1254576220,  1164878830,
                         -1415721121, 64367728,    1510138117,  -415184507,
                         1104532329,  -741631750,  -746788405,  251747543,
                         -1739147860, 132851041,   -1789308330, 249961789,
                         1386472565,  421331619,   950860384,   -2132772987};
  const int32_t ans[] = {-321975821,  -321975821,  -321975821,  -321975821,
                         -709424178,  -709424178,  -709424178,  -709424178,
                         -619246133,  -619246133,  -619246133,  -619246133,
                         -424570052,  -424570052,  -424570052,  -424570052,
                         -1415721121, -1415721121, -1415721121, -1415721121,
                         1104532329,  1104532329,  1104532329,  1104532329,
                         -1739147860, -1739147860, -1739147860, -1739147860,
                         1386472565,  1386472565,  1386472565,  1386472565};
  SET_MBA0_I32();
  msettilek(K);
  msettilen(N);
  mint32_t ms = mlb_m(src, stride);
  mint32_t md = mbcbc_m(ms);
  msb_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, K * N, "MBCBC_M I32");
}

static void test_mbcbc_m_i64() {
  const size_t K = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  const int64_t src[] = {
      617372944194097219,   -221734813008626796,  -6524972372728999902,
      -7653602329922623019, 4848327024677531751,  -3820871660896525210,
      2464751792809672044,  4260720898238469872,  1337459136955060167,
      -231891009581926996,  -5001537806982991133, -1164931353671369986,
      -8191568821119924594, -8828993539181073541, -6817507502146717071,
      -1850975531126208740};
  const int64_t ans[] = {
      617372944194097219,   617372944194097219,   -6524972372728999902,
      -6524972372728999902, 4848327024677531751,  4848327024677531751,
      2464751792809672044,  2464751792809672044,  1337459136955060167,
      1337459136955060167,  -5001537806982991133, -5001537806982991133,
      -8191568821119924594, -8191568821119924594, -6817507502146717071,
      -6817507502146717071};
  SET_MBA0_I64();
  msettilek(K);
  msettilen(N);
  mint64_t ms = mlb_m(src, stride);
  mint64_t md = mbcbc_m(ms);
  msb_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, K * N, "MBCBC_M I64");
}

static void test_mbccc_m_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  const int8_t src[] = {
      20,  -115, 86,   60,  -121, -65, 13,   23,  -42,  -98,  55,   -10,  -14,
      -33, 50,   -77,  -39, 43,   48,  78,   -65, -103, -5,   -106, 12,   -30,
      -4,  22,   26,   -33, -54,  -52, -91,  42,  -90,  7,    94,   10,   96,
      -23, 90,   30,   -74, 58,   97,  -105, 90,  116,  51,   65,   -116, -124,
      -22, -88,  -108, 87,  124,  -89, 105,  -35, 120,  -110, 35,   -12};
  const int8_t ans[] = {20,  20,  20,  20,  20,  20,  20,  20,  -42, -42, -42,
                        -42, -42, -42, -42, -42, -39, -39, -39, -39, -39, -39,
                        -39, -39, 12,  12,  12,  12,  12,  12,  12,  12,  -91,
                        -91, -91, -91, -91, -91, -91, -91, 90,  90,  90,  90,
                        90,  90,  90,  90,  51,  51,  51,  51,  51,  51,  51,
                        51,  124, 124, 124, 124, 124, 124, 124, 124};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, stride);
  mint8_t md = mbccc_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCC_M I8");
}

static void test_mbccc_m_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  const int16_t src[] = {
      -7690,  12558,  3183,   22604,  -18273, -24291, -11966, -21854,
      18805,  2152,   1483,   9481,   -26302, 28770,  -15463, 15424,
      -5700,  -8134,  29987,  -32219, -6094,  -2298,  -1439,  -32391,
      -16360, 15326,  12646,  -29096, 23807,  -2382,  -21707, -26034,
      -14132, -30965, -26743, -13183, -15103, 11217,  -30362, 11997,
      1654,   27224,  -7659,  -25918, 28302,  -5578,  3459,   18050,
      23571,  7084,   -26377, 12233,  -21415, 9957,   -10436, 8196,
      -4200,  22627,  23802,  18424,  -27237, -15616, -26594, 25201};
  const int16_t ans[] = {
      -7690,  -7690,  -7690,  -7690,  -7690,  -7690,  -7690,  -7690,
      18805,  18805,  18805,  18805,  18805,  18805,  18805,  18805,
      -5700,  -5700,  -5700,  -5700,  -5700,  -5700,  -5700,  -5700,
      -16360, -16360, -16360, -16360, -16360, -16360, -16360, -16360,
      -14132, -14132, -14132, -14132, -14132, -14132, -14132, -14132,
      1654,   1654,   1654,   1654,   1654,   1654,   1654,   1654,
      23571,  23571,  23571,  23571,  23571,  23571,  23571,  23571,
      -4200,  -4200,  -4200,  -4200,  -4200,  -4200,  -4200,  -4200};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, stride);
  mint16_t md = mbccc_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCC_M I16");
}

static void test_mbccc_m_i32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  const int32_t src[] = {-321975821,  -1322719428, -148101083,  146474221,
                         -709424178,  -180831403,  1706139401,  -592368167,
                         -619246133,  -361371894,  1140928762,  393851099,
                         -424570052,  -1986063133, 1254576220,  1164878830,
                         -1415721121, 64367728,    1510138117,  -415184507,
                         1104532329,  -741631750,  -746788405,  251747543,
                         -1739147860, 132851041,   -1789308330, 249961789,
                         1386472565,  421331619,   950860384,   -2132772987};
  const int32_t ans[] = {-321975821,  -321975821,  -321975821,  -321975821,
                         -709424178,  -709424178,  -709424178,  -709424178,
                         -619246133,  -619246133,  -619246133,  -619246133,
                         -424570052,  -424570052,  -424570052,  -424570052,
                         -1415721121, -1415721121, -1415721121, -1415721121,
                         1104532329,  1104532329,  1104532329,  1104532329,
                         -1739147860, -1739147860, -1739147860, -1739147860,
                         1386472565,  1386472565,  1386472565,  1386472565};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, stride);
  mint32_t md = mbccc_m(ms);
  msc_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MBCCC_M I32");
}

static void test_mbccc_m_i64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  const int64_t src[] = {
      617372944194097219,   -221734813008626796,  -6524972372728999902,
      -7653602329922623019, 4848327024677531751,  -3820871660896525210,
      2464751792809672044,  4260720898238469872,  1337459136955060167,
      -231891009581926996,  -5001537806982991133, -1164931353671369986,
      -8191568821119924594, -8828993539181073541, -6817507502146717071,
      -1850975531126208740};
  const int64_t ans[] = {
      617372944194097219,   617372944194097219,   -6524972372728999902,
      -6524972372728999902, 4848327024677531751,  4848327024677531751,
      2464751792809672044,  2464751792809672044,  1337459136955060167,
      1337459136955060167,  -5001537806982991133, -5001537806982991133,
      -8191568821119924594, -8191568821119924594, -6817507502146717071,
      -6817507502146717071};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, stride);
  mint64_t md = mbccc_m(ms);
  msc_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MBCCC_M I64");
}

static void test_mbcac_m_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint8_t);
  const uint8_t src[] = {206, 202, 76,  163, 98,  180, 161, 194, 151, 44,  198,
                         246, 89,  39,  134, 122, 90,  217, 54,  72,  147, 26,
                         154, 243, 89,  136, 20,  187, 45,  38,  149, 149, 248,
                         56,  39,  164, 61,  89,  171, 57,  247, 186, 77,  177,
                         243, 4,   219, 51,  217, 23,  13,  234, 178, 203, 48,
                         95,  214, 55,  217, 55,  142, 85,  234, 102};
  const uint8_t ans[] = {206, 206, 206, 206, 206, 206, 206, 206, 151, 151, 151,
                         151, 151, 151, 151, 151, 90,  90,  90,  90,  90,  90,
                         90,  90,  89,  89,  89,  89,  89,  89,  89,  89,  248,
                         248, 248, 248, 248, 248, 248, 248, 247, 247, 247, 247,
                         247, 247, 247, 247, 217, 217, 217, 217, 217, 217, 217,
                         217, 214, 214, 214, 214, 214, 214, 214, 214};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  muint8_t ms = mla_m(src, stride);
  muint8_t md = mbcac_m(ms);
  msa_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * K, "MBCAC_M U8");
}

static void test_mbcac_m_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint16_t);
  const uint16_t src[] = {
      7845,  21690, 64497, 38993, 63909, 58830, 3695,  12352, 27432, 37638,
      58201, 18615, 51475, 15850, 55841, 50871, 419,   12565, 2364,  64067,
      5329,  61160, 37696, 34765, 10707, 61000, 21337, 31555, 18952, 62797,
      36837, 26242, 2284,  59689, 14312, 48362, 13548, 148,   13733, 45575,
      45332, 57371, 26789, 43767, 10911, 4989,  60300, 5326,  14935, 42586,
      28109, 55842, 33558, 20347, 48284, 43575, 31306, 32488, 46145, 36306,
      51150, 24739, 32300, 50665};
  const uint16_t ans[] = {
      7845,  7845,  7845,  7845,  7845,  7845,  7845,  7845,  27432, 27432,
      27432, 27432, 27432, 27432, 27432, 27432, 419,   419,   419,   419,
      419,   419,   419,   419,   10707, 10707, 10707, 10707, 10707, 10707,
      10707, 10707, 2284,  2284,  2284,  2284,  2284,  2284,  2284,  2284,
      45332, 45332, 45332, 45332, 45332, 45332, 45332, 45332, 14935, 14935,
      14935, 14935, 14935, 14935, 14935, 14935, 31306, 31306, 31306, 31306,
      31306, 31306, 31306, 31306};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  muint16_t ms = mla_m(src, stride);
  muint16_t md = mbcac_m(ms);
  msa_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, M * K, "MBCAC_M U16");
}

static void test_mbcac_m_u32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t stride = K * sizeof(uint32_t);
  const uint32_t src[] = {
      1905332638, 1399744668, 217462862,  3196248750, 3515367003, 2344016596,
      3920285464, 4018419322, 3185686922, 2412545578, 816918535,  2653263510,
      2674905508, 411340842,  2275561905, 1252634707, 490725464,  114528472,
      3256300722, 108569143,  2965439687, 971631989,  730755688,  2891751198,
      4043081320, 3146902875, 4251412877, 322610367,  3488478984, 1301092448,
      2231078871, 3103637821};
  const uint32_t ans[] = {
      1905332638, 1905332638, 1905332638, 1905332638, 3515367003, 3515367003,
      3515367003, 3515367003, 3185686922, 3185686922, 3185686922, 3185686922,
      2674905508, 2674905508, 2674905508, 2674905508, 490725464,  490725464,
      490725464,  490725464,  2965439687, 2965439687, 2965439687, 2965439687,
      4043081320, 4043081320, 4043081320, 4043081320, 3488478984, 3488478984,
      3488478984, 3488478984};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  muint32_t ms = mla_m(src, stride);
  muint32_t md = mbcac_m(ms);
  msa_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * K, "MBCAC_M U32");
}

static void test_mbcac_m_u64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t stride = K * sizeof(uint64_t);
  const uint64_t src[] = {
      15469116976082905479, 10526586570291156398, 16761128624258935574,
      12425831314326185140, 8683346056223704910,  5767824631885819746,
      6977653418496640555,  8942628704317439647,  11488626663727683227,
      12269044266526704486, 1900947285346495466,  8335413816029519819,
      10376566675285823797, 17815280279524766867, 10590018933761991290,
      15826490273322948870};
  const uint64_t ans[] = {
      15469116976082905479, 15469116976082905479, 16761128624258935574,
      16761128624258935574, 8683346056223704910,  8683346056223704910,
      6977653418496640555,  6977653418496640555,  11488626663727683227,
      11488626663727683227, 1900947285346495466,  1900947285346495466,
      10376566675285823797, 10376566675285823797, 10590018933761991290,
      10590018933761991290};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  muint64_t ms = mla_m(src, stride);
  muint64_t md = mbcac_m(ms);
  msa_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * K, "MBCAC_M U64");
}

static void test_mbcbc_m_u8() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  const uint8_t src[] = {206, 202, 76,  163, 98,  180, 161, 194, 151, 44,  198,
                         246, 89,  39,  134, 122, 90,  217, 54,  72,  147, 26,
                         154, 243, 89,  136, 20,  187, 45,  38,  149, 149, 248,
                         56,  39,  164, 61,  89,  171, 57,  247, 186, 77,  177,
                         243, 4,   219, 51,  217, 23,  13,  234, 178, 203, 48,
                         95,  214, 55,  217, 55,  142, 85,  234, 102};
  const uint8_t ans[] = {206, 206, 206, 206, 206, 206, 206, 206, 151, 151, 151,
                         151, 151, 151, 151, 151, 90,  90,  90,  90,  90,  90,
                         90,  90,  89,  89,  89,  89,  89,  89,  89,  89,  248,
                         248, 248, 248, 248, 248, 248, 248, 247, 247, 247, 247,
                         247, 247, 247, 247, 217, 217, 217, 217, 217, 217, 217,
                         217, 214, 214, 214, 214, 214, 214, 214, 214};
  SET_MBA0_I8();
  msettilek(K);
  msettilen(N);
  muint8_t ms = mlb_m(src, stride);
  muint8_t md = mbcbc_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBC_M U8");
}

static void test_mbcbc_m_u16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  const uint16_t src[] = {
      7845,  21690, 64497, 38993, 63909, 58830, 3695,  12352, 27432, 37638,
      58201, 18615, 51475, 15850, 55841, 50871, 419,   12565, 2364,  64067,
      5329,  61160, 37696, 34765, 10707, 61000, 21337, 31555, 18952, 62797,
      36837, 26242, 2284,  59689, 14312, 48362, 13548, 148,   13733, 45575,
      45332, 57371, 26789, 43767, 10911, 4989,  60300, 5326,  14935, 42586,
      28109, 55842, 33558, 20347, 48284, 43575, 31306, 32488, 46145, 36306,
      51150, 24739, 32300, 50665};
  const uint16_t ans[] = {
      7845,  7845,  7845,  7845,  7845,  7845,  7845,  7845,  27432, 27432,
      27432, 27432, 27432, 27432, 27432, 27432, 419,   419,   419,   419,
      419,   419,   419,   419,   10707, 10707, 10707, 10707, 10707, 10707,
      10707, 10707, 2284,  2284,  2284,  2284,  2284,  2284,  2284,  2284,
      45332, 45332, 45332, 45332, 45332, 45332, 45332, 45332, 14935, 14935,
      14935, 14935, 14935, 14935, 14935, 14935, 31306, 31306, 31306, 31306,
      31306, 31306, 31306, 31306};
  SET_MBA0_I16();
  msettilek(K);
  msettilen(N);
  muint16_t ms = mlb_m(src, stride);
  muint16_t md = mbcbc_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBC_M U16");
}

static void test_mbcbc_m_u32() {
  const size_t K = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  const uint32_t src[] = {
      1905332638, 1399744668, 217462862,  3196248750, 3515367003, 2344016596,
      3920285464, 4018419322, 3185686922, 2412545578, 816918535,  2653263510,
      2674905508, 411340842,  2275561905, 1252634707, 490725464,  114528472,
      3256300722, 108569143,  2965439687, 971631989,  730755688,  2891751198,
      4043081320, 3146902875, 4251412877, 322610367,  3488478984, 1301092448,
      2231078871, 3103637821};
  const uint32_t ans[] = {
      1905332638, 1905332638, 1905332638, 1905332638, 3515367003, 3515367003,
      3515367003, 3515367003, 3185686922, 3185686922, 3185686922, 3185686922,
      2674905508, 2674905508, 2674905508, 2674905508, 490725464,  490725464,
      490725464,  490725464,  2965439687, 2965439687, 2965439687, 2965439687,
      4043081320, 4043081320, 4043081320, 4043081320, 3488478984, 3488478984,
      3488478984, 3488478984};
  SET_MBA0_I32();
  msettilek(K);
  msettilen(N);
  muint32_t ms = mlb_m(src, stride);
  muint32_t md = mbcbc_m(ms);
  msb_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, K * N, "MBCBC_M U32");
}

static void test_mbcbc_m_u64() {
  const size_t K = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  const uint64_t src[] = {
      15469116976082905479, 10526586570291156398, 16761128624258935574,
      12425831314326185140, 8683346056223704910,  5767824631885819746,
      6977653418496640555,  8942628704317439647,  11488626663727683227,
      12269044266526704486, 1900947285346495466,  8335413816029519819,
      10376566675285823797, 17815280279524766867, 10590018933761991290,
      15826490273322948870};
  const uint64_t ans[] = {
      15469116976082905479, 15469116976082905479, 16761128624258935574,
      16761128624258935574, 8683346056223704910,  8683346056223704910,
      6977653418496640555,  6977653418496640555,  11488626663727683227,
      11488626663727683227, 1900947285346495466,  1900947285346495466,
      10376566675285823797, 10376566675285823797, 10590018933761991290,
      10590018933761991290};
  SET_MBA0_I64();
  msettilek(K);
  msettilen(N);
  muint64_t ms = mlb_m(src, stride);
  muint64_t md = mbcbc_m(ms);
  msb_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, K * N, "MBCBC_M U64");
}

static void test_mbccc_m_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  const uint8_t src[] = {206, 202, 76,  163, 98,  180, 161, 194, 151, 44,  198,
                         246, 89,  39,  134, 122, 90,  217, 54,  72,  147, 26,
                         154, 243, 89,  136, 20,  187, 45,  38,  149, 149, 248,
                         56,  39,  164, 61,  89,  171, 57,  247, 186, 77,  177,
                         243, 4,   219, 51,  217, 23,  13,  234, 178, 203, 48,
                         95,  214, 55,  217, 55,  142, 85,  234, 102};
  const uint8_t ans[] = {206, 206, 206, 206, 206, 206, 206, 206, 151, 151, 151,
                         151, 151, 151, 151, 151, 90,  90,  90,  90,  90,  90,
                         90,  90,  89,  89,  89,  89,  89,  89,  89,  89,  248,
                         248, 248, 248, 248, 248, 248, 248, 247, 247, 247, 247,
                         247, 247, 247, 247, 217, 217, 217, 217, 217, 217, 217,
                         217, 214, 214, 214, 214, 214, 214, 214, 214};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, stride);
  muint8_t md = mbccc_m(ms);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MBCCC_M U8");
}

static void test_mbccc_m_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  const uint16_t src[] = {
      7845,  21690, 64497, 38993, 63909, 58830, 3695,  12352, 27432, 37638,
      58201, 18615, 51475, 15850, 55841, 50871, 419,   12565, 2364,  64067,
      5329,  61160, 37696, 34765, 10707, 61000, 21337, 31555, 18952, 62797,
      36837, 26242, 2284,  59689, 14312, 48362, 13548, 148,   13733, 45575,
      45332, 57371, 26789, 43767, 10911, 4989,  60300, 5326,  14935, 42586,
      28109, 55842, 33558, 20347, 48284, 43575, 31306, 32488, 46145, 36306,
      51150, 24739, 32300, 50665};
  const uint16_t ans[] = {
      7845,  7845,  7845,  7845,  7845,  7845,  7845,  7845,  27432, 27432,
      27432, 27432, 27432, 27432, 27432, 27432, 419,   419,   419,   419,
      419,   419,   419,   419,   10707, 10707, 10707, 10707, 10707, 10707,
      10707, 10707, 2284,  2284,  2284,  2284,  2284,  2284,  2284,  2284,
      45332, 45332, 45332, 45332, 45332, 45332, 45332, 45332, 14935, 14935,
      14935, 14935, 14935, 14935, 14935, 14935, 31306, 31306, 31306, 31306,
      31306, 31306, 31306, 31306};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, stride);
  muint16_t md = mbccc_m(ms);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, M * N, "MBCCC_M U16");
}

static void test_mbccc_m_u32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  const uint32_t src[] = {
      1905332638, 1399744668, 217462862,  3196248750, 3515367003, 2344016596,
      3920285464, 4018419322, 3185686922, 2412545578, 816918535,  2653263510,
      2674905508, 411340842,  2275561905, 1252634707, 490725464,  114528472,
      3256300722, 108569143,  2965439687, 971631989,  730755688,  2891751198,
      4043081320, 3146902875, 4251412877, 322610367,  3488478984, 1301092448,
      2231078871, 3103637821};
  const uint32_t ans[] = {
      1905332638, 1905332638, 1905332638, 1905332638, 3515367003, 3515367003,
      3515367003, 3515367003, 3185686922, 3185686922, 3185686922, 3185686922,
      2674905508, 2674905508, 2674905508, 2674905508, 490725464,  490725464,
      490725464,  490725464,  2965439687, 2965439687, 2965439687, 2965439687,
      4043081320, 4043081320, 4043081320, 4043081320, 3488478984, 3488478984,
      3488478984, 3488478984};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, stride);
  muint32_t md = mbccc_m(ms);
  msc_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MBCCC_M U32");
}

static void test_mbccc_m_u64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  const uint64_t src[] = {
      15469116976082905479, 10526586570291156398, 16761128624258935574,
      12425831314326185140, 8683346056223704910,  5767824631885819746,
      6977653418496640555,  8942628704317439647,  11488626663727683227,
      12269044266526704486, 1900947285346495466,  8335413816029519819,
      10376566675285823797, 17815280279524766867, 10590018933761991290,
      15826490273322948870};
  const uint64_t ans[] = {
      15469116976082905479, 15469116976082905479, 16761128624258935574,
      16761128624258935574, 8683346056223704910,  8683346056223704910,
      6977653418496640555,  6977653418496640555,  11488626663727683227,
      11488626663727683227, 1900947285346495466,  1900947285346495466,
      10376566675285823797, 10376566675285823797, 10590018933761991290,
      10590018933761991290};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, stride);
  muint64_t md = mbccc_m(ms);
  msc_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MBCCC_M U64");
}

static void test_mbcae_m_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int8_t);
  const int8_t src[] = {
      -51, 90,  16,   95,  60,   49,  13,   31,  -105, 98,   -101, -13,  80,
      46,  -32, -101, 115, 27,   27,  -119, 70,  -127, 48,   -27,  -4,   -123,
      -69, -83, 100,  -14, -105, 89,  -12,  121, 2,    36,   -6,   -111, 10,
      99,  -70, -98,  120, 12,   60,  -123, 110, 21,   -117, 41,   -47,  98,
      -46, 44,  -127, 17,  45,   -70, -45,  77,  121,  37,   -47,  -32};
  const int8_t ans[] = {-51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  mint8_t ms = mla_m(src, stride);
  mint8_t md = mbcae_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAE_M I8");
}

static void test_mbcae_m_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int16_t);
  const int16_t src[] = {
      -17219, 15147,  -19253, -4942,  17655,  7502,   24433,  -6394,
      -27583, 18253,  -3924,  -2904,  20540,  22536,  -6549,  12215,
      12308,  -30322, -8700,  -5312,  -11508, 26302,  -17412, 29739,
      -14142, 25367,  5122,   11280,  -18973, 1750,   -13004, 15584,
      27305,  -31209, 6214,   -21281, -14306, -20525, -25720, -22149,
      -4951,  -18744, -15289, 5640,   -3973,  11573,  26250,  26036,
      29391,  -18070, 25373,  -18133, -21467, 6287,   14166,  -31015,
      -8217,  -31739, 25246,  19554,  -8303,  -4051,  -18985, -4491};
  const int16_t ans[] = {
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  mint16_t ms = mla_m(src, stride);
  mint16_t md = mbcae_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAE_M I16");
}

static void test_mbcae_m_i32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t stride = K * sizeof(int32_t);
  const int32_t src[] = {2129553685,  123956867,   289661479,   1664148910,
                         -1273350107, 2065759698,  1553205022,  2004638074,
                         -64787973,   1348726948,  124068446,   1301209047,
                         -1938924401, -1537700884, -355622168,  -1742640268,
                         967100185,   -2028528702, -1631115388, -2007570789,
                         -487904468,  -838523462,  467121052,   935042018,
                         1299525700,  -1493601128, -1450630678, 57741759,
                         1601086584,  1347959837,  -1308714436, 1146270493};
  const int32_t ans[] = {
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  mint32_t ms = mla_m(src, stride);
  mint32_t md = mbcae_m(ms);
  msa_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * K, "MBCAE_M I32");
}

static void test_mbcae_m_i64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t stride = K * sizeof(int64_t);
  const int64_t src[] = {
      -6733770408108298932, -8944736776375441768, -4994226234128646545,
      1798928686738366291,  3160629852475881401,  908611188796671082,
      -2609485441178473125, -86413267484844895,   3193496704357884678,
      -934621520680256550,  -6052812384973802666, -8974393305386894214,
      -1182225851558444230, -1632680507056497993, 3380869464820388833,
      -155294900069335207};
  const int64_t ans[] = {
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  mint64_t ms = mla_m(src, stride);
  mint64_t md = mbcae_m(ms);
  msa_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * K, "MBCAE_M I64");
}

static void test_mbcbe_m_i8() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  const int8_t src[] = {
      -51, 90,  16,   95,  60,   49,  13,   31,  -105, 98,   -101, -13,  80,
      46,  -32, -101, 115, 27,   27,  -119, 70,  -127, 48,   -27,  -4,   -123,
      -69, -83, 100,  -14, -105, 89,  -12,  121, 2,    36,   -6,   -111, 10,
      99,  -70, -98,  120, 12,   60,  -123, 110, 21,   -117, 41,   -47,  98,
      -46, 44,  -127, 17,  45,   -70, -45,  77,  121,  37,   -47,  -32};
  const int8_t ans[] = {-51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51};
  SET_MBA0_I8();
  msettilek(K);
  msettilen(N);
  mint8_t ms = mlb_m(src, stride);
  mint8_t md = mbcbe_m(ms);
  msb_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, K * N, "MBCBE_M I8");
}

static void test_mbcbe_m_i16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  const int16_t src[] = {
      -17219, 15147,  -19253, -4942,  17655,  7502,   24433,  -6394,
      -27583, 18253,  -3924,  -2904,  20540,  22536,  -6549,  12215,
      12308,  -30322, -8700,  -5312,  -11508, 26302,  -17412, 29739,
      -14142, 25367,  5122,   11280,  -18973, 1750,   -13004, 15584,
      27305,  -31209, 6214,   -21281, -14306, -20525, -25720, -22149,
      -4951,  -18744, -15289, 5640,   -3973,  11573,  26250,  26036,
      29391,  -18070, 25373,  -18133, -21467, 6287,   14166,  -31015,
      -8217,  -31739, 25246,  19554,  -8303,  -4051,  -18985, -4491};
  const int16_t ans[] = {
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219};
  SET_MBA0_I16();
  msettilek(K);
  msettilen(N);
  mint16_t ms = mlb_m(src, stride);
  mint16_t md = mbcbe_m(ms);
  msb_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, K * N, "MBCBE_M I16");
}

static void test_mbcbe_m_i32() {
  const size_t K = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  const int32_t src[] = {2129553685,  123956867,   289661479,   1664148910,
                         -1273350107, 2065759698,  1553205022,  2004638074,
                         -64787973,   1348726948,  124068446,   1301209047,
                         -1938924401, -1537700884, -355622168,  -1742640268,
                         967100185,   -2028528702, -1631115388, -2007570789,
                         -487904468,  -838523462,  467121052,   935042018,
                         1299525700,  -1493601128, -1450630678, 57741759,
                         1601086584,  1347959837,  -1308714436, 1146270493};
  const int32_t ans[] = {
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685};
  SET_MBA0_I32();
  msettilek(K);
  msettilen(N);
  mint32_t ms = mlb_m(src, stride);
  mint32_t md = mbcbe_m(ms);
  msb_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, K * N, "MBCBE_M I32");
}

static void test_mbcbe_m_i64() {
  const size_t K = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  const int64_t src[] = {
      -6733770408108298932, -8944736776375441768, -4994226234128646545,
      1798928686738366291,  3160629852475881401,  908611188796671082,
      -2609485441178473125, -86413267484844895,   3193496704357884678,
      -934621520680256550,  -6052812384973802666, -8974393305386894214,
      -1182225851558444230, -1632680507056497993, 3380869464820388833,
      -155294900069335207};
  const int64_t ans[] = {
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932};
  SET_MBA0_I64();
  msettilek(K);
  msettilen(N);
  mint64_t ms = mlb_m(src, stride);
  mint64_t md = mbcbe_m(ms);
  msb_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, K * N, "MBCBE_M I64");
}

static void test_mbcce_m_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  const int8_t src[] = {
      -51, 90,  16,   95,  60,   49,  13,   31,  -105, 98,   -101, -13,  80,
      46,  -32, -101, 115, 27,   27,  -119, 70,  -127, 48,   -27,  -4,   -123,
      -69, -83, 100,  -14, -105, 89,  -12,  121, 2,    36,   -6,   -111, 10,
      99,  -70, -98,  120, 12,   60,  -123, 110, 21,   -117, 41,   -47,  98,
      -46, 44,  -127, 17,  45,   -70, -45,  77,  121,  37,   -47,  -32};
  const int8_t ans[] = {-51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51, -51, -51,
                        -51, -51, -51, -51, -51, -51, -51, -51, -51};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, stride);
  mint8_t md = mbcce_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCE_M I8");
}

static void test_mbcce_m_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  const int16_t src[] = {
      -17219, 15147,  -19253, -4942,  17655,  7502,   24433,  -6394,
      -27583, 18253,  -3924,  -2904,  20540,  22536,  -6549,  12215,
      12308,  -30322, -8700,  -5312,  -11508, 26302,  -17412, 29739,
      -14142, 25367,  5122,   11280,  -18973, 1750,   -13004, 15584,
      27305,  -31209, 6214,   -21281, -14306, -20525, -25720, -22149,
      -4951,  -18744, -15289, 5640,   -3973,  11573,  26250,  26036,
      29391,  -18070, 25373,  -18133, -21467, 6287,   14166,  -31015,
      -8217,  -31739, 25246,  19554,  -8303,  -4051,  -18985, -4491};
  const int16_t ans[] = {
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219,
      -17219, -17219, -17219, -17219, -17219, -17219, -17219, -17219};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, stride);
  mint16_t md = mbcce_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCE_M I16");
}

static void test_mbcce_m_i32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  const int32_t src[] = {2129553685,  123956867,   289661479,   1664148910,
                         -1273350107, 2065759698,  1553205022,  2004638074,
                         -64787973,   1348726948,  124068446,   1301209047,
                         -1938924401, -1537700884, -355622168,  -1742640268,
                         967100185,   -2028528702, -1631115388, -2007570789,
                         -487904468,  -838523462,  467121052,   935042018,
                         1299525700,  -1493601128, -1450630678, 57741759,
                         1601086584,  1347959837,  -1308714436, 1146270493};
  const int32_t ans[] = {
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685, 2129553685, 2129553685, 2129553685, 2129553685,
      2129553685, 2129553685};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, stride);
  mint32_t md = mbcce_m(ms);
  msc_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MBCCE_M I32");
}

static void test_mbcce_m_i64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  const int64_t src[] = {
      -6733770408108298932, -8944736776375441768, -4994226234128646545,
      1798928686738366291,  3160629852475881401,  908611188796671082,
      -2609485441178473125, -86413267484844895,   3193496704357884678,
      -934621520680256550,  -6052812384973802666, -8974393305386894214,
      -1182225851558444230, -1632680507056497993, 3380869464820388833,
      -155294900069335207};
  const int64_t ans[] = {
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932, -6733770408108298932, -6733770408108298932,
      -6733770408108298932};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, stride);
  mint64_t md = mbcce_m(ms);
  msc_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MBCCE_M I64");
}

static void test_mbcae_m_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint8_t);
  const uint8_t src[] = {31,  114, 233, 68,  236, 16,  237, 81,  114, 217, 216,
                         103, 143, 239, 238, 36,  197, 46,  179, 53,  188, 247,
                         243, 74,  191, 216, 224, 64,  92,  69,  0,   204, 64,
                         40,  193, 11,  156, 54,  14,  14,  23,  221, 57,  70,
                         20,  104, 82,  105, 220, 191, 70,  196, 132, 227, 46,
                         74,  25,  199, 35,  23,  46,  251, 101, 102};
  const uint8_t ans[] = {31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  muint8_t ms = mla_m(src, stride);
  muint8_t md = mbcae_m(ms);
  msa_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * K, "MBCAE_M U8");
}

static void test_mbcae_m_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint16_t);
  const uint16_t src[] = {
      19847, 12164, 64849, 59035, 43536, 50384, 29196, 36819, 35576, 27922,
      40393, 2750,  56403, 33402, 49066, 22451, 36077, 44342, 27110, 40034,
      62910, 25966, 43854, 37246, 8029,  18441, 30894, 9992,  17696, 58503,
      10379, 486,   4784,  19570, 12357, 25332, 62688, 21334, 51022, 5356,
      355,   41537, 63958, 9534,  26639, 34214, 14289, 6919,  62040, 42954,
      7568,  53407, 12061, 50516, 3010,  46167, 50847, 4467,  22364, 39414,
      50195, 14464, 19236, 33624};
  const uint16_t ans[] = {
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  muint16_t ms = mla_m(src, stride);
  muint16_t md = mbcae_m(ms);
  msa_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, M * K, "MBCAE_M U16");
}

static void test_mbcae_m_u32() {
  const size_t M = 8;
  const size_t K = 4;
  const size_t stride = K * sizeof(uint32_t);
  const uint32_t src[] = {
      3989409382, 3920324652, 2411070431, 2823953980, 2505519419, 1091324908,
      3801260950, 98320923,   2199864084, 2119219749, 1099400789, 1405698776,
      2196198014, 3817690013, 3108097068, 4175590998, 3231173074, 549522083,
      2358573328, 2623762825, 3941992683, 63656290,   3959661593, 1942303697,
      3787383118, 768399281,  881489350,  3820705763, 2065131711, 2504356931,
      632364752,  3106270315};
  const uint32_t ans[] = {
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  muint32_t ms = mla_m(src, stride);
  muint32_t md = mbcae_m(ms);
  msa_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * K, "MBCAE_M U32");
}

static void test_mbcae_m_u64() {
  const size_t M = 8;
  const size_t K = 2;
  const size_t stride = K * sizeof(uint64_t);
  const uint64_t src[] = {
      7308779709197070745,  12155779903504350874, 15742832390281634628,
      18363449304327437809, 16720424843240370148, 18055941332905357865,
      17897927201706768868, 16280124223894768875, 13243845895538846845,
      368439777315246442,   15968270664722670195, 4065484585229421582,
      17181904194087435767, 8388205463641575952,  3582091909137408722,
      9603567256529961273};
  const uint64_t ans[] = {
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  muint64_t ms = mla_m(src, stride);
  muint64_t md = mbcae_m(ms);
  msa_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * K, "MBCAE_M U64");
}

static void test_mbcbe_m_u8() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  const uint8_t src[] = {31,  114, 233, 68,  236, 16,  237, 81,  114, 217, 216,
                         103, 143, 239, 238, 36,  197, 46,  179, 53,  188, 247,
                         243, 74,  191, 216, 224, 64,  92,  69,  0,   204, 64,
                         40,  193, 11,  156, 54,  14,  14,  23,  221, 57,  70,
                         20,  104, 82,  105, 220, 191, 70,  196, 132, 227, 46,
                         74,  25,  199, 35,  23,  46,  251, 101, 102};
  const uint8_t ans[] = {31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31};
  SET_MBA0_I8();
  msettilek(K);
  msettilen(N);
  muint8_t ms = mlb_m(src, stride);
  muint8_t md = mbcbe_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBE_M U8");
}

static void test_mbcbe_m_u16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  const uint16_t src[] = {
      19847, 12164, 64849, 59035, 43536, 50384, 29196, 36819, 35576, 27922,
      40393, 2750,  56403, 33402, 49066, 22451, 36077, 44342, 27110, 40034,
      62910, 25966, 43854, 37246, 8029,  18441, 30894, 9992,  17696, 58503,
      10379, 486,   4784,  19570, 12357, 25332, 62688, 21334, 51022, 5356,
      355,   41537, 63958, 9534,  26639, 34214, 14289, 6919,  62040, 42954,
      7568,  53407, 12061, 50516, 3010,  46167, 50847, 4467,  22364, 39414,
      50195, 14464, 19236, 33624};
  const uint16_t ans[] = {
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847};
  SET_MBA0_I16();
  msettilek(K);
  msettilen(N);
  muint16_t ms = mlb_m(src, stride);
  muint16_t md = mbcbe_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBE_M U16");
}

static void test_mbcbe_m_u32() {
  const size_t K = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  const uint32_t src[] = {
      3989409382, 3920324652, 2411070431, 2823953980, 2505519419, 1091324908,
      3801260950, 98320923,   2199864084, 2119219749, 1099400789, 1405698776,
      2196198014, 3817690013, 3108097068, 4175590998, 3231173074, 549522083,
      2358573328, 2623762825, 3941992683, 63656290,   3959661593, 1942303697,
      3787383118, 768399281,  881489350,  3820705763, 2065131711, 2504356931,
      632364752,  3106270315};
  const uint32_t ans[] = {
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382};
  SET_MBA0_I32();
  msettilek(K);
  msettilen(N);
  muint32_t ms = mlb_m(src, stride);
  muint32_t md = mbcbe_m(ms);
  msb_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, K * N, "MBCBE_M U32");
}

static void test_mbcbe_m_u64() {
  const size_t K = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  const uint64_t src[] = {
      7308779709197070745,  12155779903504350874, 15742832390281634628,
      18363449304327437809, 16720424843240370148, 18055941332905357865,
      17897927201706768868, 16280124223894768875, 13243845895538846845,
      368439777315246442,   15968270664722670195, 4065484585229421582,
      17181904194087435767, 8388205463641575952,  3582091909137408722,
      9603567256529961273};
  const uint64_t ans[] = {
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745};
  SET_MBA0_I64();
  msettilek(K);
  msettilen(N);
  muint64_t ms = mlb_m(src, stride);
  muint64_t md = mbcbe_m(ms);
  msb_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, K * N, "MBCBE_M U64");
}

static void test_mbcce_m_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  const uint8_t src[] = {31,  114, 233, 68,  236, 16,  237, 81,  114, 217, 216,
                         103, 143, 239, 238, 36,  197, 46,  179, 53,  188, 247,
                         243, 74,  191, 216, 224, 64,  92,  69,  0,   204, 64,
                         40,  193, 11,  156, 54,  14,  14,  23,  221, 57,  70,
                         20,  104, 82,  105, 220, 191, 70,  196, 132, 227, 46,
                         74,  25,  199, 35,  23,  46,  251, 101, 102};
  const uint8_t ans[] = {31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
                         31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, stride);
  muint8_t md = mbcce_m(ms);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MBCCE_M U8");
}

static void test_mbcce_m_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  const uint16_t src[] = {
      19847, 12164, 64849, 59035, 43536, 50384, 29196, 36819, 35576, 27922,
      40393, 2750,  56403, 33402, 49066, 22451, 36077, 44342, 27110, 40034,
      62910, 25966, 43854, 37246, 8029,  18441, 30894, 9992,  17696, 58503,
      10379, 486,   4784,  19570, 12357, 25332, 62688, 21334, 51022, 5356,
      355,   41537, 63958, 9534,  26639, 34214, 14289, 6919,  62040, 42954,
      7568,  53407, 12061, 50516, 3010,  46167, 50847, 4467,  22364, 39414,
      50195, 14464, 19236, 33624};
  const uint16_t ans[] = {
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847, 19847,
      19847, 19847, 19847, 19847};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, stride);
  muint16_t md = mbcce_m(ms);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u8_buffer, M * N, "MBCCE_M U16");
}

static void test_mbcce_m_u32() {
  const size_t M = 8;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  const uint32_t src[] = {
      3989409382, 3920324652, 2411070431, 2823953980, 2505519419, 1091324908,
      3801260950, 98320923,   2199864084, 2119219749, 1099400789, 1405698776,
      2196198014, 3817690013, 3108097068, 4175590998, 3231173074, 549522083,
      2358573328, 2623762825, 3941992683, 63656290,   3959661593, 1942303697,
      3787383118, 768399281,  881489350,  3820705763, 2065131711, 2504356931,
      632364752,  3106270315};
  const uint32_t ans[] = {
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382, 3989409382, 3989409382, 3989409382, 3989409382,
      3989409382, 3989409382};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, stride);
  muint32_t md = mbcce_m(ms);
  msc_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MBCCE_M U32");
}

static void test_mbcce_m_u64() {
  const size_t M = 8;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  const uint64_t src[] = {
      7308779709197070745,  12155779903504350874, 15742832390281634628,
      18363449304327437809, 16720424843240370148, 18055941332905357865,
      17897927201706768868, 16280124223894768875, 13243845895538846845,
      368439777315246442,   15968270664722670195, 4065484585229421582,
      17181904194087435767, 8388205463641575952,  3582091909137408722,
      9603567256529961273};
  const uint64_t ans[] = {
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745, 7308779709197070745, 7308779709197070745,
      7308779709197070745};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, stride);
  muint64_t md = mbcce_m(ms);
  msc_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MBCCE_M U64");
}

static void test_mbcce_m_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  const fp16_t src[] = {
      -5.105, 8.87,    -7.625, -3.514, -2.967, 6.598,  -2.098, 5.582,
      -5.64,  -4.805,  1.735,  8.984,  -0.25,  0.2761, -6.54,  4.18,
      -3.635, -0.9277, 2.844,  -9.55,  8.7,    -2.678, -5.47,  9.98,
      -9.375, 9.38,    3.418,  8.09,   5.484,  4.05,   7.316,  0.8955,
      -4.9,   8.08,    9.6,    6.73,   0.3462, -5.207, 2.965,  1.738,
      7.605,  1.37,    -8.95,  3.746,  -5.53,  6.297,  -6.95,  7.89,
      8.33,   3.084,   8.32,   -8.93,  7.754,  3.213,  5.04,   8.52,
      -8.984, 5.656,   1.938,  -6.555, 4.945,  -0.184, -1.357, 0.9595};
  const fp16_t ans[] = {
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, stride);
  mfloat16_t md = mbcce_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCE_M F16");
}

static void test_mbcce_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  const fp32_t src[] = {-1.8194413, 7.8502493, -6.510312,  -4.364824,
                        0.92431074, 1.861387,  9.012739,   -0.34902114,
                        -0.9701752, 3.9547222, 9.937506,   -8.996556,
                        -8.029423,  -8.197484, 0.12765718, 1.2457145};
  const fp32_t ans[] = {-1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, stride);
  mfloat32_t md = mbcce_m(ms);
  msc_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * N, "MBCCE_M F32");
}

static void test_mbcce_m_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  const fp64_t src[] = {4.33113695, -1.81790527, 1.58037653, 2.93150723};
  const fp64_t ans[] = {4.33113695, 4.33113695, 4.33113695, 4.33113695};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, stride);
  mfloat64_t md = mbcce_m(ms);
  msc_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * N, "MBCCE_M F64");
}

static void test_mbcbe_m_f16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  const fp16_t src[] = {
      -5.105, 8.87,    -7.625, -3.514, -2.967, 6.598,  -2.098, 5.582,
      -5.64,  -4.805,  1.735,  8.984,  -0.25,  0.2761, -6.54,  4.18,
      -3.635, -0.9277, 2.844,  -9.55,  8.7,    -2.678, -5.47,  9.98,
      -9.375, 9.38,    3.418,  8.09,   5.484,  4.05,   7.316,  0.8955,
      -4.9,   8.08,    9.6,    6.73,   0.3462, -5.207, 2.965,  1.738,
      7.605,  1.37,    -8.95,  3.746,  -5.53,  6.297,  -6.95,  7.89,
      8.33,   3.084,   8.32,   -8.93,  7.754,  3.213,  5.04,   8.52,
      -8.984, 5.656,   1.938,  -6.555, 4.945,  -0.184, -1.357, 0.9595};
  const fp16_t ans[] = {
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105};
  SET_MBA0_F16();
  msettilek(K);
  msettilen(N);
  mfloat16_t ms = mlb_m(src, stride);
  mfloat16_t md = mbcbe_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBE_M F16");
}

static void test_mbcbe_m_f32() {
  const size_t K = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  const fp32_t src[] = {-1.8194413, 7.8502493, -6.510312,  -4.364824,
                        0.92431074, 1.861387,  9.012739,   -0.34902114,
                        -0.9701752, 3.9547222, 9.937506,   -8.996556,
                        -8.029423,  -8.197484, 0.12765718, 1.2457145};
  const fp32_t ans[] = {-1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413};
  SET_MBA0_F32();
  msettilek(K);
  msettilen(N);
  mfloat32_t ms = mlb_m(src, stride);
  mfloat32_t md = mbcbe_m(ms);
  msb_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, K * N, "MBCBE_M F32");
}

static void test_mbcbe_m_f64() {
  const size_t K = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  const fp64_t src[] = {4.33113695, -1.81790527, 1.58037653, 2.93150723};
  const fp64_t ans[] = {4.33113695, 4.33113695, 4.33113695, 4.33113695};
  SET_MBA0_F64();
  msettilek(K);
  msettilen(N);
  mfloat64_t ms = mlb_m(src, stride);
  mfloat64_t md = mbcbe_m(ms);
  msb_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, K * N, "MBCBE_M F64");
}

static void test_mbcae_m_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(fp16_t);
  const fp16_t src[] = {
      -5.105, 8.87,    -7.625, -3.514, -2.967, 6.598,  -2.098, 5.582,
      -5.64,  -4.805,  1.735,  8.984,  -0.25,  0.2761, -6.54,  4.18,
      -3.635, -0.9277, 2.844,  -9.55,  8.7,    -2.678, -5.47,  9.98,
      -9.375, 9.38,    3.418,  8.09,   5.484,  4.05,   7.316,  0.8955,
      -4.9,   8.08,    9.6,    6.73,   0.3462, -5.207, 2.965,  1.738,
      7.605,  1.37,    -8.95,  3.746,  -5.53,  6.297,  -6.95,  7.89,
      8.33,   3.084,   8.32,   -8.93,  7.754,  3.213,  5.04,   8.52,
      -8.984, 5.656,   1.938,  -6.555, 4.945,  -0.184, -1.357, 0.9595};
  const fp16_t ans[] = {
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105,
      -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105, -5.105};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  mfloat16_t ms = mla_m(src, stride);
  mfloat16_t md = mbcae_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAE_M F16");
}

static void test_mbcae_m_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(fp32_t);
  const fp32_t src[] = {-1.8194413, 7.8502493, -6.510312,  -4.364824,
                        0.92431074, 1.861387,  9.012739,   -0.34902114,
                        -0.9701752, 3.9547222, 9.937506,   -8.996556,
                        -8.029423,  -8.197484, 0.12765718, 1.2457145};
  const fp32_t ans[] = {-1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413,
                        -1.8194413, -1.8194413, -1.8194413, -1.8194413};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  mfloat32_t ms = mla_m(src, stride);
  mfloat32_t md = mbcae_m(ms);
  msa_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * K, "MBCAE_M F32");
}

static void test_mbcae_m_f64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(fp64_t);
  const fp64_t src[] = {4.33113695, -1.81790527, 1.58037653, 2.93150723};
  const fp64_t ans[] = {4.33113695, 4.33113695, 4.33113695, 4.33113695};
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  mfloat64_t ms = mla_m(src, stride);
  mfloat64_t md = mbcae_m(ms);
  msa_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * K, "MBCAE_M F64");
}

static void test_mbccr_m_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  const fp16_t src[] = {
      -0.8955, 6.676,    -2.502, -3.725, -7.684, 0.9004,  9.445,  8.07,
      2.22,    -0.325,   3.643,  8.48,   -1.413, 1.675,   -3.44,  2.127,
      8.26,    -7.16,    6.492,  -9.89,  5.203,  -0.4854, -3.57,  -4.89,
      -0.9077, 4.8,      0.4482, 7.19,   1.799,  4.773,   -8.67,  -6.105,
      -5.69,   0.1652,   3.33,   5.598,  -2.191, 1.703,   9.54,   5.562,
      6.87,    -8.33,    -7.484, 1.696,  -0.272, -0.793,  -6.242, -0.4434,
      2.51,    9.22,     9.34,   6.402,  -5.09,  -1.021,  8.54,   2.002,
      7.656,   -0.00992, 1.562,  -7.348, -6.254, 8.17,    -1.522, -9.766};
  const fp16_t ans[] = {
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, stride);
  mfloat16_t md = mbccr_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCR_M F16");
}

static void test_mbccr_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  const fp32_t src[] = {2.4341593,  0.86075234,  2.9517949, 2.4783812,
                        8.96967,    -6.387821,   4.0983267, -8.276018,
                        -5.1994543, -8.306698,   -9.860818, 1.3069794,
                        6.6508865,  -0.36102858, 8.585612,  -6.113518};
  const fp32_t ans[] = {2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, stride);
  mfloat32_t md = mbccr_m(ms);
  msc_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * N, "MBCCR_M F32");
}

static void test_mbccr_m_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  const fp64_t src[] = {3.02528944, 5.83357396, 5.99826743, 0.4087259};
  const fp64_t ans[] = {3.02528944, 5.83357396, 3.02528944, 5.83357396};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, stride);
  mfloat64_t md = mbccr_m(ms);
  msc_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * N, "MBCCR_M F64");
}

static void test_mbcbr_m_f16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  const fp16_t src[] = {
      -0.8955, 6.676,    -2.502, -3.725, -7.684, 0.9004,  9.445,  8.07,
      2.22,    -0.325,   3.643,  8.48,   -1.413, 1.675,   -3.44,  2.127,
      8.26,    -7.16,    6.492,  -9.89,  5.203,  -0.4854, -3.57,  -4.89,
      -0.9077, 4.8,      0.4482, 7.19,   1.799,  4.773,   -8.67,  -6.105,
      -5.69,   0.1652,   3.33,   5.598,  -2.191, 1.703,   9.54,   5.562,
      6.87,    -8.33,    -7.484, 1.696,  -0.272, -0.793,  -6.242, -0.4434,
      2.51,    9.22,     9.34,   6.402,  -5.09,  -1.021,  8.54,   2.002,
      7.656,   -0.00992, 1.562,  -7.348, -6.254, 8.17,    -1.522, -9.766};
  const fp16_t ans[] = {
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07};
  SET_MBA0_F16();
  msettilek(K);
  msettilen(N);
  mfloat16_t ms = mlb_m(src, stride);
  mfloat16_t md = mbcbr_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBR_M F16");
}

static void test_mbcbr_m_f32() {
  const size_t K = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  const fp32_t src[] = {2.4341593,  0.86075234,  2.9517949, 2.4783812,
                        8.96967,    -6.387821,   4.0983267, -8.276018,
                        -5.1994543, -8.306698,   -9.860818, 1.3069794,
                        6.6508865,  -0.36102858, 8.585612,  -6.113518};
  const fp32_t ans[] = {2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812};
  SET_MBA0_F32();
  msettilek(K);
  msettilen(N);
  mfloat32_t ms = mlb_m(src, stride);
  mfloat32_t md = mbcbr_m(ms);
  msb_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, K * N, "MBCBR_M F32");
}

static void test_mbcbr_m_f64() {
  const size_t K = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  const fp64_t src[] = {3.02528944, 5.83357396, 5.99826743, 0.4087259};
  const fp64_t ans[] = {3.02528944, 5.83357396, 3.02528944, 5.83357396};
  SET_MBA0_F64();
  msettilek(K);
  msettilen(N);
  mfloat64_t ms = mlb_m(src, stride);
  mfloat64_t md = mbcbr_m(ms);
  msb_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, K * N, "MBCBR_M F64");
}

static void test_mbcar_m_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(fp16_t);
  const fp16_t src[] = {
      -0.8955, 6.676,    -2.502, -3.725, -7.684, 0.9004,  9.445,  8.07,
      2.22,    -0.325,   3.643,  8.48,   -1.413, 1.675,   -3.44,  2.127,
      8.26,    -7.16,    6.492,  -9.89,  5.203,  -0.4854, -3.57,  -4.89,
      -0.9077, 4.8,      0.4482, 7.19,   1.799,  4.773,   -8.67,  -6.105,
      -5.69,   0.1652,   3.33,   5.598,  -2.191, 1.703,   9.54,   5.562,
      6.87,    -8.33,    -7.484, 1.696,  -0.272, -0.793,  -6.242, -0.4434,
      2.51,    9.22,     9.34,   6.402,  -5.09,  -1.021,  8.54,   2.002,
      7.656,   -0.00992, 1.562,  -7.348, -6.254, 8.17,    -1.522, -9.766};
  const fp16_t ans[] = {
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07,
      -0.8955, 6.676, -2.502, -3.725, -7.684, 0.9004, 9.445, 8.07};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  mfloat16_t ms = mla_m(src, stride);
  mfloat16_t md = mbcar_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAR_M F16");
}

static void test_mbcar_m_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(fp32_t);
  const fp32_t src[] = {2.4341593,  0.86075234,  2.9517949, 2.4783812,
                        8.96967,    -6.387821,   4.0983267, -8.276018,
                        -5.1994543, -8.306698,   -9.860818, 1.3069794,
                        6.6508865,  -0.36102858, 8.585612,  -6.113518};
  const fp32_t ans[] = {2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812,
                        2.4341593, 0.86075234, 2.9517949, 2.4783812};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  mfloat32_t ms = mla_m(src, stride);
  mfloat32_t md = mbcar_m(ms);
  msa_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * K, "MBCAR_M F32");
}

static void test_mbcar_m_f64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(fp64_t);
  const fp64_t src[] = {3.02528944, 5.83357396, 5.99826743, 0.4087259};
  const fp64_t ans[] = {3.02528944, 5.83357396, 3.02528944, 5.83357396};
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  mfloat64_t ms = mla_m(src, stride);
  mfloat64_t md = mbcar_m(ms);
  msa_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * K, "MBCAR_M F64");
}

static void test_mbccc_m_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  const fp16_t src[] = {
      -4.875, 3.39,   -2.096, 1.699,    -2.66,   7.793,  -5.06,  6.223,
      3.035,  1.014,  4.41,   -0.03558, 6.426,   -1.783, 2.371,  0.705,
      -3.234, 4.617,  9.23,   -3.902,   0.0693,  -0.796, -6.926, -7.953,
      -6.434, 8.19,   -1.528, 4.305,    -0.5386, 3.008,  4.44,   2.242,
      1.261,  -6.09,  -2.76,  -2.95,    1.3955,  -5.508, 8.36,   3.316,
      -5.63,  -6.56,  9.61,   -7.02,    9.57,    1.61,   1.149,  -0.6445,
      9.94,   -1.368, -1.113, -0.8,     4.34,    -2.705, -9.77,  -6.31,
      7.582,  -2.816, 6.594,  3.97,     -7.312,  9.57,   7.492,  1.785};
  const fp16_t ans[] = {
      -4.875, -4.875, -4.875, -4.875, -4.875, -4.875, -4.875, -4.875,
      3.035,  3.035,  3.035,  3.035,  3.035,  3.035,  3.035,  3.035,
      -3.234, -3.234, -3.234, -3.234, -3.234, -3.234, -3.234, -3.234,
      -6.434, -6.434, -6.434, -6.434, -6.434, -6.434, -6.434, -6.434,
      1.261,  1.261,  1.261,  1.261,  1.261,  1.261,  1.261,  1.261,
      -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,
      9.94,   9.94,   9.94,   9.94,   9.94,   9.94,   9.94,   9.94,
      7.582,  7.582,  7.582,  7.582,  7.582,  7.582,  7.582,  7.582};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, stride);
  mfloat16_t md = mbccc_m(ms);
  msc_m(md, i8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, i8_buffer, M * N, "MBCCC_M F16");
}

static void test_mbccc_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  const fp32_t src[] = {-7.6936803, -1.9407004, -9.125422,   -8.124201,
                        0.07061221, 8.656778,   -4.9118924,  -4.566506,
                        -2.3865843, 4.214645,   8.443874,    -1.8578162,
                        5.3037033,  -2.1532393, -0.62118703, -7.048722};
  const fp32_t ans[] = {-7.6936803, -7.6936803, -7.6936803, -7.6936803,
                        0.07061221, 0.07061221, 0.07061221, 0.07061221,
                        -2.3865843, -2.3865843, -2.3865843, -2.3865843,
                        5.3037033,  5.3037033,  5.3037033,  5.3037033};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, stride);
  mfloat32_t md = mbccc_m(ms);
  msc_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * N, "MBCCC_M F32");
}

static void test_mbccc_m_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  const fp64_t src[] = {6.73263389, 5.47753985, -4.28081835, -6.83835533};
  const fp64_t ans[] = {6.73263389, 6.73263389, -4.28081835, -4.28081835};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, stride);
  mfloat64_t md = mbccc_m(ms);
  msc_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * N, "MBCCC_M F64");
}

static void test_mbcbc_m_f16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  const fp16_t src[] = {
      -4.875, 3.39,   -2.096, 1.699,    -2.66,   7.793,  -5.06,  6.223,
      3.035,  1.014,  4.41,   -0.03558, 6.426,   -1.783, 2.371,  0.705,
      -3.234, 4.617,  9.23,   -3.902,   0.0693,  -0.796, -6.926, -7.953,
      -6.434, 8.19,   -1.528, 4.305,    -0.5386, 3.008,  4.44,   2.242,
      1.261,  -6.09,  -2.76,  -2.95,    1.3955,  -5.508, 8.36,   3.316,
      -5.63,  -6.56,  9.61,   -7.02,    9.57,    1.61,   1.149,  -0.6445,
      9.94,   -1.368, -1.113, -0.8,     4.34,    -2.705, -9.77,  -6.31,
      7.582,  -2.816, 6.594,  3.97,     -7.312,  9.57,   7.492,  1.785};
  const fp16_t ans[] = {
      -4.875, -4.875, -4.875, -4.875, -4.875, -4.875, -4.875, -4.875,
      3.035,  3.035,  3.035,  3.035,  3.035,  3.035,  3.035,  3.035,
      -3.234, -3.234, -3.234, -3.234, -3.234, -3.234, -3.234, -3.234,
      -6.434, -6.434, -6.434, -6.434, -6.434, -6.434, -6.434, -6.434,
      1.261,  1.261,  1.261,  1.261,  1.261,  1.261,  1.261,  1.261,
      -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,
      9.94,   9.94,   9.94,   9.94,   9.94,   9.94,   9.94,   9.94,
      7.582,  7.582,  7.582,  7.582,  7.582,  7.582,  7.582,  7.582};
  SET_MBA0_F16();
  msettilek(K);
  msettilen(N);
  mfloat16_t ms = mlb_m(src, stride);
  mfloat16_t md = mbcbc_m(ms);
  msb_m(md, u8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, u8_buffer, K * N, "MBCBC_M F16");
}

static void test_mbcbc_m_f32() {
  const size_t K = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  const fp32_t src[] = {-7.6936803, -1.9407004, -9.125422,   -8.124201,
                        0.07061221, 8.656778,   -4.9118924,  -4.566506,
                        -2.3865843, 4.214645,   8.443874,    -1.8578162,
                        5.3037033,  -2.1532393, -0.62118703, -7.048722};
  const fp32_t ans[] = {-7.6936803, -7.6936803, -7.6936803, -7.6936803,
                        0.07061221, 0.07061221, 0.07061221, 0.07061221,
                        -2.3865843, -2.3865843, -2.3865843, -2.3865843,
                        5.3037033,  5.3037033,  5.3037033,  5.3037033};
  SET_MBA0_F32();
  msettilek(K);
  msettilen(N);
  mfloat32_t ms = mlb_m(src, stride);
  mfloat32_t md = mbcbc_m(ms);
  msb_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, K * N, "MBCBC_M F32");
}

static void test_mbcbc_m_f64() {
  const size_t K = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  const fp64_t src[] = {6.73263389, 5.47753985, -4.28081835, -6.83835533};
  const fp64_t ans[] = {6.73263389, 6.73263389, -4.28081835, -4.28081835};
  SET_MBA0_F64();
  msettilek(K);
  msettilen(N);
  mfloat64_t ms = mlb_m(src, stride);
  mfloat64_t md = mbcbc_m(ms);
  msb_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, K * N, "MBCBC_M F64");
}

static void test_mbcac_m_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(fp16_t);
  const fp16_t src[] = {
      -4.875, 3.39,   -2.096, 1.699,    -2.66,   7.793,  -5.06,  6.223,
      3.035,  1.014,  4.41,   -0.03558, 6.426,   -1.783, 2.371,  0.705,
      -3.234, 4.617,  9.23,   -3.902,   0.0693,  -0.796, -6.926, -7.953,
      -6.434, 8.19,   -1.528, 4.305,    -0.5386, 3.008,  4.44,   2.242,
      1.261,  -6.09,  -2.76,  -2.95,    1.3955,  -5.508, 8.36,   3.316,
      -5.63,  -6.56,  9.61,   -7.02,    9.57,    1.61,   1.149,  -0.6445,
      9.94,   -1.368, -1.113, -0.8,     4.34,    -2.705, -9.77,  -6.31,
      7.582,  -2.816, 6.594,  3.97,     -7.312,  9.57,   7.492,  1.785};
  const fp16_t ans[] = {
      -4.875, -4.875, -4.875, -4.875, -4.875, -4.875, -4.875, -4.875,
      3.035,  3.035,  3.035,  3.035,  3.035,  3.035,  3.035,  3.035,
      -3.234, -3.234, -3.234, -3.234, -3.234, -3.234, -3.234, -3.234,
      -6.434, -6.434, -6.434, -6.434, -6.434, -6.434, -6.434, -6.434,
      1.261,  1.261,  1.261,  1.261,  1.261,  1.261,  1.261,  1.261,
      -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,  -5.63,
      9.94,   9.94,   9.94,   9.94,   9.94,   9.94,   9.94,   9.94,
      7.582,  7.582,  7.582,  7.582,  7.582,  7.582,  7.582,  7.582};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  mfloat16_t ms = mla_m(src, stride);
  mfloat16_t md = mbcac_m(ms);
  msa_m(md, i8_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, i8_buffer, M * K, "MBCAC_M F16");
}

static void test_mbcac_m_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(fp32_t);
  const fp32_t src[] = {-7.6936803, -1.9407004, -9.125422,   -8.124201,
                        0.07061221, 8.656778,   -4.9118924,  -4.566506,
                        -2.3865843, 4.214645,   8.443874,    -1.8578162,
                        5.3037033,  -2.1532393, -0.62118703, -7.048722};
  const fp32_t ans[] = {-7.6936803, -7.6936803, -7.6936803, -7.6936803,
                        0.07061221, 0.07061221, 0.07061221, 0.07061221,
                        -2.3865843, -2.3865843, -2.3865843, -2.3865843,
                        5.3037033,  5.3037033,  5.3037033,  5.3037033};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  mfloat32_t ms = mla_m(src, stride);
  mfloat32_t md = mbcac_m(ms);
  msa_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * K, "MBCAC_M F32");
}

static void test_mbcac_m_f64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(fp64_t);
  const fp64_t src[] = {6.73263389, 5.47753985, -4.28081835, -6.83835533};
  const fp64_t ans[] = {6.73263389, 6.73263389, -4.28081835, -4.28081835};
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  mfloat64_t ms = mla_m(src, stride);
  mfloat64_t md = mbcac_m(ms);
  msa_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * K, "MBCAC_M F64");
}

static void test_mbcce_m() {
  test_mbcce_m_i8();
  test_mbcce_m_i16();
  test_mbcce_m_i32();
  test_mbcce_m_i64();
  test_mbcce_m_u8();
  test_mbcce_m_u16();
  test_mbcce_m_u32();
  test_mbcce_m_u64();
  test_mbcce_m_f16();
  test_mbcce_m_f32();
  test_mbcce_m_f64();
}

static void test_mbcbe_m() {
  test_mbcbe_m_i8();
  test_mbcbe_m_i16();
  test_mbcbe_m_i32();
  test_mbcbe_m_i64();
  test_mbcbe_m_u8();
  test_mbcbe_m_u16();
  test_mbcbe_m_u32();
  test_mbcbe_m_u64();
  test_mbcbe_m_f16();
  test_mbcbe_m_f32();
  test_mbcbe_m_f64();
}

static void test_mbcae_m() {
  test_mbcae_m_i8();
  test_mbcae_m_i16();
  test_mbcae_m_i32();
  test_mbcae_m_i64();
  test_mbcae_m_u8();
  test_mbcae_m_u16();
  test_mbcae_m_u32();
  test_mbcae_m_u64();
  test_mbcae_m_f16();
  test_mbcae_m_f32();
  test_mbcae_m_f64();
}

static void test_mbccc_m() {
  test_mbccc_m_i8();
  test_mbccc_m_i16();
  test_mbccc_m_i32();
  test_mbccc_m_i64();
  test_mbccc_m_u8();
  test_mbccc_m_u16();
  test_mbccc_m_u32();
  test_mbccc_m_u64();
  test_mbccc_m_f16();
  test_mbccc_m_f32();
  test_mbccc_m_f64();
}

static void test_mbcbc_m() {
  test_mbcbc_m_i8();
  test_mbcbc_m_i16();
  test_mbcbc_m_i32();
  test_mbcbc_m_i64();
  test_mbcbc_m_u8();
  test_mbcbc_m_u16();
  test_mbcbc_m_u32();
  test_mbcbc_m_u64();
  test_mbcbc_m_f16();
  test_mbcbc_m_f32();
  test_mbcbc_m_f64();
}

static void test_mbcac_m() {
  test_mbcac_m_i8();
  test_mbcac_m_i16();
  test_mbcac_m_i32();
  test_mbcac_m_i64();
  test_mbcac_m_u8();
  test_mbcac_m_u16();
  test_mbcac_m_u32();
  test_mbcac_m_u64();
  test_mbcac_m_f16();
  test_mbcac_m_f32();
  test_mbcac_m_f64();
}

static void test_mbccr_m() {
  test_mbccr_m_i8();
  test_mbccr_m_i16();
  test_mbccr_m_i32();
  test_mbccr_m_i64();
  test_mbccr_m_u8();
  test_mbccr_m_u16();
  test_mbccr_m_u32();
  test_mbccr_m_u64();
  test_mbccr_m_f16();
  test_mbccr_m_f32();
  test_mbccr_m_f64();
}

static void test_mbcbr_m() {
  test_mbcbr_m_i8();
  test_mbcbr_m_i16();
  test_mbcbr_m_i32();
  test_mbcbr_m_i64();
  test_mbcbr_m_u8();
  test_mbcbr_m_u16();
  test_mbcbr_m_u32();
  test_mbcbr_m_u64();
  test_mbcbr_m_f16();
  test_mbcbr_m_f32();
  test_mbcbr_m_f64();
}

static void test_mbcar_m() {
  test_mbcar_m_i8();
  test_mbcar_m_i16();
  test_mbcar_m_i32();
  test_mbcar_m_i64();
  test_mbcar_m_u8();
  test_mbcar_m_u16();
  test_mbcar_m_u32();
  test_mbcar_m_u64();
  test_mbcar_m_f16();
  test_mbcar_m_f32();
  test_mbcar_m_f64();
}

static void test_mfmv_t_f() {
  test_mfmv_t_f_f16();
  test_mfmv_t_f_f32();
  test_mfmv_t_f_f64();
}

static void test_mfmv_f_t() {
  test_mfmv_f_t_f16();
  test_mfmv_f_t_f32();
  test_mfmv_f_t_f64();
}

static void test_mfmv_a_f() {
  test_mfmv_a_f_f16();
  test_mfmv_a_f_f32();
  test_mfmv_a_f_f64();
}

static void test_mfmv_f_a() {
  test_mfmv_f_a_f16();
  test_mfmv_f_a_f32();
  test_mfmv_f_a_f64();
}

static void test_mmv_t_x() {
  test_mmv_t_x_i8();
  test_mmv_t_x_u8();
  test_mmv_t_x_i16();
  test_mmv_t_x_u16();
  test_mmv_t_x_i32();
  test_mmv_t_x_u32();
  test_mmv_t_x_i64();
  test_mmv_t_x_u64();
}

static void test_mmv_x_t() {
  test_mmv_x_t_i8();
  test_mmv_x_t_u8();
  test_mmv_x_t_i16();
  test_mmv_x_t_u16();
  test_mmv_x_t_i32();
  test_mmv_x_t_u32();
  test_mmv_x_t_i64();
  test_mmv_x_t_u64();
}

static void test_mmv_a_x() {
  test_mmv_a_x_i8();
  test_mmv_a_x_u8();
  test_mmv_a_x_i16();
  test_mmv_a_x_u16();
  test_mmv_a_x_i32();
  test_mmv_a_x_u32();
  test_mmv_a_x_i64();
  test_mmv_a_x_u64();
}

static void test_mmv_x_a() {
  test_mmv_x_a_i8();
  test_mmv_x_a_u8();
  test_mmv_x_a_i16();
  test_mmv_x_a_u16();
  test_mmv_x_a_i32();
  test_mmv_x_a_u32();
  test_mmv_x_a_i64();
  test_mmv_x_a_u64();
}

static void test_data_move() {
  test_mmv_x_t();
  test_mmv_t_x();
  test_mmv_a_x();
  test_mmv_x_a();
  test_mfmv_f_t();
  test_mfmv_t_f();
  test_mfmv_a_f();
  test_mfmv_f_a();
  // // test_mmv_t_t();
  test_mbcar_m();
  test_mbcbr_m();
  test_mbccr_m();
  test_mbcac_m();
  test_mbcbc_m();
  test_mbccc_m();
  test_mbcae_m();
  test_mbcbe_m();
  test_mbcce_m();
}