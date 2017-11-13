//
// Created by pedro on 11/10/2017.
//

#ifndef HUFFMAN_CHARPATH_H
#define HUFFMAN_CHARPATH_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "huffmantree.h"

typedef unsigned char byte;
typedef struct CharData chardata;
typedef struct CharHash charhash;

/*
 * Allocate an 'struct CharHash', initialize all struct content and returns the pointer to the new 'charhash'.
 */
charhash* CreateEmptyCharHash();
/*
 * Allocate an 'struct CharData', initialize all struct content and returns the pointer to the new 'chardata'.
 */
chardata* CreateCharData(unsigned char id, int path_size);
void printHash(charhash* charhash);
/*
 * The function traverses the entire huffman tree and map to the hash the corresponding path of each leaf in the binary format.
 */
void MapCharPaths(charhash* charhash, node* root, int buffer_position, char bit);
/*
 * Calculate the size of the trash from the final byte of the compressed file.
 */
int TrashSize(frequency* file_frequency, charhash* file_charhash);
/*
 * Gets and Sets for 'struct CharHash' and 'struct CharData'.
 */
int GetCharDataPathSize(chardata* chardata);
byte GetCharDataId(chardata* chardata);
char* GetCharDataPath(chardata* chardata);
void* GetCharHashDataElement(charhash* charhash, int index);
#endif