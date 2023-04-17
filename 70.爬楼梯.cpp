/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include "include.h"
// @lc code=start

//class Solution {
//public:
//    int climbStairs(int n) {
//        int climb[n+1];
//        if(n<=1) return n;
//        for(int i=3; i<=n; i++){
//            climb[i] = climb[i-1] + climb[i-2];
//        }
//        return climb[n];
//    }
//};

class Solution{
    public:
    int climbStairs(int n){
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=2; j++){
                if(i-j>=0) dp[i]+=dp[i-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

