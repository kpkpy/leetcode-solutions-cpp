/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    vector<vector<int> > levelOrder(Node* root) {
        vector<vector<int> > res;
        queue<Node*> que;
        if(root==NULL) return res;
        que.push(root);
        while(!que.empty()){
            vector<int> level;
            int size = que.size();
            for(int i=0; i<size; i++){
                Node *tmp = que.front();
                que.pop();
                level.push_back(tmp->val);
                for(int j=0; j<tmp->children.size(); j++){
                    que.push(tmp->children[j]);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end

