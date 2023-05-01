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
// recursive traversal
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> ret;
//        if(root!=NULL) preOrder(root, ret);
//        return ret;
//    }
//
//    void preOrder(TreeNode *root, vector<int> &ret){
//        if(root==NULL) return;
//        ret.push_back(root->val);
//        if(root->left) preOrder(root->left, ret);
//        if(root->right) preOrder(root->right, ret);
//
//        return ;
//    }
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> stk;
        vector<int> res;
        if(root==NULL) return res;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            if(tmp->right) stk.push(tmp->right);
            if(tmp->left) stk.push(tmp->left);
        }
        return res;
    }
};
// @lc code=end

