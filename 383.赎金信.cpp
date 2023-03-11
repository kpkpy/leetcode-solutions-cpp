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
        if(ransomNote.length()>magazine.size()) return false;
        for(auto i=0; i<magazine.length(); i++){
            alphabet[magazine[i]-'a']++;
        }
        for(auto j=0; j<ransomNote.length(); j++){
            if(alphabet[ransomNote[j]-'a']==0){
                return false;
            }
            else alphabet[ransomNote[j]-'a']--;
        }
        return true;
    }
};
// @lc code=end

