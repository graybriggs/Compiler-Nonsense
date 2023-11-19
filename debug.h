#pragma once

#include <iostream>
#include <vector>

#include "token.h"

void dbg_tokens(std::vector<Token>& tok) {

  for (auto t : tok) {
    std::cout << token_name(t.type) << std::endl;
  }
}