# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

msae8.m tr0, (a1), a0, m4
# CHECK-INST: msae8.m tr0, (a1), a0, m4
# CHECK-ENCODING: [0x77,0x88,0xa5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 88 a5 06 <unknown>

msae16.m tr0, (a1), a0, m2
# CHECK-INST: msae16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 06 <unknown>

msae32.m tr0, (a1), a0, m2
# CHECK-INST: msae32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 06 <unknown>

msae64.m tr0, (a1), a0, m2
# CHECK-INST: msae64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 06 <unknown>

msate8.m tr0, (a1), a0, m2
# CHECK-INST: msate8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 16 <unknown>

msate16.m tr0, (a1), a0, m2
# CHECK-INST: msate16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 16 <unknown>

msate32.m tr0, (a1), a0, m2
# CHECK-INST: msate32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 16 <unknown>

msate64.m tr0, (a1), a0, m2
# CHECK-INST: msate64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x16]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 16 <unknown>

msbe8.m tr0, (a1), a0, m2
# CHECK-INST: msbe8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 0a <unknown>

msbe16.m tr0, (a1), a0, m2
# CHECK-INST: msbe16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 0a <unknown>

msbe32.m tr0, (a1), a0, m2
# CHECK-INST: msbe32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 0a <unknown>

msbe64.m tr0, (a1), a0, m2
# CHECK-INST: msbe64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 0a <unknown>

msbte8.m tr0, (a1), a0, m2
# CHECK-INST: msbte8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 1a <unknown>

msbte16.m tr0, (a1), a0, m2
# CHECK-INST: msbte16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 1a <unknown>

msbte32.m tr0, (a1), a0, m2
# CHECK-INST: msbte32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 1a <unknown>

msbte64.m tr0, (a1), a0, m2
# CHECK-INST: msbte64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 1a <unknown>

msce8.m tr0, (a1), a0, m2
# CHECK-INST: msce8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 02 <unknown>

msce16.m tr0, (a1), a0, m2
# CHECK-INST: msce16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 02 <unknown>

msce32.m tr0, (a1), a0, m2
# CHECK-INST: msce32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 02 <unknown>

msce64.m tr0, (a1), a0, m2
# CHECK-INST: msce64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 02 <unknown>

mscte8.m tr0, (a1), a0, m2
# CHECK-INST: mscte8.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x84,0xa5,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 84 a5 12 <unknown>

mscte16.m tr0, (a1), a0, m2
# CHECK-INST: mscte16.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0x94,0xa5,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 94 a5 12 <unknown>

mscte32.m tr0, (a1), a0, m2
# CHECK-INST: mscte32.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xa4,0xa5,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a4 a5 12 <unknown>

mscte64.m tr0, (a1), a0, m2
# CHECK-INST: mscte64.m tr0, (a1), a0, m2
# CHECK-ENCODING: [0x77,0xb4,0xa5,0x12]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b4 a5 12 <unknown>

msre8.m tr1, (a1), a0, m2
# CHECK-INST: msre8.m tr1, (a1), a0, m2
# CHECK-ENCODING: [0xf7,0x84,0xa5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 84 a5 0e <unknown>

msre16.m tr1, (a1), a0, m2
# CHECK-INST: msre16.m tr1, (a1), a0, m2
# CHECK-ENCODING: [0xf7,0x94,0xa5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 94 a5 0e <unknown>

msre32.m tr1, (a1), a0, m2
# CHECK-INST: msre32.m tr1, (a1), a0, m2
# CHECK-ENCODING: [0xf7,0xa4,0xa5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a4 a5 0e <unknown>

msre64.m tr1, (a1), a0, m2
# CHECK-INST: msre64.m tr1, (a1), a0, m2
# CHECK-ENCODING: [0xf7,0xb4,0xa5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b4 a5 0e <unknown>

msfdae8.m tr1, (a1), a0
# CHECK-INST: msfdae8.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0xc6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 c6 <unknown>

msfdae16.m tr1, (a1), a0
# CHECK-INST: msfdae16.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0xc6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 c6 <unknown>

msfdae32.m tr1, (a1), a0
# CHECK-INST: msfdae32.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0xc6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 c6 <unknown>

msfdae64.m tr1, (a1), a0
# CHECK-INST: msfdae64.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0xc6]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 c6 <unknown>


msfdbe8.m tr1, (a1), a0
# CHECK-INST: msfdbe8.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0xca]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 ca <unknown>

msfdbe16.m tr1, (a1), a0
# CHECK-INST: msfdbe16.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0xca]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 ca <unknown>

msfdbe32.m tr1, (a1), a0
# CHECK-INST: msfdbe32.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0xca]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 ca <unknown>

msfdbe64.m tr1, (a1), a0
# CHECK-INST: msfdbe64.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0xca]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 ca <unknown>

msfdce8.m tr1, (a1), a0
# CHECK-INST: msfdce8.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0xc2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 c2 <unknown>

msfdce16.m tr1, (a1), a0
# CHECK-INST: msfdce16.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0xc2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 c2 <unknown>

msfdce32.m tr1, (a1), a0
# CHECK-INST: msfdce32.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0xc2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 c2 <unknown>

msfdce64.m tr1, (a1), a0
# CHECK-INST: msfdce64.m tr1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0xc2]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 c2 <unknown>

msae8.v v1, (a1), a0
# CHECK-INST: msae8.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 86 <unknown>

msae16.v v1, (a1), a0
# CHECK-INST: msae16.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 86 <unknown>

msae32.v v1, (a1), a0
# CHECK-INST: msae32.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 86 <unknown>

msae64.v v1, (a1), a0
# CHECK-INST: msae64.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0x86]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 86 <unknown>

msbe8.v v1, (a1), a0
# CHECK-INST: msbe8.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 8a <unknown>

msbe16.v v1, (a1), a0
# CHECK-INST: msbe16.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 8a <unknown>

msbe32.v v1, (a1), a0
# CHECK-INST: msbe32.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 8a <unknown>

msbe64.v v1, (a1), a0
# CHECK-INST: msbe64.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 8a <unknown>

msce8.v v1, (a1), a0
# CHECK-INST: msce8.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x80,0xa5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 80 a5 82 <unknown>

msce16.v v1, (a1), a0
# CHECK-INST: msce16.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0x90,0xa5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 90 a5 82 <unknown>

msce32.v v1, (a1), a0
# CHECK-INST: msce32.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xa0,0xa5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 a0 a5 82 <unknown>

msce64.v v1, (a1), a0
# CHECK-INST: msce64.v v1, (a1), a0
# CHECK-ENCODING: [0xf7,0xb0,0xa5,0x82]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 b0 a5 82 <unknown>