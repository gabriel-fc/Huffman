cmake_minimum_required(VERSION 3.8)
project(plot)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c ../src/binary_tree.c ../src/linked_list.c ../inc/binary_tree.h ../inc/linked_list.h)
add_executable(plot ${SOURCE_FILES})
add_library(binary_tree.h ${SOURCE_FILES})
add_library(linked_list.h ${SOURCE_FILES})