//
// Created by Pedro on 27/09/2017.
//

#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

typedef unsigned char byte;
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


void printList(hufftree* tree);
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
/*
 * Print the element content into the file.
 */
void PrintHuffTreePreOrder(node* root, FILE* compressed_file);
/*
 * Calculate the size of the tree pre-order.
 */
int TreeSize(node* root);
/*
 * Gets and Sets for 'struct HuffTree'.
 */
node* GetHuffTreeRoot(hufftree* hufftree);
node* GetNodeLeft(node* root);
node* GetNodeRight(node* root);
void* GetNodeElement(node* root);


void ReadNewTree(FILE* read_file, int size_file , byte *string_tree);

#endif