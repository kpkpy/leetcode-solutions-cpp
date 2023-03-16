/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> ret;
//        prevTrev(root, ret);
//        return ret;
//    }
//
//    void prevTrev(TreeNode * root, vector<int> & ret){
//        if(!root) return;
//        ret.push_back(root->val);
//        if(root->left) prevTrev(root->left, ret);
//        if(root->right) prevTrev(root->right, ret);
//        return ;
//    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        if(root==nullptr) return ret;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *node = stk.top();
            ret.push_back(node->val);
            stk.pop();
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        return ret;
    }
};
// @lc code=end

