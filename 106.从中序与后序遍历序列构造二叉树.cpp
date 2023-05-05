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
//        if(postorder.size()==0) return NULL;
//
//        int rootVal = postorder[postorder.size()-1];
//        TreeNode *root = new TreeNode(rootVal);
//
//        if(postorder.size()==1) return root;
//
//        int delimterIndex;
//        for(int i=0; i<inorder.size(); i++){
//            if(inorder[i]==rootVal){
//                delimterIndex = i;
//                break;
//            }
//        }
//        
//        vector<int> leftinorder(inorder.begin(), inorder.begin()+delimterIndex);
//        vector<int> rightinorder(inorder.begin()+delimterIndex+1, inorder.end());
//
//        postorder.resize(postorder.size()-1);
//
//        root->left = buildTree(leftinorder, postorder);
//        root->right = buildTree(rightinorder, postorder);
//
//        return root;
//    }
        if(inorder.size()!=postorder.size()||postorder.size()==0) return NULL;
        return traversal(inorder, postorder);
    }

    TreeNode* traversal(vector<int> &inorder, vector<int> &postorder){
        if(postorder.size()==0) return NULL;
        int rootVal = postorder[postorder.size()-1];
        if(postorder.size()==1) {
            TreeNode *root = new TreeNode(rootVal);
            return root;
        }

        TreeNode *root = new TreeNode(rootVal);

        int delimterIdx;
        for(delimterIdx=0; delimterIdx<inorder.size(); delimterIdx++){
            if(inorder[delimterIdx]==rootVal) break;
        }

        vector<int> inordeleft(inorder.begin(), inorder.begin()+delimterIdx);
        vector<int> inorderright(inorder.begin()+delimterIdx+1, inorder.end());
        
        postorder.resize(postorder.size()-1);

        vector<int> postorderleft(postorder.begin(), postorder.begin()+inordeleft.size());
        vector<int> postorderright(postorder.begin()+inordeleft.size(), postorder.end());

        root->left = traversal(inordeleft, postorderleft);
        root->right = traversal(inorderright, postorderright);

        return root;
    }
};
// @lc code=end

