/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0; int flag =0;
        for(; i<nums.size(); i++){
            if(nums[i]==target){
                flag ++;
                rotate(nums, i);
            }
        }
        if(flag==0) return false;
        return true;
    }

    void rotate(vector<int>& nums, int index){
        vector<int> tmp;
        for(auto i=0; i<index; i++){
            tmp.push_back(nums[i]);
        }
        for(auto j=0; j+index<nums.size(); j++){
            nums[j] = nums[j+index];
        }
        for(auto i=0; i<tmp.size(); i++){
            nums[nums.size()-index+i] = tmp[i];
        }
    }
};

// @lc code=end

