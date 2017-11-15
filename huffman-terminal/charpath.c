//
// Created by pedro on 11/10/2017.
//

#include "charpath.h"

struct CharData {
    byte id;
    int path_size;
    char* path;
};

struct CharHash {

    void* data[MAX_CHAR_SIZE];
};

char buffer[MAX_CHAR_SIZE];

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

/*
 * Allocate an 'struct CharData', initialize all struct content and returns the pointer to the new 'chardata'.
 */
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
    new_chardata->path = new_charpath;
    return new_chardata;
}

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


/*
 * Calculate the size of the trash from the final byte of the compressed file.
 */
int TrashSize(frequency* file_frequency, charhash* file_charhash) {

    int i;
    int total_file_bits = 0;
    for(i = 0; i < MAX_CHAR_SIZE; ++i) {
        if(GetCharFrequencyElement(file_frequency, i)) {
            //Multipling the bits size of every different charactere with his frequency and acumulate the total of the compressed file bits.
            total_file_bits += GetCharDataPathSize(GetCharHashDataElement(file_charhash, i))*(GetCharFrequencyElement(file_frequency, i));
        }
    }
    int trash_size = 8-(total_file_bits%8);
    return trash_size;
}

/*
 * Gets and Sets for 'struct CharHash' and 'struct CharData'.
 */
int GetCharDataPathSize(chardata* chardata) {

    return chardata->path_size;
}

byte GetCharDataId(chardata* chardata) {

    return chardata->id;
}

char* GetCharDataPath(chardata* chardata) {

    return chardata->path;
}

void* GetCharHashDataElement(charhash* charhash, int index) {

    return charhash->data[index];
}