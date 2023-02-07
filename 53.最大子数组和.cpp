/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 * line33 存在访问越界错误
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayX(nums, 0 , nums.size()-1);
    }
    
    int maxSubArrayX(vector<int>& nums, int l, int h){
        if(l==h){return nums[l];}
        int mid = (l+h)/2;
        int left, right, cross;
        left = maxSubArrayX(nums, l, mid);
        right = maxSubArrayX(nums, mid+1, h);
        cross = maxSubArrayCross(nums, l, h, mid);
        if(left>right&&left>cross) return left;
        else if(right>left&&right>cross) return right;
        else {
            return (nums[0] > 0 ?  nums[0] : 0) + cross;
        }
    }

    int maxSubArrayCross(vector<int>& nums, int l, int h, int mid){
        int right_sum = -9999;
        int left_sum = -9999;
        int sum = 0;
        for(size_t i = mid; i>=l; i--){
            sum+=nums[i];
            if(sum>left_sum) left_sum = sum;
        }
        sum = 0;
        for(size_t i=mid+1; i<=h; i++){
            sum+=nums[i];
            if(sum>right_sum) right_sum = sum;
        }
        return left_sum+right_sum;
    }
};
// @lc code=end

