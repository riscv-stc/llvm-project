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

def MFieldIAsmOperand : AsmOperandClass {
  let Name = "MFieldI";
  let ParserMethod = "parseMFieldI";
  let DiagnosticType = "InvalidMFieldI";
}

def MFieldIOp :  Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<5>(Imm);}]> {
  let ParserMatchClass = MFieldIAsmOperand;
  let PrintMethod = "printMFieldI";
  let DecoderMethod = "decodeUImmOperand<5>";
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

// Configuration Instructions
let hasSideEffects = 1, mayLoad = 0, mayStore = 0 in {
class MSetRegClass<bits<6> funct6, bits<3> funct3, string opcodestr>
    : RVInstConfig<funct6, funct3,
                   (outs GPR:$rd), (ins GPR:$rs1),
                   opcodestr, "$rd, $rs1"> {
  let rs2 = 0b00000;
  let im = 0b0;
}

class MSetImmClass<bits<6> funct6, bits<3> funct3, string opcodestr>
    : RVInstConfigImm<funct6, funct3,
                      (outs GPR:$rd), (ins uimm10:$imm),
                      opcodestr, "$rd, $imm"> {
  let im = 0b1;
}

class MSetReg2Class<bits<6> funct6, bits<3> funct3, string opcodestr>
    : RVInstConfig<funct6, funct3,
                   (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                   opcodestr, "$rd, $rs1, $rs2"> {
  let im = 0b0;
}

class MSetSewClass<bits<5> field5, string opcodestr>
    :RVInstConfig<0b000000, 0b110,
                  (outs GPR:$rd), (ins uimm5:$rs2),
                  opcodestr, "$rd, $rs2"> {
  let rs1 = field5;
  let im = 0b1;
}

class MSetINTClass<bits<5> setval, string opcodestr>
    :RVInstConfig<0b000000, 0b110,
                  (outs GPR:$rd), (ins uimm5:$rs1),
                  opcodestr, "$rd, $rs1"> {
  let rs2 = setval;
  let im = 0b1;
}

class MSetSPIClass<bits<6> funct6, string opcodestr>
    :RVInstConfig<funct6, 0b111,
                  (outs GPR:$rd), (ins uimm5:$rs1),
                  opcodestr, "$rd, $rs1"> {
  let rs2 = 0b00000;
  let im = 0b1;
}

}

// Load/Store Instructions
let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in {
// load td, (rs1), rs2
class MatrixLoadTRRClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstLoadStore<funct6, eew,
                     (outs TRR:$md),
                     (ins GPR:$rs1, GPR:$rs2), opcodestr,
                     "$md, (${rs1}), $rs2"> {
  let ls = 0b0;
  let tr = 0b0;
}

class MatrixLoadACCRClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstLoadStore<funct6, eew,
                     (outs ACCR:$md),
                     (ins GPR:$rs1, GPR:$rs2), opcodestr,
                     "$md, (${rs1}), $rs2"> {
  let ls = 0b0;
  let tr = 0b0;
}

class MatrixTLoadTRRClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstLoadStore<funct6, eew,
                      (outs TRR:$md),
                      (ins GPR:$rs1, GPR:$rs2), opcodestr,
                      "$md, (${rs1}), $rs2"> {
  let ls = 0b0;
  let tr = 0b1;
}

class MatrixTLoadACCRClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstLoadStore<funct6, eew,
                      (outs ACCR:$md),
                      (ins GPR:$rs1, GPR:$rs2), opcodestr,
                      "$md, (${rs1}), $rs2"> {
  let ls = 0b0;
  let tr = 0b1;
}

// Zmv load
class MatrixZmvExtLoadClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstZmvLoadStore<funct6, eew,
                         (outs VR:$md),
                         (ins GPR:$rs1, GPR:$rs2), opcodestr,
                         "$md, (${rs1}), $rs2"> {
  let ls = 0b0;
}
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in {
// store md, (rs1), rs2
class MatrixStoreTRRClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstLoadStore<funct6, eew, (outs),
                      (ins TRR:$md, GPR:$rs1, GPR:$rs2),
                      opcodestr, "$md, (${rs1}), $rs2"> {
  let ls = 0b1;
  let tr = 0b0;
}

class MatrixStoreACCRClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstLoadStore<funct6, eew, (outs),
                      (ins ACCR:$md, GPR:$rs1, GPR:$rs2),
                      opcodestr, "$md, (${rs1}), $rs2"> {
  let ls = 0b1;
  let tr = 0b0;
}

class MatrixTStoreTRRClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstLoadStore<funct6, eew, (outs),
                      (ins TRR:$md, GPR:$rs1, GPR:$rs2),
                      opcodestr, "$md, (${rs1}), $rs2"> {
  let ls = 0b1;
  let tr = 0b1;
}

class MatrixTStoreACCRClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstLoadStore<funct6, eew, (outs),
                      (ins ACCR:$md, GPR:$rs1, GPR:$rs2),
                      opcodestr, "$md, (${rs1}), $rs2"> {
  let ls = 0b1;
  let tr = 0b1;
}

// Zmv store
class MatrixZmvExtStoreClass<bits<6> funct6, bits<3> eew, string opcodestr>
    : RVInstZmvLoadStore<funct6, eew, (outs),
                         (ins VR:$md, GPR:$rs1, GPR:$rs2),
                         opcodestr, "$md, (${rs1}), $rs2"> {
  let ls = 0b1;
}
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in {

class MatrixDataMoveClass<bits<6> funct6, bits<3> eew, bit d, RegisterClass OUTR,
                          RegisterClass INR, string opcodestr>
    : RVInstDataMove<funct6, eew, (outs OUTR:$rd),
                     (ins INR:$rs1, GPR:$rs2),
                     opcodestr, "$rd, $rs1, $rs2"> {
  let di = d;
}

let Constraints = "$rd = $rd_wb" in
class MatrixDataMoveScaleClass<bits<6> funct6, bits<3> eew, bit d, RegisterClass OUTR,
                          RegisterClass INR, string opcodestr>
    : RVInstDataMove<funct6, eew, (outs OUTR:$rd_wb),
                     (ins OUTR:$rd, INR:$rs1, GPR:$rs2),
                     opcodestr, "$rd, $rs1, $rs2"> {
  let di = d;
}

class MatrixDataMoveImmClass<bits<3> eew, bit d, RegisterClass OUTR,
                             RegisterClass INR, string opcodestr>
    : RVInstDataMove<0b000100, eew, (outs OUTR:$rd),
                     (ins INR:$rs1, uimm5:$rs2),
                     opcodestr, "$rd, $rs1, $rs2"> {
  let di = d;
}

class MatrixDataMoveTwoAddrClass<bits<3> eew, bits<5> rs2addr,
                                 RegisterClass RType, string opcodestr>
    : RVInstDataMove<0b000111, eew, (outs RType:$rd),
                     (ins RType:$rs1),
                     opcodestr, "$rd, $rs1"> {
  let di = 0b0;
  let rs2 = rs2addr;
}

class MatrixZmvExtM2VClass<bits<6> funct6, bits<3> eew, bit rs1var,
                                   RegisterClass RType, string opcodestr>
    : RVInstZmvM2V<funct6, eew, (outs VR:$rd),
                   (ins RType:$rs1, GPR:$rs2),
                   opcodestr, "$rd, $rs1, $rs2"> {
  let di = 0b0;
  let var = rs1var;
}

class MatrixZmvExtV2MClass<bits<6> funct6, bits<3> eew, bit rdvar,
                                   RegisterClass RType, string opcodestr>
    : RVInstZmvV2M<funct6, eew, (outs RType:$rd),
                   (ins VR:$rs1, GPR:$rs2),
                   opcodestr, "$rd, $rs1, $rs2"> {
  let di = 0b1;
  let var = rdvar;
}

let Constraints = "$md = $md_wb" in
class MatrixMULClass<bits<6> funct6, bits<3> eew, bit fp, bit sa, bit sn,
                     RegisterClass RType, string opcodestr>
    : RVInstMatrixMUL<funct6, eew, fp, sa, sn, 0b1, (outs RType:$md_wb),
                      (ins RType:$md, TRR:$ms1, TRR:$ms2),
                      opcodestr, "$md, $ms1, $ms2">;

let Constraints = "$md = $md_wb" in
class MatrixMULSPAClass<bits<6> funct6, bits<3> eew, bit fp, bit sa, bit sn,
                        bit sp, string opcodestr>
    : RVInstMatrixMUL<funct6, eew, fp, sa, sn, sp, (outs ACCR:$md_wb),
                      (ins ACCR:$md, TRR:$ms1, TRR:$ms2),
                      opcodestr, "$md, $ms1, $ms2">;

class MatrixEletwiseClass<bits<6> funct6, bits<3> eew, bit fp, bit sa, bit sn,
                          bit ma, string opcodestr>
    : RVInstMatrixMUL<funct6, eew, fp, sa, sn, ma, (outs ACCR:$md),
                      (ins ACCR:$ms1, ACCR:$ms2),
                      opcodestr, "$md, $ms1, $ms2">;

class MatrixEletwiseTwoAddrClass<bits<6> funct6, bits<3> eew, bit fp, bit sa,
                                 bit sn, bit ma, string opcodestr>
    : RVInstMatrixMUL<funct6, eew, fp, sa, sn, ma, (outs ACCR:$md),
                      (ins ACCR:$ms1),
                      opcodestr, "$md, $ms1"> {
  let ms2 = 0b0000;
}

class MatrixTypeCvtClass<bits<6> funct6, bits<3> eew, bit fd, bits<3> f3,
                         bits<2> nw, bit sn, bit ma, string opcodestr>
    : RVInstMatrixTypeCvt<funct6, eew, fd, f3, nw, sn, ma, (outs ACCR:$md),
                          (ins ACCR:$ms1), opcodestr, "$md, $ms1">;
}

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtMatrix] in {
// Configuration Instructions
def MSETTYPE   : MSetRegClass<0b000000, 0b100, "msettype">;
def MSETTYPEI  : MSetImmClass<0b000000, 0b100, "msettypei">;
def MSETTYPEHI : MSetImmClass<0b000000, 0b101, "msettypehi">;
def MSETSEW    : MSetSewClass<0b00000, "msetsew">;
def MSETINT4   : MSetSewClass<0b00001, "msetint4">;
def MSETINT8   : MSetSewClass<0b00010, "msetint8">;
def MSETINT16  : MSetSewClass<0b00011, "msetint16">;
def MSETINT32  : MSetSewClass<0b00100, "msetint32">;
def MSETINT64  : MSetSewClass<0b00101, "msetint64">;
def MSETFP8    : MSetSewClass<0b00110, "msetfp8">;
def MSETFP16   : MSetSewClass<0b00111, "msetfp16">;
def MSETFP32   : MSetSewClass<0b01000, "msetfp32">;
def MSETFP64   : MSetSewClass<0b01001, "msetfp64">;
def MSETBA     : MSetSewClass<0b01010, "msetba">;

def MSETTILEM  : MSetRegClass<0b000001, 0b101, "msettilem">;
def MSETTILEMI : MSetImmClass<0b000001, 0b101, "msettilemi">;
def MSETTILEK  : MSetRegClass<0b000001, 0b110, "msettilek">;
def MSETTILEKI : MSetImmClass<0b000001, 0b110, "msettileki">;
def MSETTILEN  : MSetRegClass<0b000001, 0b100, "msettilen">;
def MSETTILENI : MSetImmClass<0b000001, 0b100, "msettileni">;

def MSETTSPI  : MSetSPIClass<0b000000, "msettspi">;
def MSETTSP   : MSetRegClass<0b000000,  0b111, "msettsp">;
def MSETDSPI  : MSetSPIClass<0b000001, "msetdspi">;
def MSETDSP   : MSetRegClass<0b000001,  0b111, "msetdsp">;

def MSETOUTSH : MSetReg2Class<0b000010, 0b100, "msetoutsh">;
def MSETINSH  : MSetReg2Class<0b000010, 0b101, "msetinsh">;
def MSETSK    : MSetReg2Class<0b000010, 0b110, "msetsk">;
def MSETPADVAL: MSetRegClass<0b000010,  0b111, "msetpadval">;

// Load/Store Instructions
def MLAE8_M  : MatrixLoadTRRClass<0b000001, 0b000, "mlae8.m">;
def MLAE16_M : MatrixLoadTRRClass<0b000001, 0b001, "mlae16.m">;
def MLAE32_M : MatrixLoadTRRClass<0b000001, 0b010, "mlae32.m">;
def MLAE64_M : MatrixLoadTRRClass<0b000001, 0b011, "mlae64.m">;
def MLBE8_M  : MatrixLoadTRRClass<0b000010, 0b000, "mlbe8.m">;
def MLBE16_M : MatrixLoadTRRClass<0b000010, 0b001, "mlbe16.m">;
def MLBE32_M : MatrixLoadTRRClass<0b000010, 0b010, "mlbe32.m">;
def MLBE64_M : MatrixLoadTRRClass<0b000010, 0b011, "mlbe64.m">;
def MLCE8_M  : MatrixLoadACCRClass<0b000000, 0b000, "mlce8.m">;
def MLCE16_M : MatrixLoadACCRClass<0b000000, 0b001, "mlce16.m">;
def MLCE32_M : MatrixLoadACCRClass<0b000000, 0b010, "mlce32.m">;
def MLCE64_M : MatrixLoadACCRClass<0b000000, 0b011, "mlce64.m">;
def MLTRE8_M : MatrixLoadTRRClass<0b000011, 0b000, "mltre8.m">;
def MLTRE16_M: MatrixLoadTRRClass<0b000011, 0b001, "mltre16.m">;
def MLTRE32_M: MatrixLoadTRRClass<0b000011, 0b010, "mltre32.m">;
def MLTRE64_M: MatrixLoadTRRClass<0b000011, 0b011, "mltre64.m">;

def MLATE8_M  : MatrixTLoadTRRClass<0b000001, 0b000, "mlate8.m">;
def MLATE16_M : MatrixTLoadTRRClass<0b000001, 0b001, "mlate16.m">;
def MLATE32_M : MatrixTLoadTRRClass<0b000001, 0b010, "mlate32.m">;
def MLATE64_M : MatrixTLoadTRRClass<0b000001, 0b011, "mlate64.m">;
def MLBTE8_M  : MatrixTLoadTRRClass<0b000010, 0b000, "mlbte8.m">;
def MLBTE16_M : MatrixTLoadTRRClass<0b000010, 0b001, "mlbte16.m">;
def MLBTE32_M : MatrixTLoadTRRClass<0b000010, 0b010, "mlbte32.m">;
def MLBTE64_M : MatrixTLoadTRRClass<0b000010, 0b011, "mlbte64.m">;
def MLCTE8_M  : MatrixTLoadACCRClass<0b000000, 0b000, "mlcte8.m">;
def MLCTE16_M : MatrixTLoadACCRClass<0b000000, 0b001, "mlcte16.m">;
def MLCTE32_M : MatrixTLoadACCRClass<0b000000, 0b010, "mlcte32.m">;
def MLCTE64_M : MatrixTLoadACCRClass<0b000000, 0b011, "mlcte64.m">;
def MLACCE8_M : MatrixTLoadACCRClass<0b000011, 0b000, "mlacce8.m">;
def MLACCE16_M: MatrixTLoadACCRClass<0b000011, 0b001, "mlacce16.m">;
def MLACCE32_M: MatrixTLoadACCRClass<0b000011, 0b010, "mlacce32.m">;
def MLACCE64_M: MatrixTLoadACCRClass<0b000011, 0b011, "mlacce64.m">;

def MSAE8_M  : MatrixStoreTRRClass<0b000001, 0b000, "msae8.m">;
def MSAE16_M : MatrixStoreTRRClass<0b000001, 0b001, "msae16.m">;
def MSAE32_M : MatrixStoreTRRClass<0b000001, 0b010, "msae32.m">;
def MSAE64_M : MatrixStoreTRRClass<0b000001, 0b011, "msae64.m">;
def MSBE8_M  : MatrixStoreTRRClass<0b000010, 0b000, "msbe8.m">;
def MSBE16_M : MatrixStoreTRRClass<0b000010, 0b001, "msbe16.m">;
def MSBE32_M : MatrixStoreTRRClass<0b000010, 0b010, "msbe32.m">;
def MSBE64_M : MatrixStoreTRRClass<0b000010, 0b011, "msbe64.m">;
def MSCE8_M  : MatrixStoreACCRClass<0b000000, 0b000, "msce8.m">;
def MSCE16_M : MatrixStoreACCRClass<0b000000, 0b001, "msce16.m">;
def MSCE32_M : MatrixStoreACCRClass<0b000000, 0b010, "msce32.m">;
def MSCE64_M : MatrixStoreACCRClass<0b000000, 0b011, "msce64.m">;
def MSTRE8_M : MatrixStoreTRRClass<0b000011, 0b000, "mstre8.m">;
def MSTRE16_M: MatrixStoreTRRClass<0b000011, 0b001, "mstre16.m">;
def MSTRE32_M: MatrixStoreTRRClass<0b000011, 0b010, "mstre32.m">;
def MSTRE64_M: MatrixStoreTRRClass<0b000011, 0b011, "mstre64.m">;

def MSATE8_M  : MatrixTStoreTRRClass<0b000001, 0b000, "msate8.m">;
def MSATE16_M : MatrixTStoreTRRClass<0b000001, 0b001, "msate16.m">;
def MSATE32_M : MatrixTStoreTRRClass<0b000001, 0b010, "msate32.m">;
def MSATE64_M : MatrixTStoreTRRClass<0b000001, 0b011, "msate64.m">;
def MSBTE8_M  : MatrixTStoreTRRClass<0b000010, 0b000, "msbte8.m">;
def MSBTE16_M : MatrixTStoreTRRClass<0b000010, 0b001, "msbte16.m">;
def MSBTE32_M : MatrixTStoreTRRClass<0b000010, 0b010, "msbte32.m">;
def MSBTE64_M : MatrixTStoreTRRClass<0b000010, 0b011, "msbte64.m">;
def MSCTE8_M  : MatrixTStoreACCRClass<0b000000, 0b000, "mscte8.m">;
def MSCTE16_M : MatrixTStoreACCRClass<0b000000, 0b001, "mscte16.m">;
def MSCTE32_M : MatrixTStoreACCRClass<0b000000, 0b010, "mscte32.m">;
def MSCTE64_M : MatrixTStoreACCRClass<0b000000, 0b011, "mscte64.m">;
def MSACCE8_M : MatrixTStoreACCRClass<0b000011, 0b000, "msacce8.m">;
def MSACCE16_M: MatrixTStoreACCRClass<0b000011, 0b001, "msacce16.m">;
def MSACCE32_M: MatrixTStoreACCRClass<0b000011, 0b010, "msacce32.m">;
def MSACCE64_M: MatrixTStoreACCRClass<0b000011, 0b011, "msacce64.m">;

def MLAE8_V  : MatrixZmvExtLoadClass<0b100001, 0b000, "mlae8.v">;
def MLAE16_V : MatrixZmvExtLoadClass<0b100001, 0b001, "mlae16.v">;
def MLAE32_V : MatrixZmvExtLoadClass<0b100001, 0b010, "mlae32.v">;
def MLAE64_V : MatrixZmvExtLoadClass<0b100001, 0b011, "mlae64.v">;
def MLBE8_V  : MatrixZmvExtLoadClass<0b100010, 0b000, "mlbe8.v">;
def MLBE16_V : MatrixZmvExtLoadClass<0b100010, 0b001, "mlbe16.v">;
def MLBE32_V : MatrixZmvExtLoadClass<0b100010, 0b010, "mlbe32.v">;
def MLBE64_V : MatrixZmvExtLoadClass<0b100010, 0b011, "mlbe64.v">;
def MLCE8_V  : MatrixZmvExtLoadClass<0b100000, 0b000, "mlce8.v">;
def MLCE16_V : MatrixZmvExtLoadClass<0b100000, 0b001, "mlce16.v">;
def MLCE32_V : MatrixZmvExtLoadClass<0b100000, 0b010, "mlce32.v">;
def MLCE64_V : MatrixZmvExtLoadClass<0b100000, 0b011, "mlce64.v">;

def MSAE8_V  : MatrixZmvExtStoreClass<0b100001, 0b000, "msae8.v">;
def MSAE16_V : MatrixZmvExtStoreClass<0b100001, 0b001, "msae16.v">;
def MSAE32_V : MatrixZmvExtStoreClass<0b100001, 0b010, "msae32.v">;
def MSAE64_V : MatrixZmvExtStoreClass<0b100001, 0b011, "msae64.v">;
def MSBE8_V  : MatrixZmvExtStoreClass<0b100010, 0b000, "msbe8.v">;
def MSBE16_V : MatrixZmvExtStoreClass<0b100010, 0b001, "msbe16.v">;
def MSBE32_V : MatrixZmvExtStoreClass<0b100010, 0b010, "msbe32.v">;
def MSBE64_V : MatrixZmvExtStoreClass<0b100010, 0b011, "msbe64.v">;
def MSCE8_V  : MatrixZmvExtStoreClass<0b100000, 0b000, "msce8.v">;
def MSCE16_V : MatrixZmvExtStoreClass<0b100000, 0b001, "msce16.v">;
def MSCE32_V : MatrixZmvExtStoreClass<0b100000, 0b010, "msce32.v">;
def MSCE64_V : MatrixZmvExtStoreClass<0b100000, 0b011, "msce64.v">;

def MLUFAE8_M  : MatrixLoadTRRClass<0b100001, 0b100, "mlufae8.m">;
def MLUFAE16_M : MatrixLoadTRRClass<0b100001, 0b101, "mlufae16.m">;
def MLUFAE32_M : MatrixLoadTRRClass<0b100001, 0b110, "mlufae32.m">;
def MLUFAE64_M : MatrixLoadTRRClass<0b100001, 0b111, "mlufae64.m">;
def MLUFBE8_M  : MatrixLoadTRRClass<0b100010, 0b100, "mlufbe8.m">;
def MLUFBE16_M : MatrixLoadTRRClass<0b100010, 0b101, "mlufbe16.m">;
def MLUFBE32_M : MatrixLoadTRRClass<0b100010, 0b110, "mlufbe32.m">;
def MLUFBE64_M : MatrixLoadTRRClass<0b100010, 0b111, "mlufbe64.m">;
def MLUFCE8_M  : MatrixLoadACCRClass<0b100000, 0b100, "mlufce8.m">;
def MLUFCE16_M : MatrixLoadACCRClass<0b100000, 0b101, "mlufce16.m">;
def MLUFCE32_M : MatrixLoadACCRClass<0b100000, 0b110, "mlufce32.m">;
def MLUFCE64_M : MatrixLoadACCRClass<0b100000, 0b111, "mlufce64.m">;

def MSFDAE8_M  : MatrixStoreTRRClass<0b100001, 0b100, "msfdae8.m">;
def MSFDAE16_M : MatrixStoreTRRClass<0b100001, 0b101, "msfdae16.m">;
def MSFDAE32_M : MatrixStoreTRRClass<0b100001, 0b110, "msfdae32.m">;
def MSFDAE64_M : MatrixStoreTRRClass<0b100001, 0b111, "msfdae64.m">;
def MSFDBE8_M  : MatrixStoreTRRClass<0b100010, 0b100, "msfdbe8.m">;
def MSFDBE16_M : MatrixStoreTRRClass<0b100010, 0b101, "msfdbe16.m">;
def MSFDBE32_M : MatrixStoreTRRClass<0b100010, 0b110, "msfdbe32.m">;
def MSFDBE64_M : MatrixStoreTRRClass<0b100010, 0b111, "msfdbe64.m">;
def MSFDCE8_M  : MatrixStoreACCRClass<0b100000, 0b100, "msfdce8.m">;
def MSFDCE16_M : MatrixStoreACCRClass<0b100000, 0b101, "msfdce16.m">;
def MSFDCE32_M : MatrixStoreACCRClass<0b100000, 0b110, "msfdce32.m">;
def MSFDCE64_M : MatrixStoreACCRClass<0b100000, 0b111, "msfdce64.m">;

// Data Move Instructions
def MMVE8_A_T  : MatrixDataMoveClass<0b000100, 0b000, 0b0, ACCR, TRR, "mmve8.a.t">;
def MMVE16_A_T : MatrixDataMoveClass<0b000100, 0b001, 0b0, ACCR, TRR, "mmve16.a.t">;
def MMVE32_A_T : MatrixDataMoveClass<0b000100, 0b010, 0b0, ACCR, TRR, "mmve32.a.t">;
def MMVE64_A_T : MatrixDataMoveClass<0b000100, 0b011, 0b0, ACCR, TRR, "mmve64.a.t">;
def MMVE8_T_A  : MatrixDataMoveClass<0b000100, 0b000, 0b1, TRR, ACCR, "mmve8.t.a">;
def MMVE16_T_A : MatrixDataMoveClass<0b000100, 0b001, 0b1, TRR, ACCR, "mmve16.t.a">;
def MMVE32_T_A : MatrixDataMoveClass<0b000100, 0b010, 0b1, TRR, ACCR, "mmve32.t.a">;
def MMVE64_T_A : MatrixDataMoveClass<0b000100, 0b011, 0b1, TRR, ACCR, "mmve64.t.a">;

def MMVIE8_A_T  : MatrixDataMoveImmClass<0b100, 0b0, ACCR, TRR, "mmvie8.a.t">;
def MMVIE16_A_T : MatrixDataMoveImmClass<0b101, 0b0, ACCR, TRR, "mmvie16.a.t">;
def MMVIE32_A_T : MatrixDataMoveImmClass<0b110, 0b0, ACCR, TRR, "mmvie32.a.t">;
def MMVIE64_A_T : MatrixDataMoveImmClass<0b111, 0b0, ACCR, TRR, "mmvie64.a.t">;
def MMVIE8_T_A  : MatrixDataMoveImmClass<0b100, 0b1, TRR, ACCR, "mmvie8.t.a">;
def MMVIE16_T_A : MatrixDataMoveImmClass<0b101, 0b1, TRR, ACCR, "mmvie16.t.a">;
def MMVIE32_T_A : MatrixDataMoveImmClass<0b110, 0b1, TRR, ACCR, "mmvie32.t.a">;
def MMVIE64_T_A : MatrixDataMoveImmClass<0b111, 0b1, TRR, ACCR, "mmvie64.t.a">;

def MMVE8_X_T  : MatrixDataMoveClass<0b000101, 0b000, 0b0, GPR, TRR, "mmve8.x.t">;
def MMVE16_X_T : MatrixDataMoveClass<0b000101, 0b001, 0b0, GPR, TRR, "mmve16.x.t">;
def MMVE32_X_T : MatrixDataMoveClass<0b000101, 0b010, 0b0, GPR, TRR, "mmve32.x.t">;
def MMVE64_X_T : MatrixDataMoveClass<0b000101, 0b011, 0b0, GPR, TRR, "mmve64.x.t">;
def MMVE8_T_X  : MatrixDataMoveScaleClass<0b000101, 0b000, 0b1, TRR, GPR, "mmve8.t.x">;
def MMVE16_T_X : MatrixDataMoveScaleClass<0b000101, 0b001, 0b1, TRR, GPR, "mmve16.t.x">;
def MMVE32_T_X : MatrixDataMoveScaleClass<0b000101, 0b010, 0b1, TRR, GPR, "mmve32.t.x">;
def MMVE64_T_X : MatrixDataMoveScaleClass<0b000101, 0b011, 0b1, TRR, GPR, "mmve64.t.x">;

def MMVE8_X_A  : MatrixDataMoveClass<0b000101, 0b100, 0b0, GPR, ACCR, "mmve8.x.a">;
def MMVE16_X_A : MatrixDataMoveClass<0b000101, 0b101, 0b0, GPR, ACCR, "mmve16.x.a">;
def MMVE32_X_A : MatrixDataMoveClass<0b000101, 0b110, 0b0, GPR, ACCR, "mmve32.x.a">;
def MMVE64_X_A : MatrixDataMoveClass<0b000101, 0b111, 0b0, GPR, ACCR, "mmve64.x.a">;
def MMVE8_A_X  : MatrixDataMoveScaleClass<0b000101, 0b100, 0b1, ACCR, GPR, "mmve8.a.x">;
def MMVE16_A_X : MatrixDataMoveScaleClass<0b000101, 0b101, 0b1, ACCR, GPR, "mmve16.a.x">;
def MMVE32_A_X : MatrixDataMoveScaleClass<0b000101, 0b110, 0b1, ACCR, GPR, "mmve32.a.x">;
def MMVE64_A_X : MatrixDataMoveScaleClass<0b000101, 0b111, 0b1, ACCR, GPR, "mmve64.a.x">;

def MFMVE8_F_T  : MatrixDataMoveClass<0b000110, 0b000, 0b0, FPR32, TRR, "mfmve8.f.t">;
def MFMVE16_F_T : MatrixDataMoveClass<0b000110, 0b001, 0b0, FPR16, TRR, "mfmve16.f.t">;
def MFMVE32_F_T : MatrixDataMoveClass<0b000110, 0b010, 0b0, FPR32, TRR, "mfmve32.f.t">;
def MFMVE64_F_T : MatrixDataMoveClass<0b000110, 0b011, 0b0, FPR64, TRR, "mfmve64.f.t">;
def MFMVE8_T_F  : MatrixDataMoveScaleClass<0b000110, 0b000, 0b1, TRR, FPR32, "mfmve8.t.f">;
def MFMVE16_T_F : MatrixDataMoveScaleClass<0b000110, 0b001, 0b1, TRR, FPR16, "mfmve16.t.f">;
def MFMVE32_T_F : MatrixDataMoveScaleClass<0b000110, 0b010, 0b1, TRR, FPR32, "mfmve32.t.f">;
def MFMVE64_T_F : MatrixDataMoveScaleClass<0b000110, 0b011, 0b1, TRR, FPR64, "mfmve64.t.f">;

def MFMVE8_F_A  : MatrixDataMoveClass<0b000110, 0b100, 0b0, FPR32, ACCR, "mfmve8.f.a">;
def MFMVE16_F_A : MatrixDataMoveClass<0b000110, 0b101, 0b0, FPR16, ACCR, "mfmve16.f.a">;
def MFMVE32_F_A : MatrixDataMoveClass<0b000110, 0b110, 0b0, FPR32, ACCR, "mfmve32.f.a">;
def MFMVE64_F_A : MatrixDataMoveClass<0b000110, 0b111, 0b0, FPR64, ACCR, "mfmve64.f.a">;
def MFMVE8_A_F  : MatrixDataMoveScaleClass<0b000110, 0b100, 0b1, ACCR, FPR32, "mfmve8.a.f">;
def MFMVE16_A_F : MatrixDataMoveScaleClass<0b000110, 0b101, 0b1, ACCR, FPR16, "mfmve16.a.f">;
def MFMVE32_A_F : MatrixDataMoveScaleClass<0b000110, 0b110, 0b1, ACCR, FPR32, "mfmve32.a.f">;
def MFMVE64_A_F : MatrixDataMoveScaleClass<0b000110, 0b111, 0b1, ACCR, FPR64, "mfmve64.a.f">;

def MMVE8_T_T  : MatrixDataMoveTwoAddrClass<0b000, 0b00000, TRR, "mmve8.t.t">;
def MMVE16_T_T : MatrixDataMoveTwoAddrClass<0b001, 0b00000, TRR, "mmve16.t.t">;
def MMVE32_T_T : MatrixDataMoveTwoAddrClass<0b010, 0b00000, TRR, "mmve32.t.t">;
def MMVE64_T_T : MatrixDataMoveTwoAddrClass<0b011, 0b00000, TRR, "mmve64.t.t">;

def MMVE8_A_A  : MatrixDataMoveTwoAddrClass<0b000, 0b00001, ACCR, "mmve8.a.a">;
def MMVE16_A_A : MatrixDataMoveTwoAddrClass<0b001, 0b00001, ACCR, "mmve16.a.a">;
def MMVE32_A_A : MatrixDataMoveTwoAddrClass<0b010, 0b00001, ACCR, "mmve32.a.a">;
def MMVE64_A_A : MatrixDataMoveTwoAddrClass<0b011, 0b00001, ACCR, "mmve64.a.a">;

def MBCAR_M : MatrixDataMoveTwoAddrClass<0b000, 0b10001, TRR,  "mbcar.m">;
def MBCBR_M : MatrixDataMoveTwoAddrClass<0b000, 0b10010, TRR,  "mbcbr.m">;
def MBCCR_M : MatrixDataMoveTwoAddrClass<0b000, 0b10000, ACCR, "mbccr.m">;

def MBCACE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b10101, TRR, "mbcace8.m">;
def MBCACE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b10101, TRR, "mbcace16.m">;
def MBCACE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b10101, TRR, "mbcace32.m">;
def MBCACE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b10101, TRR, "mbcace64.m">;
def MBCBCE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b10110, TRR, "mbcbce8.m">;
def MBCBCE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b10110, TRR, "mbcbce16.m">;
def MBCBCE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b10110, TRR, "mbcbce32.m">;
def MBCBCE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b10110, TRR, "mbcbce64.m">;
def MBCCCE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b10100, ACCR, "mbccce8.m">;
def MBCCCE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b10100, ACCR, "mbccce16.m">;
def MBCCCE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b10100, ACCR, "mbccce32.m">;
def MBCCCE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b10100, ACCR, "mbccce64.m">;

def MBCAEE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b11001, TRR, "mbcaee8.m">;
def MBCAEE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b11001, TRR, "mbcaee16.m">;
def MBCAEE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b11001, TRR, "mbcaee32.m">;
def MBCAEE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b11001, TRR, "mbcaee64.m">;
def MBCBEE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b11010, TRR, "mbcbee8.m">;
def MBCBEE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b11010, TRR, "mbcbee16.m">;
def MBCBEE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b11010, TRR, "mbcbee32.m">;
def MBCBEE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b11010, TRR, "mbcbee64.m">;
def MBCCEE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b11000, ACCR, "mbccee8.m">;
def MBCCEE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b11000, ACCR, "mbccee16.m">;
def MBCCEE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b11000, ACCR, "mbccee32.m">;
def MBCCEE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b11000, ACCR, "mbccee64.m">;

def MTAE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b11101, TRR, "mtae8.m">;
def MTAE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b11101, TRR, "mtae16.m">;
def MTAE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b11101, TRR, "mtae32.m">;
def MTAE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b11101, TRR, "mtae64.m">;
def MTBE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b11110, TRR, "mtbe8.m">;
def MTBE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b11110, TRR, "mtbe16.m">;
def MTBE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b11110, TRR, "mtbe32.m">;
def MTBE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b11110, TRR, "mtbe64.m">;
def MTCE8_M  : MatrixDataMoveTwoAddrClass<0b000, 0b11100, ACCR, "mtce8.m">;
def MTCE16_M : MatrixDataMoveTwoAddrClass<0b001, 0b11100, ACCR, "mtce16.m">;
def MTCE32_M : MatrixDataMoveTwoAddrClass<0b010, 0b11100, ACCR, "mtce32.m">;
def MTCE64_M : MatrixDataMoveTwoAddrClass<0b011, 0b11100, ACCR, "mtce64.m">;

// Zmv Extension Data Move Instructions
def MMVARE8_V_M  : MatrixZmvExtM2VClass<0b100110, 0b100, 0b0, TRR, "mmvare8.v.m">;
def MMVARE16_V_M : MatrixZmvExtM2VClass<0b100110, 0b101, 0b0, TRR, "mmvare16.v.m">;
def MMVARE32_V_M : MatrixZmvExtM2VClass<0b100110, 0b110, 0b0, TRR, "mmvare32.v.m">;
def MMVARE64_V_M : MatrixZmvExtM2VClass<0b100110, 0b111, 0b0, TRR, "mmvare64.v.m">;
def MMVBRE8_V_M  : MatrixZmvExtM2VClass<0b100110, 0b100, 0b1, TRR, "mmvbre8.v.m">;
def MMVBRE16_V_M : MatrixZmvExtM2VClass<0b100110, 0b101, 0b1, TRR, "mmvbre16.v.m">;
def MMVBRE32_V_M : MatrixZmvExtM2VClass<0b100110, 0b110, 0b1, TRR, "mmvbre32.v.m">;
def MMVBRE64_V_M : MatrixZmvExtM2VClass<0b100110, 0b111, 0b1, TRR, "mmvbre64.v.m">;
def MMVCRE8_V_M  : MatrixZmvExtM2VClass<0b100110, 0b000, 0b0, ACCR, "mmvcre8.v.m">;
def MMVCRE16_V_M : MatrixZmvExtM2VClass<0b100110, 0b001, 0b0, ACCR, "mmvcre16.v.m">;
def MMVCRE32_V_M : MatrixZmvExtM2VClass<0b100110, 0b010, 0b0, ACCR, "mmvcre32.v.m">;
def MMVCRE64_V_M : MatrixZmvExtM2VClass<0b100110, 0b011, 0b0, ACCR, "mmvcre64.v.m">;

def MMVARE8_M_V  : MatrixZmvExtV2MClass<0b100110, 0b100, 0b0, TRR, "mmvare8.m.v">;
def MMVARE16_M_V : MatrixZmvExtV2MClass<0b100110, 0b101, 0b0, TRR, "mmvare16.m.v">;
def MMVARE32_M_V : MatrixZmvExtV2MClass<0b100110, 0b110, 0b0, TRR, "mmvare32.m.v">;
def MMVARE64_M_V : MatrixZmvExtV2MClass<0b100110, 0b111, 0b0, TRR, "mmvare64.m.v">;
def MMVBRE8_M_V  : MatrixZmvExtV2MClass<0b100110, 0b100, 0b1, TRR, "mmvbre8.m.v">;
def MMVBRE16_M_V : MatrixZmvExtV2MClass<0b100110, 0b101, 0b1, TRR, "mmvbre16.m.v">;
def MMVBRE32_M_V : MatrixZmvExtV2MClass<0b100110, 0b110, 0b1, TRR, "mmvbre32.m.v">;
def MMVBRE64_M_V : MatrixZmvExtV2MClass<0b100110, 0b111, 0b1, TRR, "mmvbre64.m.v">;
def MMVCRE8_M_V  : MatrixZmvExtV2MClass<0b100110, 0b000, 0b0, ACCR, "mmvcre8.m.v">;
def MMVCRE16_M_V : MatrixZmvExtV2MClass<0b100110, 0b001, 0b0, ACCR, "mmvcre16.m.v">;
def MMVCRE32_M_V : MatrixZmvExtV2MClass<0b100110, 0b010, 0b0, ACCR, "mmvcre32.m.v">;
def MMVCRE64_M_V : MatrixZmvExtV2MClass<0b100110, 0b011, 0b0, ACCR, "mmvcre64.m.v">;

def MMVACE8_V_M  : MatrixZmvExtM2VClass<0b100111, 0b100, 0b0, TRR, "mmvace8.v.m">;
def MMVACE16_V_M : MatrixZmvExtM2VClass<0b100111, 0b101, 0b0, TRR, "mmvace16.v.m">;
def MMVACE32_V_M : MatrixZmvExtM2VClass<0b100111, 0b110, 0b0, TRR, "mmvace32.v.m">;
def MMVACE64_V_M : MatrixZmvExtM2VClass<0b100111, 0b111, 0b0, TRR, "mmvace64.v.m">;
def MMVBCE8_V_M  : MatrixZmvExtM2VClass<0b100111, 0b100, 0b1, TRR, "mmvbce8.v.m">;
def MMVBCE16_V_M : MatrixZmvExtM2VClass<0b100111, 0b101, 0b1, TRR, "mmvbce16.v.m">;
def MMVBCE32_V_M : MatrixZmvExtM2VClass<0b100111, 0b110, 0b1, TRR, "mmvbce32.v.m">;
def MMVBCE64_V_M : MatrixZmvExtM2VClass<0b100111, 0b111, 0b1, TRR, "mmvbce64.v.m">;
def MMVCCE8_V_M  : MatrixZmvExtM2VClass<0b100111, 0b000, 0b0, ACCR, "mmvcce8.v.m">;
def MMVCCE16_V_M : MatrixZmvExtM2VClass<0b100111, 0b001, 0b0, ACCR, "mmvcce16.v.m">;
def MMVCCE32_V_M : MatrixZmvExtM2VClass<0b100111, 0b010, 0b0, ACCR, "mmvcce32.v.m">;
def MMVCCE64_V_M : MatrixZmvExtM2VClass<0b100111, 0b011, 0b0, ACCR, "mmvcce64.v.m">;

def MMVACE8_M_V  : MatrixZmvExtV2MClass<0b100111, 0b100, 0b0, TRR, "mmvace8.m.v">;
def MMVACE16_M_V : MatrixZmvExtV2MClass<0b100111, 0b101, 0b0, TRR, "mmvace16.m.v">;
def MMVACE32_M_V : MatrixZmvExtV2MClass<0b100111, 0b110, 0b0, TRR, "mmvace32.m.v">;
def MMVACE64_M_V : MatrixZmvExtV2MClass<0b100111, 0b111, 0b0, TRR, "mmvace64.m.v">;
def MMVBCE8_M_V  : MatrixZmvExtV2MClass<0b100111, 0b100, 0b1, TRR, "mmvbce8.m.v">;
def MMVBCE16_M_V : MatrixZmvExtV2MClass<0b100111, 0b101, 0b1, TRR, "mmvbce16.m.v">;
def MMVBCE32_M_V : MatrixZmvExtV2MClass<0b100111, 0b110, 0b1, TRR, "mmvbce32.m.v">;
def MMVBCE64_M_V : MatrixZmvExtV2MClass<0b100111, 0b111, 0b1, TRR, "mmvbce64.m.v">;
def MMVCCE8_M_V  : MatrixZmvExtV2MClass<0b100111, 0b000, 0b0, ACCR, "mmvcce8.m.v">;
def MMVCCE16_M_V : MatrixZmvExtV2MClass<0b100111, 0b001, 0b0, ACCR, "mmvcce16.m.v">;
def MMVCCE32_M_V : MatrixZmvExtV2MClass<0b100111, 0b010, 0b0, ACCR, "mmvcce32.m.v">;
def MMVCCE64_M_V : MatrixZmvExtV2MClass<0b100111, 0b011, 0b0, ACCR, "mmvcce64.m.v">;

// Matrix Multiplication Instructions
def MMAU_MM     : MatrixMULClass<0b001000, 0b100, 0b0, 0b0, 0b0, ACCR, "mmau.mm">;
def MMAU_H_MM   : MatrixMULClass<0b001000, 0b001, 0b0, 0b0, 0b0, ACCR, "mmau.h.mm">;
def MMAU_W_MM   : MatrixMULClass<0b001000, 0b010, 0b0, 0b0, 0b0, ACCR, "mmau.w.mm">;
def MMAU_DW_MM  : MatrixMULClass<0b001000, 0b011, 0b0, 0b0, 0b0, ACCR, "mmau.dw.mm">;
def MSMAU_MM    : MatrixMULClass<0b001000, 0b100, 0b0, 0b1, 0b0, ACCR, "msmau.mm">;
def MSMAU_H_MM  : MatrixMULClass<0b001000, 0b001, 0b0, 0b1, 0b0, ACCR, "msmau.h.mm">;
def MSMAU_W_MM  : MatrixMULClass<0b001000, 0b010, 0b0, 0b1, 0b0, ACCR, "msmau.w.mm">;
def MSMAU_DW_MM : MatrixMULClass<0b001000, 0b011, 0b0, 0b1, 0b0, ACCR, "msmau.dw.mm">;
def MMA_MM      : MatrixMULClass<0b001000, 0b100, 0b0, 0b0, 0b1, ACCR, "mma.mm">;
def MMA_H_MM    : MatrixMULClass<0b001000, 0b001, 0b0, 0b0, 0b1, ACCR, "mma.h.mm">;
def MMA_W_MM    : MatrixMULClass<0b001000, 0b010, 0b0, 0b0, 0b1, ACCR, "mma.w.mm">;
def MMA_DW_MM   : MatrixMULClass<0b001000, 0b011, 0b0, 0b0, 0b1, ACCR, "mma.dw.mm">;
def MSMA_MM     : MatrixMULClass<0b001000, 0b100, 0b0, 0b1, 0b1, ACCR, "msma.mm">;
def MSMA_H_MM   : MatrixMULClass<0b001000, 0b001, 0b0, 0b1, 0b1, ACCR, "msma.h.mm">;
def MSMA_W_MM   : MatrixMULClass<0b001000, 0b010, 0b0, 0b1, 0b1, ACCR, "msma.w.mm">;
def MSMA_DW_MM  : MatrixMULClass<0b001000, 0b011, 0b0, 0b1, 0b1, ACCR, "msma.dw.mm">;
def MFMA_MM     : MatrixMULClass<0b001000, 0b100, 0b1, 0b0, 0b0, ACCR, "mfma.mm">;
def MFMA_HF_MM  : MatrixMULClass<0b001000, 0b001, 0b1, 0b0, 0b0, ACCR, "mfma.hf.mm">;
def MFMA_F_MM   : MatrixMULClass<0b001000, 0b010, 0b1, 0b0, 0b0, ACCR, "mfma.f.mm">;
def MFMA_D_MM   : MatrixMULClass<0b001000, 0b011, 0b1, 0b0, 0b0, ACCR, "mfma.d.mm">;
def MWMAU_MM    : MatrixMULClass<0b001001, 0b100, 0b0, 0b0, 0b0, ACCR, "mwmau.mm">;
def MWMAU_H_MM  : MatrixMULClass<0b001001, 0b001, 0b0, 0b0, 0b0, ACCR, "mwmau.h.mm">;
def MWMAU_W_MM  : MatrixMULClass<0b001001, 0b010, 0b0, 0b0, 0b0, ACCR, "mwmau.w.mm">;
def MSWMAU_MM   : MatrixMULClass<0b001001, 0b100, 0b0, 0b1, 0b0, ACCR, "mswmau.mm">;
def MSWMAU_H_MM : MatrixMULClass<0b001001, 0b001, 0b0, 0b1, 0b0, ACCR, "mswmau.h.mm">;
def MSWMAU_W_MM : MatrixMULClass<0b001001, 0b010, 0b0, 0b1, 0b0, ACCR, "mswmau.w.mm">;
def MWMA_MM     : MatrixMULClass<0b001001, 0b100, 0b0, 0b0, 0b1, ACCR, "mwma.mm">;
def MWMA_H_MM   : MatrixMULClass<0b001001, 0b001, 0b0, 0b0, 0b1, ACCR, "mwma.h.mm">;
def MWMA_W_MM   : MatrixMULClass<0b001001, 0b010, 0b0, 0b0, 0b1, ACCR, "mwma.w.mm">;
def MSWMA_MM    : MatrixMULClass<0b001001, 0b100, 0b0, 0b1, 0b1, ACCR, "mswma.mm">;
def MSWMA_H_MM  : MatrixMULClass<0b001001, 0b001, 0b0, 0b1, 0b1, ACCR, "mswma.h.mm">;
def MSWMA_W_MM  : MatrixMULClass<0b001001, 0b010, 0b0, 0b1, 0b1, ACCR, "mswma.w.mm">;
def MFWMA_MM    : MatrixMULClass<0b001001, 0b100, 0b1, 0b0, 0b0, ACCR, "mfwma.mm">;
def MFWMA_CF_MM : MatrixMULClass<0b001001, 0b000, 0b1, 0b0, 0b0, ACCR, "mfwma.cf.mm">;
def MFWMA_HF_MM : MatrixMULClass<0b001001, 0b001, 0b1, 0b0, 0b0, ACCR, "mfwma.hf.mm">;
def MFWMA_F_MM  : MatrixMULClass<0b001001, 0b010, 0b1, 0b0, 0b0, ACCR, "mfwma.f.mm">;
def MQMAU_MM    : MatrixMULClass<0b001010, 0b100, 0b0, 0b0, 0b0, ACCR, "mqmau.mm">;
def MQMAU_B_MM  : MatrixMULClass<0b001010, 0b000, 0b0, 0b0, 0b0, ACCR, "mqmau.b.mm">;
def MSQMAU_MM   : MatrixMULClass<0b001010, 0b100, 0b0, 0b1, 0b0, ACCR, "msqmau.mm">;
def MSQMAU_B_MM : MatrixMULClass<0b001010, 0b000, 0b0, 0b1, 0b0, ACCR, "msqmau.b.mm">;
def MQMA_MM     : MatrixMULClass<0b001010, 0b100, 0b0, 0b0, 0b1, ACCR, "mqma.mm">;
def MQMA_B_MM   : MatrixMULClass<0b001010, 0b000, 0b0, 0b0, 0b1, ACCR, "mqma.b.mm">;
def MSQMA_MM    : MatrixMULClass<0b001010, 0b100, 0b0, 0b1, 0b1, ACCR, "msqma.mm">;
def MSQMA_B_MM  : MatrixMULClass<0b001010, 0b000, 0b0, 0b1, 0b1, ACCR, "msqma.b.mm">;
def MFQMA_MM    : MatrixMULClass<0b001010, 0b100, 0b1, 0b0, 0b1, ACCR, "mfqma.mm">;
def MFQMA_CF_MM : MatrixMULClass<0b001010, 0b000, 0b1, 0b0, 0b1, ACCR, "mfqma.cf.mm">;
def MOMAU_MM    : MatrixMULClass<0b001011, 0b100, 0b0, 0b0, 0b0, ACCR, "momau.mm">;
def MOMAU_HB_MM : MatrixMULClass<0b001011, 0b111, 0b0, 0b0, 0b0, ACCR, "momau.hb.mm">;
def MSOMAU_MM   : MatrixMULClass<0b001011, 0b100, 0b0, 0b1, 0b0, ACCR, "msomau.mm">;
def MSOMAU_HB_MM: MatrixMULClass<0b001011, 0b111, 0b0, 0b1, 0b0, ACCR, "msomau.hb.mm">;
def MOMA_MM     : MatrixMULClass<0b001011, 0b100, 0b0, 0b0, 0b1, ACCR, "moma.mm">;
def MOMA_HB_MM  : MatrixMULClass<0b001011, 0b111, 0b0, 0b0, 0b1, ACCR, "moma.hb.mm">;
def MSOMA_MM    : MatrixMULClass<0b001011, 0b100, 0b0, 0b1, 0b1, ACCR, "msoma.mm">;
def MSOMA_HB_MM : MatrixMULClass<0b001011, 0b111, 0b0, 0b1, 0b1, ACCR, "msoma.hb.mm">;

// Sparsing Matrix Multiplication Instructions
def MMAU_SPA_MM     : MatrixMULSPAClass<0b101000, 0b100, 0b0, 0b0, 0b0, 0b0, "mmau.spa.mm">;
def MMAU_SPB_MM     : MatrixMULSPAClass<0b101000, 0b100, 0b0, 0b0, 0b0, 0b1, "mmau.spb.mm">;
def MMAU_SPA_H_MM   : MatrixMULSPAClass<0b101000, 0b001, 0b0, 0b0, 0b0, 0b0, "mmau.spa.h.mm">;
def MMAU_SPB_H_MM   : MatrixMULSPAClass<0b101000, 0b001, 0b0, 0b0, 0b0, 0b1, "mmau.spb.h.mm">;
def MMAU_SPA_W_MM   : MatrixMULSPAClass<0b101000, 0b010, 0b0, 0b0, 0b0, 0b0, "mmau.spa.w.mm">;
def MMAU_SPB_W_MM   : MatrixMULSPAClass<0b101000, 0b010, 0b0, 0b0, 0b0, 0b1, "mmau.spb.w.mm">;
def MMAU_SPA_DW_MM  : MatrixMULSPAClass<0b101000, 0b011, 0b0, 0b0, 0b0, 0b0, "mmau.spa.dw.mm">;
def MMAU_SPB_DW_MM  : MatrixMULSPAClass<0b101000, 0b011, 0b0, 0b0, 0b0, 0b1, "mmau.spb.dw.mm">;
def MSMAU_SPA_MM    : MatrixMULSPAClass<0b101000, 0b100, 0b0, 0b1, 0b0, 0b0, "msmau.spa.mm">;
def MSMAU_SPB_MM    : MatrixMULSPAClass<0b101000, 0b100, 0b0, 0b1, 0b0, 0b1, "msmau.spb.mm">;
def MSMAU_SPA_H_MM  : MatrixMULSPAClass<0b101000, 0b001, 0b0, 0b1, 0b0, 0b0, "msmau.spa.h.mm">;
def MSMAU_SPB_H_MM  : MatrixMULSPAClass<0b101000, 0b001, 0b0, 0b1, 0b0, 0b1, "msmau.spb.h.mm">;
def MSMAU_SPA_W_MM  : MatrixMULSPAClass<0b101000, 0b010, 0b0, 0b1, 0b0, 0b0, "msmau.spa.w.mm">;
def MSMAU_SPB_W_MM  : MatrixMULSPAClass<0b101000, 0b010, 0b0, 0b1, 0b0, 0b1, "msmau.spb.w.mm">;
def MSMAU_SPA_DW_MM : MatrixMULSPAClass<0b101000, 0b011, 0b0, 0b1, 0b0, 0b0, "msmau.spa.dw.mm">;
def MSMAU_SPB_DW_MM : MatrixMULSPAClass<0b101000, 0b011, 0b0, 0b1, 0b0, 0b1, "msmau.spb.dw.mm">;
def MMA_SPA_MM      : MatrixMULSPAClass<0b101000, 0b100, 0b0, 0b0, 0b1, 0b0, "mma.spa.mm">;
def MMA_SPB_MM      : MatrixMULSPAClass<0b101000, 0b100, 0b0, 0b0, 0b1, 0b1, "mma.spb.mm">;
def MMA_SPA_H_MM    : MatrixMULSPAClass<0b101000, 0b001, 0b0, 0b0, 0b1, 0b0, "mma.spa.h.mm">;
def MMA_SPB_H_MM    : MatrixMULSPAClass<0b101000, 0b001, 0b0, 0b0, 0b1, 0b1, "mma.spb.h.mm">;
def MMA_SPA_W_MM    : MatrixMULSPAClass<0b101000, 0b010, 0b0, 0b0, 0b1, 0b0, "mma.spa.w.mm">;
def MMA_SPB_W_MM    : MatrixMULSPAClass<0b101000, 0b010, 0b0, 0b0, 0b1, 0b1, "mma.spb.w.mm">;
def MMA_SPA_DW_MM   : MatrixMULSPAClass<0b101000, 0b011, 0b0, 0b0, 0b1, 0b0, "mma.spa.dw.mm">;
def MMA_SPB_DW_MM   : MatrixMULSPAClass<0b101000, 0b011, 0b0, 0b0, 0b1, 0b1, "mma.spb.dw.mm">;
def MSMA_SPA_MM     : MatrixMULSPAClass<0b101000, 0b100, 0b0, 0b1, 0b1, 0b0, "msma.spa.mm">;
def MSMA_SPB_MM     : MatrixMULSPAClass<0b101000, 0b100, 0b0, 0b1, 0b1, 0b1, "msma.spb.mm">;
def MSMA_SPA_H_MM   : MatrixMULSPAClass<0b101000, 0b001, 0b0, 0b1, 0b1, 0b0, "msma.spa.h.mm">;
def MSMA_SPB_H_MM   : MatrixMULSPAClass<0b101000, 0b001, 0b0, 0b1, 0b1, 0b1, "msma.spb.h.mm">;
def MSMA_SPA_W_MM   : MatrixMULSPAClass<0b101000, 0b010, 0b0, 0b1, 0b1, 0b0, "msma.spa.w.mm">;
def MSMA_SPB_W_MM   : MatrixMULSPAClass<0b101000, 0b010, 0b0, 0b1, 0b1, 0b1, "msma.spb.w.mm">;
def MSMA_SPA_DW_MM  : MatrixMULSPAClass<0b101000, 0b011, 0b0, 0b1, 0b1, 0b0, "msma.spa.dw.mm">;
def MSMA_SPB_DW_MM  : MatrixMULSPAClass<0b101000, 0b011, 0b0, 0b1, 0b1, 0b1, "msma.spb.dw.mm">;
def MFMA_SPA_MM     : MatrixMULSPAClass<0b101000, 0b100, 0b1, 0b0, 0b1, 0b0, "mfma.spa.mm">;
def MFMA_SPB_MM     : MatrixMULSPAClass<0b101000, 0b100, 0b1, 0b0, 0b1, 0b1, "mfma.spb.mm">;
def MFMA_SPA_HF_MM  : MatrixMULSPAClass<0b101000, 0b001, 0b1, 0b0, 0b1, 0b0, "mfma.spa.hf.mm">;
def MFMA_SPB_HF_MM  : MatrixMULSPAClass<0b101000, 0b001, 0b1, 0b0, 0b1, 0b1, "mfma.spb.hf.mm">;
def MFMA_SPA_F_MM   : MatrixMULSPAClass<0b101000, 0b010, 0b1, 0b0, 0b1, 0b0, "mfma.spa.f.mm">;
def MFMA_SPB_F_MM   : MatrixMULSPAClass<0b101000, 0b010, 0b1, 0b0, 0b1, 0b1, "mfma.spb.f.mm">;
def MFMA_SPA_D_MM   : MatrixMULSPAClass<0b101000, 0b011, 0b1, 0b0, 0b1, 0b0, "mfma.spa.d.mm">;
def MFMA_SPB_D_MM   : MatrixMULSPAClass<0b101000, 0b011, 0b1, 0b0, 0b1, 0b1, "mfma.spb.d.mm">;
def MWMAU_SPA_MM    : MatrixMULSPAClass<0b101001, 0b100, 0b0, 0b0, 0b0, 0b0, "mwmau.spa.mm">;
def MWMAU_SPB_MM    : MatrixMULSPAClass<0b101001, 0b100, 0b0, 0b0, 0b0, 0b1, "mwmau.spb.mm">;
def MWMAU_SPA_H_MM  : MatrixMULSPAClass<0b101001, 0b001, 0b0, 0b0, 0b0, 0b0, "mwmau.spa.h.mm">;
def MWMAU_SPB_H_MM  : MatrixMULSPAClass<0b101001, 0b001, 0b0, 0b0, 0b0, 0b1, "mwmau.spb.h.mm">;
def MWMAU_SPA_W_MM  : MatrixMULSPAClass<0b101001, 0b010, 0b0, 0b0, 0b0, 0b0, "mwmau.spa.w.mm">;
def MWMAU_SPB_W_MM  : MatrixMULSPAClass<0b101001, 0b010, 0b0, 0b0, 0b0, 0b1, "mwmau.spb.w.mm">;
def MSWMAU_SPA_MM   : MatrixMULSPAClass<0b101001, 0b100, 0b0, 0b1, 0b0, 0b0, "mswmau.spa.mm">;
def MSWMAU_SPB_MM   : MatrixMULSPAClass<0b101001, 0b100, 0b0, 0b1, 0b0, 0b1, "mswmau.spb.mm">;
def MSWMAU_SPA_H_MM : MatrixMULSPAClass<0b101001, 0b001, 0b0, 0b1, 0b0, 0b0, "mswmau.spa.h.mm">;
def MSWMAU_SPB_H_MM : MatrixMULSPAClass<0b101001, 0b001, 0b0, 0b1, 0b0, 0b1, "mswmau.spb.h.mm">;
def MSWMAU_SPA_W_MM : MatrixMULSPAClass<0b101001, 0b010, 0b0, 0b1, 0b0, 0b0, "mswmau.spa.w.mm">;
def MSWMAU_SPB_W_MM : MatrixMULSPAClass<0b101001, 0b010, 0b0, 0b1, 0b0, 0b1, "mswmau.spb.w.mm">;
def MWMA_SPA_MM     : MatrixMULSPAClass<0b101001, 0b100, 0b0, 0b0, 0b1, 0b0, "mwma.spa.mm">;
def MWMA_SPB_MM     : MatrixMULSPAClass<0b101001, 0b100, 0b0, 0b0, 0b1, 0b1, "mwma.spb.mm">;
def MWMA_SPA_H_MM   : MatrixMULSPAClass<0b101001, 0b001, 0b0, 0b0, 0b1, 0b0, "mwma.spa.h.mm">;
def MWMA_SPB_H_MM   : MatrixMULSPAClass<0b101001, 0b001, 0b0, 0b0, 0b1, 0b1, "mwma.spb.h.mm">;
def MWMA_SPA_W_MM   : MatrixMULSPAClass<0b101001, 0b010, 0b0, 0b0, 0b1, 0b0, "mwma.spa.w.mm">;
def MWMA_SPB_W_MM   : MatrixMULSPAClass<0b101001, 0b010, 0b0, 0b0, 0b1, 0b1, "mwma.spb.w.mm">;
def MSWMA_SPA_MM    : MatrixMULSPAClass<0b101001, 0b100, 0b0, 0b1, 0b1, 0b0, "mswma.spa.mm">;
def MSWMA_SPB_MM    : MatrixMULSPAClass<0b101001, 0b100, 0b0, 0b1, 0b1, 0b1, "mswma.spb.mm">;
def MSWMA_SPA_H_MM  : MatrixMULSPAClass<0b101001, 0b001, 0b0, 0b1, 0b1, 0b0, "mswma.spa.h.mm">;
def MSWMA_SPB_H_MM  : MatrixMULSPAClass<0b101001, 0b001, 0b0, 0b1, 0b1, 0b1, "mswma.spb.h.mm">;
def MSWMA_SPA_W_MM  : MatrixMULSPAClass<0b101001, 0b010, 0b0, 0b1, 0b1, 0b0, "mswma.spa.w.mm">;
def MSWMA_SPB_W_MM  : MatrixMULSPAClass<0b101001, 0b010, 0b0, 0b1, 0b1, 0b1, "mswma.spb.w.mm">;
def MFWMA_SPA_MM    : MatrixMULSPAClass<0b101001, 0b100, 0b1, 0b0, 0b1, 0b0, "mfwma.spa.mm">;
def MFWMA_SPB_MM    : MatrixMULSPAClass<0b101001, 0b100, 0b1, 0b0, 0b1, 0b1, "mfwma.spb.mm">;
def MFWMA_SPA_HF_MM : MatrixMULSPAClass<0b101001, 0b001, 0b1, 0b0, 0b1, 0b0, "mfwma.spa.hf.mm">;
def MFWMA_SPB_HF_MM : MatrixMULSPAClass<0b101001, 0b001, 0b1, 0b0, 0b1, 0b1, "mfwma.spb.hf.mm">;
def MFWMA_SPA_F_MM  : MatrixMULSPAClass<0b101001, 0b010, 0b1, 0b0, 0b1, 0b0, "mfwma.spa.f.mm">;
def MFWMA_SPB_F_MM  : MatrixMULSPAClass<0b101001, 0b010, 0b1, 0b0, 0b1, 0b1, "mfwma.spb.f.mm">;
def MQMAU_SPA_MM    : MatrixMULSPAClass<0b101010, 0b100, 0b0, 0b0, 0b0, 0b0, "mqmau.spa.mm">;
def MQMAU_SPB_MM    : MatrixMULSPAClass<0b101010, 0b100, 0b0, 0b0, 0b0, 0b1, "mqmau.spb.mm">;
def MQMAU_SPA_B_MM  : MatrixMULSPAClass<0b101010, 0b000, 0b0, 0b0, 0b0, 0b0, "mqmau.spa.b.mm">;
def MQMAU_SPB_B_MM  : MatrixMULSPAClass<0b101010, 0b000, 0b0, 0b0, 0b0, 0b1, "mqmau.spb.b.mm">;
def MSQMAU_SPA_MM   : MatrixMULSPAClass<0b101010, 0b100, 0b0, 0b1, 0b0, 0b0, "msqmau.spa.mm">;
def MSQMAU_SPB_MM   : MatrixMULSPAClass<0b101010, 0b100, 0b0, 0b1, 0b0, 0b1, "msqmau.spb.mm">;
def MSQMAU_SPA_B_MM : MatrixMULSPAClass<0b101010, 0b000, 0b0, 0b1, 0b0, 0b0, "msqmau.spa.b.mm">;
def MSQMAU_SPB_B_MM : MatrixMULSPAClass<0b101010, 0b000, 0b0, 0b1, 0b0, 0b1, "msqmau.spb.b.mm">;
def MQMA_SPA_MM     : MatrixMULSPAClass<0b101010, 0b100, 0b0, 0b0, 0b1, 0b0, "mqma.spa.mm">;
def MQMA_SPB_MM     : MatrixMULSPAClass<0b101010, 0b100, 0b0, 0b0, 0b1, 0b1, "mqma.spb.mm">;
def MQMA_SPA_B_MM   : MatrixMULSPAClass<0b101010, 0b000, 0b0, 0b0, 0b1, 0b0, "mqma.spa.b.mm">;
def MQMA_SPB_B_MM   : MatrixMULSPAClass<0b101010, 0b000, 0b0, 0b0, 0b1, 0b1, "mqma.spb.b.mm">;
def MSQMA_SPA_MM    : MatrixMULSPAClass<0b101010, 0b100, 0b0, 0b1, 0b1, 0b0, "msqma.spa.mm">;
def MSQMA_SPB_MM    : MatrixMULSPAClass<0b101010, 0b100, 0b0, 0b1, 0b1, 0b1, "msqma.spb.mm">;
def MSQMA_SPA_B_MM  : MatrixMULSPAClass<0b101010, 0b000, 0b0, 0b1, 0b1, 0b0, "msqma.spa.b.mm">;
def MSQMA_SPB_B_MM  : MatrixMULSPAClass<0b101010, 0b000, 0b0, 0b1, 0b1, 0b1, "msqma.spb.b.mm">;
def MFQMA_SPA_MM    : MatrixMULSPAClass<0b101010, 0b100, 0b1, 0b0, 0b1, 0b0, "mfqma.spa.mm">;
def MFQMA_SPB_MM    : MatrixMULSPAClass<0b101010, 0b100, 0b1, 0b0, 0b1, 0b1, "mfqma.spb.mm">;
def MFQMA_SPA_CF_MM : MatrixMULSPAClass<0b101010, 0b000, 0b1, 0b0, 0b1, 0b0, "mfqma.spa.cf.mm">;
def MFQMA_SPB_CF_MM : MatrixMULSPAClass<0b101010, 0b000, 0b1, 0b0, 0b1, 0b1, "mfqma.spb.cf.mm">;
def MOMAU_SPA_MM    : MatrixMULSPAClass<0b101011, 0b100, 0b0, 0b0, 0b0, 0b0, "momau.spa.mm">;
def MOMAU_SPB_MM    : MatrixMULSPAClass<0b101011, 0b100, 0b0, 0b0, 0b0, 0b1, "momau.spb.mm">;
def MOMAU_SPA_HB_MM : MatrixMULSPAClass<0b101011, 0b111, 0b0, 0b0, 0b0, 0b0, "momau.spa.hb.mm">;
def MOMAU_SPB_HB_MM : MatrixMULSPAClass<0b101011, 0b111, 0b0, 0b0, 0b0, 0b1, "momau.spb.hb.mm">;
def MSOMAU_SPA_MM   : MatrixMULSPAClass<0b101011, 0b100, 0b0, 0b1, 0b0, 0b0, "msomau.spa.mm">;
def MSOMAU_SPB_MM   : MatrixMULSPAClass<0b101011, 0b100, 0b0, 0b1, 0b0, 0b1, "msomau.spb.mm">;
def MSOMAU_SPA_HB_MM: MatrixMULSPAClass<0b101011, 0b111, 0b0, 0b1, 0b0, 0b0, "msomau.spa.hb.mm">;
def MSOMAU_SPB_HB_MM: MatrixMULSPAClass<0b101011, 0b111, 0b0, 0b1, 0b0, 0b1, "msomau.spb.hb.mm">;
def MOMA_SPA_MM     : MatrixMULSPAClass<0b101011, 0b100, 0b0, 0b0, 0b1, 0b0, "moma.spa.mm">;
def MOMA_SPB_MM     : MatrixMULSPAClass<0b101011, 0b100, 0b0, 0b0, 0b1, 0b1, "moma.spb.mm">;
def MOMA_SPA_HB_MM  : MatrixMULSPAClass<0b101011, 0b111, 0b0, 0b0, 0b1, 0b0, "moma.spa.hb.mm">;
def MOMA_SPB_HB_MM  : MatrixMULSPAClass<0b101011, 0b111, 0b0, 0b0, 0b1, 0b1, "moma.spb.hb.mm">;
def MSOMA_SPA_MM    : MatrixMULSPAClass<0b101011, 0b100, 0b0, 0b1, 0b1, 0b0, "msoma.spa.mm">;
def MSOMA_SPB_MM    : MatrixMULSPAClass<0b101011, 0b100, 0b0, 0b1, 0b1, 0b1, "msoma.spb.mm">;
def MSOMA_SPA_HB_MM : MatrixMULSPAClass<0b101011, 0b111, 0b0, 0b1, 0b1, 0b0, "msoma.spa.hb.mm">;
def MSOMA_SPB_HB_MM : MatrixMULSPAClass<0b101011, 0b111, 0b0, 0b1, 0b1, 0b1, "msoma.spb.hb.mm">;

// Element-wise Arithmetic & Logic Instructions
def MADDU_MM      : MatrixEletwiseClass<0b001000, 0b100, 0b0, 0b0, 0b0, 0b0, "maddu.mm">;
def MADDU_B_MM    : MatrixEletwiseClass<0b001000, 0b000, 0b0, 0b0, 0b0, 0b0, "maddu.b.mm">;
def MADDU_H_MM    : MatrixEletwiseClass<0b001000, 0b001, 0b0, 0b0, 0b0, 0b0, "maddu.h.mm">;
def MADDU_W_MM    : MatrixEletwiseClass<0b001000, 0b010, 0b0, 0b0, 0b0, 0b0, "maddu.w.mm">;
def MADDU_DW_MM   : MatrixEletwiseClass<0b001000, 0b011, 0b0, 0b0, 0b0, 0b0, "maddu.dw.mm">;
def MADDU_HB_MM   : MatrixEletwiseClass<0b001000, 0b111, 0b0, 0b0, 0b0, 0b0, "maddu.hb.mm">;
def MSADDU_MM     : MatrixEletwiseClass<0b001000, 0b100, 0b0, 0b1, 0b0, 0b0, "msaddu.mm">;
def MSADDU_B_MM   : MatrixEletwiseClass<0b001000, 0b000, 0b0, 0b1, 0b0, 0b0, "msaddu.b.mm">;
def MSADDU_H_MM   : MatrixEletwiseClass<0b001000, 0b001, 0b0, 0b1, 0b0, 0b0, "msaddu.h.mm">;
def MSADDU_W_MM   : MatrixEletwiseClass<0b001000, 0b010, 0b0, 0b1, 0b0, 0b0, "msaddu.w.mm">;
def MSADDU_DW_MM  : MatrixEletwiseClass<0b001000, 0b011, 0b0, 0b1, 0b0, 0b0, "msaddu.dw.mm">;
def MSADDU_HB_MM  : MatrixEletwiseClass<0b001000, 0b111, 0b0, 0b1, 0b0, 0b0, "msaddu.hb.mm">;
def MADD_MM       : MatrixEletwiseClass<0b001000, 0b100, 0b0, 0b0, 0b1, 0b0, "madd.mm">;
def MADD_B_MM     : MatrixEletwiseClass<0b001000, 0b000, 0b0, 0b0, 0b1, 0b0, "madd.b.mm">;
def MADD_H_MM     : MatrixEletwiseClass<0b001000, 0b001, 0b0, 0b0, 0b1, 0b0, "madd.h.mm">;
def MADD_W_MM     : MatrixEletwiseClass<0b001000, 0b010, 0b0, 0b0, 0b1, 0b0, "madd.w.mm">;
def MADD_DW_MM    : MatrixEletwiseClass<0b001000, 0b011, 0b0, 0b0, 0b1, 0b0, "madd.dw.mm">;
def MADD_HB_MM    : MatrixEletwiseClass<0b001000, 0b111, 0b0, 0b0, 0b1, 0b0, "madd.hb.mm">;
def MSADD_MM      : MatrixEletwiseClass<0b001000, 0b100, 0b0, 0b1, 0b1, 0b0, "msadd.mm">;
def MSADD_B_MM    : MatrixEletwiseClass<0b001000, 0b000, 0b0, 0b1, 0b1, 0b0, "msadd.b.mm">;
def MSADD_H_MM    : MatrixEletwiseClass<0b001000, 0b001, 0b0, 0b1, 0b1, 0b0, "msadd.h.mm">;
def MSADD_W_MM    : MatrixEletwiseClass<0b001000, 0b010, 0b0, 0b1, 0b1, 0b0, "msadd.w.mm">;
def MSADD_DW_MM   : MatrixEletwiseClass<0b001000, 0b011, 0b0, 0b1, 0b1, 0b0, "msadd.dw.mm">;
def MSADD_HB_MM   : MatrixEletwiseClass<0b001000, 0b111, 0b0, 0b1, 0b1, 0b0, "msadd.hb.mm">;
def MFADD_MM      : MatrixEletwiseClass<0b001000, 0b100, 0b1, 0b0, 0b1, 0b0, "mfadd.mm">;
def MFADD_CF_MM   : MatrixEletwiseClass<0b001000, 0b000, 0b1, 0b0, 0b1, 0b0, "mfadd.cf.mm">;
def MFADD_HF_MM   : MatrixEletwiseClass<0b001000, 0b001, 0b1, 0b0, 0b1, 0b0, "mfadd.hf.mm">;
def MFADD_F_MM    : MatrixEletwiseClass<0b001000, 0b010, 0b1, 0b0, 0b1, 0b0, "mfadd.f.mm">;
def MFADD_D_MM    : MatrixEletwiseClass<0b001000, 0b011, 0b1, 0b0, 0b1, 0b0, "mfadd.d.mm">;
def MWADDU_MM     : MatrixEletwiseClass<0b001001, 0b100, 0b0, 0b0, 0b0, 0b0, "mwaddu.mm">;
def MWADDU_B_MM   : MatrixEletwiseClass<0b001001, 0b000, 0b0, 0b0, 0b0, 0b0, "mwaddu.b.mm">;
def MWADDU_H_MM   : MatrixEletwiseClass<0b001001, 0b001, 0b0, 0b0, 0b0, 0b0, "mwaddu.h.mm">;
def MWADDU_W_MM   : MatrixEletwiseClass<0b001001, 0b010, 0b0, 0b0, 0b0, 0b0, "mwaddu.w.mm">;
def MWADDU_HB_MM  : MatrixEletwiseClass<0b001001, 0b111, 0b0, 0b0, 0b0, 0b0, "mwaddu.hb.mm">;
def MWADD_MM      : MatrixEletwiseClass<0b001001, 0b100, 0b0, 0b0, 0b1, 0b0, "mwadd.mm">;
def MWADD_B_MM    : MatrixEletwiseClass<0b001001, 0b000, 0b0, 0b0, 0b1, 0b0, "mwadd.b.mm">;
def MWADD_H_MM    : MatrixEletwiseClass<0b001001, 0b001, 0b0, 0b0, 0b1, 0b0, "mwadd.h.mm">;
def MWADD_W_MM    : MatrixEletwiseClass<0b001001, 0b010, 0b0, 0b0, 0b1, 0b0, "mwadd.w.mm">;
def MWADD_HB_MM   : MatrixEletwiseClass<0b001001, 0b111, 0b0, 0b0, 0b1, 0b0, "mwadd.hb.mm">;
def MFWADD_MM     : MatrixEletwiseClass<0b001001, 0b100, 0b1, 0b0, 0b1, 0b0, "mfwadd.mm">;
def MFWADD_CF_MM  : MatrixEletwiseClass<0b001001, 0b000, 0b1, 0b0, 0b1, 0b0, "mfwadd.cf.mm">;
def MFWADD_HF_MM  : MatrixEletwiseClass<0b001001, 0b001, 0b1, 0b0, 0b1, 0b0, "mfwadd.hf.mm">;
def MFWADD_F_MM   : MatrixEletwiseClass<0b001001, 0b010, 0b1, 0b0, 0b1, 0b0, "mfwadd.f.mm">;
def MSUBU_MM      : MatrixEletwiseClass<0b001010, 0b100, 0b0, 0b0, 0b0, 0b0, "msubu.mm">;
def MSUBU_B_MM    : MatrixEletwiseClass<0b001010, 0b000, 0b0, 0b0, 0b0, 0b0, "msubu.b.mm">;
def MSUBU_H_MM    : MatrixEletwiseClass<0b001010, 0b001, 0b0, 0b0, 0b0, 0b0, "msubu.h.mm">;
def MSUBU_W_MM    : MatrixEletwiseClass<0b001010, 0b010, 0b0, 0b0, 0b0, 0b0, "msubu.w.mm">;
def MSUBU_DW_MM   : MatrixEletwiseClass<0b001010, 0b011, 0b0, 0b0, 0b0, 0b0, "msubu.dw.mm">;
def MSUBU_HB_MM   : MatrixEletwiseClass<0b001010, 0b111, 0b0, 0b0, 0b0, 0b0, "msubu.hb.mm">;
def MSSUBU_MM     : MatrixEletwiseClass<0b001010, 0b100, 0b0, 0b1, 0b0, 0b0, "mssubu.mm">;
def MSSUBU_B_MM   : MatrixEletwiseClass<0b001010, 0b000, 0b0, 0b1, 0b0, 0b0, "mssubu.b.mm">;
def MSSUBU_H_MM   : MatrixEletwiseClass<0b001010, 0b001, 0b0, 0b1, 0b0, 0b0, "mssubu.h.mm">;
def MSSUBU_W_MM   : MatrixEletwiseClass<0b001010, 0b010, 0b0, 0b1, 0b0, 0b0, "mssubu.w.mm">;
def MSSUBU_DW_MM  : MatrixEletwiseClass<0b001010, 0b011, 0b0, 0b1, 0b0, 0b0, "mssubu.dw.mm">;
def MSSUBU_HB_MM  : MatrixEletwiseClass<0b001010, 0b111, 0b0, 0b1, 0b0, 0b0, "mssubu.hb.mm">;
def MSUB_MM       : MatrixEletwiseClass<0b001010, 0b100, 0b0, 0b0, 0b1, 0b0, "msub.mm">;
def MSUB_B_MM     : MatrixEletwiseClass<0b001010, 0b000, 0b0, 0b0, 0b1, 0b0, "msub.b.mm">;
def MSUB_H_MM     : MatrixEletwiseClass<0b001010, 0b001, 0b0, 0b0, 0b1, 0b0, "msub.h.mm">;
def MSUB_W_MM     : MatrixEletwiseClass<0b001010, 0b010, 0b0, 0b0, 0b1, 0b0, "msub.w.mm">;
def MSUB_DW_MM    : MatrixEletwiseClass<0b001010, 0b011, 0b0, 0b0, 0b1, 0b0, "msub.dw.mm">;
def MSUB_HB_MM    : MatrixEletwiseClass<0b001010, 0b111, 0b0, 0b0, 0b1, 0b0, "msub.hb.mm">;
def MSSUB_MM      : MatrixEletwiseClass<0b001010, 0b100, 0b0, 0b1, 0b1, 0b0, "mssub.mm">;
def MSSUB_B_MM    : MatrixEletwiseClass<0b001010, 0b000, 0b0, 0b1, 0b1, 0b0, "mssub.b.mm">;
def MSSUB_H_MM    : MatrixEletwiseClass<0b001010, 0b001, 0b0, 0b1, 0b1, 0b0, "mssub.h.mm">;
def MSSUB_W_MM    : MatrixEletwiseClass<0b001010, 0b010, 0b0, 0b1, 0b1, 0b0, "mssub.w.mm">;
def MSSUB_DW_MM   : MatrixEletwiseClass<0b001010, 0b011, 0b0, 0b1, 0b1, 0b0, "mssub.dw.mm">;
def MSSUB_HB_MM   : MatrixEletwiseClass<0b001010, 0b111, 0b0, 0b1, 0b1, 0b0, "mssub.hb.mm">;
def MFSUB_MM      : MatrixEletwiseClass<0b001010, 0b100, 0b1, 0b0, 0b1, 0b0, "mfsub.mm">;
def MFSUB_CF_MM   : MatrixEletwiseClass<0b001010, 0b000, 0b1, 0b0, 0b1, 0b0, "mfsub.cf.mm">;
def MFSUB_HF_MM   : MatrixEletwiseClass<0b001010, 0b001, 0b1, 0b0, 0b1, 0b0, "mfsub.hf.mm">;
def MFSUB_F_MM    : MatrixEletwiseClass<0b001010, 0b010, 0b1, 0b0, 0b1, 0b0, "mfsub.f.mm">;
def MFSUB_D_MM    : MatrixEletwiseClass<0b001010, 0b011, 0b1, 0b0, 0b1, 0b0, "mfsub.d.mm">;
def MWSUBU_MM     : MatrixEletwiseClass<0b001011, 0b100, 0b0, 0b0, 0b0, 0b0, "mwsubu.mm">;
def MWSUBU_B_MM   : MatrixEletwiseClass<0b001011, 0b000, 0b0, 0b0, 0b0, 0b0, "mwsubu.b.mm">;
def MWSUBU_H_MM   : MatrixEletwiseClass<0b001011, 0b001, 0b0, 0b0, 0b0, 0b0, "mwsubu.h.mm">;
def MWSUBU_W_MM   : MatrixEletwiseClass<0b001011, 0b010, 0b0, 0b0, 0b0, 0b0, "mwsubu.w.mm">;
def MWSUBU_HB_MM  : MatrixEletwiseClass<0b001011, 0b111, 0b0, 0b0, 0b0, 0b0, "mwsubu.hb.mm">;
def MWSUB_MM      : MatrixEletwiseClass<0b001011, 0b100, 0b0, 0b0, 0b1, 0b0, "mwsub.mm">;
def MWSUB_B_MM    : MatrixEletwiseClass<0b001011, 0b000, 0b0, 0b0, 0b1, 0b0, "mwsub.b.mm">;
def MWSUB_H_MM    : MatrixEletwiseClass<0b001011, 0b001, 0b0, 0b0, 0b1, 0b0, "mwsub.h.mm">;
def MWSUB_W_MM    : MatrixEletwiseClass<0b001011, 0b010, 0b0, 0b0, 0b1, 0b0, "mwsub.w.mm">;
def MWSUB_HB_MM   : MatrixEletwiseClass<0b001011, 0b111, 0b0, 0b0, 0b1, 0b0, "mwsub.hb.mm">;
def MFWSUB_MM     : MatrixEletwiseClass<0b001011, 0b100, 0b1, 0b0, 0b1, 0b0, "mfwsub.mm">;
def MFWSUB_CF_MM  : MatrixEletwiseClass<0b001011, 0b000, 0b1, 0b0, 0b1, 0b0, "mfwsub.cf.mm">;
def MFWSUB_HF_MM  : MatrixEletwiseClass<0b001011, 0b001, 0b1, 0b0, 0b1, 0b0, "mfwsub.hf.mm">;
def MFWSUB_F_MM   : MatrixEletwiseClass<0b001011, 0b010, 0b1, 0b0, 0b1, 0b0, "mfwsub.f.mm">;
def MMINU_MM      : MatrixEletwiseClass<0b001100, 0b100, 0b0, 0b0, 0b0, 0b0, "mminu.mm">;
def MMINU_B_MM    : MatrixEletwiseClass<0b001100, 0b000, 0b0, 0b0, 0b0, 0b0, "mminu.b.mm">;
def MMINU_H_MM    : MatrixEletwiseClass<0b001100, 0b001, 0b0, 0b0, 0b0, 0b0, "mminu.h.mm">;
def MMINU_W_MM    : MatrixEletwiseClass<0b001100, 0b010, 0b0, 0b0, 0b0, 0b0, "mminu.w.mm">;
def MMINU_DW_MM   : MatrixEletwiseClass<0b001100, 0b011, 0b0, 0b0, 0b0, 0b0, "mminu.dw.mm">;
def MMINU_HB_MM   : MatrixEletwiseClass<0b001100, 0b111, 0b0, 0b0, 0b0, 0b0, "mminu.hb.mm">;
def MMAXU_MM      : MatrixEletwiseClass<0b001100, 0b100, 0b0, 0b1, 0b0, 0b0, "mmaxu.mm">;
def MMAXU_B_MM    : MatrixEletwiseClass<0b001100, 0b000, 0b0, 0b1, 0b0, 0b0, "mmaxu.b.mm">;
def MMAXU_H_MM    : MatrixEletwiseClass<0b001100, 0b001, 0b0, 0b1, 0b0, 0b0, "mmaxu.h.mm">;
def MMAXU_W_MM    : MatrixEletwiseClass<0b001100, 0b010, 0b0, 0b1, 0b0, 0b0, "mmaxu.w.mm">;
def MMAXU_DW_MM   : MatrixEletwiseClass<0b001100, 0b011, 0b0, 0b1, 0b0, 0b0, "mmaxu.dw.mm">;
def MMAXU_HB_MM   : MatrixEletwiseClass<0b001100, 0b111, 0b0, 0b1, 0b0, 0b0, "mmaxu.hb.mm">;
def MMIN_MM       : MatrixEletwiseClass<0b001100, 0b100, 0b0, 0b0, 0b1, 0b0, "mmin.mm">;
def MMIN_B_MM     : MatrixEletwiseClass<0b001100, 0b000, 0b0, 0b0, 0b1, 0b0, "mmin.b.mm">;
def MMIN_H_MM     : MatrixEletwiseClass<0b001100, 0b001, 0b0, 0b0, 0b1, 0b0, "mmin.h.mm">;
def MMIN_W_MM     : MatrixEletwiseClass<0b001100, 0b010, 0b0, 0b0, 0b1, 0b0, "mmin.w.mm">;
def MMIN_DW_MM    : MatrixEletwiseClass<0b001100, 0b011, 0b0, 0b0, 0b1, 0b0, "mmin.dw.mm">;
def MMIN_HB_MM    : MatrixEletwiseClass<0b001100, 0b111, 0b0, 0b0, 0b1, 0b0, "mmin.hb.mm">;
def MMAX_MM       : MatrixEletwiseClass<0b001100, 0b100, 0b0, 0b1, 0b1, 0b0, "mmax.mm">;
def MMAX_B_MM     : MatrixEletwiseClass<0b001100, 0b000, 0b0, 0b1, 0b1, 0b0, "mmax.b.mm">;
def MMAX_H_MM     : MatrixEletwiseClass<0b001100, 0b001, 0b0, 0b1, 0b1, 0b0, "mmax.h.mm">;
def MMAX_W_MM     : MatrixEletwiseClass<0b001100, 0b010, 0b0, 0b1, 0b1, 0b0, "mmax.w.mm">;
def MMAX_DW_MM    : MatrixEletwiseClass<0b001100, 0b011, 0b0, 0b1, 0b1, 0b0, "mmax.dw.mm">;
def MMAX_HB_MM    : MatrixEletwiseClass<0b001100, 0b111, 0b0, 0b1, 0b1, 0b0, "mmax.hb.mm">;
def MFMIN_MM      : MatrixEletwiseClass<0b001100, 0b100, 0b1, 0b0, 0b1, 0b0, "mfmin.mm">;
def MFMIN_CF_MM   : MatrixEletwiseClass<0b001100, 0b000, 0b1, 0b0, 0b1, 0b0, "mfmin.cf.mm">;
def MFMIN_HF_MM   : MatrixEletwiseClass<0b001100, 0b001, 0b1, 0b0, 0b1, 0b0, "mfmin.hf.mm">;
def MFMIN_F_MM    : MatrixEletwiseClass<0b001100, 0b010, 0b1, 0b0, 0b1, 0b0, "mfmin.f.mm">;
def MFMIN_D_MM    : MatrixEletwiseClass<0b001100, 0b011, 0b1, 0b0, 0b1, 0b0, "mfmin.d.mm">;
def MFMAX_MM      : MatrixEletwiseClass<0b001100, 0b100, 0b1, 0b1, 0b1, 0b0, "mfmax.mm">;
def MFMAX_CF_MM   : MatrixEletwiseClass<0b001100, 0b000, 0b1, 0b1, 0b1, 0b0, "mfmax.cf.mm">;
def MFMAX_HF_MM   : MatrixEletwiseClass<0b001100, 0b001, 0b1, 0b1, 0b1, 0b0, "mfmax.hf.mm">;
def MFMAX_F_MM    : MatrixEletwiseClass<0b001100, 0b010, 0b1, 0b1, 0b1, 0b0, "mfmax.f.mm">;
def MFMAX_D_MM    : MatrixEletwiseClass<0b001100, 0b011, 0b1, 0b1, 0b1, 0b0, "mfmax.d.mm">;
def MSMULU_MM     : MatrixEletwiseClass<0b001101, 0b100, 0b0, 0b1, 0b0, 0b0, "msmulu.mm">;
def MSMULU_B_MM   : MatrixEletwiseClass<0b001101, 0b000, 0b0, 0b1, 0b0, 0b0, "msmulu.b.mm">;
def MSMULU_H_MM   : MatrixEletwiseClass<0b001101, 0b001, 0b0, 0b1, 0b0, 0b0, "msmulu.h.mm">;
def MSMULU_W_MM   : MatrixEletwiseClass<0b001101, 0b010, 0b0, 0b1, 0b0, 0b0, "msmulu.w.mm">;
def MSMULU_DW_MM  : MatrixEletwiseClass<0b001101, 0b011, 0b0, 0b1, 0b0, 0b0, "msmulu.dw.mm">;
def MSMULU_HB_MM  : MatrixEletwiseClass<0b001101, 0b111, 0b0, 0b1, 0b0, 0b0, "msmulu.hb.mm">;
def MMUL_MM       : MatrixEletwiseClass<0b001101, 0b100, 0b0, 0b0, 0b1, 0b0, "mmul.mm">;
def MMUL_B_MM     : MatrixEletwiseClass<0b001101, 0b000, 0b0, 0b0, 0b1, 0b0, "mmul.b.mm">;
def MMUL_H_MM     : MatrixEletwiseClass<0b001101, 0b001, 0b0, 0b0, 0b1, 0b0, "mmul.h.mm">;
def MMUL_W_MM     : MatrixEletwiseClass<0b001101, 0b010, 0b0, 0b0, 0b1, 0b0, "mmul.w.mm">;
def MMUL_DW_MM    : MatrixEletwiseClass<0b001101, 0b011, 0b0, 0b0, 0b1, 0b0, "mmul.dw.mm">;
def MMUL_HB_MM    : MatrixEletwiseClass<0b001101, 0b111, 0b0, 0b0, 0b1, 0b0, "mmul.hb.mm">;
def MSMUL_MM      : MatrixEletwiseClass<0b001101, 0b100, 0b0, 0b1, 0b1, 0b0, "msmul.mm">;
def MSMUL_B_MM    : MatrixEletwiseClass<0b001101, 0b000, 0b0, 0b1, 0b1, 0b0, "msmul.b.mm">;
def MSMUL_H_MM    : MatrixEletwiseClass<0b001101, 0b001, 0b0, 0b1, 0b1, 0b0, "msmul.h.mm">;
def MSMUL_W_MM    : MatrixEletwiseClass<0b001101, 0b010, 0b0, 0b1, 0b1, 0b0, "msmul.w.mm">;
def MSMUL_DW_MM   : MatrixEletwiseClass<0b001101, 0b011, 0b0, 0b1, 0b1, 0b0, "msmul.dw.mm">;
def MSMUL_HB_MM   : MatrixEletwiseClass<0b001101, 0b111, 0b0, 0b1, 0b1, 0b0, "msmul.hb.mm">;
def MFMUL_MM      : MatrixEletwiseClass<0b001101, 0b100, 0b1, 0b0, 0b1, 0b0, "mfmul.mm">;
def MFMUL_CF_MM   : MatrixEletwiseClass<0b001101, 0b000, 0b1, 0b0, 0b1, 0b0, "mfmul.cf.mm">;
def MFMUL_HF_MM   : MatrixEletwiseClass<0b001101, 0b001, 0b1, 0b0, 0b1, 0b0, "mfmul.hf.mm">;
def MFMUL_F_MM    : MatrixEletwiseClass<0b001101, 0b010, 0b1, 0b0, 0b1, 0b0, "mfmul.f.mm">;
def MFMUL_D_MM    : MatrixEletwiseClass<0b001101, 0b011, 0b1, 0b0, 0b1, 0b0, "mfmul.d.mm">;
def MMULHU_MM     : MatrixEletwiseClass<0b001110, 0b100, 0b0, 0b0, 0b0, 0b0, "mmulhu.mm">;
def MMULHU_B_MM   : MatrixEletwiseClass<0b001110, 0b000, 0b0, 0b0, 0b0, 0b0, "mmulhu.b.mm">;
def MMULHU_H_MM   : MatrixEletwiseClass<0b001110, 0b001, 0b0, 0b0, 0b0, 0b0, "mmulhu.h.mm">;
def MMULHU_W_MM   : MatrixEletwiseClass<0b001110, 0b010, 0b0, 0b0, 0b0, 0b0, "mmulhu.w.mm">;
def MMULHU_DW_MM  : MatrixEletwiseClass<0b001110, 0b011, 0b0, 0b0, 0b0, 0b0, "mmulhu.dw.mm">;
def MMULHU_HB_MM  : MatrixEletwiseClass<0b001110, 0b111, 0b0, 0b0, 0b0, 0b0, "mmulhu.hb.mm">;
def MMULH_MM      : MatrixEletwiseClass<0b001110, 0b100, 0b0, 0b0, 0b1, 0b0, "mmulh.mm">;
def MMULH_B_MM    : MatrixEletwiseClass<0b001110, 0b000, 0b0, 0b0, 0b1, 0b0, "mmulh.b.mm">;
def MMULH_H_MM    : MatrixEletwiseClass<0b001110, 0b001, 0b0, 0b0, 0b1, 0b0, "mmulh.h.mm">;
def MMULH_W_MM    : MatrixEletwiseClass<0b001110, 0b010, 0b0, 0b0, 0b1, 0b0, "mmulh.w.mm">;
def MMULH_DW_MM   : MatrixEletwiseClass<0b001110, 0b011, 0b0, 0b0, 0b1, 0b0, "mmulh.dw.mm">;
def MMULH_HB_MM   : MatrixEletwiseClass<0b001110, 0b111, 0b0, 0b0, 0b1, 0b0, "mmulh.hb.mm">;
def MMULHSU_MM    : MatrixEletwiseClass<0b001110, 0b100, 0b0, 0b1, 0b0, 0b0, "mmulhsu.mm">;
def MMULHSU_B_MM  : MatrixEletwiseClass<0b001110, 0b000, 0b0, 0b1, 0b0, 0b0, "mmulhsu.b.mm">;
def MMULHSU_H_MM  : MatrixEletwiseClass<0b001110, 0b001, 0b0, 0b1, 0b0, 0b0, "mmulhsu.h.mm">;
def MMULHSU_W_MM  : MatrixEletwiseClass<0b001110, 0b010, 0b0, 0b1, 0b0, 0b0, "mmulhsu.w.mm">;
def MMULHSU_DW_MM : MatrixEletwiseClass<0b001110, 0b011, 0b0, 0b1, 0b0, 0b0, "mmulhsu.dw.mm">;
def MMULHSU_HB_MM : MatrixEletwiseClass<0b001110, 0b111, 0b0, 0b1, 0b0, 0b0, "mmulhsu.hb.mm">;
def MSMULSU_MM    : MatrixEletwiseClass<0b001110, 0b100, 0b0, 0b1, 0b1, 0b0, "msmulsu.mm">;
def MSMULSU_B_MM  : MatrixEletwiseClass<0b001110, 0b000, 0b0, 0b1, 0b1, 0b0, "msmulsu.b.mm">;
def MSMULSU_H_MM  : MatrixEletwiseClass<0b001110, 0b001, 0b0, 0b1, 0b1, 0b0, "msmulsu.h.mm">;
def MSMULSU_W_MM  : MatrixEletwiseClass<0b001110, 0b010, 0b0, 0b1, 0b1, 0b0, "msmulsu.w.mm">;
def MSMULSU_DW_MM : MatrixEletwiseClass<0b001110, 0b011, 0b0, 0b1, 0b1, 0b0, "msmulsu.dw.mm">;
def MSMULSU_HB_MM : MatrixEletwiseClass<0b001110, 0b111, 0b0, 0b1, 0b1, 0b0, "msmulsu.hb.mm">;
def MFDIV_MM      : MatrixEletwiseClass<0b001110, 0b100, 0b1, 0b0, 0b1, 0b0, "mfdiv.mm">;
def MFDIV_CF_MM   : MatrixEletwiseClass<0b001110, 0b000, 0b1, 0b0, 0b1, 0b0, "mfdiv.cf.mm">;
def MFDIV_HF_MM   : MatrixEletwiseClass<0b001110, 0b001, 0b1, 0b0, 0b1, 0b0, "mfdiv.hf.mm">;
def MFDIV_F_MM    : MatrixEletwiseClass<0b001110, 0b010, 0b1, 0b0, 0b1, 0b0, "mfdiv.f.mm">;
def MFDIV_D_MM    : MatrixEletwiseClass<0b001110, 0b011, 0b1, 0b0, 0b1, 0b0, "mfdiv.d.mm">;
def MWMULU_MM     : MatrixEletwiseClass<0b001111, 0b100, 0b0, 0b0, 0b0, 0b0, "mwmulu.mm">;
def MWMULU_B_MM   : MatrixEletwiseClass<0b001111, 0b000, 0b0, 0b0, 0b0, 0b0, "mwmulu.b.mm">;
def MWMULU_H_MM   : MatrixEletwiseClass<0b001111, 0b001, 0b0, 0b0, 0b0, 0b0, "mwmulu.h.mm">;
def MWMULU_W_MM   : MatrixEletwiseClass<0b001111, 0b010, 0b0, 0b0, 0b0, 0b0, "mwmulu.w.mm">;
def MWMULU_HB_MM  : MatrixEletwiseClass<0b001111, 0b111, 0b0, 0b0, 0b0, 0b0, "mwmulu.hb.mm">;
def MWMUL_MM      : MatrixEletwiseClass<0b001111, 0b100, 0b0, 0b0, 0b1, 0b0, "mwmul.mm">;
def MWMUL_B_MM    : MatrixEletwiseClass<0b001111, 0b000, 0b0, 0b0, 0b1, 0b0, "mwmul.b.mm">;
def MWMUL_H_MM    : MatrixEletwiseClass<0b001111, 0b001, 0b0, 0b0, 0b1, 0b0, "mwmul.h.mm">;
def MWMUL_W_MM    : MatrixEletwiseClass<0b001111, 0b010, 0b0, 0b0, 0b1, 0b0, "mwmul.w.mm">;
def MWMUL_HB_MM   : MatrixEletwiseClass<0b001111, 0b111, 0b0, 0b0, 0b1, 0b0, "mwmul.hb.mm">;
def MWMULSU_MM    : MatrixEletwiseClass<0b001111, 0b100, 0b0, 0b1, 0b1, 0b0, "mwmulsu.mm">;
def MWMULSU_B_MM  : MatrixEletwiseClass<0b001111, 0b000, 0b0, 0b1, 0b1, 0b0, "mwmulsu.b.mm">;
def MWMULSU_H_MM  : MatrixEletwiseClass<0b001111, 0b001, 0b0, 0b1, 0b1, 0b0, "mwmulsu.h.mm">;
def MWMULSU_W_MM  : MatrixEletwiseClass<0b001111, 0b010, 0b0, 0b1, 0b1, 0b0, "mwmulsu.w.mm">;
def MWMULSU_HB_MM : MatrixEletwiseClass<0b001111, 0b111, 0b0, 0b1, 0b1, 0b0, "mwmulsu.hb.mm">;
def MFWMUL_MM     : MatrixEletwiseClass<0b001111, 0b100, 0b1, 0b0, 0b1, 0b0, "mfwmul.mm">;
def MFWMUL_CF_MM  : MatrixEletwiseClass<0b001111, 0b000, 0b1, 0b0, 0b1, 0b0, "mfwmul.cf.mm">;
def MFWMUL_HF_MM  : MatrixEletwiseClass<0b001111, 0b001, 0b1, 0b0, 0b1, 0b0, "mfwmul.hf.mm">;
def MFWMUL_F_MM   : MatrixEletwiseClass<0b001111, 0b010, 0b1, 0b0, 0b1, 0b0, "mfwmul.f.mm">;
def MAND_MM       : MatrixEletwiseClass<0b010000, 0b100, 0b0, 0b0, 0b0, 0b0, "mand.mm">;
def MOR_MM        : MatrixEletwiseClass<0b010000, 0b100, 0b0, 0b1, 0b0, 0b0, "mor.mm">;
def MXOR_MM       : MatrixEletwiseClass<0b010000, 0b100, 0b0, 0b1, 0b1, 0b0, "mxor.mm">;
def MFSQRT_M      : MatrixEletwiseTwoAddrClass<0b010000, 0b100, 0b1, 0b0, 0b1, 0b0, "mfsqrt.m">;
def MFSQRT_CF_M   : MatrixEletwiseTwoAddrClass<0b010000, 0b000, 0b1, 0b0, 0b1, 0b0, "mfsqrt.cf.m">;
def MFSQRT_HF_M   : MatrixEletwiseTwoAddrClass<0b010000, 0b001, 0b1, 0b0, 0b1, 0b0, "mfsqrt.hf.m">;
def MFSQRT_F_M    : MatrixEletwiseTwoAddrClass<0b010000, 0b010, 0b1, 0b0, 0b1, 0b0, "mfsqrt.f.m">;
def MFSQRT_D_M    : MatrixEletwiseTwoAddrClass<0b010000, 0b011, 0b1, 0b0, 0b1, 0b0, "mfsqrt.d.m">;
def MSLL_MM       : MatrixEletwiseClass<0b010001, 0b100, 0b0, 0b0, 0b0, 0b0, "msll.mm">;
def MSLL_B_MM     : MatrixEletwiseClass<0b010001, 0b000, 0b0, 0b0, 0b0, 0b0, "msll.b.mm">;
def MSLL_H_MM     : MatrixEletwiseClass<0b010001, 0b001, 0b0, 0b0, 0b0, 0b0, "msll.h.mm">;
def MSLL_W_MM     : MatrixEletwiseClass<0b010001, 0b010, 0b0, 0b0, 0b0, 0b0, "msll.w.mm">;
def MSLL_DW_MM    : MatrixEletwiseClass<0b010001, 0b011, 0b0, 0b0, 0b0, 0b0, "msll.dw.mm">;
def MSLL_HB_MM    : MatrixEletwiseClass<0b010001, 0b111, 0b0, 0b0, 0b0, 0b0, "msll.hb.mm">;
def MSRL_MM       : MatrixEletwiseClass<0b010001, 0b100, 0b0, 0b1, 0b0, 0b0, "msrl.mm">;
def MSRL_B_MM     : MatrixEletwiseClass<0b010001, 0b000, 0b0, 0b1, 0b0, 0b0, "msrl.b.mm">;
def MSRL_H_MM     : MatrixEletwiseClass<0b010001, 0b001, 0b0, 0b1, 0b0, 0b0, "msrl.h.mm">;
def MSRL_W_MM     : MatrixEletwiseClass<0b010001, 0b010, 0b0, 0b1, 0b0, 0b0, "msrl.w.mm">;
def MSRL_DW_MM    : MatrixEletwiseClass<0b010001, 0b011, 0b0, 0b1, 0b0, 0b0, "msrl.dw.mm">;
def MSRL_HB_MM    : MatrixEletwiseClass<0b010001, 0b111, 0b0, 0b1, 0b0, 0b0, "msrl.hb.mm">;
def MSRA_MM       : MatrixEletwiseClass<0b010001, 0b100, 0b0, 0b1, 0b1, 0b0, "msra.mm">;
def MSRA_B_MM     : MatrixEletwiseClass<0b010001, 0b000, 0b0, 0b1, 0b1, 0b0, "msra.b.mm">;
def MSRA_H_MM     : MatrixEletwiseClass<0b010001, 0b001, 0b0, 0b1, 0b1, 0b0, "msra.h.mm">;
def MSRA_W_MM     : MatrixEletwiseClass<0b010001, 0b010, 0b0, 0b1, 0b1, 0b0, "msra.w.mm">;
def MSRA_DW_MM    : MatrixEletwiseClass<0b010001, 0b011, 0b0, 0b1, 0b1, 0b0, "msra.dw.mm">;
def MSRA_HB_MM    : MatrixEletwiseClass<0b010001, 0b111, 0b0, 0b1, 0b1, 0b0, "msra.hb.mm">;

// Type Convert Instructions
def MCVT_X_XU_M    : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b000, 0b00, 0b1, 0b0, "mcvt.x.xu.m">;
def MCVT_HB_UHB_M  : MatrixTypeCvtClass<0b011000, 0b111, 0b0, 0b000, 0b00, 0b1, 0b0, "mcvt.hb.uhb.m">;
def MCVT_B_UB_M    : MatrixTypeCvtClass<0b011000, 0b000, 0b0, 0b000, 0b00, 0b1, 0b0, "mcvt.b.ub.m">;
def MCVT_H_UH_M    : MatrixTypeCvtClass<0b011000, 0b001, 0b0, 0b000, 0b00, 0b1, 0b0, "mcvt.h.uh.m">;
def MCVT_W_UW_M    : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b000, 0b00, 0b1, 0b0, "mcvt.w.uw.m">;
def MCVT_DW_UDW_M  : MatrixTypeCvtClass<0b011000, 0b011, 0b0, 0b000, 0b00, 0b1, 0b0, "mcvt.dw.udw.m">;
def MCVT_XU_X_M    : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b001, 0b00, 0b1, 0b0, "mcvt.xu.x.m">;
def MCVT_UHB_HB_M  : MatrixTypeCvtClass<0b011000, 0b111, 0b0, 0b001, 0b00, 0b1, 0b0, "mcvt.uhb.hb.m">;
def MCVT_UB_B_M    : MatrixTypeCvtClass<0b011000, 0b000, 0b0, 0b001, 0b00, 0b1, 0b0, "mcvt.ub.b.m">;
def MCVT_UH_H_M    : MatrixTypeCvtClass<0b011000, 0b001, 0b0, 0b001, 0b00, 0b1, 0b0, "mcvt.uh.h.m">;
def MCVT_UW_W_M    : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b001, 0b00, 0b1, 0b0, "mcvt.uw.w.m">;
def MCVT_UDW_DW_M  : MatrixTypeCvtClass<0b011000, 0b011, 0b0, 0b001, 0b00, 0b1, 0b0, "mcvt.udw.dw.m">;
def MWCVTU_XW_X_M  : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b000, 0b01, 0b0, 0b0, "mwcvtu.xw.x.m">;
def MWCVTU_XQ_X_M  : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b001, 0b01, 0b0, 0b0, "mwcvtu.xq.x.m">;
def MWCVTU_XO_X_M  : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b010, 0b01, 0b0, 0b0, "mwcvtu.xo.x.m">;
def MWCVTU_B_HB_M  : MatrixTypeCvtClass<0b011000, 0b111, 0b0, 0b000, 0b01, 0b0, 0b0, "mwcvtu.b.hb.m">;
def MWCVTU_H_HB_M  : MatrixTypeCvtClass<0b011000, 0b111, 0b0, 0b001, 0b01, 0b0, 0b0, "mwcvtu.h.hb.m">;
def MWCVTU_W_HB_M  : MatrixTypeCvtClass<0b011000, 0b111, 0b0, 0b010, 0b01, 0b0, 0b0, "mwcvtu.w.hb.m">;
def MWCVTU_H_B_M   : MatrixTypeCvtClass<0b011000, 0b000, 0b0, 0b000, 0b01, 0b0, 0b0, "mwcvtu.h.b.m">;
def MWCVTU_W_B_M   : MatrixTypeCvtClass<0b011000, 0b000, 0b0, 0b001, 0b01, 0b0, 0b0, "mwcvtu.w.b.m">;
def MWCVTU_W_H_M   : MatrixTypeCvtClass<0b011000, 0b001, 0b0, 0b000, 0b01, 0b0, 0b0, "mwcvtu.w.h.m">;
def MWCVTU_DW_W_M  : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b000, 0b01, 0b0, 0b0, "mwcvtu.dw.w.m">;
def MWCVT_XW_X_M   : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b000, 0b01, 0b1, 0b0, "mwcvt.xw.x.m">;
def MWCVT_XQ_X_M   : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b001, 0b01, 0b1, 0b0, "mwcvt.xq.x.m">;
def MWCVT_XO_X_M   : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b010, 0b01, 0b1, 0b0, "mwcvt.xo.x.m">;
def MWCVT_B_HB_M   : MatrixTypeCvtClass<0b011000, 0b111, 0b0, 0b000, 0b01, 0b1, 0b0, "mwcvt.b.hb.m">;
def MWCVT_H_HB_M   : MatrixTypeCvtClass<0b011000, 0b111, 0b0, 0b001, 0b01, 0b1, 0b0, "mwcvt.h.hb.m">;
def MWCVT_W_HB_M   : MatrixTypeCvtClass<0b011000, 0b111, 0b0, 0b010, 0b01, 0b1, 0b0, "mwcvt.w.hb.m">;
def MWCVT_H_B_M    : MatrixTypeCvtClass<0b011000, 0b000, 0b0, 0b000, 0b01, 0b1, 0b0, "mwcvt.h.b.m">;
def MWCVT_W_B_M    : MatrixTypeCvtClass<0b011000, 0b000, 0b0, 0b001, 0b01, 0b1, 0b0, "mwcvt.w.b.m">;
def MWCVT_W_H_M    : MatrixTypeCvtClass<0b011000, 0b001, 0b0, 0b000, 0b01, 0b1, 0b0, "mwcvt.w.h.m">;
def MWCVT_DW_W_M   : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b000, 0b01, 0b1, 0b0, "mwcvt.dw.w.m">;
def MNCVTU_X_XW_M  : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b000, 0b10, 0b0, 0b0, "mncvtu.x.xw.m">;
def MNCVTU_X_XQ_M  : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b001, 0b10, 0b0, 0b0, "mncvtu.x.xq.m">;
def MNCVTU_X_XO_M  : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b010, 0b10, 0b0, 0b0, "mncvtu.x.xo.m">;
def MNCVTU_HB_B_M  : MatrixTypeCvtClass<0b011000, 0b000, 0b0, 0b000, 0b10, 0b0, 0b0, "mncvtu.hb.b.m">;
def MNCVTU_HB_H_M  : MatrixTypeCvtClass<0b011000, 0b001, 0b0, 0b001, 0b10, 0b0, 0b0, "mncvtu.hb.h.m">;
def MNCVTU_HB_W_M  : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b010, 0b10, 0b0, 0b0, "mncvtu.hb.w.m">;
def MNCVTU_B_H_M   : MatrixTypeCvtClass<0b011000, 0b001, 0b0, 0b000, 0b10, 0b0, 0b0, "mncvtu.b.h.m">;
def MNCVTU_B_W_M   : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b001, 0b10, 0b0, 0b0, "mncvtu.b.w.m">;
def MNCVTU_H_W_M   : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b000, 0b10, 0b0, 0b0, "mncvtu.h.w.m">;
def MNCVTU_W_DW_M  : MatrixTypeCvtClass<0b011000, 0b011, 0b0, 0b000, 0b10, 0b0, 0b0, "mncvtu.w.dw.m">;
def MNCVT_X_XW_M   : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b000, 0b10, 0b1, 0b0, "mncvt.x.xw.m">;
def MNCVT_X_XQ_M   : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b001, 0b10, 0b1, 0b0, "mncvt.x.xq.m">;
def MNCVT_X_XO_M   : MatrixTypeCvtClass<0b011000, 0b100, 0b0, 0b010, 0b10, 0b1, 0b0, "mncvt.x.xo.m">;
def MNCVT_HB_B_M   : MatrixTypeCvtClass<0b011000, 0b000, 0b0, 0b000, 0b10, 0b1, 0b0, "mncvt.hb.b.m">;
def MNCVT_HB_H_M   : MatrixTypeCvtClass<0b011000, 0b001, 0b0, 0b001, 0b10, 0b1, 0b0, "mncvt.hb.h.m">;
def MNCVT_HB_W_M   : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b010, 0b10, 0b1, 0b0, "mncvt.hb.w.m">;
def MNCVT_B_H_M    : MatrixTypeCvtClass<0b011000, 0b001, 0b0, 0b000, 0b10, 0b1, 0b0, "mncvt.b.h.m">;
def MNCVT_B_W_M    : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b001, 0b10, 0b1, 0b0, "mncvt.b.w.m">;
def MNCVT_H_W_M    : MatrixTypeCvtClass<0b011000, 0b010, 0b0, 0b000, 0b10, 0b1, 0b0, "mncvt.h.w.m">;
def MNCVT_W_DW_M   : MatrixTypeCvtClass<0b011000, 0b011, 0b0, 0b000, 0b10, 0b1, 0b0, "mncvt.w.dw.m">;
def MFCVT_BF_HF_M  : MatrixTypeCvtClass<0b011001, 0b001, 0b1, 0b000, 0b00, 0b0, 0b0, "mfcvt.bf.hf.m">;
def MFCVT_HF_BF_M  : MatrixTypeCvtClass<0b011001, 0b001, 0b1, 0b000, 0b00, 0b1, 0b0, "mfcvt.hf.bf.m">;
def MFWCVT_FW_F_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b001, 0b01, 0b0, 0b0, "mfwcvt.fw.f.m">;
def MFWCVT_HF_CF_M : MatrixTypeCvtClass<0b011001, 0b000, 0b1, 0b001, 0b01, 0b0, 0b0, "mfwcvt.hf.cf.m">;
def MFWCVT_F_HF_M  : MatrixTypeCvtClass<0b011001, 0b001, 0b1, 0b001, 0b01, 0b0, 0b0, "mfwcvt.f.hf.m">;
def MFWCVT_D_F_M   : MatrixTypeCvtClass<0b011001, 0b010, 0b1, 0b001, 0b01, 0b0, 0b0, "mfwcvt.d.f.m">;
def MFNCVT_F_FW_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b001, 0b10, 0b0, 0b0, "mfncvt.f.fw.m">;
def MFNCVT_CF_HF_M : MatrixTypeCvtClass<0b011001, 0b001, 0b1, 0b001, 0b10, 0b0, 0b0, "mfncvt.cf.hf.m">;
def MFNCVT_HF_F_M  : MatrixTypeCvtClass<0b011001, 0b010, 0b1, 0b001, 0b10, 0b0, 0b0, "mfncvt.hf.f.m">;
def MFNCVT_F_D_M   : MatrixTypeCvtClass<0b011001, 0b011, 0b1, 0b001, 0b10, 0b0, 0b0, "mfncvt.f.d.m">;
def MFCVTU_F_X_M   : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b010, 0b00, 0b0, 0b0, "mfcvtu.f.x.m">;
def MFCVTU_HF_H_M  : MatrixTypeCvtClass<0b011001, 0b001, 0b1, 0b010, 0b00, 0b0, 0b0, "mfcvtu.hf.h.m">;
def MFCVTU_F_W_M   : MatrixTypeCvtClass<0b011001, 0b010, 0b1, 0b010, 0b00, 0b0, 0b0, "mfcvtu.f.w.m">;
def MFCVTU_D_DW_M  : MatrixTypeCvtClass<0b011001, 0b011, 0b1, 0b010, 0b00, 0b0, 0b0, "mfcvtu.d.dw.m">;
def MFCVT_F_X_M    : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b010, 0b00, 0b1, 0b0, "mfcvt.f.x.m">;
def MFCVT_HF_H_M   : MatrixTypeCvtClass<0b011001, 0b001, 0b1, 0b010, 0b00, 0b1, 0b0, "mfcvt.hf.h.m">;
def MFCVT_F_W_M    : MatrixTypeCvtClass<0b011001, 0b010, 0b1, 0b010, 0b00, 0b1, 0b0, "mfcvt.f.w.m">;
def MFCVT_D_DW_M   : MatrixTypeCvtClass<0b011001, 0b011, 0b1, 0b010, 0b00, 0b1, 0b0, "mfcvt.d.dw.m">;
def MFWCVTU_FW_X_M : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b010, 0b01, 0b0, 0b0, "mfwcvtu.fw.x.m">;
def MFWCVTU_HF_B_M : MatrixTypeCvtClass<0b011001, 0b000, 0b1, 0b010, 0b01, 0b0, 0b0, "mfwcvtu.hf.b.m">;
def MFWCVTU_F_H_M  : MatrixTypeCvtClass<0b011001, 0b001, 0b1, 0b010, 0b01, 0b0, 0b0, "mfwcvtu.f.h.m">;
def MFWCVTU_D_W_M  : MatrixTypeCvtClass<0b011001, 0b010, 0b1, 0b010, 0b01, 0b0, 0b0, "mfwcvtu.d.w.m">;
def MFWCVT_FW_X_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b010, 0b01, 0b1, 0b0, "mfwcvt.fw.x.m">;
def MFWCVT_HF_B_M  : MatrixTypeCvtClass<0b011001, 0b000, 0b1, 0b010, 0b01, 0b1, 0b0, "mfwcvt.hf.b.m">;
def MFWCVT_F_H_M   : MatrixTypeCvtClass<0b011001, 0b001, 0b1, 0b010, 0b01, 0b1, 0b0, "mfwcvt.f.h.m">;
def MFWCVT_D_W_M   : MatrixTypeCvtClass<0b011001, 0b010, 0b1, 0b010, 0b01, 0b1, 0b0, "mfwcvt.d.w.m">;
def MFNCVTU_F_XW_M : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b010, 0b10, 0b0, 0b0, "mfncvtu.f.xw.m">;
def MFNCVTU_HF_W_M : MatrixTypeCvtClass<0b011001, 0b010, 0b1, 0b010, 0b10, 0b0, 0b0, "mfncvtu.hf.w.m">;
def MFNCVTU_F_DW_M : MatrixTypeCvtClass<0b011001, 0b011, 0b1, 0b010, 0b10, 0b0, 0b0, "mfncvtu.f.dw.m">;
def MFNCVT_F_XW_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b010, 0b10, 0b1, 0b0, "mfncvt.f.xw.m">;
def MFNCVT_HF_W_M  : MatrixTypeCvtClass<0b011001, 0b010, 0b1, 0b010, 0b10, 0b1, 0b0, "mfncvt.hf.w.m">;
def MFNCVT_F_DW_M  : MatrixTypeCvtClass<0b011001, 0b011, 0b1, 0b010, 0b10, 0b1, 0b0, "mfncvt.f.dw.m">;
def MFCVTU_X_F_M   : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b010, 0b00, 0b0, 0b0, "mfcvtu.x.f.m">;
def MFCVTU_H_HF_M  : MatrixTypeCvtClass<0b011001, 0b001, 0b0, 0b010, 0b00, 0b0, 0b0, "mfcvtu.h.hf.m">;
def MFCVTU_W_F_M   : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b010, 0b00, 0b0, 0b0, "mfcvtu.w.f.m">;
def MFCVTU_DW_D_M  : MatrixTypeCvtClass<0b011001, 0b011, 0b0, 0b010, 0b00, 0b0, 0b0, "mfcvtu.dw.d.m">;
def MFCVT_X_F_M    : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b010, 0b00, 0b1, 0b0, "mfcvt.x.f.m">;
def MFCVT_H_HF_M   : MatrixTypeCvtClass<0b011001, 0b001, 0b0, 0b010, 0b00, 0b1, 0b0, "mfcvt.h.hf.m">;
def MFCVT_W_F_M    : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b010, 0b00, 0b1, 0b0, "mfcvt.w.f.m">;
def MFCVT_DW_D_M   : MatrixTypeCvtClass<0b011001, 0b011, 0b0, 0b010, 0b00, 0b1, 0b0, "mfcvt.dw.d.m">;
def MFWCVTU_XW_F_M : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b010, 0b01, 0b0, 0b0, "mfwcvtu.xw.f.m">;
def MFWCVTU_W_HF_M : MatrixTypeCvtClass<0b011001, 0b001, 0b0, 0b010, 0b01, 0b0, 0b0, "mfwcvtu.w.hf.m">;
def MFWCVTU_DW_F_M : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b010, 0b01, 0b0, 0b0, "mfwcvtu.dw.f.m">;
def MFWCVT_XW_F_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b010, 0b01, 0b1, 0b0, "mfwcvt.xw.f.m">;
def MFWCVT_W_HF_M  : MatrixTypeCvtClass<0b011001, 0b001, 0b0, 0b010, 0b01, 0b1, 0b0, "mfwcvt.w.hf.m">;
def MFWCVT_DW_F_M  : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b010, 0b01, 0b1, 0b0, "mfwcvt.dw.f.m">;
def MFNCVTU_X_FW_M : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b010, 0b10, 0b0, 0b0, "mfncvtu.x.fw.m">;
def MFNCVTU_B_HF_M : MatrixTypeCvtClass<0b011001, 0b001, 0b0, 0b010, 0b10, 0b0, 0b0, "mfncvtu.b.hf.m">;
def MFNCVTU_H_F_M  : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b010, 0b10, 0b0, 0b0, "mfncvtu.h.f.m">;
def MFNCVTU_W_D_M  : MatrixTypeCvtClass<0b011001, 0b011, 0b0, 0b010, 0b10, 0b0, 0b0, "mfncvtu.w.d.m">;
def MFNCVT_X_FW_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b010, 0b10, 0b1, 0b0, "mfncvt.x.fw.m">;
def MFNCVT_B_HF_M  : MatrixTypeCvtClass<0b011001, 0b001, 0b0, 0b010, 0b10, 0b1, 0b0, "mfncvt.b.hf.m">;
def MFNCVT_H_F_M   : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b010, 0b10, 0b1, 0b0, "mfncvt.h.f.m">;
def MFNCVT_W_D_M   : MatrixTypeCvtClass<0b011001, 0b011, 0b0, 0b010, 0b10, 0b1, 0b0, "mfncvt.w.d.m">;
def MFWCVTU_FQ_X_M : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b110, 0b01, 0b0, 0b0, "mfwcvtu.fq.x.m">;
def MFWCVTU_HF_HB_M: MatrixTypeCvtClass<0b011001, 0b111, 0b1, 0b110, 0b01, 0b0, 0b0, "mfwcvtu.hf.hb.m">;
def MFWCVTU_F_B_M  : MatrixTypeCvtClass<0b011001, 0b000, 0b1, 0b110, 0b01, 0b0, 0b0, "mfwcvtu.f.b.m">;
def MFWCVT_FQ_X_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b110, 0b01, 0b1, 0b0, "mfwcvt.fq.x.m">;
def MFWCVT_HF_HB_M : MatrixTypeCvtClass<0b011001, 0b111, 0b1, 0b110, 0b01, 0b1, 0b0, "mfwcvt.hf.hb.m">;
def MFWCVT_F_B_M   : MatrixTypeCvtClass<0b011001, 0b000, 0b1, 0b110, 0b01, 0b1, 0b0, "mfwcvt.f.b.m">;
def MFWCVTU_FO_X_M : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b111, 0b01, 0b0, 0b0, "mfwcvtu.fo.x.m">;
def MFWCVTU_F_HB_M : MatrixTypeCvtClass<0b011001, 0b111, 0b1, 0b111, 0b01, 0b0, 0b0, "mfwcvtu.f.hb.m">;
def MFWCVT_FO_X_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b1, 0b111, 0b01, 0b1, 0b0, "mfwcvt.fo.x.m">;
def MFWCVT_F_HB_M  : MatrixTypeCvtClass<0b011001, 0b111, 0b1, 0b111, 0b01, 0b1, 0b0, "mfwcvt.f.hb.m">;
def MFNCVTU_X_FQ_M : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b110, 0b10, 0b0, 0b0, "mfncvtu.x.fq.m">;
def MFNCVTU_HB_HF_M: MatrixTypeCvtClass<0b011001, 0b001, 0b0, 0b110, 0b10, 0b0, 0b0, "mfncvtu.hb.hf.m">;
def MFNCVTU_B_F_M  : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b110, 0b10, 0b0, 0b0, "mfncvtu.b.f.m">;
def MFNCVT_X_FQ_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b110, 0b10, 0b1, 0b0, "mfncvt.x.fq.m">;
def MFNCVT_HB_HF_M : MatrixTypeCvtClass<0b011001, 0b001, 0b0, 0b110, 0b10, 0b1, 0b0, "mfncvt.hb.hf.m">;
def MFNCVT_B_F_M   : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b110, 0b10, 0b1, 0b0, "mfncvt.b.f.m">;
def MFNCVTU_X_FO_M : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b111, 0b10, 0b0, 0b0, "mfncvtu.x.fo.m">;
def MFNCVTU_HB_F_M : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b111, 0b10, 0b0, 0b0, "mfncvtu.hb.f.m">;
def MFNCVT_X_FO_M  : MatrixTypeCvtClass<0b011001, 0b100, 0b0, 0b111, 0b10, 0b1, 0b0, "mfncvt.x.fo.m">;
def MFNCVT_HB_F_M  : MatrixTypeCvtClass<0b011001, 0b010, 0b0, 0b111, 0b10, 0b1, 0b0, "mfncvt.hb.f.m">;

}

include "RISCVInstrInfoMatrixPatterns.td"