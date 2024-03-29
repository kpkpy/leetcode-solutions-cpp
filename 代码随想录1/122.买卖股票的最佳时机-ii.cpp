/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    int maxProfit(vector<int>& prices) {
//        int profit = 0;
//        for(int i=0; i<prices.size()-1; i++){
//            if(prices[i+1]-prices[i]>0){
//                profit+=prices[i+1]-prices[i];
//            }
//        }
//        return profit;
//    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        vector<vector<int> > dp(prices.size(), vector<int>(2));
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for(int i=1; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};
// @lc code=end

