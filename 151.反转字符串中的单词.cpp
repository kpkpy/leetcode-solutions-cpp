/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    void removeExtraSpaces(string &s){
        for(int i=1; i<s.size(); i++){
            if(s.at(i)==' '&&s.at(i-1)==' ') {
                s.erase(s.begin()+i);
                i--;
            }
        }

        if(s.size()>0 && s.at(s.size()-1)==' '){
            s.erase(s.begin()+s.size()-1);
        }

        if(s.size()>0&&s[0]==' '){
            s.erase(s.begin());
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s.begin(), s.end());
        int slow=0; int fast=0;
        for(;fast<=s.size(); fast++){
            if(fast==s.size()){
                reverse(s.begin()+slow, s.end());
                break;
            }
            if(s.at(fast)==' '){
                reverse(s.begin()+slow, s.begin()+fast);
                slow=fast+1;
            }
        }
        return s;
    }
};
// @lc code=end

