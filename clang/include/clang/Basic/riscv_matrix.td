//==--- riscv_matrix.td - RISC-V Matrix-ext Builtin function list --------------===//

// This is simply from RVVBuiltin in riscv_vector.td

// TypeRange is a non-empty sequence of basic types:
//
//   c: int8_t (i8)
//   s: int16_t (i16)
//   i: int32_t (i32)
//   l: int64_t (i64)
//   x: float16_t (half)
//   f: float32_t (float)
//   d: float64_t (double)
//
// This way, given an LMUL, a record with a TypeRange "sil" will cause the
// definition of 3 builtins. Each type "t" in the TypeRange (in this example
// they are int16_t, int32_t, int64_t) is used as a parameter that drives the
// definition of that particular builtin (for the given LMUL).
//
// During the instantiation, types can be transformed or modified using type
// transformers. Given a type "t" the following primitive type transformers can
// be applied to it to yield another type.
//
//   e: type of "t" as is (identity)
//   a: v in zmv
//   v: computes a vector type whose element type is "t" for the current LMUL
//   w: computes a vector type identical to what 'v' computes except for the
//      element type which is twice as wide as the element type of 'v'
//   q: computes a vector type identical to what 'v' computes except for the
//      element type which is four times as wide as the element type of 'v'
//   o: computes a vector type identical to what 'v' computes except for the
//      element type which is eight times as wide as the element type of 'v'
//   m: computes a vector type identical to what 'v' computes except for the
//      element type which is bool
//   0: void type, ignores "t"
//   z: size_t, ignores "t"
//   t: ptrdiff_t, ignores "t"
//   u: unsigned long, ignores "t"
//   l: long, ignores "t"
//
// So for instance if t is "i", i.e. int, then "e" will yield int again. "v"
// will yield an RVV vector type (assume LMUL=1), so __rvv_int32m1_t.
// Accordingly "w" would yield __rvv_int64m2_t.

class RISCVMatrixBuiltin<string suffix, string prototype, string type_range> {
  // Base name that will be prepended in __builtin_riscv_ and appended the
  // computed Suffix.
  string Name = NAME;

  // If not empty, each instantiated builtin will have this appended after an
  // underscore (_). It is instantiated like Prototype.
  string Suffix = suffix;

  // The different variants of the builtin, parameterised with a type.
  string TypeRange = type_range;

  // We use each type described in TypeRange and LMUL with prototype to
  // instantiate a specific element of the set of builtins being defined.
  string Prototype = prototype;

  // Reads or writes "memory" or has other side-effects.
  bit HasSideEffects = false;

  // intrinsic with lmul parameter
  bit HasLMUL = false;

  // Load Inst
  bit IsLoad = false;

  // This builtin is valid for the given LMULs.
  // m1, m2, m4
  list<int> LMUL = [1];

  // Manual code in clang codegen riscv_matrix_builtin_cg.inc
  code ManualCodegen = [{}];

  // When emit the automatic clang codegen, it describes what types we have to use
  // to obtain the specific LLVM intrinsic. -1 means the return type, otherwise,
  // k >= 0 meaning the k-th operand (counting from zero) of the codegen'd
  // parameter of the unmasked version. k can't be the mask operand's position.
  list<int> IntrinsicTypes = [];

  // If these names are not empty, this is the ID of the LLVM intrinsic
  // we want to lower to.
  string IRName = NAME;

  // If non empty, this is the code emitted in the header, otherwise
  // an automatic definition in header is emitted.
  string HeaderCode = "";
}

class RVMatrixBin<string suffix, string prototype, string type_range>
    : RISCVMatrixBuiltin<suffix, prototype, type_range> {
  let IntrinsicTypes = [-1];
}

class RVMatrixWidenBin<string suffix, string prototype, string type_range>
    : RISCVMatrixBuiltin<suffix, prototype, type_range> {
  let IntrinsicTypes = [-1, 1];
}

class IsFloat<string type> {
  bit val = !or(!eq(type, "x"), !eq(type, "f"), !eq(type, "d"));
}

defvar TypeList = ["c","s","i","l","x","f","d"];
multiclass RVMatrixMLoadBuiltin {
  let Name = NAME,
      IRName = NAME,
      IsLoad = true,
      ManualCodegen = [{
      IntrinsicTypes = {ResultType, Ops[1]->getType()};
      Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
      }] in {
    foreach type = TypeList in {
      def : RISCVMatrixBuiltin<"v", "vPCez", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UvPCUez", type>;
      }
    }
  }
}

multiclass RVMatrixMStoreBuiltin {
  let Name = NAME,
      IRName = NAME,
      ManualCodegen = [{
     Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
     IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType()};
      }] in {
    foreach type = TypeList in {
      def : RISCVMatrixBuiltin<"v", "0vPCez", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "0UvPCUez", type>;
      }
    }
  }
}

multiclass RVMatrixBCBuitin {
  let Name = NAME,
      IRName = NAME,
      IntrinsicTypes = [-1] in {
    foreach type = TypeList in {
      def : RISCVMatrixBuiltin<"v", "vv", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UvUv", type>;
      }
    }
  }
}

multiclass RVMatrixBitWiseBuitin<list<string> types> {
  let Name = NAME,
      IRName = NAME,
      IntrinsicTypes = [-1] in {
    foreach type = types in {
      def : RISCVMatrixBuiltin<"v", "vvv", type>;
      def : RISCVMatrixBuiltin<"Uv", "UvUvUv", type>;
    }
  }
}

multiclass RVMatrixBuitinSet<string type_range, list<int> intrinsic_types,
                             list<list<string>> suffixes_prototypes> {
  let Name = NAME,
      IRName = NAME,
      IntrinsicTypes = intrinsic_types in {
    foreach s_p = suffixes_prototypes in {
      defvar suffix = s_p[0];
      defvar prototype = s_p[1];
      def : RISCVMatrixBuiltin<suffix, prototype, type_range>;
    }
  }
}

let IntrinsicTypes = [-1], HasSideEffects = true in {
  def msettype   : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettypei  : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettypehi : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettilem  : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettilemi : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettilen  : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettileni : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettilek  : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettileki : RISCVMatrixBuiltin<"", "zz", "i">;

  def msettspi   : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettsp    : RISCVMatrixBuiltin<"", "zz", "i">;
  def msetdspi   : RISCVMatrixBuiltin<"", "zz", "i">;
  def msetdsp    : RISCVMatrixBuiltin<"", "zz", "i">;

  def msetoutsh  : RISCVMatrixBuiltin<"", "zzz", "i">;
  def msetinsh   : RISCVMatrixBuiltin<"", "zzz", "i">;
  def msetsk     : RISCVMatrixBuiltin<"", "zzz", "i">;
  def msetpadval : RISCVMatrixBuiltin<"", "zz", "i">;
}


// 4.3. Load and Store Instructions
// 4.3.1. Load Instructions
defm mla_m   : RVMatrixMLoadBuiltin;
defm mlb_m   : RVMatrixMLoadBuiltin;
defm mlc_m   : RVMatrixMLoadBuiltin;
defm mlat_m  : RVMatrixMLoadBuiltin;
defm mlbt_m  : RVMatrixMLoadBuiltin;
defm mlct_m  : RVMatrixMLoadBuiltin;
defm mltr_m  : RVMatrixMLoadBuiltin;
defm mlacc_m : RVMatrixMLoadBuiltin;

defm mlufa_m : RVMatrixMLoadBuiltin;
defm mlufb_m : RVMatrixMLoadBuiltin;
defm mlufc_m : RVMatrixMLoadBuiltin;

// 4.3.2. Store Instructions
defm msa_m   : RVMatrixMStoreBuiltin;
defm msb_m   : RVMatrixMStoreBuiltin;
defm msc_m   : RVMatrixMStoreBuiltin;
defm msat_m  : RVMatrixMStoreBuiltin;
defm msbt_m  : RVMatrixMStoreBuiltin;
defm msct_m  : RVMatrixMStoreBuiltin;
defm mstr_m  : RVMatrixMStoreBuiltin;
defm msacc_m : RVMatrixMStoreBuiltin;

defm msfda_m : RVMatrixMStoreBuiltin;
defm msfdb_m : RVMatrixMStoreBuiltin;
defm msfdc_m : RVMatrixMStoreBuiltin;

// 4.4. Data Move Instructions
multiclass RVMatrixMMVBuitin {
  let Name = NAME,
      IRName = NAME,
      IntrinsicTypes = [-1, 0, 1] in {
    foreach type = TypeList in {
      def : RISCVMatrixBuiltin<"v", "vvz", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UvUvz", type>;
      }
    }
  }
}

defm mmv_a_t : RVMatrixMMVBuitin;
defm mmv_t_a : RVMatrixMMVBuitin;

defm mmv_x_a : RVMatrixBuitinSet<"csil", [-1, 0, 1],
                                 [["v","evz"], ["Uv","UeUvz"]]>;
defm mmv_a_x : RVMatrixBuitinSet<"csil", [-1, 1, 2],
                                 [["v","vvez"], ["Uv","UvUvUez"]]>;
defm mfmv_f_a : RVMatrixBuitinSet<"xfd", [-1, 0, 1],
                                 [["v","evz"]]>;
defm mfmv_a_f : RVMatrixBuitinSet<"xfd", [-1, 1, 2],
                                 [["v","vvez"]]>;

defm mmv_x_t : RVMatrixBuitinSet<"csil", [-1, 0, 1],
                                 [["v","evz"], ["Uv","UeUvz"]]>;
defm mmv_t_x : RVMatrixBuitinSet<"csil", [-1, 1, 2],
                                 [["v","vvez"], ["Uv","UvUvUez"]]>;
defm mfmv_f_t : RVMatrixBuitinSet<"xfd", [-1, 0, 1],
                                 [["v","evz"]]>;
defm mfmv_t_f : RVMatrixBuitinSet<"xfd", [-1, 1, 2],
                                 [["v","vvez"]]>;

defm mbcar_m : RVMatrixBCBuitin;
defm mbcbr_m : RVMatrixBCBuitin;
defm mbccr_m : RVMatrixBCBuitin;
defm mbcac_m : RVMatrixBCBuitin;
defm mbcbc_m : RVMatrixBCBuitin;
defm mbccc_m : RVMatrixBCBuitin;
defm mbcae_m : RVMatrixBCBuitin;
defm mbcbe_m : RVMatrixBCBuitin;
defm mbcce_m : RVMatrixBCBuitin;

defm mta_m : RVMatrixBCBuitin;
defm mtb_m : RVMatrixBCBuitin;
defm mtc_m : RVMatrixBCBuitin;

// 4.5.1. Matrix Multiplication Instructions
def mmau_mm     : RVMatrixBin<"Uv", "UvUvUvUv", "sil">;
def mmau_h_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "s">;
def mmau_w_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "i">;
def mmau_dw_mm  : RVMatrixBin<"Uv", "UvUvUvUv", "l">;
def mwmau_mm    : RVMatrixWidenBin<"Uw", "UwUwUvUv", "si">;
def mwmau_h_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "s">;
def mwmau_w_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "i">;
def mqmau_mm    : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def mqmau_b_mm  : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def msmau_mm    : RVMatrixBin<"Uv", "UvUvUvUv", "sil">;
def msmau_h_mm  : RVMatrixBin<"Uv", "UvUvUvUv", "s">;
def msmau_w_mm  : RVMatrixBin<"Uv", "UvUvUvUv", "i">;
def msmau_dw_mm : RVMatrixBin<"Uv", "UvUvUvUv", "l">;
def mswmau_mm   : RVMatrixWidenBin<"Uw", "UwUwUvUv", "si">;
def mswmau_h_mm : RVMatrixWidenBin<"Uw", "UwUwUvUv", "s">;
def mswmau_w_mm : RVMatrixWidenBin<"Uw", "UwUwUvUv", "i">;
def msqmau_mm   : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def msqmau_b_mm : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def mma_mm      : RVMatrixBin<"v", "vvvv", "sil">;
def mma_h_mm    : RVMatrixBin<"v", "vvvv", "s">;
def mma_w_mm    : RVMatrixBin<"v", "vvvv", "i">;
def mma_dw_mm   : RVMatrixBin<"v", "vvvv", "l">;
def mwma_mm     : RVMatrixWidenBin<"w", "wwvv", "si">;
def mwma_h_mm   : RVMatrixWidenBin<"w", "wwvv", "s">;
def mwma_w_mm   : RVMatrixWidenBin<"w", "wwvv", "i">;
def mqma_mm     : RVMatrixWidenBin<"q", "qqvv", "c">;
def mqma_b_mm   : RVMatrixWidenBin<"q", "qqvv", "c">;
def msma_mm     : RVMatrixBin<"v", "vvvv", "sil">;
def msma_h_mm   : RVMatrixBin<"v", "vvvv", "s">;
def msma_w_mm   : RVMatrixBin<"v", "vvvv", "i">;
def msma_dw_mm  : RVMatrixBin<"v", "vvvv", "l">;
def mswma_mm    : RVMatrixWidenBin<"w", "wwvv", "si">;
def mswma_h_mm  : RVMatrixWidenBin<"w", "wwvv", "s">;
def mswma_w_mm  : RVMatrixWidenBin<"w", "wwvv", "i">;
def msqma_mm    : RVMatrixWidenBin<"q", "qqvv", "c">;
def msqma_b_mm  : RVMatrixWidenBin<"q", "qqvv", "c">;

def mfma_mm     : RVMatrixBin<"v", "vvvv", "xfd">;
def mfma_hf_mm  : RVMatrixBin<"v", "vvvv", "x">;
def mfma_f_mm   : RVMatrixBin<"v", "vvvv", "f">;
def mfma_d_mm   : RVMatrixBin<"v", "vvvv", "d">;
def mfwma_mm    : RVMatrixWidenBin<"w", "wwvv", "xf">;
def mfwma_hf_mm : RVMatrixWidenBin<"w", "wwvv", "x">;
def mfwma_f_mm  : RVMatrixWidenBin<"w", "wwvv", "f">;

// Matrix Sparsity Extension
def mmau_spa_mm     : RVMatrixBin<"Uv", "UvUvUvUv", "sil">;
def mmau_spa_h_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "s">;
def mmau_spa_w_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "i">;
def mmau_spa_dw_mm  : RVMatrixBin<"Uv", "UvUvUvUv", "l">;
def mwmau_spa_mm    : RVMatrixWidenBin<"Uw", "UwUwUvUv", "si">;
def mwmau_spa_h_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "s">;
def mwmau_spa_w_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "i">;
def mqmau_spa_mm    : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def mqmau_spa_b_mm  : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def msmau_spa_mm     : RVMatrixBin<"Uv", "UvUvUvUv", "sil">;
def msmau_spa_h_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "s">;
def msmau_spa_w_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "i">;
def msmau_spa_dw_mm  : RVMatrixBin<"Uv", "UvUvUvUv", "l">;
def mswmau_spa_mm    : RVMatrixWidenBin<"Uw", "UwUwUvUv", "si">;
def mswmau_spa_h_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "s">;
def mswmau_spa_w_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "i">;
def msqmau_spa_mm    : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def msqmau_spa_b_mm  : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;

def mma_spa_mm     : RVMatrixBin<"v", "vvvv", "sil">;
def mma_spa_h_mm   : RVMatrixBin<"v", "vvvv", "s">;
def mma_spa_w_mm   : RVMatrixBin<"v", "vvvv", "i">;
def mma_spa_dw_mm  : RVMatrixBin<"v", "vvvv", "l">;
def mwma_spa_mm    : RVMatrixWidenBin<"w", "wwvv", "si">;
def mwma_spa_h_mm  : RVMatrixWidenBin<"w", "wwvv", "s">;
def mwma_spa_w_mm  : RVMatrixWidenBin<"w", "wwvv", "i">;
def mqma_spa_mm    : RVMatrixWidenBin<"q", "qqvv", "c">;
def mqma_spa_b_mm  : RVMatrixWidenBin<"q", "qqvv", "c">;
def msma_spa_mm     : RVMatrixBin<"v", "vvvv", "sil">;
def msma_spa_h_mm   : RVMatrixBin<"v", "vvvv", "s">;
def msma_spa_w_mm   : RVMatrixBin<"v", "vvvv", "i">;
def msma_spa_dw_mm  : RVMatrixBin<"v", "vvvv", "l">;
def mswma_spa_mm    : RVMatrixWidenBin<"w", "wwvv", "si">;
def mswma_spa_h_mm  : RVMatrixWidenBin<"w", "wwvv", "s">;
def mswma_spa_w_mm  : RVMatrixWidenBin<"w", "wwvv", "i">;
def msqma_spa_mm    : RVMatrixWidenBin<"q", "qqvv", "c">;
def msqma_spa_b_mm  : RVMatrixWidenBin<"q", "qqvv", "c">;

def mfma_spa_mm     : RVMatrixBin<"v", "vvvv", "xfd">;
def mfma_spa_hf_mm  : RVMatrixBin<"v", "vvvv", "x">;
def mfma_spa_f_mm   : RVMatrixBin<"v", "vvvv", "f">;
def mfma_spa_d_mm   : RVMatrixBin<"v", "vvvv", "d">;
def mfwma_spa_mm    : RVMatrixWidenBin<"w", "wwvv", "xf">;
def mfwma_spa_hf_mm : RVMatrixWidenBin<"w", "wwvv", "x">;
def mfwma_spa_f_mm  : RVMatrixWidenBin<"w", "wwvv", "f">;

def mmau_spb_mm     : RVMatrixBin<"Uv", "UvUvUvUv", "sil">;
def mmau_spb_h_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "s">;
def mmau_spb_w_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "i">;
def mmau_spb_dw_mm  : RVMatrixBin<"Uv", "UvUvUvUv", "l">;
def mwmau_spb_mm    : RVMatrixWidenBin<"Uw", "UwUwUvUv", "si">;
def mwmau_spb_h_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "s">;
def mwmau_spb_w_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "i">;
def mqmau_spb_mm    : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def mqmau_spb_b_mm  : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def msmau_spb_mm     : RVMatrixBin<"Uv", "UvUvUvUv", "sil">;
def msmau_spb_h_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "s">;
def msmau_spb_w_mm   : RVMatrixBin<"Uv", "UvUvUvUv", "i">;
def msmau_spb_dw_mm  : RVMatrixBin<"Uv", "UvUvUvUv", "l">;
def mswmau_spb_mm    : RVMatrixWidenBin<"Uw", "UwUwUvUv", "si">;
def mswmau_spb_h_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "s">;
def mswmau_spb_w_mm  : RVMatrixWidenBin<"Uw", "UwUwUvUv", "i">;
def msqmau_spb_mm    : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;
def msqmau_spb_b_mm  : RVMatrixWidenBin<"Uq", "UqUqUvUv", "c">;

def mma_spb_mm     : RVMatrixBin<"v", "vvvv", "sil">;
def mma_spb_h_mm   : RVMatrixBin<"v", "vvvv", "s">;
def mma_spb_w_mm   : RVMatrixBin<"v", "vvvv", "i">;
def mma_spb_dw_mm  : RVMatrixBin<"v", "vvvv", "l">;
def mwma_spb_mm    : RVMatrixWidenBin<"w", "wwvv", "si">;
def mwma_spb_h_mm  : RVMatrixWidenBin<"w", "wwvv", "s">;
def mwma_spb_w_mm  : RVMatrixWidenBin<"w", "wwvv", "i">;
def mqma_spb_mm    : RVMatrixWidenBin<"q", "qqvv", "c">;
def mqma_spb_b_mm  : RVMatrixWidenBin<"q", "qqvv", "c">;
def msma_spb_mm     : RVMatrixBin<"v", "vvvv", "sil">;
def msma_spb_h_mm   : RVMatrixBin<"v", "vvvv", "s">;
def msma_spb_w_mm   : RVMatrixBin<"v", "vvvv", "i">;
def msma_spb_dw_mm  : RVMatrixBin<"v", "vvvv", "l">;
def mswma_spb_mm    : RVMatrixWidenBin<"w", "wwvv", "si">;
def mswma_spb_h_mm  : RVMatrixWidenBin<"w", "wwvv", "s">;
def mswma_spb_w_mm  : RVMatrixWidenBin<"w", "wwvv", "i">;
def msqma_spb_mm    : RVMatrixWidenBin<"q", "qqvv", "c">;
def msqma_spb_b_mm  : RVMatrixWidenBin<"q", "qqvv", "c">;

def mfma_spb_mm     : RVMatrixBin<"v", "vvvv", "xfd">;
def mfma_spb_hf_mm  : RVMatrixBin<"v", "vvvv", "x">;
def mfma_spb_f_mm   : RVMatrixBin<"v", "vvvv", "f">;
def mfma_spb_d_mm   : RVMatrixBin<"v", "vvvv", "d">;
def mfwma_spb_mm    : RVMatrixWidenBin<"w", "wwvv", "xf">;
def mfwma_spb_hf_mm : RVMatrixWidenBin<"w", "wwvv", "x">;
def mfwma_spb_f_mm  : RVMatrixWidenBin<"w", "wwvv", "f">;

// 4.5.2 Element-Wise Add/Sub/Multiply Instructions
def maddu_mm    : RVMatrixBin<"Uv", "UvUvUv", "csil">;
def maddu_b_mm  : RVMatrixBin<"Uv", "UvUvUv", "c">;
def maddu_h_mm  : RVMatrixBin<"Uv", "UvUvUv", "s">;
def maddu_w_mm  : RVMatrixBin<"Uv", "UvUvUv", "i">;
def maddu_dw_mm : RVMatrixBin<"Uv", "UvUvUv", "l">;
def msaddu_mm    : RVMatrixBin<"Uv", "UvUvUv", "csil">;
def msaddu_b_mm  : RVMatrixBin<"Uv", "UvUvUv", "c">;
def msaddu_h_mm  : RVMatrixBin<"Uv", "UvUvUv", "s">;
def msaddu_w_mm  : RVMatrixBin<"Uv", "UvUvUv", "i">;
def msaddu_dw_mm : RVMatrixBin<"Uv", "UvUvUv", "l">;
def mwaddu_mm   : RVMatrixWidenBin<"Uw", "UwUvUv", "csi">;
def mwaddu_b_mm : RVMatrixWidenBin<"Uw", "UwUvUv", "c">;
def mwaddu_h_mm : RVMatrixWidenBin<"Uw", "UwUvUv", "s">;
def mwaddu_w_mm : RVMatrixWidenBin<"Uw", "UwUvUv", "i">;

def madd_mm    : RVMatrixBin<"v", "vvv", "csil">;
def madd_b_mm  : RVMatrixBin<"v", "vvv", "c">;
def madd_h_mm  : RVMatrixBin<"v", "vvv", "s">;
def madd_w_mm  : RVMatrixBin<"v", "vvv", "i">;
def madd_dw_mm : RVMatrixBin<"v", "vvv", "l">;
def msadd_mm    : RVMatrixBin<"v", "vvv", "csil">;
def msadd_b_mm  : RVMatrixBin<"v", "vvv", "c">;
def msadd_h_mm  : RVMatrixBin<"v", "vvv", "s">;
def msadd_w_mm  : RVMatrixBin<"v", "vvv", "i">;
def msadd_dw_mm : RVMatrixBin<"v", "vvv", "l">;
def mwadd_mm   : RVMatrixWidenBin<"w", "wvv", "csi">;
def mwadd_b_mm : RVMatrixWidenBin<"w", "wvv", "c">;
def mwadd_h_mm : RVMatrixWidenBin<"w", "wvv", "s">;
def mwadd_w_mm : RVMatrixWidenBin<"w", "wvv", "i">;

def msubu_mm    : RVMatrixBin<"Uv", "vUvUv", "csil">;
def msubu_b_mm  : RVMatrixBin<"Uv", "vUvUv", "c">;
def msubu_h_mm  : RVMatrixBin<"Uv", "vUvUv", "s">;
def msubu_w_mm  : RVMatrixBin<"Uv", "vUvUv", "i">;
def msubu_dw_mm : RVMatrixBin<"Uv", "vUvUv", "l">;
def mssubu_mm    : RVMatrixBin<"Uv", "vUvUv", "csil">;
def mssubu_b_mm  : RVMatrixBin<"Uv", "vUvUv", "c">;
def mssubu_h_mm  : RVMatrixBin<"Uv", "vUvUv", "s">;
def mssubu_w_mm  : RVMatrixBin<"Uv", "vUvUv", "i">;
def mssubu_dw_mm : RVMatrixBin<"Uv", "vUvUv", "l">;
def mwsubu_mm   : RVMatrixWidenBin<"Uw", "wUvUv", "csi">;
def mwsubu_b_mm : RVMatrixWidenBin<"Uw", "wUvUv", "c">;
def mwsubu_h_mm : RVMatrixWidenBin<"Uw", "wUvUv", "s">;
def mwsubu_w_mm : RVMatrixWidenBin<"Uw", "wUvUv", "i">;

def msub_mm    : RVMatrixBin<"v", "vvv", "csil">;
def msub_b_mm  : RVMatrixBin<"v", "vvv", "c">;
def msub_h_mm  : RVMatrixBin<"v", "vvv", "s">;
def msub_w_mm  : RVMatrixBin<"v", "vvv", "i">;
def msub_dw_mm : RVMatrixBin<"v", "vvv", "l">;
def mssub_mm    : RVMatrixBin<"v", "vvv", "csil">;
def mssub_b_mm  : RVMatrixBin<"v", "vvv", "c">;
def mssub_h_mm  : RVMatrixBin<"v", "vvv", "s">;
def mssub_w_mm  : RVMatrixBin<"v", "vvv", "i">;
def mssub_dw_mm : RVMatrixBin<"v", "vvv", "l">;
def mwsub_mm   : RVMatrixWidenBin<"w", "wvv", "csi">;
def mwsub_b_mm : RVMatrixWidenBin<"w", "wvv", "c">;
def mwsub_h_mm : RVMatrixWidenBin<"w", "wvv", "s">;
def mwsub_w_mm : RVMatrixWidenBin<"w", "wvv", "i">;

def mminu_mm    : RVMatrixBin<"Uv", "UvUvUv", "csil">;
def mminu_b_mm  : RVMatrixBin<"Uv", "UvUvUv", "c">;
def mminu_h_mm  : RVMatrixBin<"Uv", "UvUvUv", "s">;
def mminu_w_mm  : RVMatrixBin<"Uv", "UvUvUv", "i">;
def mminu_dw_mm : RVMatrixBin<"Uv", "UvUvUv", "l">;
def mmin_mm    : RVMatrixBin<"v", "vvv", "csil">;
def mmin_b_mm  : RVMatrixBin<"v", "vvv", "c">;
def mmin_h_mm  : RVMatrixBin<"v", "vvv", "s">;
def mmin_w_mm  : RVMatrixBin<"v", "vvv", "i">;
def mmin_dw_mm : RVMatrixBin<"v", "vvv", "l">;

def mmaxu_mm    : RVMatrixBin<"Uv", "UvUvUv", "csil">;
def mmaxu_b_mm  : RVMatrixBin<"Uv", "UvUvUv", "c">;
def mmaxu_h_mm  : RVMatrixBin<"Uv", "UvUvUv", "s">;
def mmaxu_w_mm  : RVMatrixBin<"Uv", "UvUvUv", "i">;
def mmaxu_dw_mm : RVMatrixBin<"Uv", "UvUvUv", "l">;
def mmax_mm     : RVMatrixBin<"v", "vvv", "csil">;
def mmax_b_mm   : RVMatrixBin<"v", "vvv", "c">;
def mmax_h_mm   : RVMatrixBin<"v", "vvv", "s">;
def mmax_w_mm   : RVMatrixBin<"v", "vvv", "i">;
def mmax_dw_mm  : RVMatrixBin<"v", "vvv", "l">;

defm mand_mm : RVMatrixBitWiseBuitin<["c","s","i","l"]>;
defm mor_mm  : RVMatrixBitWiseBuitin<["c","s","i","l"]>;
defm mxor_mm : RVMatrixBitWiseBuitin<["c","s","i","l"]>;

defm msll_mm    : RVMatrixBitWiseBuitin<["c","s","i","l"]>;
defm msll_b_mm  : RVMatrixBitWiseBuitin<["c"]>;
defm msll_h_mm  : RVMatrixBitWiseBuitin<["s"]>;
defm msll_w_mm  : RVMatrixBitWiseBuitin<["i"]>;
defm msll_dw_mm : RVMatrixBitWiseBuitin<["l"]>;

defm msrl_mm    : RVMatrixBitWiseBuitin<["c","s","i","l"]>;
defm msrl_b_mm  : RVMatrixBitWiseBuitin<["c"]>;
defm msrl_h_mm  : RVMatrixBitWiseBuitin<["s"]>;
defm msrl_w_mm  : RVMatrixBitWiseBuitin<["i"]>;
defm msrl_dw_mm : RVMatrixBitWiseBuitin<["l"]>;

defm msra_mm    : RVMatrixBitWiseBuitin<["c","s","i","l"]>;
defm msra_b_mm  : RVMatrixBitWiseBuitin<["c"]>;
defm msra_h_mm  : RVMatrixBitWiseBuitin<["s"]>;
defm msra_w_mm  : RVMatrixBitWiseBuitin<["i"]>;
defm msra_dw_mm : RVMatrixBitWiseBuitin<["l"]>;

def mmul_mm    : RVMatrixBin<"v", "vvv", "csil">;
def mmul_b_mm  : RVMatrixBin<"v", "vvv", "c">;
def mmul_h_mm  : RVMatrixBin<"v", "vvv", "s">;
def mmul_w_mm  : RVMatrixBin<"v", "vvv", "i">;
def mmul_dw_mm : RVMatrixBin<"v", "vvv", "l">;

def mmulh_mm    : RVMatrixBin<"v", "vvv", "csil">;
def mmulh_b_mm  : RVMatrixBin<"v", "vvv", "c">;
def mmulh_h_mm  : RVMatrixBin<"v", "vvv", "s">;
def mmulh_w_mm  : RVMatrixBin<"v", "vvv", "i">;
def mmulh_dw_mm : RVMatrixBin<"v", "vvv", "l">;

def mmulhu_mm    : RVMatrixBin<"Uv", "UvUvUv", "csil">;
def mmulhu_b_mm  : RVMatrixBin<"Uv", "UvUvUv", "c">;
def mmulhu_h_mm  : RVMatrixBin<"Uv", "UvUvUv", "s">;
def mmulhu_w_mm  : RVMatrixBin<"Uv", "UvUvUv", "i">;
def mmulhu_dw_mm : RVMatrixBin<"Uv", "UvUvUv", "l">;

def mmulhsu_mm    : RVMatrixBin<"v", "vvUv", "csil">;
def mmulhsu_b_mm  : RVMatrixBin<"v", "vvUv", "c">;
def mmulhsu_h_mm  : RVMatrixBin<"v", "vvUv", "s">;
def mmulhsu_w_mm  : RVMatrixBin<"v", "vvUv", "i">;
def mmulhsu_dw_mm : RVMatrixBin<"v", "vvUv", "l">;

def msmul_mm    : RVMatrixBin<"v", "vvv", "csil">;
def msmul_b_mm  : RVMatrixBin<"v", "vvv", "c">;
def msmul_h_mm  : RVMatrixBin<"v", "vvv", "s">;
def msmul_w_mm  : RVMatrixBin<"v", "vvv", "i">;
def msmul_dw_mm : RVMatrixBin<"v", "vvv", "l">;

def msmulu_mm    : RVMatrixBin<"Uv", "UvUvUv", "csil">;
def msmulu_b_mm  : RVMatrixBin<"Uv", "UvUvUv", "c">;
def msmulu_h_mm  : RVMatrixBin<"Uv", "UvUvUv", "s">;
def msmulu_w_mm  : RVMatrixBin<"Uv", "UvUvUv", "i">;
def msmulu_dw_mm : RVMatrixBin<"Uv", "UvUvUv", "l">;

def msmulsu_mm    : RVMatrixBin<"v", "vvUv", "csil">;
def msmulsu_b_mm  : RVMatrixBin<"v", "vvUv", "c">;
def msmulsu_h_mm  : RVMatrixBin<"v", "vvUv", "s">;
def msmulsu_w_mm  : RVMatrixBin<"v", "vvUv", "i">;
def msmulsu_dw_mm : RVMatrixBin<"v", "vvUv", "l">;

def mwmul_mm   : RVMatrixWidenBin<"w", "wvv", "csi">;
def mwmul_b_mm : RVMatrixWidenBin<"w", "wvv", "c">;
def mwmul_h_mm : RVMatrixWidenBin<"w", "wvv", "s">;
def mwmul_w_mm : RVMatrixWidenBin<"w", "wvv", "i">;

def mwmulu_mm   : RVMatrixWidenBin<"Uw", "UwUvUv", "csi">;
def mwmulu_b_mm : RVMatrixWidenBin<"Uw", "UwUvUv", "c">;
def mwmulu_h_mm : RVMatrixWidenBin<"Uw", "UwUvUv", "s">;
def mwmulu_w_mm : RVMatrixWidenBin<"Uw", "UwUvUv", "i">;

def mwmulsu_mm   : RVMatrixWidenBin<"w", "wvUv", "csi">;
def mwmulsu_b_mm : RVMatrixWidenBin<"w", "wvUv", "c">;
def mwmulsu_h_mm : RVMatrixWidenBin<"w", "wvUv", "s">;
def mwmulsu_w_mm : RVMatrixWidenBin<"w", "wvUv", "i">;

// Float matrix element-wise
def mfadd_mm     : RVMatrixBin<"v", "vvv", "xfd">;
def mfadd_hf_mm  : RVMatrixBin<"v", "vvv", "x">;
def mfadd_f_mm   : RVMatrixBin<"v", "vvv", "f">;
def mfadd_d_mm   : RVMatrixBin<"v", "vvv", "d">;
def mfwadd_mm    : RVMatrixWidenBin<"w", "wvv", "xf">;
def mfwadd_hf_mm : RVMatrixWidenBin<"w", "wvv", "x">;
def mfwadd_f_mm  : RVMatrixWidenBin<"w", "wvv", "f">;

def mfsub_mm     : RVMatrixBin<"v", "vvv", "xfd">;
def mfsub_hf_mm  : RVMatrixBin<"v", "vvv", "x">;
def mfsub_f_mm   : RVMatrixBin<"v", "vvv", "f">;
def mfsub_d_mm   : RVMatrixBin<"v", "vvv", "d">;
def mfwsub_mm    : RVMatrixWidenBin<"w", "wvv", "xf">;
def mfwsub_hf_mm : RVMatrixWidenBin<"w", "wvv", "x">;
def mfwsub_f_mm  : RVMatrixWidenBin<"w", "wvv", "f">;

def mfmin_mm     : RVMatrixBin<"v", "vvv", "xfd">;
def mfmin_hf_mm  : RVMatrixBin<"v", "vvv", "x">;
def mfmin_f_mm   : RVMatrixBin<"v", "vvv", "f">;
def mfmin_d_mm   : RVMatrixBin<"v", "vvv", "d">;

def mfmax_mm     : RVMatrixBin<"v", "vvv", "xfd">;
def mfmax_hf_mm  : RVMatrixBin<"v", "vvv", "x">;
def mfmax_f_mm   : RVMatrixBin<"v", "vvv", "f">;
def mfmax_d_mm   : RVMatrixBin<"v", "vvv", "d">;

def mfmul_mm     : RVMatrixBin<"v", "vvv", "xfd">;
def mfmul_hf_mm  : RVMatrixBin<"v", "vvv", "x">;
def mfmul_f_mm   : RVMatrixBin<"v", "vvv", "f">;
def mfmul_d_mm   : RVMatrixBin<"v", "vvv", "d">;
def mfwmul_mm    : RVMatrixWidenBin<"w", "wvv", "xf">;
def mfwmul_hf_mm : RVMatrixWidenBin<"w", "wvv", "x">;
def mfwmul_f_mm  : RVMatrixWidenBin<"w", "wvv", "f">;

def mfdiv_mm     : RVMatrixBin<"v", "vvv", "xfd">;
def mfdiv_hf_mm  : RVMatrixBin<"v", "vvv", "x">;
def mfdiv_f_mm   : RVMatrixBin<"v", "vvv", "f">;
def mfdiv_d_mm   : RVMatrixBin<"v", "vvv", "d">;

def mfsqrt_m    : RVMatrixBin<"v", "vv", "xfd">;
def mfsqrt_hf_m : RVMatrixBin<"v", "vv", "x">;
def mfsqrt_f_m  : RVMatrixBin<"v", "vv", "f">;
def mfsqrt_d_m  : RVMatrixBin<"v", "vv", "d">;

// 4.5.3. Type-Convert Instructions
let IntrinsicTypes = [-1, 0] in {
def mcvt_x_xu_m   : RISCVMatrixBuiltin<"v", "vUv", "csil">;
def mcvt_b_ub_m   : RISCVMatrixBuiltin<"v", "vUv", "c">;
def mcvt_h_uh_m   : RISCVMatrixBuiltin<"v", "vUv", "s">;
def mcvt_w_uw_m   : RISCVMatrixBuiltin<"v", "vUv", "i">;
def mcvt_dw_udw_m : RISCVMatrixBuiltin<"v", "vUv", "l">;

def mcvt_xu_x_m   : RISCVMatrixBuiltin<"Uv", "Uvv", "csil">;
def mcvt_ub_b_m   : RISCVMatrixBuiltin<"Uv", "Uvv", "c">;
def mcvt_uh_h_m   : RISCVMatrixBuiltin<"Uv", "Uvv", "s">;
def mcvt_uw_w_m   : RISCVMatrixBuiltin<"Uv", "Uvv", "i">;
def mcvt_udw_dw_m : RISCVMatrixBuiltin<"Uv", "Uvv", "l">;

def mwcvtu_xw_x_m : RISCVMatrixBuiltin<"Uw", "UwUv", "csi">;
def mwcvtu_h_b_m  : RISCVMatrixBuiltin<"Uw", "UwUv", "c">;
def mwcvtu_w_h_m  : RISCVMatrixBuiltin<"Uw", "UwUv", "s">;
def mwcvtu_dw_w_m : RISCVMatrixBuiltin<"Uw", "UwUv", "i">;
def mwcvtu_xq_x_m : RISCVMatrixBuiltin<"Uq", "UqUv", "c">;
def mwcvtu_w_b_m  : RISCVMatrixBuiltin<"Uq", "UqUv", "c">;

def mwcvt_xw_x_m : RISCVMatrixBuiltin<"w", "wv", "csi">;
def mwcvt_h_b_m  : RISCVMatrixBuiltin<"w", "wv", "c">;
def mwcvt_w_h_m  : RISCVMatrixBuiltin<"w", "wv", "s">;
def mwcvt_dw_w_m : RISCVMatrixBuiltin<"w", "wv", "i">;
def mwcvt_xq_x_m : RISCVMatrixBuiltin<"q", "qv", "c">;
def mwcvt_w_b_m  : RISCVMatrixBuiltin<"q", "qv", "c">;

def mncvtu_x_xw_m : RISCVMatrixBuiltin<"Uv", "UvUw", "csi">;
def mncvtu_b_h_m  : RISCVMatrixBuiltin<"Uv", "UvUw", "c">;
def mncvtu_h_w_m  : RISCVMatrixBuiltin<"Uv", "UvUw", "s">;
def mncvtu_w_dw_m : RISCVMatrixBuiltin<"Uv", "UvUw", "i">;
def mncvtu_x_xq_m : RISCVMatrixBuiltin<"Uv", "UvUq", "c">;
def mncvtu_b_w_m  : RISCVMatrixBuiltin<"Uv", "UvUq", "c">;

def mncvt_x_xw_m : RISCVMatrixBuiltin<"v", "vw", "csi">;
def mncvt_b_h_m  : RISCVMatrixBuiltin<"v", "vw", "c">;
def mncvt_h_w_m  : RISCVMatrixBuiltin<"v", "vw", "s">;
def mncvt_w_dw_m : RISCVMatrixBuiltin<"v", "vw", "i">;
def mncvt_x_xq_m : RISCVMatrixBuiltin<"v", "vq", "c">;
def mncvt_b_w_m  : RISCVMatrixBuiltin<"v", "vq", "c">;

def mfwcvt_fw_f_m : RISCVMatrixBuiltin<"w", "wv", "xf">;
def mfwcvt_f_hf_m : RISCVMatrixBuiltin<"w", "wv", "x">;
def mfwcvt_d_f_m  : RISCVMatrixBuiltin<"w", "wv", "f">;

def mfncvt_f_fw_m : RISCVMatrixBuiltin<"v", "vw", "xf">;
def mfncvt_hf_f_m : RISCVMatrixBuiltin<"v", "vw", "x">;
def mfncvt_f_d_m  : RISCVMatrixBuiltin<"v", "vw", "f">;

// ===== i -> f
def mfcvtu_f_x_m  : RISCVMatrixBuiltin<"Fv", "FvUv", "sil">;
def mfcvtu_hf_h_m : RISCVMatrixBuiltin<"Fv", "FvUv", "s">;
def mfcvtu_f_w_m  : RISCVMatrixBuiltin<"Fv", "FvUv", "i">;
def mfcvtu_d_dw_m : RISCVMatrixBuiltin<"Fv", "FvUv", "l">;

def mfcvt_f_x_m  : RISCVMatrixBuiltin<"Fv", "Fvv", "sil">;
def mfcvt_hf_h_m : RISCVMatrixBuiltin<"Fv", "Fvv", "s">;
def mfcvt_f_w_m  : RISCVMatrixBuiltin<"Fv", "Fvv", "i">;
def mfcvt_d_dw_m : RISCVMatrixBuiltin<"Fv", "Fvv", "l">;

def mfwcvtu_fw_x_m : RISCVMatrixBuiltin<"Fw", "FwUv", "csi">;
def mfwcvtu_hf_b_m : RISCVMatrixBuiltin<"Fw", "FwUv", "c">;
def mfwcvtu_f_h_m  : RISCVMatrixBuiltin<"Fw", "FwUv", "s">;
def mfwcvtu_d_w_m  : RISCVMatrixBuiltin<"Fw", "FwUv", "i">;
def mfwcvtu_fq_x_m : RISCVMatrixBuiltin<"Fq", "FqUv", "c">;
def mfwcvtu_f_b_m  : RISCVMatrixBuiltin<"Fq", "FqUv", "c">;

def mfwcvt_fw_x_m : RISCVMatrixBuiltin<"Fw", "Fwv", "csi">;
def mfwcvt_hf_b_m : RISCVMatrixBuiltin<"Fw", "Fwv", "c">;
def mfwcvt_f_h_m  : RISCVMatrixBuiltin<"Fw", "Fwv", "s">;
def mfwcvt_d_w_m  : RISCVMatrixBuiltin<"Fw", "Fwv", "i">;
def mfwcvt_fq_x_m : RISCVMatrixBuiltin<"Fq", "Fqv", "c">;
def mfwcvt_f_b_m  : RISCVMatrixBuiltin<"Fq", "Fqv", "c">;

def mfncvtu_f_xw_m : RISCVMatrixBuiltin<"Fv", "FvUw", "si">;
def mfncvtu_hf_w_m : RISCVMatrixBuiltin<"Fv", "FvUw", "s">;
def mfncvtu_f_dw_m : RISCVMatrixBuiltin<"Fv", "FvUw", "i">;

def mfncvt_f_xw_m : RISCVMatrixBuiltin<"Fv", "Fvw", "si">;
def mfncvt_hf_w_m : RISCVMatrixBuiltin<"Fv", "Fvw", "s">;
def mfncvt_f_dw_m : RISCVMatrixBuiltin<"Fv", "Fvw", "i">;

// ----- f -> i
def mfcvtu_x_f_m  : RISCVMatrixBuiltin<"Uv", "Uvv", "xfd">;
def mfcvtu_h_hf_m : RISCVMatrixBuiltin<"Uv", "Uvv", "x">;
def mfcvtu_w_f_m  : RISCVMatrixBuiltin<"Uv", "Uvv", "f">;
def mfcvtu_dw_d_m : RISCVMatrixBuiltin<"Uv", "Uvv", "d">;

def mfcvt_x_f_m  : RISCVMatrixBuiltin<"Iv", "Ivv", "xfd">;
def mfcvt_h_hf_m : RISCVMatrixBuiltin<"Iv", "Ivv", "x">;
def mfcvt_w_f_m  : RISCVMatrixBuiltin<"Iv", "Ivv", "f">;
def mfcvt_dw_d_m : RISCVMatrixBuiltin<"Iv", "Ivv", "d">;

def mfwcvtu_xw_f_m : RISCVMatrixBuiltin<"Uw", "Uwv", "xf">;
def mfwcvtu_w_hf_m : RISCVMatrixBuiltin<"Uw", "Uwv", "x">;
def mfwcvtu_dw_f_m : RISCVMatrixBuiltin<"Uw", "Uwv", "f">;

def mfwcvt_xw_f_m : RISCVMatrixBuiltin<"Iw", "Iwv", "xf">;
def mfwcvt_w_hf_m : RISCVMatrixBuiltin<"Iw", "Iwv", "x">;
def mfwcvt_dw_f_m : RISCVMatrixBuiltin<"Iw", "Iwv", "f">;

def mfncvtu_x_fw_m : RISCVMatrixBuiltin<"Uv", "UvFw", "csi">;
def mfncvtu_b_hf_m : RISCVMatrixBuiltin<"Uv", "UvFw", "c">;
def mfncvtu_h_f_m  : RISCVMatrixBuiltin<"Uv", "UvFw", "s">;
def mfncvtu_w_d_m  : RISCVMatrixBuiltin<"Uv", "UvFw", "i">;
def mfncvtu_x_fq_m : RISCVMatrixBuiltin<"Uv", "UvFq", "c">;
def mfncvtu_b_f_m  : RISCVMatrixBuiltin<"Uv", "UvFq", "c">;

def mfncvt_x_fw_m : RISCVMatrixBuiltin<"v", "vFw", "csi">;
def mfncvt_b_hf_m : RISCVMatrixBuiltin<"v", "vFw", "c">;
def mfncvt_h_f_m  : RISCVMatrixBuiltin<"v", "vFw", "s">;
def mfncvt_w_d_m  : RISCVMatrixBuiltin<"v", "vFw", "i">;
def mfncvt_x_fq_m : RISCVMatrixBuiltin<"v", "vFq", "c">;
def mfncvt_b_f_m  : RISCVMatrixBuiltin<"v", "vFq", "c">;
}


multiclass RVMatrixLoadVBuiltin {
  let Name = NAME,
      IRName = NAME,
      ManualCodegen = [{
      IntrinsicTypes = {ResultType, Ops[1]->getType()};
      Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
      }] in {
    foreach type = TypeList in {
      def : RISCVMatrixBuiltin<"v", "aPCez", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UaPCUez", type>;
      }
    }
  }
}

defm mla_v : RVMatrixLoadVBuiltin;
defm mlb_v : RVMatrixLoadVBuiltin;
defm mlc_v : RVMatrixLoadVBuiltin;

multiclass RVMatrixStoreVBuiltin {
  let Name = NAME,
      IRName = NAME,
      LMUL = [1],
      ManualCodegen = [{
     Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
     IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType()};
      }] in {
    foreach type = TypeList in {
      def : RISCVMatrixBuiltin<"v", "0aPCez", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "0UaPCUez", type>;
      }
    }
  }
}

defm msa_v : RVMatrixStoreVBuiltin;
defm msb_v : RVMatrixStoreVBuiltin;
defm msc_v : RVMatrixStoreVBuiltin;

multiclass RVMatrixZVMBuitin {
  let Name = NAME,
      IRName = NAME,
      IntrinsicTypes = [-1, 0, 1] in {
    foreach type = TypeList in {
      def : RISCVMatrixBuiltin<"v", "avz", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UaUvz", type>;
      }
    }
  }
}

multiclass RVMatrixZMVBuitin {
  let Name = NAME,
      IRName = NAME,
      IntrinsicTypes = [-1, 0, 1] in {
    foreach type = TypeList in {
      def : RISCVMatrixBuiltin<"v", "vaz", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UvUaz", type>;
      }
    }
  }
}

defm mmvar_v_m : RVMatrixZVMBuitin;
defm mmvbr_v_m : RVMatrixZVMBuitin;
defm mmvcr_v_m : RVMatrixZVMBuitin;
defm mmvar_m_v : RVMatrixZMVBuitin;
defm mmvbr_m_v : RVMatrixZMVBuitin;
defm mmvcr_m_v : RVMatrixZMVBuitin;

defm mmvac_v_m : RVMatrixZVMBuitin;
defm mmvbc_v_m : RVMatrixZVMBuitin;
defm mmvcc_v_m : RVMatrixZVMBuitin;
defm mmvac_m_v : RVMatrixZMVBuitin;
defm mmvbc_m_v : RVMatrixZMVBuitin;
defm mmvcc_m_v : RVMatrixZMVBuitin;
