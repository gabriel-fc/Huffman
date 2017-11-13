#include <stdio.h>

#include "inc/huffmantree.h"

#include "inc/charpath.h"

#include "inc/header.h"



#define READ_BUFFER_SIZE 1024



void Compress(char* file_path);

void Decompress(char* file_path, char* file_path_out);

void CompressTheBytes(charhash* tree_charhash, FILE* file_to_compress, FILE* compressed_file);

void PrintElement(void* void_element, FILE* compressed_file);

void DecompressTheBytes(node *root, FILE *file_to_decompress, FILE* output_file);







int main() {



    int operation;

    char file_path[100], file_path_out[100];

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

        printf("Enter the file path to compress:\n");

        gets(file_path);

        Compress(file_path);

    } else {

        printf("DECOMPRESS\n");

        printf("Enter the file path to descompress:");

        gets(file_path);

        printf("Enter the new file path:");

        gets(file_path_out);

        Decompress(file_path, file_path_out);

    }

    return 0;

}



/*

 * Compression main function.

 */

void Compress(char* file_path) {



    //Open the file;

    FILE* file_to_compress = fopen(file_path, "rb");

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

    //Create the new file (compressed file).

    FILE* compressed_file = fopen("compressed.huff", "wb");

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

    PrintHuffTreePreOrder(GetHuffTreeRoot(file_tree), compressed_file);

    //Compression process, the function read the 'file_to_compress' and convert all the bytes to the compressed format into the 'compressed_file'.

    CompressTheBytes(tree_charhash, file_to_compress, compressed_file);

}



void CompressTheBytes(charhash* tree_charhash, FILE* file_to_compress, FILE* compressed_file) {



    //Buffer to hold 'READ_BUFFER_SIZE' bytes at time from the file to be used by the function.

    byte read_buffer[READ_BUFFER_SIZE];



    //Buffer to hold the binary string of the byte to be translated to a single unsigned char and printed in the file. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    byte print_byte = '\0';



    //Buffer control variables.

    int read_buffer_position, read_size, print_byte_bit_position = 0;



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

                print_byte_bit_position++;

                //If the 8 bits of print_byte was set, print de byte in the file and start again.

                if(print_byte_bit_position == 8) {

                    fprintf(compressed_file, "%c", print_byte);

                    print_byte_bit_position = 0;

                    print_byte = '\0';

                }

                bit_path_position++;

            }

            bit_path_position = 0;

        }

    }



    fprintf(compressed_file, "%c", print_byte);

}



/*

 * Decompression main function.

 */

void Decompress(char* file_path, char* file_path_out) {



    FILE* file_to_decompress = fopen(file_path, "rb");

    if(!file_to_decompress) {

        printf("fopen() error!\n");

        printf("Unable to descompress the file!\n");

        return;

    }

    FILE* output_file = fopen(file_path_out, "wb");

    if(!output_file) {

        printf("fopen() error!\n");

        printf("Unable to descompress the new file!\n");

        return;

    }



    int size_file = HeaderRead(file_to_decompress);

    byte string_tree[size_file];

    node *new_ht = NULL;

    

    ReadNewTree(file_to_decompress, size_file, string_tree);

    new_ht = CreateHTDecompress(string_tree, new_ht, size_file);

    DecompressTheBytes(new_ht, file_to_decompress, output_file);

    

    fclose(file_to_decompress);

    fclose(output_file);



}





void DecompressTheBytes(node *root, FILE *file_to_decompress, FILE* output_file){

    long long int size_current;

    int j, i, bit, flag = 0;

    byte last_byte;

    byte *current = (byte*) malloc(1024 * sizeof(byte));

    node *new_node = root;

    

    

    while((size_current = fread(current, 1, 1024, file_to_decompress)) >= 1){

        if(flag){

            for (i = 7; i >= 0; --i){

                    if(GetNodeLeft(new_node) == NULL && GetNodeRight(new_node) == NULL){

                    fprintf(output_file, "%c", (byte)GetNodeElement(new_node));

                    new_node = root;

                }

                bit = is_bit_i_set(last_byte, i);

                if(!bit)

                    new_node = GetNodeLeft(new_node);

                else

                    new_node = GetNodeRight(new_node);

            }

        }

        

        flag = 1;

        last_byte = current[--size_current];

        

        for (i = 0; i < size_current; ++i){

            for (j = 7; j >= 0; --j) {

                if(GetNodeLeft(new_node) == NULL && GetNodeRight(new_node) == NULL){

                    fprintf(output_file, "%c", (byte)GetNodeElement(new_node));

                    new_node = root;

                }

                bit = is_bit_i_set(current[i], j);

                if(!bit)

                    new_node = GetNodeLeft(new_node);

                else

                    new_node = GetNodeRight(new_node);

            }

        }

    }



    for (i = 7; i >= trash; --i){

            

        if(GetNodeLeft(new_node) == NULL && GetNodeRight(new_node) == NULL){

            fprintf(output_file, "%c", (byte)GetNodeElement(new_node));

            new_node = root;

        }

        bit = is_bit_i_set(last_byte, i);

        if(!bit)

            new_node = GetNodeLeft(new_node);

        else

            new_node = GetNodeRight(new_node);

    }

    

}