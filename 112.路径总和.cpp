/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        stack<pair<TreeNode*, int> > stk;
        stk.push(pair<TreeNode*, int>(root, root->val));
        while(!stk.empty()){
            pair<TreeNode*, int> tmp = stk.top();
            stk.pop();
            if(tmp.first->left==NULL&&tmp.first->right==NULL&&tmp.second==targetSum){
                return true;
            }
            if(tmp.first->right){
                stk.push(pair<TreeNode*, int>(tmp.first->right, tmp.second+tmp.first->right->val));
            }
            if(tmp.first->left){
                stk.push(pair<TreeNode*, int>(tmp.first->left, tmp.second+tmp.first->left->val));
            }
        }
        return false;
    }
};
// @lc code=end

