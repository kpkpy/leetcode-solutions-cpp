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
        unordered_set<int> us(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for(auto num : nums2){
            if(us.find(num)!=us.end()){
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

