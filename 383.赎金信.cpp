/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> alphabet(26, 0);
        for(int i=0; i<magazine.size(); i++){
            alphabet[magazine[i]-'a']++;
        }
        for(int i=0; i<ransomNote.size(); i++){
            alphabet[ransomNote[i]-'a']--;
            if(alphabet[ransomNote[i]-'a']<0) return false;
        }
        return true;
    }
};
// @lc code=end

