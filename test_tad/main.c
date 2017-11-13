#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "inc/charpath.h"

/*
 * CUnit Test Suite with Hash functions
 */

int init_suite_charpath(void) {
    return 0;
}

int clean_suite_charpath(void) {
    return 0;
}

void testCreateEmptyCharHash() {
    charhash* result = CreateEmptyCharHash();
    int position = 10;
    if (!GetCharHashDataElement(result, position)) {
        CU_ASSERT(1);
    }
    else
    CU_ASSERT(0);
}

void testCreateCharData() {
    unsigned char id = 'K';
    int path_size = 5;
    chardata* result = CreateCharData(id, path_size);

    CU_ASSERT_EQUAL(GetCharDataId(result), 'K');
    CU_ASSERT_EQUAL(GetCharDataPathSize(result), 5);
}

/*
 * CUnit Test Suite with Huffman Tree functions
 */

int init_suite_huffmantree(void) {
    return 0;
}

int clean_suite_huffmantree(void) {
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
    CU_pSuite pSuite1 = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite1 = CU_add_suite("tests", init_suite_charpath, clean_suite_charpath);
    if (NULL == pSuite1) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite1, "testCreateEmptyCharHash", testCreateEmptyCharHash)) ||
        (NULL == CU_add_test(pSuite1, "testCreateCharData", testCreateCharData))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    //CUnit Test Suite with Huffman Tree functions

    CU_pSuite pSuite2 = NULL;
    

    /* Add a suite to the registry */
    pSuite2 = CU_add_suite("tests2", init_suite_huffmantree, clean_suite_huffmantree);
    if (NULL == pSuite2) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite2, "testCreateNewHuffTree", testCreateNewHuffTree)) ||
        (NULL == CU_add_test(pSuite2, "testCreateHuffTreeNode", testCreateHuffTreeNode)) ||
        (NULL == CU_add_test(pSuite2, "testTreeListAdd", testTreeListAdd)) ||
        (NULL == CU_add_test(pSuite2, "testTreeListRemove", testTreeListRemove)) ||
        (NULL == CU_add_test(pSuite2, "testBuildInternalTreeNode", testBuildInternalTreeNode))) {
        CU_cleanup_registry();
        return CU_get_error();
    }


    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}