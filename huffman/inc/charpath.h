//
// Created by pedro on 11/10/2017.
//

#ifndef HUFFMAN_CHARPATH_H
#define HUFFMAN_CHARPATH_H

#include <stdlib.h>
#include <string.h>
#include "huffmantree.h"
#include <stdio.h>

#define BUFFER_SIZE 256

typedef unsigned char byte;
typedef struct CharData chardata;
typedef struct CharHash charhash;

charhash* CreateEmptyCharHash();
chardata* CreateCharData(unsigned char id, char* path, int path_size);
void MapCharPaths(charhash* charhash, node* root, int buffer_position, char bit);
void PrintCharData(chardata* chardata);
void PrintCharHash(charhash* charhash);

#endif //HUFFMAN_CHARPATH_H
