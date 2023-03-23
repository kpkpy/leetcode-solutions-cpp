/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    int sum = 0;
//    vector<vector<int> > res;
//    vector<int> path;
//    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
//        if(candidates.size()==0) return res;
//        vector<bool> visited(candidates.size(), false);
//        sort(candidates.begin(), candidates.end());
//        dfs(candidates, visited,  target, 0);
//        return res;
//    }
//
//    void dfs(vector<int> &candidates, vector<bool> &visited, int target, int startIndex){
//        if(sum>=target){
//            if(sum==target) res.push_back(path);
//            return ;
//        }
//        for(int i=startIndex; i<candidates.size(); i++){
//            if(i>0&&candidates[i]==candidates[i-1]&&visited[i-1]==false) continue;
//            path.push_back(candidates[i]);
//            sum += candidates[i];
//            visited[i] = true;
//            dfs(candidates, visited, target, i+1);
//            sum -= candidates[i];
//            path.pop_back();
//            visited[i] = false;
//        }
//        return ;
//    }
    vector<vector<int> > res;
    vector<int> path;
    int sum = 0;

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int startIndex){
        if(sum>=target){
            if(sum==target) res.push_back(path);
            return ;
        }
        unordered_set<int> uset;
        for(int i=startIndex; i<candidates.size(); i++){
            if(uset.find(candidates[i])!=uset.end()) continue;
            sum+=candidates[i];
            path.push_back(candidates[i]);
            uset.insert(candidates[i]);
            dfs(candidates, target, i+1);
            sum-=candidates[i];
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end

