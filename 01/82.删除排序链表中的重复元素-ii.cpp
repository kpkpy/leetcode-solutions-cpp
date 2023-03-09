/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
//        ListNode *dummy = new ListNode(0, head);
//        cp = dummy;
//        while(cp->next&&cp->next->next){
//            if(cp->next->val==cp->next->next->val){
//                int x = cp->next->val;
//                while(cp->next&&cp->next->val==x){
//                    cp->next = cp->next->next;
//                }
//            }
//            else{
//                cp = cp->next;
//            }
//        }
//        return dummy->next;
//    }
    ListNode* deleteDuplicates(ListNode* head){
        ListNode *cp;
        ListNode *dummy = new ListNode(0, head);
        ListNode *cpn ,*cpnn;
        for(cp = dummy; cp->next;){
            cpn = cp->next;
            if(!cpn->next) break;
            cpnn = cpn->next;
            if(cpnn->val==cpn->val){
                while(cpnn&&cpn->val == cpnn->val){
                    cpnn = cpnn->next;
                }
                cp->next = cpnn;
            }
            else cp=cp->next;
        }
        return dummy->next;
    }
};
// @lc code=end

