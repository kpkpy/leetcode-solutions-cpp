/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};

    vector<string> res;
    string s;
    vector<string> letterCombinations(string digits) {
        res.clear(); s.clear();
        if(digits.size()==0) return res;
        dfs(digits, 0);
        return res;
    }

    void dfs(string &digits, int index){
        if(index==digits.size()){
            res.push_back(s);
            return ;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i=0; i<letters.size(); i++){
            s.push_back(letters[i]);
            dfs(digits, index+1);
            s.pop_back();
        }
        return ;
    }
};
// @lc code=end

