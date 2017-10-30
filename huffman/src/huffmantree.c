//
// Created by Pedro on 27/09/2017.
//

#include "../inc/huffmantree.h"

/*
 * Huffman Tree node struct.
 */
struct Node {

    void* element;
    long long int frequency;
    node* next;
    node* left;
    node* right;
};

/*
 * Huffman Tree main struct.
 */
struct HuffTree {

    int list_size;
    node* root;
};

/*
 * Allocate an 'struct HuffTree', initialize all struct content and returns the pointer to the new 'hufftree'.
 */
hufftree* CreateNewHuffTree() {

    hufftree* new_hufftree = (hufftree*)malloc(sizeof(hufftree));
    if(!new_hufftree) {
        printf("CreateNewHuffTree() error!\n");
        printf("Memory allocation error!\n");
        return NULL;
    }
    new_hufftree->list_size = 0;
    new_hufftree->root = NULL;
    return new_hufftree;
}

/*
 * Allocate an 'struct Node', initialize all struct content and returns the pointer to the new 'node'.
 */
node* CreateHuffTreeNode(void* element, long long int frequency){

    node* new_node = (node*)malloc(sizeof(node));
    if(!new_node) {
        printf("CreateHuffTreeNode() error!\n");
        printf("Memory allocation error!\n");
        return NULL;
    }
    new_node->element = element;
    new_node->frequency = frequency;
    new_node->next = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/*
 * Add the 'add_node' to the correctly position on the huffman tree list (from smallest to the largest frequency).
 */
void TreeListAdd(hufftree* hufftree, node* add_node) {

    if(hufftree->root != NULL) {
        node* current = hufftree->root;
        if(add_node->frequency < hufftree->root->frequency) {
            add_node->next = hufftree->root;
            hufftree->root = add_node;
            hufftree->list_size++;
            return;
        } else {
            while (current->next != NULL) {
                if (add_node->frequency < current->next->frequency) {
                    add_node->next = current->next;
                    current->next = add_node;
                    hufftree->list_size++;
                    return;
                }
                current = current->next;
            }
            current->next = add_node;
            hufftree->list_size++;
        }
    } else {
        hufftree->root = add_node;
        hufftree->list_size++;
    }
}

/*
 * Read the frequency table and create the nodes to the characteres with a frequency > 0 and calls the function TreeListAdd() to correctly position the nodes in the list.
 */
void CreateTreeList(hufftree* hufftree, frequency* frequency) {

    if(!hufftree && !frequency) {
        printf("CreateTreeList() error!\n");
        printf("Unable to create the tree's list.\n");
        return;
    } else {
        int i;
        node* tree_node = NULL;
        for(i = 0; i < MAX_CHAR_SIZE; ++i) {
            //If the char 'i' frequency is > 0 create a node and add to the list.
            if(GetCharFrequencyElement(frequency,i)) {
                tree_node = CreateHuffTreeNode((byte*)i, GetCharFrequencyElement(frequency,i));
                TreeListAdd(hufftree, tree_node);
            }
        }
    }
}

/*
 * Logically removes the node from the list and returns the pointer of the removed node.
 */
node* TreeListRemove(hufftree* hufftree) {

    if(hufftree->list_size) {
        node* remove_node = hufftree->root;
        hufftree->root = remove_node->next;
        hufftree->list_size--;
        return remove_node;
    } else {
        return NULL;
    }
}

/*
 * Allocate a new internal node (not a element node), calculate the node frequency and set the pointers of the left and right nodes.
 */
node* BuildInternalTreeNode(node* left, node* right) {

    node* new_node = (node*)malloc(sizeof(node));
    if(!new_node) {
        printf("BuildInternalTreeNode() error!\n");
        printf("Memory allocation error.\n");
        printf("Unable to Build internal node.\n");
        return NULL;
    }
    new_node->element = NULL;
    new_node->frequency = left->frequency + right->frequency;
    new_node->next = NULL;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

/*
 * Build the tree-structure of huffman tree with the organized list.
 */
void BuildHuffmanTree(hufftree* hufftree) {

    if(!hufftree) {
        printf("BuildHuffmanTree() error!\n");
        printf("NULL pointer.\n");
        printf("Unable to build the tree.\n");
    } else {
        node* aux1 = NULL;
        node* aux2 = NULL;
        node* new_node = NULL;
        //If the list have 2 or more elements remove the 2 smallest frequency nodes and build a internal node to make the tree-structure.
        while(hufftree->root->next != NULL) {
            aux1 = TreeListRemove(hufftree);
            aux2 = TreeListRemove(hufftree);
            new_node = BuildInternalTreeNode(aux1, aux2);
            //add the new internal node to the list to continue the process.
            TreeListAdd(hufftree, new_node);
        }
    }
}

//THIS FUNCTION WILL BE MODIFIED TO PRINT THE TREE DIRECTLY IN THE FILE!
void PrintHuffTreePreOrder(node* root, void(*PrintElement)(void*)) {

    if(root != NULL) {
        if(root->element == NULL) {
            printf("*");
        } else {
            if((byte)root->element == '*' || (byte)root->element == '\\') {
                printf("\\");
            }
            (*PrintElement)(root->element);
        }
        PrintHuffTreePreOrder(root->left, (*PrintElement));
        PrintHuffTreePreOrder(root->right, (*PrintElement));
    }
}

//UNFINISHED
hufftree* MakeTreeFromPreOrder(char* pre_order) {


}

/*
 * Gets and Sets for 'struct HuffTree'.
 */
node* GetHuffTreeRoot(hufftree* hufftree) {

    return hufftree->root;
}

node* GetNodeLeft(node* root) {

    return root->left;
}

node* GetNodeRight(node* root) {

    return root->right;
}

void* GetNodeElement(node* root) {

    return root->element;
}
/*
 * DEBUG FUNCTIONS (TEMPORARY)
 */
void PrintStructHuffTreeList(hufftree* hufftree, void (*PrintElement)(void*)) {

    printf("PrintStructHuffTreeList():\n");
    if(hufftree != NULL) {
        node* current = hufftree->root;
        if(current == NULL) {
            printf("\tEmpty list!\n");
        }
        while(current != NULL) {
            printf("\t[");
            (*PrintElement)(current->element);
            printf("] = %lld\n", current->frequency);
            current = current->next;
        }
    } else {
        printf("\tNULL pointer!\n");
    }
}