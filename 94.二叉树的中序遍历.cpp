/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        inorder(root, res);
//        return res;
//    }
//
//    void inorder(TreeNode *root, vector<int> &res){
//        if(root==NULL) return;
//        if(root->left) inorder(root->left, res);
//        res.push_back(root->val);
//        if(root->right) inorder(root->right, res);
//        return ;
//    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while(!stk.empty()||cur!=NULL){
            if(cur!=NULL){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
// @lc code=end

