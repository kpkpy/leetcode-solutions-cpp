/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int> > res;
    vector<vector<int> > permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        dfs(nums, visited);
        return res;
    }

    void dfs(vector<int>& nums, vector<bool>& visited){
        if(path.size()==nums.size()) res.push_back(path);
        for(int i=0; i<nums.size(); i++){
            if(visited[i]==false){
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, visited);
                visited[i] = false;
                path.pop_back();
            }
        }
        return ;
    }

};
// @lc code=end

