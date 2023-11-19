#include <cstdlib>
#include <iostream>

#include "tokenization.h"

Tokenizer::Tokenizer(std::string str):
    m_src(std::move(str))
    {}


std::vector<Token> Tokenizer::tokenize() {

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
std::optional<char> Tokenizer::peek(int ahead) const {
  if (m_index + ahead >= m_src.length()) {
    return {};
  }
  else {
    return m_src.at(m_index);
  }
}

char Tokenizer::consume() {
  char c = m_src.at(m_index);
  std::cout << c << "\n";
  ++m_index;
  return c;
}