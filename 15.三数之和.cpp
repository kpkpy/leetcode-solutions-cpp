/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    vector<vector<int> > threeSum(vector<int>& nums) {
//        vector<vector<int> > res;
//        sort(nums.begin(), nums.end());
//        for(int i=0; i<nums.size(); i++){
//            if(nums[i]>0) break;
//            if(i>0&&nums[i]==nums[i-1]) continue;
//
//            unordered_set<int> uset;
//            for(int j=i+1; j<nums.size(); j++){
//                if(j>i+2&&nums[j-1]==nums[j-2]&&nums[j]==nums[j-1]) continue;
//                int c = 0-nums[i]-nums[j];
//                if(uset.find(c)!=uset.end()){
//                    res.push_back(vector<int>{nums[i], nums[j], c});
//                    uset.erase(c);
//                }
//                else{
//                    uset.insert(nums[j]);
//                }
//            }
//        }
//        return res;
//    }
    vector<vector<int> > threeSum(vector<int> &nums){
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;

            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0) right--;
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left<right&&nums[left]==nums[left+1]) left++;
                    while(left<right&&nums[right]==nums[right-1]) right--;
                    left++; right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

