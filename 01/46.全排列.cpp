/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> ret;
        vector<vector<int> > res;
        dfs(nums, used, ret, res);
        return res;
    }

    void dfs(vector<int> & nums, vector<bool> & used, vector<int> & ret, vector<vector<int> > & res){
        if(ret.size()==nums.size()){
            res.push_back(ret);
            return;
        }
        else{
            for(int i=0; i<nums.size(); i++){
                if(used[i]!=false) continue;
                else{
                    used[i] = true;
                    ret.push_back(nums[i]);
                    dfs(nums, used, ret, res);
                    used[i] = false; 
                    ret.pop_back();
                }
            }
        }
    }  
};
// @lc code=end

