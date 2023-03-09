/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<bool> flag(candidates.size(), false);
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        comb(candidates, target, 0, 0, flag);
        return res;
    }
    
    void comb(vector<int> & candidates, int target, int sum,  int startIndex, vector<bool> & flag){
        //跳出条件
        if(sum==target){
            res.push_back(path);
            return;
        }
        //////////
        for(int i=startIndex; i<candidates.size()&&sum+candidates[i]<=target; i++){
            if(i>0&&candidates[i]==candidates[i-1]&&flag[i-1] == false){
                continue;
            }
            sum+=candidates[i];
            path.push_back(candidates[i]);
            flag[i] = true;
            comb(candidates, target, sum, i+1, flag);
            sum-=candidates[i];
            path.pop_back();
            flag[i] = false;
        }
    }

private:
    vector<vector<int> > res;
    vector<int> path;
};
// @lc code=end

