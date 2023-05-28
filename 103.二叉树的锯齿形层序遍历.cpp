/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> que;
        vector<vector<int>> res;
        if(root==NULL)
            return res;

        que.push(root);
        while(!que.empty()){
            vector<int> level;
            int size = que.size();
            for (int i = 0;i <size; i++){
                TreeNode *tmp = que.front();
                level.push_back(tmp->val);
                que.pop();
                if(tmp->left)
                    que.push(tmp->left);
                if(tmp->right)
                    que.push(tmp->right);
            }
            res.push_back(level);
        }
        bool rf = false;
        for (int i = 0; i < res.size(); i++){
            if(rf==true){
                reverse(res[i].begin(), res[i].end());
            }
            rf = !rf;
        }
        return res;
    }
};
// @lc code=end

