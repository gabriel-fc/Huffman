#include "../inc/BinaryTree.h"

struct Node{
	int item;
	Node * right;
	Node * left;
};

Node * CreateEmptyNode(){
	return NULL;
}
Node * CreateNode(int item){
	Node * NewNode = (Node*) malloc(sizeof(Node));
	NewNode->item = item;
	NewNode->right = NULL;
	NewNode->left = NULL;
	return NewNode;
}

Node * AddNode(Node * root, int item, FILE * frequency, int count){
	count++;
	if(root == NULL){
		fprintf(frequency, "%d", count);
		return CreateNode(item);
	}
	if(root->item > item)
		root->left = AddNode(root->left, item, frequency, count);
	else
		root->right = AddNode(root->right, item, frequency, count);
	return root;
}

Node * search(Node * root, int item){
	if(root == NULL)
		return root;
	if(root->item > item){
		root = search(root->left, item);
	}
	else if (root->item < item){
		root = search(root->right, item);
	}
	return root;
}

int IsEmpty(Node * root){
	return root == NULL;
}