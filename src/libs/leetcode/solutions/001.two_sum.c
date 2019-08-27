/** -------------------------------------------------------------------------------------

001. 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

    给定 nums = [2, 7, 11, 15], target = 9

    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * -------------------------------------------------------------------------------------
 */

#include <stdlib.h>

#include "leetcode.h"

struct obj_s{
    int val;
    int idx;
};

static int _cmp(const void* a, const void* b)
{
    return ((struct obj_s*)a)->val - ((struct obj_s*)b)->val;
}

int* two_sum(int arr[], int cnt, int target)
{
    int i, j;

    if(cnt < 2)
        return 0;

    //! step 1:
    //! alloc a memory buffer to store the source idx and value of each element
    //!
    struct obj_s *objs = malloc(cnt * sizeof(*objs));
    for(int i = 0; i < cnt; i++)
    {
        objs[i].idx = i;
        objs[i].val = arr[i];
    }

    //! step 2: sort it before start
    qsort(objs, cnt, sizeof(*objs), _cmp);

    //! step 3: searching
    {
        i = 0;              // start from begining
        j = cnt - 1;        // start from end

        while(i < j)
        {
            int need = target - objs[i].val;

            if(need > objs[j].val)
            {
                //! the needed val is bigger than max number in arr
                //! so we need to move i -> j
                while(++i < j && objs[i].val == objs[i - 1].val);
            }
            else if(need > objs[j].val)
            {
                //! the needed val is less than max number in arr
                //! so we need to move j -> i
                while(i < --j && objs[j].val == objs[i + 1].val);
            }
            else
            {
                //! ok, found it!!!
                int * ret = malloc(2 * sizeof(int));

                ret[0] = objs[i].idx;
                ret[1] = objs[j].idx;

                return ret;
            }
        }
    }

    return 0;
}
