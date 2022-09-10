/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > ms;
        string s; string st;
        while(!strs.empty()){
            s = strs.at(strs.size()-1);
            st = s;
            strs.pop_back();
            sort(st.begin(), st.end());
            ms[st].push_back(s);
        }
        vector<vector<string> > ret;
        for(map<string, vector<string> >::iterator it= ms.begin();\
         it != ms.end(); it++){
            ret.push_back(it->second);
        }
        return ret;
    }
};
// @lc code=end

