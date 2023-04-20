/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
//    ListNode* partition(ListNode* head, int x) {
//        ListNode *head1, *cp1;
//        ListNode *head2, *cp2;
//        head1 = new ListNode(0, nullptr);
//        head2 = new ListNode(0, nullptr);
//        cp1 = head1; cp2 = head2;
//        while(head){
//            if(head->val<x){
//                cp1->next = head;
//                cp1 = cp1->next;
//            }
//            else{
//                cp2->next = head;
//                cp2=cp2->next;
//            }
//            head = head->next;
//        }
//        cp2->next=nullptr;
//        cp1->next = head2->next;
//        return head1->next;
//    }

    ListNode* partition(ListNode* head, int x){
        ListNode *head1, *cp1;
        ListNode *head2, *cp2;
        ListNode *cp=head;
        head1 = new ListNode(0, nullptr);
        head2 = new ListNode(0, nullptr);
        cp1 = head1; cp2 = head2;
        while(cp!=nullptr){
            if(cp->val<x){
                cp1->next = new ListNode(cp->val, nullptr);
                cp1 = cp1->next;
            }
            else{
                cp2->next = new ListNode(cp->val, nullptr);
                cp2 = cp2->next;
            }
            cp = cp->next;
        }
        cp1->next = head2->next;
        return head1->next;
    }
};
// @lc code=end

