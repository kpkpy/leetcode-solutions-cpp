/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<int> path;
    vector < vector<int>> res;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum){
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode *root, int targetSum){
        if(root==NULL)
            return;

        path.emplace_back(root->val);
        targetSum -= root->val;
        if(targetSum==0 && root->left==NULL && root->right==NULL){
            res.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
        return;
    }
};
// @lc code=end

