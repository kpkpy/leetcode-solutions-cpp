/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include "include.h"
// @lc code=start
class Monoqueue{
    public:
    deque<int> que;
    void pop(int value){
        if(!que.empty()&&value==que.front()){
            que.pop_front();
        }
    }

    void push(int value){
        while(!que.empty()&&value>que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }

    int front(){
        return que.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        Monoqueue que;
        for(int i=0; i<k; i++){
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for(int i=k; i<nums.size(); i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};
// @lc code=end

