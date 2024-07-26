# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

mmvar.v.m v0, tr1, a0
# CHECK-INST: mmvar.v.m v0, tr1, a0
# CHECK-ENCODING: [0x77,0xd0,0xa0,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 a0 14 <unknown>

mmvar.m.v tr1, v0, a0
# CHECK-INST: mmvar.m.v tr1, v0, a0
# CHECK-ENCODING: [0xf7,0x50,0xa0,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 a0 16 <unknown>

mmvbr.v.m v0, tr1, a0
# CHECK-INST: mmvbr.v.m v0, tr1, a0
# CHECK-ENCODING: [0x77,0xd0,0xa0,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 a0 18 <unknown>

mmvbr.m.v tr1, v0, a0
# CHECK-INST: mmvbr.m.v tr1, v0, a0
# CHECK-ENCODING: [0xf7,0x50,0xa0,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 a0 1a <unknown>

mmvcr.v.m v0, tr1, a0
# CHECK-INST: mmvcr.v.m v0, tr1, a0
# CHECK-ENCODING: [0x77,0xd0,0xa0,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 a0 10 <unknown>

mmvcr.m.v tr1, v0, a0
# CHECK-INST: mmvcr.m.v tr1, v0, a0
# CHECK-ENCODING: [0xf7,0x50,0xa0,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 a0 12 <unknown>

mmvac.v.m v0, tr1, a0
# CHECK-INST: mmvac.v.m v0, tr1, a0
# CHECK-ENCODING: [0x77,0xd0,0xa0,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 a0 24 <unknown>

mmvac.m.v tr1, v0, a0
# CHECK-INST: mmvac.m.v tr1, v0, a0
# CHECK-ENCODING: [0xf7,0x50,0xa0,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 a0 26 <unknown>

mmvbc.v.m v0, tr1, a0
# CHECK-INST: mmvbc.v.m v0, tr1, a0
# CHECK-ENCODING: [0x77,0xd0,0xa0,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 a0 28 <unknown>

mmvbc.m.v tr1, v0, a0
# CHECK-INST: mmvbc.m.v tr1, v0, a0
# CHECK-ENCODING: [0xf7,0x50,0xa0,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 a0 2a <unknown>

mmvcc.v.m v0, tr1, a0
# CHECK-INST: mmvcc.v.m v0, tr1, a0
# CHECK-ENCODING: [0x77,0xd0,0xa0,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 a0 20 <unknown>

mmvcc.m.v tr1, v0, a0
# CHECK-INST: mmvcc.m.v tr1, v0, a0
# CHECK-ENCODING: [0xf7,0x50,0xa0,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 a0 22 <unknown>

mmv.x.s a1, tr1, a0
# CHECK-INST: mmv.x.s a1, tr1, a0
# CHECK-ENCODING: [0xf7,0xd5,0xa0,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 d5 a0 00 <unknown>

mmv.s.x tr1, a1, a0
# CHECK-INST: mmv.s.x tr1, a1, a0
# CHECK-ENCODING: [0xf7,0xd0,0xa5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 d0 a5 02 <unknown>

mfmv.f.s fa1, tr1, a0
# CHECK-INST: mfmv.f.s fa1, tr1, a0
# CHECK-ENCODING: [0xf7,0xd5,0xa0,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 d5 a0 04 <unknown>

mfmv.s.f tr1, fa1, a0
# CHECK-INST: mfmv.s.f tr1, fa1, a0
# CHECK-ENCODING: [0xf7,0xd0,0xa5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 d0 a5 06 <unknown>

mbcar.m tr0, tr1
# CHECK-INST: mbcar.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0x10,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 10 08 <unknown>

mbcbr.m tr0, tr1
# CHECK-INST: mbcbr.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0x20,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 20 08 <unknown>

mbccr.m tr0, tr1
# CHECK-INST: mbccr.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0x00,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 00 08 <unknown>

mbcac.m tr0, tr1
# CHECK-INST: mbcac.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0x50,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 50 08 <unknown>

mbcbc.m tr0, tr1
# CHECK-INST: mbcbc.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0x60,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 60 08 <unknown>

mbccc.m tr0, tr1
# CHECK-INST: mbccc.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0x40,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 40 08 <unknown>

mbcae.m tr0, tr1
# CHECK-INST: mbcae.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0x90,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 90 08 <unknown>

mbcbe.m tr0, tr1
# CHECK-INST: mbcbe.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0xa0,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 a0 08 <unknown>

mbcce.m tr0, tr1
# CHECK-INST: mbcce.m tr0, tr1
# CHECK-ENCODING: [0x77,0xd0,0x80,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d0 80 08 <unknown>