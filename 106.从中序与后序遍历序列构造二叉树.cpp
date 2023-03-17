/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = traversal(inorder, postorder);
        return root;
    }

    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
            if(postorder.size()==0) return NULL;

            int rootVal = postorder[postorder.size()-1];

            TreeNode *root = new TreeNode(rootVal);
            
            if(postorder.size()==1) return root;

            int cut;
            for(cut=0; cut<inorder.size(); cut++){
                if(inorder[cut]==rootVal) break;
            }

            vector<int> leftinorder(inorder.begin(), inorder.begin()+cut);
            vector<int> rightinorder(inorder.begin()+cut+1, inorder.end());

            postorder.resize(postorder.size()-1);
            vector<int> leftpostorder(postorder.begin(), postorder.begin()+leftinorder.size());
            vector<int> rightpostorder(postorder.begin()+leftinorder.size(), postorder.end());
            
            root->left = traversal(leftinorder, leftpostorder);
            root->right = traversal(rightinorder, rightpostorder);

            return root;
    }
};
// @lc code=end

