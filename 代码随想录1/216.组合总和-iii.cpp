/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    int sum = 0;
    vector<vector<int> > combinationSum3(int k, int n) {
        dfs(1, n, k);
        return res;
    }
    
    void dfs(int startIndex, int n, int k){
        if(path.size()==k){
            if(sum==n){
                res.push_back(path);
            }
            return ;
        }
        for(int i=startIndex; i<=9; i++){
            path.push_back(i);
            sum +=i;
            dfs(i+1, n, k);
            path.pop_back();
            sum -=i;
        }
        return ;
    }
};
// @lc code=end

