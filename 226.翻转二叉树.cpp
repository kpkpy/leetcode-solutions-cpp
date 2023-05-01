/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
//    TreeNode* invertTree(TreeNode* root) {
//        postswap(root);
//        return root;
//    }
//
//    void postswap(TreeNode *root){
//        if(root==NULL) return;
//        if(root->left||root->right){
//            swap(root->left, root->right);
//        }
//        else if(root->left){
//            root->right = root->left;
//            root->left = NULL;
//        }
//        else{
//            root->left = root->right;
//            root->right = NULL;
//        }
//        postswap(root->left);
//        postswap(root->right);
//        return ;
//    }
    
    TreeNode* invertTree(TreeNode* root){
        stack<TreeNode*> stk;
        if(root==NULL) return root;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *tmp = stk.top();
            stk.pop();
            swap(tmp->left, tmp->right);
            if(tmp->right) stk.push(tmp->right);
            if(tmp->left) stk.push(tmp->left);
        }
        return root;
    }
};
// @lc code=end

