#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inc/BinaryTree.h"
#include "inc/LinkedList.h"
//gcc main.c ../src/binary_tree.c ../src/linked_list.c -Ibinary_tree.h -Ilinked_list.h -o main//
int main(){
    long int random, * j = (long int*) malloc(sizeof(long int)), first_of_sequence;
    long int i = 0;
    int flag = 0;
    FILE * bt_file = fopen("binary_tree_out.txt", "w");
    FILE * list_file = fopen("linked_list_out.txt", "w");
    Node * bt = CreateEmptyNode();
    _node * head = create_linked_list();
    srand((unsigned) time(NULL));
    for(i = 0; i < 1000000; i++){
        random = rand()*rand();
        if(!flag){
    		first_of_sequence = random;
    		flag++;
    	}
        bt = AddNode(bt, random, bt_file, 0);
        if(i != 999999)
            fprintf(bt_file,"\n");
        head = add(head, random);
    }
    list_search(head, first_of_sequence, list_file);
    fclose(bt_file);
    fclose(list_file);
}


