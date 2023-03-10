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
        int x=0; int y=nums.size()-1;
        int a,b; int i=nums.size()-1;
        vector<int> ret(nums.size(), 0);
        while(i>=0){
            a = nums[x]*nums[x];
            b = nums[y]*nums[y];
            if(a>=b){
                ret[i] = a;
                x++; i--;
            }
            else{
                ret[i] = b;
                y--; i--;
            }
        }
        return ret;
    }
};
// @lc code=end

