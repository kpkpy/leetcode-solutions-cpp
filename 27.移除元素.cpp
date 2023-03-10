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
        int i=0; int j=0;
        for(j=0; j<nums.size(); ){
            if(i!=j) nums[i] = nums[j];
            if(nums[j]==val){
                j++;
            }
            else{
                i++; j++;
            }
        }
        return i;
    }
};
// @lc code=end

