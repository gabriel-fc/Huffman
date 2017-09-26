//
// Created by Pedro on 25/09/2017.
//

#include "../inc/header.h"


struct Frequency {

    int total_frequency;
    long long int char_frequency[MAX_CHAR_SIZE];
};

frequency* CreateEmptyFrequency();
void GetBytesFrequency(FILE* read_file, frequency* frequency);

/*
 * Allocates and initializes a 'struct Frequency'(frequency);
 * Returns a pointer(frequency*) to the new struct.
 */
frequency* CreateEmptyFrequency() {

    frequency* new_frequency = (frequency*)malloc(sizeof(frequency));
    if(!new_frequency) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    new_frequency->total_frequency = 0;
    int i;
    for(i = 0; i < MAX_CHAR_SIZE; ++i) {
        new_frequency->char_frequency[i] = 0;
    }
    return new_frequency;
}

/*
 * Read the file bytes in blocks of 'BUFFER_SIZE' bytes and count in the table(frequency).
 */
void GetBytesFrequency(FILE* read_file, frequency* frequency) {

    byte file_bytes[BUFFER_SIZE];
    int read_size, total_frequency = 0;
    int i;
    while((read_size = fread(&file_bytes, 1, BUFFER_SIZE, read_file)) >= 1) {
        for(i = 0; i < read_size; ++i) {
            frequency->char_frequency[file_bytes[i]]++;
            total_frequency++;
        }
    }
    Frequency->total_frequency = total_frequency;
    rewind(read_file);
}
