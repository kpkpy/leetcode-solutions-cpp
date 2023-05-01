/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
//    vector<int> rightSideView(TreeNode* root) {
//        vector<vector<int> > res;
//        queue<TreeNode*> que;
//        if(root==NULL) return vector<int>{};
//        que.push(root);
//        while(!que.empty()){
//            int size=que.size();
//            vector<int> level;
//            for(int i=0; i<size; i++){
//                TreeNode *tmp=que.front();
//                que.pop();
//                if(tmp->left) que.push(tmp->left);
//                if(tmp->right) que.push(tmp->right);
//                level.push_back(tmp->val);
//            }
//            res.push_back(level);
//        }
//        vector<int> ret;
//        for(int i=0; i<res.size(); i++){
//            ret.push_back(res.at(i)[res.at(i).size()-1]);
//        }
//        return ret;
//    }
    vector<int> rightSideView(TreeNode* root){
        vector<int> res;
        int k=1, lay=0;
        RVL(root, res, k, lay);
        return res;
    }
    
    void RVL(TreeNode* root, vector<int> &res, int k, int &lay){
        if(root==NULL) return;
        if(k>lay){
            lay=k;
            res.emplace_back(root->val);
        }
        RVL(root->right, res, k+1, lay);
        RVL(root->left, res, k+1, lay);
    }
};


// @lc code=end