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
        int sum = 0;
        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum>res) res = sum;
            if(sum<0){
                sum = 0;
            }
        }
        return res;
    }
};
// @lc code=end

