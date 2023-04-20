/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> ret;
        for(auto i : nums2){
            if(set1.find(i)!=set1.end()){
                ret.insert(i);
            }
        }
        vector<int> ret1(ret.begin(), ret.end());
        return ret1;
    }
};
// @lc code=end

