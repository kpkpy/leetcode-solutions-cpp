/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL) return res;
        string s = "";
        stack<TreeNode*> stk;
        stk.push(root);
        s+=to_string(root->val); s+="->";
        while(!stk.empty()){
            TreeNode *tmp = stk.top();
            stk.pop();
            if(tmp->right) stk.push(tmp->right);
            if(tmp->left) stk.push(tmp->left);
        }
    }
};
// @lc code=end

