/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        int h = getHeight(root);
        return h==-1? false : true;
    }

    int getHeight(TreeNode *root) {
        if(root==NULL) return 0;
        int lefth = getHeight(root->left);
        int righth = getHeight(root->right);
        if(lefth==-1||righth==-1) return -1;
        else return abs(righth-lefth)>1? -1 : max(lefth, righth)+1;
    }
};
// @lc code=end

