/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *cp1, *cp2;
        cp1 = head; cp2 = head;
        while(cp2&&cp2->next){
            cp1=cp1->next;
            cp2 = cp2->next->next;
            if(cp1==cp2) {
                ListNode *index1 = cp2;
                ListNode *index2 = head;
                while(index1!=index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            };
        }
        return nullptr;
    }
};
// @lc code=end

