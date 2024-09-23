# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

mlae8.m tr0, (a0), a1
# CHECK-INST: mlae8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 04 <unknown>

mlae16.m tr0, (a0), a1
# CHECK-INST: mlae16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 04 <unknown>

mlae32.m tr0, (a0), a1
# CHECK-INST: mlae32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 04 <unknown>

mlae64.m tr0, (a0), a1
# CHECK-INST: mlae64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 04 <unknown>

mlbe8.m tr0, (a0), a1
# CHECK-INST: mlbe8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 08 <unknown>

mlbe16.m tr0, (a0), a1
# CHECK-INST: mlbe16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 08 <unknown>

mlbe32.m tr0, (a0), a1
# CHECK-INST: mlbe32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 08 <unknown>

mlbe64.m tr0, (a0), a1
# CHECK-INST: mlbe64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 08 <unknown>

mlce8.m acc0, (a0), a1
# CHECK-INST: mlce8.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 00 <unknown>

mlce16.m acc0, (a0), a1
# CHECK-INST: mlce16.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 00 <unknown>

mlce32.m acc0, (a0), a1
# CHECK-INST: mlce32.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 00 <unknown>

mlce64.m acc0, (a0), a1
# CHECK-INST: mlce64.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 00 <unknown>

mltre8.m tr0, (a0), a1
# CHECK-INST: mltre8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 0c <unknown>

mltre16.m tr0, (a0), a1
# CHECK-INST: mltre16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 0c <unknown>

mltre32.m tr0, (a0), a1
# CHECK-INST: mltre32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 0c <unknown>

mltre64.m tr0, (a0), a1
# CHECK-INST: mltre64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 0c <unknown>

mlate8.m tr0, (a0), a1
# CHECK-INST: mlate8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x08,0xb5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 b5 04 <unknown>

mlate16.m tr0, (a0), a1
# CHECK-INST: mlate16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x18,0xb5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 b5 04 <unknown>

mlate32.m tr0, (a0), a1
# CHECK-INST: mlate32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x28,0xb5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 b5 04 <unknown>

mlate64.m tr0, (a0), a1
# CHECK-INST: mlate64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x38,0xb5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 b5 04 <unknown>

mlbte8.m tr0, (a0), a1
# CHECK-INST: mlbte8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x08,0xb5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 b5 08 <unknown>

mlbte16.m tr0, (a0), a1
# CHECK-INST: mlbte16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x18,0xb5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 b5 08 <unknown>

mlbte32.m tr0, (a0), a1
# CHECK-INST: mlbte32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x28,0xb5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 b5 08 <unknown>

mlbte64.m tr0, (a0), a1
# CHECK-INST: mlbte64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x38,0xb5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 b5 08 <unknown>

mlcte8.m acc0, (a0), a1
# CHECK-INST: mlcte8.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x08,0xb5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 b5 00 <unknown>

mlcte16.m acc0, (a0), a1
# CHECK-INST: mlcte16.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x18,0xb5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 b5 00 <unknown>

mlcte32.m acc0, (a0), a1
# CHECK-INST: mlcte32.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x28,0xb5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 b5 00 <unknown>

mlcte64.m acc0, (a0), a1
# CHECK-INST: mlcte64.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x38,0xb5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 b5 00 <unknown>

mlacce8.m acc0, (a0), a1
# CHECK-INST: mlacce8.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x08,0xb5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 b5 0c <unknown>

mlacce16.m acc0, (a0), a1
# CHECK-INST: mlacce16.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x18,0xb5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 b5 0c <unknown>

mlacce32.m acc0, (a0), a1
# CHECK-INST: mlacce32.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x28,0xb5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 b5 0c <unknown>

mlacce64.m acc0, (a0), a1
# CHECK-INST: mlacce64.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x38,0xb5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 b5 0c <unknown>

mlae8.v v0, (a0), a1
# CHECK-INST: mlae8.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 84 <unknown>

mlae16.v v0, (a0), a1
# CHECK-INST: mlae16.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 84 <unknown>

mlae32.v v0, (a0), a1
# CHECK-INST: mlae32.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 84 <unknown>

mlae64.v v0, (a0), a1
# CHECK-INST: mlae64.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 84 <unknown>

mlbe8.v v0, (a0), a1
# CHECK-INST: mlbe8.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 88 <unknown>

mlbe16.v v0, (a0), a1
# CHECK-INST: mlbe16.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 88 <unknown>

mlbe32.v v0, (a0), a1
# CHECK-INST: mlbe32.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 88 <unknown>

mlbe64.v v0, (a0), a1
# CHECK-INST: mlbe64.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 88 <unknown>

mlce8.v v0, (a0), a1
# CHECK-INST: mlce8.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 80 <unknown>

mlce16.v v0, (a0), a1
# CHECK-INST: mlce16.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 80 <unknown>

mlce32.v v0, (a0), a1
# CHECK-INST: mlce32.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 80 <unknown>

mlce64.v v0, (a0), a1
# CHECK-INST: mlce64.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 80 <unknown>

mlufae8.m tr0, (a0), a1
# CHECK-INST: mlufae8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x40,0xb5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 b5 84 <unknown>

mlufae16.m tr0, (a0), a1
# CHECK-INST: mlufae16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x50,0xb5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 b5 84 <unknown>

mlufae32.m tr0, (a0), a1
# CHECK-INST: mlufae32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x60,0xb5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 b5 84 <unknown>

mlufae64.m tr0, (a0), a1
# CHECK-INST: mlufae64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x70,0xb5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 b5 84 <unknown>

mlufbe8.m tr0, (a0), a1
# CHECK-INST: mlufbe8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x40,0xb5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 b5 88 <unknown>

mlufbe16.m tr0, (a0), a1
# CHECK-INST: mlufbe16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x50,0xb5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 b5 88 <unknown>

mlufbe32.m tr0, (a0), a1
# CHECK-INST: mlufbe32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x60,0xb5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 b5 88 <unknown>

mlufbe64.m tr0, (a0), a1
# CHECK-INST: mlufbe64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x70,0xb5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 b5 88 <unknown>

mlufce8.m acc0, (a0), a1
# CHECK-INST: mlufce8.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x40,0xb5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 b5 80 <unknown>

mlufce16.m acc0, (a0), a1
# CHECK-INST: mlufce16.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x50,0xb5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 b5 80 <unknown>

mlufce32.m acc0, (a0), a1
# CHECK-INST: mlufce32.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x60,0xb5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 b5 80 <unknown>

mlufce64.m acc0, (a0), a1
# CHECK-INST: mlufce64.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x70,0xb5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 b5 80 <unknown>