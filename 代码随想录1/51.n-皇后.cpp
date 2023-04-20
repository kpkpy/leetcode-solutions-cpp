/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<string> > res;
    vector<vector<string> > solveNQueens(int n) {
        string str(n, '.');
        vector<string> board(n, str);
        dfs(board, 0);
        return res;
    }

    bool isValid(vector<string>& board, int x, int y){
        for(int i=0; i<board.size(); i++){
            if(board[i][y]=='Q') return false;
        }
        for(int i=x, j=y; i<board.size()&&j<board.size(); i++, j++){
            if(board[i][j]=='Q')  return false;
        }
        for(int i=x, j=y; i>=0&&j<board.size(); i--, j++){
            if(board[i][j]=='Q') return false;
        }
        for(int i=x, j=y; i<board.size()&&j>=0; i++, j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=x, j=y; i>=0&&j>=0; i--, j--){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }

    void dfs(vector<string> &board, int queen ){
        if(queen==board.size()) {
            res.push_back(board);
            return;
        }
        for(int i=0; i<board.size(); i++){
            if(isValid(board, queen, i)){
                board[queen][i] = 'Q';
                dfs(board, queen+1);
                board[queen][i] = '.';
            }
        }
        return;
    }
};
// @lc code=end

