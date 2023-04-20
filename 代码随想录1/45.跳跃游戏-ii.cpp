/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int curdist = 0; int nextdist = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            nextdist = max(nextdist, i+nums[i]);
            if(i==curdist){
                if(curdist<nums.size()-1){
                    res ++;
                    curdist = nextdist;
                }
                else break;
            }
        }
        return res;
    }
};
// @lc code=end

