# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN


msettype ra, a0
# CHECK-INST: msettype ra, a0
# CHECK-ENCODING: [0xf7,0x40,0x05,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 40 05 00 <unknown>

msettypei ra, e8
# CHECK-INST: msettypei ra, e8
# CHECK-ENCODING: [0xf7,0x40,0x00,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 40 00 02 <unknown>

msettypei ra, e16, int4, int8, int16
# CHECK-INST: msettypei ra, e16, int4, int8, int16
# CHECK-ENCODING: [0xf7,0xc0,0x1c,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 c0 1c 02 <unknown>

msettypei ra, e32, int4, int8, int16, int32, int64
# CHECK-INST: msettypei ra, e32, int4, int8, int16, int32, int64
# CHECK-ENCODING: [0xf7,0x40,0x7d,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 40 7d 02 <unknown>

msettypei ra, e64, int4, int8, int16, int32, int64, e3m4
# CHECK-INST: msettypei ra, e64, int4, int8, int16, int32, int64, e3m4
# CHECK-ENCODING: [0xf7,0xc0,0xfd,0x03]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 c0 fd 03 <unknown>

msettypei ra, e8, int4, int8, int16, int32, int64, e4m3
# CHECK-INST: msettypei ra, e8, int4, int8, int16, int32, int64, e4m3
# CHECK-ENCODING: [0xf7,0x40,0xfc,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 40 fc 02 <unknown>

msettypehi ra, bu
# CHECK-INST: msettypehi ra, bu
# CHECK-ENCODING: [0xf7,0x50,0x00,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 00 02 <unknown>

msettypehi ra, ba, bf16, tf32
# CHECK-INST: msettypehi ra, ba, bf16, tf32
# CHECK-ENCODING: [0xf7,0x50,0x15,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 15 02 <unknown>

msettypehi ra, ba, fp16, fp32, fp64
# CHECK-INST: msettypehi ra, ba, fp16, fp32, fp64
# CHECK-ENCODING: [0xf7,0xd0,0x1a,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 d0 1a 02 <unknown>

msetsew ra, 0
# CHECK-INST: msetsew ra, 0
# CHECK-ENCODING: [0xf7,0x60,0x00,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 60 00 02 <unknown>

msetint4 ra, 0
# CHECK-INST: msetint4 ra, 0
# CHECK-ENCODING: [0xf7,0xe0,0x00,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 e0 00 02 <unknown>

msetint8 ra, 0
# CHECK-INST: msetint8 ra, 0
# CHECK-ENCODING: [0xf7,0x60,0x01,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 60 01 02 <unknown>

msetint16 ra, 0
# CHECK-INST: msetint16 ra, 0
# CHECK-ENCODING: [0xf7,0xe0,0x01,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 e0 01 02 <unknown>

msetint32 ra, 0
# CHECK-INST: msetint32 ra, 0
# CHECK-ENCODING: [0xf7,0x60,0x02,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 60 02 02 <unknown>

msetint64 ra, 0
# CHECK-INST: msetint64 ra, 0
# CHECK-ENCODING: [0xf7,0xe0,0x02,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 e0 02 02 <unknown>

msetfp8 ra, 0
# CHECK-INST: msetfp8 ra, 0
# CHECK-ENCODING: [0xf7,0x60,0x03,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 60 03 02 <unknown>

msetfp16 ra, 0
# CHECK-INST: msetfp16 ra, 0
# CHECK-ENCODING: [0xf7,0xe0,0x03,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 e0 03 02 <unknown>

msetfp32 ra, 0
# CHECK-INST: msetfp32 ra, 0
# CHECK-ENCODING: [0xf7,0x60,0x04,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 60 04 02 <unknown>

msetfp64 ra, 0
# CHECK-INST: msetfp64 ra, 0
# CHECK-ENCODING: [0xf7,0xe0,0x04,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 e0 04 02 <unknown>

msetba ra, 0
# CHECK-INST: msetba ra, 0
# CHECK-ENCODING: [0xf7,0x60,0x05,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 60 05 02 <unknown>

msettilem ra, a0
# CHECK-INST: msettilem ra, a0
# CHECK-ENCODING: [0xf7,0x50,0x05,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 05 04 <unknown>

msettilemi ra, 0
# CHECK-INST: msettilemi ra, 0
# CHECK-ENCODING: [0xf7,0x50,0x00,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 50 00 06 <unknown>

msettilek ra, a0
# CHECK-INST: msettilek ra, a0
# CHECK-ENCODING: [0xf7,0x60,0x05,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 60 05 04 <unknown>

msettileki ra, 0
# CHECK-INST: msettileki ra, 0
# CHECK-ENCODING: [0xf7,0x60,0x00,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 60 00 06 <unknown>

msettilen ra, a0
# CHECK-INST: msettilen ra, a0
# CHECK-ENCODING: [0xf7,0x40,0x05,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 40 05 04 <unknown>

msettileni ra, 0
# CHECK-INST: msettileni ra, 0
# CHECK-ENCODING: [0xf7,0x40,0x00,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 40 00 06 <unknown>

msettspi ra, 0
# CHECK-INST: msettspi ra, 0
# CHECK-ENCODING: [0xf7,0x70,0x00,0x02]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 00 02 <unknown>

msettsp ra, a0
# CHECK-INST: msettsp ra, a0
# CHECK-ENCODING: [0xf7,0x70,0x05,0x00]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 05 00 <unknown>

msetdspi ra, 0
# CHECK-INST: msetdspi ra, 0
# CHECK-ENCODING: [0xf7,0x70,0x00,0x06]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 00 06 <unknown>

msetdsp ra, a0
# CHECK-INST: msetdsp ra, a0
# CHECK-ENCODING: [0xf7,0x70,0x05,0x04]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: f7 70 05 04 <unknown>

msetoutsh a0, a1, a2
# CHECK-INST: msetoutsh a0, a1, a2
# CHECK-ENCODING: [0x77,0xc5,0xc5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c5 c5 08 <unknown>

msetinsh a0, a1, a2
# CHECK-INST: msetinsh a0, a1, a2
# CHECK-ENCODING: [0x77,0xd5,0xc5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 d5 c5 08 <unknown>

msetsk a0, a1, a2
# CHECK-INST: msetsk a0, a1, a2
# CHECK-ENCODING: [0x77,0xe5,0xc5,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 e5 c5 08 <unknown>

msetpadval a0, a1
# CHECK-INST: msetpadval a0, a1
# CHECK-ENCODING: [0x77,0xf5,0x05,0x08]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f5 05 08 <unknown>
