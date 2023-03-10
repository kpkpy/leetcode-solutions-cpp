/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0; int r=nums.size()-1;
        int m=-1; int ret = 100000;
        while(l<=r){
            m = (l+r)/2;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]<target){
                l = m+1;
            }
            else{
                r = m-1; 
            }
        }
        return r+1;
    }

};
// @lc code=end

