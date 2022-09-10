/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
//    int jump(vector<int>& nums) {
        //int pos = nums.size()-1;
        //int jumps = 0;
        //while(pos>0){
            //for(int i=0; i<pos; i++){
                //if(nums[i]+i>=pos){
                    //jumps++;
                    //pos = i;
                    //break;
                //}
            //}
        //}
        //return jumps;
    //}
    
    int jump(vector<int> & nums){
        int boundary = nums[0];
        int far = boundary;
        int steps = 1;
        if(nums.size()==1){return 0;}
        if(boundary>=nums.size()-1) return 1;
        for(int i=1; i<nums.size(); i++){
            if(i+nums[i]>far) far = i+nums[i];

            if(i==boundary){
                steps++;
                boundary = far;
                if(boundary>=nums.size()-1) return steps;
            }
        }
        return -1;
    }
};
// @lc code=end

