/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    void removeDupSpaces(string &s){
        int i=0; int j=0;
        for(;;){
            if(s[j]!=' ') break;
            j++;
        }
        for(; j<s.size();j++){
            if(j-1>0&&s[j]==s[j-1]&&s[j]==' '){
                continue;
            }
            else{
                s[i++] = s[j];
            }
        }
        if(s[i-1]==' ') i--;
        s.resize(i);
    }
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
        // 去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }
    string reverseWords(string s) {
        removeDupSpaces(s);
        //removeExtraSpaces(s);
        reverse(s.begin(), s.end());
        int start =0;
        for(int i=0; i<=s.size(); i++){
            if(i==s.size()||s[i]==' '){
                reverse(s.begin()+start, s.begin()+i);
                start = i+1;
            }
        }
        return s;
    }
};

// @lc code=end

