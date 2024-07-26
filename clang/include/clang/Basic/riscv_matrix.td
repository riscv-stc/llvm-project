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
  list<int> LMUL = [1, 2, 4];

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

class RVMatrixBinLMUL<string suffix, string prototype, string type_range>
    : RISCVMatrixBuiltin<suffix, prototype, type_range> {
  let HasLMUL = true;
  let IntrinsicTypes = [-1, 2];
}
class RVMatrixSignedBinLMUL : RVMatrixBinLMUL<"v", "vvvz", "csil">;
class RVMatrixUnsignedBinLMUL : RVMatrixBinLMUL<"Uv", "UvUvUvz", "csil">;
class RVMatrixFloatBinLMUL : RVMatrixBinLMUL<"v", "vvvz", "xfd">;

class RVMatrixWidenBinLMUL<string suffix, string prototype, string type_range>
    : RISCVMatrixBuiltin<suffix, prototype, type_range> {
  let HasLMUL = true;
  let IntrinsicTypes = [-1, 1, 2];
  let LMUL = [1, 2];
}
class RVMatrixSignedWidenBinLMUL : RVMatrixWidenBinLMUL<"w", "wvvz", "csi">;
class RVMatrixUnsignedWidenBinLMUL : RVMatrixWidenBinLMUL<"Uw", "UwUvUvz", "csi">;
class RVMatrixFloatWidenBinLMUL : RVMatrixWidenBinLMUL<"w", "wvvz", "xf">;

class RVMatrixOut<string suffix, string prototype, string type_range>
    : RISCVMatrixBuiltin<suffix, prototype, type_range> {
  let IntrinsicTypes = [-1];
}
class RVMatrixSignedTer : RVMatrixOut<"v", "vvvv", "csil">;
class RVMatrixUnsignedTer : RVMatrixOut<"Uv", "UvUvUvUv", "csil">;
class RVMatrixFloatTer : RVMatrixOut<"v", "vvvv", "xfd">;

class RVMatrixWidenOutOp1<string suffix, string prototype, string type_range>
    : RISCVMatrixBuiltin<suffix, prototype, type_range> {
  let IntrinsicTypes = [-1, 1];
  let LMUL = [1, 2];
}
class RVMatrixSignedWidenTer : RVMatrixWidenOutOp1<"w", "wwvv", "csi">;
class RVMatrixUnsignedWidenTer : RVMatrixWidenOutOp1<"Uw", "UwUwUvUv", "csi">;
class RVMatrixFloatWidenTer : RVMatrixWidenOutOp1<"w", "wwvv", "xf">;

class RVMatrixQuadTer<string suffix, string prototype, string type_range>
    : RISCVMatrixBuiltin<suffix, prototype, type_range> {
  let IntrinsicTypes = [-1, 1];
  let LMUL = [1];
}
class RVMatrixSignedQuadTer : RVMatrixQuadTer<"q", "qqvv", "cs">;
class RVMatrixUnsignedQuadTer : RVMatrixQuadTer<"Uq", "UqUqUvUv", "cs">;

class IsFloat<string type> {
  bit val = !or(!eq(type, "x"), !eq(type, "f"), !eq(type, "d"));
}

multiclass RVMatrixMLEBuiltin<list<string> types, string ir_name> {
  let Name = NAME,
      IRName = ir_name,
      HasLMUL = true,
      IsLoad = true,
      ManualCodegen = [{
      IntrinsicTypes = {ResultType, Ops[1]->getType()};
      Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
      }] in {
    foreach type = types in {
      def : RISCVMatrixBuiltin<"v", "vPCezz", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UvPCUezz", type>;
      }
    }
  }
}

multiclass RVMatrixMSEBuiltin<list<string> types, string ir_name> {
  let Name = NAME,
      IRName = ir_name,
      HasLMUL = true,
      ManualCodegen = [{
     Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
     IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType()};
      }] in {
    foreach type = types in {
      def : RISCVMatrixBuiltin<"v", "0vPCezz", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "0UvPCUezz", type>;
      }
    }
  }
}


defvar TypeList = ["c","s","i","l","x","f","d"];
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

// 4.3. Load and Store Instructions
// 4.3.1. Load Instructions
defm mlae8_m : RVMatrixMLEBuiltin<["c"], "mlae_m">;
defm mlae16_m : RVMatrixMLEBuiltin<["s","x"], "mlae_m">;
defm mlae32_m : RVMatrixMLEBuiltin<["i","f"], "mlae_m">;
defm mlae64_m : RVMatrixMLEBuiltin<["l","d"], "mlae_m">;
defm mlbe8_m : RVMatrixMLEBuiltin<["c"], "mlbe_m">;
defm mlbe16_m : RVMatrixMLEBuiltin<["s","x"], "mlbe_m">;
defm mlbe32_m : RVMatrixMLEBuiltin<["i","f"], "mlbe_m">;
defm mlbe64_m : RVMatrixMLEBuiltin<["l","d"], "mlbe_m">;
defm mlce8_m : RVMatrixMLEBuiltin<["c"], "mlce_m">;
defm mlce16_m : RVMatrixMLEBuiltin<["s","x"], "mlce_m">;
defm mlce32_m : RVMatrixMLEBuiltin<["i","f"], "mlce_m">;
defm mlce64_m : RVMatrixMLEBuiltin<["l","d"], "mlce_m">;

defm mlate8_m : RVMatrixMLEBuiltin<["c"], "mlate_m">;
defm mlate16_m : RVMatrixMLEBuiltin<["s","x"], "mlate_m">;
defm mlate32_m : RVMatrixMLEBuiltin<["i","f"], "mlate_m">;
defm mlate64_m : RVMatrixMLEBuiltin<["l","d"], "mlate_m">;
defm mlbte8_m : RVMatrixMLEBuiltin<["c"], "mlbte_m">;
defm mlbte16_m : RVMatrixMLEBuiltin<["s","x"], "mlbte_m">;
defm mlbte32_m : RVMatrixMLEBuiltin<["i","f"], "mlbte_m">;
defm mlbte64_m : RVMatrixMLEBuiltin<["l","d"], "mlbte_m">;
defm mlcte8_m : RVMatrixMLEBuiltin<["c"], "mlcte_m">;
defm mlcte16_m : RVMatrixMLEBuiltin<["s","x"], "mlcte_m">;
defm mlcte32_m : RVMatrixMLEBuiltin<["i","f"], "mlcte_m">;
defm mlcte64_m : RVMatrixMLEBuiltin<["l","d"], "mlcte_m">;

// 4.3.2. Store Instructions
defm msae8_m : RVMatrixMSEBuiltin<["c"], "msae_m">;
defm msae16_m : RVMatrixMSEBuiltin<["s","x"], "msae_m">;
defm msae32_m : RVMatrixMSEBuiltin<["i","f"], "msae_m">;
defm msae64_m : RVMatrixMSEBuiltin<["l","d"], "msae_m">;
defm msbe8_m : RVMatrixMSEBuiltin<["c"], "msbe_m">;
defm msbe16_m : RVMatrixMSEBuiltin<["s","x"], "msbe_m">;
defm msbe32_m : RVMatrixMSEBuiltin<["i","f"], "msbe_m">;
defm msbe64_m : RVMatrixMSEBuiltin<["l","d"], "msbe_m">;
defm msce8_m : RVMatrixMSEBuiltin<["c"], "msce_m">;
defm msce16_m : RVMatrixMSEBuiltin<["s","x"], "msce_m">;
defm msce32_m : RVMatrixMSEBuiltin<["i","f"], "msce_m">;
defm msce64_m : RVMatrixMSEBuiltin<["l","d"], "msce_m">;

defm msate8_m : RVMatrixMSEBuiltin<["c"], "msate_m">;
defm msate16_m : RVMatrixMSEBuiltin<["s","x"], "msate_m">;
defm msate32_m : RVMatrixMSEBuiltin<["i","f"], "msate_m">;
defm msate64_m : RVMatrixMSEBuiltin<["l","d"], "msate_m">;
defm msbte8_m : RVMatrixMSEBuiltin<["c"], "msbte_m">;
defm msbte16_m : RVMatrixMSEBuiltin<["s","x"], "msbte_m">;
defm msbte32_m : RVMatrixMSEBuiltin<["i","f"], "msbte_m">;
defm msbte64_m : RVMatrixMSEBuiltin<["l","d"], "msbte_m">;
defm mscte8_m : RVMatrixMSEBuiltin<["c"], "mscte_m">;
defm mscte16_m : RVMatrixMSEBuiltin<["s","x"], "mscte_m">;
defm mscte32_m : RVMatrixMSEBuiltin<["i","f"], "mscte_m">;
defm mscte64_m : RVMatrixMSEBuiltin<["l","d"], "mscte_m">;

// 4.3.3. Whole Matrix Load & Store Instructions
defm mlre8_m : RVMatrixMLEBuiltin<["c"], "mlre_m">;
defm mlre16_m : RVMatrixMLEBuiltin<["s","x"], "mlre_m">;
defm mlre32_m : RVMatrixMLEBuiltin<["i","f"], "mlre_m">;
defm mlre64_m : RVMatrixMLEBuiltin<["l","d"], "mlre_m">;

defm msre8_m : RVMatrixMSEBuiltin<["c"], "msre_m">;
defm msre16_m : RVMatrixMSEBuiltin<["s","x"], "msre_m">;
defm msre32_m : RVMatrixMSEBuiltin<["i","f"], "msre_m">;
defm msre64_m : RVMatrixMSEBuiltin<["l","d"], "msre_m">;

// 4.4. Data Move Instructions
defm mmv_x_s : RVMatrixBuitinSet<"csil", [-1, 0, 1],
                                 [["v","evz"], ["Uv","UeUvz"]]>;

defm mmv_s_x : RVMatrixBuitinSet<"csil", [-1, 1, 2],
                                 [["v","vvez"], ["Uv","UvUvUez"]]>;

defm mfmv_f_s : RVMatrixBuitinSet<"xfd", [-1, 0, 1],
                                 [["v","evz"]]>;

defm mfmv_s_f : RVMatrixBuitinSet<"xfd", [-1, 1, 2],
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

// 4.5.1. Matrix Multiplication Instructions
def mmau_mm : RVMatrixUnsignedTer;
def mwmau_mm : RVMatrixUnsignedWidenTer;
def mqmau_mm : RVMatrixUnsignedQuadTer;
def msmau_mm : RVMatrixUnsignedTer;
def mswmau_mm : RVMatrixUnsignedWidenTer;
def msqmau_mm : RVMatrixUnsignedQuadTer;

def mma_mm : RVMatrixSignedTer;
def mwma_mm : RVMatrixSignedWidenTer;
def mqma_mm : RVMatrixSignedQuadTer;
def msma_mm : RVMatrixSignedTer;
def mswma_mm : RVMatrixSignedWidenTer;
def msqma_mm : RVMatrixSignedQuadTer;

def mfma_mm : RVMatrixFloatTer;
def mfwma_mm : RVMatrixFloatWidenTer;

// 4.5.2 Element-Wise Add/Sub/Multiply Instructions
def maddu_mm : RVMatrixUnsignedBinLMUL;
def msaddu_mm : RVMatrixUnsignedBinLMUL;
def mwaddu_mm : RVMatrixUnsignedWidenBinLMUL;
def madd_mm : RVMatrixSignedBinLMUL;
def msadd_mm : RVMatrixSignedBinLMUL;
def mwadd_mm : RVMatrixSignedWidenBinLMUL;
def msubu_mm : RVMatrixBinLMUL<"v", "vUvUvz", "csil">;
def mssubu_mm : RVMatrixBinLMUL<"v", "vUvUvz", "csil">;
def mwsubu_mm : RVMatrixWidenBinLMUL<"w", "wUvUvz", "csi">;
def msub_mm : RVMatrixSignedBinLMUL;
def mssub_mm : RVMatrixSignedBinLMUL;
def mwsub_mm : RVMatrixSignedWidenBinLMUL;
def mminu_mm : RVMatrixUnsignedBinLMUL;
def mmin_mm : RVMatrixSignedBinLMUL;
def mmaxu_mm :RVMatrixUnsignedBinLMUL;
def mmax_mm : RVMatrixSignedBinLMUL;
def mmul_mm : RVMatrixSignedBinLMUL;
def mmulh_mm : RVMatrixSignedBinLMUL;
def mmulhu_mm : RVMatrixUnsignedBinLMUL;
def msmul_mm : RVMatrixSignedBinLMUL;
def msmulu_mm : RVMatrixUnsignedBinLMUL;
def mwmul_mm : RVMatrixSignedWidenBinLMUL;
def mwmulu_mm : RVMatrixUnsignedWidenBinLMUL;

let HasLMUL = true, IntrinsicTypes = [-1, 1, 2] in {
def mmulhsu_mm : RISCVMatrixBuiltin<"v", "vvUvz", "csil">;
def msmulsu_mm : RISCVMatrixBuiltin<"v", "vvUvz", "csil">;
}

let HasLMUL = true, IntrinsicTypes = [-1, 0, 1, 2], LMUL = [1, 2] in {
def mwmulsu_mm : RISCVMatrixBuiltin<"w", "wvUvz", "csi">;
}

// Float matrix element-wise
def mfadd_mm : RVMatrixFloatBinLMUL;
def mfwadd_mm : RVMatrixFloatWidenBinLMUL;
def mfsub_mm : RVMatrixFloatBinLMUL;
def mfwsub_mm : RVMatrixFloatWidenBinLMUL;
def mfmin_mm : RVMatrixFloatBinLMUL;
def mfmax_mm : RVMatrixFloatBinLMUL;
def mfmul_mm : RVMatrixFloatBinLMUL;
def mfwmul_mm : RVMatrixFloatWidenBinLMUL;
def mfdiv_mm : RVMatrixFloatBinLMUL;

let HasLMUL = true, IntrinsicTypes = [-1, 1] in {
def mfsqrt_m : RISCVMatrixBuiltin<"v", "vvz", "xfd">;
}

// 4.5.3. Type-Convert Instructions
let HasLMUL = true, IntrinsicTypes = [-1, 0, 1] in {

let LMUL = [1, 2] in {
def mfncvt_f_fw_m : RISCVMatrixBuiltin<"v", "vwz", "xf">;
def mfwcvt_fw_f_m : RISCVMatrixBuiltin<"w", "wvz", "xf">;

def mfncvt_f_xw_m : RISCVMatrixBuiltin<"Fv", "Fvwz", "si">;
def mfwcvt_fw_x_m : RISCVMatrixBuiltin<"Fw", "Fwvz", "csi">;
def mfcvt_fw_xw_m : RISCVMatrixBuiltin<"Fw", "Fwwz", "csi">;

def mfwcvt_xw_f_m : RISCVMatrixBuiltin<"Iw", "Iwvz", "xf">;
def mfncvt_x_fw_m : RISCVMatrixBuiltin<"v", "vFwz", "csi">;
def mfcvt_xw_fw_m : RISCVMatrixBuiltin<"Iw", "Iwwz", "xf">;

}

def mfcvt_f_x_m : RISCVMatrixBuiltin<"Fv", "Fvvz", "sil">;
def mfcvt_x_f_m : RISCVMatrixBuiltin<"Iv", "Ivvz", "xfd">;

let LMUL = [1] in {
def mfncvt_f_xq_m : RISCVMatrixBuiltin<"Fv", "Fvqz", "s">;
def mfncvt_fw_xq_m : RISCVMatrixBuiltin<"Fw", "Fwqz", "cs">;

def mfwcvt_xq_f_m : RISCVMatrixBuiltin<"Iq", "Iqvz", "x">;
def mfwcvt_xq_fw_m : RISCVMatrixBuiltin<"Iq", "Iqwz", "x">;
}
}

let IntrinsicTypes = [-1], HasSideEffects = true, LMUL = [1] in {
  let HeaderCode =
[{
enum MLMUL {
    M1 = 0,
    M2,
    M4
};
enum MSEW {
    E8 = 0,
    E16,
    E32,
    E64
};
enum MBA {
    BU = 0,
    BA
};
enum MTYPE {
    MFP64 = 1,
    MBF16 = 2,
    MTF32 = 4,
    MFP8 = 8,
    MINT4 = 16
};

__rvm_overloaded size_t msettype(enum MSEW e, enum MLMUL m, enum MBA b) {
    size_t mtype = b;
    mtype = (mtype << 3) + e;
    mtype = (mtype << 2) + m;
    return __builtin_riscv_msettypei(mtype);
}

__rvm_overloaded size_t msettype(enum MSEW e, enum MLMUL m, enum MBA b,
                                 enum MTYPE t) {
    size_t mtype = b;
    mtype = (mtype << 3) + e;
    mtype = (mtype << 2) + m;
    mtype = (t << 6) + mtype;
    return __builtin_riscv_msettypei(mtype);
}

__rvm_overloaded size_t msettype(enum MSEW e, enum MLMUL m, enum MBA b,
                                 enum MTYPE t1, enum MTYPE t2) {
    size_t mtype = b;
    mtype = (mtype << 3) + e;
    mtype = (mtype << 2) + m;
    mtype = ((t1 + t2) << 6) + mtype;
    return __builtin_riscv_msettypei(mtype);
}

__rvm_overloaded size_t msettype(enum MSEW e, enum MLMUL m, enum MBA b,
                                 enum MTYPE t1, enum MTYPE t2, enum MTYPE t3) {
    size_t mtype = b;
    mtype = (mtype << 3) + e;
    mtype = (mtype << 2) + m;
    mtype = ((t1 + t2 + t3) << 6) + mtype;
    return __builtin_riscv_msettypei(mtype);
}

__rvm_overloaded size_t msettype(enum MSEW e, enum MLMUL m, enum MBA b,
                                 enum MTYPE t1, enum MTYPE t2, enum MTYPE t3,
                                 enum MTYPE t4) {
    size_t mtype = b;
    mtype = (mtype << 3) + e;
    mtype = (mtype << 2) + m;
    mtype = ((t1 + t2 + t3 + t4) << 6) + mtype;
    return __builtin_riscv_msettypei(mtype);
}

__rvm_overloaded size_t msettype(enum MSEW e, enum MLMUL m, enum MBA b,
                                 enum MTYPE t1, enum MTYPE t2, enum MTYPE t3,
                                 enum MTYPE t4, enum MTYPE t5) {
    size_t mtype = b;
    mtype = (mtype << 3) + e;
    mtype = (mtype << 2) + m;
    mtype = ((t1 + t2 + t3 + t4 + t5) << 6) + mtype;
    return __builtin_riscv_msettypei(mtype);
}

}] in {
  def msettype : RISCVMatrixBuiltin<"", "zz", "i">;
}

  def msettypei : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettilem : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettilemi : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettilen : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettileni : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettilek : RISCVMatrixBuiltin<"", "zz", "i">;
  def msettileki : RISCVMatrixBuiltin<"", "zz", "i">;

  let HeaderCode =
[{
__rvm_overloaded size_t msettile(uint8_t tilem, uint8_t tilen, uint8_t tilek) {
    size_t tile = tilek;
    tile = (tile << 8) + tilen;
    tile = (tile << 8) + tilem;
    return __builtin_riscv_msettile(tile);
}

}] in {
  def msettile : RISCVMatrixBuiltin<"", "zz", "i">;
}

  def msetoutsh : RISCVMatrixBuiltin<"", "zzz", "i">;
  def msetinsh : RISCVMatrixBuiltin<"", "zzz", "i">;
  def msetsk : RISCVMatrixBuiltin<"", "zzz", "i">;
  def msetpadval : RISCVMatrixBuiltin<"", "zz", "i">;
}

multiclass RVMatrixMLUFEBuiltin<list<string> types, string ir_name> {
  let Name = NAME,
      IRName = ir_name,
      LMUL = [1],
      ManualCodegen = [{
      IntrinsicTypes = {ResultType, Ops[1]->getType()};
      Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
      }] in {
    foreach type = types in {
      def : RISCVMatrixBuiltin<"v", "vPCez", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UvPCUez", type>;
      }
    }
  }
}

defm mlufae8_m : RVMatrixMLUFEBuiltin<["c"], "mlufae_m">;
defm mlufae16_m : RVMatrixMLUFEBuiltin<["s","x"], "mlufae_m">;
defm mlufae32_m : RVMatrixMLUFEBuiltin<["i","f"], "mlufae_m">;
defm mlufae64_m : RVMatrixMLUFEBuiltin<["l","d"], "mlufae_m">;
defm mlufbe8_m : RVMatrixMLUFEBuiltin<["c"], "mlufbe_m">;
defm mlufbe16_m : RVMatrixMLUFEBuiltin<["s","x"], "mlufbe_m">;
defm mlufbe32_m : RVMatrixMLUFEBuiltin<["i","f"], "mlufbe_m">;
defm mlufbe64_m : RVMatrixMLUFEBuiltin<["l","d"], "mlufbe_m">;
defm mlufce8_m : RVMatrixMLUFEBuiltin<["c"], "mlufce_m">;
defm mlufce16_m : RVMatrixMLUFEBuiltin<["s","x"], "mlufce_m">;
defm mlufce32_m : RVMatrixMLUFEBuiltin<["i","f"], "mlufce_m">;
defm mlufce64_m : RVMatrixMLUFEBuiltin<["l","d"], "mlufce_m">;

multiclass RVMatrixMSFDBuiltin<list<string> types, string ir_name> {
  let Name = NAME,
      IRName = ir_name,
      LMUL = [1],
      ManualCodegen = [{
     Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
     IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType()};
      }] in {
    foreach type = types in {
      def : RISCVMatrixBuiltin<"v", "0vPCez", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "0UvPCUez", type>;
      }
    }
  }
}

defm msfdae8_m : RVMatrixMSFDBuiltin<["c"], "msfdae_m">;
defm msfdae16_m : RVMatrixMSFDBuiltin<["s","x"], "msfdae_m">;
defm msfdae32_m : RVMatrixMSFDBuiltin<["i","f"], "msfdae_m">;
defm msfdae64_m : RVMatrixMSFDBuiltin<["l","d"], "msfdae_m">;
defm msfdbe8_m : RVMatrixMSFDBuiltin<["c"], "msfdbe_m">;
defm msfdbe16_m : RVMatrixMSFDBuiltin<["s","x"], "msfdbe_m">;
defm msfdbe32_m : RVMatrixMSFDBuiltin<["i","f"], "msfdbe_m">;
defm msfdbe64_m : RVMatrixMSFDBuiltin<["l","d"], "msfdbe_m">;
defm msfdce8_m : RVMatrixMSFDBuiltin<["c"], "msfdce_m">;
defm msfdce16_m : RVMatrixMSFDBuiltin<["s","x"], "msfdce_m">;
defm msfdce32_m : RVMatrixMSFDBuiltin<["i","f"], "msfdce_m">;
defm msfdce64_m : RVMatrixMSFDBuiltin<["l","d"], "msfdce_m">;

multiclass RVMatrixLoadVBuiltin<list<string> types, string ir_name> {
  let Name = NAME,
      IRName = ir_name,
      LMUL = [1],
      ManualCodegen = [{
      IntrinsicTypes = {ResultType, Ops[1]->getType()};
      Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
      }] in {
    foreach type = types in {
      def : RISCVMatrixBuiltin<"v", "aPCez", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "UaPCUez", type>;
      }
    }
  }
}

defm mlae8_v : RVMatrixLoadVBuiltin<["c"], "mlae_v">;
defm mlae16_v : RVMatrixLoadVBuiltin<["s","x"], "mlae_v">;
defm mlae32_v : RVMatrixLoadVBuiltin<["i","f"], "mlae_v">;
defm mlae64_v : RVMatrixLoadVBuiltin<["l","d"], "mlae_v">;
defm mlbe8_v : RVMatrixLoadVBuiltin<["c"], "mlbe_v">;
defm mlbe16_v : RVMatrixLoadVBuiltin<["s","x"], "mlbe_v">;
defm mlbe32_v : RVMatrixLoadVBuiltin<["i","f"], "mlbe_v">;
defm mlbe64_v : RVMatrixLoadVBuiltin<["l","d"], "mlbe_v">;
defm mlce8_v : RVMatrixLoadVBuiltin<["c"], "mlce_v">;
defm mlce16_v : RVMatrixLoadVBuiltin<["s","x"], "mlce_v">;
defm mlce32_v : RVMatrixLoadVBuiltin<["i","f"], "mlce_v">;
defm mlce64_v : RVMatrixLoadVBuiltin<["l","d"], "mlce_v">;

multiclass RVMatrixStoreVBuiltin<list<string> types, string ir_name> {
  let Name = NAME,
      IRName = ir_name,
      LMUL = [1],
      ManualCodegen = [{
     Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
     IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType()};
      }] in {
    foreach type = types in {
      def : RISCVMatrixBuiltin<"v", "0aPCez", type>;
      if !not(IsFloat<type>.val) then {
        def : RISCVMatrixBuiltin<"Uv", "0UaPCUez", type>;
      }
    }
  }
}

defm msae8_v : RVMatrixStoreVBuiltin<["c"], "msae_v">;
defm msae16_v : RVMatrixStoreVBuiltin<["s","x"], "msae_v">;
defm msae32_v : RVMatrixStoreVBuiltin<["i","f"], "msae_v">;
defm msae64_v : RVMatrixStoreVBuiltin<["l","d"], "msae_v">;
defm msbe8_v : RVMatrixStoreVBuiltin<["c"], "msbe_v">;
defm msbe16_v : RVMatrixStoreVBuiltin<["s","x"], "msbe_v">;
defm msbe32_v : RVMatrixStoreVBuiltin<["i","f"], "msbe_v">;
defm msbe64_v : RVMatrixStoreVBuiltin<["l","d"], "msbe_v">;
defm msce8_v : RVMatrixStoreVBuiltin<["c"], "msce_v">;
defm msce16_v : RVMatrixStoreVBuiltin<["s","x"], "msce_v">;
defm msce32_v : RVMatrixStoreVBuiltin<["i","f"], "msce_v">;
defm msce64_v : RVMatrixStoreVBuiltin<["l","d"], "msce_v">;

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
