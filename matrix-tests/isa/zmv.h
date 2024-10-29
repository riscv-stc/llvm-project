#ifndef MATRIX_TESTS_ISA_ZMV_H_
#define MATRIX_TESTS_ISA_ZMV_H_

#include "load_store.h"
#include "riscv_matrix.h"
#include "riscv_vector.h"
#include "utils.h"

static void test_mla_v_msa_v_i8() {
  const size_t M = 8;
  const size_t K = 8;
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  vint8m1_t vs = mla_v(ls_i8_src, K * sizeof(int8_t));
  msa_v(vs, i8_buffer, K * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, M * K, "MLA_V & MSA_V I8");
}

static void test_mla_v_msa_v_u8() {
  const size_t M = 8;
  const size_t K = 8;
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  vuint8m1_t vs = mla_v(ls_u8_src, K * sizeof(uint8_t));
  msa_v(vs, u8_buffer, K * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, M * K, "MLA_V & MSA_V U8");
}

static void test_mla_v_msa_v_i16() {
  const size_t M = 8;
  const size_t K = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  vint16m1_t vs = mla_v(ls_i16_src, K * sizeof(int16_t));
  msa_v(vs, i16_buffer, K * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, M * K, "MLA_V & MSA_V I16");
}

static void test_mla_v_msa_v_u16() {
  const size_t M = 8;
  const size_t K = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  vuint16m1_t vs = mla_v(ls_u16_src, K * sizeof(uint16_t));
  msa_v(vs, u16_buffer, K * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, M * K, "MLA_V & MSA_V U16");
}

static void test_mla_v_msa_v_f16() {
  const size_t M = 8;
  const size_t K = 8;
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  vfloat16m1_t vs = mla_v(ls_f16_src, K * sizeof(fp16_t));
  msa_v(vs, f16_buffer, K * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, M * K, "MLA_V & MSA_V F16");
}

static void test_mla_v_msa_v_i32() {
  const size_t M = 4;
  const size_t K = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  vint32m1_t vs = mla_v(ls_i32_src, K * sizeof(int32_t));
  msa_v(vs, i32_buffer, K * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, M * K, "MLA_V & MSA_V I32");
}

static void test_mla_v_msa_v_u32() {
  const size_t M = 4;
  const size_t K = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  vuint32m1_t vs = mla_v(ls_u32_src, K * sizeof(uint32_t));
  msa_v(vs, u32_buffer, K * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, M * K, "MLA_V & MSA_V U32");
}

static void test_mla_v_msa_v_f32() {
  const size_t M = 4;
  const size_t K = 4;
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  vfloat32m1_t vs = mla_v(ls_f32_src, K * sizeof(fp32_t));
  msa_v(vs, f32_buffer, K * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, M * K, "MLA_V & MSA_V F32");
}

static void test_mla_v_msa_v_i64() {
  const size_t M = 2;
  const size_t K = 2;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  vint64m1_t vs = mla_v(ls_i64_src, K * sizeof(int64_t));
  msa_v(vs, i64_buffer, K * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, M * K, "MLA_V & MSA_V I64");
}

static void test_mla_v_msa_v_u64() {
  const size_t M = 2;
  const size_t K = 2;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  vuint64m1_t vs = mla_v(ls_u64_src, K * sizeof(uint64_t));
  msa_v(vs, u64_buffer, K * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, M * K, "MLA_V & MSA_V U64");
}

static void test_mla_v_msa_v_f64() {
  const size_t M = 2;
  const size_t K = 2;
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  vfloat64m1_t vs = mla_v(ls_f64_src, K * sizeof(fp64_t));
  msa_v(vs, f64_buffer, K * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, M * K, "MLA_V & MSA_V F64");
}

static void test_mla_v_msa_v() {
  test_mla_v_msa_v_i8();
  test_mla_v_msa_v_u8();
  test_mla_v_msa_v_i16();
  test_mla_v_msa_v_u16();
  test_mla_v_msa_v_f16();
  test_mla_v_msa_v_i32();
  test_mla_v_msa_v_u32();
  test_mla_v_msa_v_f32();
  test_mla_v_msa_v_i64();
  test_mla_v_msa_v_u64();
  test_mla_v_msa_v_f64();
}

static void test_mlb_v_msb_v_i8() {
  const size_t N = 8;
  const size_t K = 8;
  SET_MBA0_I8();
  msettilen(N);
  msettilek(K);
  vint8m1_t vs = mlb_v(ls_i8_src, N * sizeof(int8_t));
  msb_v(vs, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, N * N, "MLB_V & MSB_V I8");
}

static void test_mlb_v_msb_v_u8() {
  const size_t N = 8;
  const size_t K = 8;
  SET_MBA0_I8();
  msettilen(N);
  msettilek(K);
  vuint8m1_t vs = mlb_v(ls_u8_src, N * sizeof(uint8_t));
  msb_v(vs, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, N * N, "MLB_V & MSB_V U8");
}

static void test_mlb_v_msb_v_i16() {
  const size_t N = 8;
  const size_t K = 8;
  SET_MBA0_I16();
  msettilen(N);
  msettilek(K);
  vint16m1_t vs = mlb_v(ls_i16_src, N * sizeof(int16_t));
  msb_v(vs, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, N * N, "MLB_V & MSB_V I16");
}

static void test_mlb_v_msb_v_u16() {
  const size_t N = 8;
  const size_t K = 8;
  SET_MBA0_I16();
  msettilen(N);
  msettilek(K);
  vuint16m1_t vs = mlb_v(ls_u16_src, N * sizeof(uint16_t));
  msb_v(vs, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, N * N, "MLB_V & MSB_V U16");
}

static void test_mlb_v_msb_v_f16() {
  const size_t N = 8;
  const size_t K = 8;
  SET_MBA0_F16();
  msettilen(N);
  msettilek(K);
  vfloat16m1_t vs = mlb_v(ls_f16_src, N * sizeof(fp16_t));
  msb_v(vs, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, N * N, "MLB_V & MSB_V F16");
}

static void test_mlb_v_msb_v_i32() {
  const size_t N = 4;
  const size_t K = 4;
  SET_MBA0_I32();
  msettilen(N);
  msettilek(K);
  vint32m1_t vs = mlb_v(ls_i32_src, N * sizeof(int32_t));
  msb_v(vs, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, N * N, "MLB_V & MSB_V I32");
}

static void test_mlb_v_msb_v_u32() {
  const size_t N = 4;
  const size_t K = 4;
  SET_MBA0_I32();
  msettilen(N);
  msettilek(K);
  vuint32m1_t vs = mlb_v(ls_u32_src, N * sizeof(uint32_t));
  msb_v(vs, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, N * N, "MLB_V & MSB_V U32");
}

static void test_mlb_v_msb_v_f32() {
  const size_t N = 4;
  const size_t K = 4;
  SET_MBA0_F32();
  msettilen(N);
  msettilek(K);
  vfloat32m1_t vs = mlb_v(ls_f32_src, N * sizeof(fp32_t));
  msb_v(vs, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, N * N, "MLB_V & MSB_V F32");
}

static void test_mlb_v_msb_v_i64() {
  const size_t N = 2;
  const size_t K = 2;
  SET_MBA0_I64();
  msettilen(N);
  msettilek(K);
  vint64m1_t vs = mlb_v(ls_i64_src, N * sizeof(int64_t));
  msb_v(vs, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, N * N, "MLB_V & MSB_V I64");
}

static void test_mlb_v_msb_v_u64() {
  const size_t N = 2;
  const size_t K = 2;
  SET_MBA0_I64();
  msettilen(N);
  msettilek(K);
  vuint64m1_t vs = mlb_v(ls_u64_src, N * sizeof(uint64_t));
  msb_v(vs, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, N * N, "MLB_V & MSB_V U64");
}

static void test_mlb_v_msb_v_f64() {
  const size_t N = 2;
  const size_t K = 2;
  SET_MBA0_F64();
  msettilen(N);
  msettilek(K);
  vfloat64m1_t vs = mlb_v(ls_f64_src, N * sizeof(fp64_t));
  msb_v(vs, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, N * N, "MLB_V & MSB_V F64");
}

static void test_mlb_v_msb_v() {
  test_mlb_v_msb_v_i8();
  test_mlb_v_msb_v_u8();
  test_mlb_v_msb_v_i16();
  test_mlb_v_msb_v_u16();
  test_mlb_v_msb_v_f16();
  test_mlb_v_msb_v_i32();
  test_mlb_v_msb_v_u32();
  test_mlb_v_msb_v_f32();
  test_mlb_v_msb_v_i64();
  test_mlb_v_msb_v_u64();
  test_mlb_v_msb_v_f64();
}

static void test_mlc_v_msc_v_i8() {
  const size_t M = 8;
  const size_t N = 8;
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  vint8m1_t vs = mlc_v(ls_i8_src, N * sizeof(int8_t));
  msc_v(vs, i8_buffer, N * sizeof(int8_t));
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, M * N, "MLC_V & MSC_V I8");
}

static void test_mlc_v_msc_v_u8() {
  const size_t M = 8;
  const size_t N = 8;
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  vuint8m1_t vs = mlc_v(ls_u8_src, N * sizeof(uint8_t));
  msc_v(vs, u8_buffer, N * sizeof(uint8_t));
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, M * N, "MLC_V & MSC_V U8");
}

static void test_mlc_v_msc_v_i16() {
  const size_t M = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  vint16m1_t vs = mlc_v(ls_i16_src, N * sizeof(int16_t));
  msc_v(vs, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, M * N, "MLC_V & MSC_V I16");
}

static void test_mlc_v_msc_v_u16() {
  const size_t M = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  vuint16m1_t vs = mlc_v(ls_u16_src, N * sizeof(uint16_t));
  msc_v(vs, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, M * N, "MLC_V & MSC_V U16");
}

static void test_mlc_v_msc_v_f16() {
  const size_t M = 8;
  const size_t N = 8;
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  vfloat16m1_t vs = mlc_v(ls_f16_src, N * sizeof(fp16_t));
  msc_v(vs, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, M * N, "MLC_V & MSC_V F16");
}

static void test_mlc_v_msc_v_i32() {
  const size_t M = 4;
  const size_t N = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  vint32m1_t vs = mlc_v(ls_i32_src, N * sizeof(int32_t));
  msc_v(vs, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, M * N, "MLC_V & MSC_V I32");
}

static void test_mlc_v_msc_v_u32() {
  const size_t M = 4;
  const size_t N = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  vuint32m1_t vs = mlc_v(ls_u32_src, N * sizeof(uint32_t));
  msc_v(vs, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, M * N, "MLC_V & MSC_V U32");
}

static void test_mlc_v_msc_v_f32() {
  const size_t M = 4;
  const size_t N = 4;
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  vfloat32m1_t vs = mlc_v(ls_f32_src, N * sizeof(fp32_t));
  msc_v(vs, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, M * N, "MLC_V & MSC_V F32");
}

static void test_mlc_v_msc_v_i64() {
  const size_t M = 2;
  const size_t N = 2;
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  vint64m1_t vs = mlc_v(ls_i64_src, N * sizeof(int64_t));
  msc_v(vs, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, M * N, "MLC_V & MSC_V I64");
}

static void test_mlc_v_msc_v_u64() {
  const size_t M = 2;
  const size_t N = 2;
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  vuint64m1_t vs = mlc_v(ls_u64_src, N * sizeof(uint64_t));
  msc_v(vs, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, M * N, "MLC_V & MSC_V U64");
}

static void test_mlc_v_msc_v_f64() {
  const size_t M = 2;
  const size_t N = 2;
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  vfloat64m1_t vs = mlc_v(ls_f64_src, N * sizeof(fp64_t));
  msc_v(vs, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, M * N, "MLC_V & MSC_V F64");
}

static void test_mlc_v_msc_v() {
  test_mlc_v_msc_v_i8();
  test_mlc_v_msc_v_u8();
  test_mlc_v_msc_v_i16();
  test_mlc_v_msc_v_u16();
  test_mlc_v_msc_v_f16();
  test_mlc_v_msc_v_i32();
  test_mlc_v_msc_v_u32();
  test_mlc_v_msc_v_f32();
  test_mlc_v_msc_v_i64();
  test_mlc_v_msc_v_u64();
  test_mlc_v_msc_v_f64();
}

static void test_mmvar_v_m_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int8_t);
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  vsetvl_e8m1(M * K);
  mint8_t ms = mla_m(ls_i8_src, stride);
  vint8m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, M * K, "MMVAR_V_M I8");
}

static void test_mmvar_v_m_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint8_t);
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  vsetvl_e8m1(M * K);
  muint8_t ms = mla_m(ls_u8_src, stride);
  vuint8m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, M * K, "MMVAR_V_M U8");
}

static void test_mmvar_v_m_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int16_t);
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  vsetvl_e16m1(M * K);
  mint16_t ms = mla_m(ls_i16_src, stride);
  vint16m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, M * K, "MMVAR_V_M I16");
}

static void test_mmvar_v_m_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint16_t);
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  vsetvl_e16m1(M * K);
  muint16_t ms = mla_m(ls_u16_src, stride);
  vuint16m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, M * K, "MMVAR_V_M U16");
}

static void test_mmvar_v_m_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(fp16_t);
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  vsetvl_e16m1(M * K);
  mfloat16_t ms = mla_m(ls_f16_src, stride);
  vfloat16m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, M * K, "MMVAR_V_M F16");
}

static void test_mmvar_v_m_i32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(int32_t);
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  vsetvl_e32m1(M * K);
  mint32_t ms = mla_m(ls_i32_src, stride);
  vint32m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, M * K, "MMVAR_V_M I32");
}

static void test_mmvar_v_m_u32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(uint32_t);
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  vsetvl_e32m1(M * K);
  muint32_t ms = mla_m(ls_u32_src, stride);
  vuint32m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, M * K, "MMVAR_V_M U32");
}

static void test_mmvar_v_m_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(fp32_t);
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  vsetvl_e32m1(M * K);
  mfloat32_t ms = mla_m(ls_f32_src, stride);
  vfloat32m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, M * K, "MMVAR_V_M F32");
}

static void test_mmvar_v_m_i64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(int64_t);
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  vsetvl_e64m1(M * K);
  mint64_t ms = mla_m(ls_i64_src, stride);
  vint64m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, M * K, "MMVAR_V_M I64");
}

static void test_mmvar_v_m_u64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(uint64_t);
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  vsetvl_e64m1(M * K);
  muint64_t ms = mla_m(ls_u64_src, stride);
  vuint64m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, M * K, "MMVAR_V_M U64");
}

static void test_mmvar_v_m_f64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(fp64_t);
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  vsetvl_e64m1(M * K);
  mfloat64_t ms = mla_m(ls_f64_src, stride);
  vfloat64m1_t vd = mmvar_v_m(ms, 0);
  msa_v(vd, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, M * K, "MMVAR_V_M F64");
}

static void test_mmvar_v_m() {
  test_mmvar_v_m_i8();
  test_mmvar_v_m_u8();
  test_mmvar_v_m_i16();
  test_mmvar_v_m_u16();
  test_mmvar_v_m_f16();
  test_mmvar_v_m_i32();
  test_mmvar_v_m_u32();
  test_mmvar_v_m_f32();
  test_mmvar_v_m_i64();
  test_mmvar_v_m_u64();
  test_mmvar_v_m_f64();
}

static void test_mmvbr_v_m_i8() {
  const size_t N = 8;
  const size_t K = 8;
  const size_t stride = N * sizeof(int8_t);
  SET_MBA0_I8();
  msettilen(N);
  msettilek(K);
  vsetvl_e8m1(K * N);
  mint8_t ms = mlb_m(ls_i8_src, stride);
  vint8m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, K * N, "MMVBR_V_M I8");
}

static void test_mmvbr_v_m_u8() {
  const size_t N = 8;
  const size_t K = 8;
  const size_t stride = N * sizeof(uint8_t);
  SET_MBA0_I8();
  msettilen(N);
  msettilek(K);
  vsetvl_e8m1(K * N);
  muint8_t ms = mlb_m(ls_u8_src, stride);
  vuint8m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, K * N, "MMVBR_V_M U8");
}

static void test_mmvbr_v_m_i16() {
  const size_t N = 8;
  const size_t K = 8;
  const size_t stride = N * sizeof(int16_t);
  SET_MBA0_I16();
  msettilen(N);
  msettilek(K);
  vsetvl_e16m1(K * N);
  mint16_t ms = mlb_m(ls_i16_src, stride);
  vint16m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, K * N, "MMVBR_V_M I16");
}

static void test_mmvbr_v_m_u16() {
  const size_t N = 8;
  const size_t K = 8;
  const size_t stride = N * sizeof(uint16_t);
  SET_MBA0_I16();
  msettilen(N);
  msettilek(K);
  vsetvl_e16m1(K * N);
  muint16_t ms = mlb_m(ls_u16_src, stride);
  vuint16m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, K * N, "MMVBR_V_M U16");
}

static void test_mmvbr_v_m_f16() {
  const size_t N = 8;
  const size_t K = 8;
  const size_t stride = N * sizeof(fp16_t);
  SET_MBA0_F16();
  msettilen(N);
  msettilek(K);
  vsetvl_e16m1(K * N);
  mfloat16_t ms = mlb_m(ls_f16_src, stride);
  vfloat16m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, K * N, "MMVBR_V_M F16");
}

static void test_mmvbr_v_m_i32() {
  const size_t N = 4;
  const size_t K = 4;
  const size_t stride = N * sizeof(int32_t);
  SET_MBA0_I32();
  msettilen(N);
  msettilek(K);
  vsetvl_e32m1(K * N);
  mint32_t ms = mlb_m(ls_i32_src, stride);
  vint32m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, K * N, "MMVBR_V_M I32");
}

static void test_mmvbr_v_m_u32() {
  const size_t N = 4;
  const size_t K = 4;
  const size_t stride = N * sizeof(uint32_t);
  SET_MBA0_I32();
  msettilen(N);
  msettilek(K);
  vsetvl_e32m1(K * N);
  muint32_t ms = mlb_m(ls_u32_src, stride);
  vuint32m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, K * N, "MMVBR_V_M U32");
}

static void test_mmvbr_v_m_f32() {
  const size_t N = 4;
  const size_t K = 4;
  const size_t stride = N * sizeof(fp32_t);
  SET_MBA0_F32();
  msettilen(N);
  msettilek(K);
  vsetvl_e32m1(K * N);
  mfloat32_t ms = mlb_m(ls_f32_src, stride);
  vfloat32m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, K * N, "MMVBR_V_M F32");
}

static void test_mmvbr_v_m_i64() {
  const size_t N = 2;
  const size_t K = 2;
  const size_t stride = N * sizeof(int64_t);
  SET_MBA0_I64();
  msettilen(N);
  msettilek(K);
  vsetvl_e64m1(K * N);
  mint64_t ms = mlb_m(ls_i64_src, stride);
  vint64m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, K * N, "MMVBR_V_M I64");
}

static void test_mmvbr_v_m_u64() {
  const size_t N = 2;
  const size_t K = 2;
  const size_t stride = N * sizeof(uint64_t);
  SET_MBA0_I64();
  msettilen(N);
  msettilek(K);
  vsetvl_e64m1(K * N);
  muint64_t ms = mlb_m(ls_u64_src, stride);
  vuint64m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, K * N, "MMVBR_V_M U64");
}

static void test_mmvbr_v_m_f64() {
  const size_t N = 2;
  const size_t K = 2;
  const size_t stride = N * sizeof(fp64_t);
  SET_MBA0_F64();
  msettilen(N);
  msettilek(K);
  vsetvl_e64m1(K * N);
  mfloat64_t ms = mlb_m(ls_f64_src, stride);
  vfloat64m1_t vd = mmvbr_v_m(ms, 0);
  msb_v(vd, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, K * N, "MMVBR_V_M F64");
}

static void test_mmvbr_v_m() {
  test_mmvbr_v_m_i8();
  test_mmvbr_v_m_u8();
  test_mmvbr_v_m_i16();
  test_mmvbr_v_m_u16();
  test_mmvbr_v_m_f16();
  test_mmvbr_v_m_i32();
  test_mmvbr_v_m_u32();
  test_mmvbr_v_m_f32();
  test_mmvbr_v_m_i64();
  test_mmvbr_v_m_u64();
  test_mmvbr_v_m_f64();
}

static void test_mmvcr_v_m_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  vsetvl_e8m1(M * N);
  mint8_t ms = mlc_m(ls_i8_src, stride);
  vint8m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, M * N, "MMVCR_V_M I8");
}

static void test_mmvcr_v_m_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  vsetvl_e8m1(M * N);
  muint8_t ms = mlc_m(ls_u8_src, stride);
  vuint8m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, M * N, "MMVCR_V_M U8");
}

static void test_mmvcr_v_m_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  vsetvl_e16m1(M * N);
  mint16_t ms = mlc_m(ls_i16_src, stride);
  vint16m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, M * N, "MMVCR_V_M I16");
}

static void test_mmvcr_v_m_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  vsetvl_e16m1(M * N);
  muint16_t ms = mlc_m(ls_u16_src, stride);
  vuint16m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, M * N, "MMVCR_V_M U16");
}

static void test_mmvcr_v_m_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  vsetvl_e16m1(M * N);
  mfloat16_t ms = mlc_m(ls_f16_src, stride);
  vfloat16m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, M * N, "MMVCR_V_M F16");
}

static void test_mmvcr_v_m_i32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  vsetvl_e32m1(M * N);
  mint32_t ms = mlc_m(ls_i32_src, stride);
  vint32m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, M * N, "MMVCR_V_M I32");
}

static void test_mmvcr_v_m_u32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  vsetvl_e32m1(M * N);
  muint32_t ms = mlc_m(ls_u32_src, stride);
  vuint32m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, M * N, "MMVCR_V_M U32");
}

static void test_mmvcr_v_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  vsetvl_e32m1(M * N);
  mfloat32_t ms = mlc_m(ls_f32_src, stride);
  vfloat32m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, M * N, "MMVCR_V_M F32");
}

static void test_mmvcr_v_m_i64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  vsetvl_e64m1(M * N);
  mint64_t ms = mlc_m(ls_i64_src, stride);
  vint64m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, M * N, "MMVCR_V_M I64");
}

static void test_mmvcr_v_m_u64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  vsetvl_e64m1(M * N);
  muint64_t ms = mlc_m(ls_u64_src, stride);
  vuint64m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, M * N, "MMVCR_V_M U64");
}

static void test_mmvcr_v_m_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  vsetvl_e64m1(M * N);
  mfloat64_t ms = mlc_m(ls_f64_src, stride);
  vfloat64m1_t vd = mmvcr_v_m(ms, 0);
  msc_v(vd, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, M * N, "MMVCR_V_M F64");
}

static void test_mmvcr_v_m() {
  test_mmvcr_v_m_i8();
  test_mmvcr_v_m_u8();
  test_mmvcr_v_m_i16();
  test_mmvcr_v_m_u16();
  test_mmvcr_v_m_f16();
  test_mmvcr_v_m_i32();
  test_mmvcr_v_m_u32();
  test_mmvcr_v_m_f32();
  test_mmvcr_v_m_i64();
  test_mmvcr_v_m_u64();
  test_mmvcr_v_m_f64();
}

static void test_mmvar_m_v_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int8_t);
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  vsetvl_e8m1(M * K);
  vint8m1_t vs = mla_v(ls_i8_src, stride);
  mint8_t md = mmvar_m_v(vs, 0);
  msa_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, M * K, "MMVAR_M_V I8");
}

static void test_mmvar_m_v_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint8_t);
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  vsetvl_e8m1(M * K);
  vuint8m1_t vs = mla_v(ls_u8_src, stride);
  muint8_t md = mmvar_m_v(vs, 0);
  msa_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, M * K, "MMVAR_M_V U8");
}

static void test_mmvar_m_v_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(int16_t);
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  vsetvl_e16m1(M * K);
  vint16m1_t vs = mla_v(ls_i16_src, stride);
  mint16_t md = mmvar_m_v(vs, 0);
  msa_m(md, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, M * K, "MMVAR_M_V I16");
}

static void test_mmvar_m_v_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(uint16_t);
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  vsetvl_e16m1(M * K);
  vuint16m1_t vs = mla_v(ls_u16_src, stride);
  muint16_t md = mmvar_m_v(vs, 0);
  msa_m(md, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, M * K, "MMVAR_M_V U16");
}

static void test_mmvar_m_v_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t stride = K * sizeof(fp16_t);
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  vsetvl_e16m1(M * K);
  vfloat16m1_t vs = mla_v(ls_f16_src, stride);
  mfloat16_t md = mmvar_m_v(vs, 0);
  msa_m(md, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, M * K, "MMVAR_M_V F16");
}

static void test_mmvar_m_v_i32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(int32_t);
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  vsetvl_e32m1(M * K);
  vint32m1_t vs = mla_v(ls_i32_src, stride);
  mint32_t md = mmvar_m_v(vs, 0);
  msa_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, M * K, "MMVAR_M_V I32");
}

static void test_mmvar_m_v_u32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(uint32_t);
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  vsetvl_e32m1(M * K);
  vuint32m1_t vs = mla_v(ls_u32_src, stride);
  muint32_t md = mmvar_m_v(vs, 0);
  msa_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, M * K, "MMVAR_M_V U32");
}

static void test_mmvar_m_v_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t stride = K * sizeof(fp32_t);
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  vsetvl_e32m1(M * K);
  vfloat32m1_t vs = mla_v(ls_f32_src, stride);
  mfloat32_t md = mmvar_m_v(vs, 0);
  msa_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, M * K, "MMVAR_M_V F32");
}

static void test_mmvar_m_v_i64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(int64_t);
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  vsetvl_e64m1(M * K);
  vint64m1_t vs = mla_v(ls_i64_src, stride);
  mint64_t md = mmvar_m_v(vs, 0);
  msa_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, M * K, "MMVAR_M_V I64");
}

static void test_mmvar_m_v_u64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(uint64_t);
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  vsetvl_e64m1(M * K);
  vuint64m1_t vs = mla_v(ls_u64_src, stride);
  muint64_t md = mmvar_m_v(vs, 0);
  msa_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, M * K, "MMVAR_M_V U64");
}

static void test_mmvar_m_v_f64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t stride = K * sizeof(fp64_t);
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  vsetvl_e64m1(M * K);
  vfloat64m1_t vs = mla_v(ls_f64_src, stride);
  mfloat64_t md = mmvar_m_v(vs, 0);
  msa_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, M * K, "MMVAR_M_V F64");
}

static void test_mmvar_m_v() {
  test_mmvar_m_v_i8();
  test_mmvar_m_v_u8();
  test_mmvar_m_v_i16();
  test_mmvar_m_v_u16();
  test_mmvar_m_v_f16();
  test_mmvar_m_v_i32();
  test_mmvar_m_v_u32();
  test_mmvar_m_v_f32();
  test_mmvar_m_v_i64();
  test_mmvar_m_v_u64();
  test_mmvar_m_v_f64();
}

static void test_mmvbr_m_v_i8() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  SET_MBA0_I8();
  msettilek(K);
  msettilen(N);
  vsetvl_e8m1(K * N);
  vint8m1_t vs = mlb_v(ls_i8_src, stride);
  mint8_t md = mmvbr_m_v(vs, 0);
  msb_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, K * N, "MMVBR_M_V I8");
}

static void test_mmvbr_m_v_u8() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  SET_MBA0_I8();
  msettilek(K);
  msettilen(N);
  vsetvl_e8m1(K * N);
  vuint8m1_t vs = mlb_v(ls_u8_src, stride);
  muint8_t md = mmvbr_m_v(vs, 0);
  msb_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, K * N, "MMVBR_M_V U8");
}

static void test_mmvbr_m_v_i16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  SET_MBA0_I16();
  msettilek(K);
  msettilen(N);
  vsetvl_e16m1(K * N);
  vint16m1_t vs = mlb_v(ls_i16_src, stride);
  mint16_t md = mmvbr_m_v(vs, 0);
  msb_m(md, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, K * N, "MMVBR_M_V I16");
}

static void test_mmvbr_m_v_u16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  SET_MBA0_I16();
  msettilek(K);
  msettilen(N);
  vsetvl_e16m1(K * N);
  vuint16m1_t vs = mlb_v(ls_u16_src, stride);
  muint16_t md = mmvbr_m_v(vs, 0);
  msb_m(md, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, K * N, "MMVBR_M_V U16");
}

static void test_mmvbr_m_v_f16() {
  const size_t K = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  SET_MBA0_F16();
  msettilek(K);
  msettilen(N);
  vsetvl_e16m1(K * N);
  vfloat16m1_t vs = mlb_v(ls_f16_src, stride);
  mfloat16_t md = mmvbr_m_v(vs, 0);
  msb_m(md, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, K * N, "MMVBR_M_V F16");
}

static void test_mmvbr_m_v_i32() {
  const size_t K = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  SET_MBA0_I32();
  msettilek(K);
  msettilen(N);
  vsetvl_e32m1(K * N);
  vint32m1_t vs = mlb_v(ls_i32_src, stride);
  mint32_t md = mmvbr_m_v(vs, 0);
  msb_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, K * N, "MMVBR_M_V I32");
}

static void test_mmvbr_m_v_u32() {
  const size_t K = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  SET_MBA0_I32();
  msettilek(K);
  msettilen(N);
  vsetvl_e32m1(K * N);
  vuint32m1_t vs = mlb_v(ls_u32_src, stride);
  muint32_t md = mmvbr_m_v(vs, 0);
  msb_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, K * N, "MMVBR_M_V U32");
}

static void test_mmvbr_m_v_f32() {
  const size_t K = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  SET_MBA0_F32();
  msettilek(K);
  msettilen(N);
  vsetvl_e32m1(K * N);
  vfloat32m1_t vs = mlb_v(ls_f32_src, stride);
  mfloat32_t md = mmvbr_m_v(vs, 0);
  msb_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, K * N, "MMVBR_M_V F32");
}

static void test_mmvbr_m_v_i64() {
  const size_t K = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  SET_MBA0_I64();
  msettilek(K);
  msettilen(N);
  vsetvl_e64m1(K * N);
  vint64m1_t vs = mlb_v(ls_i64_src, stride);
  mint64_t md = mmvbr_m_v(vs, 0);
  msb_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, K * N, "MMVBR_M_V I64");
}

static void test_mmvbr_m_v_u64() {
  const size_t K = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  SET_MBA0_I64();
  msettilek(K);
  msettilen(N);
  vsetvl_e64m1(K * N);
  vuint64m1_t vs = mlb_v(ls_u64_src, stride);
  muint64_t md = mmvbr_m_v(vs, 0);
  msb_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, K * N, "MMVBR_M_V U64");
}

static void test_mmvbr_m_v_f64() {
  const size_t K = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  SET_MBA0_F64();
  msettilek(K);
  msettilen(N);
  vsetvl_e64m1(K * N);
  vfloat64m1_t vs = mlb_v(ls_f64_src, stride);
  mfloat64_t md = mmvbr_m_v(vs, 0);
  msb_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, K * N, "MMVBR_M_V F64");
}

static void test_mmvbr_m_v() {
  test_mmvbr_m_v_i8();
  test_mmvbr_m_v_u8();
  test_mmvbr_m_v_i16();
  test_mmvbr_m_v_u16();
  test_mmvbr_m_v_f16();
  test_mmvbr_m_v_i32();
  test_mmvbr_m_v_u32();
  test_mmvbr_m_v_f32();
  test_mmvbr_m_v_i64();
  test_mmvbr_m_v_u64();
  test_mmvbr_m_v_f64();
}

static void test_mmvcr_m_v_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int8_t);
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  vsetvl_e8m1(M * N);
  vint8m1_t vs = mlc_v(ls_i8_src, stride);
  mint8_t md = mmvcr_m_v(vs, 0);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ls_i8_src, i8_buffer, M * N, "MMVCR_M_V I8");
}

static void test_mmvcr_m_v_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint8_t);
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  vsetvl_e8m1(M * N);
  vuint8m1_t vs = mlc_v(ls_u8_src, stride);
  muint8_t md = mmvcr_m_v(vs, 0);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ls_u8_src, u8_buffer, M * N, "MMVCR_M_V U8");
}

static void test_mmvcr_m_v_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(int16_t);
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  vsetvl_e16m1(M * N);
  vint16m1_t vs = mlc_v(ls_i16_src, stride);
  mint16_t md = mmvcr_m_v(vs, 0);
  msc_m(md, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ls_i16_src, i16_buffer, M * N, "MMVCR_M_V I16");
}

static void test_mmvcr_m_v_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(uint16_t);
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  vsetvl_e16m1(M * N);
  vuint16m1_t vs = mlc_v(ls_u16_src, stride);
  muint16_t md = mmvcr_m_v(vs, 0);
  msc_m(md, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ls_u16_src, u16_buffer, M * N, "MMVCR_M_V U16");
}

static void test_mmvcr_m_v_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const size_t stride = N * sizeof(fp16_t);
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  vsetvl_e16m1(M * N);
  vfloat16m1_t vs = mlc_v(ls_f16_src, stride);
  mfloat16_t md = mmvcr_m_v(vs, 0);
  msc_m(md, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ls_f16_src, f16_buffer, M * N, "MMVCR_M_V F16");
}

static void test_mmvcr_m_v_i32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(int32_t);
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  vsetvl_e32m1(M * N);
  vint32m1_t vs = mlc_v(ls_i32_src, stride);
  mint32_t md = mmvcr_m_v(vs, 0);
  msc_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ls_i32_src, i32_buffer, M * N, "MMVCR_M_V I32");
}

static void test_mmvcr_m_v_u32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(uint32_t);
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  vsetvl_e32m1(M * N);
  vuint32m1_t vs = mlc_v(ls_u32_src, stride);
  muint32_t md = mmvcr_m_v(vs, 0);
  msc_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ls_u32_src, u32_buffer, M * N, "MMVCR_M_V U32");
}

static void test_mmvcr_m_v_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const size_t stride = N * sizeof(fp32_t);
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  vsetvl_e32m1(M * N);
  vfloat32m1_t vs = mlc_v(ls_f32_src, stride);
  mfloat32_t md = mmvcr_m_v(vs, 0);
  msc_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ls_f32_src, f32_buffer, M * N, "MMVCR_M_V F32");
}

static void test_mmvcr_m_v_i64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(int64_t);
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  vsetvl_e64m1(M * N);
  vint64m1_t vs = mlc_v(ls_i64_src, stride);
  mint64_t md = mmvcr_m_v(vs, 0);
  msc_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ls_i64_src, i64_buffer, M * N, "MMVCR_M_V I64");
}

static void test_mmvcr_m_v_u64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(uint64_t);
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  vsetvl_e64m1(M * N);
  vuint64m1_t vs = mlc_v(ls_u64_src, stride);
  muint64_t md = mmvcr_m_v(vs, 0);
  msc_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ls_u64_src, u64_buffer, M * N, "MMVCR_M_V U64");
}

static void test_mmvcr_m_v_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const size_t stride = N * sizeof(fp64_t);
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  vsetvl_e64m1(M * N);
  vfloat64m1_t vs = mlc_v(ls_f64_src, stride);
  mfloat64_t md = mmvcr_m_v(vs, 0);
  msc_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ls_f64_src, f64_buffer, M * N, "MMVCR_M_V F64");
}

static void test_mmvcr_m_v() {
  test_mmvcr_m_v_i8();
  test_mmvcr_m_v_u8();
  test_mmvcr_m_v_i16();
  test_mmvcr_m_v_u16();
  test_mmvcr_m_v_f16();
  test_mmvcr_m_v_i32();
  test_mmvcr_m_v_u32();
  test_mmvcr_m_v_f32();
  test_mmvcr_m_v_i64();
  test_mmvcr_m_v_u64();
  test_mmvcr_m_v_f64();
}

static void test_mmvac_v_m_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(int8_t);
  const int8_t src[M * K] = {
      -85, -13, -51, -124, -68, -114, -59,  -21,  -37,  1,   -122, -122, 11,
      -71, -36, -83, -123, -10, -82,  -32,  -100, 2,    -15, -113, -35,  -47,
      -79, -86, -89, -58,  -51, -34,  -86,  -82,  8,    -53, -21,  -119, -76,
      -26, -24, -77, -82,  -28, -68,  -125, -59,  -124, -73, -77,  -76,  -126,
      -44, -39, -40, 2,    -36, -104, -95,  -41,  -56,  -38, -68,  -102};
  const int8_t ans[M * K] = {
      -85, -37,  -123, -35, -86,  -24,  -73,  -36, -13,  1,    -10, -47,  -82,
      -77, -77,  -104, -51, -122, -82,  -79,  8,   -82,  -76,  -95, -124, -122,
      -32, -86,  -53,  -28, -126, -41,  -68,  11,  -100, -89,  -21, -68,  -44,
      -56, -114, -71,  2,   -58,  -119, -125, -39, -38,  -59,  -36, -15,  -51,
      -76, -59,  -40,  -68, -21,  -83,  -113, -34, -26,  -124, 2,   -102};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  mint8_t ms = mla_m(src, stride);
  vint8m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * K, "MMVAC_V_M I8");
}

static void test_mmvac_v_m_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(uint8_t);
  const uint8_t src[M * K] = {13, 22, 12, 9,  20, 8,  21, 16, 13, 21, 7,  4,  4,
                              14, 23, 12, 13, 22, 21, 23, 12, 8,  24, 18, 9,  2,
                              5,  18, 9,  18, 16, 12, 0,  7,  0,  4,  13, 10, 0,
                              7,  18, 0,  23, 5,  16, 12, 4,  13, 20, 10, 6,  8,
                              20, 21, 14, 24, 17, 5,  9,  11, 11, 16, 11, 22};
  const uint8_t ans[M * K] = {
      13, 13, 13, 9,  0,  18, 20, 17, 22, 21, 22, 2,  7,  0,  10, 5,
      12, 7,  21, 5,  0,  23, 6,  9,  9,  4,  23, 18, 4,  5,  8,  11,
      20, 4,  12, 9,  13, 16, 20, 11, 8,  14, 8,  18, 10, 12, 21, 16,
      21, 23, 24, 16, 0,  4,  14, 11, 16, 12, 18, 12, 7,  13, 24, 22};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  muint8_t ms = mla_m(src, stride);
  vuint8m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * K, "MMVAC_V_M U8");
}

static void test_mmvac_v_m_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(int16_t);
  const int16_t src[M * K] = {
      -5425,  -11718, -30942, -28248, 2017,   -32725, -26490, -21852,
      -24975, -23807, -9985,  -4170,  1197,   -26895, -20729, -25764,
      -11771, -23136, -28255, -5703,  -32654, -16646, -18539, -27270,
      -4951,  -5929,  -19715, -23622, -28771, -23319, -7449,  -6663,
      -24938, -8445,  -9267,  -13083, -26818, -19951, -18282, -32219,
      -22533, -1971,  -21335, 2671,   -1788,  3263,   -9403,  -9777,
      -13618, -20526, -3629,  1735,   -30173, -27919, -25814, -7144,
      -10995, -21088, -132,   -2277,  2556,   3096,   -1606,  -31842};
  const int16_t ans[M * K] = {
      -5425,  -24975, -11771, -4951,  -24938, -22533, -13618, -10995,
      -11718, -23807, -23136, -5929,  -8445,  -1971,  -20526, -21088,
      -30942, -9985,  -28255, -19715, -9267,  -21335, -3629,  -132,
      -28248, -4170,  -5703,  -23622, -13083, 2671,   1735,   -2277,
      2017,   1197,   -32654, -28771, -26818, -1788,  -30173, 2556,
      -32725, -26895, -16646, -23319, -19951, 3263,   -27919, 3096,
      -26490, -20729, -18539, -7449,  -18282, -9403,  -25814, -1606,
      -21852, -25764, -27270, -6663,  -32219, -9777,  -7144,  -31842};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  mint16_t ms = mla_m(src, stride);
  vint16m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * K, "MMVAC_V_M I16");
}

static void test_mmvac_v_m_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(uint16_t);
  const uint16_t src[M * K] = {
      1587, 2558, 4834, 1346, 4132, 1934, 5209, 257,  5062, 3556, 5426,
      3684, 2149, 1905, 4819, 3468, 3057, 373,  5537, 2768, 3865, 6206,
      1197, 3730, 5522, 432,  3812, 332,  3764, 5475, 3599, 6231, 4775,
      243,  4459, 2844, 3689, 1890, 1094, 792,  1456, 1474, 1135, 4119,
      3406, 2321, 3273, 5111, 91,   5128, 5503, 6391, 3386, 3915, 5409,
      4928, 1632, 1186, 2210, 5002, 5162, 1218, 6446, 2258};
  const uint16_t ans[M * K] = {
      1587, 5062, 3057, 5522, 4775, 1456, 91,   1632, 2558, 3556, 373,
      432,  243,  1474, 5128, 1186, 4834, 5426, 5537, 3812, 4459, 1135,
      5503, 2210, 1346, 3684, 2768, 332,  2844, 4119, 6391, 5002, 4132,
      2149, 3865, 3764, 3689, 3406, 3386, 5162, 1934, 1905, 6206, 5475,
      1890, 2321, 3915, 1218, 5209, 4819, 1197, 3599, 1094, 3273, 5409,
      6446, 257,  3468, 3730, 6231, 792,  5111, 4928, 2258};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  muint16_t ms = mla_m(src, stride);
  vuint16m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * K, "MMVAC_V_M U16");
}

static void test_mmvac_v_m_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(fp16_t);
  const fp16_t src[M * K] = {
      8.23,    6.26,    -0.586,  -7.742, 9.26,   4.02,    5.375,  8.79,
      9.18,    -7.57,   -9.84,   1.505,  -3.188, -2.809,  -2.412, 3.576,
      -1.0625, 6.31,    -4.305,  -3.035, -9.586, 0.03546, 1.705,  9.,
      7.34,    -4.367,  -6.76,   0.0746, -1.752, -2.902,  7.418,  7.695,
      -6.875,  8.84,    -7.21,   8.445,  3.295,  -7.324,  -6.793, 9.17,
      -6.42,   -1.1455, -8.766,  0.692,  4.645,  -4.227,  -7.83,  -8.805,
      -9.05,   -6.543,  0.707,   9.27,   -0.183, 9.05,    -4.387, -4.926,
      1.543,   2.201,   -0.5103, 3.357,  -0.823, 4.016,   -4.164, 1.863};
  const fp16_t ans[M * K] = {
      8.23,   9.18,   -1.0625, 7.34,   -6.875, -6.42,   -9.05,  1.543,
      6.26,   -7.57,  6.31,    -4.367, 8.84,   -1.1455, -6.543, 2.201,
      -0.586, -9.84,  -4.305,  -6.76,  -7.21,  -8.766,  0.707,  -0.5103,
      -7.742, 1.505,  -3.035,  0.0746, 8.445,  0.692,   9.27,   3.357,
      9.26,   -3.188, -9.586,  -1.752, 3.295,  4.645,   -0.183, -0.823,
      4.02,   -2.809, 0.03546, -2.902, -7.324, -4.227,  9.05,   4.016,
      5.375,  -2.412, 1.705,   7.418,  -6.793, -7.83,   -4.387, -4.164,
      8.79,   3.576,  9.,      7.695,  9.17,   -8.805,  -4.926, 1.863};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  mfloat16_t ms = mla_m(src, stride);
  vfloat16m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, f16_buffer, M * K, "MMVAC_V_M F16");
}

static void test_mmvac_v_m_i32() {
  const size_t M = 4;
  const size_t K = 4;
  const stride = K * sizeof(int32_t);
  const int32_t src[M * K] = {
      -461443808,  199472183,  -1232905849, -523658315,
      -1778254273, -291435809, -1741937253, -1630191164,
      -1948196316, -546547128, -43138968,   -100936611,
      -1523765476, 167556507,  -1435011556, -1085808352};
  const int32_t ans[M * K] = {
      -461443808, -1778254273, -1948196316, -1523765476, 199472183, -291435809,
      -546547128, 167556507,   -1232905849, -1741937253, -43138968, -1435011556,
      -523658315, -1630191164, -100936611,  -1085808352};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  mint32_t ms = mla_m(src, stride);
  vint32m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * K, "MMVAC_V_M I32");
}

static void test_mmvac_v_m_u32() {
  const size_t M = 4;
  const size_t K = 4;
  const stride = K * sizeof(uint32_t);
  const uint32_t src[M * K] = {50443330,  107617688, 35212877,  326932685,
                               272952075, 269090771, 212306001, 230806585,
                               72269869,  428907790, 165502858, 52502382,
                               274162938, 230802888, 415885704, 264777885};
  const uint32_t ans[M * K] = {50443330,  272952075, 72269869,  274162938,
                               107617688, 269090771, 428907790, 230802888,
                               35212877,  212306001, 165502858, 415885704,
                               326932685, 230806585, 52502382,  264777885};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  muint32_t ms = mla_m(src, stride);
  vuint32m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * K, "MMVAC_V_M U32");
}

static void test_mmvac_v_m_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const stride = K * sizeof(fp32_t);
  const fp32_t src[M * K] = {-8.834909, 3.2987583,  6.7918887,  -2.7559993,
                             2.9014728, -3.3611052, -2.1716158, 0.11627129,
                             6.7316413, -4.4896226, 1.9561698,  -4.1715975,
                             -9.602308, -2.576488,  -7.7930236, -4.608881};
  const fp32_t ans[M * K] = {-8.834909,  2.9014728,  6.7316413,  -9.602308,
                             3.2987583,  -3.3611052, -4.4896226, -2.576488,
                             6.7918887,  -2.1716158, 1.9561698,  -7.7930236,
                             -2.7559993, 0.11627129, -4.1715975, -4.608881};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  mfloat32_t ms = mla_m(src, stride);
  vfloat32m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * K, "MMVAC_V_M F32");
}

static void test_mmvac_v_m_i64() {
  const size_t M = 2;
  const size_t K = 2;
  const stride = K * sizeof(int64_t);
  const int64_t src[M * K] = {-4024136034524734487, -985927737141634133,
                              -533801673561669591, -3657806910442662472};
  const int64_t ans[M * K] = {-4024136034524734487, -533801673561669591,
                              -985927737141634133, -3657806910442662472};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  mint64_t ms = mla_m(src, stride);
  vint64m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * K, "MMVAC_V_M I64");
}

static void test_mmvac_v_m_u64() {
  const size_t M = 2;
  const size_t K = 2;
  const stride = K * sizeof(uint64_t);
  const uint64_t src[M * K] = {115562859305890809, 402067820069744121,
                               824600090362417004, 1380241037346867911};
  const uint64_t ans[M * K] = {115562859305890809, 824600090362417004,
                               402067820069744121, 1380241037346867911};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  muint64_t ms = mla_m(src, stride);
  vuint64m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * K, "MMVAC_V_M U64");
}

static void test_mmvac_v_m_f64() {
  const size_t M = 2;
  const size_t K = 2;
  const stride = K * sizeof(fp64_t);
  const fp64_t src[M * K] = {-0.2921088, -2.49639746, 8.26217066, -7.39624643};
  const fp64_t ans[M * K] = {-0.2921088, 8.26217066, -2.49639746, -7.39624643};
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  mfloat64_t ms = mla_m(src, stride);
  vfloat64m1_t vd = mmvac_v_m(ms, 0);
  msa_v(vd, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * K, "MMVAC_V_M F64");
}

static void test_mmvac_v_m() {
  test_mmvac_v_m_i8();
  test_mmvac_v_m_u8();
  test_mmvac_v_m_i16();
  test_mmvac_v_m_u16();
  test_mmvac_v_m_f16();
  test_mmvac_v_m_i32();
  test_mmvac_v_m_u32();
  test_mmvac_v_m_f32();
  test_mmvac_v_m_i64();
  test_mmvac_v_m_u64();
  test_mmvac_v_m_f64();
}

static void test_mmvbc_v_m_i8() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(int8_t);
  const int8_t src[K * N] = {
      -85, -13, -51, -124, -68, -114, -59,  -21,  -37,  1,   -122, -122, 11,
      -71, -36, -83, -123, -10, -82,  -32,  -100, 2,    -15, -113, -35,  -47,
      -79, -86, -89, -58,  -51, -34,  -86,  -82,  8,    -53, -21,  -119, -76,
      -26, -24, -77, -82,  -28, -68,  -125, -59,  -124, -73, -77,  -76,  -126,
      -44, -39, -40, 2,    -36, -104, -95,  -41,  -56,  -38, -68,  -102};
  const int8_t ans[K * N] = {
      -85, -37,  -123, -35, -86,  -24,  -73,  -36, -13,  1,    -10, -47,  -82,
      -77, -77,  -104, -51, -122, -82,  -79,  8,   -82,  -76,  -95, -124, -122,
      -32, -86,  -53,  -28, -126, -41,  -68,  11,  -100, -89,  -21, -68,  -44,
      -56, -114, -71,  2,   -58,  -119, -125, -39, -38,  -59,  -36, -15,  -51,
      -76, -59,  -40,  -68, -21,  -83,  -113, -34, -26,  -124, 2,   -102};
  SET_MBA0_I8();
  msettilen(N);
  msettilek(K);
  mint8_t ms = mlb_m(src, stride);
  vint8m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, K * N, "MMVBC_V_M I8");
}

static void test_mmvbc_v_m_u8() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(uint8_t);
  const uint8_t src[K * N] = {13, 22, 12, 9,  20, 8,  21, 16, 13, 21, 7,  4,  4,
                              14, 23, 12, 13, 22, 21, 23, 12, 8,  24, 18, 9,  2,
                              5,  18, 9,  18, 16, 12, 0,  7,  0,  4,  13, 10, 0,
                              7,  18, 0,  23, 5,  16, 12, 4,  13, 20, 10, 6,  8,
                              20, 21, 14, 24, 17, 5,  9,  11, 11, 16, 11, 22};
  const uint8_t ans[K * N] = {
      13, 13, 13, 9,  0,  18, 20, 17, 22, 21, 22, 2,  7,  0,  10, 5,
      12, 7,  21, 5,  0,  23, 6,  9,  9,  4,  23, 18, 4,  5,  8,  11,
      20, 4,  12, 9,  13, 16, 20, 11, 8,  14, 8,  18, 10, 12, 21, 16,
      21, 23, 24, 16, 0,  4,  14, 11, 16, 12, 18, 12, 7,  13, 24, 22};
  SET_MBA0_I8();
  msettilen(N);
  msettilek(K);
  muint8_t ms = mlb_m(src, stride);
  vuint8m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, K * N, "MMVBC_V_M U8");
}

static void test_mmvbc_v_m_i16() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(int16_t);
  const int16_t src[K * N] = {
      -5425,  -11718, -30942, -28248, 2017,   -32725, -26490, -21852,
      -24975, -23807, -9985,  -4170,  1197,   -26895, -20729, -25764,
      -11771, -23136, -28255, -5703,  -32654, -16646, -18539, -27270,
      -4951,  -5929,  -19715, -23622, -28771, -23319, -7449,  -6663,
      -24938, -8445,  -9267,  -13083, -26818, -19951, -18282, -32219,
      -22533, -1971,  -21335, 2671,   -1788,  3263,   -9403,  -9777,
      -13618, -20526, -3629,  1735,   -30173, -27919, -25814, -7144,
      -10995, -21088, -132,   -2277,  2556,   3096,   -1606,  -31842};
  const int16_t ans[K * N] = {
      -5425,  -24975, -11771, -4951,  -24938, -22533, -13618, -10995,
      -11718, -23807, -23136, -5929,  -8445,  -1971,  -20526, -21088,
      -30942, -9985,  -28255, -19715, -9267,  -21335, -3629,  -132,
      -28248, -4170,  -5703,  -23622, -13083, 2671,   1735,   -2277,
      2017,   1197,   -32654, -28771, -26818, -1788,  -30173, 2556,
      -32725, -26895, -16646, -23319, -19951, 3263,   -27919, 3096,
      -26490, -20729, -18539, -7449,  -18282, -9403,  -25814, -1606,
      -21852, -25764, -27270, -6663,  -32219, -9777,  -7144,  -31842};
  SET_MBA0_I16();
  msettilen(N);
  msettilek(K);
  mint16_t ms = mlb_m(src, stride);
  vint16m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, K * N, "MMVBC_V_M I16");
}

static void test_mmvbc_v_m_u16() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(uint16_t);
  const uint16_t src[K * N] = {
      1587, 2558, 4834, 1346, 4132, 1934, 5209, 257,  5062, 3556, 5426,
      3684, 2149, 1905, 4819, 3468, 3057, 373,  5537, 2768, 3865, 6206,
      1197, 3730, 5522, 432,  3812, 332,  3764, 5475, 3599, 6231, 4775,
      243,  4459, 2844, 3689, 1890, 1094, 792,  1456, 1474, 1135, 4119,
      3406, 2321, 3273, 5111, 91,   5128, 5503, 6391, 3386, 3915, 5409,
      4928, 1632, 1186, 2210, 5002, 5162, 1218, 6446, 2258};
  const uint16_t ans[K * N] = {
      1587, 5062, 3057, 5522, 4775, 1456, 91,   1632, 2558, 3556, 373,
      432,  243,  1474, 5128, 1186, 4834, 5426, 5537, 3812, 4459, 1135,
      5503, 2210, 1346, 3684, 2768, 332,  2844, 4119, 6391, 5002, 4132,
      2149, 3865, 3764, 3689, 3406, 3386, 5162, 1934, 1905, 6206, 5475,
      1890, 2321, 3915, 1218, 5209, 4819, 1197, 3599, 1094, 3273, 5409,
      6446, 257,  3468, 3730, 6231, 792,  5111, 4928, 2258};
  SET_MBA0_I16();
  msettilen(N);
  msettilek(K);
  muint16_t ms = mlb_m(src, stride);
  vuint16m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, K * N, "MMVBC_V_M U16");
}

static void test_mmvbc_v_m_f16() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(fp16_t);
  const fp16_t src[K * N] = {
      8.23,    6.26,    -0.586,  -7.742, 9.26,   4.02,    5.375,  8.79,
      9.18,    -7.57,   -9.84,   1.505,  -3.188, -2.809,  -2.412, 3.576,
      -1.0625, 6.31,    -4.305,  -3.035, -9.586, 0.03546, 1.705,  9.,
      7.34,    -4.367,  -6.76,   0.0746, -1.752, -2.902,  7.418,  7.695,
      -6.875,  8.84,    -7.21,   8.445,  3.295,  -7.324,  -6.793, 9.17,
      -6.42,   -1.1455, -8.766,  0.692,  4.645,  -4.227,  -7.83,  -8.805,
      -9.05,   -6.543,  0.707,   9.27,   -0.183, 9.05,    -4.387, -4.926,
      1.543,   2.201,   -0.5103, 3.357,  -0.823, 4.016,   -4.164, 1.863};
  const fp16_t ans[K * N] = {
      8.23,   9.18,   -1.0625, 7.34,   -6.875, -6.42,   -9.05,  1.543,
      6.26,   -7.57,  6.31,    -4.367, 8.84,   -1.1455, -6.543, 2.201,
      -0.586, -9.84,  -4.305,  -6.76,  -7.21,  -8.766,  0.707,  -0.5103,
      -7.742, 1.505,  -3.035,  0.0746, 8.445,  0.692,   9.27,   3.357,
      9.26,   -3.188, -9.586,  -1.752, 3.295,  4.645,   -0.183, -0.823,
      4.02,   -2.809, 0.03546, -2.902, -7.324, -4.227,  9.05,   4.016,
      5.375,  -2.412, 1.705,   7.418,  -6.793, -7.83,   -4.387, -4.164,
      8.79,   3.576,  9.,      7.695,  9.17,   -8.805,  -4.926, 1.863};
  SET_MBA0_F16();
  msettilen(N);
  msettilek(K);
  mfloat16_t ms = mlb_m(src, stride);
  vfloat16m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, f16_buffer, K * N, "MMVBC_V_M F16");
}

static void test_mmvbc_v_m_i32() {
  const size_t N = 4;
  const size_t K = 4;
  const stride = N * sizeof(int32_t);
  const int32_t src[K * N] = {
      -461443808,  199472183,  -1232905849, -523658315,
      -1778254273, -291435809, -1741937253, -1630191164,
      -1948196316, -546547128, -43138968,   -100936611,
      -1523765476, 167556507,  -1435011556, -1085808352};
  const int32_t ans[K * N] = {
      -461443808, -1778254273, -1948196316, -1523765476, 199472183, -291435809,
      -546547128, 167556507,   -1232905849, -1741937253, -43138968, -1435011556,
      -523658315, -1630191164, -100936611,  -1085808352};
  SET_MBA0_I32();
  msettilen(N);
  msettilek(K);
  mint32_t ms = mlb_m(src, stride);
  vint32m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, K * N, "MMVBC_V_M I32");
}

static void test_mmvbc_v_m_u32() {
  const size_t N = 4;
  const size_t K = 4;
  const stride = N * sizeof(uint32_t);
  const uint32_t src[K * N] = {50443330,  107617688, 35212877,  326932685,
                               272952075, 269090771, 212306001, 230806585,
                               72269869,  428907790, 165502858, 52502382,
                               274162938, 230802888, 415885704, 264777885};
  const uint32_t ans[K * N] = {50443330,  272952075, 72269869,  274162938,
                               107617688, 269090771, 428907790, 230802888,
                               35212877,  212306001, 165502858, 415885704,
                               326932685, 230806585, 52502382,  264777885};
  SET_MBA0_I32();
  msettilen(N);
  msettilek(K);
  muint32_t ms = mlb_m(src, stride);
  vuint32m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, K * N, "MMVBC_V_M U32");
}

static void test_mmvbc_v_m_f32() {
  const size_t N = 4;
  const size_t K = 4;
  const stride = N * sizeof(fp32_t);
  const fp32_t src[K * N] = {-8.834909, 3.2987583,  6.7918887,  -2.7559993,
                             2.9014728, -3.3611052, -2.1716158, 0.11627129,
                             6.7316413, -4.4896226, 1.9561698,  -4.1715975,
                             -9.602308, -2.576488,  -7.7930236, -4.608881};
  const fp32_t ans[K * N] = {-8.834909,  2.9014728,  6.7316413,  -9.602308,
                             3.2987583,  -3.3611052, -4.4896226, -2.576488,
                             6.7918887,  -2.1716158, 1.9561698,  -7.7930236,
                             -2.7559993, 0.11627129, -4.1715975, -4.608881};
  SET_MBA0_F32();
  msettilen(N);
  msettilek(K);
  mfloat32_t ms = mlb_m(src, stride);
  vfloat32m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, K * N, "MMVBC_V_M F32");
}

static void test_mmvbc_v_m_i64() {
  const size_t N = 2;
  const size_t K = 2;
  const stride = N * sizeof(int64_t);
  const int64_t src[K * N] = {-4024136034524734487, -985927737141634133,
                              -533801673561669591, -3657806910442662472};
  const int64_t ans[K * N] = {-4024136034524734487, -533801673561669591,
                              -985927737141634133, -3657806910442662472};
  SET_MBA0_I64();
  msettilen(N);
  msettilek(K);
  mint64_t ms = mlb_m(src, stride);
  vint64m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, K * N, "MMVBC_V_M I64");
}

static void test_mmvbc_v_m_u64() {
  const size_t N = 2;
  const size_t K = 2;
  const stride = N * sizeof(uint64_t);
  const uint64_t src[K * N] = {115562859305890809, 402067820069744121,
                               824600090362417004, 1380241037346867911};
  const uint64_t ans[K * N] = {115562859305890809, 824600090362417004,
                               402067820069744121, 1380241037346867911};
  SET_MBA0_I64();
  msettilen(N);
  msettilek(K);
  muint64_t ms = mlb_m(src, stride);
  vuint64m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, K * N, "MMVBC_V_M U64");
}

static void test_mmvbc_v_m_f64() {
  const size_t N = 2;
  const size_t K = 2;
  const stride = N * sizeof(fp64_t);
  const fp64_t src[K * N] = {-0.2921088, -2.49639746, 8.26217066, -7.39624643};
  const fp64_t ans[K * N] = {-0.2921088, 8.26217066, -2.49639746, -7.39624643};
  SET_MBA0_F64();
  msettilen(N);
  msettilek(K);
  mfloat64_t ms = mlb_m(src, stride);
  vfloat64m1_t vd = mmvbc_v_m(ms, 0);
  msb_v(vd, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, K * N, "MMVBC_V_M F64");
}

static void test_mmvbc_v_m() {
  test_mmvbc_v_m_i8();
  test_mmvbc_v_m_u8();
  test_mmvbc_v_m_i16();
  test_mmvbc_v_m_u16();
  test_mmvbc_v_m_f16();
  test_mmvbc_v_m_i32();
  test_mmvbc_v_m_u32();
  test_mmvbc_v_m_f32();
  test_mmvbc_v_m_i64();
  test_mmvbc_v_m_u64();
  test_mmvbc_v_m_f64();
}

static void test_mmvcc_v_m_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(int8_t);
  const int8_t src[M * N] = {
      -85, -13, -51, -124, -68, -114, -59,  -21,  -37,  1,   -122, -122, 11,
      -71, -36, -83, -123, -10, -82,  -32,  -100, 2,    -15, -113, -35,  -47,
      -79, -86, -89, -58,  -51, -34,  -86,  -82,  8,    -53, -21,  -119, -76,
      -26, -24, -77, -82,  -28, -68,  -125, -59,  -124, -73, -77,  -76,  -126,
      -44, -39, -40, 2,    -36, -104, -95,  -41,  -56,  -38, -68,  -102};
  const int8_t ans[M * N] = {
      -85, -37,  -123, -35, -86,  -24,  -73,  -36, -13,  1,    -10, -47,  -82,
      -77, -77,  -104, -51, -122, -82,  -79,  8,   -82,  -76,  -95, -124, -122,
      -32, -86,  -53,  -28, -126, -41,  -68,  11,  -100, -89,  -21, -68,  -44,
      -56, -114, -71,  2,   -58,  -119, -125, -39, -38,  -59,  -36, -15,  -51,
      -76, -59,  -40,  -68, -21,  -83,  -113, -34, -26,  -124, 2,   -102};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  mint8_t ms = mlc_m(src, stride);
  vint8m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MMVCC_V_M I8");
}

static void test_mmvcc_v_m_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(uint8_t);
  const uint8_t src[M * N] = {13, 22, 12, 9,  20, 8,  21, 16, 13, 21, 7,  4,  4,
                              14, 23, 12, 13, 22, 21, 23, 12, 8,  24, 18, 9,  2,
                              5,  18, 9,  18, 16, 12, 0,  7,  0,  4,  13, 10, 0,
                              7,  18, 0,  23, 5,  16, 12, 4,  13, 20, 10, 6,  8,
                              20, 21, 14, 24, 17, 5,  9,  11, 11, 16, 11, 22};
  const uint8_t ans[M * N] = {
      13, 13, 13, 9,  0,  18, 20, 17, 22, 21, 22, 2,  7,  0,  10, 5,
      12, 7,  21, 5,  0,  23, 6,  9,  9,  4,  23, 18, 4,  5,  8,  11,
      20, 4,  12, 9,  13, 16, 20, 11, 8,  14, 8,  18, 10, 12, 21, 16,
      21, 23, 24, 16, 0,  4,  14, 11, 16, 12, 18, 12, 7,  13, 24, 22};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  muint8_t ms = mlc_m(src, stride);
  vuint8m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MMVCC_V_M U8");
}

static void test_mmvcc_v_m_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(int16_t);
  const int16_t src[M * N] = {
      -5425,  -11718, -30942, -28248, 2017,   -32725, -26490, -21852,
      -24975, -23807, -9985,  -4170,  1197,   -26895, -20729, -25764,
      -11771, -23136, -28255, -5703,  -32654, -16646, -18539, -27270,
      -4951,  -5929,  -19715, -23622, -28771, -23319, -7449,  -6663,
      -24938, -8445,  -9267,  -13083, -26818, -19951, -18282, -32219,
      -22533, -1971,  -21335, 2671,   -1788,  3263,   -9403,  -9777,
      -13618, -20526, -3629,  1735,   -30173, -27919, -25814, -7144,
      -10995, -21088, -132,   -2277,  2556,   3096,   -1606,  -31842};
  const int16_t ans[M * N] = {
      -5425,  -24975, -11771, -4951,  -24938, -22533, -13618, -10995,
      -11718, -23807, -23136, -5929,  -8445,  -1971,  -20526, -21088,
      -30942, -9985,  -28255, -19715, -9267,  -21335, -3629,  -132,
      -28248, -4170,  -5703,  -23622, -13083, 2671,   1735,   -2277,
      2017,   1197,   -32654, -28771, -26818, -1788,  -30173, 2556,
      -32725, -26895, -16646, -23319, -19951, 3263,   -27919, 3096,
      -26490, -20729, -18539, -7449,  -18282, -9403,  -25814, -1606,
      -21852, -25764, -27270, -6663,  -32219, -9777,  -7144,  -31842};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  mint16_t ms = mlc_m(src, stride);
  vint16m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MMVCC_V_M I16");
}

static void test_mmvcc_v_m_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(uint16_t);
  const uint16_t src[M * N] = {
      1587, 2558, 4834, 1346, 4132, 1934, 5209, 257,  5062, 3556, 5426,
      3684, 2149, 1905, 4819, 3468, 3057, 373,  5537, 2768, 3865, 6206,
      1197, 3730, 5522, 432,  3812, 332,  3764, 5475, 3599, 6231, 4775,
      243,  4459, 2844, 3689, 1890, 1094, 792,  1456, 1474, 1135, 4119,
      3406, 2321, 3273, 5111, 91,   5128, 5503, 6391, 3386, 3915, 5409,
      4928, 1632, 1186, 2210, 5002, 5162, 1218, 6446, 2258};
  const uint16_t ans[M * N] = {
      1587, 5062, 3057, 5522, 4775, 1456, 91,   1632, 2558, 3556, 373,
      432,  243,  1474, 5128, 1186, 4834, 5426, 5537, 3812, 4459, 1135,
      5503, 2210, 1346, 3684, 2768, 332,  2844, 4119, 6391, 5002, 4132,
      2149, 3865, 3764, 3689, 3406, 3386, 5162, 1934, 1905, 6206, 5475,
      1890, 2321, 3915, 1218, 5209, 4819, 1197, 3599, 1094, 3273, 5409,
      6446, 257,  3468, 3730, 6231, 792,  5111, 4928, 2258};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  muint16_t ms = mlc_m(src, stride);
  vuint16m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MMVCC_V_M U16");
}

static void test_mmvcc_v_m_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(fp16_t);
  const fp16_t src[M * N] = {
      8.23,    6.26,    -0.586,  -7.742, 9.26,   4.02,    5.375,  8.79,
      9.18,    -7.57,   -9.84,   1.505,  -3.188, -2.809,  -2.412, 3.576,
      -1.0625, 6.31,    -4.305,  -3.035, -9.586, 0.03546, 1.705,  9.,
      7.34,    -4.367,  -6.76,   0.0746, -1.752, -2.902,  7.418,  7.695,
      -6.875,  8.84,    -7.21,   8.445,  3.295,  -7.324,  -6.793, 9.17,
      -6.42,   -1.1455, -8.766,  0.692,  4.645,  -4.227,  -7.83,  -8.805,
      -9.05,   -6.543,  0.707,   9.27,   -0.183, 9.05,    -4.387, -4.926,
      1.543,   2.201,   -0.5103, 3.357,  -0.823, 4.016,   -4.164, 1.863};
  const fp16_t ans[M * N] = {
      8.23,   9.18,   -1.0625, 7.34,   -6.875, -6.42,   -9.05,  1.543,
      6.26,   -7.57,  6.31,    -4.367, 8.84,   -1.1455, -6.543, 2.201,
      -0.586, -9.84,  -4.305,  -6.76,  -7.21,  -8.766,  0.707,  -0.5103,
      -7.742, 1.505,  -3.035,  0.0746, 8.445,  0.692,   9.27,   3.357,
      9.26,   -3.188, -9.586,  -1.752, 3.295,  4.645,   -0.183, -0.823,
      4.02,   -2.809, 0.03546, -2.902, -7.324, -4.227,  9.05,   4.016,
      5.375,  -2.412, 1.705,   7.418,  -6.793, -7.83,   -4.387, -4.164,
      8.79,   3.576,  9.,      7.695,  9.17,   -8.805,  -4.926, 1.863};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  mfloat16_t ms = mlc_m(src, stride);
  vfloat16m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, f16_buffer, M * N, "MMVCC_V_M F16");
}

static void test_mmvcc_v_m_i32() {
  const size_t M = 4;
  const size_t N = 4;
  const stride = N * sizeof(int32_t);
  const int32_t src[M * N] = {
      -461443808,  199472183,  -1232905849, -523658315,
      -1778254273, -291435809, -1741937253, -1630191164,
      -1948196316, -546547128, -43138968,   -100936611,
      -1523765476, 167556507,  -1435011556, -1085808352};
  const int32_t ans[M * N] = {
      -461443808, -1778254273, -1948196316, -1523765476, 199472183, -291435809,
      -546547128, 167556507,   -1232905849, -1741937253, -43138968, -1435011556,
      -523658315, -1630191164, -100936611,  -1085808352};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  mint32_t ms = mlc_m(src, stride);
  vint32m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MMVCC_V_M I32");
}

static void test_mmvcc_v_m_u32() {
  const size_t M = 4;
  const size_t N = 4;
  const stride = N * sizeof(uint32_t);
  const uint32_t src[M * N] = {50443330,  107617688, 35212877,  326932685,
                               272952075, 269090771, 212306001, 230806585,
                               72269869,  428907790, 165502858, 52502382,
                               274162938, 230802888, 415885704, 264777885};
  const uint32_t ans[M * N] = {50443330,  272952075, 72269869,  274162938,
                               107617688, 269090771, 428907790, 230802888,
                               35212877,  212306001, 165502858, 415885704,
                               326932685, 230806585, 52502382,  264777885};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  muint32_t ms = mlc_m(src, stride);
  vuint32m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MMVCC_V_M U32");
}

static void test_mmvcc_v_m_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const stride = N * sizeof(fp32_t);
  const fp32_t src[M * N] = {-8.834909, 3.2987583,  6.7918887,  -2.7559993,
                             2.9014728, -3.3611052, -2.1716158, 0.11627129,
                             6.7316413, -4.4896226, 1.9561698,  -4.1715975,
                             -9.602308, -2.576488,  -7.7930236, -4.608881};
  const fp32_t ans[M * N] = {-8.834909,  2.9014728,  6.7316413,  -9.602308,
                             3.2987583,  -3.3611052, -4.4896226, -2.576488,
                             6.7918887,  -2.1716158, 1.9561698,  -7.7930236,
                             -2.7559993, 0.11627129, -4.1715975, -4.608881};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  mfloat32_t ms = mlc_m(src, stride);
  vfloat32m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * N, "MMVCC_V_M F32");
}

static void test_mmvcc_v_m_i64() {
  const size_t M = 2;
  const size_t N = 2;
  const stride = N * sizeof(int64_t);
  const int64_t src[M * N] = {-4024136034524734487, -985927737141634133,
                              -533801673561669591, -3657806910442662472};
  const int64_t ans[M * N] = {-4024136034524734487, -533801673561669591,
                              -985927737141634133, -3657806910442662472};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  mint64_t ms = mlc_m(src, stride);
  vint64m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MMVCC_V_M I64");
}

static void test_mmvcc_v_m_u64() {
  const size_t M = 2;
  const size_t N = 2;
  const stride = N * sizeof(uint64_t);
  const uint64_t src[M * N] = {115562859305890809, 402067820069744121,
                               824600090362417004, 1380241037346867911};
  const uint64_t ans[M * N] = {115562859305890809, 824600090362417004,
                               402067820069744121, 1380241037346867911};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  muint64_t ms = mlc_m(src, stride);
  vuint64m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MMVCC_V_M U64");
}

static void test_mmvcc_v_m_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const stride = N * sizeof(fp64_t);
  const fp64_t src[M * N] = {-0.2921088, -2.49639746, 8.26217066, -7.39624643};
  const fp64_t ans[M * N] = {-0.2921088, 8.26217066, -2.49639746, -7.39624643};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  mfloat64_t ms = mlc_m(src, stride);
  vfloat64m1_t vd = mmvcc_v_m(ms, 0);
  msc_v(vd, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * N, "MMVCC_V_M F64");
}

static void test_mmvcc_v_m() {
  test_mmvcc_v_m_i8();
  test_mmvcc_v_m_u8();
  test_mmvcc_v_m_i16();
  test_mmvcc_v_m_u16();
  test_mmvcc_v_m_f16();
  test_mmvcc_v_m_i32();
  test_mmvcc_v_m_u32();
  test_mmvcc_v_m_f32();
  test_mmvcc_v_m_i64();
  test_mmvcc_v_m_u64();
  test_mmvcc_v_m_f64();
}

static void test_mmvcc_m_v_i8() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(int8_t);
  const int8_t src[M * N] = {
      -85, -13, -51, -124, -68, -114, -59,  -21,  -37,  1,   -122, -122, 11,
      -71, -36, -83, -123, -10, -82,  -32,  -100, 2,    -15, -113, -35,  -47,
      -79, -86, -89, -58,  -51, -34,  -86,  -82,  8,    -53, -21,  -119, -76,
      -26, -24, -77, -82,  -28, -68,  -125, -59,  -124, -73, -77,  -76,  -126,
      -44, -39, -40, 2,    -36, -104, -95,  -41,  -56,  -38, -68,  -102};
  const int8_t ans[M * N] = {
      -85, -37,  -123, -35, -86,  -24,  -73,  -36, -13,  1,    -10, -47,  -82,
      -77, -77,  -104, -51, -122, -82,  -79,  8,   -82,  -76,  -95, -124, -122,
      -32, -86,  -53,  -28, -126, -41,  -68,  11,  -100, -89,  -21, -68,  -44,
      -56, -114, -71,  2,   -58,  -119, -125, -39, -38,  -59,  -36, -15,  -51,
      -76, -59,  -40,  -68, -21,  -83,  -113, -34, -26,  -124, 2,   -102};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  vint8m1_t vs = mlc_v(src, stride);
  mint8_t md = mmvcc_m_v(vs, 0);
  msc_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * N, "MMVCC_M_V I8");
}

static void test_mmvcc_m_v_u8() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(uint8_t);
  const uint8_t src[M * N] = {13, 22, 12, 9,  20, 8,  21, 16, 13, 21, 7,  4,  4,
                              14, 23, 12, 13, 22, 21, 23, 12, 8,  24, 18, 9,  2,
                              5,  18, 9,  18, 16, 12, 0,  7,  0,  4,  13, 10, 0,
                              7,  18, 0,  23, 5,  16, 12, 4,  13, 20, 10, 6,  8,
                              20, 21, 14, 24, 17, 5,  9,  11, 11, 16, 11, 22};
  const uint8_t ans[M * N] = {
      13, 13, 13, 9,  0,  18, 20, 17, 22, 21, 22, 2,  7,  0,  10, 5,
      12, 7,  21, 5,  0,  23, 6,  9,  9,  4,  23, 18, 4,  5,  8,  11,
      20, 4,  12, 9,  13, 16, 20, 11, 8,  14, 8,  18, 10, 12, 21, 16,
      21, 23, 24, 16, 0,  4,  14, 11, 16, 12, 18, 12, 7,  13, 24, 22};
  SET_MBA0_I8();
  msettilem(M);
  msettilen(N);
  vuint8m1_t vs = mlc_v(src, stride);
  muint8_t md = mmvcc_m_v(vs, 0);
  msc_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * N, "MMVCC_M_V U8");
}

static void test_mmvcc_m_v_i16() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(int16_t);
  const int16_t src[M * N] = {
      -5425,  -11718, -30942, -28248, 2017,   -32725, -26490, -21852,
      -24975, -23807, -9985,  -4170,  1197,   -26895, -20729, -25764,
      -11771, -23136, -28255, -5703,  -32654, -16646, -18539, -27270,
      -4951,  -5929,  -19715, -23622, -28771, -23319, -7449,  -6663,
      -24938, -8445,  -9267,  -13083, -26818, -19951, -18282, -32219,
      -22533, -1971,  -21335, 2671,   -1788,  3263,   -9403,  -9777,
      -13618, -20526, -3629,  1735,   -30173, -27919, -25814, -7144,
      -10995, -21088, -132,   -2277,  2556,   3096,   -1606,  -31842};
  const int16_t ans[M * N] = {
      -5425,  -24975, -11771, -4951,  -24938, -22533, -13618, -10995,
      -11718, -23807, -23136, -5929,  -8445,  -1971,  -20526, -21088,
      -30942, -9985,  -28255, -19715, -9267,  -21335, -3629,  -132,
      -28248, -4170,  -5703,  -23622, -13083, 2671,   1735,   -2277,
      2017,   1197,   -32654, -28771, -26818, -1788,  -30173, 2556,
      -32725, -26895, -16646, -23319, -19951, 3263,   -27919, 3096,
      -26490, -20729, -18539, -7449,  -18282, -9403,  -25814, -1606,
      -21852, -25764, -27270, -6663,  -32219, -9777,  -7144,  -31842};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  vint16m1_t vs = mlc_v(src, stride);
  mint16_t md = mmvcc_m_v(vs, 0);
  msc_m(md, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * N, "MMVCC_M_V I16");
}

static void test_mmvcc_m_v_u16() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(uint16_t);
  const uint16_t src[M * N] = {
      1587, 2558, 4834, 1346, 4132, 1934, 5209, 257,  5062, 3556, 5426,
      3684, 2149, 1905, 4819, 3468, 3057, 373,  5537, 2768, 3865, 6206,
      1197, 3730, 5522, 432,  3812, 332,  3764, 5475, 3599, 6231, 4775,
      243,  4459, 2844, 3689, 1890, 1094, 792,  1456, 1474, 1135, 4119,
      3406, 2321, 3273, 5111, 91,   5128, 5503, 6391, 3386, 3915, 5409,
      4928, 1632, 1186, 2210, 5002, 5162, 1218, 6446, 2258};
  const uint16_t ans[M * N] = {
      1587, 5062, 3057, 5522, 4775, 1456, 91,   1632, 2558, 3556, 373,
      432,  243,  1474, 5128, 1186, 4834, 5426, 5537, 3812, 4459, 1135,
      5503, 2210, 1346, 3684, 2768, 332,  2844, 4119, 6391, 5002, 4132,
      2149, 3865, 3764, 3689, 3406, 3386, 5162, 1934, 1905, 6206, 5475,
      1890, 2321, 3915, 1218, 5209, 4819, 1197, 3599, 1094, 3273, 5409,
      6446, 257,  3468, 3730, 6231, 792,  5111, 4928, 2258};
  SET_MBA0_I16();
  msettilem(M);
  msettilen(N);
  vuint16m1_t vs = mlc_v(src, stride);
  muint16_t md = mmvcc_m_v(vs, 0);
  msc_m(md, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * N, "MMVCC_M_V U16");
}

static void test_mmvcc_m_v_f16() {
  const size_t M = 8;
  const size_t N = 8;
  const stride = N * sizeof(fp16_t);
  const fp16_t src[M * N] = {
      8.23,    6.26,    -0.586,  -7.742, 9.26,   4.02,    5.375,  8.79,
      9.18,    -7.57,   -9.84,   1.505,  -3.188, -2.809,  -2.412, 3.576,
      -1.0625, 6.31,    -4.305,  -3.035, -9.586, 0.03546, 1.705,  9.,
      7.34,    -4.367,  -6.76,   0.0746, -1.752, -2.902,  7.418,  7.695,
      -6.875,  8.84,    -7.21,   8.445,  3.295,  -7.324,  -6.793, 9.17,
      -6.42,   -1.1455, -8.766,  0.692,  4.645,  -4.227,  -7.83,  -8.805,
      -9.05,   -6.543,  0.707,   9.27,   -0.183, 9.05,    -4.387, -4.926,
      1.543,   2.201,   -0.5103, 3.357,  -0.823, 4.016,   -4.164, 1.863};
  const fp16_t ans[M * N] = {
      8.23,   9.18,   -1.0625, 7.34,   -6.875, -6.42,   -9.05,  1.543,
      6.26,   -7.57,  6.31,    -4.367, 8.84,   -1.1455, -6.543, 2.201,
      -0.586, -9.84,  -4.305,  -6.76,  -7.21,  -8.766,  0.707,  -0.5103,
      -7.742, 1.505,  -3.035,  0.0746, 8.445,  0.692,   9.27,   3.357,
      9.26,   -3.188, -9.586,  -1.752, 3.295,  4.645,   -0.183, -0.823,
      4.02,   -2.809, 0.03546, -2.902, -7.324, -4.227,  9.05,   4.016,
      5.375,  -2.412, 1.705,   7.418,  -6.793, -7.83,   -4.387, -4.164,
      8.79,   3.576,  9.,      7.695,  9.17,   -8.805,  -4.926, 1.863};
  SET_MBA0_F16();
  msettilem(M);
  msettilen(N);
  vfloat16m1_t vs = mlc_v(src, stride);
  mfloat16_t md = mmvcc_m_v(vs, 0);
  msc_m(md, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, f16_buffer, M * N, "MMVCC_M_V F16");
}

static void test_mmvcc_m_v_i32() {
  const size_t M = 4;
  const size_t N = 4;
  const stride = N * sizeof(int32_t);
  const int32_t src[M * N] = {
      -461443808,  199472183,  -1232905849, -523658315,
      -1778254273, -291435809, -1741937253, -1630191164,
      -1948196316, -546547128, -43138968,   -100936611,
      -1523765476, 167556507,  -1435011556, -1085808352};
  const int32_t ans[M * N] = {
      -461443808, -1778254273, -1948196316, -1523765476, 199472183, -291435809,
      -546547128, 167556507,   -1232905849, -1741937253, -43138968, -1435011556,
      -523658315, -1630191164, -100936611,  -1085808352};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  vint32m1_t vs = mlc_v(src, stride);
  mint32_t md = mmvcc_m_v(vs, 0);
  msc_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * N, "MMVCC_M_V I32");
}

static void test_mmvcc_m_v_u32() {
  const size_t M = 4;
  const size_t N = 4;
  const stride = N * sizeof(uint32_t);
  const uint32_t src[M * N] = {50443330,  107617688, 35212877,  326932685,
                               272952075, 269090771, 212306001, 230806585,
                               72269869,  428907790, 165502858, 52502382,
                               274162938, 230802888, 415885704, 264777885};
  const uint32_t ans[M * N] = {50443330,  272952075, 72269869,  274162938,
                               107617688, 269090771, 428907790, 230802888,
                               35212877,  212306001, 165502858, 415885704,
                               326932685, 230806585, 52502382,  264777885};
  SET_MBA0_I32();
  msettilem(M);
  msettilen(N);
  vuint32m1_t vs = mlc_v(src, stride);
  muint32_t md = mmvcc_m_v(vs, 0);
  msc_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * N, "MMVCC_M_V U32");
}

static void test_mmvcc_m_v_f32() {
  const size_t M = 4;
  const size_t N = 4;
  const stride = N * sizeof(fp32_t);
  const fp32_t src[M * N] = {-8.834909, 3.2987583,  6.7918887,  -2.7559993,
                             2.9014728, -3.3611052, -2.1716158, 0.11627129,
                             6.7316413, -4.4896226, 1.9561698,  -4.1715975,
                             -9.602308, -2.576488,  -7.7930236, -4.608881};
  const fp32_t ans[M * N] = {-8.834909,  2.9014728,  6.7316413,  -9.602308,
                             3.2987583,  -3.3611052, -4.4896226, -2.576488,
                             6.7918887,  -2.1716158, 1.9561698,  -7.7930236,
                             -2.7559993, 0.11627129, -4.1715975, -4.608881};
  SET_MBA0_F32();
  msettilem(M);
  msettilen(N);
  vfloat32m1_t vs = mlc_v(src, stride);
  mfloat32_t md = mmvcc_m_v(vs, 0);
  msc_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * N, "MMVCC_M_V F32");
}

static void test_mmvcc_m_v_i64() {
  const size_t M = 2;
  const size_t N = 2;
  const stride = N * sizeof(int64_t);
  const int64_t src[M * N] = {-4024136034524734487, -985927737141634133,
                              -533801673561669591, -3657806910442662472};
  const int64_t ans[M * N] = {-4024136034524734487, -533801673561669591,
                              -985927737141634133, -3657806910442662472};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  vint64m1_t vs = mlc_v(src, stride);
  mint64_t md = mmvcc_m_v(vs, 0);
  msc_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * N, "MMVCC_M_V I64");
}

static void test_mmvcc_m_v_u64() {
  const size_t M = 2;
  const size_t N = 2;
  const stride = N * sizeof(uint64_t);
  const uint64_t src[M * N] = {115562859305890809, 402067820069744121,
                               824600090362417004, 1380241037346867911};
  const uint64_t ans[M * N] = {115562859305890809, 824600090362417004,
                               402067820069744121, 1380241037346867911};
  SET_MBA0_I64();
  msettilem(M);
  msettilen(N);
  vuint64m1_t vs = mlc_v(src, stride);
  muint64_t md = mmvcc_m_v(vs, 0);
  msc_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * N, "MMVCC_M_V U64");
}

static void test_mmvcc_m_v_f64() {
  const size_t M = 2;
  const size_t N = 2;
  const stride = N * sizeof(fp64_t);
  const fp64_t src[M * N] = {-0.2921088, -2.49639746, 8.26217066, -7.39624643};
  const fp64_t ans[M * N] = {-0.2921088, 8.26217066, -2.49639746, -7.39624643};
  SET_MBA0_F64();
  msettilem(M);
  msettilen(N);
  vfloat64m1_t vs = mlc_v(src, stride);
  mfloat64_t md = mmvcc_m_v(vs, 0);
  msc_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * N, "MMVCC_M_V F64");
}

static void test_mmvcc_m_v() {
  test_mmvcc_m_v_i8();
  test_mmvcc_m_v_u8();
  test_mmvcc_m_v_i16();
  test_mmvcc_m_v_u16();
  test_mmvcc_m_v_f16();
  test_mmvcc_m_v_i32();
  test_mmvcc_m_v_u32();
  test_mmvcc_m_v_f32();
  test_mmvcc_m_v_i64();
  test_mmvcc_m_v_u64();
  test_mmvcc_m_v_f64();
}

static void test_mmvac_m_v_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(int8_t);
  const int8_t src[M * K] = {
      -85, -13, -51, -124, -68, -114, -59,  -21,  -37,  1,   -122, -122, 11,
      -71, -36, -83, -123, -10, -82,  -32,  -100, 2,    -15, -113, -35,  -47,
      -79, -86, -89, -58,  -51, -34,  -86,  -82,  8,    -53, -21,  -119, -76,
      -26, -24, -77, -82,  -28, -68,  -125, -59,  -124, -73, -77,  -76,  -126,
      -44, -39, -40, 2,    -36, -104, -95,  -41,  -56,  -38, -68,  -102};
  const int8_t ans[M * K] = {
      -85, -37,  -123, -35, -86,  -24,  -73,  -36, -13,  1,    -10, -47,  -82,
      -77, -77,  -104, -51, -122, -82,  -79,  8,   -82,  -76,  -95, -124, -122,
      -32, -86,  -53,  -28, -126, -41,  -68,  11,  -100, -89,  -21, -68,  -44,
      -56, -114, -71,  2,   -58,  -119, -125, -39, -38,  -59,  -36, -15,  -51,
      -76, -59,  -40,  -68, -21,  -83,  -113, -34, -26,  -124, 2,   -102};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  vint8m1_t vs = mla_v(src, stride);
  mint8_t md = mmvac_m_v(vs, 0);
  msa_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, M * K, "MMVAC_M_V I8");
}

static void test_mmvac_m_v_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(uint8_t);
  const uint8_t src[M * K] = {13, 22, 12, 9,  20, 8,  21, 16, 13, 21, 7,  4,  4,
                              14, 23, 12, 13, 22, 21, 23, 12, 8,  24, 18, 9,  2,
                              5,  18, 9,  18, 16, 12, 0,  7,  0,  4,  13, 10, 0,
                              7,  18, 0,  23, 5,  16, 12, 4,  13, 20, 10, 6,  8,
                              20, 21, 14, 24, 17, 5,  9,  11, 11, 16, 11, 22};
  const uint8_t ans[M * K] = {
      13, 13, 13, 9,  0,  18, 20, 17, 22, 21, 22, 2,  7,  0,  10, 5,
      12, 7,  21, 5,  0,  23, 6,  9,  9,  4,  23, 18, 4,  5,  8,  11,
      20, 4,  12, 9,  13, 16, 20, 11, 8,  14, 8,  18, 10, 12, 21, 16,
      21, 23, 24, 16, 0,  4,  14, 11, 16, 12, 18, 12, 7,  13, 24, 22};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  vuint8m1_t vs = mla_v(src, stride);
  muint8_t md = mmvac_m_v(vs, 0);
  msa_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, M * K, "MMVAC_M_V U8");
}

static void test_mmvac_m_v_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(int16_t);
  const int16_t src[M * K] = {
      -5425,  -11718, -30942, -28248, 2017,   -32725, -26490, -21852,
      -24975, -23807, -9985,  -4170,  1197,   -26895, -20729, -25764,
      -11771, -23136, -28255, -5703,  -32654, -16646, -18539, -27270,
      -4951,  -5929,  -19715, -23622, -28771, -23319, -7449,  -6663,
      -24938, -8445,  -9267,  -13083, -26818, -19951, -18282, -32219,
      -22533, -1971,  -21335, 2671,   -1788,  3263,   -9403,  -9777,
      -13618, -20526, -3629,  1735,   -30173, -27919, -25814, -7144,
      -10995, -21088, -132,   -2277,  2556,   3096,   -1606,  -31842};
  const int16_t ans[M * K] = {
      -5425,  -24975, -11771, -4951,  -24938, -22533, -13618, -10995,
      -11718, -23807, -23136, -5929,  -8445,  -1971,  -20526, -21088,
      -30942, -9985,  -28255, -19715, -9267,  -21335, -3629,  -132,
      -28248, -4170,  -5703,  -23622, -13083, 2671,   1735,   -2277,
      2017,   1197,   -32654, -28771, -26818, -1788,  -30173, 2556,
      -32725, -26895, -16646, -23319, -19951, 3263,   -27919, 3096,
      -26490, -20729, -18539, -7449,  -18282, -9403,  -25814, -1606,
      -21852, -25764, -27270, -6663,  -32219, -9777,  -7144,  -31842};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  vint16m1_t vs = mla_v(src, stride);
  mint16_t md = mmvac_m_v(vs, 0);
  msa_m(md, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, M * K, "MMVAC_M_V I16");
}

static void test_mmvac_m_v_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(uint16_t);
  const uint16_t src[M * K] = {
      1587, 2558, 4834, 1346, 4132, 1934, 5209, 257,  5062, 3556, 5426,
      3684, 2149, 1905, 4819, 3468, 3057, 373,  5537, 2768, 3865, 6206,
      1197, 3730, 5522, 432,  3812, 332,  3764, 5475, 3599, 6231, 4775,
      243,  4459, 2844, 3689, 1890, 1094, 792,  1456, 1474, 1135, 4119,
      3406, 2321, 3273, 5111, 91,   5128, 5503, 6391, 3386, 3915, 5409,
      4928, 1632, 1186, 2210, 5002, 5162, 1218, 6446, 2258};
  const uint16_t ans[M * K] = {
      1587, 5062, 3057, 5522, 4775, 1456, 91,   1632, 2558, 3556, 373,
      432,  243,  1474, 5128, 1186, 4834, 5426, 5537, 3812, 4459, 1135,
      5503, 2210, 1346, 3684, 2768, 332,  2844, 4119, 6391, 5002, 4132,
      2149, 3865, 3764, 3689, 3406, 3386, 5162, 1934, 1905, 6206, 5475,
      1890, 2321, 3915, 1218, 5209, 4819, 1197, 3599, 1094, 3273, 5409,
      6446, 257,  3468, 3730, 6231, 792,  5111, 4928, 2258};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  vuint16m1_t vs = mla_v(src, stride);
  muint16_t md = mmvac_m_v(vs, 0);
  msa_m(md, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, M * K, "MMVAC_M_V U16");
}

static void test_mmvac_m_v_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const stride = K * sizeof(fp16_t);
  const fp16_t src[M * K] = {
      8.23,    6.26,    -0.586,  -7.742, 9.26,   4.02,    5.375,  8.79,
      9.18,    -7.57,   -9.84,   1.505,  -3.188, -2.809,  -2.412, 3.576,
      -1.0625, 6.31,    -4.305,  -3.035, -9.586, 0.03546, 1.705,  9.,
      7.34,    -4.367,  -6.76,   0.0746, -1.752, -2.902,  7.418,  7.695,
      -6.875,  8.84,    -7.21,   8.445,  3.295,  -7.324,  -6.793, 9.17,
      -6.42,   -1.1455, -8.766,  0.692,  4.645,  -4.227,  -7.83,  -8.805,
      -9.05,   -6.543,  0.707,   9.27,   -0.183, 9.05,    -4.387, -4.926,
      1.543,   2.201,   -0.5103, 3.357,  -0.823, 4.016,   -4.164, 1.863};
  const fp16_t ans[M * K] = {
      8.23,   9.18,   -1.0625, 7.34,   -6.875, -6.42,   -9.05,  1.543,
      6.26,   -7.57,  6.31,    -4.367, 8.84,   -1.1455, -6.543, 2.201,
      -0.586, -9.84,  -4.305,  -6.76,  -7.21,  -8.766,  0.707,  -0.5103,
      -7.742, 1.505,  -3.035,  0.0746, 8.445,  0.692,   9.27,   3.357,
      9.26,   -3.188, -9.586,  -1.752, 3.295,  4.645,   -0.183, -0.823,
      4.02,   -2.809, 0.03546, -2.902, -7.324, -4.227,  9.05,   4.016,
      5.375,  -2.412, 1.705,   7.418,  -6.793, -7.83,   -4.387, -4.164,
      8.79,   3.576,  9.,      7.695,  9.17,   -8.805,  -4.926, 1.863};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  vfloat16m1_t vs = mla_v(src, stride);
  mfloat16_t md = mmvac_m_v(vs, 0);
  msa_m(md, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, f16_buffer, M * K, "MMVAC_M_V F16");
}

static void test_mmvac_m_v_i32() {
  const size_t M = 4;
  const size_t K = 4;
  const stride = K * sizeof(int32_t);
  const int32_t src[M * K] = {
      -461443808,  199472183,  -1232905849, -523658315,
      -1778254273, -291435809, -1741937253, -1630191164,
      -1948196316, -546547128, -43138968,   -100936611,
      -1523765476, 167556507,  -1435011556, -1085808352};
  const int32_t ans[M * K] = {
      -461443808, -1778254273, -1948196316, -1523765476, 199472183, -291435809,
      -546547128, 167556507,   -1232905849, -1741937253, -43138968, -1435011556,
      -523658315, -1630191164, -100936611,  -1085808352};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  vint32m1_t vs = mla_v(src, stride);
  mint32_t md = mmvac_m_v(vs, 0);
  msa_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, M * K, "MMVAC_M_V I32");
}

static void test_mmvac_m_v_u32() {
  const size_t M = 4;
  const size_t K = 4;
  const stride = K * sizeof(uint32_t);
  const uint32_t src[M * K] = {50443330,  107617688, 35212877,  326932685,
                               272952075, 269090771, 212306001, 230806585,
                               72269869,  428907790, 165502858, 52502382,
                               274162938, 230802888, 415885704, 264777885};
  const uint32_t ans[M * K] = {50443330,  272952075, 72269869,  274162938,
                               107617688, 269090771, 428907790, 230802888,
                               35212877,  212306001, 165502858, 415885704,
                               326932685, 230806585, 52502382,  264777885};
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  vuint32m1_t vs = mla_v(src, stride);
  muint32_t md = mmvac_m_v(vs, 0);
  msa_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, M * K, "MMVAC_M_V U32");
}

static void test_mmvac_m_v_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const stride = K * sizeof(fp32_t);
  const fp32_t src[M * K] = {-8.834909, 3.2987583,  6.7918887,  -2.7559993,
                             2.9014728, -3.3611052, -2.1716158, 0.11627129,
                             6.7316413, -4.4896226, 1.9561698,  -4.1715975,
                             -9.602308, -2.576488,  -7.7930236, -4.608881};
  const fp32_t ans[M * K] = {-8.834909,  2.9014728,  6.7316413,  -9.602308,
                             3.2987583,  -3.3611052, -4.4896226, -2.576488,
                             6.7918887,  -2.1716158, 1.9561698,  -7.7930236,
                             -2.7559993, 0.11627129, -4.1715975, -4.608881};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  vfloat32m1_t vs = mla_v(src, stride);
  mfloat32_t md = mmvac_m_v(vs, 0);
  msa_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, M * K, "MMVAC_M_V F32");
}

static void test_mmvac_m_v_i64() {
  const size_t M = 2;
  const size_t K = 2;
  const stride = K * sizeof(int64_t);
  const int64_t src[M * K] = {-4024136034524734487, -985927737141634133,
                              -533801673561669591, -3657806910442662472};
  const int64_t ans[M * K] = {-4024136034524734487, -533801673561669591,
                              -985927737141634133, -3657806910442662472};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  vint64m1_t vs = mla_v(src, stride);
  mint64_t md = mmvac_m_v(vs, 0);
  msa_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, M * K, "MMVAC_M_V I64");
}

static void test_mmvac_m_v_u64() {
  const size_t M = 2;
  const size_t K = 2;
  const stride = K * sizeof(uint64_t);
  const uint64_t src[M * K] = {115562859305890809, 402067820069744121,
                               824600090362417004, 1380241037346867911};
  const uint64_t ans[M * K] = {115562859305890809, 824600090362417004,
                               402067820069744121, 1380241037346867911};
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  vuint64m1_t vs = mla_v(src, stride);
  muint64_t md = mmvac_m_v(vs, 0);
  msa_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, M * K, "MMVAC_M_V U64");
}

static void test_mmvac_m_v_f64() {
  const size_t M = 2;
  const size_t K = 2;
  const stride = K * sizeof(fp64_t);
  const fp64_t src[M * K] = {-0.2921088, -2.49639746, 8.26217066, -7.39624643};
  const fp64_t ans[M * K] = {-0.2921088, 8.26217066, -2.49639746, -7.39624643};
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  vfloat64m1_t vs = mla_v(src, stride);
  mfloat64_t md = mmvac_m_v(vs, 0);
  msa_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, M * K, "MMVAC_M_V F64");
}

static void test_mmvac_m_v() {
  test_mmvac_m_v_i8();
  test_mmvac_m_v_u8();
  test_mmvac_m_v_i16();
  test_mmvac_m_v_u16();
  test_mmvac_m_v_f16();
  test_mmvac_m_v_i32();
  test_mmvac_m_v_u32();
  test_mmvac_m_v_f32();
  test_mmvac_m_v_i64();
  test_mmvac_m_v_u64();
  test_mmvac_m_v_f64();
}

static void test_mmvbc_m_v_i8() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(int8_t);
  const int8_t src[K * N] = {
      -85, -13, -51, -124, -68, -114, -59,  -21,  -37,  1,   -122, -122, 11,
      -71, -36, -83, -123, -10, -82,  -32,  -100, 2,    -15, -113, -35,  -47,
      -79, -86, -89, -58,  -51, -34,  -86,  -82,  8,    -53, -21,  -119, -76,
      -26, -24, -77, -82,  -28, -68,  -125, -59,  -124, -73, -77,  -76,  -126,
      -44, -39, -40, 2,    -36, -104, -95,  -41,  -56,  -38, -68,  -102};
  const int8_t ans[K * N] = {
      -85, -37,  -123, -35, -86,  -24,  -73,  -36, -13,  1,    -10, -47,  -82,
      -77, -77,  -104, -51, -122, -82,  -79,  8,   -82,  -76,  -95, -124, -122,
      -32, -86,  -53,  -28, -126, -41,  -68,  11,  -100, -89,  -21, -68,  -44,
      -56, -114, -71,  2,   -58,  -119, -125, -39, -38,  -59,  -36, -15,  -51,
      -76, -59,  -40,  -68, -21,  -83,  -113, -34, -26,  -124, 2,   -102};
  SET_MBA0_I8();
  msettilen(N);
  msettilek(K);
  vint8m1_t vs = mlb_v(src, stride);
  mint8_t md = mmvbc_m_v(vs, 0);
  msb_m(md, i8_buffer, stride);
  EXCEPT_I8_ARRAY_EQ(ans, i8_buffer, K * N, "MMVBC_M_V I8");
}

static void test_mmvbc_m_v_u8() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(uint8_t);
  const uint8_t src[K * N] = {13, 22, 12, 9,  20, 8,  21, 16, 13, 21, 7,  4,  4,
                              14, 23, 12, 13, 22, 21, 23, 12, 8,  24, 18, 9,  2,
                              5,  18, 9,  18, 16, 12, 0,  7,  0,  4,  13, 10, 0,
                              7,  18, 0,  23, 5,  16, 12, 4,  13, 20, 10, 6,  8,
                              20, 21, 14, 24, 17, 5,  9,  11, 11, 16, 11, 22};
  const uint8_t ans[K * N] = {
      13, 13, 13, 9,  0,  18, 20, 17, 22, 21, 22, 2,  7,  0,  10, 5,
      12, 7,  21, 5,  0,  23, 6,  9,  9,  4,  23, 18, 4,  5,  8,  11,
      20, 4,  12, 9,  13, 16, 20, 11, 8,  14, 8,  18, 10, 12, 21, 16,
      21, 23, 24, 16, 0,  4,  14, 11, 16, 12, 18, 12, 7,  13, 24, 22};
  SET_MBA0_I8();
  msettilen(N);
  msettilek(K);
  vuint8m1_t vs = mlb_v(src, stride);
  muint8_t md = mmvbc_m_v(vs, 0);
  msb_m(md, u8_buffer, stride);
  EXCEPT_U8_ARRAY_EQ(ans, u8_buffer, K * N, "MMVBC_M_V U8");
}

static void test_mmvbc_m_v_i16() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(int16_t);
  const int16_t src[K * N] = {
      -5425,  -11718, -30942, -28248, 2017,   -32725, -26490, -21852,
      -24975, -23807, -9985,  -4170,  1197,   -26895, -20729, -25764,
      -11771, -23136, -28255, -5703,  -32654, -16646, -18539, -27270,
      -4951,  -5929,  -19715, -23622, -28771, -23319, -7449,  -6663,
      -24938, -8445,  -9267,  -13083, -26818, -19951, -18282, -32219,
      -22533, -1971,  -21335, 2671,   -1788,  3263,   -9403,  -9777,
      -13618, -20526, -3629,  1735,   -30173, -27919, -25814, -7144,
      -10995, -21088, -132,   -2277,  2556,   3096,   -1606,  -31842};
  const int16_t ans[K * N] = {
      -5425,  -24975, -11771, -4951,  -24938, -22533, -13618, -10995,
      -11718, -23807, -23136, -5929,  -8445,  -1971,  -20526, -21088,
      -30942, -9985,  -28255, -19715, -9267,  -21335, -3629,  -132,
      -28248, -4170,  -5703,  -23622, -13083, 2671,   1735,   -2277,
      2017,   1197,   -32654, -28771, -26818, -1788,  -30173, 2556,
      -32725, -26895, -16646, -23319, -19951, 3263,   -27919, 3096,
      -26490, -20729, -18539, -7449,  -18282, -9403,  -25814, -1606,
      -21852, -25764, -27270, -6663,  -32219, -9777,  -7144,  -31842};
  SET_MBA0_I16();
  msettilen(N);
  msettilek(K);
  vint16m1_t vs = mlb_v(src, stride);
  mint16_t md = mmvbc_m_v(vs, 0);
  msb_m(md, i16_buffer, stride);
  EXCEPT_I16_ARRAY_EQ(ans, i16_buffer, K * N, "MMVBC_M_V I16");
}

static void test_mmvbc_m_v_u16() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(uint16_t);
  const uint16_t src[K * N] = {
      1587, 2558, 4834, 1346, 4132, 1934, 5209, 257,  5062, 3556, 5426,
      3684, 2149, 1905, 4819, 3468, 3057, 373,  5537, 2768, 3865, 6206,
      1197, 3730, 5522, 432,  3812, 332,  3764, 5475, 3599, 6231, 4775,
      243,  4459, 2844, 3689, 1890, 1094, 792,  1456, 1474, 1135, 4119,
      3406, 2321, 3273, 5111, 91,   5128, 5503, 6391, 3386, 3915, 5409,
      4928, 1632, 1186, 2210, 5002, 5162, 1218, 6446, 2258};
  const uint16_t ans[K * N] = {
      1587, 5062, 3057, 5522, 4775, 1456, 91,   1632, 2558, 3556, 373,
      432,  243,  1474, 5128, 1186, 4834, 5426, 5537, 3812, 4459, 1135,
      5503, 2210, 1346, 3684, 2768, 332,  2844, 4119, 6391, 5002, 4132,
      2149, 3865, 3764, 3689, 3406, 3386, 5162, 1934, 1905, 6206, 5475,
      1890, 2321, 3915, 1218, 5209, 4819, 1197, 3599, 1094, 3273, 5409,
      6446, 257,  3468, 3730, 6231, 792,  5111, 4928, 2258};
  SET_MBA0_I16();
  msettilen(N);
  msettilek(K);
  vuint16m1_t vs = mlb_v(src, stride);
  muint16_t md = mmvbc_m_v(vs, 0);
  msb_m(md, u16_buffer, stride);
  EXCEPT_U16_ARRAY_EQ(ans, u16_buffer, K * N, "MMVBC_M_V U16");
}

static void test_mmvbc_m_v_f16() {
  const size_t N = 8;
  const size_t K = 8;
  const stride = N * sizeof(fp16_t);
  const fp16_t src[K * N] = {
      8.23,    6.26,    -0.586,  -7.742, 9.26,   4.02,    5.375,  8.79,
      9.18,    -7.57,   -9.84,   1.505,  -3.188, -2.809,  -2.412, 3.576,
      -1.0625, 6.31,    -4.305,  -3.035, -9.586, 0.03546, 1.705,  9.,
      7.34,    -4.367,  -6.76,   0.0746, -1.752, -2.902,  7.418,  7.695,
      -6.875,  8.84,    -7.21,   8.445,  3.295,  -7.324,  -6.793, 9.17,
      -6.42,   -1.1455, -8.766,  0.692,  4.645,  -4.227,  -7.83,  -8.805,
      -9.05,   -6.543,  0.707,   9.27,   -0.183, 9.05,    -4.387, -4.926,
      1.543,   2.201,   -0.5103, 3.357,  -0.823, 4.016,   -4.164, 1.863};
  const fp16_t ans[K * N] = {
      8.23,   9.18,   -1.0625, 7.34,   -6.875, -6.42,   -9.05,  1.543,
      6.26,   -7.57,  6.31,    -4.367, 8.84,   -1.1455, -6.543, 2.201,
      -0.586, -9.84,  -4.305,  -6.76,  -7.21,  -8.766,  0.707,  -0.5103,
      -7.742, 1.505,  -3.035,  0.0746, 8.445,  0.692,   9.27,   3.357,
      9.26,   -3.188, -9.586,  -1.752, 3.295,  4.645,   -0.183, -0.823,
      4.02,   -2.809, 0.03546, -2.902, -7.324, -4.227,  9.05,   4.016,
      5.375,  -2.412, 1.705,   7.418,  -6.793, -7.83,   -4.387, -4.164,
      8.79,   3.576,  9.,      7.695,  9.17,   -8.805,  -4.926, 1.863};
  SET_MBA0_F16();
  msettilen(N);
  msettilek(K);
  vfloat16m1_t vs = mlb_v(src, stride);
  mfloat16_t md = mmvbc_m_v(vs, 0);
  msb_m(md, f16_buffer, stride);
  EXCEPT_F16_ARRAY_EQ(ans, f16_buffer, K * N, "MMVBC_M_V F16");
}

static void test_mmvbc_m_v_i32() {
  const size_t N = 4;
  const size_t K = 4;
  const stride = N * sizeof(int32_t);
  const int32_t src[K * N] = {
      -461443808,  199472183,  -1232905849, -523658315,
      -1778254273, -291435809, -1741937253, -1630191164,
      -1948196316, -546547128, -43138968,   -100936611,
      -1523765476, 167556507,  -1435011556, -1085808352};
  const int32_t ans[K * N] = {
      -461443808, -1778254273, -1948196316, -1523765476, 199472183, -291435809,
      -546547128, 167556507,   -1232905849, -1741937253, -43138968, -1435011556,
      -523658315, -1630191164, -100936611,  -1085808352};
  SET_MBA0_I32();
  msettilen(N);
  msettilek(K);
  vint32m1_t vs = mlb_v(src, stride);
  mint32_t md = mmvbc_m_v(vs, 0);
  msb_m(md, i32_buffer, stride);
  EXCEPT_I32_ARRAY_EQ(ans, i32_buffer, K * N, "MMVBC_M_V I32");
}

static void test_mmvbc_m_v_u32() {
  const size_t N = 4;
  const size_t K = 4;
  const stride = N * sizeof(uint32_t);
  const uint32_t src[K * N] = {50443330,  107617688, 35212877,  326932685,
                               272952075, 269090771, 212306001, 230806585,
                               72269869,  428907790, 165502858, 52502382,
                               274162938, 230802888, 415885704, 264777885};
  const uint32_t ans[K * N] = {50443330,  272952075, 72269869,  274162938,
                               107617688, 269090771, 428907790, 230802888,
                               35212877,  212306001, 165502858, 415885704,
                               326932685, 230806585, 52502382,  264777885};
  SET_MBA0_I32();
  msettilen(N);
  msettilek(K);
  vuint32m1_t vs = mlb_v(src, stride);
  muint32_t md = mmvbc_m_v(vs, 0);
  msb_m(md, u32_buffer, stride);
  EXCEPT_U32_ARRAY_EQ(ans, u32_buffer, K * N, "MMVBC_M_V U32");
}

static void test_mmvbc_m_v_f32() {
  const size_t N = 4;
  const size_t K = 4;
  const stride = N * sizeof(fp32_t);
  const fp32_t src[K * N] = {-8.834909, 3.2987583,  6.7918887,  -2.7559993,
                             2.9014728, -3.3611052, -2.1716158, 0.11627129,
                             6.7316413, -4.4896226, 1.9561698,  -4.1715975,
                             -9.602308, -2.576488,  -7.7930236, -4.608881};
  const fp32_t ans[K * N] = {-8.834909,  2.9014728,  6.7316413,  -9.602308,
                             3.2987583,  -3.3611052, -4.4896226, -2.576488,
                             6.7918887,  -2.1716158, 1.9561698,  -7.7930236,
                             -2.7559993, 0.11627129, -4.1715975, -4.608881};
  SET_MBA0_F32();
  msettilen(N);
  msettilek(K);
  vfloat32m1_t vs = mlb_v(src, stride);
  mfloat32_t md = mmvbc_m_v(vs, 0);
  msb_m(md, f32_buffer, stride);
  EXCEPT_F32_ARRAY_EQ(ans, f32_buffer, K * N, "MMVBC_M_V F32");
}

static void test_mmvbc_m_v_i64() {
  const size_t N = 2;
  const size_t K = 2;
  const stride = N * sizeof(int64_t);
  const int64_t src[K * N] = {-4024136034524734487, -985927737141634133,
                              -533801673561669591, -3657806910442662472};
  const int64_t ans[K * N] = {-4024136034524734487, -533801673561669591,
                              -985927737141634133, -3657806910442662472};
  SET_MBA0_I64();
  msettilen(N);
  msettilek(K);
  vint64m1_t vs = mlb_v(src, stride);
  mint64_t md = mmvbc_m_v(vs, 0);
  msb_m(md, i64_buffer, stride);
  EXCEPT_I64_ARRAY_EQ(ans, i64_buffer, K * N, "MMVBC_M_V I64");
}

static void test_mmvbc_m_v_u64() {
  const size_t N = 2;
  const size_t K = 2;
  const stride = N * sizeof(uint64_t);
  const uint64_t src[K * N] = {115562859305890809, 402067820069744121,
                               824600090362417004, 1380241037346867911};
  const uint64_t ans[K * N] = {115562859305890809, 824600090362417004,
                               402067820069744121, 1380241037346867911};
  SET_MBA0_I64();
  msettilen(N);
  msettilek(K);
  vuint64m1_t vs = mlb_v(src, stride);
  muint64_t md = mmvbc_m_v(vs, 0);
  msb_m(md, u64_buffer, stride);
  EXCEPT_U64_ARRAY_EQ(ans, u64_buffer, K * N, "MMVBC_M_V U64");
}

static void test_mmvbc_m_v_f64() {
  const size_t N = 2;
  const size_t K = 2;
  const stride = N * sizeof(fp64_t);
  const fp64_t src[K * N] = {-0.2921088, -2.49639746, 8.26217066, -7.39624643};
  const fp64_t ans[K * N] = {-0.2921088, 8.26217066, -2.49639746, -7.39624643};
  SET_MBA0_F64();
  msettilen(N);
  msettilek(K);
  vfloat64m1_t vs = mlb_v(src, stride);
  mfloat64_t md = mmvbc_m_v(vs, 0);
  msb_m(md, f64_buffer, stride);
  EXCEPT_F64_ARRAY_EQ(ans, f64_buffer, K * N, "MMVBC_M_V F64");
}

static void test_mmvbc_m_v() {
  test_mmvbc_m_v_i8();
  test_mmvbc_m_v_u8();
  test_mmvbc_m_v_i16();
  test_mmvbc_m_v_u16();
  test_mmvbc_m_v_f16();
  test_mmvbc_m_v_i32();
  test_mmvbc_m_v_u32();
  test_mmvbc_m_v_f32();
  test_mmvbc_m_v_i64();
  test_mmvbc_m_v_u64();
  test_mmvbc_m_v_f64();
}

static void test_zmv() {
  test_mla_v_msa_v();
  test_mlb_v_msb_v();
  test_mlc_v_msc_v();
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
}

#endif // !MATRIX_TESTS_ISA_ZMV_H_