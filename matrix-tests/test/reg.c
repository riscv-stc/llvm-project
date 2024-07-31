      
#include <riscv_matrix.h>
#include "isa/utils.h"

int main() {
  msettype(E32, M1, BA);
  msettilemi(2);
  msettileni(2);
  float buffer[4];
  float src0[] = {0, 0, 0, 0};
  float src1[] = {1, 1, 1, 1};
  float src2[] = {2, 2, 2, 2};
  float src3[] = {3, 3, 3, 3};
  float src4[] = {4, 4, 4, 4};
  float src5[] = {5, 5, 5, 5};
  float src6[] = {6, 6, 6, 6};
  float src7[] = {7, 7, 7, 7};
  float src8[] = {8, 8, 8, 8};
  float src9[] = {9, 9, 9, 9};
  float src10[] = {10, 10, 10, 10};
  float src11[] = {11, 11, 11, 11};

  mfloat32m1_t tr0 = mlce32_m1(src0, 8);
  mfloat32m1_t tr1 = mlce32_m1(src1, 8);
  mfloat32m1_t tr2 = mlce32_m1(src2, 8);
  mfloat32m1_t tr3 = mlce32_m1(src3, 8);
  mfloat32m1_t tr4 = mlce32_m1(src4, 8);
  mfloat32m1_t tr5 = mlce32_m1(src5, 8);
  mfloat32m1_t tr6 = mlce32_m1(src6, 8);
  mfloat32m1_t tr7 = mlce32_m1(src7, 8);
  mfloat32m1_t tr8 = mlce32_m1(src8, 8);
  mfloat32m1_t tr9 = mlce32_m1(src9, 8);
  mfloat32m1_t tr10 = mlce32_m1(src10, 8);
  mfloat32m1_t tr11 = mlce32_m1(src11, 8);

  mfloat32m1_t out0 = mfadd_mm(tr0, tr1);
  mfloat32m1_t out1 = mfadd_mm(tr2, tr3);
  mfloat32m1_t out2 = mfadd_mm(tr4, tr5);
  mfloat32m1_t out3 = mfadd_mm(tr6, tr7);
  mfloat32m1_t out4 = mfadd_mm(tr8, tr9);
  mfloat32m1_t out5 = mfadd_mm(tr10, tr11);

  mfloat32m1_t out6 = mfadd_mm(out0, out1);
  mfloat32m1_t out7 = mfadd_mm(out2, out3);
  mfloat32m1_t out8 = mfadd_mm(out4, out5);
  mfloat32m1_t out9 = mfadd_mm(out6, out7);
  mfloat32m1_t out = mfadd_mm(out8, out9);
  // mfloat32m1_t tmp1 = mfadd_mm(tr0, tr1);
  // mfloat32m1_t tmp2 = mfadd_mm(tr2, tr3);
  // mfloat32m1_t tmp3 = mfadd_mm(tr4, tr5);
  // mfloat32m1_t tmp4 = mfadd_mm(tr6, tr7);
  // mfloat32m1_t tmp5 = mfadd_mm(tr8, tr9);
  // mfloat32m1_t tmp6 = mfadd_mm(tr10, tr11);
  // mfloat32m1_t tmp7 = mfadd_mm(tr0, tr11);
  // mfloat32m1_t tmp8 = mfadd_mm(tr1, tr10);
  // mfloat32m1_t tmp9 = mfadd_mm(tr2, tr9);
  // mfloat32m1_t tmp10 = mfadd_mm(tr3, tr8);
  // mfloat32m1_t tmp11 = mfadd_mm(tr4, tr7);
  // mfloat32m1_t tmp12 = mfadd_mm(tr5, tr6);
  // out = mfsub_mm(out, tmp1);
  // out = mfsub_mm(out, tmp2);
  // out = mfsub_mm(out, tmp3);
  // out = mfsub_mm(out, tmp4);
  // out = mfsub_mm(out, tmp5);
  // out = mfsub_mm(out, tmp6);
  // out = mfsub_mm(out, tmp7);
  // out = mfsub_mm(out, tmp8);
  // out = mfsub_mm(out, tmp9);
  // out = mfsub_mm(out, tmp10);
  // out = mfsub_mm(out, tmp11);
  // out = mfsub_mm(out, tmp12);
  // msce32_m(tmp1, buffer, 8);
  // msce32_m(tmp2, buffer, 8);
  // msce32_m(tmp3, buffer, 8);
  // msce32_m(tmp4, buffer, 8);
  // msce32_m(tmp5, buffer, 8);
  // msce32_m(tmp6, buffer, 8);
  msce32_m(out, buffer, 8);
  for (int i = 0; i < 4; ++i) {
    printf("%f\n", buffer[i]);
  }
  return 0;
}

    
