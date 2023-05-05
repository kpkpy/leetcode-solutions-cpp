/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        dfs(root, sum);
        return sum;
    }

    void dfs(TreeNode* root, int &sum){
        if(root==NULL) return ;
        if(root->left){
            if(root->left->left==NULL&&root->left->right==NULL) sum+=root->left->val;
            dfs(root->left, sum);
        }
        if(root->right){
            dfs(root->right, sum);
        }
        return;
    }
};
// @lc code=end

