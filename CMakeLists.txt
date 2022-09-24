cmake_minimum_required(VERSION 3.5)

project(so-trab-1 VERSION 0.1 LANGUAGES C)

include_directories(include)

file( GLOB LIB_SOURCES src/*.c )
file( GLOB LIB_HEADERS include/*.h )
add_library( libs ${LIB_SOURCES} ${LIB_HEADERS} )

add_executable( seq src/sequencial.c )
target_link_libraries( seq libs )
add_executable( aux src/auxiliate.c )
target_link_libraries( aux libs )

set(CMAKE_CXX_FLAGS "-Wall -g -fsanitize=address -lm")
