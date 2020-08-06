#ifndef LEETCODE_H_
#define LEETCODE_H_

#include <stdbool.h>

typedef struct ListNode {
     int val;
     struct ListNode *next;
}ListNode_t;


int*        two_sum(int arr[], int cnt, int target, int* returnSize);                       // 0001   Easy
ListNode_t* addTwoNumbers(ListNode_t* l1, ListNode_t* l2);                                  // 0002   Mediam
int         lengthOfLongestSubstring(char * s);                                             // 0003   Mediam
double      findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);   // 0004
char*       longestPalindrome(char* s);                                                     // 0005   Hard
char*       convert(char * s, int numRows);                                                 // 0006
int         reverse(int x);                                                                 // 0007
int         myAtoi(char *s);                                                                // 0008
bool        isPalindrome(int x);                                                            // 0009
bool        isMatch(char * s, char * p);                                                    // 0010   Hard


#endif
