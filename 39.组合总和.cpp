/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        comb(candidates, target, 0, 0);
        return res;
    }
    
    void comb(vector<int> & candidates, int target, int sum,  int startIndex){
        //跳出条件
        if(sum==target){
            res.push_back(path);
            return;
        }
        //////////
        for(int i=startIndex; i<candidates.size()&&sum+candidates[i]<=target; i++){
            sum+=candidates[i];
            path.push_back(candidates[i]);
            comb(candidates, target, sum, i);
            sum-=candidates[i];
            path.pop_back();
        }
    }

private:
    vector<vector<int> > res;
    vector<int> path;
};
// @lc code=end

