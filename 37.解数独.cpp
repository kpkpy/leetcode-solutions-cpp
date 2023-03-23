/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        dfs(board);
    }
    bool dfs(vector<vector<char> >& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(int k=1; k<10; k++){
                        if(isValid(board, i, j, k)){
                            board[i][j] = k+'0';
                            if(dfs(board)) return true;
                            board[i][j] = '.';
                        }
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char> >& board, int x, int y, int k) {
        for(int i=0; i<9; i++){
            if(board[i][y]==k+'0') return false;
        }
        for(int i=0; i<9; i++){
            if(board[x][i]==k+'0') return false;
        }
        int xbase = x/3*3;
        int ybase = y/3*3;
        for(int i=xbase; i<xbase+3; i++){
            for(int j=ybase; j<ybase+3; j++){
                if(board[i][j]==k+'0') return false;
            }
        }
        return true;
    }
};
// @lc code=end

