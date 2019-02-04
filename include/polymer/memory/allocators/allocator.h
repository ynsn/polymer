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

#ifndef POLYMER_ALLOCATOR_H
#define POLYMER_ALLOCATOR_H

namespace polymer {

/// Allocator - Pure virtual base class that provides a common interface to a Polymer allocator.
/// \tparam T type that the allocator allocates
template<typename T>
class Allocator {
public:
  /// Allocates a specified amount of bytes.
  /// \param size size in bytes to allocate
  /// \return pointer to allocated memory
  virtual T *allocate(size_t size) = 0;

  /// Deallocates memory.
  /// \param dealloc memory to deallocate
  virtual void deallocate(T *dealloc) = 0;
};

}

#endif //POLYMER_ALLOCATOR_H
