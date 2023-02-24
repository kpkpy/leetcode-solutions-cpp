/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(auto i=0; i<nums.size(); i++){
            for(auto j=i; j<nums.size(); j++){
                if(nums.at(i)==nums.at(j)) j++;
                else{
                    swap(nums[i], nums[j]);
                }
            }
            
        }
    }
};
// @lc code=end

