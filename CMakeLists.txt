cmake_minimum_required(VERSION 3.5)

project(so-trab-1 VERSION 0.1 LANGUAGES C)

# FILE(GLOB SOURCE_FILES src/*.c)

include_directories(include)
add_executable(
  matrix-mult
  src/sequencial.c)

set(CMAKE_CXX_FLAGS "-Wall -g -fsanitize=address -lm")
