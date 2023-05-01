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
//        vector<int> res;
//        postOrder(root, res);
//        return res;
//    }
//
//    void postOrder(TreeNode* root, vector<int> &res){
//        if(root==NULL) return;
//        if(root->left) postOrder(root->left, res);
//        if(root->right) postOrder(root->right, res);
//        res.push_back(root->val);
//        return ;
//    }
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> stk;
        if(root==NULL) return res;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* tmp=stk.top();
            stk.pop();
            res.push_back(tmp->val);
            if(tmp->left) stk.push(tmp->left);
            if(tmp->right) stk.push(tmp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

