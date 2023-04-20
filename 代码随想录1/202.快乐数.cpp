/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    unordered_set<int> set1;
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        while(1){
            int sum  = getSum(n);
            if(sum==1){
                return true;
            }
            if(set1.find(sum)!=set1.end()){
                return false;
            }
            else {
                set1.insert(sum);
            }
            n = sum;
        }
        return false;
    }
};
// @lc code=end

