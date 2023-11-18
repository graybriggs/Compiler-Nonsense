#pragma once

#include <cstdlib>
#include <iostream>
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
  inline explicit Tokenizer(std::string str):
    m_src(std::move(str))
    {}


  inline std::vector<Token> tokenize() {
    std::vector<Token> tokens;

    std::string buf;
    while (peek().has_value()) {
      if (std::isalpha(peek().value())) {
        buf.push_back(consume());
        while (peek().has_value() && std::isalnum(peek().value())) {
          buf.push_back(consume());
        }
        
        if (buf == "exit") {
          std::cout << "got exit" << std::endl;
          tokens.push_back({ .type = TokenType::tt_exit, .value = buf });
          buf.clear();
          continue;
        }
        else if (buf == "return") {
          std::cout << "got return" << std::endl;
          tokens.push_back({ .type = TokenType::tt_return, .value = buf });
          continue;
        }
        else if (buf == ";") {
          std::cout << "got semicolon\n" << std::endl;
          tokens.push_back({ .type = TokenType::tt_semi, .value = buf });
          buf.clear();
          continue;
        }
        else if (std::isspace(peek().has_value())) {
          continue;
        }
        else {
          std::cerr << "Error" << std::endl;
          exit(EXIT_FAILURE);
        }
      }
    }

    return tokens;
  }

private:
  std::optional<char> peek(int ahead = 1) const {
    if (m_index + ahead >= m_src.length()) {
      return {};
    }
    else {
      return m_src.at(m_index);
    }
  }

  char consume() {
    char c = m_src.at(m_index);
    std::cout << c << "\n";
    ++m_index;
    return c;
  }

  std::string m_src;
  int m_index;
};