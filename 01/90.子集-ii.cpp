/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include "include.h"
// @lc code=start
//class Solution {
//public:
//    vector<vector<int> > ret;
//    vector<int> tmp;
//    vector<bool> visit;
//    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
//        visit.resize(nums.size());
//        for(auto k=0; k<=nums.size(); k++){
//            dfs(nums, 0, k);
//        }
//        return ret;
//    }
//
//    void dfs(vector<int>& nums, int cur, int k){
//        if(k==0){
//            ret.push_back(tmp);
//            return;
//        }
//        for(auto i=cur; i<nums.size(); i++){
//            if(visit[i]||(i>0&&nums[i]==nums[i-1]&&!visit[i-1])){
//                continue;
//            }
//            visit[i] = true;
//            tmp.push_back(nums[i]);
//            dfs(nums, cur+1, k-1);
//            tmp.pop_back();
//            visit[i] = false;
//        }
//    }
//};

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    vector<bool> visit;
    //k表示生成大小为k的数组
    void backtrack(int start, int k, vector<int>& nums){
        if(k == 0){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < nums.size(); i ++){
            if(visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])){
                continue;
            } //去除重复元素
            visit[i] = true;
            path.push_back(nums[i]);
            backtrack(i + 1, k - 1, nums);
            path.pop_back();
            visit[i] = false;
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        visit.resize(n);
        for(int i = 0; i <= nums.size(); i ++){
            backtrack(0, i, nums);
        }
        return ans;
    }
};

// @lc code=end

