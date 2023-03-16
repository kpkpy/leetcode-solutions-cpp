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
        if(root->left==NULL && root->right==NULL) return true;
        return compare(root->left, root->right);
    }

    bool compare(TreeNode *left, TreeNode *right){
        if(left==NULL&&right!=NULL) return false;
        else if(left!=NULL&&right==NULL) return false;
        else if(left==NULL&&right==NULL) return true;
        else if(left->val!=right->val) return false;
        else{
            bool outside = compare(left->left, right->right);
            bool inside = compare(left->right, right->left);
            return outside&&inside;
        }
        return false;
    }
};
// @lc code=end

