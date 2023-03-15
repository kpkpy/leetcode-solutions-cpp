/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s+s;
        t.erase(t.begin());
        t.erase(t.end()-1);
        if(t.find(s)!=std::string::npos) return true;
        else return false;
    }
};
// @lc code=end

