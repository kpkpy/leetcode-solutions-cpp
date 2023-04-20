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
        TreeNode *root = traversal(preorder, inorder);
        return root;
    }

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;

        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(rootVal);
        if(preorder.size()==1) return root;

        int cut;
        for(cut=0; cut<inorder.size(); cut++){
            if(inorder[cut]==rootVal) break;
        }

        vector<int> leftinorder(inorder.begin(), inorder.begin()+cut);
        vector<int> rightinorder(inorder.begin()+cut+1, inorder.end());

//        preorder.erase(preorder.begin(), preorder.begin()+1);
//        vector<int> leftpreorder(preorder.begin(), preorder.begin()+leftinorder.size());
//        vector<int> rightpreorder(preorder.begin()+leftinorder.size(), preorder.end());
        vector<int> leftpreorder(preorder.begin()+1, preorder.begin()+1+leftinorder.size());
        vector<int> rightpreorder(preorder.begin()+1+leftinorder.size(), preorder.end());

        root->left = traversal(leftpreorder, leftinorder);
        root->right = traversal(rightpreorder, rightinorder);

        return root;
    }
};
// @lc code=end

