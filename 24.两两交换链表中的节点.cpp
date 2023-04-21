/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include "include.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cp = dummy;
        while(cp->next!=NULL&&cp->next->next!=NULL){
            ListNode *tmp1 = cp->next;
            ListNode *tmp2 = cp->next->next->next;

            cp->next = cp->next->next;
            cp->next->next = tmp1;
            cp->next->next->next = tmp2;

            cp = cp->next->next;
        }
        return dummy->next;
    }
};
// @lc code=end

