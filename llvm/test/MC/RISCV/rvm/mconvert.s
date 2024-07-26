# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

mfncvt.f.fw.m tr0, tr1, m2
# CHECK-INST: mfncvt.f.fw.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x42]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 42 <unknown>

mfwcvt.fw.f.m tr0, tr1, m2
# CHECK-INST: mfwcvt.fw.f.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x40]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 40 <unknown>

mfcvt.f.x.m tr0, tr1, m2
# CHECK-INST: mfcvt.f.x.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x4a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 4a <unknown>

mfcvt.x.f.m tr0, tr1, m2
# CHECK-INST: mfcvt.x.f.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x48]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 48 <unknown>

mfncvt.f.xw.m tr0, tr1, m2
# CHECK-INST: mfncvt.f.xw.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x4e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 4e <unknown>

mfwcvt.xw.f.m tr0, tr1, m2
# CHECK-INST: mfwcvt.xw.f.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x4c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 4c <unknown>

mfncvt.f.xq.m tr0, tr1, m2
# CHECK-INST: mfncvt.f.xq.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x52]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 52 <unknown>

mfwcvt.xq.f.m tr0, tr1, m2
# CHECK-INST: mfwcvt.xq.f.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x50]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 50 <unknown>

mfwcvt.fw.x.m tr0, tr1, m2
# CHECK-INST: mfwcvt.fw.x.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x56]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 56 <unknown>

mfncvt.x.fw.m tr0, tr1, m2
# CHECK-INST: mfncvt.x.fw.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x54]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 54 <unknown>

mfcvt.fw.xw.m tr0, tr1, m2
# CHECK-INST: mfcvt.fw.xw.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x5a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 5a <unknown>

mfcvt.xw.fw.m tr0, tr1, m2
# CHECK-INST: mfcvt.xw.fw.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x58]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 58 <unknown>

mfncvt.fw.xq.m tr0, tr1, m2
# CHECK-INST: mfncvt.fw.xq.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x5e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 5e <unknown>

mfwcvt.xq.fw.m tr0, tr1, m2
# CHECK-INST: mfwcvt.xq.fw.m tr0, tr1, m2
# CHECK-ENCODING: [0x77,0xe4,0x00,0x5c]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e4 00 5c <unknown>