/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
//    int countNodes(TreeNode* root) {
//        queue<TreeNode*> que;
//        int count=0;
//        if(!root) return count;
//        que.push(root);
//        count ++;
//        while(!que.empty()){
//            int size = que.size();
//            for(int i=0; i<size; i++){
//                TreeNode *node=que.front();
//                que.pop();
//                if(node->left) {que.push(node->left);count++;}
//                if(node->right) {que.push(node->right);count++;}
//            }
//        }
//        return count;
//    }
    int countNodes(TreeNode* root){
        if(root==NULL) return 0;
        TreeNode *left=root->left;
        TreeNode *right=root->right;
        int leftdepth = 0; int rightdepth = 0;
        while(left){
            left = left->left;
            leftdepth++;
        }
        while(right){
            right = right->right;
            rightdepth++;
        }
        if(leftdepth==rightdepth) return (2<<leftdepth)-1;
        else return countNodes(root->left)+countNodes(root->right)+1;
    }
};
// @lc code=end

