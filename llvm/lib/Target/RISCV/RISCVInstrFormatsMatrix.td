//===-- RISCVInstrFormatsMatrix.td - RISCV Matrix Instruction Formats --*- tablegen -*-=//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
//  This file describes the RISC-V Matrix extension instruction formats.
//
//===----------------------------------------------------------------------===//

class RVInstConfig<bits<6> funct6, bits<3> funct3, dag outs, dag ins,
                   string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rd;
  bits<5> rs1;
  bits<5> rs2;
  bit im;

  let Inst{31-26} = funct6;
  let Inst{25} = im;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;
}

class RVInstConfigImm<bits<6> funct6, bits<3> funct3, dag outs, dag ins,
                      string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rd;
  bits<10> imm;
  bit im;

  let Inst{31-26} = funct6;
  let Inst{25} = im;
  let Inst{24-15} = imm;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;
}

class RVInstLoadStore<bits<6> funct6, bits<3> eew,
                      dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<4> md;
  bit tr;
  bit ls;

  let Inst{31-26} = funct6;
  let Inst{25} = ls;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = eew;
  let Inst{11} = tr;
  let Inst{10-7} = md;
  let Opcode = OPC_OP_M.Value;
}

class RVInstDataMove<bits<6> funct6, bits<3> eew,
                     dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> rd;
  bit di;

  let Inst{31-26} = funct6;
  let Inst{25} = di;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = eew;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;
}

class RVInstZmvLoadStore<bits<6> funct6, bits<3> eew,
                      dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> md;
  bit ls;

  let Inst{31-26} = funct6;
  let Inst{25} = ls;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = eew;
  let Inst{11-7} = md;
  let Opcode = OPC_OP_M.Value;
}

class RVInstZmvM2V<bits<6> funct6, bits<3> eew,
                   dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rd;
  bits<4> rs1;
  bit var;
  bits<5> rs2;
  bit di;

  let Inst{31-26} = funct6;
  let Inst{25} = di;
  let Inst{24-20} = rs2;
  let Inst{19} = var;
  let Inst{18-15} = rs1;
  let Inst{14-12} = eew;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;
}

class RVInstZmvV2M<bits<6> funct6, bits<3> eew,
                   dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<4> rd;
  bit var;
  bits<5> rs1;
  bits<5> rs2;
  bit di;

  let Inst{31-26} = funct6;
  let Inst{25} = di;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = eew;
  let Inst{11} = var;
  let Inst{10-7} = rd;
  let Opcode = OPC_OP_M.Value;
}

class RVInstMatrixMUL<bits<6> funct6, bits<3> eew, bit fp, bit sa, bit sn, bit ma,
                      dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<4> ms2;
  bits<4> ms1;
  bits<4> md;

  let Inst{31-26} = funct6;
  let Inst{25} = fp;
  let Inst{24} = sa;
  let Inst{23-20} = ms2;
  let Inst{19} = sn;
  let Inst{18-15} = ms1;
  let Inst{14-12} = eew;
  let Inst{11} = ma;
  let Inst{10-7} = md;
  let Opcode = OPC_OP_M.Value;
}

class RVInstMatrixTypeCvt<bits<6> funct6, bits<3> eew, bit fd, bits<3> f3,
                      bits<2> nw, bit sn, bit ma, dag outs, dag ins,
                      string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<4> ms1;
  bits<4> md;

  let Inst{31-26} = funct6;
  let Inst{25} = fd;
  let Inst{24-22} = f3;
  let Inst{21-20} = nw;
  let Inst{19} = sn;
  let Inst{18-15} = ms1;
  let Inst{14-12} = eew;
  let Inst{11} = ma;
  let Inst{10-7} = md;
  let Opcode = OPC_OP_M.Value;
}
