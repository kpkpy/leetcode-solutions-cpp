/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "include.h"

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size();i++){
            auto iter = umap.find(target-nums[i]);
            if(iter!=umap.end()){
                return {iter->second, i};
            }
            umap.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
// @lc code=end

