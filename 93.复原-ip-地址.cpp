/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if(s.size()==0||s.size()>12) return res;
        dfs(s, 0, 0);
        return res;
    }

    bool isValid(string &s, int start, int end){
        if(start>end) return false;
        if(start!=end&&s[start]=='0') return false;
        int num = 0;
        for(int i=start; i<=end; i++){
            if(s[i]<'0'||s[i]>'9') return false;
            num*=10;
            num+=s[i]-'0';
        }
        return num<=255;
    }

    void dfs(string &s, int start, int point){
        if(point==3){
            if(isValid(s, start, s.size()-1)) {
                res.push_back(s);
            };
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(isValid(s, start, i)){
                s.insert(s.begin()+i+1, '.');
                dfs(s, i+2, point+1);
                s.erase(s.begin()+i+1);
            }
            else break;
        }
    }

};
// @lc code=end

