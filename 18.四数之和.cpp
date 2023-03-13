/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>target && nums[i]>=0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;

            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]>target&&nums[i]+nums[j]>=0) break;
                if(j>i+1 && nums[j]==nums[j-1]) continue; 

                int left=j+1; int right=nums.size()-1;
                while(left<right){
                    long sum = (long) nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum>target) right--;
                    else if(sum<target) left++;
                    else{
                        ret.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(left<right&&nums[left]==nums[left+1]) left++;
                        while(left<right&&nums[right]==nums[right-1]) right--;
                        left++; right--;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

