#pragma once

#include <optional>
#include <string>

enum class TokenType {
  tt_return,
  tt_exit,
  tt_int,
  tt_if,
  tt_else,
  tt_while,
  tt_semi,
  tt_keyword
};

struct Token {
  TokenType type;
  std::optional<std::string> value {};
};

const char* token_name(TokenType);
