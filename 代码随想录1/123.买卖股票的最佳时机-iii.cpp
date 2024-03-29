/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        vector<vector<int> > dp(prices.size(), vector<int>(5, 0));
        /*
        没有操作
        第一次持有股票
        第一次不持有股票
        第二次持有股票
        第二次不持有股票
        */
        dp[0][1] = -prices[0]; dp[0][3] = -prices[0];
        for(int i=1; i<prices.size(); i++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]+prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2]-prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3]+prices[i]);
        }
        return dp[prices.size()-1][4];
    }
};
// @lc code=end

