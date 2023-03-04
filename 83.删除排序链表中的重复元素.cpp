/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
//    ListNode* deleteDuplicates(ListNode* head) {
//        ListNode *cp;
//        cp = head;
//        if(!head) return head;
//        if(!head->next) return head;
//        while(cp->next){
//            if(cp->val == cp->next->val){
//                cp-> next = cp->next->next;
//            }
//            else cp=cp->next;
//        }
//        return head;
//    }
    ListNode* deleteDuplicates(ListNode* head){
        if(!head||!head->next){
            return head;
        }
        head->next = deleteDuplicates(head->next);
        if(head->val==head->next->val) head = head->next;
        return head;
    }
};
// @lc code=end

