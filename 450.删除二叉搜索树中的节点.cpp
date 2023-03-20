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
        if(!root) return root;
        if(root->val==key){
            //delete root
            if(!root->left&&!root->right){
                delete root;
                return NULL;
            }
            else if(!root->left&&root->right){
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            }
            else if(root->left&&!root->right){
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            }
            else {
                //root->left && root->right
                TreeNode *cur = root->right;
                while(cur->left){
                    cur = cur->left;
                }
                TreeNode *tmp = root;
                cur->left = root->left;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        else if(root->val>key) root->left = deleteNode(root->left, key);
        else{ //root->Val<key
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end

