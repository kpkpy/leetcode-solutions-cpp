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
//    int sumOfLeftLeaves(TreeNode* root) {
//        if(root==NULL) return 0;
//        if(root->left==NULL&&root->right==NULL) return 0;
//
//        int suml = sumOfLeftLeaves(root->left);
//        int sumr = sumOfLeftLeaves(root->right);
//        if(root->left&&!root->left->left&&!root->left->right) {
//            suml = root->left->val;
//        }
//        int sum = suml+sumr;
//        return sum;
//    }
    int sumOfLeftLeaves(TreeNode *root){
        stack<TreeNode*> stk;
        if(root==NULL) return 0;
        stk.push(root); int sum = 0;
        while(!stk.empty()){
            TreeNode *node = stk.top();
            stk.pop();
            if(node->left&&!node->left->right&&!node->left->left){
                sum+=node->left->val;
            }
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
        }
        return sum;
    }
};
// @lc code=end

