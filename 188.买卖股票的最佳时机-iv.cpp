/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0) return 0;
        if(prices.size()==0) return 0;
        vector<vector<int> > dp(prices.size(), vector<int> (2*k+1, 0));
        for(int i=1; i<2*k+1; i+=2){
            dp[0][i] = -prices[0];
        }

        for(int i=1; i<prices.size(); i++){
            dp[i][0] = dp[i-1][0];
            for(int j=0; j<2*k-1; j+=2){
                dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j]-prices[i]);
                dp[i][j+2] = max(dp[i-1][j+2], dp[i-1][j+1]+prices[i]);
            }
        }
        return dp[prices.size()-1][2*k];
    }
};
// @lc code=end

