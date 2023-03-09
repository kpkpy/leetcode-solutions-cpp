/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std; 

// @lc code=start
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > ret;
        vector<int> cur;
        sort(intervals.begin(), intervals.end());
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

