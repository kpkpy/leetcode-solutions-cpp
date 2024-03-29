/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }

    bool compare(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL) return true;
        else if(p==NULL&&q!=NULL) return false;
        else if(p!=NULL&&q==NULL) return false;
        else if(p->val!=q->val) return false;
        return compare(p->left, q->left) && compare(p->right, q->right);
    }
};
// @lc code=end

