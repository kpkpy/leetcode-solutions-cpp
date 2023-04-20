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
        int n = nums1.size();
        for(auto i=0; i<n; i++){
            for(auto j=0; j<n; j++){
                umap[nums1[i]+nums2[j]]++;
            }
        }

        int count = 0;
        for(auto i=0; i<n; i++){
            for(auto j=0; j<n; j++){
                if(umap.find(0-nums3[i]-nums4[j])!=umap.end()){
                    count+=umap[0-nums3[i]-nums4[j]];
                }
            }
        }
        return count;
    }
};
// @lc code=end

