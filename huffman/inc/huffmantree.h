//
// Created by Pedro on 27/09/2017.
//

#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
typedef struct HuffTree hufftree;

hufftree* CreateNewHuffTree();
node* CreateHuffTreeNode(void* element, long long int frequency);
void TreeListAdd(hufftree* hufftree, node* add_node);
void CreateTreeList(hufftree* hufftree, frequency* frequency);
node* TreeListRemove(hufftree* hufftree);
node* BuildInternalTreeNode(node* left, node* right);
void BuildHuffmanTree(hufftree* hufftree);
void PrintHuffTreePreOrder(node* root, void(*PrintElement)(void*));

hufftree* MakeTreeFromPreOrder(char* pre_order);

/*
 * Gets and Sets for 'struct HuffTree'.
 */
node* GetHuffTreeRoot(hufftree* hufftree);

/*
 * DEBUG FUNCTIONS (TEMPORARY)
 */
void PrintStructHuffTreeList(hufftree* hufftree, void (*PrintElement)(void*));

#endif //HUFFMAN_HUFFMANTREE_H
