// Matrix
let TargetPrefix = "riscv" in {
  // Configuration Instructions
  class MConfigIntrinsic
      : Intrinsic<[llvm_anyint_ty],
                  [LLVMMatchType<0>],
                  [IntrNoMem, IntrHasSideEffects]>;

  class MConfigIntrinsicZmic
      : Intrinsic<[llvm_anyint_ty],
                  [LLVMMatchType<0>, LLVMMatchType<0>],
                  [IntrNoMem, IntrHasSideEffects]>;

  class MLoadIntrinsic
      : Intrinsic<[llvm_anyvector_ty],
                  [LLVMPointerType<LLVMMatchType<0>>,
                   llvm_anyint_ty],
                  [NoCapture<ArgIndex<0>>, IntrReadMem]>, RISCVVIntrinsic;

  class MStoreIntrinsic
      : Intrinsic<[],
                  [llvm_anyvector_ty,
                   LLVMPointerType<LLVMMatchType<0>>,
                   llvm_anyint_ty],
                  [NoCapture<ArgIndex<1>>, IntrWriteMem]>, RISCVVIntrinsic;

  class MUnaryMMIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                      [LLVMMatchType<0>],
                                      [IntrNoMem]>, RISCVVIntrinsic;

  class MCVTIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyvector_ty],
                                  [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryMMIIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                        [llvm_anyvector_ty, llvm_anyint_ty],
                                        [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryIMIIntrinsic : Intrinsic<[llvm_anyint_ty],
                                        [llvm_anyvector_ty, llvm_anyint_ty],
                                        [IntrNoMem]>, RISCVVIntrinsic;

  class MMoveMMIIIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                       [LLVMMatchType<0>, llvm_anyint_ty, llvm_anyint_ty],
                                       [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryFMIIntrinsic : Intrinsic<[llvm_anyfloat_ty],
                                        [llvm_anyvector_ty, llvm_anyint_ty],
                                        [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryMFIIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                        [LLVMMatchType<0>, llvm_anyfloat_ty, llvm_anyint_ty],
                                        [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryMMMIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                        [LLVMMatchType<0>, LLVMMatchType<0>],
                                        [IntrNoMem]>, RISCVVIntrinsic;

  class MBinaryWMMMIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                         [llvm_anyvector_ty, LLVMMatchType<1>],
                                         [IntrNoMem]>, RISCVVIntrinsic;

  class MTernaryMMMMIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                          [LLVMMatchType<0>, LLVMMatchType<0>, LLVMMatchType<0>],
                                          [IntrNoMem]>, RISCVVIntrinsic;

  class MTernaryWMMMMIntrinsic : Intrinsic<[llvm_anyvector_ty],
                                           [LLVMMatchType<0>, llvm_anyvector_ty, LLVMMatchType<1>],
                                           [IntrNoMem]>, RISCVVIntrinsic;

  // Configuration Instructions
  def int_riscv_msettype   : MConfigIntrinsic;
  def int_riscv_msettypei  : MConfigIntrinsic;
  def int_riscv_msettypehi : MConfigIntrinsic;
  def int_riscv_msettilemi : MConfigIntrinsic;
  def int_riscv_msettilem  : MConfigIntrinsic;
  def int_riscv_msettileni : MConfigIntrinsic;
  def int_riscv_msettilen  : MConfigIntrinsic;
  def int_riscv_msettileki : MConfigIntrinsic;
  def int_riscv_msettilek  : MConfigIntrinsic;
  def int_riscv_msettspi   : MConfigIntrinsic;
  def int_riscv_msettsp    : MConfigIntrinsic;
  def int_riscv_msetdspi   : MConfigIntrinsic;
  def int_riscv_msetdsp    : MConfigIntrinsic;
  def int_riscv_msetoutsh  : MConfigIntrinsicZmic;
  def int_riscv_msetinsh   : MConfigIntrinsicZmic;
  def int_riscv_msetsk     : MConfigIntrinsicZmic;
  def int_riscv_msetpadval : MConfigIntrinsic;

  // Load/Store Instructions
  def int_riscv_mla_m   : MLoadIntrinsic;
  def int_riscv_mlb_m   : MLoadIntrinsic;
  def int_riscv_mlc_m   : MLoadIntrinsic;
  def int_riscv_mltr_m  : MLoadIntrinsic;
  def int_riscv_mlat_m  : MLoadIntrinsic;
  def int_riscv_mlbt_m  : MLoadIntrinsic;
  def int_riscv_mlct_m  : MLoadIntrinsic;
  def int_riscv_mlacc_m : MLoadIntrinsic;
  def int_riscv_msa_m   : MStoreIntrinsic;
  def int_riscv_msb_m   : MStoreIntrinsic;
  def int_riscv_msc_m   : MStoreIntrinsic;
  def int_riscv_mstr_m  : MStoreIntrinsic;
  def int_riscv_msat_m  : MStoreIntrinsic;
  def int_riscv_msbt_m  : MStoreIntrinsic;
  def int_riscv_msct_m  : MStoreIntrinsic;
  def int_riscv_msacc_m : MStoreIntrinsic;
  def int_riscv_mla_v   : MLoadIntrinsic;
  def int_riscv_mlb_v   : MLoadIntrinsic;
  def int_riscv_mlc_v   : MLoadIntrinsic;
  def int_riscv_msa_v   : MStoreIntrinsic;
  def int_riscv_msb_v   : MStoreIntrinsic;
  def int_riscv_msc_v   : MStoreIntrinsic;
  def int_riscv_mlufa_m : MLoadIntrinsic;
  def int_riscv_mlufb_m : MLoadIntrinsic;
  def int_riscv_mlufc_m : MLoadIntrinsic;
  def int_riscv_msfda_m : MStoreIntrinsic;
  def int_riscv_msfdb_m : MStoreIntrinsic;
  def int_riscv_msfdc_m : MStoreIntrinsic;

  // Data Move Instructions
  def int_riscv_mmv_a_t : MBinaryMMIIntrinsic;
  def int_riscv_mmv_t_a : MBinaryMMIIntrinsic;

  def int_riscv_mmv_x_t  : MBinaryIMIIntrinsic;
  def int_riscv_mmv_t_x  : MMoveMMIIIntrinsic;
  def int_riscv_mmv_x_a  : MBinaryIMIIntrinsic;
  def int_riscv_mmv_a_x  : MMoveMMIIIntrinsic;
  def int_riscv_mfmv_f_t : MBinaryFMIIntrinsic;
  def int_riscv_mfmv_t_f : MBinaryMFIIntrinsic;
  def int_riscv_mfmv_f_a : MBinaryFMIIntrinsic;
  def int_riscv_mfmv_a_f : MBinaryMFIIntrinsic;

  def int_riscv_mbcar_m : MUnaryMMIntrinsic;
  def int_riscv_mbcbr_m : MUnaryMMIntrinsic;
  def int_riscv_mbccr_m : MUnaryMMIntrinsic;
  def int_riscv_mbcac_m : MUnaryMMIntrinsic;
  def int_riscv_mbcbc_m : MUnaryMMIntrinsic;
  def int_riscv_mbccc_m : MUnaryMMIntrinsic;
  def int_riscv_mbcae_m : MUnaryMMIntrinsic;
  def int_riscv_mbcbe_m : MUnaryMMIntrinsic;
  def int_riscv_mbcce_m : MUnaryMMIntrinsic;
  def int_riscv_mta_m   : MUnaryMMIntrinsic;
  def int_riscv_mtb_m   : MUnaryMMIntrinsic;
  def int_riscv_mtc_m   : MUnaryMMIntrinsic;

  // Zmv Extension Data Move Instructions
  def int_riscv_mmvar_v_m : MBinaryMMIIntrinsic;
  def int_riscv_mmvbr_v_m : MBinaryMMIIntrinsic;
  def int_riscv_mmvcr_v_m : MBinaryMMIIntrinsic;
  def int_riscv_mmvac_v_m : MBinaryMMIIntrinsic;
  def int_riscv_mmvbc_v_m : MBinaryMMIIntrinsic;
  def int_riscv_mmvcc_v_m : MBinaryMMIIntrinsic;

  def int_riscv_mmvar_m_v : MBinaryMMIIntrinsic;
  def int_riscv_mmvbr_m_v : MBinaryMMIIntrinsic;
  def int_riscv_mmvcr_m_v : MBinaryMMIIntrinsic;
  def int_riscv_mmvac_m_v : MBinaryMMIIntrinsic;
  def int_riscv_mmvbc_m_v : MBinaryMMIIntrinsic;
  def int_riscv_mmvcc_m_v : MBinaryMMIIntrinsic;

  // Matrix Multiplication Instructions
  def int_riscv_mmau_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_h_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_w_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_dw_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_h_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_w_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_dw_mm : MTernaryMMMMIntrinsic;
  def int_riscv_mma_mm      : MTernaryMMMMIntrinsic;
  def int_riscv_mma_h_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_mma_w_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_mma_dw_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_msma_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_msma_h_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_msma_w_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_msma_dw_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_hf_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_f_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_d_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mwmau_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mwmau_h_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mwmau_w_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_h_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_w_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_h_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_w_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_h_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_w_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_cf_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_hf_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_f_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mqmau_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mqmau_b_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_msqmau_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_msqmau_b_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mqma_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_mqma_b_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_msqma_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_msqma_b_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mfqma_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mfqma_cf_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_momau_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_momau_hb_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_msomau_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_msomau_hb_mm: MTernaryWMMMMIntrinsic;
  def int_riscv_moma_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_moma_hb_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_msoma_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_msoma_hb_mm : MTernaryWMMMMIntrinsic;

  // Sparsing Matrix Multiplication Instructions
  def int_riscv_mmau_spa_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_spb_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_spa_h_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_spb_h_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_spa_w_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_spb_w_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_spa_dw_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_mmau_spb_dw_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_spa_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_spb_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_spa_h_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_spb_h_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_spa_w_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_spb_w_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_spa_dw_mm : MTernaryMMMMIntrinsic;
  def int_riscv_msmau_spb_dw_mm : MTernaryMMMMIntrinsic;
  def int_riscv_mma_spa_mm      : MTernaryMMMMIntrinsic;
  def int_riscv_mma_spb_mm      : MTernaryMMMMIntrinsic;
  def int_riscv_mma_spa_h_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_mma_spb_h_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_mma_spa_w_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_mma_spb_w_mm    : MTernaryMMMMIntrinsic;
  def int_riscv_mma_spa_dw_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mma_spb_dw_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_msma_spa_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_msma_spb_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_msma_spa_h_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_msma_spb_h_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_msma_spa_w_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_msma_spb_w_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_msma_spa_dw_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_msma_spb_dw_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_spa_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_spb_mm     : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_spa_hf_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_spb_hf_mm  : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_spa_f_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_spb_f_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_spa_d_mm   : MTernaryMMMMIntrinsic;
  def int_riscv_mfma_spb_d_mm   : MTernaryMMMMIntrinsic;

  def int_riscv_mwmau_spa_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mwmau_spb_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mwmau_spa_h_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mwmau_spb_h_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mwmau_spa_w_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mwmau_spb_w_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_spa_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_spb_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_spa_h_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_spb_h_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_spa_w_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mswmau_spb_w_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_spa_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_spb_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_spa_h_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_spb_h_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_spa_w_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mwma_spb_w_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_spa_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_spb_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_spa_h_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_spb_h_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_spa_w_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mswma_spb_w_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_spa_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_spb_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_spa_hf_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_spb_hf_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_spa_f_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mfwma_spb_f_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mqmau_spa_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mqmau_spb_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mqmau_spa_b_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mqmau_spb_b_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_msqmau_spa_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_msqmau_spb_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_msqmau_spa_b_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_msqmau_spb_b_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mqma_spa_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_mqma_spb_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_mqma_spa_b_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_mqma_spb_b_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_msqma_spa_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_msqma_spb_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_msqma_spa_b_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_msqma_spb_b_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_mfqma_spa_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_mfqma_spb_mm    : MTernaryWMMMMIntrinsic;      
  def int_riscv_mfqma_spa_cf_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_mfqma_spb_cf_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_momau_spa_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_momau_spb_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_momau_spa_hb_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_momau_spb_hb_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_msomau_spa_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_msomau_spb_mm   : MTernaryWMMMMIntrinsic;
  def int_riscv_msomau_spa_hb_mm: MTernaryWMMMMIntrinsic;
  def int_riscv_msomau_spb_hb_mm: MTernaryWMMMMIntrinsic;
  def int_riscv_moma_spa_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_moma_spb_mm     : MTernaryWMMMMIntrinsic;
  def int_riscv_moma_spa_hb_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_moma_spb_hb_mm  : MTernaryWMMMMIntrinsic;
  def int_riscv_msoma_spa_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_msoma_spb_mm    : MTernaryWMMMMIntrinsic;
  def int_riscv_msoma_spa_hb_mm : MTernaryWMMMMIntrinsic;
  def int_riscv_msoma_spb_hb_mm : MTernaryWMMMMIntrinsic;

  // Element-wise Arithmetic & Logic Instructions
  def int_riscv_maddu_mm     : MBinaryMMMIntrinsic;
  def int_riscv_maddu_b_mm   : MBinaryMMMIntrinsic;
  def int_riscv_maddu_h_mm   : MBinaryMMMIntrinsic;
  def int_riscv_maddu_w_mm   : MBinaryMMMIntrinsic;
  def int_riscv_maddu_dw_mm  : MBinaryMMMIntrinsic;
  def int_riscv_maddu_hb_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msaddu_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msaddu_b_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msaddu_h_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msaddu_w_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msaddu_dw_mm : MBinaryMMMIntrinsic;
  def int_riscv_msaddu_hb_mm : MBinaryMMMIntrinsic;
  def int_riscv_madd_mm      : MBinaryMMMIntrinsic;
  def int_riscv_madd_b_mm    : MBinaryMMMIntrinsic;
  def int_riscv_madd_h_mm    : MBinaryMMMIntrinsic;
  def int_riscv_madd_w_mm    : MBinaryMMMIntrinsic;
  def int_riscv_madd_dw_mm   : MBinaryMMMIntrinsic;
  def int_riscv_madd_hb_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msadd_mm     : MBinaryMMMIntrinsic;
  def int_riscv_msadd_b_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msadd_h_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msadd_w_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msadd_dw_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msadd_hb_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfadd_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mfadd_cf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfadd_hf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfadd_f_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mfadd_d_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mwaddu_mm    : MBinaryWMMMIntrinsic;
  def int_riscv_mwaddu_b_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwaddu_h_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwaddu_w_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwaddu_hb_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mwadd_mm     : MBinaryWMMMIntrinsic;
  def int_riscv_mwadd_b_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwadd_h_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwadd_w_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwadd_hb_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mfwadd_mm    : MBinaryWMMMIntrinsic;
  def int_riscv_mfwadd_cf_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mfwadd_hf_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mfwadd_f_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_msubu_mm     : MBinaryMMMIntrinsic;
  def int_riscv_msubu_b_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msubu_h_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msubu_w_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msubu_dw_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msubu_hb_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mssubu_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mssubu_b_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mssubu_h_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mssubu_w_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mssubu_dw_mm : MBinaryMMMIntrinsic;
  def int_riscv_mssubu_hb_mm : MBinaryMMMIntrinsic;
  def int_riscv_msub_mm      : MBinaryMMMIntrinsic;
  def int_riscv_msub_b_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msub_h_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msub_w_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msub_dw_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msub_hb_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mssub_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mssub_b_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mssub_h_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mssub_w_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mssub_dw_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mssub_hb_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfsub_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mfsub_cf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfsub_hf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfsub_f_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mfsub_d_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mwsubu_mm    : MBinaryWMMMIntrinsic;
  def int_riscv_mwsubu_b_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwsubu_h_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwsubu_w_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwsubu_hb_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mwsub_mm     : MBinaryWMMMIntrinsic;
  def int_riscv_mwsub_b_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwsub_h_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwsub_w_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwsub_hb_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mfwsub_mm    : MBinaryWMMMIntrinsic;
  def int_riscv_mfwsub_cf_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mfwsub_hf_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mfwsub_f_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mminu_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mminu_b_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mminu_h_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mminu_w_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mminu_dw_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mminu_hb_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mmaxu_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mmaxu_b_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmaxu_h_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmaxu_w_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmaxu_dw_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mmaxu_hb_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mmin_mm      : MBinaryMMMIntrinsic;
  def int_riscv_mmin_b_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmin_h_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmin_w_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmin_dw_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmin_hb_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmax_mm      : MBinaryMMMIntrinsic;
  def int_riscv_mmax_b_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmax_h_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmax_w_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmax_dw_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmax_hb_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mfmin_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mfmin_cf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfmin_hf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfmin_f_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mfmin_d_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mfmax_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mfmax_cf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfmax_hf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfmax_f_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mfmax_d_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msmulu_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msmulu_b_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msmulu_h_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msmulu_w_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msmulu_dw_mm : MBinaryMMMIntrinsic;
  def int_riscv_msmulu_hb_mm : MBinaryMMMIntrinsic;
  def int_riscv_mmul_mm      : MBinaryMMMIntrinsic;
  def int_riscv_mmul_b_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmul_h_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmul_w_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmul_dw_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmul_hb_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msmul_mm     : MBinaryMMMIntrinsic;
  def int_riscv_msmul_b_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msmul_h_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msmul_w_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msmul_dw_mm  : MBinaryMMMIntrinsic;
  def int_riscv_msmul_hb_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfmul_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mfmul_cf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfmul_hf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfmul_f_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mfmul_d_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmulhu_mm    : MBinaryMMMIntrinsic;
  def int_riscv_mmulhu_b_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mmulhu_h_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mmulhu_w_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mmulhu_dw_mm : MBinaryMMMIntrinsic;
  def int_riscv_mmulhu_hb_mm : MBinaryMMMIntrinsic;
  def int_riscv_mmulh_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mmulh_b_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmulh_h_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmulh_w_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmulh_dw_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mmulh_hb_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mmulhsu_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mmulhsu_b_mm : MBinaryMMMIntrinsic;
  def int_riscv_mmulhsu_h_mm : MBinaryMMMIntrinsic;
  def int_riscv_mmulhsu_w_mm : MBinaryMMMIntrinsic;
  def int_riscv_mmulhsu_dw_mm: MBinaryMMMIntrinsic;
  def int_riscv_mmulhsu_hb_mm: MBinaryMMMIntrinsic;
  def int_riscv_msmulsu_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msmulsu_b_mm : MBinaryMMMIntrinsic;
  def int_riscv_msmulsu_h_mm : MBinaryMMMIntrinsic;
  def int_riscv_msmulsu_w_mm : MBinaryMMMIntrinsic;
  def int_riscv_msmulsu_dw_mm: MBinaryMMMIntrinsic;
  def int_riscv_msmulsu_hb_mm: MBinaryMMMIntrinsic;
  def int_riscv_mfdiv_mm     : MBinaryMMMIntrinsic;
  def int_riscv_mfdiv_cf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfdiv_hf_mm  : MBinaryMMMIntrinsic;
  def int_riscv_mfdiv_f_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mfdiv_d_mm   : MBinaryMMMIntrinsic;
  def int_riscv_mwmulu_mm    : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulu_b_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulu_h_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulu_w_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulu_hb_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mwmul_mm     : MBinaryWMMMIntrinsic;
  def int_riscv_mwmul_b_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwmul_h_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwmul_w_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwmul_hb_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulsu_mm   : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulsu_b_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulsu_h_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulsu_w_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mwmulsu_hb_mm: MBinaryWMMMIntrinsic;
  def int_riscv_mfwmul_mm    : MBinaryWMMMIntrinsic;
  def int_riscv_mfwmul_cf_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mfwmul_hf_mm : MBinaryWMMMIntrinsic;
  def int_riscv_mfwmul_f_mm  : MBinaryWMMMIntrinsic;
  def int_riscv_mand_mm      : MBinaryMMMIntrinsic;
  def int_riscv_mor_mm       : MBinaryMMMIntrinsic;
  def int_riscv_mxor_mm      : MBinaryMMMIntrinsic;
  def int_riscv_mfsqrt_m     : MUnaryMMIntrinsic;
  def int_riscv_mfsqrt_cf_m  : MUnaryMMIntrinsic;
  def int_riscv_mfsqrt_hf_m  : MUnaryMMIntrinsic;
  def int_riscv_mfsqrt_f_m   : MUnaryMMIntrinsic;
  def int_riscv_mfsqrt_d_m   : MUnaryMMIntrinsic;
  def int_riscv_msll_mm      : MBinaryMMMIntrinsic;
  def int_riscv_msll_b_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msll_h_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msll_w_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msll_dw_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msll_hb_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msrl_mm      : MBinaryMMMIntrinsic;
  def int_riscv_msrl_b_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msrl_h_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msrl_w_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msrl_dw_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msrl_hb_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msra_mm      : MBinaryMMMIntrinsic;
  def int_riscv_msra_b_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msra_h_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msra_w_mm    : MBinaryMMMIntrinsic;
  def int_riscv_msra_dw_mm   : MBinaryMMMIntrinsic;
  def int_riscv_msra_hb_mm   : MBinaryMMMIntrinsic;

  // Type Convert Instructions
  def int_riscv_mcvt_x_xu_m    : MCVTIntrinsic;
  def int_riscv_mcvt_hb_uhb_m  : MCVTIntrinsic;
  def int_riscv_mcvt_b_ub_m    : MCVTIntrinsic;
  def int_riscv_mcvt_h_uh_m    : MCVTIntrinsic;
  def int_riscv_mcvt_w_uw_m    : MCVTIntrinsic;
  def int_riscv_mcvt_dw_udw_m  : MCVTIntrinsic;
  def int_riscv_mcvt_xu_x_m    : MCVTIntrinsic;
  def int_riscv_mcvt_uhb_hb_m  : MCVTIntrinsic;
  def int_riscv_mcvt_ub_b_m    : MCVTIntrinsic;
  def int_riscv_mcvt_uh_h_m    : MCVTIntrinsic;
  def int_riscv_mcvt_uw_w_m    : MCVTIntrinsic;
  def int_riscv_mcvt_udw_dw_m  : MCVTIntrinsic;
  def int_riscv_mwcvtu_xw_x_m  : MCVTIntrinsic;
  def int_riscv_mwcvtu_xq_x_m  : MCVTIntrinsic;
  def int_riscv_mwcvtu_xo_x_m  : MCVTIntrinsic;
  def int_riscv_mwcvtu_b_hb_m  : MCVTIntrinsic;
  def int_riscv_mwcvtu_h_hb_m  : MCVTIntrinsic;
  def int_riscv_mwcvtu_w_hb_m  : MCVTIntrinsic;
  def int_riscv_mwcvtu_h_b_m   : MCVTIntrinsic;
  def int_riscv_mwcvtu_w_b_m   : MCVTIntrinsic;
  def int_riscv_mwcvtu_w_h_m   : MCVTIntrinsic;
  def int_riscv_mwcvtu_dw_w_m  : MCVTIntrinsic;
  def int_riscv_mwcvt_xw_x_m   : MCVTIntrinsic;
  def int_riscv_mwcvt_xq_x_m   : MCVTIntrinsic;
  def int_riscv_mwcvt_xo_x_m   : MCVTIntrinsic;
  def int_riscv_mwcvt_b_hb_m   : MCVTIntrinsic;
  def int_riscv_mwcvt_h_hb_m   : MCVTIntrinsic;
  def int_riscv_mwcvt_w_hb_m   : MCVTIntrinsic;
  def int_riscv_mwcvt_h_b_m    : MCVTIntrinsic;
  def int_riscv_mwcvt_w_b_m    : MCVTIntrinsic;
  def int_riscv_mwcvt_w_h_m    : MCVTIntrinsic;
  def int_riscv_mwcvt_dw_w_m   : MCVTIntrinsic;
  def int_riscv_mncvtu_x_xw_m  : MCVTIntrinsic;
  def int_riscv_mncvtu_x_xq_m  : MCVTIntrinsic;
  def int_riscv_mncvtu_x_xo_m  : MCVTIntrinsic;
  def int_riscv_mncvtu_hb_b_m  : MCVTIntrinsic;
  def int_riscv_mncvtu_hb_h_m  : MCVTIntrinsic;
  def int_riscv_mncvtu_hb_w_m  : MCVTIntrinsic;
  def int_riscv_mncvtu_b_h_m   : MCVTIntrinsic;
  def int_riscv_mncvtu_b_w_m   : MCVTIntrinsic;
  def int_riscv_mncvtu_h_w_m   : MCVTIntrinsic;
  def int_riscv_mncvtu_w_dw_m  : MCVTIntrinsic;
  def int_riscv_mncvt_x_xw_m   : MCVTIntrinsic;
  def int_riscv_mncvt_x_xq_m   : MCVTIntrinsic;
  def int_riscv_mncvt_x_xo_m   : MCVTIntrinsic;
  def int_riscv_mncvt_hb_b_m   : MCVTIntrinsic;
  def int_riscv_mncvt_hb_h_m   : MCVTIntrinsic;
  def int_riscv_mncvt_hb_w_m   : MCVTIntrinsic;
  def int_riscv_mncvt_b_h_m    : MCVTIntrinsic;
  def int_riscv_mncvt_b_w_m    : MCVTIntrinsic;
  def int_riscv_mncvt_h_w_m    : MCVTIntrinsic;
  def int_riscv_mncvt_w_dw_m   : MCVTIntrinsic;
  def int_riscv_mfcvt_bf_hf_m  : MCVTIntrinsic;
  def int_riscv_mfcvt_hf_bf_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_fw_f_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_hf_cf_m : MCVTIntrinsic;
  def int_riscv_mfwcvt_f_hf_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_d_f_m   : MCVTIntrinsic;
  def int_riscv_mfncvt_f_fw_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_cf_hf_m : MCVTIntrinsic;
  def int_riscv_mfncvt_hf_f_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_f_d_m   : MCVTIntrinsic;
  def int_riscv_mfcvtu_f_x_m   : MCVTIntrinsic;
  def int_riscv_mfcvtu_hf_h_m  : MCVTIntrinsic;
  def int_riscv_mfcvtu_f_w_m   : MCVTIntrinsic;
  def int_riscv_mfcvtu_d_dw_m  : MCVTIntrinsic;
  def int_riscv_mfcvt_f_x_m    : MCVTIntrinsic;
  def int_riscv_mfcvt_hf_h_m   : MCVTIntrinsic;
  def int_riscv_mfcvt_f_w_m    : MCVTIntrinsic;
  def int_riscv_mfcvt_d_dw_m   : MCVTIntrinsic;
  def int_riscv_mfwcvtu_fw_x_m : MCVTIntrinsic;
  def int_riscv_mfwcvtu_hf_b_m : MCVTIntrinsic;
  def int_riscv_mfwcvtu_f_h_m  : MCVTIntrinsic;
  def int_riscv_mfwcvtu_d_w_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_fw_x_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_hf_b_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_f_h_m   : MCVTIntrinsic;
  def int_riscv_mfwcvt_d_w_m   : MCVTIntrinsic;
  def int_riscv_mfncvtu_f_xw_m : MCVTIntrinsic;
  def int_riscv_mfncvtu_hf_w_m : MCVTIntrinsic;
  def int_riscv_mfncvtu_f_dw_m : MCVTIntrinsic;
  def int_riscv_mfncvt_f_xw_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_hf_w_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_f_dw_m  : MCVTIntrinsic;
  def int_riscv_mfcvtu_x_f_m   : MCVTIntrinsic;
  def int_riscv_mfcvtu_h_hf_m  : MCVTIntrinsic;
  def int_riscv_mfcvtu_w_f_m   : MCVTIntrinsic;
  def int_riscv_mfcvtu_dw_d_m  : MCVTIntrinsic;
  def int_riscv_mfcvt_x_f_m    : MCVTIntrinsic;
  def int_riscv_mfcvt_h_hf_m   : MCVTIntrinsic;
  def int_riscv_mfcvt_w_f_m    : MCVTIntrinsic;
  def int_riscv_mfcvt_dw_d_m   : MCVTIntrinsic;
  def int_riscv_mfwcvtu_xw_f_m : MCVTIntrinsic;
  def int_riscv_mfwcvtu_w_hf_m : MCVTIntrinsic;
  def int_riscv_mfwcvtu_dw_f_m : MCVTIntrinsic;
  def int_riscv_mfwcvt_xw_f_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_w_hf_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_dw_f_m  : MCVTIntrinsic;
  def int_riscv_mfncvtu_x_fw_m : MCVTIntrinsic;
  def int_riscv_mfncvtu_b_hf_m : MCVTIntrinsic;
  def int_riscv_mfncvtu_h_f_m  : MCVTIntrinsic;
  def int_riscv_mfncvtu_w_d_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_x_fw_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_b_hf_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_h_f_m   : MCVTIntrinsic;
  def int_riscv_mfncvt_w_d_m   : MCVTIntrinsic;
  def int_riscv_mfwcvtu_fq_x_m : MCVTIntrinsic;
  def int_riscv_mfwcvtu_hf_hb_m: MCVTIntrinsic;
  def int_riscv_mfwcvtu_f_b_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_fq_x_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_hf_hb_m : MCVTIntrinsic;
  def int_riscv_mfwcvt_f_b_m   : MCVTIntrinsic;
  def int_riscv_mfwcvtu_fo_x_m : MCVTIntrinsic;
  def int_riscv_mfwcvtu_f_hb_m : MCVTIntrinsic;
  def int_riscv_mfwcvt_fo_x_m  : MCVTIntrinsic;
  def int_riscv_mfwcvt_f_hb_m  : MCVTIntrinsic;
  def int_riscv_mfncvtu_x_fq_m : MCVTIntrinsic;
  def int_riscv_mfncvtu_hb_hf_m: MCVTIntrinsic;
  def int_riscv_mfncvtu_b_f_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_x_fq_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_hb_hf_m : MCVTIntrinsic;
  def int_riscv_mfncvt_b_f_m   : MCVTIntrinsic;
  def int_riscv_mfncvtu_x_fo_m : MCVTIntrinsic;
  def int_riscv_mfncvtu_hb_f_m : MCVTIntrinsic;
  def int_riscv_mfncvt_x_fo_m  : MCVTIntrinsic;
  def int_riscv_mfncvt_hb_f_m  : MCVTIntrinsic;
} // TargetPrefix = "riscv"