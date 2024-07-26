// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-matrix -target-feature +experimental-v -O2 -S -o - %s | FileCheck --check-prefix=CHECK-ASM-RV64 %s

#include <riscv_matrix.h>

int foo(const int8_t *in1, const int8_t *in2, int8_t *out, int a) {
    // CHECK-ASM-RV64:  msettype        a4, a3
    // CHECK-ASM-RV64:  msettilem       a4, a3
    // CHECK-ASM-RV64:  msettilen       a4, a3
    // CHECK-ASM-RV64:  msettilek       a4, a3
    // CHECK-ASM-RV64:  msettypei       a4, e8, m1, bu, fp64
    // CHECK-ASM-RV64:  msettilemi      a4, 32
    // CHECK-ASM-RV64:  msettileni      a4, 64
    // CHECK-ASM-RV64:  msettileki      a4, 128
    // CHECK-ASM-RV64:  addi    a4, zero, 256
    // CHECK-ASM-RV64:  msettile        a4, a4
    // CHECK-ASM-RV64:  mlae8.m     tr0, (a0), a3, m1
    // CHECK-ASM-RV64:  mlae8.m     tr1, (a1), a3, m1
    // CHECK-ASM-RV64:  madd.mm     tr0, tr0, tr1, m1
    // CHECK-ASM-RV64:  msae8.m     tr0, (a2), a3, m1
    msettype(a);
    msettilem(a);
    msettilen(a);
    msettilek(a);
    msettypei(64);
    msettilemi(32);
    msettileni(64);
    msettileki(128);
    msettile(256);
    mint8m1_t m1 = mlae8_m1(in1, a);
    mint8m1_t m2 = mlae8_m1(in2, a);
    // m1 = mmv_s_x(m1, 5, a);
    mint8m1_t m3 = madd_mm(m1, m2);
    msae8_m(m3, out, a);
    return 0;
}
