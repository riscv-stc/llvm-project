# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

mmve8.a.t acc0, tr0, a0
# CHECK-INST: mmve8.a.t acc0, tr0, a0
# CHECK-ENCODING: [0x77,0x00,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 a0 10 <unknown>

mmve16.a.t acc0, tr0, a0
# CHECK-INST: mmve16.a.t acc0, tr0, a0
# CHECK-ENCODING: [0x77,0x10,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 a0 10 <unknown>

mmve32.a.t acc0, tr0, a0
# CHECK-INST: mmve32.a.t acc0, tr0, a0
# CHECK-ENCODING: [0x77,0x20,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 a0 10 <unknown>

mmve64.a.t acc0, tr0, a0
# CHECK-INST: mmve64.a.t acc0, tr0, a0
# CHECK-ENCODING: [0x77,0x30,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 a0 10 <unknown>

mmve8.t.a tr0, acc0, a0
# CHECK-INST: mmve8.t.a tr0, acc0, a0
# CHECK-ENCODING: [0x77,0x00,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 a0 12 <unknown>

mmve16.t.a tr0, acc0, a0
# CHECK-INST: mmve16.t.a tr0, acc0, a0
# CHECK-ENCODING: [0x77,0x10,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 a0 12 <unknown>

mmve32.t.a tr0, acc0, a0
# CHECK-INST: mmve32.t.a tr0, acc0, a0
# CHECK-ENCODING: [0x77,0x20,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 a0 12 <unknown>

mmve64.t.a tr0, acc0, a0
# CHECK-INST: mmve64.t.a tr0, acc0, a0
# CHECK-ENCODING: [0x77,0x30,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 a0 12 <unknown>

mmvie8.a.t acc0, tr0, 10
# CHECK-INST: mmvie8.a.t acc0, tr0, 10
# CHECK-ENCODING: [0x77,0x40,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a0 10 <unknown>

mmvie16.a.t acc0, tr0, 10
# CHECK-INST: mmvie16.a.t acc0, tr0, 10
# CHECK-ENCODING: [0x77,0x50,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a0 10 <unknown>

mmvie32.a.t acc0, tr0, 10
# CHECK-INST: mmvie32.a.t acc0, tr0, 10
# CHECK-ENCODING: [0x77,0x60,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a0 10 <unknown>

mmvie64.a.t acc0, tr0, 10
# CHECK-INST: mmvie64.a.t acc0, tr0, 10
# CHECK-ENCODING: [0x77,0x70,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a0 10 <unknown>

mmvie8.t.a tr0, acc0, 10
# CHECK-INST: mmvie8.t.a tr0, acc0, 10
# CHECK-ENCODING: [0x77,0x40,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a0 12 <unknown>

mmvie16.t.a tr0, acc0, 10
# CHECK-INST: mmvie16.t.a tr0, acc0, 10
# CHECK-ENCODING: [0x77,0x50,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a0 12 <unknown>

mmvie32.t.a tr0, acc0, 10
# CHECK-INST: mmvie32.t.a tr0, acc0, 10
# CHECK-ENCODING: [0x77,0x60,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a0 12 <unknown>

mmvie64.t.a tr0, acc0, 10
# CHECK-INST: mmvie64.t.a tr0, acc0, 10
# CHECK-ENCODING: [0x77,0x70,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a0 12 <unknown>

mmve8.x.t a0, tr0, a1
# CHECK-INST: mmve8.x.t a0, tr0, a1
# CHECK-ENCODING: [0x77,0x05,0xb0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 05 b0 14 <unknown>

mmve16.x.t a0, tr0, a1
# CHECK-INST: mmve16.x.t a0, tr0, a1
# CHECK-ENCODING: [0x77,0x15,0xb0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 15 b0 14 <unknown>

mmve32.x.t a0, tr0, a1
# CHECK-INST: mmve32.x.t a0, tr0, a1
# CHECK-ENCODING: [0x77,0x25,0xb0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 25 b0 14 <unknown>

mmve64.x.t a0, tr0, a1
# CHECK-INST: mmve64.x.t a0, tr0, a1
# CHECK-ENCODING: [0x77,0x35,0xb0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 35 b0 14 <unknown>

mmve8.t.x tr0, a0, a1
# CHECK-INST: mmve8.t.x tr0, a0, a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 16 <unknown>

mmve16.t.x tr0, a0, a1
# CHECK-INST: mmve16.t.x tr0, a0, a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 16 <unknown>

mmve32.t.x tr0, a0, a1
# CHECK-INST: mmve32.t.x tr0, a0, a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 16 <unknown>

mmve64.t.x tr0, a0, a1
# CHECK-INST: mmve64.t.x tr0, a0, a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 16 <unknown>

mmve8.x.a a0, acc0, a1
# CHECK-INST: mmve8.x.a a0, acc0, a1
# CHECK-ENCODING: [0x77,0x45,0xb0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 45 b0 14 <unknown>

mmve16.x.a a0, acc0, a1
# CHECK-INST: mmve16.x.a a0, acc0, a1
# CHECK-ENCODING: [0x77,0x55,0xb0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 55 b0 14 <unknown>

mmve32.x.a a0, acc0, a1
# CHECK-INST: mmve32.x.a a0, acc0, a1
# CHECK-ENCODING: [0x77,0x65,0xb0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 65 b0 14 <unknown>

mmve64.x.a a0, acc0, a1
# CHECK-INST: mmve64.x.a a0, acc0, a1
# CHECK-ENCODING: [0x77,0x75,0xb0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 75 b0 14 <unknown>

mmve8.a.x acc0, a0, a1
# CHECK-INST: mmve8.a.x acc0, a0, a1
# CHECK-ENCODING: [0x77,0x40,0xb5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 b5 16 <unknown>

mmve16.a.x acc0, a0, a1
# CHECK-INST: mmve16.a.x acc0, a0, a1
# CHECK-ENCODING: [0x77,0x50,0xb5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 b5 16 <unknown>

mmve32.a.x acc0, a0, a1
# CHECK-INST: mmve32.a.x acc0, a0, a1
# CHECK-ENCODING: [0x77,0x60,0xb5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 b5 16 <unknown>

mmve64.a.x acc0, a0, a1
# CHECK-INST: mmve64.a.x acc0, a0, a1
# CHECK-ENCODING: [0x77,0x70,0xb5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 b5 16 <unknown>

mfmve8.f.t fa0, tr0, a0
# CHECK-INST: mfmve8.f.t fa0, tr0, a0
# CHECK-ENCODING: [0x77,0x05,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 05 a0 18 <unknown>

mfmve16.f.t fa0, tr0, a0
# CHECK-INST: mfmve16.f.t fa0, tr0, a0
# CHECK-ENCODING: [0x77,0x15,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 15 a0 18 <unknown>

mfmve32.f.t fa0, tr0, a0
# CHECK-INST: mfmve32.f.t fa0, tr0, a0
# CHECK-ENCODING: [0x77,0x25,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 25 a0 18 <unknown>

mfmve64.f.t fa0, tr0, a0
# CHECK-INST: mfmve64.f.t fa0, tr0, a0
# CHECK-ENCODING: [0x77,0x35,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 35 a0 18 <unknown>

mfmve8.t.f tr0, fa0, a0
# CHECK-INST: mfmve8.t.f tr0, fa0, a0
# CHECK-ENCODING: [0x77,0x00,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 a5 1a <unknown>

mfmve16.t.f tr0, fa0, a0
# CHECK-INST: mfmve16.t.f tr0, fa0, a0
# CHECK-ENCODING: [0x77,0x10,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 a5 1a <unknown>

mfmve32.t.f tr0, fa0, a0
# CHECK-INST: mfmve32.t.f tr0, fa0, a0
# CHECK-ENCODING: [0x77,0x20,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 a5 1a <unknown>

mfmve64.t.f tr0, fa0, a0
# CHECK-INST: mfmve64.t.f tr0, fa0, a0
# CHECK-ENCODING: [0x77,0x30,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 a5 1a <unknown>

mfmve8.f.a fa0, acc0, a0
# CHECK-INST: mfmve8.f.a fa0, acc0, a0
# CHECK-ENCODING: [0x77,0x45,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 45 a0 18 <unknown>

mfmve16.f.a fa0, acc0, a0
# CHECK-INST: mfmve16.f.a fa0, acc0, a0
# CHECK-ENCODING: [0x77,0x55,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 55 a0 18 <unknown>

mfmve32.f.a fa0, acc0, a0
# CHECK-INST: mfmve32.f.a fa0, acc0, a0
# CHECK-ENCODING: [0x77,0x65,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 65 a0 18 <unknown>

mfmve64.f.a fa0, acc0, a0
# CHECK-INST: mfmve64.f.a fa0, acc0, a0
# CHECK-ENCODING: [0x77,0x75,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 75 a0 18 <unknown>

mfmve8.a.f acc0, fa0, a0
# CHECK-INST: mfmve8.a.f acc0, fa0, a0
# CHECK-ENCODING: [0x77,0x40,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a5 1a <unknown>

mfmve16.a.f acc0, fa0, a0
# CHECK-INST: mfmve16.a.f acc0, fa0, a0
# CHECK-ENCODING: [0x77,0x50,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a5 1a <unknown>

mfmve32.a.f acc0, fa0, a0
# CHECK-INST: mfmve32.a.f acc0, fa0, a0
# CHECK-ENCODING: [0x77,0x60,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a5 1a <unknown>
mfmve64.a.f acc0, fa0, a0
# CHECK-INST: mfmve64.a.f acc0, fa0, a0
# CHECK-ENCODING: [0x77,0x70,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a5 1a <unknown>

mmve8.t.t tr0, tr1
# CHECK-INST: mmve8.t.t tr0, tr1
# CHECK-ENCODING: [0x77,0x80,0x00,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 00 1c <unknown>

mmve16.t.t tr0, tr1
# CHECK-INST: mmve16.t.t tr0, tr1
# CHECK-ENCODING: [0x77,0x90,0x00,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 00 1c <unknown>
mmve32.t.t tr0, tr1
# CHECK-INST: mmve32.t.t tr0, tr1
# CHECK-ENCODING: [0x77,0xa0,0x00,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 00 1c <unknown>

mmve64.t.t tr0, tr1
# CHECK-INST: mmve64.t.t tr0, tr1
# CHECK-ENCODING: [0x77,0xb0,0x00,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 00 1c <unknown>

mmve8.a.a acc0, acc1
# CHECK-INST: mmve8.a.a acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x10,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 10 1c <unknown>

mmve16.a.a acc0, acc1
# CHECK-INST: mmve16.a.a acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x10,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 10 1c <unknown>

mmve32.a.a acc0, acc1
# CHECK-INST: mmve32.a.a acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x10,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 10 1c <unknown>

mmve64.a.a acc0, acc1
# CHECK-INST: mmve64.a.a acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x10,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 10 1c <unknown>

mbcar.m tr0, tr1
# CHECK-INST: mbcar.m tr0, tr1
# CHECK-ENCODING: [0x77,0x80,0x10,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 10 1d <unknown>

mbcbr.m tr0, tr1
# CHECK-INST: mbcbr.m tr0, tr1
# CHECK-ENCODING: [0x77,0x80,0x20,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 1d <unknown>

mbccr.m acc0, acc1
# CHECK-INST: mbccr.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x00,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 00 1d <unknown>

mbcace8.m tr0, tr1
# CHECK-INST: mbcace8.m tr0, tr1
# CHECK-ENCODING: [0x77,0x80,0x50,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 50 1d <unknown>

mbcace16.m tr0, tr1
# CHECK-INST: mbcace16.m tr0, tr1
# CHECK-ENCODING: [0x77,0x90,0x50,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 50 1d <unknown>

mbcace32.m tr0, tr1
# CHECK-INST: mbcace32.m tr0, tr1
# CHECK-ENCODING: [0x77,0xa0,0x50,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 50 1d <unknown>

mbcace64.m tr0, tr1
# CHECK-INST: mbcace64.m tr0, tr1
# CHECK-ENCODING: [0x77,0xb0,0x50,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 50 1d <unknown>

mbcbce8.m tr0, tr1
# CHECK-INST: mbcbce8.m tr0, tr1
# CHECK-ENCODING: [0x77,0x80,0x60,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 60 1d <unknown>

mbcbce16.m tr0, tr1
# CHECK-INST: mbcbce16.m tr0, tr1
# CHECK-ENCODING: [0x77,0x90,0x60,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 60 1d <unknown>

mbcbce32.m tr0, tr1
# CHECK-INST: mbcbce32.m tr0, tr1
# CHECK-ENCODING: [0x77,0xa0,0x60,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 60 1d <unknown>

mbcbce64.m tr0, tr1
# CHECK-INST: mbcbce64.m tr0, tr1
# CHECK-ENCODING: [0x77,0xb0,0x60,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 60 1d <unknown>

mbccce8.m acc0, acc1
# CHECK-INST: mbccce8.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x40,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 40 1d <unknown>

mbccce16.m acc0, acc1
# CHECK-INST: mbccce16.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x40,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 40 1d <unknown>

mbccce32.m acc0, acc1
# CHECK-INST: mbccce32.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x40,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 40 1d <unknown>

mbccce64.m acc0, acc1
# CHECK-INST: mbccce64.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x40,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 40 1d <unknown>

mtae8.m tr0, tr1
# CHECK-INST: mtae8.m tr0, tr1
# CHECK-ENCODING: [0x77,0x80,0xd0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 d0 1d <unknown>

mtae16.m tr0, tr1
# CHECK-INST: mtae16.m tr0, tr1
# CHECK-ENCODING: [0x77,0x90,0xd0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 d0 1d <unknown>

mtae32.m tr0, tr1
# CHECK-INST: mtae32.m tr0, tr1
# CHECK-ENCODING: [0x77,0xa0,0xd0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 d0 1d <unknown>

mtae64.m tr0, tr1
# CHECK-INST: mtae64.m tr0, tr1
# CHECK-ENCODING: [0x77,0xb0,0xd0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 d0 1d <unknown>

mtbe8.m tr0, tr1
# CHECK-INST: mtbe8.m tr0, tr1
# CHECK-ENCODING: [0x77,0x80,0xe0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 e0 1d <unknown>

mtbe16.m tr0, tr1
# CHECK-INST: mtbe16.m tr0, tr1
# CHECK-ENCODING: [0x77,0x90,0xe0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 e0 1d <unknown>

mtbe32.m tr0, tr1
# CHECK-INST: mtbe32.m tr0, tr1
# CHECK-ENCODING: [0x77,0xa0,0xe0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 e0 1d <unknown>

mtbe64.m tr0, tr1
# CHECK-INST: mtbe64.m tr0, tr1
# CHECK-ENCODING: [0x77,0xb0,0xe0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 e0 1d <unknown>

mtce8.m acc0, acc1
# CHECK-INST: mtce8.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0xc0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 c0 1d <unknown>

mtce16.m acc0, acc1
# CHECK-INST: mtce16.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0xc0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 c0 1d <unknown>

mtce32.m acc0, acc1
# CHECK-INST: mtce32.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xc0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 c0 1d <unknown>

mtce64.m acc0, acc1
# CHECK-INST: mtce64.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0xc0,0x1d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 c0 1d <unknown>

mmvare8.v.m v0, tr0, a0
# CHECK-INST: mmvare8.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x40,0xa0,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a0 98 <unknown>

mmvare16.v.m v0, tr0, a0
# CHECK-INST: mmvare16.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x50,0xa0,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a0 98 <unknown>

mmvare32.v.m v0, tr0, a0
# CHECK-INST: mmvare32.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x60,0xa0,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a0 98 <unknown>

mmvare64.v.m v0, tr0, a0
# CHECK-INST: mmvare64.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x70,0xa0,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a0 98 <unknown>

mmvbre8.v.m v0, tr0, a0
# CHECK-INST: mmvbre8.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x40,0xa8,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a8 98 <unknown>

mmvbre16.v.m v0, tr0, a0
# CHECK-INST: mmvbre16.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x50,0xa8,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a8 98 <unknown>

mmvbre32.v.m v0, tr0, a0
# CHECK-INST: mmvbre32.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x60,0xa8,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a8 98 <unknown>

mmvbre64.v.m v0, tr0, a0
# CHECK-INST: mmvbre64.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x70,0xa8,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a8 98 <unknown>

mmvcre8.v.m v0, acc0, a0
# CHECK-INST: mmvcre8.v.m v0, acc0, a0
# CHECK-ENCODING: [0x77,0x00,0xa0,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 a0 98 <unknown>

mmvcre16.v.m v0, acc0, a0
# CHECK-INST: mmvcre16.v.m v0, acc0, a0
# CHECK-ENCODING: [0x77,0x10,0xa0,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 a0 98 <unknown>

mmvcre32.v.m v0, acc0, a0
# CHECK-INST: mmvcre32.v.m v0, acc0, a0
# CHECK-ENCODING: [0x77,0x20,0xa0,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 a0 98 <unknown>

mmvcre64.v.m v0, acc0, a0
# CHECK-INST: mmvcre64.v.m v0, acc0, a0
# CHECK-ENCODING: [0x77,0x30,0xa0,0x98]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 a0 98 <unknown>

mmvare8.m.v tr0, v0, a0
# CHECK-INST: mmvare8.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x40,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a0 9a <unknown>

mmvare16.m.v tr0, v0, a0
# CHECK-INST: mmvare16.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x50,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a0 9a <unknown>

mmvare32.m.v tr0, v0, a0
# CHECK-INST: mmvare32.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x60,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a0 9a <unknown>

mmvare64.m.v tr0, v0, a0
# CHECK-INST: mmvare64.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x70,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a0 9a <unknown>

mmvbre8.m.v tr0, v0, a0
# CHECK-INST: mmvbre8.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x48,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 a0 9a <unknown>

mmvbre16.m.v tr0, v0, a0
# CHECK-INST: mmvbre16.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x58,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 58 a0 9a <unknown>

mmvbre32.m.v tr0, v0, a0
# CHECK-INST: mmvbre32.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x68,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 68 a0 9a <unknown>

mmvbre64.m.v tr0, v0, a0
# CHECK-INST: mmvbre64.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x78,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 a0 9a <unknown>

mmvcre8.m.v acc0, v0, a0
# CHECK-INST: mmvcre8.m.v acc0, v0, a0
# CHECK-ENCODING: [0x77,0x00,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 a0 9a <unknown>

mmvcre16.m.v acc0, v0, a0
# CHECK-INST: mmvcre16.m.v acc0, v0, a0
# CHECK-ENCODING: [0x77,0x10,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 a0 9a <unknown>

mmvcre32.m.v acc0, v0, a0
# CHECK-INST: mmvcre32.m.v acc0, v0, a0
# CHECK-ENCODING: [0x77,0x20,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 a0 9a <unknown>

mmvcre64.m.v acc0, v0, a0
# CHECK-INST: mmvcre64.m.v acc0, v0, a0
# CHECK-ENCODING: [0x77,0x30,0xa0,0x9a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 a0 9a <unknown>

mmvace8.v.m v0, tr0, a0
# CHECK-INST: mmvace8.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x40,0xa0,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a0 9c <unknown>

mmvace16.v.m v0, tr0, a0
# CHECK-INST: mmvace16.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x50,0xa0,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a0 9c <unknown>

mmvace32.v.m v0, tr0, a0
# CHECK-INST: mmvace32.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x60,0xa0,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a0 9c <unknown>

mmvace64.v.m v0, tr0, a0
# CHECK-INST: mmvace64.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x70,0xa0,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a0 9c <unknown>

mmvbce8.v.m v0, tr0, a0
# CHECK-INST: mmvbce8.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x40,0xa8,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a8 9c <unknown>

mmvbce16.v.m v0, tr0, a0
# CHECK-INST: mmvbce16.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x50,0xa8,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a8 9c <unknown>

mmvbce32.v.m v0, tr0, a0
# CHECK-INST: mmvbce32.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x60,0xa8,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a8 9c <unknown>

mmvbce64.v.m v0, tr0, a0
# CHECK-INST: mmvbce64.v.m v0, tr0, a0
# CHECK-ENCODING: [0x77,0x70,0xa8,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a8 9c <unknown>

mmvcce8.v.m v0, acc0, a0
# CHECK-INST: mmvcce8.v.m v0, acc0, a0
# CHECK-ENCODING: [0x77,0x00,0xa0,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 a0 9c <unknown>

mmvcce16.v.m v0, acc0, a0
# CHECK-INST: mmvcce16.v.m v0, acc0, a0
# CHECK-ENCODING: [0x77,0x10,0xa0,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 a0 9c <unknown>

mmvcce32.v.m v0, acc0, a0
# CHECK-INST: mmvcce32.v.m v0, acc0, a0
# CHECK-ENCODING: [0x77,0x20,0xa0,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 a0 9c <unknown>

mmvcce64.v.m v0, acc0, a0
# CHECK-INST: mmvcce64.v.m v0, acc0, a0
# CHECK-ENCODING: [0x77,0x30,0xa0,0x9c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 a0 9c <unknown>

mmvace8.m.v tr0, v0, a0
# CHECK-INST: mmvace8.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x40,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 a0 9e <unknown>

mmvace16.m.v tr0, v0, a0
# CHECK-INST: mmvace16.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x50,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 a0 9e <unknown>

mmvace32.m.v tr0, v0, a0
# CHECK-INST: mmvace32.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x60,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 a0 9e <unknown>

mmvace64.m.v tr0, v0, a0
# CHECK-INST: mmvace64.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x70,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 a0 9e <unknown>

mmvbce8.m.v tr0, v0, a0
# CHECK-INST: mmvbce8.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x48,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 a0 9e <unknown>

mmvbce16.m.v tr0, v0, a0
# CHECK-INST: mmvbce16.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x58,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 58 a0 9e <unknown>

mmvbce32.m.v tr0, v0, a0
# CHECK-INST: mmvbce32.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x68,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 68 a0 9e <unknown>

mmvbce64.m.v tr0, v0, a0
# CHECK-INST: mmvbce64.m.v tr0, v0, a0
# CHECK-ENCODING: [0x77,0x78,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 a0 9e <unknown>

mmvcce8.m.v acc0, v0, a0
# CHECK-INST: mmvcce8.m.v acc0, v0, a0
# CHECK-ENCODING: [0x77,0x00,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 a0 9e <unknown>

mmvcce16.m.v acc0, v0, a0
# CHECK-INST: mmvcce16.m.v acc0, v0, a0
# CHECK-ENCODING: [0x77,0x10,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 a0 9e <unknown>

mmvcce32.m.v acc0, v0, a0
# CHECK-INST: mmvcce32.m.v acc0, v0, a0
# CHECK-ENCODING: [0x77,0x20,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 a0 9e <unknown>

mmvcce64.m.v acc0, v0, a0
# CHECK-INST: mmvcce64.m.v acc0, v0, a0
# CHECK-ENCODING: [0x77,0x30,0xa0,0x9e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 a0 9e <unknown>