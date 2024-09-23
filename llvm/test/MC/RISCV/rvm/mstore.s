# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

msae8.m tr0, (a0), a1
# CHECK-INST: msae8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 06 <unknown>

msae16.m tr0, (a0), a1
# CHECK-INST: msae16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 06 <unknown>

msae32.m tr0, (a0), a1
# CHECK-INST: msae32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 06 <unknown>

msae64.m tr0, (a0), a1
# CHECK-INST: msae64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 06 <unknown>

msbe8.m tr0, (a0), a1
# CHECK-INST: msbe8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 0a <unknown>

msbe16.m tr0, (a0), a1
# CHECK-INST: msbe16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 0a <unknown>

msbe32.m tr0, (a0), a1
# CHECK-INST: msbe32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 0a <unknown>

msbe64.m tr0, (a0), a1
# CHECK-INST: msbe64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 0a <unknown>

msce8.m acc0, (a0), a1
# CHECK-INST: msce8.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 02 <unknown>

msce16.m acc0, (a0), a1
# CHECK-INST: msce16.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 02 <unknown>

msce32.m acc0, (a0), a1
# CHECK-INST: msce32.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 02 <unknown>

msce64.m acc0, (a0), a1
# CHECK-INST: msce64.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 02 <unknown>

mstre8.m tr0, (a0), a1
# CHECK-INST: mstre8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 0e <unknown>

mstre16.m tr0, (a0), a1
# CHECK-INST: mstre16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 0e <unknown>

mstre32.m tr0, (a0), a1
# CHECK-INST: mstre32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 0e <unknown>

mstre64.m tr0, (a0), a1
# CHECK-INST: mstre64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 0e <unknown>

msate8.m tr0, (a0), a1
# CHECK-INST: msate8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x08,0xb5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 b5 06 <unknown>

msate16.m tr0, (a0), a1
# CHECK-INST: msate16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x18,0xb5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 b5 06 <unknown>

msate32.m tr0, (a0), a1
# CHECK-INST: msate32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x28,0xb5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 b5 06 <unknown>

msate64.m tr0, (a0), a1
# CHECK-INST: msate64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x38,0xb5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 b5 06 <unknown>

msbte8.m tr0, (a0), a1
# CHECK-INST: msbte8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x08,0xb5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 b5 0a <unknown>

msbte16.m tr0, (a0), a1
# CHECK-INST: msbte16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x18,0xb5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 b5 0a <unknown>

msbte32.m tr0, (a0), a1
# CHECK-INST: msbte32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x28,0xb5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 b5 0a <unknown>

msbte64.m tr0, (a0), a1
# CHECK-INST: msbte64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x38,0xb5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 b5 0a <unknown>

mscte8.m acc0, (a0), a1
# CHECK-INST: mscte8.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x08,0xb5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 b5 02 <unknown>

mscte16.m acc0, (a0), a1
# CHECK-INST: mscte16.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x18,0xb5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 b5 02 <unknown>

mscte32.m acc0, (a0), a1
# CHECK-INST: mscte32.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x28,0xb5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 b5 02 <unknown>

mscte64.m acc0, (a0), a1
# CHECK-INST: mscte64.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x38,0xb5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 b5 02 <unknown>

msacce8.m acc0, (a0), a1
# CHECK-INST: msacce8.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x08,0xb5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 08 b5 0e <unknown>

msacce16.m acc0, (a0), a1
# CHECK-INST: msacce16.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x18,0xb5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 18 b5 0e <unknown>

msacce32.m acc0, (a0), a1
# CHECK-INST: msacce32.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x28,0xb5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 28 b5 0e <unknown>

msacce64.m acc0, (a0), a1
# CHECK-INST: msacce64.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x38,0xb5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 38 b5 0e <unknown>

msae8.v v0, (a0), a1
# CHECK-INST: msae8.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 86 <unknown>

msae16.v v0, (a0), a1
# CHECK-INST: msae16.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 86 <unknown>

msae32.v v0, (a0), a1
# CHECK-INST: msae32.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 86 <unknown>

msae64.v v0, (a0), a1
# CHECK-INST: msae64.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 86 <unknown>

msbe8.v v0, (a0), a1
# CHECK-INST: msbe8.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 8a <unknown>

msbe16.v v0, (a0), a1
# CHECK-INST: msbe16.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 8a <unknown>

msbe32.v v0, (a0), a1
# CHECK-INST: msbe32.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 8a <unknown>

msbe64.v v0, (a0), a1
# CHECK-INST: msbe64.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 8a <unknown>

msce8.v v0, (a0), a1
# CHECK-INST: msce8.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x00,0xb5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 00 b5 82 <unknown>

msce16.v v0, (a0), a1
# CHECK-INST: msce16.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x10,0xb5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 10 b5 82 <unknown>

msce32.v v0, (a0), a1
# CHECK-INST: msce32.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x20,0xb5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 20 b5 82 <unknown>

msce64.v v0, (a0), a1
# CHECK-INST: msce64.v v0, (a0), a1
# CHECK-ENCODING: [0x77,0x30,0xb5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 30 b5 82 <unknown>

msfdae8.m tr0, (a0), a1
# CHECK-INST: msfdae8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x40,0xb5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 b5 86 <unknown>

msfdae16.m tr0, (a0), a1
# CHECK-INST: msfdae16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x50,0xb5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 b5 86 <unknown>

msfdae32.m tr0, (a0), a1
# CHECK-INST: msfdae32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x60,0xb5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 b5 86 <unknown>

msfdae64.m tr0, (a0), a1
# CHECK-INST: msfdae64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x70,0xb5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 b5 86 <unknown>

msfdbe8.m tr0, (a0), a1
# CHECK-INST: msfdbe8.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x40,0xb5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 b5 8a <unknown>

msfdbe16.m tr0, (a0), a1
# CHECK-INST: msfdbe16.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x50,0xb5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 b5 8a <unknown>

msfdbe32.m tr0, (a0), a1
# CHECK-INST: msfdbe32.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x60,0xb5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 b5 8a <unknown>

msfdbe64.m tr0, (a0), a1
# CHECK-INST: msfdbe64.m tr0, (a0), a1
# CHECK-ENCODING: [0x77,0x70,0xb5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 b5 8a <unknown>

msfdce8.m acc0, (a0), a1
# CHECK-INST: msfdce8.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x40,0xb5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 40 b5 82 <unknown>

msfdce16.m acc0, (a0), a1
# CHECK-INST: msfdce16.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x50,0xb5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 50 b5 82 <unknown>

msfdce32.m acc0, (a0), a1
# CHECK-INST: msfdce32.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x60,0xb5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 60 b5 82 <unknown>

msfdce64.m acc0, (a0), a1
# CHECK-INST: msfdce64.m acc0, (a0), a1
# CHECK-ENCODING: [0x77,0x70,0xb5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 70 b5 82 <unknown>