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

char buffer[BUFFER_SIZE];

/*
 * Allocate an 'struct CharHash', initialize all struct content and returns the pointer to the new 'charhash'.
 */
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

//<<<<<<< HEAD//
//=======//
/*
 * Allocate an 'struct CharData', initialize all struct content and returns the pointer to the new 'chardata'.
 */
//>>>>>>> origin/Pedro//
chardata* CreateCharData(unsigned char id, int path_size) {

    chardata* new_chardata = (chardata*)malloc(sizeof(chardata));
    if(new_chardata == NULL) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    new_chardata->id = id;
    char* new_charpath = (char*)malloc(sizeof(char)*path_size);
    int i;
    for(i = 0; i < path_size; ++i) {
        new_charpath[i] = buffer[i];
    }
    new_chardata->path_size = path_size;
//<<<<<<< HEAD//
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






//=======//
    //new_chardata->path = new_charpath;
    //return new_chardata;
//}//

/*
 * The function traverses the entire huffman tree and map to the hash the corresponding path of each leaf in the binary format.
 */
void MapCharPaths(charhash* charhash, node* root, int buffer_position, char bit) {

    if(bit != '2' && root != NULL) {
        buffer[buffer_position] = bit;
    }
    if(root != NULL) {
        if(GetNodeRight(root) == NULL && GetNodeLeft(root) == NULL) {
            buffer[++buffer_position] = '\0';
            byte node_element = (byte)GetNodeElement(root);
            chardata* new_chardata = CreateCharData(node_element, strlen(buffer));
            charhash->data[(int)node_element] = new_chardata;
        } else {
            if(bit != '2') {
                MapCharPaths(charhash, GetNodeLeft(root), buffer_position+1, '0');
                MapCharPaths(charhash, GetNodeRight(root), buffer_position+1, '1');
            } else {
                MapCharPaths(charhash, GetNodeLeft(root), buffer_position, '0');
                MapCharPaths(charhash, GetNodeRight(root), buffer_position, '1');
            }
        }
    }
}
//>>>>>>> origin/Pedro//
