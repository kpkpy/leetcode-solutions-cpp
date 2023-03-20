/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=0; i<prices.size()-1; i++){
            if(prices[i+1]-prices[i]>0){
                profit+=prices[i+1]-prices[i];
            }
        }
        return profit;
    }
};
// @lc code=end

