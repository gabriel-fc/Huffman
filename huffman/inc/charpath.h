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

/*
 * Allocate an 'struct CharHash', initialize all struct content and returns the pointer to the new 'charhash'.
 */
charhash* CreateEmptyCharHash();
/*
 * Allocate an 'struct CharData', initialize all struct content and returns the pointer to the new 'chardata'.
 */
chardata* CreateCharData(unsigned char id, int path_size);
/*
 * The function traverses the entire huffman tree and map to the hash the corresponding path of each leaf in the binary format.
 */
void MapCharPaths(charhash* charhash, node* root, int buffer_position, char bit);

#endif //HUFFMAN_CHARPATH_H
