#include <stdio.h>
#include "inc/header.h"
#include "inc/huffmantree.h"

void Compress(char* file_to_compress);
void Decompress(char* file_to_decompress);
void PrintElement(void* void_element);

int main() {

    int operation;
    char file_path[100];
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
    getchar();
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
        printf("Unable to compress the file!\n");
        return;
    }
    GetBytesFrequency(file_to_compress, frequency_table);
    hufftree* file_tree = CreateNewHuffTree();
    CreateTreeList(file_tree, frequency_table);
    BuildHuffmanTree(file_tree);
    PrintHuffTreePreOrder(GetHuffTreeRoot(file_tree),PrintElement);
    printf("\n");
}

void Decompress(char* file_path) {


    FILE* file_to_decompress = fopen(file_path, "r");
    if(!file_to_decompress) {
        printf("fopen() error!\n");
        printf("Unable to crompress the file!\n");
        return;
    }
}

void PrintElement(void* void_element) {

    byte element = (byte)void_element;
    printf("%c", element);
}
