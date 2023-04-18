/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    int maxProfit(vector<int>& prices) {
//        int low = INT_MAX;
//        int res = 0;
//        for(int i=0; i<prices.size(); i++){
//            low = min(low, prices[i]);
//            res = max(res, prices[i]-low);
//        }
//        return res;
//    }
    int maxProfit(vector<int> &prices){
        if(prices.size()==0) return 0;
        vector<vector<int> > dp(prices.size(), vector<int>(2));
        dp[0][0]=-prices[0]; dp[0][1]=0;
        for(int i=1; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i]+dp[i-1][0]);
        }
        return dp[prices.size()-1][1];
    }
};
// @lc code=end

