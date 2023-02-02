/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include "include.h"

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        stack<string> s_stk;
        string word;
        for(string::iterator si=path.begin(); si!=path.end(); si++){
            if(*si == '/'){
                si ++;
                return tractNextWord(path, si);
                //if(word!="")    s_stk.push(word);
                if(word!="") return word;
                word = "";
            }
        }

        while(!s_stk.empty()){
            ret+=s_stk.top();
            s_stk.pop();
            ret+='/';
        }
        return ret;
    }

    string tractNextWord(string target, string::iterator it){
        string ret = "";
        for(string::iterator i  = it; i<target.end(); i ++){
            if(*i == '/') break;
            ret += *i;
        }
        return ret;
    }
};
// @lc code=end

