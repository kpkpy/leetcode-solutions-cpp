/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    vector<vector<int> > res;
//    vector<int> path;
//    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
//        vector<bool> visited(nums.size(), false);
//        sort(nums.begin(), nums.end());
//        dfs(nums, visited, 0);
//        return res;
//    }
//
//    void dfs(vector<int>& nums, vector<bool>& visited, int startIndex){
//        res.push_back(path);
//        for(int i=startIndex; i<nums.size(); i++){
//            if(i>0&&nums[i]==nums[i-1]&&visited[i-1]==false){
//                continue;
//            }
//            path.push_back(nums[i]);
//            visited[i] = true;
//            dfs(nums, visited, i+1);
//            path.pop_back();
//            visited[i] = false;
//        }
//        return ;
//    }
    vector<vector<int> > res;
    vector<int> path;
    vector<vector<int> > subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int start){
        res.push_back(path);
        unordered_set<int> uset;
        for(int i=start; i<nums.size(); i++){
            if(uset.find(nums[i])!=uset.end()) continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end

