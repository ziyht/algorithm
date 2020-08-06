/** -------------------------------------------------------------------------------------

0005. 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。

示例 2：

    输入: "cbbd"
    输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * -------------------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <string.h>

#include "leetcode.h"

static char* __get_help_string(char* s, int len, char c)
{

    char* out = malloc(len*2 + 1);
    char* p = out;

    for(int i = 0; i < len; i++)
    {
        p[0] = c;
        p[1] = s[i];
        p += 2;
    }

    p[0] = c;

    return out;
}

static int __min(int a, int b) { return a < b ? a : b;}

char* longestPalindrome(char* s)
{
    int lens = strlen(s);

    if(lens <= 1)
        return s ? strdup(s) : 0;

    char* s2 = __get_help_string(s, lens, '#');
    int lens2 = lens * 2 + 1;

    int curR = 0;       // 当前位置对应的回文串的最右侧位置
    int curP = 0;       // 当前位置
    int maxR = 0;       // 最大回文串的半径
    int maxP = 0;       // 最大回文串的中心位置
    int* rarr = calloc(1, lens2 * sizeof(int));  // 所有字符对应的 (回文串的半径 + 1)

    for(int i = 0; i < lens2; i++)
    {
        //! 当前字符在 curR 左边，
        //! 那么 i 对应的回文半径可以直接由对称于 curP 的 (2 * curP - i) 获取
        //! 但是注意，获取的回文半径对 i 来说仅为 它的初始值
        if( i < curR )
        {
            rarr[i] = __min( rarr[2 * curP - i], curR - i );
        }
        //!
        else
        {
            rarr[i] = 1;
        }

        //! 尝试扩展当前位置
        while( i - rarr[i] >= 0     &&
               i + rarr[i] < lens2 &&
               s2[i - rarr[i]] == s2[i + rarr[i]]
              )
        {
            rarr[i]++;
        }

        if( i + (rarr[i] - 1) > curR )
        {
            curR = i + (rarr[i] - 1);
            curP = i;
        }

        if( maxR <= rarr[i] )
        {
            maxR = rarr[i];
            maxP = i;
        }
    }

    maxR--;
    s2  = realloc(s2, maxR + 1);

    memcpy(s2, s + (maxP - maxR) / 2, maxR);
    s2[maxR] = 0;

    free(rarr);

    return s2;
}
