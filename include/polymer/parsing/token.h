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

#ifndef POLYMER_TOKEN_H
#define POLYMER_TOKEN_H

namespace polymer {

/// TokenKind - Defines the numerous types of token kinds.
typedef enum TokenKind {
  None,
  EndOfFile
} TokenKind;

/// Get the name of the TokenKind.
/// \param kind kind to get name for
/// \return StringRef containing the kind name
llvm::StringRef GetTokenKindName(const TokenKind &kind);

/// Token - Represents a lexical token with an associated meaning and value.
struct Token {
  /// The kind of the token.
  const TokenKind kTokenKind;

  /// The token value.
  const std::string kTokenValue;

  /// Start position of the token in the source.
  const llvm::SMLoc kStartLoc;

  /// End position of the token in the source
  const llvm::SMLoc kEndLoc;

  Token(const TokenKind &kind, std::string value, llvm::SMLoc startLoc, llvm::SMLoc endLoc);

  /// Check if the token is of a specified kind.
  /// \param kind kind of the token to check for
  /// \return true if this token is of kind, false otherwise
  bool is(const TokenKind &kind) const;

  /// Inverse of Token::is(TokenKind)
  /// \param kind kind of the token to check for
  /// \return false if this token is of kind, true otherwise
  bool isNot(const TokenKind &kind) const;
};

}

#endif //POLYMER_TOKEN_H
