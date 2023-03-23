/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    vector<vector<int> > combine(int n, int k) {
        dfs(1, n ,k);
        return res;
    }

    void dfs(int startIndex, int n, int k){
        if(path.size()==k) {
            res.push_back(path);
            return ;
        }
        for(int i=startIndex; i<=n-(k-path.size()-1); i++){
            path.push_back(i);//select i
            dfs(i+1, n, k);
            path.pop_back();// not select
        }
        return;
    }

};
// @lc code=end

