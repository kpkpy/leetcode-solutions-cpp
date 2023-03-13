/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0; int j=s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++; j--;
        }
        return;
    }
};
// @lc code=end

