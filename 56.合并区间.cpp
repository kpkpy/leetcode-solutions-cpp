/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int> > res;
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= res.back()[1]){//overlap
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else { // not  overlap
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

