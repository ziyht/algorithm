/**
* this file is create by subsystem 'ETest' from EMake framework
*/

#include <etest.h>

static int 0005_case1()
{
    eexpect_num(1, 1);      // passed

    return ETEST_OK;
}

static int 0005_case2()
{
    eexpect_num(1, 0);      // will failed

    return ETEST_OK;
}


int 0005(int argc, char* argv[])
{
    (void)argc; (void)argv;

    ETEST_RUN( 0005_case1() );
    ETEST_RUN( 0005_case2() );

    return ETEST_OK;
}

