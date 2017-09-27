cmake_minimum_required(VERSION 3.7.1)
project(huffman)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES huffman/main.c huffman/src/header.c huffman/src/huffmantree.c)
add_executable(huffman ${SOURCE_FILES})