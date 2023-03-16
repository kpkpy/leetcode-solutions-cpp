/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            TreeNode *node;
            vector<int> level;
            for(int i=0; i<size; i++){
                node = que.front();
                que.pop();
                level.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ret.push_back(level);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

