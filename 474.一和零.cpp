/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(string s : strs){
            int one = 0;
            int zero = 0;
            for(char c : s){
                if(c=='0')
                    zero++;
                else
                    one++;
            }
            for (int i = m; i >= zero; i--){
                for (int j = n; j >= one; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

