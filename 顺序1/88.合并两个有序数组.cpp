/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m);
        if(n==0) return;
        if(m==0) {
            nums1 = nums2; return;
        }
        for(auto i=0; i<m; i++){
            nums3[i] = nums1[i];
        }
        int b=0; int c=0;
        for(auto i=0; i<nums1.size(); i++){
            if(c==m) {
                nums1[i] = nums2[b++];
            }
            else if(b==n) {
                nums1[i] = nums3[c++];
            }
            else if(nums3[c]>nums2[b]){
                nums1[i] = nums2[b++]; 
            }
            else if(nums3[c]<=nums2[b]){
                nums1[i] = nums3[c++];
            }
        }
        return;
    }
};
// @lc code=end

