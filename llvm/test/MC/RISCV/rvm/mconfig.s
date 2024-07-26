# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN


msettypei ra, e8, m4, ba, fp64, int4
# CHECK-INST: msettypei ra, e8, m4, ba, fp64, int4
# CHECK-ENCODING: [0xf7,0x70,0x31,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 31 02 <unknown>

msettype ra, a0
# CHECK-INST: msettype ra, a0
# CHECK-ENCODING: [0xf7,0x70,0x05,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 05 10 <unknown>

msettilemi ra, 4097
# CHECK-INST: msettilemi ra, 4097
# CHECK-ENCODING: [0xf7,0xf0,0x00,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 f0 00 28 <unknown>

msettileki ra, 4097
# CHECK-INST: msettileki ra, 4097
# CHECK-ENCODING: [0xf7,0xf0,0x00,0x48]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 f0 00 48 <unknown>

msettileni ra, 4097
# CHECK-INST: msettileni ra, 4097
# CHECK-ENCODING: [0xf7,0xf0,0x00,0x68]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 f0 00 68 <unknown>

msettilem ra, a0
# CHECK-INST: msettilem ra, a0
# CHECK-ENCODING: [0xf7,0x70,0x05,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 05 30 <unknown>

msettilek ra, a0
# CHECK-INST: msettilek ra, a0
# CHECK-ENCODING: [0xf7,0x70,0x05,0x50]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 05 50 <unknown>

msettilen ra, a0
# CHECK-INST: msettilen ra, a0
# CHECK-ENCODING: [0xf7,0x70,0x05,0x70]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 05 70 <unknown>

msettile ra, a0
# CHECK-INST: msettile ra, a0
# CHECK-ENCODING: [0xf7,0x70,0x05,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 05 80 <unknown>

msetoutsh a0, a1, a2
# CHECK-INST: msetoutsh a0, a1, a2
# CHECK-ENCODING: [0x77,0xf5,0xc5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f5 c5 80 <unknown>

msetinsh a0, a1, a2
# CHECK-INST: msetinsh a0, a1, a2
# CHECK-ENCODING: [0x77,0xf5,0xc5,0x90]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f5 c5 90 <unknown>

msetsk a0, a1, a2
# CHECK-INST: msetsk a0, a1, a2
# CHECK-ENCODING: [0x77,0xf5,0xc5,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f5 c5 a0 <unknown>

msetpadval a0, a1
# CHECK-INST: msetpadval a0, a1
# CHECK-ENCODING: [0x77,0xf5,0x05,0xb0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f5 05 b0 <unknown>