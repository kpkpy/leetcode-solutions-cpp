/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    int search(vector<int>& nums, int target) {
//        return binsearch(nums, 0, nums.size()-1, target);
//    }
//    int binsearch(vector<int>& nums, int l, int h, int target){
//        int m = (l+h)/2;
//        if(nums[m]==target) return m;
//        else if(l==h) return -1;
//        else if(nums[m]>target) {
//            return binsearch(nums, l, m, target);
//        }
//        else{
//            return binsearch(nums, m+1, h, target);
//        }
//    }
    int search(vector<int> & nums, int target) {
        int l = 0; int r = nums.size()-1;
        int m = -1;
        if(nums.size()==1&&nums[0]==target) return 0;
        while(l<=r){
            m = (l+r)/2;
            if(nums[m]==target) return m;
            else if(nums[m]<target) {
                l = m+1;// h not change
            }
            else {
                r = m-1;
            }
        }
        return -1;
    }
};
// @lc code=end

