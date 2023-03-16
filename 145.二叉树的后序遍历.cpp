/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> ret;
//        postTrev(root, ret);
//        return ret;
//    }
//
//    void postTrev(TreeNode *root, vector<int> &ret){
//        if(!root) return ;
//        if(root->left) postTrev(root->left, ret);
//        if(root->right) postTrev(root->right, ret);
//        ret.push_back(root->val);
//        return ;
//    }
   vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        if(root==nullptr) return ret;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *node = stk.top();
            ret.push_back(node->val);
            stk.pop();
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end

