/**
 * Copyright 2019 Polymer developers
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "polymer/polymer.h"

static llvm::cl::opt<std::string> InputFile(llvm::cl::Positional,
                                            llvm::cl::desc("<source file>"),
                                            llvm::cl::value_desc("source file"),
                                            llvm::cl::init("-"),
                                            llvm::cl::ZeroOrMore);

static llvm::cl::list<std::string> Args(llvm::cl::ConsumeAfter, llvm::cl::desc("<args...>"));

int main(int argc, char **argv) {
  llvm::cl::ParseCommandLineOptions(argc, argv, "Polymer");
  llvm::llvm_shutdown_obj Y;
  polymer::Initialize();

  if (!InputFile.empty() && InputFile.getValue() != "-") {
    llvm::Expected<std::unique_ptr<polymer::SourceFile>> inputFile = polymer::SourceFile::Open(InputFile.getValue());
    if (!inputFile) {
      llvm::logAllUnhandledErrors(inputFile.takeError(), llvm::errs(), "Input error: ");
      return -1;
    }

    // TODO Parse the file and start executing it...
  } else {
    // Start REPL
    // TODO Implement REPL
  }
}

