cmake_minimum_required(VERSION 3.8)
project(test_tad)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c src/header.c src/charpath.c src/huffmantree.c inc/header.h inc/charpath.h inc/huffmantree.h)
add_executable(test_tad ${SOURCE_FILES})
include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(test_tad cunit)