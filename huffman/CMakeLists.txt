cmake_minimum_required(VERSION 3.8)
project(huffman)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c inc/header.h src/header.c src/huffmantree.c inc/huffmantree.h src/charpath.c inc/charpath.h)
add_executable(huffman ${SOURCE_FILES})
target_link_libraries(huffman m)