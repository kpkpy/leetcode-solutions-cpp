/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
/*
//迭代遍历2次
//T(n) = O(n)
//S(n) = O(1)
    int maxSubArray(vector<int>& nums) {
        int sum =0; int max=nums[0];
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>max) max = nums[i];
        }

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum<0){//sum <0 则弃置
                sum=0;
                continue;
            }
            if(sum>max){
                max = sum;
            }
        }
        return max;
    }
*/
    int maxSubArray(vector<int>& nums) {
        int max = 0;
        maxArray(nums, 0, nums.size(), max);
        return max;
    }

    int maxArray(vector<int> & nums , int q, int p, int & max) {
        int mid = (p+q) / 2;
        maxSubArrayCross(nums, p, q, max);
        maxArray(nums, p, mid, max);
        maxArray(nums, mid+1, q, max);
        return max;
    }

    int maxSubArrayCross(vector<int> & nums , int p , int q, \
                         int & max) {
        int mid = (p+q) / 2;
        int sum = 0;
        int maxL = 0; int maxR = 0;
        for(int i=mid -1; i>=0; i--){
            sum+=nums[i];
            if(sum<0){
                sum =0; continue;
            }
            else if(sum>max){
                maxL = sum;
            }
        }
        sum =0 ;
        for(int i=mid; i<q; i++){
            sum += nums[i];
            if(sum<0){
                sum =0 ; continue;
            }
            else if(sum>maxR){
                maxR = sum ;
            }
        }
        if(max < maxR+maxL){
            max = maxR+maxL;
        }
        return maxR+maxL;
    }
};
// @lc code=end

