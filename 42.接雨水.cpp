/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * 322/322 cases passed (16 ms)
 * Your runtime beats 50.06 % of cpp submissions
 * Your memory usage beats 87.89 % of cpp submissions (19.2 MB)
 * 
 * 
 * [42] 接雨水
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int left, right;
        int water=0;
        int leftp=0; int rightp = height.size()-1;
        left = height[leftp]; right = height[rightp];
        int maxI = findMaxIndex(height);
        for(int i=leftp+1; i<maxI; i++){
            if(height[i]<left){
                water+=left-height[i];
            }
            else{
                left = height[i];
                leftp = i;
            }
        }
        for(int i=rightp-1; i>maxI; i--){
            if(height[i]<right){
                water+=right-height[i];
            }
            else{
                right = height[i];
                rightp = i;
            }
        }
        return water;
    }

    int findMaxIndex(vector<int> & height){
        int max=height[0]; int maxI = 0;
        for(int i=0; i<height.size(); i++){
            if(height[i]>max){
                max = height[i];
                maxI= i;
            }
        }
        return maxI;
    }
};
// @lc code=end

