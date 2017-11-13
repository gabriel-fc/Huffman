#include "BinaryTree.h"

typedef struct _node _node;

_node* create_linked_list();

int is_empty(_node *head);

_node* add(_node *head, int item);

_node * list_search(_node *head, int item,FILE *list_file);