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
        vector<int> alphabet(26, 0);
        for(int i=0; i<s.size(); i++){
            alphabet[s.at(i)-'a']++;
        }
        for(int i=0; i<t.size(); i++){
            alphabet[t.at(i)-'a']--;
        }
        for(int i=0; i<alphabet.size(); i++){
            if(alphabet[i]!=0) return false;
        }
        return true;
    }
};
// @lc code=end

