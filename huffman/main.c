#include <stdio.h>
#include "inc/header.h"

int main() {

    int operation;
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
        //Compress();
    } else {
        printf("DECOMPRESS\n");
        //Decompress();
    }
    return 0;
}