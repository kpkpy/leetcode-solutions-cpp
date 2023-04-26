/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    void getNext(int *next, string & s){
        int j = -1;
        next[0]=j;
        for(int i=1; i<s.size(); i++){
            //前后缀不相同, 寻找相同的前后缀
            while(j>=0&&s[i]!=s[j+1]){
                j = next[j];
            }
            if(s[i]==s[j+1]){
                j++;
            }
            next[i]=j;
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        int next[needle.size()];
        int j=-1;
        getNext(next, needle);
        for(int i=0; i<haystack.size(); i++){
            while(j>=0&&haystack[i]!=needle[j+1]){
                j = next[j];
            }
            if(haystack[i]==needle[j]){
                j++;
            }
            if(j==needle.size()-1){
                return (i-needle.size()+1);
            }
        }
        return 0;
    }
};
// @lc code=end

