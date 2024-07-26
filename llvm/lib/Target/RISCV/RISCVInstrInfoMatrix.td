//===-- RISCVInstrInfoMatrix.td - RISC-V 'Matrix' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// This file describes the RISC-V instructions from the standard Matrix
/// extension, version 0.3.1
/// This version is still experimental as the 'Matrix' extension hasn't been
/// ratified yet.
///
//===----------------------------------------------------------------------===//

include "RISCVInstrFormatsMatrix.td"

//===----------------------------------------------------------------------===//
// Operand and SDNode transformation definitions.
//===----------------------------------------------------------------------===//

def LMULTypeIAsmOperand : AsmOperandClass {
  let Name = "LMULTypeI";
  let ParserMethod = "parseLMULTypeI";
  let DiagnosticType = "InvalidLMULTypeI";
}

def LMULTypeIOp : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<2>(Imm);}]> {
  let ParserMatchClass = LMULTypeIAsmOperand;
  let PrintMethod = "printLMULTypeI";
  let DecoderMethod = "decodeUImmOperand<2>";
}

def MTypeIAsmOperand : AsmOperandClass {
  let Name = "MTypeI";
  let ParserMethod = "parseMTypeI";
  let DiagnosticType = "InvalidMTypeI";
}

def MTypeIOp : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<13>(Imm);}]> {
  let ParserMatchClass = MTypeIAsmOperand;
  let PrintMethod = "printMTypeI";
  let DecoderMethod = "decodeUImmOperand<13>";
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in {
// unfold load td, (rs1), rs2
class MatrixTRULoad<bits<6> funct6, bits<3> width, string opcodestr>
    : RVInstMUL<funct6, width,
                (outs TRR:$td),
                (ins GPR:$rs1, GPR:$rs2), opcodestr,
                "$td, (${rs1}), $rs2">;
// load td, (rs1), rs2, lmul
class MatrixTRLoad<bits<6> funct6, bits<3> width, string opcodestr>
    : RVInstML<funct6, width,
                (outs TRR:$td),
                (ins GPR:$rs1, GPR:$rs2, LMULTypeIOp:$lmul), opcodestr,
                "$td, (${rs1}), $rs2, $lmul">;
class MatrixVectorLoad<bits<6> funct6, bits<3> width, string opcodestr>
    : RVInstVL<funct6, width,
                (outs VR:$vd),
                (ins GPR:$rs1, GPR:$rs2), opcodestr,
                "$vd, (${rs1}), $rs2">;
} // hasSideEffects = 0, mayLoad = 1, mayStore = 0

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in {
// unfold store ts3, (rs1), rs2
class MatrixTRUStore<bits<6> funct6, bits<3> width, string opcodestr>
    : RVInstMUS<funct6, width, (outs),
                (ins TRR:$ts3, GPR:$rs1, GPR:$rs2),
                opcodestr, "$ts3, (${rs1}), $rs2">;
// store ts3, (rs1), rs2, lmul
class MatrixTRStore<bits<6> funct6, bits<3> width, string opcodestr>
    : RVInstMS<funct6, width, (outs),
                (ins TRR:$ts3, GPR:$rs1, GPR:$rs2, LMULTypeIOp:$lmul),
                opcodestr, "$ts3, (${rs1}), $rs2, $lmul">;
class MatrixVectorStore<bits<6> funct6, bits<3> width, string opcodestr>
    : RVInstVS<funct6, width, (outs),
                (ins VR:$vs3, GPR:$rs1, GPR:$rs2),
                opcodestr, "$vs3, (${rs1}), $rs2">;
} // hasSideEffects = 0, mayLoad = 0, mayStore = 1

// Matrix Arithmetic
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in {
// Matrix multiplication and add, td = td + ts1 * ts2
let Constraints = "$td = $td_wb" in
class MALUMM<bits<6> funct6, bit fp, bit sn, bit sa, string opcodestr>
    : RVInstMM<funct6, fp, sn, sa, (outs TRR:$td_wb),
                (ins TRR:$td, TRR:$ts1, TRR:$ts2),
                opcodestr, "$td, $ts1, $ts2">;

class MALUMMI<bits<6> funct6, bit fp, bit sn, bit sa, string opcodestr>
    : RVInstMMI<funct6, fp, sn, sa, (outs TRR:$td),
                (ins TRR:$ts1, TRR:$ts2, LMULTypeIOp:$lmul),
                opcodestr, "$td, $ts1, $ts2, $lmul">;

class MALUMMI_UNARY<bits<6> funct6, bit fp, bit sn, bit sa, string opcodestr>
    : RVInstMMI_UNARY<funct6, fp, sn, sa, (outs TRR:$td),
                (ins TRR:$ts1, LMULTypeIOp:$lmul),
                opcodestr, "$td, $ts1, $lmul">;

class MFCVTMI<bits<6> funct6, bit fdst, string opcodestr>
    : RVInstMCVTI<funct6, fdst, (outs TRR:$td),
                (ins TRR:$ts1, LMULTypeIOp:$lmul),
                opcodestr, "$td, $ts1, $lmul">;

class MMOVETR2V<bits<6> funct6, string opcodestr>
    : RVInstMOVT2V<funct6, (outs VR:$vd),
                    (ins TRR:$td, GPR:$rs2),
                    opcodestr, "$vd, $td, $rs2">;

class MMOVEV2TR<bits<6> funct6, string opcodestr>
    : RVInstMOVV2T<funct6, (outs TRR:$td),
                    (ins VR:$vs1, GPR:$rs2),
                    opcodestr, "$td, $vs1, $rs2">;

class MMOVETR2GR<bits<6> funct6, string opcodestr>
    : RVInstMOVT2G<funct6, (outs GPR:$rd),
                    (ins TRR:$td, GPR:$rs2),
                    opcodestr, "$rd, $td, $rs2">;

class MMOVEGR2TR<bits<6> funct6, string opcodestr>
    : RVInstMOVG2T<funct6, (outs TRR:$td),
                    (ins GPR:$rs1, GPR:$rs2),
                    opcodestr, "$td, $rs1, $rs2">;

class MMOVEFTR2GR<bits<6> funct6, string opcodestr>
    : RVInstMOVT2G<funct6, (outs FPR32:$rd),
                    (ins TRR:$td, GPR:$rs2),
                    opcodestr, "$rd, $td, $rs2">;

class MMOVEFGR2TR<bits<6> funct6, string opcodestr>
    : RVInstMOVG2T<funct6, (outs TRR:$td),
                    (ins FPR32:$rs1, GPR:$rs2),
                    opcodestr, "$td, $rs1, $rs2">;

class MMOVEBR2TR<bits<5> funct5, string opcodestr>
    : RVInstMOVBR2T<funct5, (outs TRR:$td),
                    (ins TRR:$ts1),
                    opcodestr, "$td, $ts1">;
} // hasSideEffects = 0, mayLoad = 0, mayStore = 0

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtMatrix] in {
// Configuration
let hasSideEffects = 1, mayLoad = 0, mayStore = 0 in {
// Mtype Config
def MSETTYPEI : RVInstSetMTypei<(outs GPR:$rd), (ins MTypeIOp:$mtypei),
                           "msettypei", "$rd, $mtypei">;
def MSETTYPE : RVInstSetMType<(outs GPR:$rd), (ins GPR:$rs1),
                         "msettype", "$rd, $rs1">;
// Tile Config
def MSETTILEMI : RVInstSetTilei<0b0010, (outs GPR:$rd), (ins uimm13:$mleni),
                         "msettilemi", "$rd, $mleni">;
def MSETTILEM : RVInstSetTile<0b0011, (outs GPR:$rd), (ins GPR:$rs1),
                         "msettilem", "$rd, $rs1">;
def MSETTILEKI : RVInstSetTilei<0b0100, (outs GPR:$rd), (ins uimm13:$mleni),
                         "msettileki", "$rd, $mleni">;
def MSETTILEK : RVInstSetTile<0b0101, (outs GPR:$rd), (ins GPR:$rs1),
                         "msettilek", "$rd, $rs1">;
def MSETTILENI : RVInstSetTilei<0b0110, (outs GPR:$rd), (ins uimm13:$mleni),
                         "msettileni", "$rd, $mleni">;
def MSETTILEN : RVInstSetTile<0b0111, (outs GPR:$rd), (ins GPR:$rs1),
                         "msettilen", "$rd, $rs1">;
def MSETTILE : RVInstSetTile<0b1000, (outs GPR:$rd), (ins GPR:$rs1),
                         "msettile", "$rd, $rs1">;
// IM2COL Config
def MSETOUTSH  : RVInstSetIm2col<0b1000, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                         "msetoutsh", "$rd, $rs1, $rs2">;
def MSETINSH   : RVInstSetIm2col<0b1001, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                         "msetinsh", "$rd, $rs1, $rs2">;
def MSETSK     : RVInstSetIm2col<0b1010, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                         "msetsk", "$rd, $rs1, $rs2">;
def MSETPADVAL : RVInstSetPadVal<0b1011, (outs GPR:$rd), (ins GPR:$rs1),
                         "msetpadval", "$rd, $rs1">;
} // hasSideEffects = 1, mayLoad = 0, mayStore = 0

// Matrix Load Instructions
// Matrix Load A
def MLAE8_M        : MatrixTRLoad<0b000001, 0b000, "mlae8.m">;
def MLAE16_M       : MatrixTRLoad<0b000001, 0b001, "mlae16.m">;
def MLAE32_M       : MatrixTRLoad<0b000001, 0b010, "mlae32.m">;
def MLAE64_M       : MatrixTRLoad<0b000001, 0b011, "mlae64.m">;
// Matrix Load A Transposed
def MLATE8_M       : MatrixTRLoad<0b000101, 0b000, "mlate8.m">;
def MLATE16_M      : MatrixTRLoad<0b000101, 0b001, "mlate16.m">;
def MLATE32_M      : MatrixTRLoad<0b000101, 0b010, "mlate32.m">;
def MLATE64_M      : MatrixTRLoad<0b000101, 0b011, "mlate64.m">;
// Matrix Load B
def MLBE8_M        : MatrixTRLoad<0b000010, 0b000, "mlbe8.m">;
def MLBE16_M       : MatrixTRLoad<0b000010, 0b001, "mlbe16.m">;
def MLBE32_M       : MatrixTRLoad<0b000010, 0b010, "mlbe32.m">;
def MLBE64_M       : MatrixTRLoad<0b000010, 0b011, "mlbe64.m">;
// Matrix Load B Transposed
def MLBTE8_M       : MatrixTRLoad<0b000110, 0b000, "mlbte8.m">;
def MLBTE16_M      : MatrixTRLoad<0b000110, 0b001, "mlbte16.m">;
def MLBTE32_M      : MatrixTRLoad<0b000110, 0b010, "mlbte32.m">;
def MLBTE64_M      : MatrixTRLoad<0b000110, 0b011, "mlbte64.m">;
// Matrix Load C
def MLCE8_M        : MatrixTRLoad<0b000000, 0b000, "mlce8.m">;
def MLCE16_M       : MatrixTRLoad<0b000000, 0b001, "mlce16.m">;
def MLCE32_M       : MatrixTRLoad<0b000000, 0b010, "mlce32.m">;
def MLCE64_M       : MatrixTRLoad<0b000000, 0b011, "mlce64.m">;
// Matrix Load C Transposed
def MLCTE8_M       : MatrixTRLoad<0b000100, 0b000, "mlcte8.m">;
def MLCTE16_M      : MatrixTRLoad<0b000100, 0b001, "mlcte16.m">;
def MLCTE32_M      : MatrixTRLoad<0b000100, 0b010, "mlcte32.m">;
def MLCTE64_M      : MatrixTRLoad<0b000100, 0b011, "mlcte64.m">;
// Whole Matrix Load
def MLRE8_M        : MatrixTRLoad<0b000011, 0b000, "mlre8.m">;
def MLRE16_M       : MatrixTRLoad<0b000011, 0b001, "mlre16.m">;
def MLRE32_M       : MatrixTRLoad<0b000011, 0b010, "mlre32.m">;
def MLRE64_M       : MatrixTRLoad<0b000011, 0b011, "mlre64.m">;

// Matrix Store Instructions
// Store A
def MSAE8_M        : MatrixTRStore<0b000001, 0b000, "msae8.m">;
def MSAE16_M       : MatrixTRStore<0b000001, 0b001, "msae16.m">;
def MSAE32_M       : MatrixTRStore<0b000001, 0b010, "msae32.m">;
def MSAE64_M       : MatrixTRStore<0b000001, 0b011, "msae64.m">;
// Matrix Store A Transposed
def MSATE8_M       : MatrixTRStore<0b000101, 0b000, "msate8.m">;
def MSATE16_M      : MatrixTRStore<0b000101, 0b001, "msate16.m">;
def MSATE32_M      : MatrixTRStore<0b000101, 0b010, "msate32.m">;
def MSATE64_M      : MatrixTRStore<0b000101, 0b011, "msate64.m">;
// Matrix Store B
def MSBE8_M        : MatrixTRStore<0b000010, 0b000, "msbe8.m">;
def MSBE16_M       : MatrixTRStore<0b000010, 0b001, "msbe16.m">;
def MSBE32_M       : MatrixTRStore<0b000010, 0b010, "msbe32.m">;
def MSBE64_M       : MatrixTRStore<0b000010, 0b011, "msbe64.m">;
// Matrix Store B Transposed
def MSBTE8_M       : MatrixTRStore<0b000110, 0b000, "msbte8.m">;
def MSBTE16_M      : MatrixTRStore<0b000110, 0b001, "msbte16.m">;
def MSBTE32_M      : MatrixTRStore<0b000110, 0b010, "msbte32.m">;
def MSBTE64_M      : MatrixTRStore<0b000110, 0b011, "msbte64.m">;
// Matrix Store C
def MSCE8_M        : MatrixTRStore<0b000000, 0b000, "msce8.m">;
def MSCE16_M       : MatrixTRStore<0b000000, 0b001, "msce16.m">;
def MSCE32_M       : MatrixTRStore<0b000000, 0b010, "msce32.m">;
def MSCE64_M       : MatrixTRStore<0b000000, 0b011, "msce64.m">;
// Matrix Store C Transposed
def MSCTE8_M       : MatrixTRStore<0b000100, 0b000, "mscte8.m">;
def MSCTE16_M      : MatrixTRStore<0b000100, 0b001, "mscte16.m">;
def MSCTE32_M      : MatrixTRStore<0b000100, 0b010, "mscte32.m">;
def MSCTE64_M      : MatrixTRStore<0b000100, 0b011, "mscte64.m">;
// Whole Matrix Store
def MSRE8_M        : MatrixTRStore<0b000011, 0b000, "msre8.m">;
def MSRE16_M       : MatrixTRStore<0b000011, 0b001, "msre16.m">;
def MSRE32_M       : MatrixTRStore<0b000011, 0b010, "msre32.m">;
def MSRE64_M       : MatrixTRStore<0b000011, 0b011, "msre64.m">;

// Vector Load Instructions
// Vector Load A
def MLAE8_V        : MatrixVectorLoad<0b100001, 0b000, "mlae8.v">;
def MLAE16_V       : MatrixVectorLoad<0b100001, 0b001, "mlae16.v">;
def MLAE32_V       : MatrixVectorLoad<0b100001, 0b010, "mlae32.v">;
def MLAE64_V       : MatrixVectorLoad<0b100001, 0b011, "mlae64.v">;
// Vector Load B
def MLBE8_V        : MatrixVectorLoad<0b100010, 0b000, "mlbe8.v">;
def MLBE16_V       : MatrixVectorLoad<0b100010, 0b001, "mlbe16.v">;
def MLBE32_V       : MatrixVectorLoad<0b100010, 0b010, "mlbe32.v">;
def MLBE64_V       : MatrixVectorLoad<0b100010, 0b011, "mlbe64.v">;
// Vector Load C
def MLCE8_V        : MatrixVectorLoad<0b100000, 0b000, "mlce8.v">;
def MLCE16_V       : MatrixVectorLoad<0b100000, 0b001, "mlce16.v">;
def MLCE32_V       : MatrixVectorLoad<0b100000, 0b010, "mlce32.v">;
def MLCE64_V       : MatrixVectorLoad<0b100000, 0b011, "mlce64.v">;
// Vector Store A
def MSAE8_V        : MatrixVectorStore<0b100001, 0b000, "msae8.v">;
def MSAE16_V       : MatrixVectorStore<0b100001, 0b001, "msae16.v">;
def MSAE32_V       : MatrixVectorStore<0b100001, 0b010, "msae32.v">;
def MSAE64_V       : MatrixVectorStore<0b100001, 0b011, "msae64.v">;
// Vector Store B
def MSBE8_V        : MatrixVectorStore<0b100010, 0b000, "msbe8.v">;
def MSBE16_V       : MatrixVectorStore<0b100010, 0b001, "msbe16.v">;
def MSBE32_V       : MatrixVectorStore<0b100010, 0b010, "msbe32.v">;
def MSBE64_V       : MatrixVectorStore<0b100010, 0b011, "msbe64.v">;
// Vector Store C
def MSCE8_V        : MatrixVectorStore<0b100000, 0b000, "msce8.v">;
def MSCE16_V       : MatrixVectorStore<0b100000, 0b001, "msce16.v">;
def MSCE32_V       : MatrixVectorStore<0b100000, 0b010, "msce32.v">;
def MSCE64_V       : MatrixVectorStore<0b100000, 0b011, "msce64.v">;

// Matrix Load Unfold Instructions
// Matrix Load Unfold A
def MLUFAE8_M      : MatrixTRULoad<0b110001, 0b000, "mlufae8.m">;
def MLUFAE16_M     : MatrixTRULoad<0b110001, 0b001, "mlufae16.m">;
def MLUFAE32_M     : MatrixTRULoad<0b110001, 0b010, "mlufae32.m">;
def MLUFAE64_M     : MatrixTRULoad<0b110001, 0b011, "mlufae64.m">;
// Matrix Load Unfold B
def MLUFBE8_M      : MatrixTRULoad<0b110010, 0b000, "mlufbe8.m">;
def MLUFBE16_M     : MatrixTRULoad<0b110010, 0b001, "mlufbe16.m">;
def MLUFBE32_M     : MatrixTRULoad<0b110010, 0b010, "mlufbe32.m">;
def MLUFBE64_M     : MatrixTRULoad<0b110010, 0b011, "mlufbe64.m">;
// Matrix Load Unfold C
def MLUFCE8_M      : MatrixTRULoad<0b110000, 0b000, "mlufce8.m">;
def MLUFCE16_M     : MatrixTRULoad<0b110000, 0b001, "mlufce16.m">;
def MLUFCE32_M     : MatrixTRULoad<0b110000, 0b010, "mlufce32.m">;
def MLUFCE64_M     : MatrixTRULoad<0b110000, 0b011, "mlufce64.m">;
// Matrix Store Fold Instructions
// Matrix Store Fold A
def MSFDAE8_M      : MatrixTRUStore<0b110001, 0b000, "msfdae8.m">;
def MSFDAE16_M     : MatrixTRUStore<0b110001, 0b001, "msfdae16.m">;
def MSFDAE32_M     : MatrixTRUStore<0b110001, 0b010, "msfdae32.m">;
def MSFDAE64_M     : MatrixTRUStore<0b110001, 0b011, "msfdae64.m">;
// Matrix Store Fold B
def MSFDBE8_M      : MatrixTRUStore<0b110010, 0b000, "msfdbe8.m">;
def MSFDBE16_M     : MatrixTRUStore<0b110010, 0b001, "msfdbe16.m">;
def MSFDBE32_M     : MatrixTRUStore<0b110010, 0b010, "msfdbe32.m">;
def MSFDBE64_M     : MatrixTRUStore<0b110010, 0b011, "msfdbe64.m">;
// Matrix Store Fold C
def MSFDCE8_M      : MatrixTRUStore<0b110000, 0b000, "msfdce8.m">;
def MSFDCE16_M     : MatrixTRUStore<0b110000, 0b001, "msfdce16.m">;
def MSFDCE32_M     : MatrixTRUStore<0b110000, 0b010, "msfdce32.m">;
def MSFDCE64_M     : MatrixTRUStore<0b110000, 0b011, "msfdce64.m">;

// Data Mov
// Integer to Tile
def MMV_X_S        : MMOVETR2GR<0b000000, "mmv.x.s">;
def MFMV_F_S       : MMOVEFTR2GR<0b000001, "mfmv.f.s">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, Constraints = "$td = $td_wb" in {
def MMV_S_X : RVInstMOVG2T<0b000000, (outs TRR:$td_wb),
                          (ins TRR:$td, GPR:$rs1, GPR:$rs2),
                          "mmv.s.x", "$td, $rs1, $rs2">;
def MFMV_S_F : RVInstMOVG2T<0b000001, (outs TRR:$td_wb),
                            (ins TRR:$td, FPR32:$rs1, GPR:$rs2),
                            "mfmv.s.f", "$td, $rs1, $rs2">;
}

// Broadcast to Tile
def MBCAR_M        : MMOVEBR2TR<0b00001, "mbcar.m">;
def MBCBR_M        : MMOVEBR2TR<0b00010, "mbcbr.m">;
def MBCCR_M        : MMOVEBR2TR<0b00000, "mbccr.m">;
def MBCAC_M        : MMOVEBR2TR<0b00101, "mbcac.m">;
def MBCBC_M        : MMOVEBR2TR<0b00110, "mbcbc.m">;
def MBCCC_M        : MMOVEBR2TR<0b00100, "mbccc.m">;
def MBCAE_M        : MMOVEBR2TR<0b01001, "mbcae.m">;
def MBCBE_M        : MMOVEBR2TR<0b01010, "mbcbe.m">;
def MBCCE_M        : MMOVEBR2TR<0b01000, "mbcce.m">;

// Tile to Vector
def MMVAR_V_M      : MMOVETR2V<0b000101, "mmvar.v.m">;
def MMVAR_M_V      : MMOVEV2TR<0b000101, "mmvar.m.v">;
def MMVBR_V_M      : MMOVETR2V<0b000110, "mmvbr.v.m">;
def MMVBR_M_V      : MMOVEV2TR<0b000110, "mmvbr.m.v">;
def MMVCR_V_M      : MMOVETR2V<0b000100, "mmvcr.v.m">;
def MMVCR_M_V      : MMOVEV2TR<0b000100, "mmvcr.m.v">;
def MMVAC_V_M      : MMOVETR2V<0b001001, "mmvac.v.m">;
def MMVAC_M_V      : MMOVEV2TR<0b001001, "mmvac.m.v">;
def MMVBC_V_M      : MMOVETR2V<0b001010, "mmvbc.v.m">;
def MMVBC_M_V      : MMOVEV2TR<0b001010, "mmvbc.m.v">;
def MMVCC_V_M      : MMOVETR2V<0b001000, "mmvcc.v.m">;
def MMVCC_M_V      : MMOVEV2TR<0b001000, "mmvcc.m.v">;

// Arithmetic

// Matrix multiplication and add
def MMAU_MM    : MALUMM<0b000000, 0, 0, 0, "mmau.mm">;
def MSMAU_MM   : MALUMM<0b000000, 0, 0, 1, "msmau.mm">;
def MMA_MM     : MALUMM<0b000000, 0, 1, 0, "mma.mm">;
def MSMA_MM    : MALUMM<0b000000, 0, 1, 1, "msma.mm">;
def MFMA_MM    : MALUMM<0b000000, 1, 0, 0, "mfma.mm">;
def MWMAU_MM   : MALUMM<0b000001, 0, 0, 0, "mwmau.mm">;
def MSWMAU_MM  : MALUMM<0b000001, 0, 0, 1, "mswmau.mm">;
def MWMA_MM    : MALUMM<0b000001, 0, 1, 0, "mwma.mm">;
def MSWMA_MM   : MALUMM<0b000001, 0, 1, 1, "mswma.mm">;
def MFWMA_MM   : MALUMM<0b000001, 1, 0, 0, "mfwma.mm">;

def MQMAU_MM    : MALUMM<0b000010, 0, 0, 0, "mqmau.mm">;
def MSQMAU_MM   : MALUMM<0b000010, 0, 0, 1, "msqmau.mm">;
def MQMA_MM     : MALUMM<0b000010, 0, 1, 0, "mqma.mm">;
def MSQMA_MM    : MALUMM<0b000010, 0, 1, 1, "msqma.mm">;
def MFQMA_MM    : MALUMM<0b000010, 1, 0, 0, "mfqma.mm">;

// Matrix element-wise add
def MADDU_MM    : MALUMMI<0b000100, 0, 0, 0, "maddu.mm">;
def MSADDU_MM   : MALUMMI<0b000100, 0, 0, 1, "msaddu.mm">;
def MADD_MM     : MALUMMI<0b000100, 0, 1, 0, "madd.mm">;
def MSADD_MM    : MALUMMI<0b000100, 0, 1, 1, "msadd.mm">;
def MFADD_MM    : MALUMMI<0b000100, 1, 0, 0, "mfadd.mm">;

def MWADDU_MM   : MALUMMI<0b000101, 0, 0, 0, "mwaddu.mm">;
def MWADD_MM    : MALUMMI<0b000101, 0, 1, 0, "mwadd.mm">;
def MFWADD_MM   : MALUMMI<0b000101, 1, 0, 0, "mfwadd.mm">;

// Matrix element-wise sub
def MSUBU_MM    : MALUMMI<0b000110, 0, 0, 0, "msubu.mm">;
def MSSUBU_MM   : MALUMMI<0b000110, 0, 0, 1, "mssubu.mm">;
def MSUB_MM     : MALUMMI<0b000110, 0, 1, 0, "msub.mm">;
def MSSUB_MM    : MALUMMI<0b000110, 0, 1, 1, "mssub.mm">;
def MFSUB_MM    : MALUMMI<0b000110, 1, 0, 0, "mfsub.mm">;

def MWSUBU_MM   : MALUMMI<0b000111, 0, 0, 0, "mwsubu.mm">;
def MWSUB_MM    : MALUMMI<0b000111, 0, 1, 0, "mwsub.mm">;
def MFWSUB_MM   : MALUMMI<0b000111, 1, 0, 0, "mfwsub.mm">;

// Matrix min
def MMINU_MM   : MALUMMI<0b001000, 0, 0, 0, "mminu.mm">;
def MMIN_MM    : MALUMMI<0b001000, 0, 1, 0, "mmin.mm">;
def MFMIN_MM   : MALUMMI<0b001000, 1, 0, 0, "mfmin.mm">;
// Matrix max
def MMAXU_MM   : MALUMMI<0b001001, 0, 0, 0, "mmaxu.mm">;
def MMAX_MM    : MALUMMI<0b001001, 0, 1, 0, "mmax.mm">;
def MFMAX_MM   : MALUMMI<0b001001, 1, 0, 0, "mfmax.mm">;

// Matrix mul
def MSMULU_MM  : MALUMMI<0b001010, 0, 0, 1, "msmulu.mm">;
def MMUL_MM    : MALUMMI<0b001010, 0, 1, 0, "mmul.mm">;
def MSMUL_MM   : MALUMMI<0b001010, 0, 1, 1, "msmul.mm">;
def MFMUL_MM   : MALUMMI<0b001010, 1, 0, 0, "mfmul.mm">;

def MMULHU_MM  : MALUMMI<0b001011, 0, 0, 0, "mmulhu.mm">;
def MMULH_MM   : MALUMMI<0b001011, 0, 1, 0, "mmulh.mm">;

def MMULHSU_MM  : MALUMMI<0b001100, 0, 0, 0, "mmulhsu.mm">;
def MSMULSU_MM  : MALUMMI<0b001100, 0, 0, 1, "msmulsu.mm">;

def MWMULU_MM  : MALUMMI<0b001101, 0, 0, 0, "mwmulu.mm">;
def MWMUL_MM   : MALUMMI<0b001101, 0, 1, 0, "mwmul.mm">;
def MWMULSU_MM : MALUMMI<0b001101, 0, 1, 1, "mwmulsu.mm">;
def MFWMUL_MM  : MALUMMI<0b001101, 1, 0, 0, "mfwmul.mm">;

def MFDIV_MM   : MALUMMI<0b001110, 1, 0, 0, "mfdiv.mm">;
def MFSQRT_M  : MALUMMI_UNARY<0b001111, 1, 0, 0, "mfsqrt.m">;

// Matrix cvt
def MFNCVT_F_FW_M   : MFCVTMI<0b010000, 1, "mfncvt.f.fw.m">;
def MFWCVT_FW_F_M   : MFCVTMI<0b010000, 0, "mfwcvt.fw.f.m">;

def MFCVT_F_X_M     : MFCVTMI<0b010010, 1, "mfcvt.f.x.m">;
def MFCVT_X_F_M     : MFCVTMI<0b010010, 0, "mfcvt.x.f.m">;

def MFNCVT_F_XW_M   : MFCVTMI<0b010011, 1, "mfncvt.f.xw.m">;
def MFWCVT_XW_F_M   : MFCVTMI<0b010011, 0, "mfwcvt.xw.f.m">;

def MFNCVT_F_XQ_M   : MFCVTMI<0b010100, 1, "mfncvt.f.xq.m">;
def MFWCVT_XQ_F_M   : MFCVTMI<0b010100, 0, "mfwcvt.xq.f.m">;

def MFWCVT_FW_X_M   : MFCVTMI<0b010101, 1, "mfwcvt.fw.x.m">;
def MFNCVT_X_FW_M   : MFCVTMI<0b010101, 0, "mfncvt.x.fw.m">;

def MFCVT_FW_XW_M   : MFCVTMI<0b010110, 1, "mfcvt.fw.xw.m">;
def MFCVT_XW_FW_M   : MFCVTMI<0b010110, 0, "mfcvt.xw.fw.m">;

def MFNCVT_FW_XQ_M  : MFCVTMI<0b010111, 1, "mfncvt.fw.xq.m">;
def MFWCVT_XQ_FW_M  : MFCVTMI<0b010111, 0, "mfwcvt.xq.fw.m">;

} // Predicates = [HasStdExtMatrix]

include "RISCVInstrInfoMatrixPatterns.td"