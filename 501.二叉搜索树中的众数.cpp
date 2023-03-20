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
    vector<int> ret;
    TreeNode *pre=NULL;
    int count=0; int maxcount;

    void traversal(TreeNode *cur){
        if(cur==NULL) return ;
        traversal(cur->left);
        if(pre==NULL){
            count = 1;
        }
        else if(cur->val == pre->val){
            count ++;
        }
        else {
            count = 1;
        }
        if(count == maxcount) ret.push_back(cur->val);
        else if(count>maxcount){
            maxcount = count; 
            ret.clear();
            ret.push_back(cur->val);
        }
        pre = cur;
        traversal(cur->right);
    }

    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return ret;
    }
};
// @lc code=end

