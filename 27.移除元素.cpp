/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0; int fast=0;
        for(;fast<nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end

