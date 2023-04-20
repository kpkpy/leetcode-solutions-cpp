/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
//    TreeNode* insertIntoBST(TreeNode* root, int val) {
//        if(root==NULL){
//            TreeNode *node = new TreeNode(val);
//            return node;
//        }
//        if(root->val>val){
//            root->left = insertIntoBST(root->left, val);
//        }
//        else if(root->val<val) {
//            root->right = insertIntoBST(root->right ,val);
//        }
//        return root;
//    }
    TreeNode* insertIntoBST(TreeNode *root, int val){
        TreeNode *pre=NULL;
        TreeNode *cur = root;
        TreeNode *node = new TreeNode(val);
        if(!root) return node;
        while(cur!=NULL){
            pre = cur;
            if(cur->val>val){
                cur = cur->left;
            }
            else {
                cur = cur ->right;
            }
        }
        if(pre->val > val) {
            pre->left =  node;
        }
        else {
            pre->right = node;
        }
        return root;
    }
};
// @lc code=end

