/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
//    bool isValidBST(TreeNode* root) {
//        if(!root) return true;
//        if(root->left&&root->left->val >= root->val) return false;
//        if(root->right&&root->right->val <= root->val) return false;
//        return isValidBST(root->left) && isValidBST(root->right);
//    }
//};

class Solution {
    public:
    bool isValidBST(TreeNode *root) {
        vector<int> nums;
        traversal(root, nums);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=nums[i-1]) return false;
        }
        return true;
    }
    
    void traversal(TreeNode* root, vector<int>& nums){
        if(root==NULL) return ;
        if(root->left) traversal(root->left, nums);
        nums.push_back(root->val);
        if(root->right) traversal(root->right, nums);
    }
};
// @lc code=end

