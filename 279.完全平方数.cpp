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
//        vector<int> dp(n+1, INT_MAX);
//        dp[0] = 0;
//        for(int i=0; i<=n; i++){
//            for(int j=1; j*j<=i ;j++){
//                if((i-j*j)>=0&&dp[i-j*j]!=INT_MAX)
//                    dp[i] = min(dp[i-j*j]+1, dp[i]);
//            }
//        }
//        return dp[n];
//    }
    int numSquares(int n){
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i*i<=n; i++){
            for(int j=i; j<=n; j++){
                if((j-i*i)>=0 && dp[j-i*i]!=INT_MAX)
                    dp[j] = min(dp[j-i*i]+1, dp[j]);
            }
        }
        return dp[n];
    }
};

// @lc code=end

