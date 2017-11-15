/*
 * File:   tests.c
 * Author: karen
 *
 * Created on 12/11/2017, 22:00:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../charpath.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
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

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("tests", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreateEmptyCharHash", testCreateEmptyCharHash)) ||
            (NULL == CU_add_test(pSuite, "testCreateCharData", testCreateCharData))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
