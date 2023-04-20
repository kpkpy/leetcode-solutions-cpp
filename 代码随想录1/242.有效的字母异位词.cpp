/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26, 0);
        if(s.length()!=t.length()) return false;
        for(auto i=0; i<s.length(); i++){
            alpha[s[i]-'a']++;
        }
        for(auto j=0; j<t.length(); j++){
            alpha[t[j]-'a']--;
        }
        for(auto i=0; i<alpha.size(); i++){
            if(alpha[i]!=0) return false;
        }
        return true;
    }
};
// @lc code=end

