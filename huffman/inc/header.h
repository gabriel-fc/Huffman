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

/*
 * Allocates and initializes a 'struct Frequency'(frequency);
 * Returns a pointer(frequency*) to the new struct.
 */
frequency* CreateEmptyFrequency();

/*
 * Read the file bytes in blocks of 'BUFFER_SIZE' bytes and count in the table(frequency).
 */
void GetBytesFrequency(FILE* read_file, frequency* frequency);


//Gets and Sets for 'struct Frequency'
int GetTotalFrequency(frequency* frequency);
int GetCharFrequencyElement(frequency* frequency, int index);
#endif //HUFFMAN_HEADER_H
