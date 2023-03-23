/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0) return res;
        res.clear(); path.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0);
        return res;
    }

    void dfs(vector<int> &candidates,int startIndex, int target, int sum){
        if(sum >= target){
            if(sum == target) res.push_back(path);
            return ;
        }
        for(int i=startIndex; i<candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, i,target, sum);
            path.pop_back();
            sum -= candidates[i];
        }
        return ;
    }
};
// @lc code=end

