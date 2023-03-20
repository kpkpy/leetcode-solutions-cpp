/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        // integer: 329
        // index  : 012
        int flag = s.size();
        for(int i=s.size()-1; i>0; i--){
            if(s[i-1]>s[i]){
                flag = i;
                s[i-1]--;
            }
        }
        for(int i=flag; i<s.size(); i++){
            s[i] = '9';
        }
        return stoi(s);
    }
};
// @lc code=end

