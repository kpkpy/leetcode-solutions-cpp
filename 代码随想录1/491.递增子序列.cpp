/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int> > res;

    vector<vector<int> > findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int startIndex){
        if(path.size()>=2) res.push_back(path);
        unordered_set<int> uset;
        for(int i=startIndex; i<nums.size(); i++){
            if(!path.empty()&&path.back()>nums[i]||uset.find(nums[i])!=uset.end()){
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

