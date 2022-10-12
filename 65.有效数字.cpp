/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

#include "include.h"

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        int len = 0;//去除首尾空格
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(0, s.size() - len);
        len = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(len);
        if(s.size() == 0) return false;
        
        int id = s.find('e');//划分为底数和指数
        if(id == string::npos) {
            id = s.find('E');
            if(id == string::npos) return judgeP(s);
        }//判断底数
        return judgeP(s.substr(0, id)) && judgeS(s.substr(id + 1));//判断指数
    }
    bool judgeP(string s)
    {
        bool res = false; 
        bool pointed = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' || s[i] == '-')
            {
                if(i != 0) return false;
            }
            else if(s[i] == '.')
            {
                if(pointed) return false;
                pointed = true;
            }
            else if(s[i] < '0' || s[i] > '9') return false;
            else res = true;
        }
        return res;
    }
    
    bool judgeS(string s)
    {
        bool res = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '-' || s[i] == '+')
            {
                if(i != 0) return false;
            }
            else if(s[i] < '0' || s[i] > '9') return false;
            else res = true;
        }
        return res;
    }

};// @lc code=end

