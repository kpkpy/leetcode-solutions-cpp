/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    string removeDuplicates(string s) {
//        stack<char> stk;
//        for(int i=0; i<s.size(); i++){
//            if(stk.empty()) stk.push(s[i]);
//            else if(stk.top()==s[i]) stk.pop();
//            else stk.push(s[i]);
//        }
//        string ret;
//        while(!stk.empty()){
//            ret.push_back(stk.top());
//            stk.pop();
//        }
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
    string removeDuplicates(string s){
        string ret;
        for(int i=0; i<s.size(); i++){
            if(ret.empty()) ret.push_back(s[i]);
            else if(ret[ret.size()-1]==s[i]) ret.pop_back();
            else ret.push_back(s[i]);
        }
        return ret;
    }
};
// @lc code=end

