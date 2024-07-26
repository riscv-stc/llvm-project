// Matrix
let TargetPrefix = "riscv" in {
  class MConfigIntrinsic
      : Intrinsic<[llvm_anyint_ty],
                  [LLVMMatchType<0>],
                  [IntrNoMem, IntrHasSideEffects]>;

  def int_riscv_msettype   : MConfigIntrinsic;
  def int_riscv_msettypei  : MConfigIntrinsic;
  def int_riscv_msettilemi : MConfigIntrinsic;
  def int_riscv_msettilem  : MConfigIntrinsic;
  def int_riscv_msettileni : MConfigIntrinsic;
  def int_riscv_msettilen  : MConfigIntrinsic;
  def int_riscv_msettileki : MConfigIntrinsic;
  def int_riscv_msettilek  : MConfigIntrinsic;
  def int_riscv_msettile   : MConfigIntrinsic;

  class MLoadIntrinsic
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMPointerType<LLVMMatchType<0>>,
                   llvm_anyint_ty, LLVMMatchType<1>],
                  [NoCapture<ArgIndex<0>>, IntrReadMem]>, RISCVVIntrinsic;

  def int_riscv_mlae_m : MLoadIntrinsic;
  def int_riscv_mlate_m : MLoadIntrinsic;
  def int_riscv_mlbe_m : MLoadIntrinsic;
  def int_riscv_mlbte_m : MLoadIntrinsic;
  def int_riscv_mlce_m : MLoadIntrinsic;
  def int_riscv_mlcte_m : MLoadIntrinsic;
  def int_riscv_mlre_m : MLoadIntrinsic;

  class MStoreIntrinsic
      : Intrinsic<[],
                  [llvm_anyvector_ty,
                   LLVMPointerType<LLVMMatchType<0>>,
                   llvm_anyint_ty, LLVMMatchType<1>],
                  [NoCapture<ArgIndex<1>>, IntrWriteMem]>, RISCVVIntrinsic;

  def int_riscv_msae_m : MStoreIntrinsic;
  def int_riscv_msate_m : MStoreIntrinsic;
  def int_riscv_msbe_m : MStoreIntrinsic;
  def int_riscv_msbte_m : MStoreIntrinsic;
  def int_riscv_msce_m : MStoreIntrinsic;
  def int_riscv_mscte_m : MStoreIntrinsic;
  def int_riscv_msre_m : MStoreIntrinsic;

  def int_riscv_mmv_x_s : Intrinsic<[llvm_anyint_ty],
                                    [llvm_anyvector_ty, llvm_anyint_ty],
                                    [IntrNoMem]>, RISCVVIntrinsic;

  def int_riscv_mmv_s_x : Intrinsic<[llvm_anyvector_ty],
                                    [LLVMMatchType<0>, llvm_anyint_ty,
                                     llvm_anyint_ty],
                                    [IntrNoMem]>, RISCVVIntrinsic;

  def int_riscv_mfmv_f_s : Intrinsic<[llvm_anyfloat_ty],
                                    [llvm_anyvector_ty, llvm_anyint_ty],
                                    [IntrNoMem]>, RISCVVIntrinsic;

  def int_riscv_mfmv_s_f : Intrinsic<[llvm_anyvector_ty],
                                     [LLVMMatchType<0>, llvm_anyfloat_ty,
                                      llvm_anyint_ty],
                                     [IntrNoMem]>, RISCVVIntrinsic;

  class MBroadCast : Intrinsic<[llvm_anyvector_ty],
                               [LLVMMatchType<0>],
                               [IntrNoMem]>, RISCVVIntrinsic;

  def int_riscv_mbcar_m : MBroadCast;
  def int_riscv_mbcbr_m : MBroadCast;
  def int_riscv_mbccr_m : MBroadCast;
  def int_riscv_mbcac_m : MBroadCast;
  def int_riscv_mbcbc_m : MBroadCast;
  def int_riscv_mbccc_m : MBroadCast;
  def int_riscv_mbcae_m : MBroadCast;
  def int_riscv_mbcbe_m : MBroadCast;
  def int_riscv_mbcce_m : MBroadCast;

  // Input: (vector_in, lmul)
  class MUnaryIntrinsic
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMMatchType<0>],
                  [IntrNoMem]>, RISCVVIntrinsic;

  // Input: (vector_in, vector_in, lmul)
  class MBinaryIntrinsic
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMMatchType<0>, LLVMMatchType<0>, LLVMMatchType<0>],
                  [IntrNoMem]>, RISCVVIntrinsic;

  // Input: (vector_in, lmul)
  class MUnaryIntrinsicLMUL
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMMatchType<0>, llvm_anyint_ty],
                  [IntrNoMem]>, RISCVVIntrinsic;

  // Input: (vector_in, vector_in, lmul)
  class MBinaryIntrinsicLMUL
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMMatchType<0>, LLVMMatchType<0>, llvm_anyint_ty],
                  [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryIntrinsicLMULSU
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMMatchType<0>, llvm_anyvector_ty, llvm_anyint_ty],
                  [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryIntrinsicLMULW
      : Intrinsic<[llvm_anyvector_ty],
                  [llvm_anyvector_ty, LLVMMatchType<1>, llvm_anyint_ty],
                  [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryIntrinsicW
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMMatchType<0>, llvm_anyvector_ty, LLVMMatchType<1>],
                  [IntrNoMem]>, RISCVVIntrinsic;

  def int_riscv_mmau_mm : MBinaryIntrinsic;
  def int_riscv_msmau_mm : MBinaryIntrinsic;
  def int_riscv_mma_mm : MBinaryIntrinsic;
  def int_riscv_msma_mm : MBinaryIntrinsic;
  def int_riscv_mfma_mm : MBinaryIntrinsic;

  def int_riscv_mwmau_mm : MBinaryIntrinsicW;
  def int_riscv_mswmau_mm : MBinaryIntrinsicW;
  def int_riscv_mwma_mm : MBinaryIntrinsicW;
  def int_riscv_mswma_mm : MBinaryIntrinsicW;
  def int_riscv_mfwma_mm : MBinaryIntrinsicW;

  def int_riscv_mqmau_mm : MBinaryIntrinsicW;
  def int_riscv_msqmau_mm : MBinaryIntrinsicW;
  def int_riscv_mqma_mm : MBinaryIntrinsicW;
  def int_riscv_msqma_mm : MBinaryIntrinsicW;

  def int_riscv_maddu_mm : MBinaryIntrinsicLMUL;
  def int_riscv_msaddu_mm : MBinaryIntrinsicLMUL;

  def int_riscv_madd_mm : MBinaryIntrinsicLMUL;
  def int_riscv_msadd_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mfadd_mm : MBinaryIntrinsicLMUL;

  def int_riscv_mwaddu_mm : MBinaryIntrinsicLMULW;
  def int_riscv_mwadd_mm : MBinaryIntrinsicLMULW;
  def int_riscv_mfwadd_mm : MBinaryIntrinsicLMULW;

  def int_riscv_msubu_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mssubu_mm : MBinaryIntrinsicLMUL;
  def int_riscv_msub_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mssub_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mfsub_mm : MBinaryIntrinsicLMUL;

  def int_riscv_mwsubu_mm : MBinaryIntrinsicLMULW;
  def int_riscv_mwsub_mm : MBinaryIntrinsicLMULW;
  def int_riscv_mfwsub_mm : MBinaryIntrinsicLMULW;

  def int_riscv_mminu_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mmin_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mfmin_mm : MBinaryIntrinsicLMUL;

  def int_riscv_mmaxu_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mmax_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mfmax_mm : MBinaryIntrinsicLMUL;

  def int_riscv_msmulu_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mmul_mm : MBinaryIntrinsicLMUL;
  def int_riscv_msmul_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mfmul_mm : MBinaryIntrinsicLMUL;

  def int_riscv_mmulhu_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mmulh_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mmulhsu_mm : MBinaryIntrinsicLMULSU;
  def int_riscv_msmulsu_mm : MBinaryIntrinsicLMULSU;

  def int_riscv_mwmulu_mm : MBinaryIntrinsicLMULW;
  def int_riscv_mwmul_mm : MBinaryIntrinsicLMULW;
  def int_riscv_mfwmul_mm : MBinaryIntrinsicLMULW;
  def int_riscv_mwmulsu_mm
      : Intrinsic<[llvm_anyvector_ty],
                  [llvm_anyvector_ty, llvm_anyvector_ty, llvm_anyint_ty],
                  [IntrNoMem]>, RISCVVIntrinsic;

  def int_riscv_mfdiv_mm : MBinaryIntrinsicLMUL;
  def int_riscv_mfsqrt_m : MUnaryIntrinsicLMUL;

  class MFConvertIntrinsic
      : Intrinsic<[llvm_anyvector_ty],
                  [llvm_anyvector_ty, llvm_anyint_ty],
                  [IntrNoMem]>, RISCVVIntrinsic;

  def int_riscv_mfncvt_f_fw_m : MFConvertIntrinsic;
  def int_riscv_mfwcvt_fw_f_m : MFConvertIntrinsic;

  def int_riscv_mfcvt_f_x_m : MFConvertIntrinsic;
  def int_riscv_mfncvt_f_xw_m : MFConvertIntrinsic;
  def int_riscv_mfncvt_f_xq_m : MFConvertIntrinsic;
  def int_riscv_mfwcvt_fw_x_m : MFConvertIntrinsic;
  def int_riscv_mfcvt_fw_xw_m : MFConvertIntrinsic;
  def int_riscv_mfncvt_fw_xq_m : MFConvertIntrinsic;

  def int_riscv_mfcvt_x_f_m : MFConvertIntrinsic;
  def int_riscv_mfwcvt_xw_f_m : MFConvertIntrinsic;
  def int_riscv_mfwcvt_xq_f_m : MFConvertIntrinsic;
  def int_riscv_mfncvt_x_fw_m : MFConvertIntrinsic;
  def int_riscv_mfcvt_xw_fw_m : MFConvertIntrinsic;
  def int_riscv_mfwcvt_xq_fw_m : MFConvertIntrinsic;

  class MLoadVIntrinsic
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMPointerType<LLVMMatchType<0>>,
                   llvm_anyint_ty],
                  [NoCapture<ArgIndex<0>>, IntrReadMem]>, RISCVVIntrinsic;

  def int_riscv_mlae_v : MLoadVIntrinsic;
  def int_riscv_mlbe_v : MLoadVIntrinsic;
  def int_riscv_mlce_v : MLoadVIntrinsic;

  class MStoreVIntrinsic
      : Intrinsic<[],
                  [llvm_anyvector_ty,
                   LLVMPointerType<LLVMMatchType<0>>,
                   llvm_anyint_ty],
                  [NoCapture<ArgIndex<1>>, IntrWriteMem]>, RISCVVIntrinsic;

  def int_riscv_msae_v : MStoreVIntrinsic;
  def int_riscv_msbe_v : MStoreVIntrinsic;
  def int_riscv_msce_v : MStoreVIntrinsic;

  class MMVIntrinsic
      : Intrinsic<[llvm_anyvector_ty],
                  [llvm_anyvector_ty, llvm_anyint_ty],
                  [IntrNoMem]>, RISCVVIntrinsic;

  def int_riscv_mmvar_v_m : MMVIntrinsic;
  def int_riscv_mmvbr_v_m : MMVIntrinsic;
  def int_riscv_mmvcr_v_m : MMVIntrinsic;
  def int_riscv_mmvar_m_v : MMVIntrinsic;
  def int_riscv_mmvbr_m_v : MMVIntrinsic;
  def int_riscv_mmvcr_m_v : MMVIntrinsic;

  def int_riscv_mmvac_v_m : MMVIntrinsic;
  def int_riscv_mmvbc_v_m : MMVIntrinsic;
  def int_riscv_mmvcc_v_m : MMVIntrinsic;
  def int_riscv_mmvac_m_v : MMVIntrinsic;
  def int_riscv_mmvbc_m_v : MMVIntrinsic;
  def int_riscv_mmvcc_m_v : MMVIntrinsic;

// ZMic
  class MConfigIntrinsicZmic
      : Intrinsic<[llvm_anyint_ty],
                  [LLVMMatchType<0>, LLVMMatchType<0>],
                  [IntrNoMem, IntrHasSideEffects]>;

  def int_riscv_msetoutsh : MConfigIntrinsicZmic;
  def int_riscv_msetinsh : MConfigIntrinsicZmic;
  def int_riscv_msetsk : MConfigIntrinsicZmic;
  def int_riscv_msetpadval : MConfigIntrinsic;

  class MLoadIntrinsicZmic
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMPointerType<LLVMMatchType<0>>,
                   llvm_anyint_ty],
                  [NoCapture<ArgIndex<0>>, IntrReadMem]>, RISCVVIntrinsic;

  def int_riscv_mlufae_m : MLoadIntrinsicZmic;
  def int_riscv_mlufbe_m : MLoadIntrinsicZmic;
  def int_riscv_mlufce_m : MLoadIntrinsicZmic;

  class MStoreIntrinsicZmic
      : Intrinsic<[],
                  [llvm_anyvector_ty,
                   LLVMPointerType<LLVMMatchType<0>>,
                   llvm_anyint_ty],
                  [NoCapture<ArgIndex<1>>, IntrWriteMem]>, RISCVVIntrinsic;

  def int_riscv_msfdae_m : MStoreIntrinsicZmic;
  def int_riscv_msfdbe_m : MStoreIntrinsicZmic;
  def int_riscv_msfdce_m : MStoreIntrinsicZmic;

} // TargetPrefix = "riscv"
