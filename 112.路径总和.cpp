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
//    bool hasPathSum(TreeNode* root, int targetSum) {
//        stack<pair<TreeNode*, int> > stk;
//        if(root==NULL) return false;
//        stk.push(pair<TreeNode*, int>(root, root->val));
//        while(!stk.empty()){
//            pair<TreeNode* ,int> node = stk.top();
//            stk.pop();
//            if(node.second==targetSum&&!node.first->left&&!node.first->right) return true;
//            if(node.first->left) {
//                stk.push(pair<TreeNode* , int>(node.first->left, node.second+node.first->left->val));
//            }
//            if(node.first->right) {
//                stk.push(pair<TreeNode* , int>(node.first->right, node.second+node.first->right->val));
//            }
//        }
//        return false;
//    }
    
    bool hasPathSum(TreeNode *root, int targetSum){
        if(!root) return false;
        if(!root->left&&!root->right&&targetSum==root->val) return true;
        return hasPathSum(root->left,  targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
 };
// @lc code=end

