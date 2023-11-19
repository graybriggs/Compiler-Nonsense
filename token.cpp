
#include "token.h"

const char* token_name(TokenType tt) {
  switch (tt) {
    case TokenType::tt_return: return "return";
    case TokenType::tt_exit: return "exit";
    case TokenType::tt_int: return "int";
    case TokenType::tt_if: return "if";
    case TokenType::tt_else: return "else";
    case TokenType::tt_while: return "while";
    case TokenType::tt_semi: return "semi-colon";
    default: return "none";
  }
}