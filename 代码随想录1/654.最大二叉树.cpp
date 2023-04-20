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
        return traversal(nums, 0, nums.size());
    }

    TreeNode* traversal(vector<int>& nums, int l, int r){
        if(l==r) return NULL;
        int rootVal=0; int cut;
        for(int i=l; i<r; i++){
            if(nums[i]>rootVal){
                rootVal= nums[i];
                cut = i;
            }
        }
        TreeNode *root = new TreeNode(rootVal);
        if(r-l==1) return root;

//        vector<int> lnums(nums.begin(), nums.begin()+cut);
//        vector<int> rnums(nums.begin()+cut+1, nums.end());

        root->left = traversal(nums, l, cut);
        root->right = traversal(nums, cut+1, r);

        return root;
    }
};
// @lc code=end

