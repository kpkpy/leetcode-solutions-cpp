/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int cover = 0;
        for(int i=0; i<=cover; i++){
            cover = max(i+nums[i], cover);
            if(i>=nums.size()-1) return true;
        }
        return false;
    }
};
// @lc code=end

