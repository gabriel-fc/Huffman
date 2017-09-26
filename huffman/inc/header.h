//
// Created by Pedro on 25/09/2017.
//

#ifndef HUFFMAN_HEADER_H
#define HUFFMAN_HEADER_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_SIZE 257
#define BUFFER_SIZE 1024

typedef unsigned char byte;
typedef struct Frequency frequency;

frequency* CreateEmptyFrequency();
void GetBytesFrequency(FILE* read_file, frequency* frequency);

#endif //HUFFMAN_HEADER_H
