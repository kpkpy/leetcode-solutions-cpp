/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<int> ret;
    vector<int> searchRange(vector<int>& nums, int target) {
        ret.push_back(0);
        ret.push_back(0);
        ret[0] = INT_MAX;
        ret[1] = INT_MIN;
        findlow(nums, 0, nums.size(), target);
        findhigh(nums, 0, nums.size(),target);
        if(ret[0]==INT_MAX) {
            ret[0] = -1;
            ret[1] = -1;
        }
        return ret;
    }

    void findlow(vector<int>& nums, int low, int high, int target){
        if(low>=high) return;
        int mid = (low+high)/2;
        if(nums[mid]==target){
            ret[0] = min(ret[0], mid);
            findlow(nums, low, mid, target);
        }
        if(nums[mid]>target){
            findlow(nums, low, mid, target);
        }
        else{
            findlow(nums, mid+1, high, target);
        }
    }

    void findhigh(vector<int>& nums, int low, int high, int target){
        if(low>=high) return;
        int mid = (low+high)/2;
        if(nums[mid]==target){
            ret[1] = max(ret[1], mid);
            findhigh(nums, mid+1, high, target);
        }
        if(nums[mid]>target){
            findhigh(nums, low, mid, target);
        }
        else{
            findhigh(nums, mid+1, high, target);
        }
    }
};
// @lc code=end

