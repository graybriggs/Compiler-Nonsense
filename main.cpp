#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "tokenization.h"

int main(int argc, char* argv[]) {

  if (argc != 2) {
    std::cout << "Usage: <program> <file>\n";
    return 1;
  }

  std::string contents;
  {
    std::fstream fs(argv[1], std::ios::in);
    std::stringstream ss;
    ss << fs.rdbuf();
    contents = ss.str();
  }

  Tokenizer tokenizer(std::move(contents));
  tokenizer.tokenize();
  
  //std::cout << contents << "\n";
  return 0;
}