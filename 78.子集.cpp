/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;

    vector<vector<int> > subsets(vector<int>& nums) {
//        res.push_back(vector<int>());
//        for(int i=1; i<=nums.size(); i++){
//            dfs(nums, 0, i);
//        }
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int start){
        res.push_back(path);
        for(int i=start; i<nums.size(); i++){
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end

