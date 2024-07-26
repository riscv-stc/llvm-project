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


class RVInstSetMTypei<dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rd;
  bits<13> mtypei;

  let Inst{31-28} = 0b0000;
  let Inst{27-15} = mtypei;
  let Inst{14-12} = 0b111;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;

  let Defs = [MTYPE];
}

class RVInstSetMType<dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rs1;
  bits<5> rd;

  let Inst{31-28} = 0b0001;
  let Inst{27-20} = 0b00000000;
  let Inst{19-15} = rs1;
  let Inst{14-12} = 0b111;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;

  let Defs = [MTYPE];
}

class RVInstSetTilei<bits<4> funct4, dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rd;
  bits<13> mleni;

  let Inst{31-28} = funct4;
  let Inst{27-15} = mleni;
  let Inst{14-12} = 0b111;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;

//  let Defs = [TILEM, TILEK, TILEN];
}

class RVInstSetTile<bits<4> funct4, dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rs1;
  bits<5> rd;

  let Inst{31-28} = funct4;
  let Inst{27-20} = 0;
  let Inst{19-15} = rs1;
  let Inst{14-12} = 0b111;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;

//  let Defs = [TILEM, TILEK, TILEN];
}

class RVInstSetIm2col<bits<4> mit, dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rs1;
  bits<5> rs2;
  bits<5> rd;

  let Inst{31-28} = mit;
  let Inst{27-25} = 0;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = 0b111;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;

// let Defs = [MINSH, MOUTSH, MPAD, MSTDI, MINSK, MOUTSK];
}

class RVInstSetPadVal<bits<4> mit, dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rs1;
  bits<5> rd;

  let Inst{31-28} = mit;
  let Inst{27-20} = 0;
  let Inst{19-15} = rs1;
  let Inst{14-12} = 0b111;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;

//  let Defs = [MPADVAL];
}

class RVInstVL<bits<6> funct6, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> vd;

  let Inst{31-26} = funct6;
  let Inst{25} = 0;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = vd;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMUL<bits<6> funct6, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> td;

  let Inst{31-26} = funct6;
  let Inst{25} = 0;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstVS<bits<6> funct6, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> vs3;

  let Inst{31-26} = funct6;
  let Inst{25} = 1; // store
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = vs3;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMUS<bits<6> funct6, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> ts3;

  let Inst{31-26} = funct6;
  let Inst{25} = 1; // store
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = ts3;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstML<bits<6> funct6, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<2> lmul;
  bits<3> td;

  let Inst{31-26} = funct6;
  let Inst{25} = 0;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-10} = lmul;
  let Inst{9-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMS<bits<6> funct6, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<2> lmul;
  bits<3> ts3;

  let Inst{31-26} = funct6;
  let Inst{25} = 1; // store
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-10} = lmul;
  let Inst{9-7} = ts3;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMM<bits<6> funct6, bit fp, bit sn, bit sa, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> ts2;
  bits<3> ts1;
  bits<3> td;

  let Inst{31-26} = funct6;
  let Inst{25} = fp;
  let Inst{24-20} = ts2;
  let Inst{19} = sn;
  let Inst{18} = sa;
  let Inst{17-15} = ts1;
  let Inst{14-12} = 0b110;
  let Inst{11-10} = 0b00;
  let Inst{9-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMMI<bits<6> funct6, bit fp, bit sn, bit sa, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> ts2;
  bits<3> ts1;
  bits<3> td;
  bits<2> lmul;

  let Inst{31-26} = funct6;
  let Inst{25} = fp;
  let Inst{24-20} = ts2;
  let Inst{19} = sn;
  let Inst{18} = sa;
  let Inst{17-15} = ts1;
  let Inst{14-12} = 0b110;
  let Inst{11-10} = lmul;
  let Inst{9-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMMI_UNARY<bits<6> funct6, bit fp, bit sn, bit sa, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<3> ts1;
  bits<3> td;
  bits<2> lmul;

  let Inst{31-26} = funct6;
  let Inst{25} = fp;
  let Inst{24-20} = 0b00000;
  let Inst{19} = sn;
  let Inst{18} = sa;
  let Inst{17-15} = ts1;
  let Inst{14-12} = 0b110;
  let Inst{11-10} = lmul;
  let Inst{9-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMCVTI<bits<6> funct6, bit fdst, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> ts1;
  bits<3> td;
  bits<2> lmul;

  let Inst{31-26} = funct6;
  let Inst{25} = fdst;
  let Inst{24-20} = 0b00000;
  let Inst{19-15} = ts1;
  let Inst{14-12} = 0b110;
  let Inst{11-10} = lmul;
  let Inst{9-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMOVT2V<bits<6> funct6, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> td;
  bits<5> vd;

  let Inst{31-26} = funct6;
  let Inst{25} = 0;
  let Inst{24-20} = rs2;
  let Inst{19-15} = td;
  let Inst{14-12} = 0b101;
  let Inst{11-7} = vd;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMOVV2T<bits<6> funct6, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs1;
  bits<5> rs2;
  bits<5> td;

  let Inst{31-26} = funct6;
  let Inst{25} = 1;
  let Inst{24-20} = rs2;
  let Inst{19-15} = vs1;
  let Inst{14-12} = 0b101;
  let Inst{11-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMOVT2G<bits<6> funct6, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rd;
  bits<5> td;

  let Inst{31-26} = funct6;
  let Inst{25} = 0;
  let Inst{24-20} = rs2;
  let Inst{19-15} = td;
  let Inst{14-12} = 0b101;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMOVG2T<bits<6> funct6, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> td;

  let Inst{31-26} = funct6;
  let Inst{25} = 1;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = 0b101;
  let Inst{11-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}

class RVInstMOVBR2T<bits<5> funct5, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> ts1;
  bits<5> td;

  let Inst{31-26} = 0b000010;
  let Inst{25} = 0;
  let Inst{24-20} = funct5;
  let Inst{19-15} = ts1;
  let Inst{14-12} = 0b101;
  let Inst{11-7} = td;
  let Opcode = OPC_OP_M.Value;

//  let Uses = [MTYPE, TILEM, TILEK, TILEN];
}