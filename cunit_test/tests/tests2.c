/*
 * File:   tests2.c
 * Author: karen
 *
 * Created on 12/11/2017, 22:01:01
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../huffmantree.h"
#include "../header.h"

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
    if (!GetHuffTreeRoot(result)) {
        CU_ASSERT(1);
    }
    else
        CU_ASSERT(0);
}

void testCreateHuffTreeNode() {
    void* element = (byte*)'&';
    long long int frequency = 55;
    node* result = CreateHuffTreeNode(element, frequency);
    CU_ASSERT_EQUAL(GetNodeFrequency(result), 55);
}

void testTreeListAdd() {
    hufftree* hufftree = CreateNewHuffTree();
    node* add_node = CreateHuffTreeNode((byte*)'A', 210);
    TreeListAdd(hufftree, add_node);
    if (GetTreeListSize(hufftree)) {
        CU_ASSERT(1);
    }
    else
        CU_ASSERT(0);
}

void testTreeListRemove() {
    
    hufftree* hufftree = CreateNewHuffTree();
    node* add_node = CreateHuffTreeNode((byte*)'A', 210);
    TreeListAdd(hufftree, add_node);
    node* result = TreeListRemove(hufftree);
    if (!GetTreeListSize(hufftree)) {
        CU_ASSERT(1);
    }
    else
        CU_ASSERT(0);
}

void testBuildInternalTreeNode() {
    node* left;
    node* right;
    PutFrequencyInNode(left, 10);
    PutFrequencyInNode(right, 15);
    node* result = BuildInternalTreeNode(left, right);
    CU_ASSERT_EQUAL(GetNodeFrequency(result), 25);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("tests2", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreateNewHuffTree", testCreateNewHuffTree)) ||
            (NULL == CU_add_test(pSuite, "testCreateHuffTreeNode", testCreateHuffTreeNode)) ||
            (NULL == CU_add_test(pSuite, "testTreeListAdd", testTreeListAdd)) ||
            (NULL == CU_add_test(pSuite, "testTreeListRemove", testTreeListRemove)) ||
            (NULL == CU_add_test(pSuite, "testBuildInternalTreeNode", testBuildInternalTreeNode))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
