/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "include.h"
// @lc code=start
class Solution {
public:
//    哈希法
//    vector<vector<int> > threeSum(vector<int>& nums) {
//        vector<vector<int> > ret;
//        sort(nums.begin(), nums.end());
//        for(int a=0; a<nums.size(); a++){
//
//            if(nums[a]>0) break;
//
//            if(a>0 && nums[a-1]==nums[a]) continue;
//
//            unordered_set<int> uset;
//            
//            for(int b=a+1; b<nums.size(); b++){
//                if(b>a+2
//                 &&nums[b-1]==nums[b]
//                 &&nums[b-2]==nums[b-1]) continue;
//                int c = 0-(nums[a]+ nums[b]);
//                if(uset.find(c)!=uset.end()){
//                    ret.push_back({nums[a], nums[b], c});
//                    uset.erase(c);
//                }
//                else {
//                    uset.insert(nums[b]);
//                }
//            }
//        }
//        return ret;
//    }

//  双指针法
    vector<vector<int> > threeSum(vector<int>& nums){
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        int left; int right; int sum;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            left = i+1; right = nums.size()-1;
            while(left<right){
                sum = nums[i]+nums[left]+nums[right];
                if(sum>0) right--;
                else if(sum<0) left++;
                else{
                    ret.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while(left<right&&nums[left]==nums[left+1]) left++;
                    while(left<right&&nums[right]==nums[right-1]) right--;
                    
                    right--; left++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

