/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<int> res;
        vector<vector<int> > ret;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, res, ret);
        sort(ret.begin(), ret.end());
        vector<vector<int> > rett;
        rett.push_back(ret[0]);
        for(int i=1; i<ret.size(); i++){
            if(ret[i]==ret[i-1]) continue;
            else{
                rett.push_back(ret[i]);
            }
        }
        return rett;
    }

    void dfs(vector<int> & nums, vector<bool> & used, vector<int> & res, vector<vector<int> > & ret){
//        if(res.size()==nums.size()&& isNotIn(res , ret)){
//            ret.push_back(res);
//            return;
//        }
        if(res.size()==nums.size()){
            ret.push_back(res);
            return;
        }
        else{
            for(int i=0; i<nums.size(); i++){
                if(used[i]==true) continue;
                else{
                    used[i] = true;
                    res.push_back(nums[i]);
                    dfs(nums, used, res, ret);
                    res.pop_back();
                    used[i] = false;
                }
            }
        }
    }

//    bool isNotIn(vector<int> & res ,vector<vector<int> > & ret){
//        for(int i=0; i<ret.size(); i++){
//            if(ret.at(i)==res){return false;}
//        }
//        return true;
//    }
    
};
// @lc code=end

