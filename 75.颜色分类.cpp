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
        int o=0; int l=0; int s=0;
        for(int i=0; i<nums.size(); i++){
            if(nums.at(i)==0) o++;
            else if(nums.at(i)==1) l++;
            else s++;
        }
        for(int i=0; i<nums.size(); i++){
            if(o!=0){nums.at(i)=0; o--; continue;}
            if(l!=0){nums.at(i)=1; l--; continue;}
            if(s!=0){nums.at(i)=2; s--; continue;}
        }
    }
};
// @lc code=end

