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

/*
 * Allocate an 'struct HuffTree', initialize all struct content and returns the pointer to the new 'hufftree'.
 */
hufftree* CreateNewHuffTree();
/*
 * Allocate an 'struct Node', initialize all struct content and returns the pointer to the new 'node'.
 */
node* CreateHuffTreeNode(void* element, long long int frequency);
/*
 * Add the 'add_node' to the correctly position on the huffman tree list (smallest to the largest frequency).
 */
void TreeListAdd(hufftree* hufftree, node* add_node);
/*
 * Read the frequency table and create the nodes to the characteres with a frequency > 0 and calls the function TreeListAdd() to correctly position the nodes in the list.
 */
void CreateTreeList(hufftree* hufftree, frequency* frequency);
/*
 * Logically removes the node from the list and returns the pointer of the removed node.
 */
node* TreeListRemove(hufftree* hufftree);
/*
 * Allocate a new internal node (not a element node), calculate the node frequency and set the pointers of the left and right nodes.
 */
node* BuildInternalTreeNode(node* left, node* right);
/*
 * Build the tree-structure of huffman tree with the organized list.
 */
void BuildHuffmanTree(hufftree* hufftree);

//THIS FUNCTION WILL BE MODIFIED TO PRINT THE TREE DIRECTLY IN THE FILE!
void PrintHuffTreePreOrder(node* root, void(*PrintElement)(void*));

//UNFINISHED
hufftree* MakeTreeFromPreOrder(char* pre_order);

/*
 * Gets and Sets for 'struct HuffTree'.
 */
node* GetHuffTreeRoot(hufftree* hufftree);
node* GetNodeLeft(node* root);
node* GetNodeRight(node* root);
void* GetNodeElement(node* root);
/*
 * DEBUG FUNCTIONS (TEMPORARY)
 */
void PrintStructHuffTreeList(hufftree* hufftree, void (*PrintElement)(void*));

#endif //HUFFMAN_HUFFMANTREE_H
