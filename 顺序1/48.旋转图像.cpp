/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        //先转置, 在对称变换
        int length, width;
        length = width = matrix[0].size();

        //转置
        for(int i=0; i<length ; i++){
            for(int j=i; j<width; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //对称
        for(int i=0; i<length; i++){
            for(int j=0; j<width/2; j++){
                swap(matrix[i][j], matrix[i][width-1-j]);
            }
        }
    }
};
// @lc code=end

