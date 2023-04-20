/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
//    vector<string> binaryTreePaths(TreeNode* root) {
//        vector<string> ret;
//        vector<int> path;
//        if(root==NULL) return ret;
//        preTrev(root, ret, path);
//        return ret;
//    }
//
//    void preTrev(TreeNode *root, vector<string> &ret,vector<int> &path){
//        path.push_back(root->val);
//        if(!root->left&&!root->right){
//            //gen path;
//            string spath;
//            for(int i=0; i<path.size()-1; i++){
//                spath+=to_string(path[i]);
//                spath+="->";
//            }
//            spath+=(to_string(path[path.size()-1]));
//            ret.push_back(spath);
//            return ;
//        }
//        else{
//            if(root->left) {preTrev(root->left, ret, path); path.pop_back();}
//            if(root->right) {preTrev(root->right, ret, path); path.pop_back();}
//        }
//    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        stack<string> pathstk;
        stack<TreeNode*> treestk;
        if(root==NULL) return ret;
        treestk.push(root);
        pathstk.push(to_string(root->val));
        while(!treestk.empty()){
            TreeNode *node = treestk.top(); treestk.pop();
            pathstk.push(to_string(node->val)); pathstk.pop();
            string path = pathstk.top(); pathstk.pop();
            if(node->left==NULL&&node->right==NULL) {
                ret.push_back(path);
            }
            if(node->right){
                treestk.push(node->right);
                pathstk.push(path+"->"+to_string(node->right->val));
            }
            if(node->left){
                treestk.push(node->left);
                pathstk.push(path+"->"+to_string(node->left->val));
            }
        }
        return ret;
    }
};
// @lc code=end

