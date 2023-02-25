/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int> > subsets(vector<int>& nums) {
        ans.push_back({});
        for(int i=1; i<=nums.size(); i++){
            dfs(nums, i, 0);
        }
        return ans;
    }

    vector<int> tmp;
    void dfs(vector<int> nums, int k, int cur){
        if(tmp.size()+nums.size()-cur+1<k) return ;
        if(tmp.size()==k){
            ans.push_back(tmp);
            return ;
        }
        if(cur==nums.size()) return;
        tmp.push_back(nums.at(cur));
        dfs(nums,k,cur+1);
        tmp.pop_back();
        dfs(nums,k,cur+1);
    }
};
// @lc code=end

