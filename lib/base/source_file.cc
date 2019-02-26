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

namespace polymer {

/// ====== Implement class SourceFile ====== ///

SourceFile::SourceFile(std::unique_ptr<llvm::MemoryBuffer> buffer) : buffer(std::move(buffer)) {}

SourceFile::~SourceFile() {}

const char *SourceFile::getSource() const {
  return buffer->getBufferStart();
}

const char *SourceFile::getSourceEnd() const {
  return buffer->getBufferEnd();
}

const int SourceFile::getSourceSize() const {
  return buffer->getBufferSize();
}

llvm::StringRef SourceFile::getSourceRef() const {
  return buffer->getBuffer();
}

llvm::Expected<std::unique_ptr<polymer::SourceFile>> SourceFile::Open(llvm::StringRef path) {
  auto buffer = llvm::MemoryBuffer::getFileOrSTDIN(path);
  if (!buffer) {
    return llvm::make_error<llvm::StringError>(llvm::Twine("could not find or open file \"").concat(path).concat("\"."),
                                               std::error_code(-1, std::generic_category()));
  } else {
    std::unique_ptr<SourceFile> file = llvm::make_unique<SourceFile>(std::move(buffer.get()));
    return file;
  }
}

}
