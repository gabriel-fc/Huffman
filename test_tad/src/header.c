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

void PrintHeader(int trash_size, int tree_size, FILE* compressed_file) {
    short first_2bytes[16];
    int remainder = 0;
    int current_number;
    int i;
    if(trash_size > 8 ||  trash_size < 0) {
        printf("PrintHeader error!\n");
        printf("Invalid trash size!\n");
        printf("Unable to print the header of the final file.\n");
        return;
    } else {
        //Passing trash size to the binary format into the first 3 variables of first_2bytes string.
        if(trash_size == 8) {
            trash_size = 0;
        }
        current_number = trash_size;
        for(i = 2; i >= 0; --i) {
            if(!current_number) {
                first_2bytes[i] = 0;
            } else {
                remainder = current_number/2;
                if(current_number%2) {
                    first_2bytes[i] = 1;
                } else {
                    first_2bytes[i] = 0;
                }
                current_number = remainder;
            }
        }
    }

    //Passing tree size to the binary format into the last 13 variables of first_2bytes string.
    current_number = tree_size;
    for(i = 15; i > 2; --i) {
        if(!current_number) {
            first_2bytes[i] = 0;
        } else {
            remainder = current_number/2;
            if(current_number%2) {
                first_2bytes[i] = 1;
            } else {
                first_2bytes[i] = 0;
            }
            current_number = remainder;
        }
    }

    byte print_byte = 0;
    for(i = 0; i <= 15; ++i) {
        if(i == 8) {
            fprintf(compressed_file, "%c", print_byte);
            print_byte = 0;
        }
        if(first_2bytes[i]) {
            print_byte = SetBiti(print_byte, i%8);
        }
    }
    fprintf(compressed_file, "%c", print_byte);
}

int IsBitiSet(byte file_byte, int i) {

    byte mask = 1 << i;
    return (file_byte & mask);
}

byte SetBiti(byte file_byte, int i) {

    byte mask = 1 << (7-i);
    return (file_byte | mask);
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