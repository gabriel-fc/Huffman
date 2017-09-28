//
// Created by Pedro on 27/09/2017.
//

#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct HuffTree hufftree;
typedef struct Node node;

hufftree* CreateNewHuffTree();
node* CreateHuffTreeNode(void* element, int frequency);
void TreeListAdd(hufftree* hufftree, node* add_node);
void CreateTreeList(hufftree* hufftree, frequency* frequency);
hufftree* MakeTreeFromPreOrder(char* pre_order);

#endif //HUFFMAN_HUFFMANTREE_H
