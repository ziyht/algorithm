/** -------------------------------------------------------------------------------------

0010. 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

    '.' 匹配任意单个字符
    '*' 匹配零个或多个前面的那一个元素
    所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

    s 可能为空，且只包含从 a-z 的小写字母。
    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:
    输入:
        s = "aa"
        p = "a"
    输出: false
    解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:
    输入:
        s = "aa"
        p = "a*"
    输出: true
    解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3:
    输入:
        s = "ab"
        p = ".*"
    输出: true
    解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4:
    输入:
        s = "aab"
        p = "c*a*b"
    输出: true
    解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

示例 5:

    输入:
        s = "mississippi"
        p = "mis*is*p*."
    输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * -------------------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

#include "leetcode.h"

#define ENDC '\0'

bool isMatch(char * s, char * p)
{
    if(s == 0 && p == 0)
        return p == s;

    char c = 0;

    while( *p )
    {
        switch (*p) {
            case '*':   if(!c)
                        {
                            if(*s == ENDC)          // '' <-> *
                                return true;
                        } else {
                            if (c == '.')           // abc <-> .*
                                while(*s != ENDC)
                                    s++;
                            else                    // aab <-> a*
                                while(*s != ENDC && *s == c)
                                    s++;
                        }

                        p++;
                        s++;

                        break;

            case '.':   if(*s == ENDC)              // '' <-> .
                            return false;
                        p++;                        // * <-> .
                        s++;
                        c = '.';

                        break;

            default:    c = *p;

                        if (*s == *p){              // a <-> a
                            s++;
                            p++;
                        } else if (p[1] == '*'){    // a <-> c*
                            p++;
                        } else
                            return false;

                        break;
        }
    }

    return *s == ENDC;
}


