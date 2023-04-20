/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n==1){
            return x;
        }
        else if(n==0){
            return 1;
        }
        else if(n%2==0){
            return myPow(x*x, n/2);
        }
        else{
            return (n>0? x:1/x) * myPow(x*x, n/2);
        }
    }
};
// @lc code=end

