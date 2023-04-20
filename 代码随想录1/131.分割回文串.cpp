/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<string> > ret;
    vector<string> path;
    vector<vector<string> > partition(string s) {
        if(s.size()==0) return ret;
        dfs(s, 0);
        return ret;
    }

    bool isPalindrome(string& s, int start, int end){
        for(int i=start, j=end; i<j; j--, i++){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }

    void dfs(string &s, int startIndex){
        if(startIndex>=s.size()){
            ret.push_back(path);
            return; 
        }
        for(int i=startIndex; i<s.size(); i++){
            if(isPalindrome(s, startIndex, i)){
                string str = s.substr(startIndex, i-startIndex+1);
                path.push_back(str);
                dfs(s, i+1);
                path.pop_back();
            }
        }
        return ;
    }
};
// @lc code=end

