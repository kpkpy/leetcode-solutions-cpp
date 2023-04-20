/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
//class Solution {
//public:
//    unordered_map<TreeNode*, int> umap;
//    int rob(TreeNode* root) {
//        if(root==NULL) return 0;
//        if(root->left==NULL&&root->right==NULL) return root->val;
//        if(umap[root]!=0) return umap[root];
//
//        int val1 = root->val;
//        if(root->left!=NULL) val1+=rob(root->left->left) + rob(root->left->right);
//        if(root->right!=NULL) val1+=rob(root->right->left) + rob(root->right->right);
//
//        int val2 = rob(root->left) + rob(root->right);
//        umap[root] = max(val1, val2);
//        return umap[root];
//    }
//};

class Solution {
    public:
    int rob(TreeNode *root){
        vector<int> temp =robTree(root);
        return max(temp[0], temp[1]);
    }

    vector<int> robTree(TreeNode *cur){
        if(cur==NULL) return vector<int>{0, 0};

        vector<int> left = robTree(cur->left);
        vector<int> right= robTree(cur->right);

        int val1 = cur->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {val2, val1};
    }
};
// @lc code=end

