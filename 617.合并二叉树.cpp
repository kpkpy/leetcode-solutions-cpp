/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

//class Solution {
//public:
//    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//        if (t1 == NULL) return t2; // 如果t1为空，合并之后就应该是t2
//        if (t2 == NULL) return t1; // 如果t2为空，合并之后就应该是t1
//        // 修改了t1的数值和结构
//        t1->val += t2->val;                             // 中
//        t1->left = mergeTrees(t1->left, t2->left);      // 左
//        t1->right = mergeTrees(t1->right, t2->right);   // 右
//        return t1;
//    }
//};
// @lc code=end

