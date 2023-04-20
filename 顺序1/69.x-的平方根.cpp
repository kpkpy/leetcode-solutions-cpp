/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

#include "include.h"

// @lc code=start
//class Solution {
//public:
//    int mySqrt(int x) {
//        long ret = 0;
//        bool t1 = false;
//        bool t2 = false;
//        while(!(t1&t2)){
//            if(ret*ret<=x) t1 = true;
//            ret++;
//            if(ret*ret>x) t2 = true;
//        }
//        return --ret;
//    }
//};

class Solution {
public:
    int mySqrt(int x) {
        // 牛顿迭代
        
        double x_begin = x ;
        double y_begin = x_begin*x_begin - x;
        double k = 2*x_begin;
        double b = y_begin - k * x_begin;
        // 求切线和x轴的交点
        double x_next = (-b)/k;
        while(x_begin - x_next >= 1e-7){
            double temp = x_next;
            x_next = (x_next*x_next + x) / (2 * x_next);
            x_begin = temp;
        }
        return int(x_begin);
    }
};
// @lc code=end

