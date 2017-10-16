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
    new_chardata->path_size = path_size;
    new_chardata->path = path;
    return new_chardata;
}

