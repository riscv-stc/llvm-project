// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-matrix -target-feature +experimental-v -O2 -S -o - %s | FileCheck --check-prefix=CHECK-ASM-RV64 %s

#include <riscv_matrix.h>

int foo(int a) {
    // CHECK-ASM-RV64:    msettilem       a1, a0
    // CHECK-ASM-RV64:    msettilen       a1, a0
    // CHECK-ASM-RV64:    msettilek       a1, a0
    // CHECK-ASM-RV64:    msettilemi      a1, 32
    // CHECK-ASM-RV64:    msettileni      a1, 64
    // CHECK-ASM-RV64:    msettileki      a1, 128
    // CHECK-ASM-RV64:    addi    a1, zero, 256
    // CHECK-ASM-RV64:    msettile        a1, a1
    // CHECK-ASM-RV64:    lui     a1, 16
    // CHECK-ASM-RV64:    addiw   a1, a1, 257
    // CHECK-ASM-RV64:    msettile        a1, a1
    // CHECK-ASM-RV64:    msettypei       a1, e8, m1, ba
    // CHECK-ASM-RV64:    msettypei       a1, e16, m2, bu
    // CHECK-ASM-RV64:    msettypei       a1, e32, m4, bu
    // CHECK-ASM-RV64:    msettypei       a1, e64, m1, bu
    // CHECK-ASM-RV64:    msettypei       a1, e64, m1, bu, bf16
    // CHECK-ASM-RV64:    msettypei       a1, e64, m1, bu, fp64, int4
    // CHECK-ASM-RV64:    msettypei       a1, e64, m1, bu, fp64, fp8, int4
    // CHECK-ASM-RV64:    msettypei       a1, e64, m1, bu, fp64, bf16, fp8, int4
    // CHECK-ASM-RV64:    msettypei       a1, e64, m1, bu, fp64, bf16, tf32, fp8, int4
    // CHECK-ASM-RV64:    msettype        a0, a0
    // CHECK-ASM-RV64:    msettypei       a0, e8, m1, bu, fp64

    msettilem(a);
    msettilen(a);
    msettilek(a);

    msettilemi(32);
    msettileni(64);
    msettileki(128);
    msettile(256);
    msettile(1, 1, 1);

    msettype(E8, M1, BA);
    msettype(E16, M2, BU);
    msettype(E32, M4, BU);
    msettype(E64, M1, BU);
    msettype(E64, M1, BU, MBF16);
    msettype(E64, M1, BU, MINT4, MFP64);
    msettype(E64, M1, BU, MINT4, MFP8, MFP64);
    msettype(E64, M1, BU, MINT4, MFP8, MFP64, MBF16);
    msettype(E64, M1, BU, MINT4, MFP8, MFP64, MBF16, MTF32);
    msettype(a);
    msettypei(64);

    return 0;
}
