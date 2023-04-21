/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                umap[nums1[i]+nums2[j]]++;
            }
        }
        int count = 0;
        for(int i=0; i<nums3.size(); i++){
            for(int j=0; j<nums4.size(); j++){
                auto iter = umap.find(0-nums3[i]-nums4[j]);
                if(iter!=umap.end()) count+=iter->second;
            }
        }
        return count;
    }
};
// @lc code=end

