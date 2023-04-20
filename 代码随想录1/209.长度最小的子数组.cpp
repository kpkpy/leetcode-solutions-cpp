/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0; int r=0; int len=0; int ret=INT32_MAX; int sum=0;
        for(r=0; r<nums.size(); r++){
            sum+=nums[r]; 
            while(sum>=target){
                len = r-l+1;
                ret = ret < len ? ret : len;
                sum-=nums[l++];
            }
        }
        return ret == INT32_MAX ? 0 : ret;
    }
};
// @lc code=end

