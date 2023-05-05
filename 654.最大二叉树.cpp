/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return construct(nums, 0, nums.size());
    }

    TreeNode* construct(vector<int>& nums, int l, int r){
        if(l>=r) return NULL;
        int rootVal=INT_MIN;
        int rootIdx=l;
        for(int i=l; i<r; i++){
            if(nums[i]>rootVal) {
                rootVal = nums[i];
                rootIdx = i;
            }
        }
        TreeNode *root = new TreeNode(rootVal);
        if(r-l==1) return root;
        root->left = construct(nums, l, rootIdx);
        root->right = construct(nums, rootIdx+1, r);
        return root;
    }
};
// @lc code=end

