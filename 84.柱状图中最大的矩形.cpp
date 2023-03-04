/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans=0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for(auto i=0; i<heights.size(); i++){
            while(!stk.empty()&&heights[stk.top()]>heights[i]){
                int cur = stk.top();
                stk.pop();
                int left = stk.top()+1;
                int right = i-1;
                ans = max(ans, heights[cur]*(right-left+1));
            }
            stk.push(i);
        }
        return ans;
    }

};
// @lc code=end

