#include <cstdlib>
#include <cctype>
#include <iostream>

#include "debug.h"
#include "token.h"
#include "tokenization.h"

Tokenizer::Tokenizer(std::string str):
    m_src(std::move(str))
    {}

std::vector<Token> Tokenizer::tokenize() {

  std::vector<Token> tokens;
  std::string buf;
  int val = 0;
  while (peek().has_value()) {
    if (std::isalpha(peek().value()) || peek().value() == ';') {
      buf.push_back(consume());
      while (peek().has_value() && std::isalnum(peek().value())) {
        buf.push_back(consume());
      }

      if (buf == "exit") {
        DBG_PRINT("got exit")
        tokens.push_back({ .type = TokenType::tt_exit, .value = buf });
        buf.clear();
      }
      else if (buf == "return") {
        DBG_PRINT("got return")
        tokens.push_back({ .type = TokenType::tt_return, .value = buf });
        buf.clear();
      }
      else if (buf == ";") {
        DBG_PRINT("got semi")
        tokens.push_back({ .type = TokenType::tt_semi, .value = buf });
        buf.clear();
      }
    }
    else if (std::isspace(peek().has_value())) {
        DBG_PRINT("got space")
        consume();
        buf.clear();
    }
    else if (std::isdigit(peek().value())) {
      buf.push_back(consume());
      while (peek().has_value() && std::isdigit(peek().value())) {
        buf.push_back(consume());
      }
      tokens.push_back({ .type = TokenType::tt_int, .value = buf});
      std::cout << "Got Int: " << buf << std::endl;
      buf.clear();
      continue;
    }
    else {
      DBG_PRINT("Unexpected.");
      exit(1); 
    }
  }
  return tokens;
}


std::optional<char> Tokenizer::peek(int ahead) const {
  if (m_index + ahead > m_src.length()) {
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