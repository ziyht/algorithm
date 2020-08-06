/**
* this file is create by subsystem 'ETest' from EMake framework
*/

#include "etest.h"

#include "leetcode.h"

static int t0009_case1()
{
    eexpect_1(isPalindrome(121));
    eexpect_1(isPalindrome(1221));


    return ETEST_OK;
}


int t0009(int argc, char* argv[])
{
    (void)argc; (void)argv;

    ETEST_RUN( t0009_case1() );

    return ETEST_OK;
}

