/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > board(m, vector<int> (n, 0));
        board[0][0] = 1;
        for(int i=0; i<n; i++){
            board[0][i] = 1;
        }
        for(int i=0; i<m; i++){
            board[i][0] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                board[i][j] = board[i-1][j] + board[i][j-1];
            }
        }
        return board[m-1][n-1];
    }
};
// @lc code=end

