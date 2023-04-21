/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int front=0; int rear=nums.size()-1;
        vector<int> ret;
        while(front<=rear){
            if(nums[front]*nums[front]>nums[rear]*nums[rear]){
                ret.push_back(nums[front]*nums[front]);
                front++;
            }
            else {
                ret.push_back(nums[rear]*nums[rear]);
                rear--;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

