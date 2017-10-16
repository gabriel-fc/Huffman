//
// Created by pedro on 11/10/2017.
//

#ifndef HUFFMAN_CHARPATH_H
#define HUFFMAN_CHARPATH_H

#include <stdlib.h>
#include "huffmantree.h"
#include <stdio.h>

typedef struct CharData chardata;
typedef struct CharHash charhash;

charhash* CreateEmptyCharHash();
chardata* CreateCharData(unsigned char id, char* path, int path_size);

#endif //HUFFMAN_CHARPATH_H
