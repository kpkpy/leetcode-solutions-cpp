/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    int fib(int n) {
        //if(n<=1)
            //return n;
        //vector<int> dp(n + 1);
        //dp[0] = 0;
        //dp[1] = 1;
        //for (int i = 2; i <= n; i++){
            //dp[i] = dp[i - 1] + dp[i - 2];
        //}
        //return dp[n];
    //}

    int fib(int n){
        if(n<=1)
            return n;

        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
// @lc code=end

