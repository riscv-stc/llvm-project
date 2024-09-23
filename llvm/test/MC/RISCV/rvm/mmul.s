# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

mmau.mm acc0, tr0, tr1
# CHECK-INST: mmau.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 20 <unknown>

mmau.h.mm acc0, tr0, tr1
# CHECK-INST: mmau.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 20 <unknown>

mmau.w.mm acc0, tr0, tr1
# CHECK-INST: mmau.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 20 <unknown>

mmau.dw.mm acc0, tr0, tr1
# CHECK-INST: mmau.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x10,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 10 20 <unknown>

msmau.mm acc0, tr0, tr1
# CHECK-INST: msmau.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 21 <unknown>

msmau.h.mm acc0, tr0, tr1
# CHECK-INST: msmau.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 21 <unknown>

msmau.w.mm acc0, tr0, tr1
# CHECK-INST: msmau.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 21 <unknown>

msmau.dw.mm acc0, tr0, tr1
# CHECK-INST: msmau.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x10,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 10 21 <unknown>

mma.mm acc0, tr0, tr1
# CHECK-INST: mma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 20 <unknown>

mma.h.mm acc0, tr0, tr1
# CHECK-INST: mma.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 20 <unknown>

mma.w.mm acc0, tr0, tr1
# CHECK-INST: mma.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 20 <unknown>

mma.dw.mm acc0, tr0, tr1
# CHECK-INST: mma.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x18,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 18 20 <unknown>

msma.mm acc0, tr0, tr1
# CHECK-INST: msma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 21 <unknown>

msma.h.mm acc0, tr0, tr1
# CHECK-INST: msma.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 21 <unknown>

msma.w.mm acc0, tr0, tr1
# CHECK-INST: msma.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 21 <unknown>

msma.dw.mm acc0, tr0, tr1
# CHECK-INST: msma.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x18,0x21]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 18 21 <unknown>

mfma.mm acc0, tr0, tr1
# CHECK-INST: mfma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 22 <unknown>

mfma.hf.mm acc0, tr0, tr1
# CHECK-INST: mfma.hf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 22 <unknown>

mfma.f.mm acc0, tr0, tr1
# CHECK-INST: mfma.f.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 22 <unknown>

mfma.d.mm acc0, tr0, tr1
# CHECK-INST: mfma.d.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x10,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 10 22 <unknown>

mwmau.mm acc0, tr0, tr1
# CHECK-INST: mwmau.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 24 <unknown>

mwmau.h.mm acc0, tr0, tr1
# CHECK-INST: mwmau.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 24 <unknown>

mwmau.w.mm acc0, tr0, tr1
# CHECK-INST: mwmau.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 24 <unknown>

mswmau.mm acc0, tr0, tr1
# CHECK-INST: mswmau.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x25]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 25 <unknown>

mswmau.h.mm acc0, tr0, tr1
# CHECK-INST: mswmau.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0x25]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 25 <unknown>

mswmau.w.mm acc0, tr0, tr1
# CHECK-INST: mswmau.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0x25]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 25 <unknown>

mwma.mm acc0, tr0, tr1
# CHECK-INST: mwma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 24 <unknown>

mwma.h.mm acc0, tr0, tr1
# CHECK-INST: mwma.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 24 <unknown>

mwma.w.mm acc0, tr0, tr1
# CHECK-INST: mwma.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 24 <unknown>

mswma.mm acc0, tr0, tr1
# CHECK-INST: mswma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x25]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 25 <unknown>

mswma.h.mm acc0, tr0, tr1
# CHECK-INST: mswma.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0x25]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 25 <unknown>

mswma.w.mm acc0, tr0, tr1
# CHECK-INST: mswma.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0x25]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 25 <unknown>

mfwma.mm acc0, tr0, tr1
# CHECK-INST: mfwma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 26 <unknown>

mfwma.cf.mm acc0, tr0, tr1
# CHECK-INST: mfwma.cf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x10,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 10 26 <unknown>

mfwma.hf.mm acc0, tr0, tr1
# CHECK-INST: mfwma.hf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 26 <unknown>

mfwma.f.mm acc0, tr0, tr1
# CHECK-INST: mfwma.f.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 26 <unknown>

mqmau.mm acc0, tr0, tr1
# CHECK-INST: mqmau.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 28 <unknown>

mqmau.b.mm acc0, tr0, tr1
# CHECK-INST: mqmau.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x10,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 10 28 <unknown>

msqmau.mm acc0, tr0, tr1
# CHECK-INST: msqmau.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 29 <unknown>

msqmau.b.mm acc0, tr0, tr1
# CHECK-INST: msqmau.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x10,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 10 29 <unknown>

mqma.mm acc0, tr0, tr1
# CHECK-INST: mqma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 28 <unknown>

mqma.b.mm acc0, tr0, tr1
# CHECK-INST: mqma.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x18,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 18 28 <unknown>

msqma.mm acc0, tr0, tr1
# CHECK-INST: msqma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 29 <unknown>

msqma.b.mm acc0, tr0, tr1
# CHECK-INST: msqma.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x18,0x29]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 18 29 <unknown>

mfqma.mm acc0, tr0, tr1
# CHECK-INST: mfqma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 2a <unknown>

mfqma.cf.mm acc0, tr0, tr1
# CHECK-INST: mfqma.cf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x18,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 18 2a <unknown>

momau.mm acc0, tr0, tr1
# CHECK-INST: momau.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 2c <unknown>

momau.hb.mm acc0, tr0, tr1
# CHECK-INST: momau.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x78,0x10,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 10 2c <unknown>

msomau.mm acc0, tr0, tr1
# CHECK-INST: msomau.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0x2d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 2d <unknown>

msomau.hb.mm acc0, tr0, tr1
# CHECK-INST: msomau.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x78,0x10,0x2d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 10 2d <unknown>

moma.mm acc0, tr0, tr1
# CHECK-INST: moma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 2c <unknown>

moma.hb.mm acc0, tr0, tr1
# CHECK-INST: moma.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x78,0x18,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 18 2c <unknown>

msoma.mm acc0, tr0, tr1
# CHECK-INST: msoma.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0x2d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 2d <unknown>

msoma.hb.mm acc0, tr0, tr1
# CHECK-INST: msoma.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x78,0x18,0x2d]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 18 2d <unknown>

mmau.spa.mm acc0, tr0, tr1
# CHECK-INST: mmau.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 10 a0 <unknown>

mmau.spb.mm acc0, tr0, tr1
# CHECK-INST: mmau.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 a0 <unknown>

mmau.spa.h.mm acc0, tr0, tr1
# CHECK-INST: mmau.spa.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 10 a0 <unknown>

mmau.spb.h.mm acc0, tr0, tr1
# CHECK-INST: mmau.spb.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 a0 <unknown>

mmau.spa.w.mm acc0, tr0, tr1
# CHECK-INST: mmau.spa.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 10 a0 <unknown>

mmau.spb.w.mm acc0, tr0, tr1
# CHECK-INST: mmau.spb.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 a0 <unknown>

mmau.spa.dw.mm acc0, tr0, tr1
# CHECK-INST: mmau.spa.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x30,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 10 a0 <unknown>

mmau.spb.dw.mm acc0, tr0, tr1
# CHECK-INST: mmau.spb.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 10 a0 <unknown>

mmau.spa.dw.mm acc0, tr0, tr1
# CHECK-INST: mmau.spa.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x30,0x10,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 10 a0 <unknown>

msmau.spa.mm acc0, tr0, tr1
# CHECK-INST: msmau.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x10,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 10 a1 <unknown>

msmau.spb.mm acc0, tr0, tr1
# CHECK-INST: msmau.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 a1 <unknown>

msmau.spa.h.mm acc0, tr0, tr1
# CHECK-INST: msmau.spa.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x10,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 10 a1 <unknown>

msmau.spb.h.mm acc0, tr0, tr1
# CHECK-INST: msmau.spb.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 a1 <unknown>

msmau.spa.w.mm acc0, tr0, tr1
# CHECK-INST: msmau.spa.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x10,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 10 a1 <unknown>

msmau.spb.w.mm acc0, tr0, tr1
# CHECK-INST: msmau.spb.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 a1 <unknown>

msmau.spa.dw.mm acc0, tr0, tr1
# CHECK-INST: msmau.spa.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x30,0x10,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 10 a1 <unknown>

msmau.spb.dw.mm acc0, tr0, tr1
# CHECK-INST: msmau.spb.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x10,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 10 a1 <unknown>

mma.spa.mm acc0, tr0, tr1
# CHECK-INST: mma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 a0 <unknown>

mma.spb.mm acc0, tr0, tr1
# CHECK-INST: mma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 a0 <unknown>

mma.spa.h.mm acc0, tr0, tr1
# CHECK-INST: mma.spa.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x18,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 18 a0 <unknown>

mma.spb.h.mm acc0, tr0, tr1
# CHECK-INST: mma.spb.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 a0 <unknown>

mma.spa.w.mm acc0, tr0, tr1
# CHECK-INST: mma.spa.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x18,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 18 a0 <unknown>

mma.spb.w.mm acc0, tr0, tr1
# CHECK-INST: mma.spb.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 a0 <unknown>

mma.spa.dw.mm acc0, tr0, tr1
# CHECK-INST: mma.spa.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x30,0x18,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 18 a0 <unknown>

mma.spb.dw.mm acc0, tr0, tr1
# CHECK-INST: mma.spb.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x18,0xa0]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 18 a0 <unknown>

msma.spa.mm acc0, tr0, tr1
# CHECK-INST: msma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 a1 <unknown>

msma.spb.mm acc0, tr0, tr1
# CHECK-INST: msma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 a1 <unknown>

msma.spa.h.mm acc0, tr0, tr1
# CHECK-INST: msma.spa.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x18,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 18 a1 <unknown>

msma.spb.h.mm acc0, tr0, tr1
# CHECK-INST: msma.spb.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 a1 <unknown>

msma.spa.w.mm acc0, tr0, tr1
# CHECK-INST: msma.spa.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x18,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 18 a1 <unknown>

msma.spb.w.mm acc0, tr0, tr1
# CHECK-INST: msma.spb.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 a1 <unknown>

msma.spa.dw.mm acc0, tr0, tr1
# CHECK-INST: msma.spa.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x30,0x18,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 18 a1 <unknown>

msma.spb.dw.mm acc0, tr0, tr1
# CHECK-INST: msma.spb.dw.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x18,0xa1]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 18 a1 <unknown>

mfma.spa.mm acc0, tr0, tr1
# CHECK-INST: mfma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xa2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 a2 <unknown>

mfma.spb.mm acc0, tr0, tr1
# CHECK-INST: mfma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xa2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 a2 <unknown>

mfma.spa.hf.mm acc0, tr0, tr1
# CHECK-INST: mfma.spa.hf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x18,0xa2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 18 a2 <unknown>

mfma.spb.hf.mm acc0, tr0, tr1
# CHECK-INST: mfma.spb.hf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0xa2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 a2 <unknown>

mfma.spa.f.mm acc0, tr0, tr1
# CHECK-INST: mfma.spa.f.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x18,0xa2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 18 a2 <unknown>

mfma.spb.f.mm acc0, tr0, tr1
# CHECK-INST: mfma.spb.f.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0xa2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 a2 <unknown>

mfma.spa.d.mm acc0, tr0, tr1
# CHECK-INST: mfma.spa.d.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x30,0x18,0xa2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 18 a2 <unknown>

mfma.spb.d.mm acc0, tr0, tr1
# CHECK-INST: mfma.spb.d.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x38,0x18,0xa2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 18 a2 <unknown>

mwmau.spa.mm acc0, tr0, tr1
# CHECK-INST: mwmau.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x10,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 10 a4 <unknown>

mwmau.spb.mm acc0, tr0, tr1
# CHECK-INST: mwmau.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 a4 <unknown>

mwmau.spa.h.mm acc0, tr0, tr1
# CHECK-INST: mwmau.spa.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x10,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 10 a4 <unknown>

mwmau.spb.h.mm acc0, tr0, tr1
# CHECK-INST: mwmau.spb.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 a4 <unknown>

mwmau.spa.w.mm acc0, tr0, tr1
# CHECK-INST: mwmau.spa.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x10,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 10 a4 <unknown>

mwmau.spb.w.mm acc0, tr0, tr1
# CHECK-INST: mwmau.spb.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 a4 <unknown>

mswmau.spa.mm acc0, tr0, tr1
# CHECK-INST: mswmau.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x10,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 10 a5 <unknown>

mswmau.spb.mm acc0, tr0, tr1
# CHECK-INST: mswmau.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 a5 <unknown>

mswmau.spa.h.mm acc0, tr0, tr1
# CHECK-INST: mswmau.spa.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x10,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 10 a5 <unknown>

mswmau.spb.h.mm acc0, tr0, tr1
# CHECK-INST: mswmau.spb.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x10,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 10 a5 <unknown>

mswmau.spa.w.mm acc0, tr0, tr1
# CHECK-INST: mswmau.spa.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x10,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 10 a5 <unknown>

mswmau.spb.w.mm acc0, tr0, tr1
# CHECK-INST: mswmau.spb.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x10,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 10 a5 <unknown>

mwma.spa.mm acc0, tr0, tr1
# CHECK-INST: mwma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 a4 <unknown>

mwma.spb.mm acc0, tr0, tr1
# CHECK-INST: mwma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 a4 <unknown>

mwma.spa.h.mm acc0, tr0, tr1
# CHECK-INST: mwma.spa.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x18,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 18 a4 <unknown>

mwma.spb.h.mm acc0, tr0, tr1
# CHECK-INST: mwma.spb.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 a4 <unknown>

mwma.spa.w.mm acc0, tr0, tr1
# CHECK-INST: mwma.spa.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x18,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 18 a4 <unknown>

mwma.spb.w.mm acc0, tr0, tr1
# CHECK-INST: mwma.spb.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0xa4]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 a4 <unknown>

mswma.spa.mm acc0, tr0, tr1
# CHECK-INST: mswma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 a5 <unknown>

mswma.spb.mm acc0, tr0, tr1
# CHECK-INST: mswma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 a5 <unknown>

mswma.spa.h.mm acc0, tr0, tr1
# CHECK-INST: mswma.spa.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x18,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 18 a5 <unknown>

mswma.spb.h.mm acc0, tr0, tr1
# CHECK-INST: mswma.spb.h.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 a5 <unknown>

mswma.spa.w.mm acc0, tr0, tr1
# CHECK-INST: mswma.spa.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x18,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 18 a5 <unknown>

mswma.spb.w.mm acc0, tr0, tr1
# CHECK-INST: mswma.spb.w.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0xa5]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 a5 <unknown>

mfwma.spa.mm acc0, tr0, tr1
# CHECK-INST: mfwma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xa6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 a6 <unknown>

mfwma.spb.mm acc0, tr0, tr1
# CHECK-INST: mfwma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xa6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 a6 <unknown>

mfwma.spa.hf.mm acc0, tr0, tr1
# CHECK-INST: mfwma.spa.hf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x10,0x18,0xa6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 18 a6 <unknown>

mfwma.spb.hf.mm acc0, tr0, tr1
# CHECK-INST: mfwma.spb.hf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x18,0x18,0xa6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 18 a6 <unknown>

mfwma.spa.f.mm acc0, tr0, tr1
# CHECK-INST: mfwma.spa.f.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x20,0x18,0xa6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 18 a6 <unknown>

mfwma.spb.f.mm acc0, tr0, tr1
# CHECK-INST: mfwma.spb.f.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x28,0x18,0xa6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 18 a6 <unknown>

mqmau.spa.mm acc0, tr0, tr1
# CHECK-INST: mqmau.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x10,0xa8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 10 a8 <unknown>

mqmau.spb.mm acc0, tr0, tr1
# CHECK-INST: mqmau.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0xa8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 a8 <unknown>

mqmau.spa.b.mm acc0, tr0, tr1
# CHECK-INST: mqmau.spa.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x00,0x10,0xa8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 10 a8 <unknown>

mqmau.spb.b.mm acc0, tr0, tr1
# CHECK-INST: mqmau.spb.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x10,0xa8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 10 a8 <unknown>

msqmau.spa.mm acc0, tr0, tr1
# CHECK-INST: msqmau.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x10,0xa9]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 10 a9 <unknown>

msqmau.spb.mm acc0, tr0, tr1
# CHECK-INST: msqmau.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0xa9]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 a9 <unknown>

msqmau.spa.b.mm acc0, tr0, tr1
# CHECK-INST: msqmau.spa.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x00,0x10,0xa9]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 10 a9 <unknown>

msqmau.spb.b.mm acc0, tr0, tr1
# CHECK-INST: msqmau.spb.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x10,0xa9]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 10 a9 <unknown>

mqma.spa.mm acc0, tr0, tr1
# CHECK-INST: mqma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xa8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 a8 <unknown>

mqma.spb.mm acc0, tr0, tr1
# CHECK-INST: mqma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xa8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 a8 <unknown>

mqma.spa.b.mm acc0, tr0, tr1
# CHECK-INST: mqma.spa.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x00,0x18,0xa8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 18 a8 <unknown>

mqma.spb.b.mm acc0, tr0, tr1
# CHECK-INST: mqma.spb.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x18,0xa8]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 18 a8 <unknown>

msqma.spa.mm acc0, tr0, tr1
# CHECK-INST: msqma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xa9]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 a9 <unknown>

msqma.spb.mm acc0, tr0, tr1
# CHECK-INST: msqma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xa9]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 a9 <unknown>

msqma.spa.b.mm acc0, tr0, tr1
# CHECK-INST: msqma.spa.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x00,0x18,0xa9]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 18 a9 <unknown>

msqma.spb.b.mm acc0, tr0, tr1
# CHECK-INST: msqma.spb.b.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x18,0xa9]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 18 a9 <unknown>

mfqma.spa.mm acc0, tr0, tr1
# CHECK-INST: mfqma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xaa]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 aa <unknown>

mfqma.spb.mm acc0, tr0, tr1
# CHECK-INST: mfqma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xaa]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 aa <unknown>

mfqma.spa.cf.mm acc0, tr0, tr1
# CHECK-INST: mfqma.spa.cf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x00,0x18,0xaa]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 18 aa <unknown>

mfqma.spb.cf.mm acc0, tr0, tr1
# CHECK-INST: mfqma.spb.cf.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x08,0x18,0xaa]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 18 aa <unknown>

momau.spa.mm acc0, tr0, tr1
# CHECK-INST: momau.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x10,0xac]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 10 ac <unknown>

momau.spb.mm acc0, tr0, tr1
# CHECK-INST: momau.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0xac]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 ac <unknown>

momau.spa.hb.mm acc0, tr0, tr1
# CHECK-INST: momau.spa.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x70,0x10,0xac]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 10 ac <unknown>

momau.spb.hb.mm acc0, tr0, tr1
# CHECK-INST: momau.spb.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x78,0x10,0xac]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 10 ac <unknown>

msomau.spa.mm acc0, tr0, tr1
# CHECK-INST: msomau.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x10,0xad]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 10 ad <unknown>

msomau.spb.mm acc0, tr0, tr1
# CHECK-INST: msomau.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x10,0xad]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 10 ad <unknown>

msomau.spa.hb.mm acc0, tr0, tr1
# CHECK-INST: msomau.spa.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x70,0x10,0xad]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 10 ad <unknown>

msomau.spb.hb.mm acc0, tr0, tr1
# CHECK-INST: msomau.spb.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x78,0x10,0xad]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 10 ad <unknown>

moma.spa.mm acc0, tr0, tr1
# CHECK-INST: moma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xac]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 ac <unknown>

moma.spb.mm acc0, tr0, tr1
# CHECK-INST: moma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xac]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 ac <unknown>

moma.spa.hb.mm acc0, tr0, tr1
# CHECK-INST: moma.spa.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x70,0x18,0xac]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 18 ac <unknown>

moma.spb.hb.mm acc0, tr0, tr1
# CHECK-INST: moma.spb.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x78,0x18,0xac]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 18 ac <unknown>

msoma.spa.mm acc0, tr0, tr1
# CHECK-INST: msoma.spa.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x40,0x18,0xad]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 18 ad <unknown>

msoma.spb.mm acc0, tr0, tr1
# CHECK-INST: msoma.spb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x48,0x18,0xad]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 48 18 ad <unknown>

msoma.spa.hb.mm acc0, tr0, tr1
# CHECK-INST: msoma.spa.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x70,0x18,0xad]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 18 ad <unknown>

msoma.spb.hb.mm acc0, tr0, tr1
# CHECK-INST: msoma.spb.hb.mm acc0, tr0, tr1
# CHECK-ENCODING: [0x77,0x78,0x18,0xad]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 78 18 ad <unknown>