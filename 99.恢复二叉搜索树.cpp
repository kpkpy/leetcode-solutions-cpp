/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void inorder(TreeNode *root, vector<int> &nums){
        if(root==NULL)
            return ;

        inorder(root->left, nums);
        nums.emplace_back(root->val);
        inorder(root->right, nums);

        return;
    }

    pair<int, int> findTwoSwapped(vector<int> &nums){
        int n = nums.size();
        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < n - 1; i++){
            if(nums[i+1] < nums[i]){
                index2 = i + 1;
                if(index1 == -1){
                    index1 = i;
                }
                else{
                    break;
                }
            }
        }
        int x = nums[index1], y = nums[index2];
        return {x, y};
    }

    void recover(TreeNode *root, int count, int x, int y){
        if(root==nullptr)
            return;
        
        if(root->val == x || root->val == y){
            root->val = (root->val == x ? y : x);
            count--;
            if(count == 0)
                return ;
        }
        recover(root->left, count, x, y);
        recover(root->right, count, x, y);
        return;
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int, int> swapped = findTwoSwapped(nums);
        recover(root, 2, swapped.first, swapped.second);
        return;
    }
};
// @lc code=end

