/**
* this file is create by subsystem 'ETest' from EMake framework
*/

#include <stdlib.h>

#include "etest.h"

#include "leetcode.h"

static int t0005_case1()
{

    char* s, * r;

    s = "a";
    r = longestPalindrome(s);
    eexpect_str(r, "a");
    free(r);

    s = "aba";
    r = longestPalindrome(s);
    eexpect_str(r, "aba");
    free(r);

    s = "babad";
    r = longestPalindrome(s);
    eexpect_str(r, "aba");
    free(r);

    return ETEST_OK;
}


int t0005(int argc, char* argv[])
{
    (void)argc; (void)argv;

    ETEST_RUN( t0005_case1() );

    return ETEST_OK;
}

