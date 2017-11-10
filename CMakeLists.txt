cmake_minimum_required(VERSION 3.7.1)
project(huffman)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES huffman/main.c huffman/src/header.c huffman/src/huffmantree.c huffman/src/charpath.c huffman/inc/charpath.h huffman/inc/huffmantree.h huffman/inc/header.h)
add_executable(huffman ${SOURCE_FILES})