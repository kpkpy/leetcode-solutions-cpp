/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return SA2BST(nums, 0, nums.size());
    }

    TreeNode* SA2BST(vector<int>& nums, int left, int right) {
        if(left >= right){
            return NULL;
        }
        else if(left-right==1){
            TreeNode *node = new TreeNode(nums[left]);
            return node;
        }
        else{
            int mid = (left+right)/2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = SA2BST(nums, left, mid);
            root->right = SA2BST(nums, mid+1, right);

            return root;
        }
    }
};
// @lc code=end

