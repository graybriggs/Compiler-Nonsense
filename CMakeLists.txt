
cmake_minimum_required(VERSION 3.20)

project(compiler-nonsense)

set(CMAKE_CXX_STANDARD 20)

add_executable(test main.cpp tokenization.cpp tokenization.h)

