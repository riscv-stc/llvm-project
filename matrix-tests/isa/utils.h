#ifndef _MATRIX_TEST_UTILS_H_
#define _MATRIX_TEST_UTILS_H_

#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef _Float16 fp16_t;
typedef float fp32_t;
typedef double fp64_t;

int8_t i8_buffer[200];
int16_t i16_buffer[200];
int32_t i32_buffer[200];
int64_t i64_buffer[200];
uint8_t u8_buffer[200];
uint16_t u16_buffer[200];
uint32_t u32_buffer[200];
uint64_t u64_buffer[200];
fp16_t f16_buffer[200];
fp32_t f32_buffer[200];
fp64_t f64_buffer[200];

static int test_cases = 0;
static int pass_cases = 0;

#define EXCEPT_SCALAR_EQ_BASE(equality, except, actual, format, name)          \
  do {                                                                         \
    test_cases++;                                                              \
    if ((equality)) {                                                          \
      pass_cases++;                                                            \
    } else {                                                                   \
      printf("%s:%d: %s FAIL! expect: " format " actual: " format "\n",        \
             __FILE__, __LINE__, (name), (except), (actual));                  \
    }                                                                          \
  } while (0);

#define EXCEPT_I8_SCALAR_EQ(except, actual, name)                              \
  EXCEPT_SCALAR_EQ_BASE((except) == (actual), (except), (actual), "%d", name)

#define EXCEPT_U8_SCALAR_EQ(except, actual, name)                              \
  EXCEPT_SCALAR_EQ_BASE((except) == (actual), (except), (actual), "%d", name)

#define EXCEPT_I16_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((except) == (actual), (except), (actual), "%d", name)

#define EXCEPT_U16_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((except) == (actual), (except), (actual), "%u", name)

#define EXCEPT_I32_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((except) == (actual), (except), (actual), "%d", name)

#define EXCEPT_U32_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((except) == (actual), (except), (actual), "%u", name)

#define EXCEPT_I64_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((except) == (actual), (except), (actual), "%ld", name)

#define EXCEPT_U64_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((except) == (actual), (except), (actual), "%lu", name)

#define EXCEPT_F16_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((fp16_t)(except) == (fp16_t)(actual),                  \
                        (fp16_t)(except), (fp16_t)(actual), "%f", name)

#define EXCEPT_F32_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((fp32_t)(except) == (fp32_t)(actual),                  \
                        (fp32_t)(except), (fp32_t)(actual), "%f", name)

#define EXCEPT_F64_SCALAR_EQ(except, actual, name)                             \
  EXCEPT_SCALAR_EQ_BASE((fp64_t)(except) == (fp64_t)(actual),                  \
                        (fp64_t)(except), (fp64_t)(actual), "%f", name)

#define EXCEPT_FP_SCALAR_LAX_EQ(except, actual, name)                          \
  EXCEPT_SCALAR_EQ_BASE(                                                       \
      ((((except) - (actual)) < 1e-5) && (((except) - (actual)) > -1e-5)),     \
      (except), (actual), "%f", name)

#define EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, type, format, name)              \
  do {                                                                         \
    test_cases++;                                                              \
    int i;                                                                     \
    type *casted_arr1 = (type *)(arr1);                                        \
    type *casted_arr2 = (type *)(arr2);                                        \
    for (i = 0; i < (len); ++i) {                                              \
      if (casted_arr1[i] != casted_arr2[i]) {                                  \
        printf("%s:%d: %s FAIL! First differ at index %d, "                    \
               "expect: " format " actual: " format "\n",                      \
               __FILE__, __LINE__, (name), i, casted_arr1[i], casted_arr2[i]); \
        break;                                                                 \
      }                                                                        \
    }                                                                          \
    if (i == (len)) {                                                          \
      pass_cases++;                                                            \
    }                                                                          \
  } while (0);

#define EXCEPT_U8_ARRAY_EQ(arr1, arr2, len, name)                              \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, uint8_t, "%d", name)

#define EXCEPT_I8_ARRAY_EQ(arr1, arr2, len, name)                              \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, int8_t, "%d", name)

#define EXCEPT_U16_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, uint16_t, "%u", name)

#define EXCEPT_I16_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, int16_t, "%d", name)

#define EXCEPT_U32_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, uint32_t, "%u", name)

#define EXCEPT_I32_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, int32_t, "%d", name)

#define EXCEPT_U64_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, uint64_t, "%lu", name)

#define EXCEPT_I64_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, int64_t, "%ld", name)

#define EXCEPT_F16_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, fp16_t, "%f", name)

#define EXCEPT_F32_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, fp32_t, "%f", name)

#define EXCEPT_F64_ARRAY_EQ(arr1, arr2, len, name)                             \
  EXCEPT_ARRAY_EQ_BASE(arr1, arr2, len, fp64_t, "%f", name)

#define EXCEPT_ARRAY_LAX_EQ_BASE(arr1, arr2, len, type, format, name)          \
  do {                                                                         \
    test_cases++;                                                              \
    int i;                                                                     \
    type *casted_arr1 = (type *)(arr1);                                        \
    type *casted_arr2 = (type *)(arr2);                                        \
    for (i = 0; i < (len); ++i) {                                              \
      if ((casted_arr1[i] - casted_arr2[i] > 5e-1) ||                          \
          (casted_arr1[i] - casted_arr2[i] < -5e-1)) {                         \
        printf("%s:%d: %s FAIL! First differ at index %d: "                    \
               "expect: " format " actual: " format "\n",                      \
               __FILE__, __LINE__, (name), i, casted_arr1[i], casted_arr2[i]); \
        break;                                                                 \
      }                                                                        \
    }                                                                          \
    if (i == (len)) {                                                          \
      pass_cases++;                                                            \
    }                                                                          \
  } while (0);

#define EXCEPT_F16_ARRAY_LAX_EQ(arr1, arr2, len, name)                        \
  EXCEPT_ARRAY_LAX_EQ_BASE(arr1, arr2, len, fp16_t, "%f", name)

#define EXCEPT_F32_ARRAY_LAX_EQ(arr1, arr2, len, name)                        \
  EXCEPT_ARRAY_LAX_EQ_BASE(arr1, arr2, len, fp32_t, "%f", name)

#define EXCEPT_F64_ARRAY_LAX_EQ(arr1, arr2, len, name)                        \
  EXCEPT_ARRAY_LAX_EQ_BASE(arr1, arr2, len, fp64_t, "%f", name)

#define DUMP_MATRIX(arr, row, col, format)                                     \
  do {                                                                         \
    for (int i = 0; i < (row); ++i) {                                          \
      for (int j = 0; j < (col); ++j) {                                        \
        printf(format " ", (arr)[i * (col) + j]);                              \
      }                                                                        \
      printf("\n");                                                            \
    }                                                                          \
  } while (0);

#define CONFIGURATION_MTYPE(hi, li)                                            \
  do {                                                                         \
    msettypei((li));                                                           \
    msettypehi((hi));                                                          \
  } while (0);

#define SET_MBA0_I8() CONFIGURATION_MTYPE(0x0, 0x10)

#define SET_MBA0_I16() CONFIGURATION_MTYPE(0x0, 0x21)

#define SET_MBA0_I32() CONFIGURATION_MTYPE(0x0, 0x42)

#define SET_MBA0_I64() CONFIGURATION_MTYPE(0x0, 0x83)

#define SET_MBA0_F16() CONFIGURATION_MTYPE(0x1, 0x1)

#define SET_MBA0_F32() CONFIGURATION_MTYPE(0x4, 0x2)

#define SET_MBA0_F64() CONFIGURATION_MTYPE(0x10, 0x3)

#define SET_MBA0_F16F32() CONFIGURATION_MTYPE(0x5, 0x1)

#define SET_MBA0_F32F64() CONFIGURATION_MTYPE(0x14, 0x2)

#define SET_MBA0_F16I16() CONFIGURATION_MTYPE(0x1, 0x21)

#define SET_MBA0_F32I32() CONFIGURATION_MTYPE(0x4, 0x42)

#define SET_MBA0_F64I64() CONFIGURATION_MTYPE(0x10, 0x83)

#define SET_MBA0_F16I8() CONFIGURATION_MTYPE(0x1, 0x10)

#define SET_MBA0_F16I32() CONFIGURATION_MTYPE(0x1, 0x42)

#define SET_MBA0_F32I64() CONFIGURATION_MTYPE(0x4, 0x83)

#define SET_MBA0_F32I16() CONFIGURATION_MTYPE(0x4, 0x21)

#define SET_MBA0_F64I32() CONFIGURATION_MTYPE(0x10, 0x42)

#define SET_MBA0_F32I8() CONFIGURATION_MTYPE(0x4, 0x10)

#endif // !_MATRIX_TEST_UTILS_H_