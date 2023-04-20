/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if(nums.size()==1) return nums[0];
        dp[0] = nums[0];
        int res = dp[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            if(dp[i]>res) res = dp[i];
        }
        return res;
    }
};
// @lc code=end

