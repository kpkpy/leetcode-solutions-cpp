/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include "include.h"
// @lc code=start
class Solution {
public:
///    static bool cmp(vector<int> &a, vector<int> &b){
///        return a[1] < b[1];
///    }
///    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
///        if(intervals.size()==1) return 0;
///        sort(intervals.begin(), intervals.end(), cmp);
///        int res=1; int ext=intervals[0][1];
///        for(int i=1; i<intervals.size(); i++){
///            if(ext<=intervals[i][0]){
///                ext = intervals[i][1];
///                res++;
///            }
///        }
///        return intervals.size()-res;
///   }
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int> > &intervals){
        if(intervals.size()==1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0; int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(end<=intervals[i][0]){//no overlap
                end = intervals[i][1];
            }
            else{ // overlap
                end = min(end, intervals[i][1]);
                count ++;
            }
        }
        return count;
    }
};
// @lc code=end
