/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

/*
之前有一个最小步骤的题 [45] 跳跃游戏II
*/

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = nums.size()-1;
        int dist = 1;
        if(nums.size()==1) return true;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]>=dist){
                reachable = i;
                dist = 1; continue;
            }
            else{
                dist ++;
            }
        }
        return reachable==0? true : false;
    }
};
// @lc code=end

