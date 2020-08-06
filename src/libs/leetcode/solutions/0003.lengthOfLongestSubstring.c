/** -------------------------------------------------------------------------------------

0003. 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

    输入: "abcabcbb"
    输出: 3
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * -------------------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <string.h>

#include "leetcode.h"

int lengthOfLongestSubstring(char* s)
{
    int offsets[256];       // 记录当前字符上一次出现的位置

    if(!s)
        return 0;

    int  len  = 0,          // 当前长度
         mlen = 0,          // 最大长度，结果
         idx  = 0;          //
    char c;

    memset(offsets, -1, sizeof(offsets));

#define __SAME_CHAR_SPAN(idx, c) (idx - offsets[(int)c])     // 当前字符到上一次出现之间的区间长度

    //! traverse the string
    while((c = s[idx]))
    {
        //! 当前字符从未出现，则未重复字符数加 1
        if(offsets[(int)c] == -1)
        {
            len ++;
        }
        else
        {
            //! 1: 如果当前字符的区间长度 > len（上一次统计区间长度）
            //!    说明当前字符不在上一次统计之内
            //!    统计长度加 1

            if(__SAME_CHAR_SPAN(idx, c) > len)
                len ++;

            //! 2: 否着，说明 当前字符在上一次统计中，当前无重复统计长度须从上一次此字符出现的位置截断
            //!    那么更新当前长度为 当前字符重复出现的区间长度
            else
                len = __SAME_CHAR_SPAN(idx, c);

        }

        if(mlen < len)
            mlen = len;

        //! 更新当前字符的最新出现位置
        offsets[(int)c] = idx++;
    }

    return mlen;
}
