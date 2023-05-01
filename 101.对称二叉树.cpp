/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return compare(root->left, root->right);
    }

    bool compare(TreeNode *left, TreeNode* right){
        if(left==NULL&&right==NULL) return true;
        else if(left!=NULL&&right!=NULL){
            if(left->val!=right->val) return false;
            return compare(left->right, right->left) && compare(left->left, right->right);
        }
        else return false;
    }   
};
// @lc code=end

