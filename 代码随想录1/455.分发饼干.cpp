/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookie = s.size()-1;
        int res = 0;
        for(int i=g.size()-1; i>=0; i--){
            if(cookie>=0&&s[cookie]>=g[i]){
                res ++;
                cookie--;
            }
        }
        return res;
    }
};
// @lc code=end

