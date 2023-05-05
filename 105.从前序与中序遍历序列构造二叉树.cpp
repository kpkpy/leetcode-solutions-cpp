/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()||preorder.size()==0) return NULL;
        return traversal(preorder, inorder);
    }

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(rootVal);
        if(preorder.size()==1) return root;

        int delimeterIdx;
        for(delimeterIdx=0; delimeterIdx<inorder.size(); delimeterIdx++){
            if(inorder[delimeterIdx]==rootVal) break;
        }

        vector<int> leftin(inorder.begin(), inorder.begin()+delimeterIdx);
        vector<int> rightin(inorder.begin()+delimeterIdx+1, inorder.end());

        preorder.erase(preorder.begin());

        vector<int> leftpre(preorder.begin(), preorder.begin()+leftin.size());
        vector<int> rightpre(preorder.begin()+leftin.size(), preorder.end());

        root->left = traversal(leftpre, leftin);
        root->right = traversal(rightpre, rightin);
        
        return root;

    }
};
// @lc code=end

