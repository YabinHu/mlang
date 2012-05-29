//===--- BackendUtil.h - LLVM Backend Utilities -----------------*- C++ -*-===//
//
// Copyright (C) 2010 yabin @ CGCL
// HuaZhong University of Science and Technology, China
//
//===----------------------------------------------------------------------===//

#ifndef MLANG_CODEGEN_BACKEND_UTIL_H_
#define MLANG_CODEGEN_BACKEND_UTIL_H_

namespace llvm {
  class Module;
  class raw_ostream;
}

namespace mlang {
  class Diagnostic;
  class CodeGenOptions;
  class TargetOptions;
  
  enum BackendAction {
    Backend_EmitAssembly,  ///< Emit native assembly files
    Backend_EmitBC,        ///< Emit LLVM bitcode files
    Backend_EmitLL,        ///< Emit human-readable LLVM assembly
    Backend_EmitNothing,   ///< Don't emit anything (benchmarking mode)
    Backend_EmitMCNull,    ///< Run CodeGen, but don't emit anything
    Backend_EmitObj        ///< Emit native object files
  };
  
  void EmitBackendOutput(Diagnostic &Diags, const CodeGenOptions &CGOpts,
                         const TargetOptions &TOpts, llvm::Module *M,
                         BackendAction Action, llvm::raw_ostream *OS);
}

#endif /* MLANG_CODEGEN_BACKEND_UTIL_H_ */
