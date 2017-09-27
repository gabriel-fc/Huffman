//
// Created by Pedro on 27/09/2017.
//

#include "../inc/huffmantree.h"

struct Node {

    char element;
    int frequency;
    node* next;
    node* left;
    node* right;
};

struct HuffTree {

    frequency* char_frequency;
    node* root;
};