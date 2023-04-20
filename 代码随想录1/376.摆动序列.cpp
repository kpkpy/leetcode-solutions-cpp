/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int curdiff = 0;
        int prediff = 0;
        int res = 1;
        for(int i=0; i<nums.size()-1; i++){
            curdiff = nums[i+1] - nums[i];
            if((curdiff>0&&prediff<=0)||curdiff<0&&prediff>=0) {
                res++;
                prediff = curdiff;
            }
        }
        return res;
    }
};
// @lc code=end

