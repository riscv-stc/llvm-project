# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

maddu.mm acc0, acc1, acc2
# CHECK-INST: maddu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 20 <unknown>

maddu.b.mm acc0, acc1, acc2
# CHECK-INST: maddu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 20 <unknown>

maddu.h.mm acc0, acc1, acc2
# CHECK-INST: maddu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 20 <unknown>

maddu.w.mm acc0, acc1, acc2
# CHECK-INST: maddu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 20 <unknown>

maddu.dw.mm acc0, acc1, acc2
# CHECK-INST: maddu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 20 <unknown>

maddu.hb.mm acc0, acc1, acc2
# CHECK-INST: maddu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 20 <unknown>

msaddu.mm acc0, acc1, acc2
# CHECK-INST: msaddu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 21 <unknown>

msaddu.b.mm acc0, acc1, acc2
# CHECK-INST: msaddu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 21 <unknown>

msaddu.h.mm acc0, acc1, acc2
# CHECK-INST: msaddu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 21 <unknown>

msaddu.w.mm acc0, acc1, acc2
# CHECK-INST: msaddu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 21 <unknown>

msaddu.dw.mm acc0, acc1, acc2
# CHECK-INST: msaddu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 21 <unknown>

msaddu.hb.mm acc0, acc1, acc2
# CHECK-INST: msaddu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 21 <unknown>

madd.mm acc0, acc1, acc2
# CHECK-INST: madd.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 20 <unknown>

madd.b.mm acc0, acc1, acc2
# CHECK-INST: madd.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 20 <unknown>

madd.h.mm acc0, acc1, acc2
# CHECK-INST: madd.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 20 <unknown>

madd.w.mm acc0, acc1, acc2
# CHECK-INST: madd.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 20 <unknown>

madd.dw.mm acc0, acc1, acc2
# CHECK-INST: madd.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 20 <unknown>

madd.hb.mm acc0, acc1, acc2
# CHECK-INST: madd.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 20 <unknown>

msadd.mm acc0, acc1, acc2
# CHECK-INST: msadd.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 21 <unknown>

msadd.b.mm acc0, acc1, acc2
# CHECK-INST: msadd.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 21 <unknown>

msadd.h.mm acc0, acc1, acc2
# CHECK-INST: msadd.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 21 <unknown>

msadd.w.mm acc0, acc1, acc2
# CHECK-INST: msadd.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 21 <unknown>

msadd.dw.mm acc0, acc1, acc2
# CHECK-INST: msadd.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 21 <unknown>

msadd.hb.mm acc0, acc1, acc2
# CHECK-INST: msadd.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 21 <unknown>

mfadd.mm acc0, acc1, acc2
# CHECK-INST: mfadd.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 22 <unknown>

mfadd.cf.mm acc0, acc1, acc2
# CHECK-INST: mfadd.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 22 <unknown>

mfadd.hf.mm acc0, acc1, acc2
# CHECK-INST: mfadd.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 22 <unknown>

mfadd.f.mm acc0, acc1, acc2
# CHECK-INST: mfadd.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 22 <unknown>

mfadd.d.mm acc0, acc1, acc2
# CHECK-INST: mfadd.d.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 22 <unknown>

mwaddu.mm acc0, acc1, acc2
# CHECK-INST: mwaddu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 24 <unknown>

mwaddu.b.mm acc0, acc1, acc2
# CHECK-INST: mwaddu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 24 <unknown>

mwaddu.h.mm acc0, acc1, acc2
# CHECK-INST: mwaddu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 24 <unknown>

mwaddu.w.mm acc0, acc1, acc2
# CHECK-INST: mwaddu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 24 <unknown>

mwaddu.hb.mm acc0, acc1, acc2
# CHECK-INST: mwaddu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 24 <unknown>

mwadd.mm acc0, acc1, acc2
# CHECK-INST: mwadd.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 24 <unknown>

mwadd.b.mm acc0, acc1, acc2
# CHECK-INST: mwadd.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 24 <unknown>

mwadd.h.mm acc0, acc1, acc2
# CHECK-INST: mwadd.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 24 <unknown>

mwadd.w.mm acc0, acc1, acc2
# CHECK-INST: mwadd.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 24 <unknown>

mwadd.hb.mm acc0, acc1, acc2
# CHECK-INST: mwadd.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 24 <unknown>

mfwadd.mm acc0, acc1, acc2
# CHECK-INST: mfwadd.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 26 <unknown>

mfwadd.cf.mm acc0, acc1, acc2
# CHECK-INST: mfwadd.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 26 <unknown>

mfwadd.hf.mm acc0, acc1, acc2
# CHECK-INST: mfwadd.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 26 <unknown>

mfwadd.f.mm acc0, acc1, acc2
# CHECK-INST: mfwadd.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 26 <unknown>

msubu.mm acc0, acc1, acc2
# CHECK-INST: msubu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 28 <unknown>

msubu.b.mm acc0, acc1, acc2
# CHECK-INST: msubu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 28 <unknown>

msubu.h.mm acc0, acc1, acc2
# CHECK-INST: msubu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 28 <unknown>

msubu.w.mm acc0, acc1, acc2
# CHECK-INST: msubu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 28 <unknown>

msubu.dw.mm acc0, acc1, acc2
# CHECK-INST: msubu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 28 <unknown>

msubu.hb.mm acc0, acc1, acc2
# CHECK-INST: msubu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 28 <unknown>

mssubu.mm acc0, acc1, acc2
# CHECK-INST: mssubu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 29 <unknown>

mssubu.b.mm acc0, acc1, acc2
# CHECK-INST: mssubu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 29 <unknown>

mssubu.h.mm acc0, acc1, acc2
# CHECK-INST: mssubu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 29 <unknown>

mssubu.w.mm acc0, acc1, acc2
# CHECK-INST: mssubu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 29 <unknown>

mssubu.dw.mm acc0, acc1, acc2
# CHECK-INST: mssubu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 29 <unknown>

mssubu.hb.mm acc0, acc1, acc2
# CHECK-INST: mssubu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 29 <unknown>

msub.mm acc0, acc1, acc2
# CHECK-INST: msub.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 28 <unknown>

msub.b.mm acc0, acc1, acc2
# CHECK-INST: msub.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 28 <unknown>

msub.h.mm acc0, acc1, acc2
# CHECK-INST: msub.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 28 <unknown>

msub.w.mm acc0, acc1, acc2
# CHECK-INST: msub.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 28 <unknown>

msub.dw.mm acc0, acc1, acc2
# CHECK-INST: msub.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 28 <unknown>

msub.hb.mm acc0, acc1, acc2
# CHECK-INST: msub.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 28 <unknown>

mfsub.mm acc0, acc1, acc2
# CHECK-INST: mfsub.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 2a <unknown>

mfsub.cf.mm acc0, acc1, acc2
# CHECK-INST: mfsub.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 2a <unknown>

mfsub.hf.mm acc0, acc1, acc2
# CHECK-INST: mfsub.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 2a <unknown

mfsub.f.mm acc0, acc1, acc2
# CHECK-INST: mfsub.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 2a <unknown>

mfsub.d.mm acc0, acc1, acc2
# CHECK-INST: mfsub.d.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 2a <unknown>

mwsubu.mm acc0, acc1, acc2
# CHECK-INST: mwsubu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 2c <unknown>

mwsubu.b.mm acc0, acc1, acc2
# CHECK-INST: mwsubu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 2c <unknown>

mwsubu.h.mm acc0, acc1, acc2
# CHECK-INST: mwsubu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 2c <unknown>

mwsubu.w.mm acc0, acc1, acc2
# CHECK-INST: mwsubu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 2c <unknown>

mwsubu.hb.mm acc0, acc1, acc2
# CHECK-INST: mwsubu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 2c <unknown>

mwsub.mm acc0, acc1, acc2
# CHECK-INST: mwsub.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 2c <unknown>

mwsub.b.mm acc0, acc1, acc2
# CHECK-INST: mwsub.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 2c <unknown>

mwsub.h.mm acc0, acc1, acc2
# CHECK-INST: mwsub.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 2c <unknown>

mwsub.w.mm acc0, acc1, acc2
# CHECK-INST: mwsub.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 2c <unknown>

mwsub.hb.mm acc0, acc1, acc2
# CHECK-INST: mwsub.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 2c <unknown>

mfwsub.mm acc0, acc1, acc2
# CHECK-INST: mfwsub.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x2e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 2e <unknown>

mfwsub.cf.mm acc0, acc1, acc2
# CHECK-INST: mfwsub.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x2e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 2e <unknown>

mfwsub.hf.mm acc0, acc1, acc2
# CHECK-INST: mfwsub.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x2e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 2e <unknown>

mfwsub.f.mm acc0, acc1, acc2
# CHECK-INST: mfwsub.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x2e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 2e <unknown>

mminu.mm acc0, acc1, acc2
# CHECK-INST: mminu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 30 <unknown>

mminu.b.mm acc0, acc1, acc2
# CHECK-INST: mminu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 30 <unknown>

mminu.h.mm acc0, acc1, acc2
# CHECK-INST: mminu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 30 <unknown>

mminu.w.mm acc0, acc1, acc2
# CHECK-INST: mminu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 30 <unknown>

mminu.dw.mm acc0, acc1, acc2
# CHECK-INST: mminu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 30 <unknown>

mminu.hb.mm acc0, acc1, acc2
# CHECK-INST: mminu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 30 <unknown>

mmaxu.mm acc0, acc1, acc2
# CHECK-INST: mmaxu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 31 <unknown>

mmaxu.b.mm acc0, acc1, acc2
# CHECK-INST: mmaxu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 31 <unknown>

mmaxu.h.mm acc0, acc1, acc2
# CHECK-INST: mmaxu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 31 <unknown>

mmaxu.w.mm acc0, acc1, acc2
# CHECK-INST: mmaxu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 31 <unknown>

mmaxu.dw.mm acc0, acc1, acc2
# CHECK-INST: mmaxu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 31 <unknown>

mmaxu.hb.mm acc0, acc1, acc2
# CHECK-INST: mmaxu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 31 <unknown>

mmin.mm acc0, acc1, acc2
# CHECK-INST: mmin.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 30 <unknown>

mmin.b.mm acc0, acc1, acc2
# CHECK-INST: mmin.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 30 <unknown>

mmin.h.mm acc0, acc1, acc2
# CHECK-INST: mmin.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 30 <unknown>

mmin.w.mm acc0, acc1, acc2
# CHECK-INST: mmin.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 30 <unknown>

mmin.dw.mm acc0, acc1, acc2
# CHECK-INST: mmin.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 30 <unknown>

mmin.hb.mm acc0, acc1, acc2
# CHECK-INST: mmin.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 30 <unknown>

mmax.mm acc0, acc1, acc2
# CHECK-INST: mmax.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 31 <unknown>

mmax.b.mm acc0, acc1, acc2
# CHECK-INST: mmax.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 31 <unknown>

mmax.h.mm acc0, acc1, acc2
# CHECK-INST: mmax.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 31 <unknown>

mmax.w.mm acc0, acc1, acc2
# CHECK-INST: mmax.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 31 <unknown>

mmax.dw.mm acc0, acc1, acc2
# CHECK-INST: mmax.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 31 <unknown>

mmax.hb.mm acc0, acc1, acc2
# CHECK-INST: mmax.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x31]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 31 <unknown>

mfmin.mm acc0, acc1, acc2
# CHECK-INST: mfmin.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x32]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 32 <unknown>

mfmin.cf.mm acc0, acc1, acc2
# CHECK-INST: mfmin.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x32]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 32 <unknown>

mfmin.hf.mm acc0, acc1, acc2
# CHECK-INST: mfmin.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x32]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 32 <unknown>

mfmin.f.mm acc0, acc1, acc2
# CHECK-INST: mfmin.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x32]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 32 <unknown>

mfmin.d.mm acc0, acc1, acc2
# CHECK-INST: mfmin.d.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x32]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 32 <unknown>

mfmax.mm acc0, acc1, acc2
# CHECK-INST: mfmax.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x33]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 33 <unknown>

mfmax.cf.mm acc0, acc1, acc2
# CHECK-INST: mfmax.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x33]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 33 <unknown>

mfmax.hf.mm acc0, acc1, acc2
# CHECK-INST: mfmax.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x33]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 33 <unknown>

mfmax.f.mm acc0, acc1, acc2
# CHECK-INST: mfmax.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x33]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 33 <unknown>

mfmax.d.mm acc0, acc1, acc2
# CHECK-INST: mfmax.d.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x33]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 33 <unknown>

msmulu.mm acc0, acc1, acc2
# CHECK-INST: msmulu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 35 <unknown>

msmulu.b.mm acc0, acc1, acc2
# CHECK-INST: msmulu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 35 <unknown>

msmulu.h.mm acc0, acc1, acc2
# CHECK-INST: msmulu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 35 <unknown>

msmulu.w.mm acc0, acc1, acc2
# CHECK-INST: msmulu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 35 <unknown>

msmulu.dw.mm acc0, acc1, acc2
# CHECK-INST: msmulu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 35 <unknown>

msmulu.hb.mm acc0, acc1, acc2
# CHECK-INST: msmulu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 35 <unknown>

mmul.mm acc0, acc1, acc2
# CHECK-INST: mmul.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 34 <unknown>

mmul.b.mm acc0, acc1, acc2
# CHECK-INST: mmul.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 34 <unknown>

mmul.h.mm acc0, acc1, acc2
# CHECK-INST: mmul.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 34 <unknown>

mmul.w.mm acc0, acc1, acc2
# CHECK-INST: mmul.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 34 <unknown>

mmul.dw.mm acc0, acc1, acc2
# CHECK-INST: mmul.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 34 <unknown>

mmul.hb.mm acc0, acc1, acc2
# CHECK-INST: mmul.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 34 <unknown>

msmul.mm acc0, acc1, acc2
# CHECK-INST: msmul.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 35 <unknown>

msmul.b.mm acc0, acc1, acc2
# CHECK-INST: msmul.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 35 <unknown>

msmul.h.mm acc0, acc1, acc2
# CHECK-INST: msmul.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 35 <unknown>

msmul.w.mm acc0, acc1, acc2
# CHECK-INST: msmul.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 35 <unknown>

msmul.dw.mm acc0, acc1, acc2
# CHECK-INST: msmul.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 35 <unknown>

msmul.hb.mm acc0, acc1, acc2
# CHECK-INST: msmul.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x35]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 35 <unknown>

mfmul.mm acc0, acc1, acc2
# CHECK-INST: mfmul.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x36]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 36 <unknown>

mfmul.cf.mm acc0, acc1, acc2
# CHECK-INST: mfmul.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x36]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 36 <unknown>

mfmul.hf.mm acc0, acc1, acc2
# CHECK-INST: mfmul.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x36]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 36 <unknown>

mfmul.f.mm acc0, acc1, acc2
# CHECK-INST: mfmul.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x36]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 36 <unknown>

mfmul.d.mm acc0, acc1, acc2
# CHECK-INST: mfmul.d.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x36]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 36 <unknown>

mmulhu.mm acc0, acc1, acc2
# CHECK-INST: mmulhu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 38 <unknown>

mmulhu.b.mm acc0, acc1, acc2
# CHECK-INST: mmulhu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 38 <unknown>

mmulhu.h.mm acc0, acc1, acc2
# CHECK-INST: mmulhu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 38 <unknown>

mmulhu.w.mm acc0, acc1, acc2
# CHECK-INST: mmulhu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 38 <unknown>

mmulhu.dw.mm acc0, acc1, acc2
# CHECK-INST: mmulhu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 38 <unknown>

mmulhu.hb.mm acc0, acc1, acc2
# CHECK-INST: mmulhu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 38 <unknown>

mmulh.mm acc0, acc1, acc2
# CHECK-INST: mmulh.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 38 <unknown>

mmulh.b.mm acc0, acc1, acc2
# CHECK-INST: mmulh.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 38 <unknown>

mmulh.h.mm acc0, acc1, acc2
# CHECK-INST: mmulh.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 38 <unknown>

mmulh.w.mm acc0, acc1, acc2
# CHECK-INST: mmulh.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 38 <unknown>

mmulh.dw.mm acc0, acc1, acc2
# CHECK-INST: mmulh.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 38 <unknown>

mmulh.hb.mm acc0, acc1, acc2
# CHECK-INST: mmulh.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x38]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 38 <unknown>

mmulhsu.mm acc0, acc1, acc2
# CHECK-INST: mmulhsu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 39 <unknown>

mmulhsu.b.mm acc0, acc1, acc2
# CHECK-INST: mmulhsu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 39 <unknown>

mmulhsu.h.mm acc0, acc1, acc2
# CHECK-INST: mmulhsu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 39 <unknown>

mmulhsu.w.mm acc0, acc1, acc2
# CHECK-INST: mmulhsu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 39 <unknown>

mmulhsu.dw.mm acc0, acc1, acc2
# CHECK-INST: mmulhsu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 39 <unknown>

mmulhsu.hb.mm acc0, acc1, acc2
# CHECK-INST: mmulhsu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 39 <unknown>

msmulsu.mm acc0, acc1, acc2
# CHECK-INST: msmulsu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 39 <unknown>

msmulsu.b.mm acc0, acc1, acc2
# CHECK-INST: msmulsu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 39 <unknown>

msmulsu.h.mm acc0, acc1, acc2
# CHECK-INST: msmulsu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 39 <unknown>

msmulsu.w.mm acc0, acc1, acc2
# CHECK-INST: msmulsu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 39 <unknown>

msmulsu.dw.mm acc0, acc1, acc2
# CHECK-INST: msmulsu.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 39 <unknown>

msmulsu.hb.mm acc0, acc1, acc2
# CHECK-INST: msmulsu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x39]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 39 <unknown>

mfdiv.mm acc0, acc1, acc2
# CHECK-INST: mfdiv.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x3a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 3a <unknown>

mfdiv.cf.mm acc0, acc1, acc2
# CHECK-INST: mfdiv.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x3a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 3a <unknown>

mfdiv.hf.mm acc0, acc1, acc2
# CHECK-INST: mfdiv.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x3a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 3a <unknown>

mfdiv.f.mm acc0, acc1, acc2
# CHECK-INST: mfdiv.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x3a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 3a <unknown>

mfdiv.d.mm acc0, acc1, acc2
# CHECK-INST: mfdiv.d.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x3a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 3a <unknown>

mwmulu.mm acc0, acc1, acc2
# CHECK-INST: mwmulu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 3c <unknown>

mwmulu.b.mm acc0, acc1, acc2
# CHECK-INST: mwmulu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 3c <unknown>

mwmulu.h.mm acc0, acc1, acc2
# CHECK-INST: mwmulu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 3c <unknown>

mwmulu.w.mm acc0, acc1, acc2
# CHECK-INST: mwmulu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 3c <unknown>

mwmulu.hb.mm acc0, acc1, acc2
# CHECK-INST: mwmulu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 3c <unknown>

mwmul.mm acc0, acc1, acc2
# CHECK-INST: mwmul.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 3c <unknown>

mwmul.b.mm acc0, acc1, acc2
# CHECK-INST: mwmul.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 3c <unknown>

mwmul.h.mm acc0, acc1, acc2
# CHECK-INST: mwmul.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 3c <unknown>

mwmul.w.mm acc0, acc1, acc2
# CHECK-INST: mwmul.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 3c <unknown>

mwmul.hb.mm acc0, acc1, acc2
# CHECK-INST: mwmul.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x3c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 3c <unknown>

mwmulsu.mm acc0, acc1, acc2
# CHECK-INST: mwmulsu.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x3d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 3d <unknown>

mwmulsu.b.mm acc0, acc1, acc2
# CHECK-INST: mwmulsu.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x3d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 3d <unknown>

mwmulsu.h.mm acc0, acc1, acc2
# CHECK-INST: mwmulsu.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x3d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 3d <unknown>

mwmulsu.w.mm acc0, acc1, acc2
# CHECK-INST: mwmulsu.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x3d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 3d <unknown>

mwmulsu.hb.mm acc0, acc1, acc2
# CHECK-INST: mwmulsu.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x3d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 3d <unknown>

mfwmul.mm acc0, acc1, acc2
# CHECK-INST: mfwmul.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x3e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 3e <unknown>

mfwmul.cf.mm acc0, acc1, acc2
# CHECK-INST: mfwmul.cf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x3e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 3e <unknown>

mfwmul.hf.mm acc0, acc1, acc2
# CHECK-INST: mfwmul.hf.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x3e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 3e <unknown>

mfwmul.f.mm acc0, acc1, acc2
# CHECK-INST: mfwmul.f.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x3e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 3e <unknown>

mand.mm acc0, acc1, acc2
# CHECK-INST: mand.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x40]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 40 <unknown>

mor.mm acc0, acc1, acc2
# CHECK-INST: mor.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x41]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 41 <unknown>

mxor.mm acc0, acc1, acc2
# CHECK-INST: mxor.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x41]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 41 <unknown>

mfsqrt.m acc0, acc1
# CHECK-INST: mfsqrt.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x08,0x42]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 08 42 <unknown>

mfsqrt.cf.m acc0, acc1
# CHECK-INST: mfsqrt.cf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x08,0x42]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 08 42 <unknown>

mfsqrt.hf.m acc0, acc1
# CHECK-INST: mfsqrt.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x08,0x42]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 08 42 <unknown>

mfsqrt.f.m acc0, acc1
# CHECK-INST: mfsqrt.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x08,0x42]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 08 42 <unknown>

mfsqrt.d.m acc0, acc1
# CHECK-INST: mfsqrt.d.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x08,0x42]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 08 42 <unknown>

msll.mm acc0, acc1, acc2
# CHECK-INST: msll.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x44]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 44 <unknown>

msll.b.mm acc0, acc1, acc2
# CHECK-INST: msll.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x44]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 44 <unknown>

msll.h.mm acc0, acc1, acc2
# CHECK-INST: msll.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x44]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 44 <unknown>

msll.w.mm acc0, acc1, acc2
# CHECK-INST: msll.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x44]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 44 <unknown>

msll.dw.mm acc0, acc1, acc2
# CHECK-INST: msll.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x44]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 44 <unknown>

msll.hb.mm acc0, acc1, acc2
# CHECK-INST: msll.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x44]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 44 <unknown>

msrl.mm acc0, acc1, acc2
# CHECK-INST: msrl.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x20,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 45 <unknown>

msrl.b.mm acc0, acc1, acc2
# CHECK-INST: msrl.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x20,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 45 <unknown>

msrl.h.mm acc0, acc1, acc2
# CHECK-INST: msrl.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x20,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 45 <unknown>

msrl.w.mm acc0, acc1, acc2
# CHECK-INST: msrl.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x20,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 45 <unknown>

msrl.dw.mm acc0, acc1, acc2
# CHECK-INST: msrl.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x20,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 45 <unknown>

msrl.hb.mm acc0, acc1, acc2
# CHECK-INST: msrl.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x20,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 20 45 <unknown>

msra.mm acc0, acc1, acc2
# CHECK-INST: msra.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xc0,0x28,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 45 <unknown>

msra.b.mm acc0, acc1, acc2
# CHECK-INST: msra.b.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x80,0x28,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 45 <unknown>

msra.h.mm acc0, acc1, acc2
# CHECK-INST: msra.h.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0x90,0x28,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 45 <unknown>

msra.w.mm acc0, acc1, acc2
# CHECK-INST: msra.w.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xa0,0x28,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 45 <unknown>

msra.dw.mm acc0, acc1, acc2
# CHECK-INST: msra.dw.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xb0,0x28,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 45 <unknown>

msra.hb.mm acc0, acc1, acc2
# CHECK-INST: msra.hb.mm acc0, acc1, acc2
# CHECK-ENCODING: [0x77,0xf0,0x28,0x45]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 28 45 <unknown>