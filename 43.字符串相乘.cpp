/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        return string(stoi(num1)*stoi(num2));
    }
};
// @lc code=end

