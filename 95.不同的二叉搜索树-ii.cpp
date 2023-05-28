/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end){
        if(start > end)
            return {nullptr};
        vector<TreeNode *> alltrees;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftNodes = generateTrees(start, i - 1);
            vector<TreeNode *> rightNodes = generateTrees(i + 1, end);

            for(auto &left : leftNodes){
                for(auto &right : rightNodes){
                    TreeNode *curr = new TreeNode(i);
                    curr->left = left;
                    curr->right = right;
                    alltrees.emplace_back(curr);
                }
            }
        }
        return alltrees;
    }
};

// @lc code=end

