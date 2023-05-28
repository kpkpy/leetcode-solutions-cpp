/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(10001, 0);
        int target = sum / 2;
        if(sum%2!=0)
            return false;

        for (int i = 0; i < nums.size(); i++){
            for (int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
            }
        }
        return dp[target] == target;
    }
};
// @lc code=end

