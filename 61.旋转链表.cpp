/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==nullptr) return head;
        ListNode * lencp = head; // 用于求长度的cp
        int len= 1;
        while(lencp->next != nullptr){
            lencp = lencp->next;
            len++;
        }
        k%=len;
        ListNode * front = head;
        for(int i=0; i<k; i++){
            front = front->next;
        }
        ListNode * cp = head;
        while(front->next != nullptr){
            front = front -> next;
            cp = cp -> next;
        }
        front -> next = head;
        head = cp -> next;
        cp -> next =nullptr;
        return head;
    }
};
// @lc code=end

