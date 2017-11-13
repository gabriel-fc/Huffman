/*
 * File:   newcunittest1.c
 * Author: karen
 *
 * Created on 12/11/2017, 15:52:44
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../huffmantree.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testCreateNewHuffTree() {
    hufftree* result = CreateNewHuffTree();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testCreateHuffTreeNode() {
    void* element;
    long long int frequency;
    node* result = CreateHuffTreeNode(element, frequency);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testTreeListAdd() {
    hufftree* hufftree = CreateNewHuffTree();
    node* add_node = CreateHuffTreeNode((byte*)'A', 210);
    TreeListAdd(hufftree, add_node);
    if (TreeListAdd != NULL) {
        CU_ASSERT(1);
    }
}

void testBuildInternalTreeNode() {
    node* left;
    node* right;
    node* result = BuildInternalTreeNode(left, right);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}


void testTreeSize() {
    node* root;
    int result = TreeSize(root);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testGetHuffTreeRoot() {
    hufftree* hufftree;
    node* result = GetHuffTreeRoot(hufftree);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest1", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreateNewHuffTree", testCreateNewHuffTree)) ||
            (NULL == CU_add_test(pSuite, "testCreateHuffTreeNode", testCreateHuffTreeNode)) ||
            (NULL == CU_add_test(pSuite, "testTreeListAdd", testTreeListAdd)) ||
            (NULL == CU_add_test(pSuite, "testBuildInternalTreeNode", testBuildInternalTreeNode)) ||
            (NULL == CU_add_test(pSuite, "testTreeSize", testTreeSize)) ||
            (NULL == CU_add_test(pSuite, "testGetHuffTreeRoot", testGetHuffTreeRoot))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
