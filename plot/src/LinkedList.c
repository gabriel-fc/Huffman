#include "../inc/LinkedList.h"



struct _node{
	int item;
	_node *next;
};

_node* create_linked_list()
{
	return NULL;
}

int is_empty(_node *head)
{
	return (head == NULL);
}

_node* add(_node *head, int item)
{
	_node *new_node = (_node*) malloc(sizeof(_node));
	new_node->item = item;
	new_node->next = head;
	return new_node;
}

_node * list_search(_node *head, int item,FILE *list_file)
{
	int i=1;
	while (head != NULL) 
	{
			fprintf(list_file, "%d",i);
			if(i != 1000)
				fprintf(list_file, "\n");
		if (head->item == item){
			return head;
		}
		++i;
		head = head->next;
	}

}


