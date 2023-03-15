/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include "include.h"
// @lc code=start
class Solution {

    class MyQueue{
    public:
        deque<int> que;

        //val是否相等于front, 相等则弹出
        void pop(int val){
            if(!que.empty()&&val==que.front()){
                que.pop_front();
            }
        }

        void push(int val){
            while(!que.empty()&&val>que.back()){
                que.pop_back();
            }
            que.push_back(val);
        }

        int front(){
            return que.front();
        }
    };


public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> ret;

        for(int i=0; i<k; i++){
            que.push(nums[i]);
        }
        ret.push_back(que.front());
        for(int i=k; i<nums.size(); i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            ret.push_back(que.front());
        }
        return ret;
    }
};
// @lc code=end

