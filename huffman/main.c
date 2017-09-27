#include <stdio.h>
#include "inc/header.h"
#include "inc/huffmantree.h"

void Compress(char* file_to_compress);
void Decompress(char* file_to_decompress);

int main() {

    int operation;
    char* file_path[100];
    printf(",__________________,\n");
    printf("|!-[Marcinho Zip]-!|\n");
    printf("|                  |\n");
    printf("|   [0]Compress    |\n");
    printf("|   [1]Decompress  |\n");
    printf("|__________________|\n");
    scanf("%d", &operation);
    while(operation != 0 && operation != 1) {
        printf("Invalid Operation! Try again.\n");
        scanf("%d", &operation);
    }
    if(!operation) {
        printf("COMPRESS\n");
        printf("Enter the file path:\n");
        gets(file_path);
        Compress(file_path);
    } else {
        printf("DECOMPRESS\n");
        printf("Enter the file path:");
        gets(file_path);
        //Decompress(file_path);
    }
    return 0;
}

void Compress(char* file_path) {

    //open the file;
    FILE* file_to_compress = fopen(file_path, "r");
    if(!file_to_compress) {
        printf("fopen() error!\n");
        printf("Unable to crompress the file!\n");
        return;
    }
    frequency* frequency_table = CreateEmptyFrequency();
    if(!frequency_table) {
        printf("CreateEmptyFrequency() error!\n");
        printf("Memory allocation error.\n");
        printf("Unable to compress the file!\n");
        return;
    }
    GetBytesFrequency(file_to_compress, frequency_table);

}

void Decompress(char* file_to_decompress) {


}