/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string ret(s);
        int i=0; int j=s.size()-1;
        while(i<j){
            if(isVowel(s[i])&&isVowel(s[j])) {
                swap(s[i], s[j]);
                i++; j--;
            }
            else if(isVowel(s[i])) j--;
            else i++;
        }
        return s;
    }
    bool isVowel(char c){
        if(c=='a'
        || c=='e'
        || c=='i'
        || c=='o'
        || c=='u'
        || c=='A'
        || c=='E'
        || c=='I'
        || c=='O'
        || c=='U'
        ) return true;
        else return false;
    }
};
// @lc code=end

