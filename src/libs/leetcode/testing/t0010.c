/**
* this file is create by subsystem 'ETest' from EMake framework
*/

#include "etest.h"

#include "leetcode.h"

static int t0010_case1()
{
    struct Case
    {
        char* s;
        char* p;
        bool  expect;
    } cases[] = {
        {"aa"         , "a"         , false},
        {"aa"         , "a*"        , true },
        {"ab"         , ".*"        , true },
        {"aab"        , "c*a*b"     , true },
        {"mississippi", "mis*is*p*.", false},

        {"ab" , "ab" , true },
        {"ab" , "ab ", false},
        {"ab ", "ab" , false},

    };
    int cnt = sizeof(cases) / sizeof(struct Case);
    for (int i = 0; i < cnt; i++){
        struct Case* c = &cases[i];
        eexpect_eq( isMatch(c->p, c->s), c->expect );
    }

    return ETEST_OK;
}

int t0010(int argc, char* argv[])
{
    (void)argc; (void)argv;

    ETEST_RUN( t0010_case1() );

    return ETEST_OK;
}

