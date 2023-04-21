/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n!=0){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> us;
        while(n!=1){
            n = getSum(n);
            if(us.find(n)!=us.end()) return false;
            else{
                us.insert(n);
            }
        }
        return true;
    }
};
// @lc code=end

