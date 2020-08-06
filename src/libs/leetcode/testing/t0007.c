/**
* this file is create by subsystem 'ETest' from EMake framework
*/

#include "etest.h"

#include "leetcode.h"

static int t0007_case1()
{
    eexpect_num(reverse(123), 321);


    return ETEST_OK;
}



int t0007(int argc, char* argv[])
{
    (void)argc; (void)argv;

    ETEST_RUN( t0007_case1() );

    return ETEST_OK;
}

