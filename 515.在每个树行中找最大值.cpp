/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root==NULL) return res;
        que.push(root);
        while(!que.empty()){
            int maxvalue=INT_MIN;
            int size = que.size();
            for(int i=0; i<size; i++){
                TreeNode *tmp = que.front();
                que.pop();
                maxvalue = max(maxvalue, tmp->val);
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
            }
            res.emplace_back(maxvalue);
        }
        return res;
    }
};
// @lc code=end

