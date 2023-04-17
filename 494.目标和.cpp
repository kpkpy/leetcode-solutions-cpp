/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if(sum<abs(target)) return 0;
        if((sum+target)%2==1) return 0;
        int x = (sum+target)/2;
        vector<int> dp(x+1, 0);
        dp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=x; j>=nums[i]; j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[x];
    }
};
// @lc code=end

