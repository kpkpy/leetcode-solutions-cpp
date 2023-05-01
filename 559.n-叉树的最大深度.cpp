/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */
#include "include.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        int max=0;
        dfs(root, 1, max);
        return max;
    }

    void dfs(Node* root, int depth, int& max){
        if(root==NULL) return ;
        if(depth>max) max=depth;
        for(int i=0; i<root->children.size(); i++){
            if(root->children[i]!=NULL) dfs(root->children[i], depth+1, max);
        }
        return ;
    }
};
// @lc code=end

