/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la=0; int lb=0;
        ListNode *cpa=headA; ListNode *cpb=headB;
        while(cpa->next){
            cpa=cpa->next;
            la++;
        }
        while(cpb->next){
            cpb=cpb->next;
            lb++;
        }
        if(la<lb){
            swap(la, lb);
            swap(headA, headB);
        }
        cpa=headA; cpb=headB;
        int gap = la-lb;
        while(gap-->0){
            cpa = cpa->next;
        }
        while(cpa){
            if(cpa==cpb){
                return cpa;
            }
            cpa=cpa->next;
            cpb=cpb->next;
        }
        return nullptr;
    }
};
// @lc code=end

