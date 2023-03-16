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
//        vector<int> ret;
//        inTrev(root, ret);
//        return ret;
//    }
//
//    void inTrev(TreeNode *root, vector<int> &ret){
//        if(!root) return ;
//        if(root->left) inTrev(root->left, ret);
//        ret.push_back(root->val);
//        if(root->right)inTrev(root->right, ret);
//        return ;
//    }
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        if(root!=NULL) stk.push(root);
        while(!stk.empty()){
            TreeNode *node;
            if(stk.top()!=NULL){
                node = stk.top();
                stk.pop();
                if(node->right) stk.push(node->right);
                stk.push(node);
                stk.push(NULL);
                if(node->left) stk.push(node->left);
            }
            else{
                stk.pop();
                node = stk.top();
                ret.push_back(node->val);
                stk.pop();
            }
        }
        return ret;
    }
};
// @lc code=end

