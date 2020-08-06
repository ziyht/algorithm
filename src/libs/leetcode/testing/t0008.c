/**
* this file is create by subsystem 'ETest' from EMake framework
*/

#include "etest.h"

#include "leetcode.h"

static int t0008_case1()
{
    eexpect_num(myAtoi("-91283472332"), -2147483648);      // passed
    eexpect_num(myAtoi("+1"), 1);
    eexpect_num(myAtoi("2147483800"), 2147483647);

    return ETEST_OK;
}


int t0008(int argc, char* argv[])
{
    (void)argc; (void)argv;

    ETEST_RUN( t0008_case1() );

    return ETEST_OK;
}

