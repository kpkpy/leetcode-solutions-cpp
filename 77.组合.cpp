/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int> > combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }

    vector<int> temp;
    void dfs(int cur, int n, int k){
        if(temp.size()+n-cur+1<k) return;
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(cur==n+1){
            return;
        }
        temp.push_back(cur);
        dfs(cur+1, n, k);
        temp.pop_back();
        dfs(cur+1, n, k);
    }
};
// @lc code=end

