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

    }
};
// @lc code=end

