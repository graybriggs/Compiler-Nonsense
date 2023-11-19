#pragma once

#include <iostream>
#include <vector>

#include "token.h"


#define DBG_PRINT(msg) std::cout << msg << "\n"; 


void dbg_tokens(std::vector<Token>& tok);