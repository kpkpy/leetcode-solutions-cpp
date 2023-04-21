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
        int res = INT_MAX;
        int windowlen = 0;
        int sum = 0;
        int i=0;
        for(int j=0; j<nums.size(); j++){
            sum+=nums[j];
            while(sum>=target){
                windowlen=j-i+1;
                res = min(res, windowlen);
                sum-=nums[i++];
            }
        }
        return res==INT_MAX ? 0 : res;
    }
};
// @lc code=end

