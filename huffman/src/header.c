//
// Created by Pedro on 25/09/2017.
//

#include "../inc/header.h"

/*
 * Frequency table struct.
 */
struct Frequency {

    long long int total_frequency;
    long long int char_frequency[MAX_CHAR_SIZE];
};

/*
 * Allocates and initializes a 'struct Frequency'(frequency);
 * Returns a pointer(frequency*) to the new struct.
 */
frequency* CreateEmptyFrequency() {

    frequency* new_frequency = (frequency*)malloc(sizeof(frequency));
    if(!new_frequency) {
        printf("CreateEmptyFrequency() error!\n");
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
    frequency->total_frequency = total_frequency;
    rewind(read_file);
}

/*
 * Gets and Sets for 'struct Frequency'.
 */
long long int GetTotalFrequency(frequency* frequency) {

    return frequency->total_frequency;
}

long long int GetCharFrequencyElement(frequency* frequency, int index) {

    return frequency->char_frequency[index];
}

/*
 * DEBUG FUNCTIONS (TEMPORARY)
 */
void PrintStructFrequency(frequency* frequency) {

    printf("PrintStructFrequency():\n");
    if(frequency != NULL) {
        printf("\tTotal Frequency: %lld\n", frequency->total_frequency);
        int i;
        for(i = 0; i < MAX_CHAR_SIZE; ++i) {
            printf("\tChar '%c' frequency: %lld\n", (byte)i, frequency->char_frequency[i]);
        }
    } else {
        printf("\tNULL pointer!\n");
    }
}