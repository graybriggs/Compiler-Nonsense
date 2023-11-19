#pragma once

#include <optional>
#include <string>
#include <vector>

enum class TokenType {
  tt_return,
  tt_int,
  tt_if,
  tt_else,
  tt_while,
  tt_semi,
  tt_keyword,
  tt_exit
};

struct Token {
  TokenType type;
  std::optional<std::string> value {};
};

class Tokenizer {
public:
  Tokenizer(std::string str);

  std::vector<Token> tokenize();

private:
  std::optional<char> peek(int ahead = 1) const;
  char consume();

  std::string m_src;
  int m_index;
};