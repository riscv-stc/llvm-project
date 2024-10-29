class MatrixTypeInfo<ValueType Mat, ValueType Vec, int Sew, string al, string AL,
                     ValueType Scal = XLenVT, RegisterClass ScalarReg = GPR>
{
    ValueType Matrix = Mat;
    ValueType Vector = Vec;
    int SEW = Sew;
    string alias = al;
    string ALIAS = AL;
    ValueType Scalar = Scal;
    RegisterClass ScalarRegClass = ScalarReg;

    string Suffix = !cond(!eq(Scal, XLenVT) : "I",
                          !eq(Scal, f16) : "F",
                          !eq(Scal, f32) : "F",
                          !eq(Scal, f64) : "F");
}

defset list<MatrixTypeInfo> AllMatrixs = {
  defset list<MatrixTypeInfo> AllIntegerMatrixs = {
    def MI8M1  : MatrixTypeInfo<mint8_t,  vint8m1_t,   8, "b", "B">;
    def MI16M1 : MatrixTypeInfo<mint16_t, vint16m1_t, 16, "h", "H">;
    def MI32M1 : MatrixTypeInfo<mint32_t, vint32m1_t, 32, "w", "W">;
    def MI64M1 : MatrixTypeInfo<mint64_t, vint64m1_t, 64, "dw", "DW">;
  }

  defset list<MatrixTypeInfo> AllFloatMatrixs = {
    def MF16M1 : MatrixTypeInfo<mfloat16_t, vfloat16m1_t, 16, "hf", "HF", f16, FPR16>;
    def MF32M1 : MatrixTypeInfo<mfloat32_t, vfloat32m1_t, 32, "f", "F", f32, FPR32>;
    def MF64M1 : MatrixTypeInfo<mfloat64_t, vfloat64m1_t, 64, "d", "D", f64, FPR64>;
  }
}

class MatrixTypeInfoMToW<MatrixTypeInfo mti, MatrixTypeInfo wti>
{
  MatrixTypeInfo Mti = mti;
  MatrixTypeInfo Wti = wti;
}

// 4.2. Configuration-Setting Instructions
class PatImm<SDPatternOperator OpNode, RVInst Inst, Operand imm_type>
    : Pat<(XLenVT(OpNode imm_type:$imm)), (Inst imm_type:$imm)>;

def : PatGpr<int_riscv_msettype, MSETTYPE>;
def : PatImm<int_riscv_msettype, MSETTYPEI, uimm10>;
def : PatGpr<int_riscv_msettilem, MSETTILEM>;
def : PatImm<int_riscv_msettilem, MSETTILEMI, uimm10>;
def : PatGpr<int_riscv_msettilen, MSETTILEN>;
def : PatImm<int_riscv_msettilen, MSETTILENI, uimm10>;
def : PatGpr<int_riscv_msettilek, MSETTILEK>;
def : PatImm<int_riscv_msettilek, MSETTILEKI, uimm10>;

def : PatImm<int_riscv_msettilemi, MSETTILEMI, uimm10>;
def : PatImm<int_riscv_msettileni, MSETTILENI, uimm10>;
def : PatImm<int_riscv_msettileki, MSETTILEKI, uimm10>;
def : PatImm<int_riscv_msettypehi, MSETTYPEHI, uimm10>;
def : PatImm<int_riscv_msettypei, MSETTYPEI, uimm10>;

def : PatImm<int_riscv_msettspi, MSETTSPI, uimm5>;
def : PatGpr<int_riscv_msettsp, MSETTSP>;
def : PatImm<int_riscv_msettsp, MSETTSPI, uimm5>;

def : PatImm<int_riscv_msetdspi, MSETDSPI, uimm5>;
def : PatGpr<int_riscv_msetdsp, MSETDSP>;
def : PatImm<int_riscv_msetdsp, MSETDSPI, uimm5>;

def : PatGprGpr<int_riscv_msetoutsh, MSETOUTSH>;
def : PatGprGpr<int_riscv_msetinsh, MSETINSH>;
def : PatGprGpr<int_riscv_msetsk, MSETSK>;
def : PatGpr<int_riscv_msetpadval, MSETPADVAL>;

// 4.3. Load and Store Instructions
// Pseudo Instr
class PseudoMStore<TRReg RegClass, string Base>:
      Pseudo<(outs),
             (ins RegClass:$ts3, GPR:$rs1, GPR:$rs2),
             []>, RISCVVPseudo {
  let mayLoad = 0;
  let mayStore = 1;
  let hasSideEffects = 0;
  let BaseInstr = !cast<Instruction>(Base);
}

class PatMLoad<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo type>
    : Pat<(type.Matrix (OpNode BaseAddr:$rs1, GPR:$rs2)),
          (type.Matrix (Inst BaseAddr:$rs1, GPR:$rs2))>;

class PatVLoad<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo type>
    : Pat<(type.Vector (OpNode BaseAddr:$rs1, GPR:$rs2)),
          (type.Vector (Inst BaseAddr:$rs1, GPR:$rs2))>;

foreach mtype = AllMatrixs in {
  def : PatMLoad<int_riscv_mla_m,   !cast<Instruction>("MLAE"#mtype.SEW#"_M"),  mtype>;
  def : PatMLoad<int_riscv_mlat_m,  !cast<Instruction>("MLATE"#mtype.SEW#"_M"), mtype>;
  def : PatMLoad<int_riscv_mlb_m,   !cast<Instruction>("MLBE"#mtype.SEW#"_M"),  mtype>;
  def : PatMLoad<int_riscv_mlbt_m,  !cast<Instruction>("MLBTE"#mtype.SEW#"_M"), mtype>;
  def : PatMLoad<int_riscv_mlc_m,   !cast<Instruction>("MLCE"#mtype.SEW#"_M"),  mtype>;
  def : PatMLoad<int_riscv_mlct_m,  !cast<Instruction>("MLCTE"#mtype.SEW#"_M"), mtype>;
  def : PatMLoad<int_riscv_mltr_m,  !cast<Instruction>("MLTRE"#mtype.SEW#"_M"), mtype>;
  def : PatMLoad<int_riscv_mlacc_m, !cast<Instruction>("MLACCE"#mtype.SEW#"_M"),mtype>;
  def : PatVLoad<int_riscv_mla_v,   !cast<Instruction>("MLAE"#mtype.SEW#"_V"),  mtype>;
  def : PatVLoad<int_riscv_mlb_v,   !cast<Instruction>("MLBE"#mtype.SEW#"_V"),  mtype>;
  def : PatVLoad<int_riscv_mlc_v,   !cast<Instruction>("MLCE"#mtype.SEW#"_V"),  mtype>;
  def : PatMLoad<int_riscv_mlufa_m, !cast<Instruction>("MLUFAE"#mtype.SEW#"_M"),mtype>;
  def : PatMLoad<int_riscv_mlufb_m, !cast<Instruction>("MLUFBE"#mtype.SEW#"_M"),mtype>;
  def : PatMLoad<int_riscv_mlufc_m, !cast<Instruction>("MLUFCE"#mtype.SEW#"_M"),mtype>;
}

class PatMStore<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo type>
    : Pat<(OpNode type.Matrix:$ts1, BaseAddr:$rd1, GPR:$rs2),
          (Inst type.Matrix:$ts1, BaseAddr:$rd1, GPR:$rs2)>;

class PatVStore<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo type>
    : Pat<(OpNode type.Vector:$ts1, BaseAddr:$rd1, GPR:$rs2),
          (Inst type.Vector:$ts1, BaseAddr:$rd1, GPR:$rs2)>;

foreach mtype = AllMatrixs in {
  def : PatMStore<int_riscv_msa_m,  !cast<Instruction>("MSAE"#mtype.SEW#"_M"),  mtype>;
  def : PatMStore<int_riscv_msat_m, !cast<Instruction>("MSATE"#mtype.SEW#"_M"), mtype>;
  def : PatMStore<int_riscv_msb_m,  !cast<Instruction>("MSBE"#mtype.SEW#"_M"),  mtype>;
  def : PatMStore<int_riscv_msbt_m, !cast<Instruction>("MSBTE"#mtype.SEW#"_M"), mtype>;
  def : PatMStore<int_riscv_msc_m,  !cast<Instruction>("MSCE"#mtype.SEW#"_M"),  mtype>;
  def : PatMStore<int_riscv_msct_m, !cast<Instruction>("MSCTE"#mtype.SEW#"_M"), mtype>;
  def : PatMStore<int_riscv_mstr_m, !cast<Instruction>("MSTRE"#mtype.SEW#"_M"), mtype>;
  def : PatMStore<int_riscv_msacc_m,!cast<Instruction>("MSACCE"#mtype.SEW#"_M"),mtype>;
  def : PatVStore<int_riscv_msa_v,  !cast<Instruction>("MSAE"#mtype.SEW#"_V"),  mtype>;
  def : PatVStore<int_riscv_msb_v,  !cast<Instruction>("MSBE"#mtype.SEW#"_V"),  mtype>;
  def : PatVStore<int_riscv_msc_v,  !cast<Instruction>("MSCE"#mtype.SEW#"_V"),  mtype>;
  def : PatMStore<int_riscv_msfda_m,!cast<Instruction>("MSFDAE"#mtype.SEW#"_M"),mtype>;
  def : PatMStore<int_riscv_msfdb_m,!cast<Instruction>("MSFDBE"#mtype.SEW#"_M"),mtype>;
  def : PatMStore<int_riscv_msfdc_m,!cast<Instruction>("MSFDCE"#mtype.SEW#"_M"),mtype>;
}

// 4.4. Data Move Instructions
def riscv_mmv_a_x : SDNode<"RISCVISD::MMV_A_X",
                           SDTypeProfile<1, 3, [SDTCisSameAs<0, 1>,
                                                SDTCisInt<2>,
                                                SDTCisVT<3, XLenVT>]>>;

def riscv_mmv_t_x : SDNode<"RISCVISD::MMV_T_X",
                           SDTypeProfile<1, 3, [SDTCisSameAs<0, 1>,
                                                SDTCisInt<2>,
                                                SDTCisVT<3, XLenVT>]>>;

def riscv_mmv_x_t : SDNode<"RISCVISD::MMV_X_T",
                           SDTypeProfile<1, 2, [SDTCisInt<0>, SDTCisVec<1>,
                                                SDTCisVT<2, XLenVT>]>>;

def riscv_mmv_x_a : SDNode<"RISCVISD::MMV_X_A",
                           SDTypeProfile<1, 2, [SDTCisInt<0>, SDTCisVec<1>,
                                                SDTCisVT<2, XLenVT>]>>;

foreach mtype = AllIntegerMatrixs in {
  def : Pat<(XLenVT (riscv_mmv_x_a (mtype.Matrix ACCR:$rs1), GPR:$rs2)),
            (!cast<Instruction>("MMVE"#mtype.SEW#"_X_A") (mtype.Matrix ACCR:$rs1), GPR:$rs2)>;
  def : Pat<(XLenVT (riscv_mmv_x_t (mtype.Matrix TRR:$rs1), GPR:$rs2)),
            (!cast<Instruction>("MMVE"#mtype.SEW#"_X_T") (mtype.Matrix TRR:$rs1), GPR:$rs2)>;
  def : Pat<(mtype.Matrix (riscv_mmv_t_x (mtype.Matrix TRR:$tr1), GPR:$rs2, GPR:$rs3)),
            (!cast<Instruction>("MMVE"#mtype.SEW#"_T_X") (mtype.Matrix TRR:$tr1), GPR:$rs2, GPR:$rs3)>;
  def : Pat<(mtype.Matrix (riscv_mmv_a_x (mtype.Matrix ACCR:$tr1), GPR:$rs2, GPR:$rs3)),
            (!cast<Instruction>("MMVE"#mtype.SEW#"_A_X") (mtype.Matrix ACCR:$tr1), GPR:$rs2, GPR:$rs3)>;
}

foreach mti = AllFloatMatrixs in {
def : Pat<(mti.Scalar (int_riscv_mfmv_f_t (mti.Matrix TRR:$tr1), GPR:$rs2)),
          (!cast<Instruction>("MFMVE"#mti.SEW#"_F_T") (mti.Matrix TRR:$tr1), GPR:$rs2)>;
def : Pat<(mti.Matrix (int_riscv_mfmv_t_f (mti.Matrix TRR:$tr1), mti.ScalarRegClass:$rs2, GPR:$rs3)),
          (!cast<Instruction>("MFMVE"#mti.SEW#"_T_F") (mti.Matrix TRR:$tr1), mti.ScalarRegClass:$rs2, GPR:$rs3)>;
def : Pat<(mti.Scalar (int_riscv_mfmv_f_a (mti.Matrix ACCR:$tr1), GPR:$rs2)),
          (!cast<Instruction>("MFMVE"#mti.SEW#"_F_A") (mti.Matrix ACCR:$tr1), GPR:$rs2)>;
def : Pat<(mti.Matrix (int_riscv_mfmv_a_f (mti.Matrix ACCR:$tr1), mti.ScalarRegClass:$rs2, GPR:$rs3)),
          (!cast<Instruction>("MFMVE"#mti.SEW#"_A_F") (mti.Matrix ACCR:$tr1), mti.ScalarRegClass:$rs2, GPR:$rs3)>;
}

// 4.4.4. Data Broadcast Instructions
class PatDataBOrT<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo type>
    : Pat<(type.Matrix (OpNode type.Matrix:$tr1)),  (Inst type.Matrix:$tr1)>;

foreach mti = AllMatrixs in {
  def : PatDataBOrT<int_riscv_mbcar_m, !cast<Instruction>("MBCAR_M"), mti>;
  def : PatDataBOrT<int_riscv_mbcbr_m, !cast<Instruction>("MBCBR_M"), mti>;
  def : PatDataBOrT<int_riscv_mbccr_m, !cast<Instruction>("MBCCR_M"), mti>;
  def : PatDataBOrT<int_riscv_mbcac_m, !cast<Instruction>("MBCACE"#mti.SEW#"_M"), mti>;
  def : PatDataBOrT<int_riscv_mbcbc_m, !cast<Instruction>("MBCBCE"#mti.SEW#"_M"), mti>;
  def : PatDataBOrT<int_riscv_mbccc_m, !cast<Instruction>("MBCCCE"#mti.SEW#"_M"), mti>;
  def : PatDataBOrT<int_riscv_mbcae_m, !cast<Instruction>("MBCAEE"#mti.SEW#"_M"), mti>;
  def : PatDataBOrT<int_riscv_mbcbe_m, !cast<Instruction>("MBCBEE"#mti.SEW#"_M"), mti>;
  def : PatDataBOrT<int_riscv_mbcce_m, !cast<Instruction>("MBCCEE"#mti.SEW#"_M"), mti>;
  def : PatDataBOrT<int_riscv_mta_m,   !cast<Instruction>("MTAE"#mti.SEW#"_M"), mti>;
  def : PatDataBOrT<int_riscv_mtb_m,   !cast<Instruction>("MTBE"#mti.SEW#"_M"), mti>;
  def : PatDataBOrT<int_riscv_mtc_m,   !cast<Instruction>("MTCE"#mti.SEW#"_M"), mti>;
}

// 4.5. Arithmetic Instructions
// 4.5.1. Matrix Multiplication Instructions
class PatMMul<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo TRInfo, MatrixTypeInfo ACCInfo>
    : Pat<(ACCInfo.Matrix (OpNode (ACCInfo.Matrix ACCR:$md), (TRInfo.Matrix TRR:$ms1), (TRInfo.Matrix TRR:$ms2))),
          (Inst (ACCInfo.Matrix ACCR:$md), (TRInfo.Matrix TRR:$ms1), (TRInfo.Matrix TRR:$ms2))>;

defset list<MatrixTypeInfoMToW> AllMMAIntMatrixs = {
  def : MatrixTypeInfoMToW<MI16M1, MI16M1>; // H
  def : MatrixTypeInfoMToW<MI32M1, MI32M1>; // W
  def : MatrixTypeInfoMToW<MI64M1, MI64M1>; // DW
}

defset list<MatrixTypeInfoMToW> AllMMADoubleIntMatrixs = {
  def : MatrixTypeInfoMToW<MI16M1, MI32M1>; // H
  def : MatrixTypeInfoMToW<MI32M1, MI64M1>; // W
}

defset list<MatrixTypeInfoMToW> AllMMAQuadIntMatrixs = {
  def : MatrixTypeInfoMToW<MI8M1, MI32M1>; // B
}

// defset list<MatrixTypeInfoMToW> AllMMAOctIntMatrixs = {
//   def : MatrixTypeInfoMToW<MI4M1, MI32M1>; // HB
// }

defset list<MatrixTypeInfoMToW> AllMMAFPMatrixs = {
  def : MatrixTypeInfoMToW<MF16M1, MF16M1>; // HF
  def : MatrixTypeInfoMToW<MF32M1, MF32M1>; // F
  def : MatrixTypeInfoMToW<MF64M1, MF64M1>; // D
}

defset list<MatrixTypeInfoMToW> AllMMADoubleFPMatrixs = {
  def : MatrixTypeInfoMToW<MF32M1, MF64M1>; // F
  def : MatrixTypeInfoMToW<MF16M1, MF32M1>; // HF
  // def : MatrixTypeInfoMToW<MF8M1, MF16M1>;  // CF
}

// defset list<MatrixTypeInfoMToW> AllMMAQuadFPMatrixs = {
//   def : MatrixTypeInfoMToW<MF8M1, MF32M1>; // CF
// }

foreach MInfo = AllMMAIntMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mmau_mm,   MMAU_MM,  TRInfo,  ACCInfo>;
  def : PatMMul<int_riscv_msmau_mm,  MSMAU_MM, TRInfo,  ACCInfo>;
  def : PatMMul<int_riscv_mma_mm,    MMA_MM,   TRInfo,  ACCInfo>;
  def : PatMMul<int_riscv_msma_mm,   MSMA_MM,  TRInfo,  ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mmau_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MMAU_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msmau_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSMAU_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mma_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MMA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msma_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSMA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

foreach MInfo = AllMMADoubleIntMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mwmau_mm, MWMAU_MM, TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mwmau_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MWMAU_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mswmau_mm, MSWMAU_MM, TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mswmau_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSWMAU_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mwma_mm, MWMA_MM, TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mwma_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MWMA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mswma_mm, MSWMA_MM, TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mswma_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSWMA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

foreach MInfo = AllMMAQuadIntMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mqmau_mm,     MQMAU_MM,     TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msqmau_mm,    MSQMAU_MM,    TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mqma_mm,      MQMA_MM,      TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msqma_mm,     MSQMA_MM,     TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mqmau_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MQMAU_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msqmau_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSQMAU_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mqma_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MQMA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msqma_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSQMA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

// foreach MInfo = AllMMAOctIntMatrixs in {
//   defvar TRInfo = MInfo.Mti;
//   defvar ACCInfo = MInfo.Wti;
//   def : PatMMul<int_riscv_momau_mm,     MOMAU_MM,     TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_msomau_mm,    MSOMAU_MM,    TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_moma_mm,      MOMA_MM,      TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_msoma_mm,     MSOMA_MM,     TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_momau_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MOMAU_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_msomau_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MSOMAU_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_moma_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MOMA_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_msoma_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MSOMA_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
// }

foreach MInfo = AllMMAFPMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mfma_mm, MFMA_MM, TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfma_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MFMA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

foreach MInfo = AllMMADoubleFPMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mfwma_mm, MFWMA_MM, TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfwma_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MFWMA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

// foreach MInfo = AllMMAQuadFPMatrixs in {
//   defvar TRInfo = MInfo.Mti;
//   defvar ACCInfo = MInfo.Wti;
//   def : PatMMul<int_riscv_mfqma_mm, MFQMA_MM, TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfqma_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MFQMA_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
// }

// Element-wise Arithmetic & Logic Instructions
class PatMElet<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo TRType,
               MatrixTypeInfo ACCType>
  : Pat<(ACCType.Matrix (OpNode (TRType.Matrix ACCR:$ms1), (TRType.Matrix ACCR:$ms2))),
        (Inst (TRType.Matrix ACCR:$ms1), (TRType.Matrix ACCR:$ms2))>;

defset list<MatrixTypeInfoMToW> AllEletDoubleIntMatrixs = {
  // def : MatrixTypeInfoMToW<MI4M1,  MI8M1>;  // HB
  def : MatrixTypeInfoMToW<MI8M1,  MI16M1>; // B
  def : MatrixTypeInfoMToW<MI16M1, MI32M1>; // H
  def : MatrixTypeInfoMToW<MI32M1, MI64M1>; // W
}

defset list<MatrixTypeInfoMToW> AllEletDoubleFPMatrixs = {
  // def : MatrixTypeInfoMToW<MF8M1,  MF16M1>; // CF
  def : MatrixTypeInfoMToW<MF16M1, MF32M1>; // HF
  def : MatrixTypeInfoMToW<MF32M1, MF64M1>; // F
}

foreach MInfo = AllIntegerMatrixs in {
  def : PatMElet<int_riscv_maddu_mm,   MADDU_MM,   MInfo, MInfo>;
  def : PatMElet<int_riscv_msaddu_mm,  MSADDU_MM,  MInfo, MInfo>;
  def : PatMElet<int_riscv_madd_mm,    MADD_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_msadd_mm,   MSADD_MM,   MInfo, MInfo>;
  def : PatMElet<int_riscv_msubu_mm,   MSUBU_MM,   MInfo, MInfo>;
  def : PatMElet<int_riscv_mssubu_mm,  MSSUBU_MM,  MInfo, MInfo>;
  def : PatMElet<int_riscv_msub_mm,    MSUB_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_mssub_mm,   MSSUB_MM,   MInfo, MInfo>;
  def : PatMElet<int_riscv_mminu_mm,   MMINU_MM,   MInfo, MInfo>;
  def : PatMElet<int_riscv_mmaxu_mm,   MMAXU_MM,   MInfo, MInfo>;
  def : PatMElet<int_riscv_mmin_mm,    MMIN_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_mmax_mm,    MMAX_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_msmulu_mm,  MSMULU_MM,  MInfo, MInfo>;
  def : PatMElet<int_riscv_mmul_mm,    MMUL_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_msmul_mm,   MSMUL_MM,   MInfo, MInfo>;
  def : PatMElet<int_riscv_mmulhu_mm,  MMULHU_MM,  MInfo, MInfo>;
  def : PatMElet<int_riscv_mmulh_mm,   MMULH_MM,   MInfo, MInfo>;
  def : PatMElet<int_riscv_mmulhsu_mm, MMULHSU_MM, MInfo, MInfo>;
  def : PatMElet<int_riscv_msmulsu_mm, MSMULSU_MM, MInfo, MInfo>;
  def : PatMElet<int_riscv_mand_mm,    MAND_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_mor_mm,     MOR_MM,     MInfo, MInfo>;
  def : PatMElet<int_riscv_mxor_mm,    MXOR_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_msll_mm,    MSLL_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_msrl_mm,    MSRL_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_msra_mm,    MSRA_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_mand_mm,    MAND_MM,    MInfo, MInfo>;
  def : PatMElet<int_riscv_mor_mm,     MOR_MM,     MInfo, MInfo>;
  def : PatMElet<int_riscv_mxor_mm,    MXOR_MM,    MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_maddu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MADDU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msaddu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSADDU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_madd_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MADD_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msadd_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSADD_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msubu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSUBU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mssubu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSSUBU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msub_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSUB_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mssub_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSSUB_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mminu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MMINU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mmaxu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MMAXU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mmin_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MMIN_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mmax_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MMAX_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msmulu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSMULU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mmul_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MMUL_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msmul_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSMUL_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mmulhu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MMULHU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mmulh_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MMULH_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mmulhsu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MMULHSU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msmulsu_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSMULSU_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msll_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSLL_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msrl_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSRL_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_msra_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MSRA_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
}

foreach MInfo = AllEletDoubleIntMatrixs in {
  defvar SInfo = MInfo.Mti;
  defvar DInfo = MInfo.Wti;
  def : PatMElet<int_riscv_mwaddu_mm, MWADDU_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mwaddu_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MWADDU_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
  def : PatMElet<int_riscv_mwadd_mm, MWADD_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mwadd_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MWADD_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
  def : PatMElet<int_riscv_mwsubu_mm, MWSUBU_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mwsubu_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MWSUBU_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
  def : PatMElet<int_riscv_mwsub_mm, MWSUB_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mwsub_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MWSUB_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
  def : PatMElet<int_riscv_mwmulu_mm, MWMULU_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mwmulu_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MWMULU_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
  def : PatMElet<int_riscv_mwmul_mm, MWMUL_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mwmul_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MWMUL_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
  def : PatMElet<int_riscv_mwmulsu_mm, MWMULSU_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mwmulsu_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MWMULSU_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
}

foreach MInfo = AllFloatMatrixs in {
  def : PatMElet<int_riscv_mfadd_mm, MFADD_MM, MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfadd_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MFADD_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<int_riscv_mfsub_mm, MFSUB_MM, MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfsub_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MFSUB_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<int_riscv_mfmin_mm, MFMIN_MM, MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfmin_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MFMIN_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<int_riscv_mfmax_mm, MFMAX_MM, MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfmax_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MFMAX_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<int_riscv_mfmul_mm, MFMUL_MM, MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfmul_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MFMUL_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : PatMElet<int_riscv_mfdiv_mm, MFDIV_MM, MInfo, MInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfdiv_"#MInfo.alias#"_mm"),
                 !cast<Instruction>("MFDIV_"#MInfo.ALIAS#"_MM"),
                 MInfo, MInfo>;
  def : Pat<(MInfo.Matrix (int_riscv_mfsqrt_m (MInfo.Matrix ACCR:$ms1))),
            (MFSQRT_M (MInfo.Matrix ACCR:$ms1))>;
}
def : Pat<(mfloat16_t (int_riscv_mfsqrt_hf_m (mfloat16_t ACCR:$ms1))),
          (MFSQRT_HF_M (mfloat16_t ACCR:$ms1))>;
def : Pat<(mfloat32_t (int_riscv_mfsqrt_f_m (mfloat32_t ACCR:$ms1))),
          (MFSQRT_F_M (mfloat32_t ACCR:$ms1))>;
def : Pat<(mfloat64_t (int_riscv_mfsqrt_d_m (mfloat64_t ACCR:$ms1))),
          (MFSQRT_D_M (mfloat64_t ACCR:$ms1))>;

foreach MInfo = AllEletDoubleFPMatrixs in {
  defvar SInfo = MInfo.Mti;
  defvar DInfo = MInfo.Wti;
  def : PatMElet<int_riscv_mfwadd_mm, MFWADD_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfwadd_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MFWADD_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
  def : PatMElet<int_riscv_mfwsub_mm, MFWSUB_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfwsub_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MFWSUB_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
  def : PatMElet<int_riscv_mfwmul_mm, MFWMUL_MM, SInfo, DInfo>;
  def : PatMElet<!cast<SDPatternOperator>("int_riscv_mfwmul_"#SInfo.alias#"_mm"),
                 !cast<Instruction>("MFWMUL_"#SInfo.ALIAS#"_MM"),
                 SInfo, DInfo>;
}

// 4.6. Type-Convert Instructions
defset list<MatrixTypeInfoMToW> AllDoubleIntMatrixs = {
  // def : MatrixTypeInfoMToW<MI4M1,   MI8M1>;
  def : MatrixTypeInfoMToW<MI8M1,   MI16M1>;
  def : MatrixTypeInfoMToW<MI16M1,  MI32M1>;
  def : MatrixTypeInfoMToW<MI32M1,  MI64M1>;
}

defset list<MatrixTypeInfoMToW> AllQuadIntMatrixs = {
  // def : MatrixTypeInfoMToW<MI4M1,   MI16M1>;
  def : MatrixTypeInfoMToW<MI8M1,   MI32M1>;
}

defset list<MatrixTypeInfoMToW> AllOctIntMatrixs = {
  // def : MatrixTypeInfoMToW<MI4M1,   MI32M1>;
}

// mfcvt x -> f
defset list<MatrixTypeInfoMToW> AllMFCVTMatrixs = {
  def : MatrixTypeInfoMToW<MI16M1,  MF16M1>;
  def : MatrixTypeInfoMToW<MI32M1,  MF32M1>;
  def : MatrixTypeInfoMToW<MI64M1,  MF64M1>;
}

// f -> fw
defset list<MatrixTypeInfoMToW> AllDoubleFloatMatrixs = {
  // def : MatrixTypeInfoMToW<MF8M1,  MF16M1>;
  def : MatrixTypeInfoMToW<MF16M1,  MF32M1>;
  def : MatrixTypeInfoMToW<MF32M1,  MF64M1>;
}

// x -> fw
defset list<MatrixTypeInfoMToW> AllDoubleXFWMatrixs = {
  // def : MatrixTypeInfoMToW<MI4M1,  MF8M1>;
  def : MatrixTypeInfoMToW<MI8M1,  MF16M1>;
  def : MatrixTypeInfoMToW<MI16M1, MF32M1>;
  def : MatrixTypeInfoMToW<MI32M1, MF64M1>;
}

// xw -> f
defset list<MatrixTypeInfoMToW> AllDoubleXWFMatrixs = {
  // def : MatrixTypeInfoMToW<MF8M1,  MI16M1>;
  def : MatrixTypeInfoMToW<MI32M1, MF16M1>;
  def : MatrixTypeInfoMToW<MI64M1, MF32M1>;
}

// x -> fq
defset list<MatrixTypeInfoMToW> AllQuadXFQNatrixs = {
  // def : MatrixTypeInfoMToW<MI4M1, MF16M1>;
  def : MatrixTypeInfoMToW<MI8M1, MF32M1>;
}

class PatCVT<SDPatternOperator OpNode, Instruction Inst, MatrixTypeInfo otype, MatrixTypeInfo itype>
    : Pat<(otype.Matrix (OpNode (itype.Matrix ACCR:$ts1))),
          (otype.Matrix (Inst (itype.Matrix ACCR:$ts1)))>;

// I to I
foreach mtype = AllIntegerMatrixs in {
  // uint -> int
  def : PatCVT<int_riscv_mcvt_x_xu_m, MCVT_X_XU_M, mtype, mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mcvt_"#mtype.alias#"_u"#mtype.alias#"_m"),
               !cast<Instruction>("MCVT_"#mtype.ALIAS#"_U"#mtype.ALIAS#"_M"),
               mtype, mtype>;
  // int -> uint
  def : PatCVT<int_riscv_mcvt_xu_x_m, MCVT_XU_X_M, mtype, mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mcvt_u"#mtype.alias#"_"#mtype.alias#"_m"),
               !cast<Instruction>("MCVT_U"#mtype.ALIAS#"_"#mtype.ALIAS#"_M"),
               mtype, mtype>;
}

foreach M2W = AllDoubleIntMatrixs in {
  defvar Mtype = M2W.Mti;
  defvar Wtype = M2W.Wti;
  // u -> wu
  def : PatCVT<int_riscv_mwcvtu_xw_x_m, MWCVTU_XW_X_M, Wtype, Mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mwcvtu_"#Wtype.alias#"_"#Mtype.alias#"_m"),
               !cast<Instruction>("MWCVTU_"#Wtype.ALIAS#"_"#Mtype.ALIAS#"_M"),
               Wtype, Mtype>;
  // i -> wi
  def : PatCVT<int_riscv_mwcvt_xw_x_m, MWCVT_XW_X_M, Wtype, Mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mwcvt_"#Wtype.alias#"_"#Mtype.alias#"_m"),
               !cast<Instruction>("MWCVT_"#Wtype.ALIAS#"_"#Mtype.ALIAS#"_M"),
               Wtype, Mtype>;
  // wu -> u
  def : PatCVT<int_riscv_mncvtu_x_xw_m, MNCVTU_X_XW_M, Mtype, Wtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mncvtu_"#Mtype.alias#"_"#Wtype.alias#"_m"),
               !cast<Instruction>("MNCVTU_"#Mtype.ALIAS#"_"#Wtype.ALIAS#"_M"),
               Mtype, Wtype>;
  // wi -> i
  def : PatCVT<int_riscv_mncvt_x_xw_m, MNCVT_X_XW_M, Mtype, Wtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mncvt_"#Mtype.alias#"_"#Wtype.alias#"_m"),
               !cast<Instruction>("MNCVT_"#Mtype.ALIAS#"_"#Wtype.ALIAS#"_M"),
               Mtype, Wtype>;
}

foreach M2W = AllQuadIntMatrixs in {
  defvar Mtype = M2W.Mti;
  defvar Wtype = M2W.Wti;
  // u -> wu
  def : PatCVT<int_riscv_mwcvtu_xq_x_m, MWCVTU_XQ_X_M, Wtype, Mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mwcvtu_"#Wtype.alias#"_"#Mtype.alias#"_m"),
               !cast<Instruction>("MWCVTU_"#Wtype.ALIAS#"_"#Mtype.ALIAS#"_M"),
               Wtype, Mtype>;
  // i -> wi
  def : PatCVT<int_riscv_mwcvt_xq_x_m, MWCVT_XQ_X_M, Wtype, Mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mwcvt_"#Wtype.alias#"_"#Mtype.alias#"_m"),
               !cast<Instruction>("MWCVT_"#Wtype.ALIAS#"_"#Mtype.ALIAS#"_M"),
               Wtype, Mtype>;
  // wu -> u
  def : PatCVT<int_riscv_mncvtu_x_xq_m, MNCVTU_X_XQ_M, Mtype, Wtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mncvtu_"#Mtype.alias#"_"#Wtype.alias#"_m"),
               !cast<Instruction>("MNCVTU_"#Mtype.ALIAS#"_"#Wtype.ALIAS#"_M"),
               Mtype, Wtype>;
  // wi -> i
  def : PatCVT<int_riscv_mncvt_x_xq_m, MNCVT_X_XQ_M, Mtype, Wtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mncvt_"#Mtype.alias#"_"#Wtype.alias#"_m"),
               !cast<Instruction>("MNCVT_"#Mtype.ALIAS#"_"#Wtype.ALIAS#"_M"),
               Mtype, Wtype>;
}

// F to F
foreach F2F = AllDoubleFloatMatrixs in {
  defvar Mtype = F2F.Mti;
  defvar Wtype = F2F.Wti;
  // f -> fw
  def : PatCVT<int_riscv_mfwcvt_fw_f_m, MFWCVT_FW_F_M, Wtype, Mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfwcvt_"#Wtype.alias#"_"#Mtype.alias#"_m"),
               !cast<Instruction>("MFWCVT_"#Wtype.ALIAS#"_"#Mtype.ALIAS#"_M"),
               Wtype, Mtype>;
  // fw -> f
  def : PatCVT<int_riscv_mfncvt_f_fw_m, MFNCVT_F_FW_M, Mtype, Wtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfncvt_"#Mtype.alias#"_"#Wtype.alias#"_m"),
               !cast<Instruction>("MFNCVT_"#Mtype.ALIAS#"_"#Wtype.ALIAS#"_M"),
               Mtype, Wtype>;
}

// I to F
foreach I2F = AllMFCVTMatrixs in {
  defvar Itype = I2F.Mti;
  defvar Ftype = I2F.Wti;
  def : PatCVT<int_riscv_mfcvt_f_x_m, MFCVT_F_X_M, Ftype, Itype>;
  def : PatCVT<int_riscv_mfcvt_x_f_m, MFCVT_X_F_M, Itype, Ftype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfcvt_"#Ftype.alias#"_"#Itype.alias#"_m"),
               !cast<Instruction>("MFCVT_"#Ftype.ALIAS#"_"#Itype.ALIAS#"_M"),
               Ftype, Itype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfcvt_"#Itype.alias#"_"#Ftype.alias#"_m"),
               !cast<Instruction>("MFCVT_"#Itype.ALIAS#"_"#Ftype.ALIAS#"_M"),
               Itype, Ftype>;

  def : PatCVT<int_riscv_mfcvtu_f_x_m, MFCVTU_F_X_M, Ftype, Itype>;
  def : PatCVT<int_riscv_mfcvtu_x_f_m, MFCVTU_X_F_M, Itype, Ftype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfcvtu_"#Ftype.alias#"_"#Itype.alias#"_m"),
               !cast<Instruction>("MFCVTU_"#Ftype.ALIAS#"_"#Itype.ALIAS#"_M"),
               Ftype, Itype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfcvtu_"#Itype.alias#"_"#Ftype.alias#"_m"),
               !cast<Instruction>("MFCVTU_"#Itype.ALIAS#"_"#Ftype.ALIAS#"_M"),
               Itype, Ftype>;
}

foreach I2F = AllDoubleXFWMatrixs in {
  defvar Mtype = I2F.Mti;
  defvar Wtype = I2F.Wti;
  // u -> fw
  def : PatCVT<int_riscv_mfwcvtu_fw_x_m, MFWCVTU_FW_X_M, Wtype, Mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfwcvtu_"#Wtype.alias#"_"#Mtype.alias#"_m"),
               !cast<Instruction>("MFWCVTU_"#Wtype.ALIAS#"_"#Mtype.ALIAS#"_M"),
               Wtype, Mtype>;
  // i -> fw
  def : PatCVT<int_riscv_mfwcvt_fw_x_m, MFWCVT_FW_X_M, Wtype, Mtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfwcvt_"#Wtype.alias#"_"#Mtype.alias#"_m"),
               !cast<Instruction>("MFWCVT_"#Wtype.ALIAS#"_"#Mtype.ALIAS#"_M"),
               Wtype, Mtype>;
  // wf -> u
  def : PatCVT<int_riscv_mfncvtu_x_fw_m, MFNCVTU_X_FW_M, Mtype, Wtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfncvtu_"#Mtype.alias#"_"#Wtype.alias#"_m"),
               !cast<Instruction>("MFNCVTU_"#Mtype.ALIAS#"_"#Wtype.ALIAS#"_M"),
               Mtype, Wtype>;
  // wf -> i
  def : PatCVT<int_riscv_mfncvt_x_fw_m, MFNCVT_X_FW_M, Mtype, Wtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfncvt_"#Mtype.alias#"_"#Wtype.alias#"_m"),
               !cast<Instruction>("MFNCVT_"#Mtype.ALIAS#"_"#Wtype.ALIAS#"_M"),
               Mtype, Wtype>;
}

foreach I2F = AllDoubleXWFMatrixs in {
  defvar XWtype = I2F.Mti; // xw
  defvar Ftype = I2F.Wti;  // f
  // xuw -> f
  def : PatCVT<int_riscv_mfncvtu_f_xw_m, MFNCVTU_F_XW_M, Ftype, XWtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfncvtu_"#Ftype.alias#"_"#XWtype.alias#"_m"),
               !cast<Instruction>("MFNCVTU_"#Ftype.ALIAS#"_"#XWtype.ALIAS#"_M"),
               Ftype, XWtype>;
  // xw -> f
  def : PatCVT<int_riscv_mfncvt_f_xw_m, MFNCVT_F_XW_M, Ftype, XWtype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfncvt_"#Ftype.alias#"_"#XWtype.alias#"_m"),
               !cast<Instruction>("MFNCVT_"#Ftype.ALIAS#"_"#XWtype.ALIAS#"_M"),
               Ftype, XWtype>;
  // f -> xuw
  def : PatCVT<int_riscv_mfwcvtu_xw_f_m, MFWCVTU_XW_F_M, XWtype, Ftype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfwcvtu_"#XWtype.alias#"_"#Ftype.alias#"_m"),
               !cast<Instruction>("MFWCVTU_"#XWtype.ALIAS#"_"#Ftype.ALIAS#"_M"),
               XWtype, Ftype>;
  // f -> xw
  def : PatCVT<int_riscv_mfwcvt_xw_f_m, MFWCVT_XW_F_M, XWtype, Ftype>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfwcvt_"#XWtype.alias#"_"#Ftype.alias#"_m"),
               !cast<Instruction>("MFWCVT_"#XWtype.ALIAS#"_"#Ftype.ALIAS#"_M"),
               XWtype, Ftype>;
}

foreach I2F = AllQuadXFQNatrixs in {
  defvar XType = I2F.Mti;
  defvar FQType = I2F.Wti;
  // xu -> fq
  def : PatCVT<int_riscv_mfwcvtu_fq_x_m, MFWCVTU_FQ_X_M, FQType, XType>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfwcvtu_"#FQType.alias#"_"#XType.alias#"_m"),
               !cast<Instruction>("MFWCVTU_"#FQType.ALIAS#"_"#XType.ALIAS#"_M"),
               FQType, XType>;
  // x -> fq
  def : PatCVT<int_riscv_mfwcvt_fq_x_m, MFWCVT_FQ_X_M, FQType, XType>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfwcvt_"#FQType.alias#"_"#XType.alias#"_m"),
               !cast<Instruction>("MFWCVT_"#FQType.ALIAS#"_"#XType.ALIAS#"_M"),
               FQType, XType>;
  // fq -> xu
  def : PatCVT<int_riscv_mfncvtu_x_fq_m, MFNCVTU_X_FQ_M, XType, FQType>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfncvtu_"#XType.alias#"_"#FQType.alias#"_m"),
               !cast<Instruction>("MFNCVTU_"#XType.ALIAS#"_"#FQType.ALIAS#"_M"),
               XType, FQType>;

  // fq -> x
  def : PatCVT<int_riscv_mfncvt_x_fq_m, MFNCVT_X_FQ_M, XType, FQType>;
  def : PatCVT<!cast<SDPatternOperator>("int_riscv_mfncvt_"#XType.alias#"_"#FQType.alias#"_m"),
               !cast<Instruction>("MFNCVT_"#XType.ALIAS#"_"#FQType.ALIAS#"_M"),
               XType, FQType>;
}

// Matrix Sparsity Extension
foreach MInfo = AllMMAIntMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mmau_spa_mm,  MMAU_SPA_MM,  TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msmau_spa_mm, MSMAU_SPA_MM, TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mma_spa_mm,   MMA_SPA_MM,   TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msma_spa_mm,  MSMA_SPA_MM,  TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mmau_spb_mm,  MMAU_SPB_MM,  TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msmau_spb_mm, MSMAU_SPB_MM, TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mma_spb_mm,   MMA_SPB_MM,   TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msma_spb_mm,  MSMA_SPB_MM,  TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mmau_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MMAU_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msmau_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSMAU_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mma_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MMA_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msma_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSMA_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mmau_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MMAU_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msmau_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSMAU_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mma_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MMA_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msma_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSMA_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

foreach MInfo = AllMMAQuadIntMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mqmau_spa_mm,  MQMAU_SPA_MM,  TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mqmau_spb_mm,  MQMAU_SPB_MM,  TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msqmau_spa_mm, MSQMAU_SPA_MM, TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msqmau_spb_mm, MSQMAU_SPB_MM, TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mqma_spa_mm,   MQMA_SPA_MM,   TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mqma_spb_mm,   MQMA_SPB_MM,   TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msqma_spa_mm,  MSQMA_SPA_MM,  TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_msqma_spb_mm,  MSQMA_SPB_MM,  TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mqmau_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MQMAU_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mqmau_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MQMAU_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msqmau_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSQMAU_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msqmau_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSQMAU_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mqma_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MQMA_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mqma_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MQMA_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msqma_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSQMA_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_msqma_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MSQMA_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

// foreach MInfo = AllOctIntMatrixs in {
//   defvar TRInfo = MInfo.Mti;
//   defvar ACCInfo = MInfo.Wti;
//   def : PatMMul<int_riscv_momau_spa_mm,  MOMAU_SPA_MM,  TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_momau_spb_mm,  MOMAU_SPB_MM,  TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_msomau_spa_mm, MSOMAU_SPA_MM, TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_msomau_spb_mm, MSOMAU_SPB_MM, TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_moma_spa_mm,   MOMA_SPA_MM,   TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_moma_spb_mm,   MOMA_SPB_MM,   TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_msoma_spa_mm,  MSOMA_SPA_MM,  TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_msoma_spb_mm,  MSOMA_SPB_MM,  TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_momau_spa_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MOMAU_SPA_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_momau_spb_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MOMAU_SPB_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_msomau_spa_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MSOMAU_SPA_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_msomau_spb_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MSOMAU_SPB_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_moma_spa_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MOMA_SPA_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_moma_spb_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MOMA_SPB_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_msoma_spa_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MSOMA_SPA_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_msoma_spb_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MSOMA_SPB_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
// }

foreach MInfo = AllMMAFPMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mfma_spa_mm, MFMA_SPA_MM, TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mfma_spb_mm, MFMA_SPB_MM, TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfma_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MFMA_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfma_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MFMA_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

foreach MInfo = AllMMADoubleFPMatrixs in {
  defvar TRInfo = MInfo.Mti;
  defvar ACCInfo = MInfo.Wti;
  def : PatMMul<int_riscv_mfwma_spa_mm, MFWMA_SPA_MM, TRInfo, ACCInfo>;
  def : PatMMul<int_riscv_mfwma_spb_mm, MFWMA_SPB_MM, TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfwma_spa_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MFWMA_SPA_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
  def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfwma_spb_"#TRInfo.alias#"_mm"),
                !cast<Instruction>("MFWMA_SPB_"#TRInfo.ALIAS#"_MM"),
                TRInfo, ACCInfo>;
}

// foreach MInfo = AllMMAQuadFPMatrixs in {
//   defvar TRInfo = MInfo.Mti;
//   defvar ACCInfo = MInfo.Wti;
//   def : PatMMul<int_riscv_mfqma_spa_mm, MFQMA_SPA_MM, TRInfo, ACCInfo>;
//   def : PatMMul<int_riscv_mfqma_spb_mm, MFQMA_SPB_MM, TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfqma_spa_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MFQMA_SPA_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
//   def : PatMMul<!cast<SDPatternOperator>("int_riscv_mfqma_spb_"#TRInfo.alias#"_mm"),
//                 !cast<Instruction>("MFQMA_SPB_"#TRInfo.ALIAS#"_MM"),
//                 TRInfo, ACCInfo>;
// }

class PatMMV<SDPatternOperator OpNode, Instruction Inst,  ValueType type_dest, ValueType type_src>
    : Pat<(type_dest (OpNode type_src:$tr1, GPR:$r2)),
          (type_dest (Inst type_src:$tr1, GPR:$r2))>;

foreach mti = AllMatrixs in {
def : PatMMV<int_riscv_mmvar_v_m, !cast<Instruction>("MMVARE"#mti.SEW#"_V_M"), mti.Vector, mti.Matrix>;
def : PatMMV<int_riscv_mmvbr_v_m, !cast<Instruction>("MMVBRE"#mti.SEW#"_V_M"), mti.Vector, mti.Matrix>;
def : PatMMV<int_riscv_mmvcr_v_m, !cast<Instruction>("MMVCRE"#mti.SEW#"_V_M"), mti.Vector, mti.Matrix>;
def : PatMMV<int_riscv_mmvar_m_v, !cast<Instruction>("MMVARE"#mti.SEW#"_M_V"), mti.Matrix, mti.Vector>;
def : PatMMV<int_riscv_mmvbr_m_v, !cast<Instruction>("MMVBRE"#mti.SEW#"_M_V"), mti.Matrix, mti.Vector>;
def : PatMMV<int_riscv_mmvcr_m_v, !cast<Instruction>("MMVCRE"#mti.SEW#"_M_V"), mti.Matrix, mti.Vector>;
def : PatMMV<int_riscv_mmvac_v_m, !cast<Instruction>("MMVACE"#mti.SEW#"_V_M"), mti.Vector, mti.Matrix>;
def : PatMMV<int_riscv_mmvbc_v_m, !cast<Instruction>("MMVBCE"#mti.SEW#"_V_M"), mti.Vector, mti.Matrix>;
def : PatMMV<int_riscv_mmvcc_v_m, !cast<Instruction>("MMVCCE"#mti.SEW#"_V_M"), mti.Vector, mti.Matrix>;
def : PatMMV<int_riscv_mmvac_m_v, !cast<Instruction>("MMVACE"#mti.SEW#"_M_V"), mti.Matrix, mti.Vector>;
def : PatMMV<int_riscv_mmvbc_m_v, !cast<Instruction>("MMVBCE"#mti.SEW#"_M_V"), mti.Matrix, mti.Vector>;
def : PatMMV<int_riscv_mmvcc_m_v, !cast<Instruction>("MMVCCE"#mti.SEW#"_M_V"), mti.Matrix, mti.Vector>;

// date move, acc -> tr, tr -> acc
def : PatMMV<int_riscv_mmv_a_t, !cast<Instruction>("MMVE"#mti.SEW#"_A_T"), mti.Matrix, mti.Matrix>;
def : PatMMV<int_riscv_mmv_t_a, !cast<Instruction>("MMVE"#mti.SEW#"_T_A"), mti.Matrix, mti.Matrix>;
}
