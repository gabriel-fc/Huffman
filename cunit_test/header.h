//
// Created by Pedro on 25/09/2017.
//

#ifndef HUFFMAN_HEADER_H
#define HUFFMAN_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CHAR_SIZE 256
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

void PrintHeader(int trash_size, int tree_size, FILE* compressed_file);

int IsBitiSet(byte file_byte, int i);

byte SetBiti(byte file_byte, int i);

/*
 * Gets and Sets for 'struct Frequency'.
 */
long long int GetTotalFrequency(frequency* frequency);
long long int GetCharFrequencyElement(frequency* frequency, int index);
#endif