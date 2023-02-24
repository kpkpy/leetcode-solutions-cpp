/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

#include "include.h" 

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m, n;
        n = matrix[0].size();
        m = matrix.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n;++j){
                if(matrix[i][j]==0){
                    for(int ii=0; ii<m; ii++){
                        if(matrix[ii][j]!=0)matrix[ii][j] = -888;
                    }
                    for(int jj=0; jj<n; jj++){
                        if(matrix[i][jj]!=0)matrix[i][jj] = -888;
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==-888){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
// @lc code=end
