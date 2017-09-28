//
// Created by Pedro on 27/09/2017.
//

#include "../inc/huffmantree.h"

struct Node {

    void* element;
    int frequency;
    node* next;
    node* left;
    node* right;
};

struct HuffTree {

    node* root;
};

hufftree* CreateNewHuffTree() {

    hufftree* new_hufftree = (hufftree*)malloc(sizeof(hufftree));
    if(!new_hufftree) {
        printf("CreateNewHuffTree() error!\n");
        printf("Memory allocation error!\n");
        return NULL;
    }
    new_hufftree->root = NULL;
    return new_hufftree;
}

node* CreateHuffTreeNode(void* element, int frequency){

    node* new_node = (node*)malloc(sizeof(node));
    if(!new_node) {
        printf("CreateHuffTreeNode() error!\n");
        printf("Memory allocation error!\n");
        return NULL;
    }
    new_node->element = element;
    new_node->frequency = frequency;
    new_node->next = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void TreeListAdd(hufftree* hufftree, node* add_node) {

    if(hufftree->root != NULL) {
        node* current = hufftree->root;
        if(add_node->frequency < hufftree->root->frequency) {
            add_node->next = hufftree->root;
            hufftree->root = add_node;
            return;
        } else {
            while(current->next != NULL) {
                if(add_node->frequency < current->next->frequency) {
                    add_node->next = current->next;
                    current->next = add_node;
                    return;
                }
                current = current->next;
            }
            current->next = add_node;
        }
    } else {
        hufftree->root = add_node;
    }
}

void CreateTreeList(hufftree* hufftree, frequency* frequency) {

    if(!hufftree && !frequency) {
        printf("CreateTreeList() error!\n");
        printf("Unable to create the tree's list.\n");
        return;
    } else {
        int i;
        node* tree_node = NULL;
        for(i = 0; i < MAX_CHAR_SIZE; ++i) {
            if(GetCharFrequencyElement(frequency,i)) {
                tree_node = CreateHuffTreeNode((byte*)i, GetCharFrequencyElement(frequency,i));
                TreeListAdd(hufftree, tree_node);
            }
        }
    }
}

hufftree* MakeTreeFromPreOrder(char* pre_order) {


}