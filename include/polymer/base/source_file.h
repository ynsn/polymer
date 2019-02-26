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

#ifndef POLYMER_SOURCE_FILE_H
#define POLYMER_SOURCE_FILE_H

namespace polymer {

/// SourceFile - Represents a file containing source code. This currently only handles and owns MemoryBuffers for
/// each file, and will be extended in the future to do more source-file related things.
class SourceFile {
  // TODO Write documentation for methods
private:
  /// Unique pointer to a memory buffer containing the file contents.
  std::unique_ptr<llvm::MemoryBuffer> buffer;

public:
  explicit SourceFile(std::unique_ptr<llvm::MemoryBuffer> buffer);
  ~SourceFile();

  const char *getSource() const;
  const char *getSourceEnd() const;
  const int getSourceSize() const;
  llvm::StringRef getSourceRef() const;

  static llvm::Expected<std::unique_ptr<polymer::SourceFile>> Open(llvm::StringRef name);
};

}

#endif //POLYMER_SOURCE_FILE_H
