class MatrixTypeInfo<ValueType Mat, ValueType Vec, int Sew, int Lmul, TRReg Reg,
                     ValueType Scal = XLenVT, RegisterClass ScalarReg = GPR>
{
    ValueType Matrix = Mat;
    ValueType Vector = Vec;
    int SEW = Sew;
    int LMUL = Lmul;
    TRReg TRRegClass = Reg;
    ValueType Scalar = Scal;
    RegisterClass ScalarRegClass = ScalarReg;

    string Suffix = !cond(!eq(Scal, XLenVT) : "I",
                          !eq(Scal, f16) : "F",
                          !eq(Scal, f32) : "F",
                          !eq(Scal, f64) : "F");
}

class MatrixTypeInfoMToW<MatrixTypeInfo mti, MatrixTypeInfo wti>
{
  MatrixTypeInfo Mti = mti;
  MatrixTypeInfo Wti = wti;
}

defset list<MatrixTypeInfo> AllMatrixs = {
  defset list<MatrixTypeInfo> AllIntegerMatrixs = {
    defset list<MatrixTypeInfo> AllIntegerM1 = {
      def MI8M1  : MatrixTypeInfo<mint8m1_t,  vint8m1_t,   8, 1, TRR>;
      def MI16M1 : MatrixTypeInfo<mint16m1_t, vint16m1_t, 16, 1, TRR>;
      def MI32M1 : MatrixTypeInfo<mint32m1_t, vint32m1_t, 32, 1, TRR>;
      def MI64M1 : MatrixTypeInfo<mint64m1_t, vint64m1_t, 64, 1, TRR>;
    }

    defset list<MatrixTypeInfo> AllIntegerM2 = {
      def MI8M2  : MatrixTypeInfo<mint8m2_t,  vint8m2_t,   8, 2, TRRM2>;
      def MI16M2 : MatrixTypeInfo<mint16m2_t, vint16m2_t, 16, 2, TRRM2>;
      def MI32M2 : MatrixTypeInfo<mint32m2_t, vint32m2_t, 32, 2, TRRM2>;
      def MI64M2 : MatrixTypeInfo<mint64m2_t, vint64m2_t, 64, 2, TRRM2>;
    }

    defset list<MatrixTypeInfo> AllIntegerM4 = {
      def MI8M4  : MatrixTypeInfo<mint8m4_t,  vint8m4_t,   8, 4, TRRM4>;
      def MI16M4 : MatrixTypeInfo<mint16m4_t, vint16m4_t, 16, 4, TRRM4>;
      def MI32M4 : MatrixTypeInfo<mint32m4_t, vint32m4_t, 32, 4, TRRM4>;
      def MI64M4 : MatrixTypeInfo<mint64m4_t, vint64m4_t, 64, 4, TRRM4>;
    }
  }

  defset list<MatrixTypeInfo> AllFloatMatrixs = {
    defset list<MatrixTypeInfo> AllFloatM1 = {
      def MF16M1 : MatrixTypeInfo<mfloat16m1_t, vfloat16m1_t, 16, 1, TRR, f16, FPR16>;
      def MF32M1 : MatrixTypeInfo<mfloat32m1_t, vfloat32m1_t, 32, 1, TRR, f32, FPR32>;
      def MF64M1 : MatrixTypeInfo<mfloat64m1_t, vfloat64m1_t, 64, 1, TRR, f64, FPR64>;
    }

    defset list<MatrixTypeInfo> AllFloatM2 = {
      def MF16M2 : MatrixTypeInfo<mfloat16m2_t, vfloat16m2_t, 16, 2, TRRM2, f16, FPR16>;
      def MF32M2 : MatrixTypeInfo<mfloat32m2_t, vfloat32m2_t, 32, 2, TRRM2, f32, FPR32>;
      def MF64M2 : MatrixTypeInfo<mfloat64m2_t, vfloat64m2_t, 64, 2, TRRM2, f64, FPR64>;
    }

    defset list<MatrixTypeInfo> AllFloatM4 = {
      def MF16M4 : MatrixTypeInfo<mfloat16m4_t, vfloat16m4_t, 16, 4, TRRM4, f16, FPR16>;
      def MF32M4 : MatrixTypeInfo<mfloat32m4_t, vfloat32m4_t, 32, 4, TRRM4, f32, FPR32>;
      def MF64M4 : MatrixTypeInfo<mfloat64m4_t, vfloat64m4_t, 64, 4, TRRM4, f64, FPR64>;
    }
  }
}

defset list<MatrixTypeInfoMToW> AllWidenableIntMatrixs = {
  def : MatrixTypeInfoMToW<MI8M1,   MI16M2>;
  def : MatrixTypeInfoMToW<MI8M2,   MI16M4>;
  def : MatrixTypeInfoMToW<MI16M1,  MI32M2>;
  def : MatrixTypeInfoMToW<MI16M2,  MI32M4>;
  def : MatrixTypeInfoMToW<MI32M1,  MI64M2>;
  def : MatrixTypeInfoMToW<MI32M2,  MI64M4>;
}

defset list<MatrixTypeInfoMToW> AllQuadrupleIntMatrixs = {
  def : MatrixTypeInfoMToW<MI8M1,   MI32M4>;
  def : MatrixTypeInfoMToW<MI16M1,  MI64M4>;
}

defset list<MatrixTypeInfoMToW> AllWidenableFloatMatrixs = {
  def : MatrixTypeInfoMToW<MF16M1, MF32M2>;
  def : MatrixTypeInfoMToW<MF16M2, MF32M4>;
  def : MatrixTypeInfoMToW<MF32M1, MF64M2>;
  def : MatrixTypeInfoMToW<MF32M2, MF64M4>;
}

defset list<MatrixTypeInfoMToW> AllInt2Float = {
  def : MatrixTypeInfoMToW<MI16M1,  MF16M1>;
  def : MatrixTypeInfoMToW<MI16M2,  MF16M2>;
  def : MatrixTypeInfoMToW<MI16M4,  MF16M4>;
  def : MatrixTypeInfoMToW<MI32M1,  MF32M1>;
  def : MatrixTypeInfoMToW<MI32M2,  MF32M2>;
  def : MatrixTypeInfoMToW<MI32M4,  MF32M4>;
  def : MatrixTypeInfoMToW<MI64M1,  MF64M1>;
  def : MatrixTypeInfoMToW<MI64M2,  MF64M2>;
  def : MatrixTypeInfoMToW<MI64M4,  MF64M4>;
}

defset list<MatrixTypeInfoMToW> AllWidenableInt2Float = {
  def : MatrixTypeInfoMToW<MI8M1,   MF16M2>;
  def : MatrixTypeInfoMToW<MI8M2,   MF16M4>;
  def : MatrixTypeInfoMToW<MI16M1,  MF32M2>;
  def : MatrixTypeInfoMToW<MI16M2,  MF32M4>;
  def : MatrixTypeInfoMToW<MI32M1,  MF64M2>;
  def : MatrixTypeInfoMToW<MI32M2,  MF64M4>;
}

defset list<MatrixTypeInfoMToW> AllWidenableFloat2Int = {
  def : MatrixTypeInfoMToW<MF16M1,  MI32M2>;
  def : MatrixTypeInfoMToW<MF16M2,  MI32M4>;
  def : MatrixTypeInfoMToW<MF32M1,  MI64M2>;
  def : MatrixTypeInfoMToW<MF32M2,  MI64M4>;
}

defset list<MatrixTypeInfoMToW> AllQuadrupleInt2Float = {
  def : MatrixTypeInfoMToW<MI8M1,   MF32M4>;
  def : MatrixTypeInfoMToW<MI16M1,  MF64M4>;
}

defset list<MatrixTypeInfoMToW> AllQuadrupleFloat2Int = {
  def : MatrixTypeInfoMToW<MF16M1,  MI64M4>;
}


def riscv_mmv_s_x : SDNode<"RISCVISD::MMV_S_X",
                            SDTypeProfile<1, 3, [SDTCisSameAs<0, 1>,
                                                 SDTCisInt<2>,
                                                 SDTCisVT<3, XLenVT>]>>;

def riscv_mmv_x_s : SDNode<"RISCVISD::MMV_X_S",
                           SDTypeProfile<1, 2, [SDTCisInt<0>, SDTCisVec<1>,
                                                SDTCisVT<2, XLenVT>]>>;

// 4.2. Configuration-Setting Instructions
// Config
def : PatGpr<int_riscv_msettype, MSETTYPE>;
def : PatGpr<int_riscv_msettilem, MSETTILEM>;
def : PatGpr<int_riscv_msettilen, MSETTILEN>;
def : PatGpr<int_riscv_msettilek, MSETTILEK>;
def : PatGpr<int_riscv_msettile, MSETTILE>;

class PatUimm13<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(XLenVT(OpNode uimm13:$imm)), (Inst uimm13:$imm)>;

def : PatUimm13<int_riscv_msettilemi, MSETTILEMI>;
def : PatUimm13<int_riscv_msettileni, MSETTILENI>;
def : PatUimm13<int_riscv_msettileki, MSETTILEKI>;
def : PatUimm13<int_riscv_msettypei, MSETTYPEI>;

// 4.3. Load and Store Instructions

class PseudoMLoad<TRReg RetClass, string Base>:
      Pseudo<(outs RetClass:$rd),
             (ins GPR:$rs1, GPR:$rs2, LMULTypeIOp:$rs3),
             []>, RISCVVPseudo {
  let mayLoad = 1;
  let mayStore = 0;
  let hasSideEffects = 0;
  let BaseInstr = !cast<Instruction>(Base);
}

multiclass PseudoMLE {
  foreach mtype = AllMatrixs in {
    defvar BaseName = NAME # mtype.SEW # "_M";
    defvar PName = "Pseudo" # BaseName # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
    def PName : PseudoMLoad<mtype.TRRegClass, BaseName>;
  }
}

defm MLAE  : PseudoMLE;
defm MLBE  : PseudoMLE;
defm MLCE  : PseudoMLE;
defm MLATE : PseudoMLE;
defm MLBTE : PseudoMLE;
defm MLCTE : PseudoMLE;
defm MLRE  : PseudoMLE;

class PatMLoad<SDPatternOperator OpNode, Instruction Inst, ValueType type>
    : Pat<(type (OpNode BaseAddr:$rs1, GPR:$rs2, LMULTypeIOp:$rs3)),
          (type (Inst BaseAddr:$rs1, GPR:$rs2, LMULTypeIOp:$rs3))>;

foreach mtype = AllMatrixs in {
  defvar suffix = mtype.SEW # "_M" # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
  def : PatMLoad<int_riscv_mlae_m, !cast<Instruction>("PseudoMLAE"#suffix), mtype.Matrix>;
  def : PatMLoad<int_riscv_mlate_m, !cast<Instruction>("PseudoMLATE"#suffix), mtype.Matrix>;
  def : PatMLoad<int_riscv_mlbe_m, !cast<Instruction>("PseudoMLBE"#suffix), mtype.Matrix>;
  def : PatMLoad<int_riscv_mlbte_m, !cast<Instruction>("PseudoMLBTE"#suffix), mtype.Matrix>;
  def : PatMLoad<int_riscv_mlce_m, !cast<Instruction>("PseudoMLCE"#suffix), mtype.Matrix>;
  def : PatMLoad<int_riscv_mlcte_m, !cast<Instruction>("PseudoMLCTE"#suffix), mtype.Matrix>;
  def : PatMLoad<int_riscv_mlre_m, !cast<Instruction>("PseudoMLRE"#suffix), mtype.Matrix>;
}

class PseudoMStore<TRReg RegClass, string Base>:
      Pseudo<(outs),
             (ins RegClass:$ts3, GPR:$rs1, GPR:$rs2, LMULTypeIOp:$lmul),
             []>, RISCVVPseudo {
  let mayLoad = 0;
  let mayStore = 1;
  let hasSideEffects = 0;
  let BaseInstr = !cast<Instruction>(Base);
}

multiclass PseudoMSE {
  foreach mtype = AllMatrixs in {
    defvar BaseName = NAME # mtype.SEW # "_M";
    defvar PName = "Pseudo" # BaseName # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
    def PName : PseudoMStore<mtype.TRRegClass, BaseName>;
  }
}

defm MSAE  : PseudoMSE;
defm MSBE  : PseudoMSE;
defm MSCE  : PseudoMSE;
defm MSATE : PseudoMSE;
defm MSBTE : PseudoMSE;
defm MSCTE : PseudoMSE;
defm MSRE  : PseudoMSE;

class PatMStore<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo mtype>
    : Pat<(OpNode mtype.Matrix:$ts1, BaseAddr:$rd1, GPR:$rs2, LMULTypeIOp:$rs3),
          (Inst mtype.TRRegClass:$ts1, BaseAddr:$rd1, GPR:$rs2, LMULTypeIOp:$rs3)>;

foreach mtype = AllMatrixs in {
  defvar suffix = mtype.SEW # "_M" # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
  def : PatMStore<int_riscv_msae_m, !cast<Instruction>("PseudoMSAE"#suffix), mtype>;
  def : PatMStore<int_riscv_msate_m, !cast<Instruction>("PseudoMSATE"#suffix), mtype>;
  def : PatMStore<int_riscv_msbe_m, !cast<Instruction>("PseudoMSBE"#suffix), mtype>;
  def : PatMStore<int_riscv_msbte_m, !cast<Instruction>("PseudoMSBTE"#suffix), mtype>;
  def : PatMStore<int_riscv_msce_m, !cast<Instruction>("PseudoMSCE"#suffix), mtype>;
  def : PatMStore<int_riscv_mscte_m, !cast<Instruction>("PseudoMSCTE"#suffix), mtype>;
  def : PatMStore<int_riscv_msre_m, !cast<Instruction>("PseudoMSRE"#suffix), mtype>;
}

// 4.4. Data Move Instructions

foreach mti = AllIntegerM1 in {
def : Pat<(XLenVT (riscv_mmv_x_s (mti.Matrix TRR:$tr1), GPR:$rs2)),
          (MMV_X_S (mti.Matrix TRR:$tr1), GPR:$rs2)>;
def : Pat<(mti.Matrix (riscv_mmv_s_x (mti.Matrix TRR:$tr1), GPR:$rs2, GPR:$rs3)),
          (MMV_S_X (mti.Matrix TRR:$tr1), GPR:$rs2, GPR:$rs3)>;
}

let Predicates = [HasStdExtMatrix, HasStdExtF] in {
let mayLoad = 0, mayStore = 0, hasSideEffects = 0 in {
foreach f = FPList.fpinfo in {
let BaseInstr = MFMV_F_S in
def "PseudoMFMV_" # f.FX # "_S" : Pseudo<(outs f.fprclass:$rd),
                                         (ins TRR:$tr1, ixlenimm:$rs2),
                                         []>, RISCVVPseudo;

let BaseInstr = MFMV_S_F in
def "PseudoMFMV_S_" # f.FX : Pseudo<(outs TRR:$td),
                                    (ins TRR:$tr1, f.fprclass:$rs2, ixlenimm:$rs3),
                                    []>, RISCVVPseudo;

}
}

foreach mti = AllFloatM1 in {
def : Pat<(mti.Scalar (int_riscv_mfmv_f_s (mti.Matrix TRR:$tr1), GPR:$rs2)),
                      (!cast<Instruction>("PseudoMFMV_F"#mti.SEW#"_S")
                       (mti.Matrix TRR:$tr1), GPR:$rs2)>;

def : Pat<(mti.Matrix (int_riscv_mfmv_s_f (mti.Matrix TRR:$tr1), mti.ScalarRegClass:$rs2, GPR:$rs3)),
                      (!cast<Instruction>("PseudoMFMV_S_F"#mti.SEW)
                       (mti.Matrix TRR:$tr1), mti.ScalarRegClass:$rs2, GPR:$rs3)>;

}
} // Predicates = [HasStdExtMatrix, HasStdExtF]

foreach mti = AllMatrixs in {
def : Pat<(mti.Matrix (int_riscv_mbcar_m (mti.Matrix TRR:$tr1))), (MBCAR_M (mti.Matrix TRR:$tr1))>;
def : Pat<(mti.Matrix (int_riscv_mbcbr_m (mti.Matrix TRR:$tr1))), (MBCBR_M (mti.Matrix TRR:$tr1))>;
def : Pat<(mti.Matrix (int_riscv_mbccr_m (mti.Matrix TRR:$tr1))), (MBCCR_M (mti.Matrix TRR:$tr1))>;
def : Pat<(mti.Matrix (int_riscv_mbcac_m (mti.Matrix TRR:$tr1))), (MBCAC_M (mti.Matrix TRR:$tr1))>;
def : Pat<(mti.Matrix (int_riscv_mbcbc_m (mti.Matrix TRR:$tr1))), (MBCBC_M (mti.Matrix TRR:$tr1))>;
def : Pat<(mti.Matrix (int_riscv_mbccc_m (mti.Matrix TRR:$tr1))), (MBCCC_M (mti.Matrix TRR:$tr1))>;
def : Pat<(mti.Matrix (int_riscv_mbcae_m (mti.Matrix TRR:$tr1))), (MBCAE_M (mti.Matrix TRR:$tr1))>;
def : Pat<(mti.Matrix (int_riscv_mbcbe_m (mti.Matrix TRR:$tr1))), (MBCBE_M (mti.Matrix TRR:$tr1))>;
def : Pat<(mti.Matrix (int_riscv_mbcce_m (mti.Matrix TRR:$tr1))), (MBCCE_M (mti.Matrix TRR:$tr1))>;
}

// 4.5. Arithmetic Instructions
// 4.5.1. Matrix Multiplication Instructions
class PseudoMA<TRReg RetClass, TRReg OpClass, string Base>:
      Pseudo<(outs RetClass:$td),
             (ins RetClass:$ts3, OpClass:$tr1, OpClass:$tr2),
             []>, RISCVVPseudo {
  let mayLoad = 0;
  let mayStore = 0;
  let hasSideEffects = 0;
  let Constraints = "$td = $ts3";
  let BaseInstr = !cast<Instruction>(Base);
}

multiclass PseudoMMA {
  foreach mtype = AllIntegerMatrixs in {
    defvar PName = "Pseudo" # NAME # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
    def PName : PseudoMA<mtype.TRRegClass, mtype.TRRegClass, NAME>;
  }
}

multiclass PseudoMFMA {
  foreach mtype = AllFloatMatrixs in {
    defvar PName = "Pseudo" # NAME # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
    def PName : PseudoMA<mtype.TRRegClass, mtype.TRRegClass, NAME>;
  }
}

multiclass PseudoMWMA {
  foreach MtiToWti = AllWidenableIntMatrixs in {
    defvar Mti = MtiToWti.Mti;
    defvar Wti = MtiToWti.Wti;
    defvar PName = "Pseudo" # NAME # "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
    def PName : PseudoMA<Wti.TRRegClass, Mti.TRRegClass, NAME>;
  }
}

multiclass PseudoMFWMA {
  foreach MtiToWti = AllWidenableFloatMatrixs in {
    defvar Mti = MtiToWti.Mti;
    defvar Wti = MtiToWti.Wti;
    defvar PName = "Pseudo" # NAME # "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
    def PName : PseudoMA<Wti.TRRegClass, Mti.TRRegClass, NAME>;
  }
}

multiclass PseudoMQMA {
  foreach MtiToWti = AllQuadrupleIntMatrixs in {
    defvar Mti = MtiToWti.Mti;
    defvar Wti = MtiToWti.Wti;
    defvar PName = "Pseudo" # NAME # "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
    def PName : PseudoMA<Wti.TRRegClass, Mti.TRRegClass, NAME>;
  }
}

defm MMAU_MM   : PseudoMMA;
defm MSMAU_MM  : PseudoMMA;
defm MMA_MM    : PseudoMMA;
defm MSMA_MM   : PseudoMMA;
defm MWMAU_MM  : PseudoMWMA;
defm MSWMAU_MM : PseudoMWMA;
defm MWMA_MM   : PseudoMWMA;
defm MSWMA_MM  : PseudoMWMA;
defm MQMAU_MM  : PseudoMQMA;
defm MSQMAU_MM : PseudoMQMA;
defm MQMA_MM   : PseudoMQMA;
defm MSQMA_MM  : PseudoMQMA;
defm MFMA_MM   : PseudoMFMA;
defm MFWMA_MM  : PseudoMFWMA;

class PatMMA<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo rtype, MatrixTypeInfo otype>
    : Pat<(rtype.Matrix (OpNode (rtype.Matrix rtype.TRRegClass:$td),
                                (otype.Matrix otype.TRRegClass:$tr1),
                                (otype.Matrix otype.TRRegClass:$tr2))),
          (rtype.Matrix (Inst (rtype.Matrix rtype.TRRegClass:$td),
                              (otype.Matrix otype.TRRegClass:$tr1),
                              (otype.Matrix otype.TRRegClass:$tr2)))>;

foreach mtype = AllIntegerMatrixs in {
  defvar suffix = "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
  def : PatMMA<int_riscv_mmau_mm, !cast<Instruction>("PseudoMMAU_MM"#suffix), mtype, mtype>;
  def : PatMMA<int_riscv_msmau_mm, !cast<Instruction>("PseudoMSMAU_MM"#suffix), mtype, mtype>;
  def : PatMMA<int_riscv_mma_mm, !cast<Instruction>("PseudoMMA_MM"#suffix), mtype, mtype>;
  def : PatMMA<int_riscv_msma_mm, !cast<Instruction>("PseudoMSMA_MM"#suffix), mtype, mtype>;
}

foreach mtype = AllFloatMatrixs in {
  defvar suffix = "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
  def : PatMMA<int_riscv_mfma_mm, !cast<Instruction>("PseudoMFMA_MM"#suffix), mtype, mtype>;
}

foreach MtiToWti = AllWidenableIntMatrixs in {
  defvar Mti = MtiToWti.Mti;
  defvar Wti = MtiToWti.Wti;
  defvar suffix = "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
  def : PatMMA<int_riscv_mwmau_mm, !cast<Instruction>("PseudoMWMAU_MM"#suffix), Wti, Mti>;
  def : PatMMA<int_riscv_mswmau_mm, !cast<Instruction>("PseudoMSWMAU_MM"#suffix), Wti, Mti>;
  def : PatMMA<int_riscv_mwma_mm, !cast<Instruction>("PseudoMWMA_MM"#suffix), Wti, Mti>;
  def : PatMMA<int_riscv_mswma_mm, !cast<Instruction>("PseudoMSWMA_MM"#suffix), Wti, Mti>;
}

foreach MtiToWti = AllWidenableFloatMatrixs in {
  defvar Mti = MtiToWti.Mti;
  defvar Wti = MtiToWti.Wti;
  defvar suffix = "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
  def : PatMMA<int_riscv_mfwma_mm, !cast<Instruction>("PseudoMFWMA_MM"#suffix), Wti, Mti>;
}

foreach MtiToWti = AllQuadrupleIntMatrixs in {
  defvar Mti = MtiToWti.Mti;
  defvar Wti = MtiToWti.Wti;
  defvar suffix = "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
  def : PatMMA<int_riscv_mqmau_mm, !cast<Instruction>("PseudoMQMAU_MM"#suffix), Wti, Mti>;
  def : PatMMA<int_riscv_msqmau_mm, !cast<Instruction>("PseudoMSQMAU_MM"#suffix), Wti, Mti>;
  def : PatMMA<int_riscv_mqma_mm, !cast<Instruction>("PseudoMQMA_MM"#suffix), Wti, Mti>;
  def : PatMMA<int_riscv_msqma_mm, !cast<Instruction>("PseudoMSQMA_MM"#suffix), Wti, Mti>;
}

// 4.5.2. Element-Wise Add/Sub/Multiply Instructions
class PseudoEW<TRReg RetClass, TRReg OpClass, string Base>:
      Pseudo<(outs RetClass:$td),
             (ins OpClass:$tr1, OpClass:$tr2, LMULTypeIOp:$lmul),
             []>, RISCVVPseudo {
  let mayLoad = 0;
  let mayStore = 0;
  let hasSideEffects = 0;
  let BaseInstr = !cast<Instruction>(Base);
}

class PseudoEWUnary<TRReg RetClass, TRReg OpClass, string Base>:
      Pseudo<(outs RetClass:$td),
             (ins OpClass:$tr1, LMULTypeIOp:$lmul),
             []>, RISCVVPseudo {
  let mayLoad = 0;
  let mayStore = 0;
  let hasSideEffects = 0;
  let BaseInstr = !cast<Instruction>(Base);
}

multiclass PseudoEWA {
  foreach mtype = AllIntegerMatrixs in {
    defvar PName = "Pseudo" # NAME # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
    def PName : PseudoEW<mtype.TRRegClass, mtype.TRRegClass, NAME>;
  }
}

multiclass PseudoFEWA {
  foreach mtype = AllFloatMatrixs in {
    defvar PName = "Pseudo" # NAME # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
    def PName : PseudoEW<mtype.TRRegClass, mtype.TRRegClass, NAME>;
  }
}

multiclass PseudoFEWAUnary {
  foreach mtype = AllFloatMatrixs in {
    defvar PName = "Pseudo" # NAME # "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
    def PName : PseudoEWUnary<mtype.TRRegClass, mtype.TRRegClass, NAME>;
  }
}

multiclass PseudoWEWA {
  foreach MtiToWti = AllWidenableIntMatrixs in {
    defvar Mti = MtiToWti.Mti;
    defvar Wti = MtiToWti.Wti;
    defvar PName = "Pseudo" # NAME # "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
    def PName : PseudoEW<Wti.TRRegClass, Mti.TRRegClass, NAME>;
  }
}

multiclass PseudoWFEWA {
  foreach MtiToWti = AllWidenableFloatMatrixs in {
    defvar Mti = MtiToWti.Mti;
    defvar Wti = MtiToWti.Wti;
    defvar PName = "Pseudo" # NAME # "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
    def PName : PseudoEW<Wti.TRRegClass, Mti.TRRegClass, NAME>;
  }
}

class PatEW<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo rtype, MatrixTypeInfo otype>
    : Pat<(rtype.Matrix (OpNode (otype.Matrix otype.TRRegClass:$ts1),
                                (otype.Matrix otype.TRRegClass:$ts2),
                                (LMULTypeIOp:$imm))),
          (rtype.Matrix (Inst (otype.Matrix otype.TRRegClass:$ts1),
                              (otype.Matrix otype.TRRegClass:$ts2),
                              (LMULTypeIOp:$imm)))>;

class PatEWUnary<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo rtype, MatrixTypeInfo otype>
    : Pat<(rtype.Matrix (OpNode (otype.Matrix otype.TRRegClass:$ts1), (LMULTypeIOp:$imm))),
          (rtype.Matrix (Inst (otype.Matrix otype.TRRegClass:$ts1), (LMULTypeIOp:$imm)))>;

defm MADDU_MM   : PseudoEWA;
defm MSADDU_MM  : PseudoEWA;
defm MADD_MM    : PseudoEWA;
defm MSADD_MM   : PseudoEWA;
defm MSUBU_MM   : PseudoEWA;
defm MSSUBU_MM  : PseudoEWA;
defm MSUB_MM    : PseudoEWA;
defm MSSUB_MM   : PseudoEWA;
defm MMINU_MM   : PseudoEWA;
defm MMIN_MM    : PseudoEWA;
defm MMAXU_MM   : PseudoEWA;
defm MMAX_MM    : PseudoEWA;
defm MMUL_MM    : PseudoEWA;
defm MMULH_MM   : PseudoEWA;
defm MMULHU_MM  : PseudoEWA;
defm MMULHSU_MM : PseudoEWA;
defm MSMUL_MM   : PseudoEWA;
defm MSMULU_MM  : PseudoEWA;
defm MSMULSU_MM : PseudoEWA;

defm MWADDU_MM  : PseudoWEWA;
defm MWADD_MM   : PseudoWEWA;
defm MWSUBU_MM  : PseudoWEWA;
defm MWSUB_MM   : PseudoWEWA;
defm MWMUL_MM   : PseudoWEWA;
defm MWMULU_MM  : PseudoWEWA;
defm MWMULSU_MM : PseudoWEWA;

defm MFADD_MM : PseudoFEWA;
defm MFSUB_MM : PseudoFEWA;
defm MFMIN_MM : PseudoFEWA;
defm MFMAX_MM : PseudoFEWA;
defm MFMUL_MM : PseudoFEWA;
defm MFDIV_MM : PseudoFEWA;
defm MFSQRT_M : PseudoFEWAUnary;

defm MFWADD_MM : PseudoWFEWA;
defm MFWSUB_MM : PseudoWFEWA;
defm MFWMUL_MM : PseudoWFEWA;


foreach mtype = AllIntegerMatrixs in {
  defvar suffix = "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
  def : PatEW<int_riscv_maddu_mm, !cast<Instruction>("PseudoMADDU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_msaddu_mm, !cast<Instruction>("PseudoMSADDU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_madd_mm, !cast<Instruction>("PseudoMADD_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_msadd_mm, !cast<Instruction>("PseudoMSADD_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_msubu_mm, !cast<Instruction>("PseudoMSUBU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mssubu_mm, !cast<Instruction>("PseudoMSSUBU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_msub_mm, !cast<Instruction>("PseudoMSUB_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mssub_mm, !cast<Instruction>("PseudoMSSUB_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mminu_mm, !cast<Instruction>("PseudoMMINU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mmin_mm, !cast<Instruction>("PseudoMMIN_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mmaxu_mm, !cast<Instruction>("PseudoMMAXU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mmax_mm, !cast<Instruction>("PseudoMMAX_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mmul_mm, !cast<Instruction>("PseudoMMUL_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mmulh_mm, !cast<Instruction>("PseudoMMULH_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mmulhu_mm, !cast<Instruction>("PseudoMMULHU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mmulhsu_mm, !cast<Instruction>("PseudoMMULHSU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_msmul_mm, !cast<Instruction>("PseudoMSMUL_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_msmulu_mm, !cast<Instruction>("PseudoMSMULU_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_msmulsu_mm, !cast<Instruction>("PseudoMSMULSU_MM"#suffix), mtype, mtype>;
}

foreach MtiToWti = AllWidenableIntMatrixs in {
  defvar Mti = MtiToWti.Mti;
  defvar Wti = MtiToWti.Wti;
  defvar suffix = "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
  def : PatEW<int_riscv_mwaddu_mm, !cast<Instruction>("PseudoMWADDU_MM"#suffix), Wti, Mti>;
  def : PatEW<int_riscv_mwadd_mm, !cast<Instruction>("PseudoMWADD_MM"#suffix), Wti, Mti>;
  def : PatEW<int_riscv_mwsubu_mm, !cast<Instruction>("PseudoMWSUBU_MM"#suffix), Wti, Mti>;
  def : PatEW<int_riscv_mwsub_mm, !cast<Instruction>("PseudoMWSUB_MM"#suffix), Wti, Mti>;
  def : PatEW<int_riscv_mwmul_mm, !cast<Instruction>("PseudoMWMUL_MM"#suffix), Wti, Mti>;
  def : PatEW<int_riscv_mwmulu_mm, !cast<Instruction>("PseudoMWMULU_MM"#suffix), Wti, Mti>;
  def : PatEW<int_riscv_mwmulsu_mm, !cast<Instruction>("PseudoMWMULSU_MM"#suffix), Wti, Mti>;
}

foreach mtype = AllFloatMatrixs in {
  defvar suffix = "_" # mtype.Suffix # mtype.SEW # "M" # mtype.LMUL;
  def : PatEW<int_riscv_mfadd_mm, !cast<Instruction>("PseudoMFADD_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mfsub_mm, !cast<Instruction>("PseudoMFSUB_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mfmin_mm, !cast<Instruction>("PseudoMFMIN_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mfmax_mm, !cast<Instruction>("PseudoMFMAX_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mfmul_mm, !cast<Instruction>("PseudoMFMUL_MM"#suffix), mtype, mtype>;
  def : PatEW<int_riscv_mfdiv_mm, !cast<Instruction>("PseudoMFDIV_MM"#suffix), mtype, mtype>;
  def : PatEWUnary<int_riscv_mfsqrt_m, !cast<Instruction>("PseudoMFSQRT_M"#suffix), mtype, mtype>;
}

foreach MtiToWti = AllWidenableFloatMatrixs in {
  defvar Mti = MtiToWti.Mti;
  defvar Wti = MtiToWti.Wti;
  defvar suffix = "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
  def : PatEW<int_riscv_mfwadd_mm, !cast<Instruction>("PseudoMFWADD_MM"#suffix), Wti, Mti>;
  def : PatEW<int_riscv_mfwsub_mm, !cast<Instruction>("PseudoMFWSUB_MM"#suffix), Wti, Mti>;
  def : PatEW<int_riscv_mfwmul_mm, !cast<Instruction>("PseudoMFWMUL_MM"#suffix), Wti, Mti>;
}

// 4.5.3. Type-Convert Instructions

multiclass PseudoMFNCVT<list<MatrixTypeInfoMToW> mlist> {
  foreach MtiToWti = mlist in {
    defvar Ret = MtiToWti.Mti;
    defvar Op = MtiToWti.Wti;
    defvar PName = "Pseudo" # NAME # "_" # Ret.Suffix # Ret.SEW # "M" # Ret.LMUL;
    def PName : PseudoEWUnary<Ret.TRRegClass, Op.TRRegClass, NAME>;
  }
}

multiclass PseudoMFWCVT<list<MatrixTypeInfoMToW> mlist> {
  foreach MtiToWti = mlist in {
    defvar Ret = MtiToWti.Wti;
    defvar Op = MtiToWti.Mti;
    defvar PName = "Pseudo" # NAME # "_" # Ret.Suffix # Ret.SEW # "M" # Ret.LMUL;
    def PName : PseudoEWUnary<Ret.TRRegClass, Op.TRRegClass, NAME>;
  }
}

multiclass PseudoMFCVTFX {
  foreach MtiToWti = AllInt2Float in {
    defvar Ret = MtiToWti.Wti;
    defvar Op = MtiToWti.Mti;
    defvar PName = "Pseudo" # NAME # "_" # Ret.Suffix # Ret.SEW # "M" # Ret.LMUL;
    def PName : PseudoEWUnary<Ret.TRRegClass, Op.TRRegClass, NAME>;
  }
}

multiclass PseudoMFCVTXF {
  foreach MtiToWti = AllInt2Float in {
    defvar Ret = MtiToWti.Mti;
    defvar Op = MtiToWti.Wti;
    defvar PName = "Pseudo" # NAME # "_" # Ret.Suffix # Ret.SEW # "M" # Ret.LMUL;
    def PName : PseudoEWUnary<Ret.TRRegClass, Op.TRRegClass, NAME>;
  }
}

// f 2 f
defm MFNCVT_F_FW_M : PseudoMFNCVT<AllWidenableFloatMatrixs>;
defm MFWCVT_FW_F_M : PseudoMFWCVT<AllWidenableFloatMatrixs>;
// x 2 f
defm MFCVT_F_X_M    : PseudoMFCVTFX;
defm MFCVT_FW_XW_M  : PseudoMFCVTFX;
defm MFNCVT_F_XW_M  : PseudoMFNCVT<AllWidenableFloat2Int>;
defm MFNCVT_F_XQ_M  : PseudoMFNCVT<AllQuadrupleFloat2Int>;
defm MFNCVT_FW_XQ_M : PseudoMFNCVT<AllWidenableFloat2Int>;
defm MFWCVT_FW_X_M  : PseudoMFWCVT<AllWidenableInt2Float>;

// f 2 x
defm MFCVT_X_F_M    : PseudoMFCVTXF;
defm MFCVT_XW_FW_M  : PseudoMFCVTXF;
defm MFWCVT_XW_F_M  : PseudoMFWCVT<AllWidenableFloat2Int>;
defm MFWCVT_XQ_F_M  : PseudoMFWCVT<AllQuadrupleFloat2Int>;
defm MFWCVT_XQ_FW_M : PseudoMFWCVT<AllWidenableFloat2Int>;
defm MFNCVT_X_FW_M  : PseudoMFNCVT<AllWidenableInt2Float>;


foreach MtiToWti = AllWidenableFloatMatrixs in {
  defvar Mti = MtiToWti.Mti;
  defvar Wti = MtiToWti.Wti;
  defvar suffix_n = "_" # Mti.Suffix # Mti.SEW # "M" # Mti.LMUL;
  defvar suffix_w = "_" # Wti.Suffix # Wti.SEW # "M" # Wti.LMUL;
  def : PatEWUnary<int_riscv_mfncvt_f_fw_m, !cast<Instruction>("PseudoMFNCVT_F_FW_M"#suffix_n), Mti, Wti>;
  def : PatEWUnary<int_riscv_mfwcvt_fw_f_m, !cast<Instruction>("PseudoMFWCVT_FW_F_M"#suffix_w), Wti, Mti>;
}

foreach MtiToWti = AllInt2Float in {
  defvar Xti = MtiToWti.Mti;
  defvar Fti = MtiToWti.Wti;
  defvar suffix_x = "_" # Xti.Suffix # Xti.SEW # "M" # Xti.LMUL;
  defvar suffix_f = "_" # Fti.Suffix # Fti.SEW # "M" # Fti.LMUL;
  def : PatEWUnary<int_riscv_mfcvt_f_x_m, !cast<Instruction>("PseudoMFCVT_F_X_M"#suffix_f), Fti, Xti>;
  def : PatEWUnary<int_riscv_mfcvt_fw_xw_m, !cast<Instruction>("PseudoMFCVT_FW_XW_M"#suffix_f), Fti, Xti>;
  def : PatEWUnary<int_riscv_mfcvt_x_f_m, !cast<Instruction>("PseudoMFCVT_X_F_M"#suffix_x), Xti, Fti>;
  def : PatEWUnary<int_riscv_mfcvt_xw_fw_m, !cast<Instruction>("PseudoMFCVT_XW_FW_M"#suffix_x), Xti, Fti>;
}

foreach MtiToWti = AllWidenableInt2Float in {
  defvar Xti = MtiToWti.Mti;
  defvar Fti = MtiToWti.Wti;
  defvar suffix_x = "_" # Xti.Suffix # Xti.SEW # "M" # Xti.LMUL;
  defvar suffix_f = "_" # Fti.Suffix # Fti.SEW # "M" # Fti.LMUL;
  def : PatEWUnary<int_riscv_mfwcvt_fw_x_m, !cast<Instruction>("PseudoMFWCVT_FW_X_M"#suffix_f), Fti, Xti>;
  def : PatEWUnary<int_riscv_mfncvt_x_fw_m, !cast<Instruction>("PseudoMFNCVT_X_FW_M"#suffix_x), Xti, Fti>;
}

foreach MtiToWti = AllWidenableFloat2Int in {
  defvar Fti = MtiToWti.Mti;
  defvar Xti = MtiToWti.Wti;
  defvar suffix_x = "_" # Xti.Suffix # Xti.SEW # "M" # Xti.LMUL;
  defvar suffix_f = "_" # Fti.Suffix # Fti.SEW # "M" # Fti.LMUL;
  def : PatEWUnary<int_riscv_mfncvt_f_xw_m, !cast<Instruction>("PseudoMFNCVT_F_XW_M"#suffix_f), Fti, Xti>;
  def : PatEWUnary<int_riscv_mfncvt_fw_xq_m, !cast<Instruction>("PseudoMFNCVT_FW_XQ_M"#suffix_f), Fti, Xti>;
  def : PatEWUnary<int_riscv_mfwcvt_xw_f_m, !cast<Instruction>("PseudoMFWCVT_XW_F_M"#suffix_x), Xti, Fti>;
  def : PatEWUnary<int_riscv_mfwcvt_xq_fw_m, !cast<Instruction>("PseudoMFWCVT_XQ_FW_M"#suffix_x), Xti, Fti>;
}

foreach MtiToWti = AllQuadrupleFloat2Int in {
  defvar Fti = MtiToWti.Mti;
  defvar Xti = MtiToWti.Wti;
  defvar suffix_x = "_" # Xti.Suffix # Xti.SEW # "M" # Xti.LMUL;
  defvar suffix_f = "_" # Fti.Suffix # Fti.SEW # "M" # Fti.LMUL;
  def : PatEWUnary<int_riscv_mfncvt_f_xq_m, !cast<Instruction>("PseudoMFNCVT_F_XQ_M"#suffix_f), Fti, Xti>;
  def : PatEWUnary<int_riscv_mfwcvt_xq_f_m, !cast<Instruction>("PseudoMFWCVT_XQ_F_M"#suffix_x), Xti, Fti>;
}

// zmv

class PatMLoadV<SDPatternOperator OpNode, RVInst Inst, ValueType type>
    : Pat<(type (OpNode BaseAddr:$rs1, GPR:$rs2)),
          (type (Inst BaseAddr:$rs1, GPR:$rs2))>;

foreach mtype = !listconcat(AllIntegerM1, AllFloatM1) in {
  def : PatMLoadV<int_riscv_mlae_v, !cast<RVInst>("MLAE"#mtype.SEW#"_V"), mtype.Vector>;
  def : PatMLoadV<int_riscv_mlbe_v, !cast<RVInst>("MLBE"#mtype.SEW#"_V"), mtype.Vector>;
  def : PatMLoadV<int_riscv_mlce_v, !cast<RVInst>("MLCE"#mtype.SEW#"_V"), mtype.Vector>;
}

class PatMStoreV<SDPatternOperator OpNode, RVInst Inst, ValueType type>
    : Pat<(OpNode type:$ts1, BaseAddr:$rd1, GPR:$rs2),
          (Inst VR:$ts1, BaseAddr:$rd1, GPR:$rs2)>;

foreach mtype = !listconcat(AllIntegerM1, AllFloatM1) in {
  def : PatMStoreV<int_riscv_msae_v, !cast<RVInst>("MSAE"#mtype.SEW#"_V"), mtype.Vector>;
  def : PatMStoreV<int_riscv_msbe_v, !cast<RVInst>("MSBE"#mtype.SEW#"_V"), mtype.Vector>;
  def : PatMStoreV<int_riscv_msce_v, !cast<RVInst>("MSCE"#mtype.SEW#"_V"), mtype.Vector>;
}

class PatMMV_V_M<SDPatternOperator OpNode, RVInst Inst,  ValueType type_dest, ValueType type_src>
    : Pat<(type_dest (OpNode (type_src TRR:$tr1), GPR:$r2)),
          (type_dest (Inst (type_src TRR:$tr1), GPR:$r2))>;

class PatMMV_M_V<SDPatternOperator OpNode, RVInst Inst,  ValueType type_dest, ValueType type_src>
    : Pat<(type_dest (OpNode (type_src VR:$tr1), GPR:$r2)),
          (type_dest (Inst (type_src VR:$tr1), GPR:$r2))>;

foreach mti = AllMatrixs in {
def : PatMMV_V_M<int_riscv_mmvar_v_m, MMVAR_V_M, mti.Vector, mti.Matrix>;
def : PatMMV_V_M<int_riscv_mmvbr_v_m, MMVBR_V_M, mti.Vector, mti.Matrix>;
def : PatMMV_V_M<int_riscv_mmvcr_v_m, MMVCR_V_M, mti.Vector, mti.Matrix>;
def : PatMMV_M_V<int_riscv_mmvar_m_v, MMVAR_M_V, mti.Matrix, mti.Vector>;
def : PatMMV_M_V<int_riscv_mmvbr_m_v, MMVBR_M_V, mti.Matrix, mti.Vector>;
def : PatMMV_M_V<int_riscv_mmvcr_m_v, MMVCR_M_V, mti.Matrix, mti.Vector>;
def : PatMMV_V_M<int_riscv_mmvac_v_m, MMVAC_V_M, mti.Vector, mti.Matrix>;
def : PatMMV_V_M<int_riscv_mmvbc_v_m, MMVBC_V_M, mti.Vector, mti.Matrix>;
def : PatMMV_V_M<int_riscv_mmvcc_v_m, MMVCC_V_M, mti.Vector, mti.Matrix>;
def : PatMMV_M_V<int_riscv_mmvac_m_v, MMVAC_M_V, mti.Matrix, mti.Vector>;
def : PatMMV_M_V<int_riscv_mmvbc_m_v, MMVBC_M_V, mti.Matrix, mti.Vector>;
def : PatMMV_M_V<int_riscv_mmvcc_m_v, MMVCC_M_V, mti.Matrix, mti.Vector>;
}

// Zmic
def : PatGprGpr<int_riscv_msetoutsh, MSETOUTSH>;
def : PatGprGpr<int_riscv_msetinsh, MSETINSH>;
def : PatGprGpr<int_riscv_msetsk, MSETSK>;
def : PatGpr<int_riscv_msetpadval, MSETPADVAL>;

class PatMLoadZmic<SDPatternOperator OpNode, RVInst Inst, ValueType type>
    : Pat<(type (OpNode BaseAddr:$rs1, GPR:$rs2)),
          (type (Inst BaseAddr:$rs1, GPR:$rs2))>;

foreach mtype = !listconcat(AllIntegerM1, AllFloatM1) in {
  def : PatMLoadZmic<int_riscv_mlufae_m, !cast<RVInst>("MLUFAE"#mtype.SEW#"_M"), mtype.Matrix>;
  def : PatMLoadZmic<int_riscv_mlufbe_m, !cast<RVInst>("MLUFBE"#mtype.SEW#"_M"), mtype.Matrix>;
  def : PatMLoadZmic<int_riscv_mlufce_m, !cast<RVInst>("MLUFCE"#mtype.SEW#"_M"), mtype.Matrix>;
}

class PatMStoreZmic<SDPatternOperator OpNode, RVInst Inst, ValueType type>
    : Pat<(OpNode type:$ts1, BaseAddr:$rd1, GPR:$rs2),
          (Inst TRR:$ts1, BaseAddr:$rd1, GPR:$rs2)>;

foreach mtype = !listconcat(AllIntegerM1, AllFloatM1) in {
  def : PatMStoreZmic<int_riscv_msfdae_m, !cast<RVInst>("MSFDAE"#mtype.SEW#"_M"), mtype.Matrix>;
  def : PatMStoreZmic<int_riscv_msfdbe_m, !cast<RVInst>("MSFDBE"#mtype.SEW#"_M"), mtype.Matrix>;
  def : PatMStoreZmic<int_riscv_msfdce_m, !cast<RVInst>("MSFDCE"#mtype.SEW#"_M"), mtype.Matrix>;
}


