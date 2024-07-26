# RUN: not llvm-mc -triple=riscv64 --mattr=+experimental-matrix --mattr=+f %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

msettypei ra, e80, m4, ba, fp64
# CHECK-ERROR: e[8|16|32|64],m[1|2|4],[ba|bu],fp64,bf16,tf32,fp8,int4

msettypei ra, e8, m40, bb, fp64
# CHECK-ERROR: e[8|16|32|64],m[1|2|4],[ba|bu],fp64,bf16,tf32,fp8,int4

msettypei ra, e8, m4, ba, f1
# CHECK-ERROR: e[8|16|32|64],m[1|2|4],[ba|bu],fp64,bf16,tf32,fp8,int4

msettypei ra, e8, m0, ba, fp64
# CHECK-ERROR: e[8|16|32|64],m[1|2|4],[ba|bu],fp64,bf16,tf32,fp8,int4

msettypei ra, e8, m4, bb, fp64
# CHECK-ERROR: e[8|16|32|64],m[1|2|4],[ba|bu],fp64,bf16,tf32,fp8,int4

msettypei ra, e8, m4, bu, fp64, d
# CHECK-ERROR: e[8|16|32|64],m[1|2|4],[ba|bu],fp64,bf16,tf32,fp8,int4

mlae8.m tr0, (a1), a0, m3
# CHECK-ERROR: operand must be m[0|1|2|4]

mlae8.m tr0, (a1), a0, a1
# CHECK-ERROR: operand must be m[0|1|2|4]
