#ifndef LEETCODE_H_
#define LEETCODE_H_

typedef struct ListNode {
     int val;
     struct ListNode *next;
}ListNode_t;


int*        two_sum(int arr[], int cnt, int target, int* returnSize);                 // 001   Easy
ListNode_t* addTwoNumbers(ListNode_t* l1, ListNode_t* l2);

#endif
