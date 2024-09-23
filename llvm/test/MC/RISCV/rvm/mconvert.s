# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-matrix %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-matrix - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-matrix %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

mcvt.x.xu.m acc0, acc1
# CHECK-INST: mcvt.x.xu.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x08,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 08 60 <unknown>

mcvt.hb.uhb.m acc0, acc1
# CHECK-INST: mcvt.hb.uhb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x08,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 08 60 <unknown>

mcvt.b.ub.m acc0, acc1
# CHECK-INST: mcvt.b.ub.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x08,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 08 60 <unknown>

mcvt.h.uh.m acc0, acc1
# CHECK-INST: mcvt.h.uh.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x08,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 08 60 <unknown>

mcvt.w.uw.m acc0, acc1
# CHECK-INST: mcvt.w.uw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x08,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 08 60 <unknown>

mcvt.dw.udw.m acc0, acc1
# CHECK-INST: mcvt.dw.udw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x08,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 08 60 <unknown>

mcvt.xu.x.m acc0, acc1
# CHECK-INST: mcvt.xu.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x48,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 48 60 <unknown>

mcvt.uhb.hb.m acc0, acc1
# CHECK-INST: mcvt.uhb.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x48,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 48 60 <unknown>

mcvt.ub.b.m acc0, acc1
# CHECK-INST: mcvt.ub.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x48,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 48 60 <unknown>

mcvt.uh.h.m acc0, acc1
# CHECK-INST: mcvt.uh.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x48,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 48 60 <unknown>

mcvt.uw.w.m acc0, acc1
# CHECK-INST: mcvt.uw.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x48,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 48 60 <unknown>

mcvt.udw.dw.m acc0, acc1
# CHECK-INST: mcvt.udw.dw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x48,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 48 60 <unknown>

mwcvtu.xw.x.m acc0, acc1
# CHECK-INST: mwcvtu.xw.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x10,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 10 60 <unknown>

mwcvtu.xq.x.m acc0, acc1
# CHECK-INST: mwcvtu.xq.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x50,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 50 60 <unknown>

mwcvtu.xo.x.m acc0, acc1
# CHECK-INST: mwcvtu.xo.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x90,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 90 60 <unknown>

mwcvtu.b.hb.m acc0, acc1
# CHECK-INST: mwcvtu.b.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x10,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 10 60 <unknown>

mwcvtu.h.hb.m acc0, acc1
# CHECK-INST: mwcvtu.h.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x50,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 50 60 <unknown>

mwcvtu.w.hb.m acc0, acc1
# CHECK-INST: mwcvtu.w.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x90,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 90 60 <unknown>

mwcvtu.h.b.m acc0, acc1
# CHECK-INST: mwcvtu.h.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x10,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 10 60 <unknown>

mwcvtu.w.b.m acc0, acc1
# CHECK-INST: mwcvtu.w.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x50,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 50 60 <unknown>

mwcvtu.w.h.m acc0, acc1
# CHECK-INST: mwcvtu.w.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x10,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 10 60 <unknown>

mwcvtu.dw.w.m acc0, acc1
# CHECK-INST: mwcvtu.dw.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x10,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 10 60 <unknown>

mwcvt.xw.x.m acc0, acc1
# CHECK-INST: mwcvt.xw.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x18,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 18 60 <unknown>

mwcvt.xq.x.m acc0, acc1
# CHECK-INST: mwcvt.xq.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x58,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 58 60 <unknown>

mwcvt.xo.x.m acc0, acc1
# CHECK-INST: mwcvt.xo.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x98,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 98 60 <unknown>

mwcvt.b.hb.m acc0, acc1
# CHECK-INST: mwcvt.b.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x18,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 18 60 <unknown>

mwcvt.h.hb.m acc0, acc1
# CHECK-INST: mwcvt.h.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x58,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 58 60 <unknown>

mwcvt.w.hb.m acc0, acc1
# CHECK-INST: mwcvt.w.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x98,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 98 60 <unknown>

mwcvt.h.b.m acc0, acc1
# CHECK-INST: mwcvt.h.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x18,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 18 60 <unknown>

mwcvt.w.b.m acc0, acc1
# CHECK-INST: mwcvt.w.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x58,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 58 60 <unknown>

mwcvt.w.h.m acc0, acc1
# CHECK-INST: mwcvt.w.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x18,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 18 60 <unknown>

mwcvt.dw.w.m acc0, acc1
# CHECK-INST: mwcvt.dw.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x18,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 18 60 <unknown>

mncvtu.x.xw.m acc0, acc1
# CHECK-INST: mncvtu.x.xw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x20,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 20 60 <unknown>

mncvtu.x.xq.m acc0, acc1
# CHECK-INST: mncvtu.x.xq.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x60,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 60 60 <unknown>

mncvtu.x.xo.m acc0, acc1
# CHECK-INST: mncvtu.x.xo.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xa0,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 a0 60 <unknown>

mncvtu.hb.b.m acc0, acc1
# CHECK-INST: mncvtu.hb.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x20,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 20 60 <unknown>

mncvtu.hb.h.m acc0, acc1
# CHECK-INST: mncvtu.hb.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x60,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 60 60 <unknown>

mncvtu.hb.w.m acc0, acc1
# CHECK-INST: mncvtu.hb.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xa0,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 a0 60 <unknown>

mncvtu.b.h.m acc0, acc1
# CHECK-INST: mncvtu.b.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x20,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 20 60 <unknown>

mncvtu.b.w.m acc0, acc1
# CHECK-INST: mncvtu.b.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x60,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 60 60 <unknown>

mncvtu.h.w.m acc0, acc1
# CHECK-INST: mncvtu.h.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x20,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 20 60 <unknown>

mncvtu.w.dw.m acc0, acc1
# CHECK-INST: mncvtu.w.dw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x20,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 20 60 <unknown>

mncvt.x.xw.m acc0, acc1
# CHECK-INST: mncvt.x.xw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x28,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 28 60 <unknown>

mncvt.x.xq.m acc0, acc1
# CHECK-INST: mncvt.x.xq.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x68,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 68 60 <unknown>

mncvt.x.xo.m acc0, acc1
# CHECK-INST: mncvt.x.xo.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xa8,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 a8 60 <unknown>

mncvt.hb.b.m acc0, acc1
# CHECK-INST: mncvt.hb.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x28,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 28 60 <unknown>

mncvt.hb.h.m acc0, acc1
# CHECK-INST: mncvt.hb.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x68,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 68 60 <unknown>

mncvt.hb.w.m acc0, acc1
# CHECK-INST: mncvt.hb.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xa8,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 a8 60 <unknown>

mncvt.b.h.m acc0, acc1
# CHECK-INST: mncvt.b.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x28,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 28 60 <unknown>

mncvt.b.w.m acc0, acc1
# CHECK-INST: mncvt.b.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x68,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 68 60 <unknown>

mncvt.h.w.m acc0, acc1
# CHECK-INST: mncvt.h.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x28,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 28 60 <unknown>

mncvt.w.dw.m acc0, acc1
# CHECK-INST: mncvt.w.dw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x28,0x60]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 28 60 <unknown>

mfcvt.bf.hf.m acc0, acc1
# CHECK-INST: mfcvt.bf.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x00,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 00 66 <unknown>

mfcvt.hf.bf.m acc0, acc1
# CHECK-INST: mfcvt.hf.bf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x08,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 08 66 <unknown>

mfwcvt.fw.f.m acc0, acc1
# CHECK-INST: mfwcvt.fw.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x50,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 50 66 <unknown>

mfwcvt.hf.cf.m acc0, acc1
# CHECK-INST: mfwcvt.hf.cf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x50,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 50 66 <unknown>

mfwcvt.f.hf.m acc0, acc1
# CHECK-INST: mfwcvt.f.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x50,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 50 66 <unknown>

mfwcvt.d.f.m acc0, acc1
# CHECK-INST: mfwcvt.d.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x50,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 50 66 <unknown>

mfncvt.f.fw.m acc0, acc1
# CHECK-INST: mfncvt.f.fw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x60,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 60 66 <unknown>

mfncvt.cf.hf.m acc0, acc1
# CHECK-INST: mfncvt.cf.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x60,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 60 66 <unknown>

mfncvt.hf.f.m acc0, acc1
# CHECK-INST: mfncvt.hf.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x60,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 60 66 <unknown>

mfncvt.f.d.m acc0, acc1
# CHECK-INST: mfncvt.f.d.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x60,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 60 66 <unknown>

mfcvtu.f.x.m acc0, acc1
# CHECK-INST: mfcvtu.f.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x80,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 80 66 <unknown>

mfcvtu.hf.h.m acc0, acc1
# CHECK-INST: mfcvtu.hf.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x80,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 80 66 <unknown>

mfcvtu.f.w.m acc0, acc1
# CHECK-INST: mfcvtu.f.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x80,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 80 66 <unknown>

mfcvtu.d.dw.m acc0, acc1
# CHECK-INST: mfcvtu.d.dw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x80,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 80 66 <unknown>

mfcvt.f.x.m acc0, acc1
# CHECK-INST: mfcvt.f.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x88,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 88 66 <unknown>

mfcvt.hf.h.m acc0, acc1
# CHECK-INST: mfcvt.hf.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x88,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 88 66 <unknown>

mfcvt.f.w.m acc0, acc1
# CHECK-INST: mfcvt.f.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x88,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 88 66 <unknown>

mfcvt.d.dw.m acc0, acc1
# CHECK-INST: mfcvt.d.dw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x88,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 88 66 <unknown>

mfwcvtu.fw.x.m acc0, acc1
# CHECK-INST: mfwcvtu.fw.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x90,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 90 66 <unknown>

mfwcvtu.hf.b.m acc0, acc1
# CHECK-INST: mfwcvtu.hf.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x90,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 90 66 <unknown>

mfwcvtu.f.h.m acc0, acc1
# CHECK-INST: mfwcvtu.f.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x90,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 90 66 <unknown>

mfwcvtu.d.w.m acc0, acc1
# CHECK-INST: mfwcvtu.d.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x90,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 90 66 <unknown>

mfwcvt.fw.x.m acc0, acc1
# CHECK-INST: mfwcvt.fw.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x98,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 98 66 <unknown>

mfwcvt.hf.b.m acc0, acc1
# CHECK-INST: mfwcvt.hf.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x98,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 98 66 <unknown>

mfwcvt.f.h.m acc0, acc1
# CHECK-INST: mfwcvt.f.h.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x98,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 98 66 <unknown>

mfwcvt.d.w.m acc0, acc1
# CHECK-INST: mfwcvt.d.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x98,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 98 66 <unknown>

mfncvtu.f.xw.m acc0, acc1
# CHECK-INST: mfncvtu.f.xw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xa0,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 a0 66 <unknown>

mfncvtu.hf.w.m acc0, acc1
# CHECK-INST: mfncvtu.hf.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xa0,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 a0 66 <unknown>

mfncvtu.f.dw.m acc0, acc1
# CHECK-INST: mfncvtu.f.dw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0xa0,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 a0 66 <unknown>

mfncvt.f.xw.m acc0, acc1
# CHECK-INST: mfncvt.f.xw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xa8,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 a8 66 <unknown>

mfncvt.hf.w.m acc0, acc1
# CHECK-INST: mfncvt.hf.w.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xa8,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 a8 66 <unknown>

mfncvt.f.dw.m acc0, acc1
# CHECK-INST: mfncvt.f.dw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0xa8,0x66]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 a8 66 <unknown>

mfcvtu.x.f.m acc0, acc1
# CHECK-INST: mfcvtu.x.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x80,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 80 64 <unknown>

mfcvtu.h.hf.m acc0, acc1
# CHECK-INST: mfcvtu.h.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x80,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 80 64 <unknown>

mfcvtu.w.f.m acc0, acc1
# CHECK-INST: mfcvtu.w.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x80,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 80 64 <unknown>

mfcvtu.dw.d.m acc0, acc1
# CHECK-INST: mfcvtu.dw.d.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x80,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 80 64 <unknown>

mfcvt.x.f.m acc0, acc1
# CHECK-INST: mfcvt.x.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x88,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 88 64 <unknown>

mfcvt.h.hf.m acc0, acc1
# CHECK-INST: mfcvt.h.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x88,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 88 64 <unknown>

mfcvt.w.f.m acc0, acc1
# CHECK-INST: mfcvt.w.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x88,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 88 64 <unknown>

mfcvt.dw.d.m acc0, acc1
# CHECK-INST: mfcvt.dw.d.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0x88,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 88 64 <unknown>

mfwcvtu.xw.f.m acc0, acc1
# CHECK-INST: mfwcvtu.xw.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x90,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 90 64 <unknown>

mfwcvtu.w.hf.m acc0, acc1
# CHECK-INST: mfwcvtu.w.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x90,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 90 64 <unknown>

mfwcvtu.dw.f.m acc0, acc1
# CHECK-INST: mfwcvtu.dw.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x90,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 90 64 <unknown>

mfwcvt.xw.f.m acc0, acc1
# CHECK-INST: mfwcvt.xw.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x98,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 98 64 <unknown>

mfwcvt.w.hf.m acc0, acc1
# CHECK-INST: mfwcvt.w.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0x98,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 98 64 <unknown>

mfwcvt.dw.f.m acc0, acc1
# CHECK-INST: mfwcvt.dw.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0x98,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 98 64 <unknown>

mfncvtu.x.fw.m acc0, acc1
# CHECK-INST: mfncvtu.x.fw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xa0,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 a0 64 <unknown>

mfncvtu.b.hf.m acc0, acc1
# CHECK-INST: mfncvtu.b.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0xa0,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 a0 64 <unknown>

mfncvtu.h.f.m acc0, acc1
# CHECK-INST: mfncvtu.h.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xa0,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 a0 64 <unknown>

mfncvtu.w.d.m acc0, acc1
# CHECK-INST: mfncvtu.w.d.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0xa0,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 a0 64 <unknown>

mfncvt.x.fw.m acc0, acc1
# CHECK-INST: mfncvt.x.fw.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xa8,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 a8 64 <unknown>

mfncvt.b.hf.m acc0, acc1
# CHECK-INST: mfncvt.b.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0xa8,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 a8 64 <unknown>

mfncvt.h.f.m acc0, acc1
# CHECK-INST: mfncvt.h.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xa8,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 a8 64 <unknown>

mfncvt.w.d.m acc0, acc1
# CHECK-INST: mfncvt.w.d.m acc0, acc1
# CHECK-ENCODING: [0x77,0xb0,0xa8,0x64]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 b0 a8 64 <unknown>

mfwcvtu.fq.x.m acc0, acc1
# CHECK-INST: mfwcvtu.fq.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x90,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 90 67 <unknown>

mfwcvtu.hf.hb.m acc0, acc1
# CHECK-INST: mfwcvtu.hf.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x90,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 90 67 <unknown>

mfwcvtu.f.b.m acc0, acc1
# CHECK-INST: mfwcvtu.f.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x90,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 90 67 <unknown>

mfwcvt.fq.x.m acc0, acc1
# CHECK-INST: mfwcvt.fq.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0x98,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 98 67 <unknown>

mfwcvt.hf.hb.m acc0, acc1
# CHECK-INST: mfwcvt.hf.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0x98,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 98 67 <unknown>

mfwcvt.f.b.m acc0, acc1
# CHECK-INST: mfwcvt.f.b.m acc0, acc1
# CHECK-ENCODING: [0x77,0x80,0x98,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 80 98 67 <unknown>

mfwcvtu.fo.x.m acc0, acc1
# CHECK-INST: mfwcvtu.fo.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xd0,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 d0 67 <unknown>

mfwcvtu.f.hb.m acc0, acc1
# CHECK-INST: mfwcvtu.f.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0xd0,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 d0 67 <unknown>

mfwcvt.fo.x.m acc0, acc1
# CHECK-INST: mfwcvt.fo.x.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xd8,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 d8 67 <unknown>

mfwcvt.f.hb.m acc0, acc1
# CHECK-INST: mfwcvt.f.hb.m acc0, acc1
# CHECK-ENCODING: [0x77,0xf0,0xd8,0x67]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 f0 d8 67 <unknown>

mfncvtu.x.fq.m acc0, acc1
# CHECK-INST: mfncvtu.x.fq.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xa0,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 a0 65 <unknown>

mfncvtu.hb.hf.m acc0, acc1
# CHECK-INST: mfncvtu.hb.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0xa0,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 a0 65 <unknown>

mfncvtu.b.f.m acc0, acc1
# CHECK-INST: mfncvtu.b.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xa0,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 a0 65 <unknown

mfncvt.x.fq.m acc0, acc1
# CHECK-INST: mfncvt.x.fq.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xa8,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 a8 65 <unknown>

mfncvt.hb.hf.m acc0, acc1
# CHECK-INST: mfncvt.hb.hf.m acc0, acc1
# CHECK-ENCODING: [0x77,0x90,0xa8,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 90 a8 65 <unknown>

mfncvt.b.f.m acc0, acc1
# CHECK-INST: mfncvt.b.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xa8,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 a8 65 <unknown>

mfncvtu.x.fo.m acc0, acc1
# CHECK-INST: mfncvtu.x.fo.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xe0,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 e0 65 <unknown>

mfncvtu.hb.f.m acc0, acc1
# CHECK-INST: mfncvtu.hb.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xe0,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 e0 65 <unknown>

mfncvt.x.fo.m acc0, acc1
# CHECK-INST: mfncvt.x.fo.m acc0, acc1
# CHECK-ENCODING: [0x77,0xc0,0xe8,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 c0 e8 65 <unknown>

mfncvt.hb.f.m acc0, acc1
# CHECK-INST: mfncvt.hb.f.m acc0, acc1
# CHECK-ENCODING: [0x77,0xa0,0xe8,0x65]
# CHECK-ERROR: instruction requires the following: 'Matrix' (Matrix Instructions)
# CHECK-UNKNOWN: 77 a0 e8 65 <unknown>