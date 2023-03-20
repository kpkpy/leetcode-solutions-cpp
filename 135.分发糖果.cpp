/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]){
                candies[i] = max(candies[i], candies[i-1]+1);
            }
        }

        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        
        int ret = accumulate(candies.begin(), candies.end(), 0);
        //int ret = 0;
        //for(int i=0; i<candies.size(); i++) ret+=candies[i];
        return ret;
    }
};
// @lc code=end

