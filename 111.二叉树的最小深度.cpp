/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int min = INT_MAX;
        dfs(root, 1, min);
        return min;
    }
    
    void dfs(TreeNode* root, int depth, int& min){
        if(root==NULL) return ;
        if(root->right==NULL&&root->left==NULL) if(depth<min) min = depth;
        if(root->left) dfs(root->left, depth+1, min);
        if(root->right) dfs(root->right, depth+1, min);
        return ;
    }
};
// @lc code=end

