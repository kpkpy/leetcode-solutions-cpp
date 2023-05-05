/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key) {
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL&&root->right!=NULL){
                TreeNode *cur = root->right;
                while(cur->left!=NULL){
                    cur=cur->left;
                }
                cur->left = root->left;
                TreeNode *tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
            else if(root->left){
                TreeNode * tmp = root->left;
                delete root;
                return root->left;
            }
            else {
                TreeNode *tmp = root->right;
                delete root;
                return root->right;
            }
        }
        else if(root->val > key){
            if(root->left==NULL) return root;
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            if(root->right==NULL) return root;
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end

