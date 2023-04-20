/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int maxdepth=-1;
    int leftvalue;
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return leftvalue;
    }

    void traversal(TreeNode* root, int depth){
        if(root->left==NULL&&root->right==NULL){
            if(depth>maxdepth) {
                leftvalue = root->val;
                maxdepth = depth;
            }
        }
        if(root->left){
            traversal(root->left, depth+1);
        }
        if(root->right) {
            traversal(root->right, depth+1);
        }
        return ;
    }
};
// @lc code=end

