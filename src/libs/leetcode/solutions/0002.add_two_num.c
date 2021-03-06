/** -------------------------------------------------------------------------------------

002. 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * -------------------------------------------------------------------------------------
 */

#include <stdlib.h>

#include "leetcode.h"

#define _ln_new()    malloc(sizeof(ListNode_t))

//! 创建一个新节点到末尾，并设置值
#define _ln_cat(n, v)       \
do{                         \
    n->next = _ln_new();    \
    n       = n->next;      \
    n->val  = v;            \
}while (0)

ListNode_t* addTwoNumbers(ListNode_t* l1, ListNode_t* l2)
{
    int sum;
    int in = 0;

    //! 在 栈 中创建一个 head， 方便后续逻辑处理
    ListNode_t  head = {0, 0};
    ListNode_t* cur  = &head;

    //! step1: 处理 l1 和 l2 同时 有效 的情况
    while(l1 && l2)
    {
        sum  = l1->val + l2->val + in;
        in   = sum > 9;
        sum %= 10;

        _ln_cat(cur, sum);

        l1 = l1->next;
        l2 = l2->next;
    }

    //! step2.1: 处理 l1 和 l2 同时 无效 的情况
    if(!l1 && !l2)
    {
        if(in)
        {
            _ln_cat(cur, 1);
        }
    }

    //! step2.2: 处理 只剩余 一个 有效链表的 情况
    else
    {
        if(!l1) l1 = l2;

        while(in && l1)
        {
            sum  = l1->val + in;
            in   = sum > 9;
            sum %= 10;

            _ln_cat(cur, sum);

            l1 = l1->next;
        }

        if(in)
            _ln_cat(cur, 1);

        while(l1)
        {
            _ln_cat(cur, l1->val);

            l1 = l1->next;
        }
    }

    cur->next = 0;

    return head.next;
}
