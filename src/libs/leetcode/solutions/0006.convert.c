/** -------------------------------------------------------------------------------------

0006. 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

    L   C   I   R
    E T O E S I I G
    E   D   H   N

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

示例 1:

    输入: s = "LEETCODEISHIRING", numRows = 3
    输出: "LCIRETOESIIGEDHN"

示例 2:

    输入: s = "LEETCODEISHIRING", numRows = 4
    输出: "LDREOEIIECIHNTSG"
    解释:

        L     D     R
        E   O E   I I
        E C   I H   N
        T     S     G

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * -------------------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <string.h>

#include "leetcode.h"

char * convert(char * s, int numRows){

    if(!s)
        return 0;

    int len = strlen(s);

    if(len < 2 || numRows < 2)
        return strdup(s);

    char* out = malloc(len + 1);
    out[len] = 0;


    int cur = 0;    //! 标记当前需写入的字符位置

    //! 依此写入每行的字符
    for(int row = 0; row < numRows; row++ )
    {
        int step = 2 * numRows - 2;

        //! p 为迭代字符
        //! 对于每一行，初始字符均为 s[row]
        int p = row;

        //! 对于 第一行 和 最后一行
        //! 每次 迭代 后 p 需向后偏移 2 * numRows - 2
        if(row == 0 || row == numRows - 1)
        {
            while(p < len)
            {
                out[cur++] = s[p];
                p += step;
            }
        }
        //! 对于中间的行
        //! 第一次迭代后，需向后偏移 step - 2*row 个字符
        //! 第二次迭代后，需向后偏移 2*row 个字符
        //! 依此类推
        else
        {
            int cur_step = step - 2*row;

            while(p < len){

                out[cur++] = s[p];
                p += cur_step;
                cur_step = step - cur_step;
            }
        }
    }

    return out;
}
