#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

Node * CreateNode(int item);

Node * AddNode(Node * root, int item, FILE * frequency, int count);

Node * search(Node * root, int item);

int IsEmpty(Node * root);

Node * CreateEmptyNode();	