/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include "include.h"

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i;
        for(i=0; i<m; i++){
            if(target==matrix[i][0]) return true;
            else if(target>matrix[i][0]){
                continue;
            }
            else{
                i--; if(i<0) i=0;
                for(int j=0; j<n; j++){
                    if(matrix[i][j]==target) return true;
                }
                return false;
            }
        }
        i--;
        if(i<0) i=0;
        for(int j=0; j<n; j++){
            if(matrix[i][j]==target) return true;
        }
        return false;
    }
};
// @lc code=end

