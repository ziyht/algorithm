/** -------------------------------------------------------------------------------------

0009. 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

    输入: 121
    输出: true

示例 2:

    输入: -121
    输出: false
    解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:

    输入: 10
    输出: false
    解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶:
    你能不将整数转为字符串来解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * -------------------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

#include "leetcode.h"


bool isPalindrome(int x)
{
    // 负数不是回文数
    if(x < 0)
        return false;

    // 非 0 的 10 的倍数不是回文数
    if(x && (x % 10 == 0))
        return false;

    // 这种方法最多只处理一半的位数，不用考虑溢出问题
    // 输入位数为奇数时，如 abcba，处理到中间的 c
    //
    //             ___ -> check = abc
    //           abcba ->     x = ab
    //
    // 输入位数为偶数时，如 abccba，处理一半
    //
    //              ___ -> check = abc
    //           abccba ->     x = abc
    int check = 0;
    while(x > check)
    {
        check = check * 10 + x % 10;
        x    /= 10;
    }

    // input  121   1221
    //     x    1   12
    // check   12   12
    return x == check || x == check / 10;
}


