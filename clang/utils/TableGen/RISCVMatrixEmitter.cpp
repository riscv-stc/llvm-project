#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/SmallSet.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/StringSet.h"
#include "llvm/ADT/Twine.h"
#include "llvm/TableGen/Error.h"
#include "llvm/TableGen/Record.h"
#include <iostream>
#include <numeric>

using namespace llvm;
using BasicType = char;
using VScaleVal = Optional<unsigned>;

namespace {

class RVMatrixType {
  enum ScalarTypeKind : uint32_t {
    Void,
    Size_t,
    Ptrdiff_t,
    UnsignedLong,
    SignedLong,
    Boolean,
    SignedInteger,
    UnsignedInteger,
    Float,
    Invalid,
  };
  BasicType BT;
  ScalarTypeKind ScalarType = Invalid;
  int LMUL = 0;
  bool IsPointer = false;
  // IsConstant indices are "int", but have the constant expression.
  bool IsImmediate = false;
  // Const qualifier for pointer to const object or object of const type.
  bool IsConstant = false;
  bool IsZmv = false;
  unsigned ElementBitwidth = 0;
  VScaleVal Scale = 0;
  bool Valid;

  std::string BuiltinStr;
  std::string Str;
  std::string ShortStr;

public:
  RVMatrixType() : RVMatrixType(BasicType(), 0, StringRef()) {}
  RVMatrixType(BasicType BT, int LMUL, StringRef prototype);

  // Return the string representation of a type, which is an encoded string for
  // passing to the BUILTIN() macro in Builtins.def.
  const std::string &getBuiltinStr() const { return BuiltinStr; }

  // Return the C/C++ string representation of a type for use in the
  // riscv_vector.h header file.
  const std::string &getTypeStr() const { return Str; }

  // Return the short name of a type for C/C++ name suffix.
  const std::string &getShortStr() {
    // Not all types are used in short name, so compute the short name by
    // demanded.
    if (ShortStr.empty())
      initShortStr();
    return ShortStr;
  }

  bool isValid() const { return Valid; }
  bool isScalar() const { return Scale.hasValue() && Scale.getValue() == 0; }
  bool isVector() const { return Scale.hasValue() && Scale.getValue() != 0; }
  bool isFloat() const { return ScalarType == ScalarTypeKind::Float; }
  bool isSignedInteger() const {
    return ScalarType == ScalarTypeKind::SignedInteger;
  }
  bool isFloat(unsigned Width) const {
    return isFloat() && ElementBitwidth == Width;
  }
  // Get LMUL number in parameter
  int getLMULParam();
  int getLMUL() const { return LMUL; }

private:
  // Verify RVV vector type and set Valid.
  bool verifyType() const;

  // Creates a type based on basic types of TypeRange
  void applyBasicType();

  // Applies a prototype modifier to the current type. The result maybe an
  // invalid type.
  void applyModifier(StringRef prototype);

  // Compute and record a string for legal type.
  void initBuiltinStr();

  // Compute and record a type string for used in the header.
  void initTypeStr();
  // Compute and record a short name of a type for C/C++ name suffix.
  void initShortStr();
};

using RVMatrixTypePtr = RVMatrixType *;
using RVMatrixTypes = std::vector<RVMatrixTypePtr>;

class RVMatrixIntrinsic {
private:
  std::string Name;
  std::string Suffix;
  std::string IRName;
  std::string ManualCodegen;
  bool HasSideEffects;
  bool HasLMUL;
  bool IsLoad;
  RVMatrixTypePtr OutputType; // Builtin output type
  RVMatrixTypes InputTypes;   // Builtin input types
  // The types we use to obtain the specific LLVM intrinsic. They are index of
  // InputTypes. -1 means the return type.
  std::vector<int64_t> IntrinsicTypes;

public:
  RVMatrixIntrinsic(StringRef Name, StringRef Suffix, StringRef IRName,
                    bool HasSideEffects, bool HasLMUL, bool IsLoad,
                    StringRef ManualCodegen, const RVMatrixTypes &Types,
                    const std::vector<int64_t> &IntrinsicTypes);
  ~RVMatrixIntrinsic() = default;

  StringRef getName() const { return Name; }
  StringRef getSuffix() const { return Suffix; }
  StringRef getIRName() const { return IRName; }
  StringRef getManualCodegen() const { return ManualCodegen; }
  bool hasSideEffects() const { return HasSideEffects; }
  bool hasLMUL() const { return HasLMUL; }
  bool isLoad() const { return IsLoad; }
  bool hasManualCodegen() const { return !ManualCodegen.empty(); }

  // Return the type string for a BUILTIN() macro in Builtins.def.
  std::string getBuiltinTypeStr() const;

  // Emit the code block for switch body in EmitRISCVBuiltinExpr.
  void emitCodeGenSwitchBody(raw_ostream &o) const;

  // Emit the mangled function definition.
  void emitMangledFuncDef(raw_ostream &o) const;
};

class RVMatrixEmitter {
private:
  RecordKeeper &Records;
  std::string HeaderCode;

  // Concat BasicType, LMUL and Proto as key
  StringMap<RVMatrixType> LegalTypes;
  StringSet<> IllegalTypes;

public:
  RVMatrixEmitter(RecordKeeper &R) : Records(R) {}

  /// Emit riscv_matrix.h
  void createHeader(raw_ostream &o);

  /// Emit all the __builtin prototypes and code needed by Sema.
  void createBuiltins(raw_ostream &o);

  /// Emit all the information needed to map builtin -> LLVM IR intrinsic.
  void createCodeGen(raw_ostream &o);

  std::string getSuffixStr(char Type, int LMUL, StringRef Prototypes);

private:
  /// Create all intrinsics and add them to \p Out
  void createRVMatrixIntrinsics(
      std::vector<std::unique_ptr<RVMatrixIntrinsic>> &Out);

  Optional<RVMatrixTypes> computeTypes(BasicType BT, int LMUL,
                                       ArrayRef<std::string> PrototypeSeq);
  Optional<RVMatrixTypePtr> computeType(BasicType BT, int LMUL,
                                        StringRef Proto);

  // Slice Prototypes string into sub prototype string and process each sub
  // prototype string individually in the Handler.
  void parsePrototypes(StringRef Prototypes,
                       std::function<void(StringRef)> Handler);
};
} // namespace

// ===================================================================================//
RVMatrixIntrinsic::RVMatrixIntrinsic(StringRef Name, StringRef Suffix,
                                     StringRef IRName, bool HasSideEffects,
                                     bool HasLMUL, bool IsLoad,
                                     StringRef ManualCodegen,
                                     const RVMatrixTypes &OutInTypes,
                                     const std::vector<int64_t> &IntrinsicTypes)
    : Name(Name), Suffix(Suffix), IRName(IRName),
      HasSideEffects(HasSideEffects), HasLMUL(HasLMUL), IsLoad(IsLoad),
      ManualCodegen(ManualCodegen.str()), IntrinsicTypes(IntrinsicTypes) {

  // Init OutputType and InputTypes
  OutputType = OutInTypes[0];
  InputTypes.assign(OutInTypes.begin() + 1, OutInTypes.end());
}

void RVMatrixIntrinsic::emitCodeGenSwitchBody(raw_ostream &OS) const {
  if (!getIRName().empty())
    OS << "  ID = Intrinsic::riscv_" + getIRName() + ";\n";
  if (hasManualCodegen()) {
    OS << ManualCodegen;
    OS << "break;\n";
    return;
  }
  OS << "  IntrinsicTypes = {";
  ListSeparator LS;
  for (const auto &Idx : IntrinsicTypes) {
    if (Idx == -1)
      OS << LS << "ResultType";
    else
      OS << LS << "Ops[" << Idx << "]->getType()";
  }
  OS << "};\n";
  OS << "  break;\n";
}

void RVMatrixIntrinsic::emitMangledFuncDef(raw_ostream &OS) const {
  OS << "__rvm_overloaded"
     << " " << OutputType->getTypeStr() << " " << getName();
  if (isLoad())
    OS << OutputType->getLMUL();
  OS << "(";
  int subLMUL = 0;
  if (hasLMUL())
    subLMUL = 1;
  if (!InputTypes.empty()) {
    ListSeparator LS;
    for (unsigned i = 0; i < InputTypes.size() - subLMUL; ++i) {
      OS << LS << InputTypes[i]->getTypeStr() << " op" << i;
    }
  }
  OS << ") {\n  return __builtin_riscv_" << getName();
  if (getSuffix() != "")
    OS << "_" << getSuffix();
  OS << "(";
  if (!InputTypes.empty()) {
    ListSeparator LS;
    for (unsigned i = 0; i < InputTypes.size() - subLMUL; ++i)
      OS << LS << "op" << i;
  }
  if (hasLMUL())
    OS << ", " << InputTypes[0]->getLMULParam();
  OS << ");\n}\n";
}

void RVMatrixType::applyModifier(StringRef Transformer) {
  if (Transformer.empty())
    return;

  // Handle primitive type transformer
  auto PType = Transformer.back();
  switch (PType) {
  case 'e':
    Scale = 0;
    break;
  case 'v':
    Scale = LMUL * (64 / ElementBitwidth);
    break;
  case 'a':
    Scale = LMUL * (64 / ElementBitwidth);
    IsZmv = true;
    break;
  case 'w':
    ElementBitwidth *= 2;
    LMUL *= 2;
    Scale = LMUL * (64 / ElementBitwidth);
    break;
  case 'q':
    ElementBitwidth *= 4;
    LMUL *= 4;
    Scale = LMUL * (64 / ElementBitwidth);
    break;
  case '0':
    ScalarType = ScalarTypeKind::Void;
    break;
  case 'z':
    ScalarType = ScalarTypeKind::Size_t;
    break;
  case 't':
    ScalarType = ScalarTypeKind::Ptrdiff_t;
    break;
  case 'u':
    ScalarType = ScalarTypeKind::UnsignedLong;
    break;
  case 'l':
    ScalarType = ScalarTypeKind::SignedLong;
    break;
  default:
    PrintFatalError("Illegal primitive type transformers!");
  }
  Transformer = Transformer.drop_back();

  // Compute the remain type transformers
  for (char I : Transformer) {
    switch (I) {
    case 'P':
      if (IsConstant)
        PrintFatalError("'P' transformer cannot be used after 'C'");
      if (IsPointer)
        PrintFatalError("'P' transformer cannot be used twice");
      IsPointer = true;
      break;
    case 'C':
      if (IsConstant)
        PrintFatalError("'C' transformer cannot be used twice");
      IsConstant = true;
      break;
    case 'K':
      IsImmediate = true;
      break;
    case 'U':
      ScalarType = ScalarTypeKind::UnsignedInteger;
      break;
    case 'I':
      ScalarType = ScalarTypeKind::SignedInteger;
      break;
    case 'F':
      ScalarType = ScalarTypeKind::Float;
      break;
    case 'S':
      LMUL = 0;
      // Update ElementBitwidth need to update Scale too.
      Scale = 0;
      break;
    default:
      PrintFatalError("Illegal non-primitive type transformer!");
    }
  }
}

void RVMatrixType::applyBasicType() {
  switch (BT) {
  case 'c':
    ElementBitwidth = 8;
    ScalarType = ScalarTypeKind::SignedInteger;
    break;
  case 's':
    ElementBitwidth = 16;
    ScalarType = ScalarTypeKind::SignedInteger;
    break;
  case 'i':
    ElementBitwidth = 32;
    ScalarType = ScalarTypeKind::SignedInteger;
    break;
  case 'l':
    ElementBitwidth = 64;
    ScalarType = ScalarTypeKind::SignedInteger;
    break;
  case 'x':
    ElementBitwidth = 16;
    ScalarType = ScalarTypeKind::Float;
    break;
  case 'f':
    ElementBitwidth = 32;
    ScalarType = ScalarTypeKind::Float;
    break;
  case 'd':
    ElementBitwidth = 64;
    ScalarType = ScalarTypeKind::Float;
    break;
  default:
    PrintFatalError("Unhandled type code!");
  }
  assert(ElementBitwidth != 0 && "Bad element bitwidth!");
}

bool RVMatrixType::verifyType() const {
  if (ScalarType == Invalid)
    return false;
  if (isScalar())
    return true;
  if (!Scale.hasValue())
    return false;
  if (isFloat() && ElementBitwidth == 8)
    return false;
  unsigned V = Scale.getValue();
  switch (ElementBitwidth) {
  case 1:
  case 8:
    // Check Scale is 1,2,4,8,16,32,64
    return (V <= 64 && isPowerOf2_32(V));
  case 16:
    // Check Scale is 1,2,4,8,16,32
    return (V <= 32 && isPowerOf2_32(V));
  case 32:
    // Check Scale is 1,2,4,8,16
    return (V <= 16 && isPowerOf2_32(V));
  case 64:
    // Check Scale is 1,2,4,8
    return (V <= 8 && isPowerOf2_32(V));
  }
  return false;
}

void RVMatrixType::initBuiltinStr() {
  assert(isValid() && "RVMatrixType is invalid");
  switch (ScalarType) {
  case ScalarTypeKind::Void:
    BuiltinStr = "v";
    return;
  case ScalarTypeKind::Size_t:
    BuiltinStr = "z";
    if (IsImmediate)
      BuiltinStr = "I" + BuiltinStr;
    if (IsPointer)
      BuiltinStr += "*";
    return;
  case ScalarTypeKind::Ptrdiff_t:
    BuiltinStr = "Y";
    return;
  case ScalarTypeKind::UnsignedLong:
    BuiltinStr = "ULi";
    return;
  case ScalarTypeKind::SignedLong:
    BuiltinStr = "Li";
    return;
  case ScalarTypeKind::Boolean:
    assert(ElementBitwidth == 1);
    BuiltinStr += "b";
    break;
  case ScalarTypeKind::SignedInteger:
  case ScalarTypeKind::UnsignedInteger:
    switch (ElementBitwidth) {
    case 8:
      BuiltinStr += "c";
      break;
    case 16:
      BuiltinStr += "s";
      break;
    case 32:
      BuiltinStr += "i";
      break;
    case 64:
      BuiltinStr += "Wi";
      break;
    default:
      llvm_unreachable("Unhandled ElementBitwidth!");
    }
    if (isSignedInteger())
      BuiltinStr = "S" + BuiltinStr;
    else
      BuiltinStr = "U" + BuiltinStr;
    break;
  case ScalarTypeKind::Float:
    switch (ElementBitwidth) {
    case 16:
      BuiltinStr += "x";
      break;
    case 32:
      BuiltinStr += "f";
      break;
    case 64:
      BuiltinStr += "d";
      break;
    default:
      llvm_unreachable("Unhandled ElementBitwidth!");
    }
    break;
  default:
    llvm_unreachable("ScalarType is invalid!");
  }
  if (IsImmediate)
    BuiltinStr = "I" + BuiltinStr;
  if (isScalar()) {
    if (IsConstant)
      BuiltinStr += "C";
    if (IsPointer)
      BuiltinStr += "*";
    return;
  }
  unsigned int qn = IsZmv ? 1 : 16;
  BuiltinStr = "q" + utostr(Scale.getValue() * qn) + BuiltinStr;
  // Pointer to vector types. Defined for Zvlsseg load intrinsics.
  // Zvlsseg load intrinsics have pointer type arguments to store the loaded
  // vector values.
  if (IsPointer)
    BuiltinStr += "*";
}

void RVMatrixType::initTypeStr() {
  assert(isValid() && "RVMatrixType is invalid");

  if (IsConstant)
    Str += "const ";

  auto getTypeString = [&](StringRef TypeStr) {
    if (isScalar())
      return Twine(TypeStr + Twine(ElementBitwidth) + "_t").str();
    std::string Head = IsZmv ? "v" : "m";
    return Twine(Head + TypeStr + Twine(ElementBitwidth) + "m" +
                 std::to_string(LMUL) + "_t")
        .str();
  };

  switch (ScalarType) {
  case ScalarTypeKind::Void:
    Str = "void";
    return;
  case ScalarTypeKind::Size_t:
    Str = "size_t";
    if (IsPointer)
      Str += " *";
    return;
  case ScalarTypeKind::Ptrdiff_t:
    Str = "ptrdiff_t";
    return;
  case ScalarTypeKind::UnsignedLong:
    Str = "unsigned long";
    return;
  case ScalarTypeKind::SignedLong:
    Str = "long";
    return;
  case ScalarTypeKind::Boolean:
    if (isScalar())
      Str += "bool";
    else
      // Vector bool is special case, the formulate is
      // `vbool<N>_t = MVT::nxv<64/N>i1` ex. vbool16_t = MVT::4i1
      Str += "vbool" + utostr(64 / Scale.getValue()) + "_t";
    break;
  case ScalarTypeKind::Float:
    if (isScalar()) {
      if (ElementBitwidth == 64)
        Str += "double";
      else if (ElementBitwidth == 32)
        Str += "float";
      else if (ElementBitwidth == 16)
        Str += "_Float16";
      else
        llvm_unreachable("Unhandled floating type.");
    } else
      Str += getTypeString("float");
    break;
  case ScalarTypeKind::SignedInteger:
    Str += getTypeString("int");
    break;
  case ScalarTypeKind::UnsignedInteger:
    Str += getTypeString("uint");
    break;
  default:
    llvm_unreachable("ScalarType is invalid!");
  }
  if (IsPointer)
    Str += " *";
}

void RVMatrixType::initShortStr() {
  switch (ScalarType) {
  case ScalarTypeKind::Boolean:
    assert(isVector());
    ShortStr = "b" + utostr(64 / Scale.getValue());
    return;
  case ScalarTypeKind::Float:
    ShortStr = "f" + utostr(ElementBitwidth);
    break;
  case ScalarTypeKind::SignedInteger:
    ShortStr = "i" + utostr(ElementBitwidth);
    break;
  case ScalarTypeKind::UnsignedInteger:
    ShortStr = "u" + utostr(ElementBitwidth);
    break;
  default:
    PrintFatalError("Unhandled case!");
  }
  if (isVector())
    ShortStr = ShortStr + "m" + std::to_string(LMUL);
}

RVMatrixType::RVMatrixType(BasicType BT, int LMUL, StringRef prototype)
    : BT(BT), LMUL(LMUL) {
  applyBasicType();
  applyModifier(prototype);
  Valid = verifyType();
  if (Valid) {
    initBuiltinStr();
    initTypeStr();
  }
}

int RVMatrixType::getLMULParam() {
  if (LMUL == 1)
    return 0;
  else if (LMUL == 2)
    return 1;
  else if (LMUL == 4)
    return 2;

  // default return m0
  return 3;
}

Optional<RVMatrixTypes>
RVMatrixEmitter::computeTypes(BasicType BT, int LMUL,
                              ArrayRef<std::string> PrototypeSeq) {
  RVMatrixTypes Types;
  for (const std::string &Proto : PrototypeSeq) {
    auto T = computeType(BT, LMUL, Proto);
    if (!T.hasValue())
      return llvm::None;
    // Record legal type index
    Types.push_back(T.getValue());
  }
  return Types;
}

Optional<RVMatrixTypePtr> RVMatrixEmitter::computeType(BasicType BT, int LMUL,
                                                       StringRef Proto) {
  std::string Idx = Twine(Twine(BT) + Twine(LMUL) + Proto).str();
  // Search first
  auto It = LegalTypes.find(Idx);
  if (It != LegalTypes.end())
    return &(It->second);
  if (IllegalTypes.count(Idx))
    return llvm::None;
  // Compute type and record the result.
  RVMatrixType T(BT, LMUL, Proto);
  if (T.isValid()) {
    // Record legal type index and value.
    LegalTypes.insert({Idx, T});
    return &(LegalTypes[Idx]);
  }
  // Record illegal type index.
  IllegalTypes.insert(Idx);
  return llvm::None;
}

void RVMatrixEmitter::parsePrototypes(StringRef Prototypes,
                                      std::function<void(StringRef)> Handler) {
  const StringRef Primaries("evawqom0ztul");
  while (!Prototypes.empty()) {
    size_t Idx = 0;
    // Skip over complex prototype because it could contain primitive type
    // character.
    if (Prototypes[0] == '(')
      Idx = Prototypes.find_first_of(')');
    Idx = Prototypes.find_first_of(Primaries, Idx);
    assert(Idx != StringRef::npos);
    Handler(Prototypes.slice(0, Idx + 1));
    Prototypes = Prototypes.drop_front(Idx + 1);
  }
}

std::string RVMatrixEmitter::getSuffixStr(char Type, int LMUL,
                                          StringRef Prototypes) {
  SmallVector<std::string> SuffixStrs;
  parsePrototypes(Prototypes, [&](StringRef Proto) {
    auto T = computeType(Type, LMUL, Proto);
    SuffixStrs.push_back(T.getValue()->getShortStr());
  });
  return join(SuffixStrs, "_");
}

void RVMatrixEmitter::createRVMatrixIntrinsics(
    std::vector<std::unique_ptr<RVMatrixIntrinsic>> &Out) {
  std::vector<Record *> RV =
      Records.getAllDerivedDefinitions("RISCVMatrixBuiltin");
  for (auto *R : RV) {
    StringRef Name = R->getValueAsString("Name");
    StringRef Suffix = R->getValueAsString("Suffix");
    StringRef TypeRange = R->getValueAsString("TypeRange");
    StringRef Prototypes = R->getValueAsString("Prototype");
    std::vector<int64_t> LMULList = R->getValueAsListOfInts("LMUL");
    StringRef ManualCodegen = R->getValueAsString("ManualCodegen");
    std::vector<int64_t> IntrinsicTypes =
        R->getValueAsListOfInts("IntrinsicTypes");
    StringRef IRName = R->getValueAsString("IRName");
    StringRef HeaderCodeStr = R->getValueAsString("HeaderCode");
    bool HasSideEffects = R->getValueAsBit("HasSideEffects");
    bool HasLMUL = R->getValueAsBit("HasLMUL");
    bool IsLoad = R->getValueAsBit("IsLoad");

    if (!HeaderCodeStr.empty()) {
      HeaderCode += HeaderCodeStr.str();
    }

    // Parse prototype and create a list of primitive type with transformers
    // (operand) in ProtoSeq. ProtoSeq[0] is output operand.
    SmallVector<std::string> ProtoSeq;
    parsePrototypes(Prototypes, [&ProtoSeq](StringRef Proto) {
      ProtoSeq.push_back(Proto.str());
    });

    // Create Intrinsics for each type and LMUL.
    for (char I : TypeRange) {
      for (int LMUL : LMULList) {
        Optional<RVMatrixTypes> Types = computeTypes(I, LMUL, ProtoSeq);
        StringRef SuffixStr = getSuffixStr(I, LMUL, Suffix);
        Out.push_back(std::make_unique<RVMatrixIntrinsic>(
            Name, SuffixStr, IRName, HasSideEffects, HasLMUL, IsLoad,
            ManualCodegen, Types.getValue(), IntrinsicTypes));
      }
    }
  }

  return;
}

std::string RVMatrixIntrinsic::getBuiltinTypeStr() const {
  std::string S;
  S += OutputType->getBuiltinStr();
  for (const auto &T : InputTypes) {
    S += T->getBuiltinStr();
  }
  return S;
}

void RVMatrixEmitter::createBuiltins(raw_ostream &OS) {
  std::vector<std::unique_ptr<RVMatrixIntrinsic>> Defs;
  createRVMatrixIntrinsics(Defs);

  for (auto &Def : Defs) {
    OS << "TARGET_BUILTIN(__builtin_riscv_" << Def->getName();
    
    if (Def->getSuffix() != "")
      OS << "_" << Def->getSuffix();
    OS << ",\"" << Def->getBuiltinTypeStr() << "\", ";
    if (!Def->hasSideEffects())
      OS << "\"n\", \"experimental-matrix\")\n";
    else
      OS << "\"\", \"experimental-matrix\")\n";
  }
}

void RVMatrixEmitter::createHeader(raw_ostream &OS) {
  OS << "/* riscv_matrix.h - RISC-V Matrix-extension Intrinsics */\n\n";

  OS << "#ifndef __RISCV_MATRIX_H\n";
  OS << "#define __RISCV_MATRIX_H\n\n";

  OS << "#include <stdint.h>\n";
  OS << "#include <stddef.h>\n\n";

  OS << "#ifndef __riscv_matrix\n";
  OS << "#error \"Matrix intrinsics require the matrix extension.\"\n";
  OS << "#endif\n\n";

  OS << "#define __rvm_overloaded static inline "
        "__attribute__((__always_inline__, __nodebug__, __overloadable__))\n\n";

  OS << "#ifndef __RISCV_VECTOR_H\n";
  OS << "typedef __rvv_int8m1_t vint8m1_t;\n";
  OS << "typedef __rvv_uint8m1_t vuint8m1_t;\n";
  OS << "typedef __rvv_int16m1_t vint16m1_t;\n";
  OS << "typedef __rvv_uint16m1_t vuint16m1_t;\n";
  OS << "typedef __rvv_int32m1_t vint32m1_t;\n";
  OS << "typedef __rvv_uint32m1_t vuint32m1_t;\n";
  OS << "typedef __rvv_int64m1_t vint64m1_t;\n";
  OS << "typedef __rvv_uint64m1_t vuint64m1_t;\n";
  OS << "typedef __rvv_float16m1_t vfloat16m1_t;\n";
  OS << "typedef __rvv_float32m1_t vfloat32m1_t;\n";
  OS << "typedef __rvv_float64m1_t vfloat64m1_t;\n";

  OS << "typedef __rvv_int8m2_t vint8m2_t;\n";
  OS << "typedef __rvv_uint8m2_t vuint8m2_t;\n";
  OS << "typedef __rvv_int16m2_t vint16m2_t;\n";
  OS << "typedef __rvv_uint16m2_t vuint16m2_t;\n";
  OS << "typedef __rvv_int32m2_t vint32m2_t;\n";
  OS << "typedef __rvv_uint32m2_t vuint32m2_t;\n";
  OS << "typedef __rvv_int64m2_t vint64m2_t;\n";
  OS << "typedef __rvv_uint64m2_t vuint64m2_t;\n";
  OS << "typedef __rvv_float16m2_t vfloat16m2_t;\n";
  OS << "typedef __rvv_float32m2_t vfloat32m2_t;\n";
  OS << "typedef __rvv_float64m2_t vfloat64m2_t;\n";

  OS << "typedef __rvv_int8m4_t vint8m4_t;\n";
  OS << "typedef __rvv_uint8m4_t vuint8m4_t;\n";
  OS << "typedef __rvv_int16m4_t vint16m4_t;\n";
  OS << "typedef __rvv_uint16m4_t vuint16m4_t;\n";
  OS << "typedef __rvv_int32m4_t vint32m4_t;\n";
  OS << "typedef __rvv_uint32m4_t vuint32m4_t;\n";
  OS << "typedef __rvv_int64m4_t vint64m4_t;\n";
  OS << "typedef __rvv_uint64m4_t vuint64m4_t;\n";
  OS << "typedef __rvv_float16m4_t vfloat16m4_t;\n";
  OS << "typedef __rvv_float32m4_t vfloat32m4_t;\n";
  OS << "typedef __rvv_float64m4_t vfloat64m4_t;\n";
  OS << "#endif\n\n";

  OS << "typedef __rvv_int8m16_t mint8m1_t;\n";
  OS << "typedef __rvv_uint8m16_t muint8m1_t;\n";
  OS << "typedef __rvv_int16m16_t mint16m1_t;\n";
  OS << "typedef __rvv_uint16m16_t muint16m1_t;\n";
  OS << "typedef __rvv_int32m16_t mint32m1_t;\n";
  OS << "typedef __rvv_uint32m16_t muint32m1_t;\n";
  OS << "typedef __rvv_int64m16_t mint64m1_t;\n";
  OS << "typedef __rvv_uint64m16_t muint64m1_t;\n";
  OS << "typedef __rvv_float16m16_t mfloat16m1_t;\n";
  OS << "typedef __rvv_float32m16_t mfloat32m1_t;\n";
  OS << "typedef __rvv_float64m16_t mfloat64m1_t;\n";

  OS << "typedef __rvv_int8m32_t mint8m2_t;\n";
  OS << "typedef __rvv_uint8m32_t muint8m2_t;\n";
  OS << "typedef __rvv_int16m32_t mint16m2_t;\n";
  OS << "typedef __rvv_uint16m32_t muint16m2_t;\n";
  OS << "typedef __rvv_int32m32_t mint32m2_t;\n";
  OS << "typedef __rvv_uint32m32_t muint32m2_t;\n";
  OS << "typedef __rvv_int64m32_t mint64m2_t;\n";
  OS << "typedef __rvv_uint64m32_t muint64m2_t;\n";
  OS << "typedef __rvv_float16m32_t mfloat16m2_t;\n";
  OS << "typedef __rvv_float32m32_t mfloat32m2_t;\n";
  OS << "typedef __rvv_float64m32_t mfloat64m2_t;\n";

  OS << "typedef __rvv_int8m64_t mint8m4_t;\n";
  OS << "typedef __rvv_uint8m64_t muint8m4_t;\n";
  OS << "typedef __rvv_int16m64_t mint16m4_t;\n";
  OS << "typedef __rvv_uint16m64_t muint16m4_t;\n";
  OS << "typedef __rvv_int32m64_t mint32m4_t;\n";
  OS << "typedef __rvv_uint32m64_t muint32m4_t;\n";
  OS << "typedef __rvv_int64m64_t mint64m4_t;\n";
  OS << "typedef __rvv_uint64m64_t muint64m4_t;\n";
  OS << "typedef __rvv_float16m64_t mfloat16m4_t;\n";
  OS << "typedef __rvv_float32m64_t mfloat32m4_t;\n";
  OS << "typedef __rvv_float64m64_t mfloat64m4_t;\n";
  OS << "\n";

  std::vector<std::unique_ptr<RVMatrixIntrinsic>> Defs;
  createRVMatrixIntrinsics(Defs);

  // Print header code
  if (!HeaderCode.empty()) {
    OS << HeaderCode;
  }

  for (auto &Def : Defs) {
    Def->emitMangledFuncDef(OS);
  }

  OS << "#endif // __RISCV_MATRIX_H\n";
}

void RVMatrixEmitter::createCodeGen(raw_ostream &OS) {
  std::vector<std::unique_ptr<RVMatrixIntrinsic>> Defs;
  createRVMatrixIntrinsics(Defs);
  // IR name could be empty, use the stable sort preserves the relative order.
  std::stable_sort(Defs.begin(), Defs.end(),
                   [](const std::unique_ptr<RVMatrixIntrinsic> &A,
                      const std::unique_ptr<RVMatrixIntrinsic> &B) {
                     return A->getIRName() < B->getIRName();
                   });

  // Print switch body when the ir name or ManualCodegen changes from previous
  // iteration.
  RVMatrixIntrinsic *PrevDef = Defs.begin()->get();
  for (auto &Def : Defs) {
    StringRef CurIRName = Def->getIRName();
    if (CurIRName != PrevDef->getIRName() ||
        (Def->getManualCodegen() != PrevDef->getManualCodegen())) {
      PrevDef->emitCodeGenSwitchBody(OS);
    }
    PrevDef = Def.get();
    OS << "case RISCV::BI__builtin_riscv_" << Def->getName();
    if (Def->getSuffix() != "")
      OS << "_" << Def->getSuffix();
    OS << ":\n";
  }
  Defs.back()->emitCodeGenSwitchBody(OS);
  OS << "\n";
}

namespace clang {
void EmitRVMatrixHeader(RecordKeeper &Records, raw_ostream &OS) {
  RVMatrixEmitter(Records).createHeader(OS);
}

void EmitRVMatrixBuiltins(RecordKeeper &Records, raw_ostream &OS) {
  RVMatrixEmitter(Records).createBuiltins(OS);
}

void EmitRVMatrixBuiltinCG(RecordKeeper &Records, raw_ostream &OS) {
  RVMatrixEmitter(Records).createCodeGen(OS);
}
} // namespace clang
