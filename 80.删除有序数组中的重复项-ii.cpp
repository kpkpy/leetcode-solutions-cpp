/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag =0;
        int len = nums.size();
        for(auto i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]&&flag==0) flag++;
            else if(nums[i]==nums[i-1]&&flag==1){
                nums.erase(nums.begin()+i);
                len--; i--;
            }
            else flag =0;
        }
        
        return len;
    }
};
// @lc code=end

