/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int> > res;
        if(root==NULL) return res;
        que.push(root);
        while(!que.empty()){
            vector<int> level;
            int size=que.size();
            for(int i=0; i<size; i++){
                TreeNode *tmp = que.front();
                que.pop();
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
                level.push_back(tmp->val);
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end

