# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

mmau.mm tr0, tr1, tr2
# CHECK-INST: mmau.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x20,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 20 00 <unknown>

msmau.mm tr0, tr1, tr2
# CHECK-INST: msmau.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x24,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 24 00 <unknown>

mma.mm tr0, tr1, tr2
# CHECK-INST: mma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x28,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 28 00 <unknown>

msma.mm tr0, tr1, tr2
# CHECK-INST: msma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x2c,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 2c 00 <unknown>

mfma.mm tr0, tr1, tr2
# CHECK-INST: mfma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x20,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 20 02 <unknown>


mwmau.mm tr0, tr1, tr2
# CHECK-INST: mwmau.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x20,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 20 04 <unknown>

mswmau.mm tr0, tr1, tr2
# CHECK-INST: mswmau.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x24,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 24 04 <unknown>

mwma.mm tr0, tr1, tr2
# CHECK-INST: mwma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x28,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 28 04 <unknown>

mswma.mm tr0, tr1, tr2
# CHECK-INST: mswma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x2c,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 2c 04 <unknown>

mfwma.mm tr0, tr1, tr2
# CHECK-INST: mfwma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x20,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 20 06 <unknown>


mqmau.mm tr0, tr1, tr2
# CHECK-INST: mqmau.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x20,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 20 08 <unknown>

msqmau.mm tr0, tr1, tr2
# CHECK-INST: msqmau.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x24,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 24 08 <unknown>

mqma.mm tr0, tr1, tr2
# CHECK-INST: mqma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x28,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 28 08 <unknown>

msqma.mm tr0, tr1, tr2
# CHECK-INST: msqma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x2c,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 2c 08 <unknown>

mfqma.mm tr0, tr1, tr2
# CHECK-INST: mfqma.mm tr0, tr1, tr2
# CHECK-ENCODING: [0x77,0xe0,0x20,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e0 20 0a <unknown>

maddu.mm tr0, tr1, tr2, m2
# CHECK-INST: maddu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 10 <unknown>

msaddu.mm tr0, tr1, tr2, m2
# CHECK-INST: msaddu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x24,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 24 10 <unknown>

madd.mm tr0, tr1, tr2, m2
# CHECK-INST: madd.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 10 <unknown>

msadd.mm tr0, tr1, tr2, m2
# CHECK-INST: msadd.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x2c,0x10]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 2c 10 <unknown>

mfadd.mm tr0, tr1, tr2, m2
# CHECK-INST: mfadd.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 12 <unknown>

mwaddu.mm tr0, tr1, tr2, m2
# CHECK-INST: mwaddu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 14 <unknown>

mwadd.mm tr0, tr1, tr2, m2
# CHECK-INST: mwadd.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x14]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 14 <unknown>

mfwadd.mm tr0, tr1, tr2, m2
# CHECK-INST: mfwadd.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 16 <unknown>

msubu.mm tr0, tr1, tr2, m2
# CHECK-INST: msubu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 18 <unknown>

mssubu.mm tr0, tr1, tr2, m2
# CHECK-INST: mssubu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x24,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 24 18 <unknown>

msub.mm tr0, tr1, tr2, m2
# CHECK-INST: msub.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 18 <unknown>

mssub.mm tr0, tr1, tr2, m2
# CHECK-INST: mssub.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x2c,0x18]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 2c 18 <unknown>

mfsub.mm tr0, tr1, tr2, m2
# CHECK-INST: mfsub.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 1a <unknown>

mwsubu.mm tr0, tr1, tr2, m2
# CHECK-INST: mwsubu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 1c <unknown>

mwsub.mm tr0, tr1, tr2, m2
# CHECK-INST: mwsub.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x1c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 1c <unknown>

mfwsub.mm tr0, tr1, tr2, m2
# CHECK-INST: mfwsub.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x1e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 1e <unknown>

mminu.mm tr0, tr1, tr2, m2
# CHECK-INST: mminu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 20 <unknown>

mmin.mm tr0, tr1, tr2, m2
# CHECK-INST: mmin.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x20]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 20 <unknown>

mfmin.mm tr0, tr1, tr2, m2
# CHECK-INST: mfmin.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x22]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 22 <unknown>

mmaxu.mm tr0, tr1, tr2, m2
# CHECK-INST: mmaxu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 24 <unknown>

mmax.mm tr0, tr1, tr2, m2
# CHECK-INST: mmax.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x24]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 24 <unknown>

mfmax.mm tr0, tr1, tr2, m2
# CHECK-INST: mfmax.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x26]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 26 <unknown>

msmulu.mm tr0, tr1, tr2, m2
# CHECK-INST: msmulu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x24,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 24 28 <unknown>

mmul.mm tr0, tr1, tr2, m2
# CHECK-INST: mmul.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 28 <unknown>

msmul.mm tr0, tr1, tr2, m2
# CHECK-INST: msmul.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x2c,0x28]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 2c 28 <unknown>

mfmul.mm tr0, tr1, tr2, m2
# CHECK-INST: mfmul.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x2a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 2a <unknown>

mmulhu.mm tr0, tr1, tr2, m2
# CHECK-INST: mmulhu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 2c <unknown>

mmulh.mm tr0, tr1, tr2, m2
# CHECK-INST: mmulh.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x2c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 2c <unknown>

mmulhsu.mm tr0, tr1, tr2, m2
# CHECK-INST: mmulhsu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 30 <unknown>

msmulsu.mm tr0, tr1, tr2, m2
# CHECK-INST: msmulsu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x24,0x30]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 24 30 <unknown>

mwmulu.mm tr0, tr1, tr2, m2
# CHECK-INST: mwmulu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 34 <unknown>

mwmul.mm tr0, tr1, tr2, m2
# CHECK-INST: mwmul.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x28,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 28 34 <unknown>

mwmulsu.mm tr0, tr1, tr2, m2
# CHECK-INST: mwmulsu.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x2c,0x34]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 2c 34 <unknown>

mfwmul.mm tr0, tr1, tr2, m2
# CHECK-INST: mfwmul.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x36]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 36 <unknown>

mfdiv.mm tr0, tr1, tr2, m2
# CHECK-INST: mfdiv.mm tr0, tr1, tr2, m2
# CHECK-ENCODING: [0x77,0xe4,0x20,0x3a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 20 3a <unknown>

mfsqrt.m tr0, tr1, m2
# CHECK-INST: mfsqrt.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x3e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 3e <unknown>