/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        int max=0;
        if(root==NULL) return 0;
        dfs(root, 1, max);
        return max;
    }

    void dfs(TreeNode* root, int depth, int &max){
        if(root==NULL) return ;
        if(depth>max) max = depth;
        if(root->left) dfs(root->left, depth+1, max);
        if(root->right) dfs(root->right, depth+1, max);
        return ;
    }
};
// @lc code=end

