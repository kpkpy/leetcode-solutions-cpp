/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int resnums=0;
    int totalNQueens(int n) {
        string str(n, '.');
        vector<string> board(n, str);
        dfs(board, 0);
        return resnums;
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
            resnums++;
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