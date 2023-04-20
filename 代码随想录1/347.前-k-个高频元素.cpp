/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "include.h"
// @lc code=start
class Solution {

    class mycomparsion{
        public:
        bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> nm;
        for(int i=0; i<nums.size(); i++){
            nm[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int, int> >, mycomparsion> que;
        for(auto i = nm.begin(); i!=nm.end(); i++){
            que.push(*i);
            if(que.size()>k) que.pop();
        }
        vector<int> ret(k);
        for(;k>0; k--){
            ret[k-1] = que.top().first;
            que.pop();
        }
        return ret;
    }
};
// @lc code=end

