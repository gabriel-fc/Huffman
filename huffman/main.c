#include <stdio.h>
#include "inc/huffmantree.h"
#include "inc/charpath.h"
#include "inc/header.h"

#define COMPRESSED_FILE_PATH "C:\\Users\\pedro\\Desktop\\compressed.huff"
#define READ_BUFFER_SIZE 1024

typedef unsigned char byte;

void Compress(char* file_path);
void Decompress(char* file_path);
void CompressTheBytes(charhash* tree_charhash, FILE* file_to_compress, FILE* compressed_file);
void PrintElement(void* void_element, FILE* compressed_file);

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

/*
 * Compression main function.
 */
void Compress(char* file_path) {

    //Open the file;
    FILE* file_to_compress = fopen(file_path, "r");
    if(!file_to_compress) {
        printf("fopen() error!\n");
        printf("Unable to compress the file!\n");
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
    //Create the new file (compressed file).
    FILE* compressed_file = fopen(COMPRESSED_FILE_PATH, "w");
    if(!compressed_file) {
        printf("fopen() error!\n");
        printf("'compressed_file' memory allocation error!\n");
        printf("Unable to compress the file!\n");
        return;
    }
    //Calculating the trash size.
    int trash_size = TrashSize(frequency_table, tree_charhash);
    //Calculation the tree size.
    int tree_size = TreeSize(GetHuffTreeRoot(file_tree));
    //Print the first 2 bytes of the file (trash size and tree size).
    PrintHeader(trash_size, tree_size, compressed_file);
    //Print the pre-order of the tree in the file.
    PrintHuffTreePreOrder(GetHuffTreeRoot(file_tree), PrintElement, compressed_file);
    //Compression process, the function read the 'file_to_compress' and convert all the bytes to the compressed format into the 'compressed_file'.
    CompressTheBytes(tree_charhash, file_to_compress, compressed_file);
}

void CompressTheBytes(charhash* tree_charhash, FILE* file_to_compress, FILE* compressed_file) {

    //Buffer to hold 'READ_BUFFER_SIZE' bytes at time from the file to be used by the function.
    byte read_buffer[READ_BUFFER_SIZE];

    //Buffer to hold the binary string of the byte to be translated to a single unsigned char and printed in the file. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    byte print_byte = '\0';

    //Buffer control variables.
    int read_buffer_position, read_size, print_byte_bit_position = 8;

    //Charpath control variables.
    int path_size = 0;
    char* bit_path = NULL;
    int bit_path_position = 0;
    chardata* current_byte_data;

    //Repeat the process while have something to be read in the file.
    while((read_size = fread(&read_buffer, 1, READ_BUFFER_SIZE, file_to_compress)) > 0) {
        //Repeat the process to each byte of the read_buffer.
        for(read_buffer_position = 0; read_buffer_position < read_size; ++read_buffer_position) {
            //Get the current byte information from the charhash.
            current_byte_data = GetCharHashDataElement(tree_charhash, read_buffer[read_buffer_position]);
            path_size = GetCharDataPathSize(current_byte_data);
            bit_path = GetCharDataPath(current_byte_data);
            //Set all the path bits in the print_byte.
            while(bit_path_position < path_size) {
                if(bit_path[bit_path_position] == '1') {
                    print_byte = SetBiti(print_byte, print_byte_bit_position);
                }
                print_byte_bit_position--;
                //If the 8 bits of print_byte was set, print de byte in the file and start again.
                if(print_byte_bit_position == -1) {
                    fprintf(compressed_file, "%c", print_byte);
                    print_byte_bit_position = 8;
                    print_byte = '\0';
                }
                bit_path_position++;
            }
            bit_path_position = 0;
        }
    }
}

/*
 * Decompression main function.
 */
void Decompress(char* file_path) {

    FILE* file_to_decompress = fopen(file_path, "r");
    if(!file_to_decompress) {
        printf("fopen() error!\n");
        printf("Unable to compress the file!\n");
        return;
    }
    else{}
}

void PrintElement(void* void_element, FILE* compressed_file) {

    byte element = (byte)void_element;
    fprintf(compressed_file, "%c", element);
}
