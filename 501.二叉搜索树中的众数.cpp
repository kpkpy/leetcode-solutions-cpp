/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int maxCount;
    int count;
    TreeNode *pre;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount=0;
        pre=NULL;
        res.clear();
        searchTree(root);
        return res;
    }

    void searchTree(TreeNode* root){
        if(root==NULL) return ;
        searchTree(root->left);
        if(pre==NULL) count=1;
        else if(pre->val==root->val) count++;
        else count=1;
        pre = root;
        if(count==maxCount){
            res.push_back(root->val);
        }
        else if(count>maxCount){
            maxCount = count;
            res.clear();
            res.push_back(root->val);
        }
        searchTree(root->right);
        return ;
    }
};
// @lc code=end

