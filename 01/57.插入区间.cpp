/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        bool isInsert =0 ;
        for(int i=0; i<intervals.size(); i++){
            if(newInterval[0]<intervals[i][0]){
                intervals.insert(intervals.begin()+i, newInterval);
                isInsert =  1;
                break;
            }
        }
        if(isInsert==0){intervals.push_back(newInterval);}
        return merge(intervals);
    }

    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > ret;
        vector<int> cur;
        //sort(intervals.begin(), intervals.end());
        cur = intervals[0];
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] >= cur[0] && intervals[i][1] <= cur[1] ){
                //do nothin'
            }
            else if(intervals[i][0] <= cur[1] && intervals[i][1] >= cur[1]){
                cur[1] = intervals[i][1];
            }
            else{
                ret.push_back(cur);
                cur = intervals[i];
            }
        }
        ret.push_back(cur);
        return ret;
    }
};
// @lc code=end

