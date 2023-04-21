/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int res = 1;
        vector<int> dp(nums.size(), 1);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                dp[i] = dp[i-1] +1;
            }
            if(dp[i]>res) res = dp[i];
        }
        return res;
    }
};
// @lc code=end

