/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <=i/2; j++){
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] *j));
            }
        }
        return dp[n];
    }
};
// @lc code=end

