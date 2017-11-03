#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/binary_tree.h"
#include "../inc/linked_list.h"
//gcc main.c ../src/binary_tree.c ../src/linked_list.c -Ibinary_tree.h -Ilinked_list.h -o main//
int main(){
    long int first_of_sequence, random, * j = (long int*) malloc(sizeof(long int));
    long int i = 0, media;
    FILE * bt_file = fopen("binary_tree_out.txt", "w");
    FILE * list_file = fopen("linked_list_out.txt", "w");
    _btree * bt = create_btree();
    _node * head = create_linked_list();
    srand((unsigned) time(NULL));
    while(i < 1000000) {
        random = rand()*rand();
        *j = 0;
        if (!i) {
            media = 1;
            first_of_sequence = random;
            fprintf(bt_file,"%ld\n", media);
        }
        if ((i && random != first_of_sequence) || !i) {
            bt = bt_add(bt, random, j);
            if(i){
                media = media + (*j);
                media/=2;
            }
            head = list_add(head, random);
            if(!(i%1000) && i)
                fprintf(bt_file, "%ld\n", media);
            i++;
        }
    }
    list_search(head, first_of_sequence, list_file);
    fclose(bt_file);
    fclose(list_file);
}


