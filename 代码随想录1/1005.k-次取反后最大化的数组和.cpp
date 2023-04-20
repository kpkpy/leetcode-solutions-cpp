/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        if(k==0) {
            int ret = accumulate(nums.begin(), nums.end(), 0);
            return ret;
        }
        else{
            int _min = INT_MAX; 
            int _min_flag = -1;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]<_min) {
                    _min = nums[i];
                    _min_flag = i;
                }
            }
            nums[_min_flag] = nums[_min_flag]*(-1);
            return largestSumAfterKNegations(nums, k-1);
        }
        return -1;
    }
};
// @lc code=end

