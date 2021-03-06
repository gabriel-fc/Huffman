//
// Created by karen on 15/11/17.
//

#ifndef HUFFMAN_HEADER_H
#define HUFFMAN_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CHAR_SIZE 257
#define BUFFER_SIZE 1024

typedef unsigned char byte;
typedef struct Frequency frequency;
int trash;

/*
 * Allocates and initializes a 'struct Frequency'(frequency);
 * Returns a pointer(frequency*) to the new struct.
 */
frequency* CreateEmptyFrequency();

/*
 * Read the file bytes in blocks of 'BUFFER_SIZE' bytes and count in the table(frequency).
 */
void GetBytesFrequency(FILE* read_file, frequency* frequency);
/*
 * Take the binary number in the array and return the correspondent integer.
 */
int BinaryToInteger(short binary_number[], int bits);

void PrintHeader(int trash_size, int tree_size, FILE* compressed_file);

int IsBitiSet(byte file_byte, int i);

byte SetBiti(byte file_byte, int i);

/*
 * Gets and Sets for 'struct Frequency'.
 */
long long int GetTotalFrequency(frequency* frequency);
long long int GetCharFrequencyElement(frequency* frequency, int index);

int HeaderRead(FILE* read_file);
int is_bit_i_set(unsigned char c, int i);

#endif //HUFFMAN_HEADER_H
