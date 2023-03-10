/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cp = dummy; ListNode *tmp;
        while(cp->next!=nullptr){
            if(cp->next->val==val){
                tmp = cp->next;
                cp->next = cp->next->next;
                delete tmp;
            }
            else{
                cp = cp->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

