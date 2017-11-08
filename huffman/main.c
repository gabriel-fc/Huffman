#include <stdio.h>
#include "inc/header.h"
#include "inc/huffmantree.h"
#include "inc/charpath.h"

void Compress(char* file_path);
void Decompress(char* file_path);
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

    //Open the file;
    FILE* file_to_compress = fopen(file_path, "r");
    if(!file_to_compress) {
        printf("fopen() error!\n");
        printf("Unable to crompress the file!\n");
        return;
    }
    //Create a new frequency table to store frequency data from the file.
    frequency* frequency_table = CreateEmptyFrequency();
    if(!frequency_table) {
        printf("CreateEmptyFrequency() error!\n");
        printf("Unable to compress the file!\n");
        return;
    }
    //Get the frequency data from the file and store in the frequency table.
    GetBytesFrequency(file_to_compress, frequency_table);
    //Create and initialize a new huffman tree.
    hufftree* file_tree = CreateNewHuffTree();
    if(!file_tree) {
        printf("CreateNewHuffTree() error!\n");
        printf("Unable to compress the file!\n");
        return;
    }
    //Create tree nodes and organize in a list from the smallest to the largest frequency.
    CreateTreeList(file_tree, frequency_table);
    //Build the huffman tree with the organized list (smallest to the largest frequency).
    BuildHuffmanTree(file_tree);
    //Create and initialize a new char hash.
    charhash* tree_charhash = CreateEmptyCharHash();
    //Map all the char paths of the tree on the char hash.
    MapCharPaths(tree_charhash, GetHuffTreeRoot(file_tree), 0, '2');

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
