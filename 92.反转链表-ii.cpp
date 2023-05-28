/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *leftpre = dummy;

        for (int i = 0; i < left-1; i++){
            leftpre = leftpre->next;
        }

        ListNode *rightpre = dummy;
        for (int i = 0; i < right; i++){
            rightpre = rightpre->next;
        }

        ListNode *righthead = rightpre->next;
        ListNode *lefthead = leftpre->next;
        rightpre->next = nullptr;
        reverse(lefthead);

        leftpre->next = rightpre;
        lefthead->next = righthead;

        return dummy->next;
    }

    ListNode *reverse(ListNode *head){
        ListNode *tmp;
        ListNode *cur = head;
        ListNode *pre = NULL;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
// @lc code=end

