/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
#include "include.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//    bool hasCycle(ListNode *head) {
//        ListNode *cp1, *cp2;
//        cp1 = head; cp2 = head;
//        while(cp2&&cp2->next){
//            cp2 = cp2->next;
//            cp2 = cp2->next;
//            if(cp1==cp2) return true;
//            cp1=cp1->next;
//        }
//        return false;
//    }
    bool hasCycle(ListNode *head){
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
// @lc code=end

