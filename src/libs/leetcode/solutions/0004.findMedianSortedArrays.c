/** -------------------------------------------------------------------------------------

0004. 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

    nums1 = [1, 3]
    nums2 = [2]

    则中位数是 2.0

示例 2:

    nums1 = [1, 2]
    nums2 = [3, 4]

    则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * -------------------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <string.h>

#include "leetcode.h"

/**
 *   o((m + n)/2)
 *
 */
double findMedianSortedArrays1(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int cnt = nums1Size + nums2Size;

    int mid = (cnt - 1) / 2;
    int idx1 = 0, idx2 = 0;
    int val1 = 0, val2 = 0;

    int l, r;

    for(int i = 0; i < cnt; i++)
    {
        //! 遍历两个数组， 每次获取最新值存放到 val2 中
        if(idx1 < nums1Size)
        {
            if(idx2 < nums2Size)
            {
                if(nums1[idx1] <= nums2[idx2])
                    val2 = nums1[idx1++];
                else
                    val2 = nums2[idx2++];
            }
            else
            {
                val2 = nums1[idx1++];
            }
        }
        else
        {
            val2 = nums2[idx2++];
        }

        //! 如果已遍历到 中位数 的位置
        if(i >= mid)
        {
            if(cnt % 2 == 1)
            {
                return val2;
            }

            if(i == mid)
                val1 = val2;
            else
                return (val1 + val2) / 2.0;
        }
    }

    return 0;
}

/**
 * O(log(min(m, n)))
 *
 *
 * 原则：对于查找两个有序数组的中位数，只要确定其中一个数组的分割点(i)，那么另一个数组的分割点(j)也已确定
 *      j = ( m + n + 1 ) / 2 − i
 *
 * 方法：使用二分查找的方式查找元素较小的那一个数组的分割点即可
 *
 *     分割点确定（假设 i，j 分别为数组 a， b 的分割点），符合以下条件之一：
 *         1. 查找时 i 或 j 达到边界
 *         2. 被分割的 左边的值 < 右边的值（或者需符合原始排序），同时满足：
 *            左上 < 右下
 *            左下 < 右上
 *
 */
double findMedianSortedArrays(int* a, int m, int* b, int n)
{
    if(m > n)
        return findMedianSortedArrays(b, n, a, m);

    int l = 0, r = m, i, j;

    while ( l <= m )
    {
        i = (l + r) / 2;
        j = (m + n + 1) / 2 - i;

        //! 左下 > 右上, 右上值过小，分割点需右移
        if ( i != m && j != 0 && b[j - 1] > a[i])
        {
            l = i + 1;
        }
        //! 左上 > 右下，左上值过大，分割点需左移
        else if( i != 0 && j != n && a[i - 1] > b[j])
        {
            r = i - 1;
        }
        //! 此时符合以下条件之一：
        //!
        //! 1. i 达到边界
        //! 2. j 达到边界
        //! 3. 分割点符合条件
        //!
        else{

            int lMax, rMin;

            //! 确定 左边的值
            if     ( i == 0 ) { lMax = b[j - 1];}
            else if( j == 0 ) { lMax = a[i - 1];}
            else{
                lMax = a[i - 1];
                if(lMax < b[j - 1])
                    lMax = b[j - 1];
            }

            //! 如果是 m + n 为奇数，则说明已找到中位数
            if( (m + n) % 2 == 1 )
                return lMax;

            //! 确定右边的值
            if     ( i == m) { rMin = b[j]; }
            else if( j == n) { rMin = a[i]; }
            else{
                rMin = b[j];
                if (rMin > a[i])
                    rMin = a[i];
            }

            return (lMax + rMin) / 2.0;
        }
    }

    return 0.0;
}
