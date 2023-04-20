/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    vector<vector<int> > res;
//    vector<int> path;
//    vector<vector<int> > permuteUnique(vector<int>& nums) {
//        vector<bool> visited(nums.size(), false);
//        sort(nums.begin(), nums.end());
//        dfs(nums,visited);
//        return res;
//    }
//
//    void dfs(vector<int> &nums, vector<bool>& visited){
//        if(path.size()==nums.size()){
//            res.push_back(path);
//            return;
//        }
//        for(int i=0; i<nums.size(); i++){
//            if(i>0&&nums[i]==nums[i-1]&&visited[i-1]==false) continue;
//            if(visited[i]==false){
//                path.push_back(nums[i]);
//                visited[i]=true;
//                dfs(nums, visited);
//                path.pop_back();
//                visited[i]=false;
//            }
//        }
//        return ;
//    }
    vector<vector<int> > res;
    vector<int> path;
    vector<vector<int> > permuteUnique(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        dfs(nums, visited);
        return res;
    }

    void dfs(vector<int> & nums, vector<bool> &visited){
        if(nums.size()==path.size()){
            res.push_back(path);
            return ;
        }
        unordered_set<int> uset;
        for(int i=0; i<nums.size();i++){
            if(uset.find(nums[i])!=uset.end()){
                continue;
            }
            if(visited[i]) continue;
            visited[i] = true;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, visited);
            path.pop_back();
            visited[i] = false;
        }
        return ;
    }
};
// @lc code=end

