//
// Created by pedro on 11/10/2017.
//

#include "../inc/charpath.h"

struct CharData {

    unsigned char id;
    int path_size;
    char* path;
};

struct CharHash {

    void* data[MAX_CHAR_SIZE];
};

char buffer[BUFFER_SIZE];

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

chardata* CreateCharData(unsigned char id, char* path, int path_size) {

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
    new_chardata->path = new_charpath;
    return new_chardata;
}

void MapCharPaths(charhash* charhash, node* root, int buffer_position, char bit) {

    if(bit != '2') {
        buffer[buffer_position] = bit;
    }
    if(root != NULL) {
        if(GetNodeRight(root) == NULL && GetNodeLeft(root) == NULL) {
            buffer[++buffer_position] = '\0';
            byte node_element = (byte)GetNodeElement(root);
            chardata* new_chardata = CreateCharData(node_element, buffer, strlen(buffer));
            charhash->data[(int)node_element] = new_chardata;
        } else {
            MapCharPaths(charhash, GetNodeLeft(root), buffer_position+1, '0');
            MapCharPaths(charhash, GetNodeLeft(root), buffer_position+1, '1');
        }
    }
}

void PrintCharData(chardata* chardata) {

    if(chardata != NULL) {
        printf("[%c] ->", chardata->id);
        int i;
        for(i = 0; i < chardata->path_size; ++i) {
            printf("%c", chardata->path[i]);
        }
        printf("\n");
    }
}

void PrintCharHash(charhash* charhash) {

    if(charhash != NULL) {
        printf("CHAR HASH\n");
        int i;
        for(i = 0; i < MAX_CHAR_SIZE; ++i) {
            if(charhash->data[i] != NULL) {
                PrintCharData(charhash->data[i]);
            } else {
                printf("NULL!\n");
            }
        }
    }
}

