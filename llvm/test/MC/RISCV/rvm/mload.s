# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

mlae8.m tr0, (a1), a0, m0
# CHECK-INST: mlae8.m tr0, (a1), a0, m0
# CHECK-ENCODING: [0x77,0x8c,0xa5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 8c a5 04 <unknown>

mlae8.m tr0, (a1), a0, m4
# CHECK-INST: mlae8.m tr0, (a1), a0, m4
# CHECK-ENCODING: [0x77,0x88,0xa5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 88 a5 04 <unknown>

mlae16.m tr0, (a1), a0, m2
# CHECK-INST: mlae16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 04 <unknown>

mlae32.m tr0, (a1), a0, m2
# CHECK-INST: mlae32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 04 <unknown>

mlae64.m tr0, (a1), a0, m2
# CHECK-INST: mlae64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 04 <unknown>

mlate8.m tr0, (a1), a0, m2
# CHECK-INST: mlate8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 14 <unknown>

mlate16.m tr0, (a1), a0, m2
# CHECK-INST: mlate16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 14 <unknown>

mlate32.m tr0, (a1), a0, m2
# CHECK-INST: mlate32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 14 <unknown>

mlate64.m tr0, (a1), a0, m2
# CHECK-INST: mlate64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 14 <unknown>

mlbe8.m tr0, (a1), a0, m2
# CHECK-INST: mlbe8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 08 <unknown>

mlbe16.m tr0, (a1), a0, m2
# CHECK-INST: mlbe16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 08 <unknown>

mlbe32.m tr0, (a1), a0, m2
# CHECK-INST: mlbe32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 08 <unknown>

mlbe64.m tr0, (a1), a0, m2
# CHECK-INST: mlbe64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 08 <unknown>

mlbte8.m tr0, (a1), a0, m2
# CHECK-INST: mlbte8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 18 <unknown>

mlbte16.m tr0, (a1), a0, m2
# CHECK-INST: mlbte16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 18 <unknown>

mlbte32.m tr0, (a1), a0, m2
# CHECK-INST: mlbte32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 18 <unknown>

mlbte64.m tr0, (a1), a0, m2
# CHECK-INST: mlbte64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 18 <unknown>

mlce8.m tr0, (a1), a0, m2
# CHECK-INST: mlce8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 00 <unknown>

mlce16.m tr0, (a1), a0, m2
# CHECK-INST: mlce16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 00 <unknown>

mlce32.m tr0, (a1), a0, m2
# CHECK-INST: mlce32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 00 <unknown>

mlce64.m tr0, (a1), a0, m2
# CHECK-INST: mlce64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 00 <unknown>

mlcte8.m tr0, (a1), a0, m2
# CHECK-INST: mlcte8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 10 <unknown>

mlcte16.m tr0, (a1), a0, m2
# CHECK-INST: mlcte16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 10 <unknown>

mlcte32.m tr0, (a1), a0, m2
# CHECK-INST: mlcte32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 10 <unknown>

mlcte64.m tr0, (a1), a0, m2
# CHECK-INST: mlcte64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 10 <unknown>

mlre8.m tr1, (a1), a0, m2
# CHECK-INST: mlre8.m tr1, (a1), a0, m2
# CHECK-ENCODING: [0xf7,0x84,0xa5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 84 a5 0c <unknown>

mlre16.m tr1, (a1), a0, m2
# CHECK-INST: mlre16.m tr1, (a1), a0, m2
# CHECK-ENCODING: [0xf7,0x94,0xa5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 94 a5 0c <unknown>

mlre32.m tr1, (a1), a0, m2
# CHECK-INST: mlre32.m tr1, (a1), a0, m2
# CHECK-ENCODING: [0xf7,0xa4,0xa5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a4 a5 0c <unknown>

mlre64.m tr1, (a1), a0, m2
# CHECK-INST: mlre64.m tr1, (a1), a0, m2
# CHECK-ENCODING: [0xf7,0xb4,0xa5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b4 a5 0c <unknown>


mlufae8.m tr1, (a1), a0
# CHECK-INST: mlufae8.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0xc4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 c4 <unknown>

mlufae16.m tr1, (a1), a0
# CHECK-INST: mlufae16.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0xc4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 c4 <unknown>

mlufae32.m tr1, (a1), a0
# CHECK-INST: mlufae32.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0xc4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 c4 <unknown>

mlufae64.m tr1, (a1), a0
# CHECK-INST: mlufae64.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0xc4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 c4 <unknown>

mlufbe8.m tr1, (a1), a0
# CHECK-INST: mlufbe8.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0xc8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 c8 <unknown>

mlufbe16.m tr1, (a1), a0
# CHECK-INST: mlufbe16.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0xc8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 c8 <unknown>

mlufbe32.m tr1, (a1), a0
# CHECK-INST: mlufbe32.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0xc8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 c8 <unknown>

mlufbe64.m tr1, (a1), a0
# CHECK-INST: mlufbe64.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0xc8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 c8 <unknown>

mlufce8.m tr1, (a1), a0
# CHECK-INST: mlufce8.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0xc0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 c0 <unknown>

mlufce16.m tr1, (a1), a0
# CHECK-INST: mlufce16.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0xc0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 c0 <unknown>

mlufce32.m tr1, (a1), a0
# CHECK-INST: mlufce32.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0xc0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 c0 <unknown>

mlufce64.m tr1, (a1), a0
# CHECK-INST: mlufce64.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0xc0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 c0 <unknown>

mlae8.v v1, (a1), a0
# CHECK-INST: mlae8.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 84 <unknown>

mlae16.v v1, (a1), a0
# CHECK-INST: mlae16.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 84 <unknown>

mlae32.v v1, (a1), a0
# CHECK-INST: mlae32.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 84 <unknown>

mlae64.v v1, (a1), a0
# CHECK-INST: mlae64.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0x84]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 84 <unknown>

mlbe8.v v1, (a1), a0
# CHECK-INST: mlbe8.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 88 <unknown>

mlbe16.v v1, (a1), a0
# CHECK-INST: mlbe16.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 88 <unknown>

mlbe32.v v1, (a1), a0
# CHECK-INST: mlbe32.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 88 <unknown>

mlbe64.v v1, (a1), a0
# CHECK-INST: mlbe64.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0x88]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 88 <unknown>

mlce8.v v1, (a1), a0
# CHECK-INST: mlce8.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 80 <unknown>

mlce16.v v1, (a1), a0
# CHECK-INST: mlce16.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 80 <unknown>

mlce32.v v1, (a1), a0
# CHECK-INST: mlce32.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 80 <unknown>

mlce64.v v1, (a1), a0
# CHECK-INST: mlce64.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0x80]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 80 <unknown>