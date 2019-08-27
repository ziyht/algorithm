/**
* this file is create by subsystem 'ETest' from EMake framework
*/

#include "stdlib.h"

#include "./etest.h"

#include "leetcode.h"

static int test_two_sum()
{
    eexpect_num(1, 1);      // passed

    int arr[] =
    {
        2, 1, 4, 3, 5, 6, 9, 7, 8
    };

    {
        int *ret = two_sum(arr, 2, 3);
        eexpect_1(ret);
        eexpect_eq(arr[ret[0]] + arr[ret[1]], 3);
        free(ret);
    }

    {
        int *ret = two_sum(arr, 2, 4);
        eexpect_0(ret);
    }

    {
        int *ret = two_sum(arr, 4, 7);
        eexpect_1(ret);
        eexpect_eq(arr[ret[0]] + arr[ret[1]], 7);
        free(ret);
    }

    {
        int *ret = two_sum(arr, 9, 16);
        eexpect_1(ret);
        eexpect_eq(arr[ret[0]] + arr[ret[1]], 16);
        free(ret);
    }

    return ETEST_OK;
}



int array(int argc, char* argv[])
{
    (void)argc; (void)argv;

    ETEST_RUN( test_two_sum() );

    return ETEST_OK;
}

