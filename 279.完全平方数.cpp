/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    int numSquares(int n) {
//        vector<int> dp(n + 1, INT_MAX);
//        dp[0] = 0;
//        for (int i = 1; i*i <= n; i++){
//            for (int j = i * i; j <= n; j++){
//                dp[j] = min(dp[j], dp[j - i * i]+1);
//            }
//        }
//        return dp[n];
//    }
    int numSquares(int n){
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++){
            for (int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

