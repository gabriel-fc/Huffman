//
// Created by pedro on 11/10/2017.
//

#include "../inc/charpath.h"

struct CharData {

    unsigned char id;
    int path_size;
    char * path;
};

struct CharHash {

    void* data[MAX_CHAR_SIZE];
};

charhash* CreateEmptyCharHash() {

    charhash* new_charhash = (charhash*)malloc(sizeof(charhash));
    if(new_charhash == NULL) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    int i;
    for(i = 0; i < MAX_CHAR_SIZE; ++i) {
        new_charhash->data[i] = NULL;
    }
    return new_charhash;
}

chardata* CreateCharData(unsigned char id, int path_size) {

    chardata* new_chardata = (chardata*)malloc(sizeof(chardata));
    if(new_chardata == NULL) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    new_chardata->id = id;
    new_chardata->path_size = path_size;
    return new_chardata;
}

 void CreatePath(Node * root, int path_size, char path[], charhash * tree_charhash) {
     if (root != NULL) {
         printf("Empty tree!\n");
         return;
     }
     if (root->left != NULL) {
         path[path_size] = '0';
         CreatePath(root->left, path_size + 1, path, tree_charhash);
     }
     if (root->right != NULL) {
         path[path_size] = '1';
         CreatePath(root->right, path_size + 1, path, tree_charhash);
     } else {
         int i;
         tree_charhash->data[root->element] = CreateCharData(*(root->element), path_size);
         for (i = 0; i < path_size; ++i) {
             *(tree_charhash->data[root->element]->path[i]) = path[i];
         }
     }
 }






