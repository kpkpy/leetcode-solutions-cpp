/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include "include.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
//private:
//    TreeNode *pre = NULL;
//    int res = INT_MAX;
//public:
//    int getMinimumDifference(TreeNode* root) {
//        traversal(root);
//        return res;
//    }
//
//    void traversal(TreeNode *cur){
//        if(cur==NULL) return;
//        traversal(cur->left);
//        if(pre!=NULL){
//            res = min(res, cur->val-pre->val);
//        }
//        pre = cur;
//        traversal(cur->right);
//    }
    public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode *pre = NULL;
        TreeNode *cur = root;
        int res = INT_MAX;
        stack<TreeNode*> stk;
        while(cur!=NULL||!stk.empty()){
            if(cur!=NULL){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                cur = stk.top();
                stk.pop();
                if(pre!=NULL) res = min(res, cur->val-pre->val);
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }
};
// @lc code=end

