/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> flag(0, 10);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.') continue;
                if(isSolveable(board, flag, i, j)!=-1){
                    board[i][j] = isSolveable(board, flag, i, j);
                }
            }
        }
    }

    int isSolveable(vector<vector<char>> & board, vector<int> & flag, int row, int col){
        flag.assign(0, 10);
        int count =0;
        int x_base; int y_base;
        x_base = row - row%3;
        y_base = col - col%3;
        for(int i=0; i<9; i++){
            if(board[row][i]!='.'){
                if(flag[board[row][i]-'0']==0){
                    flag[board[row][i]-'0'] = 1;
                    count ++;
                }
            }
        }

        for(int i=0; i<9; i++){
            if(board[i][col]!='.'){
                if(flag[board[i][col]-'0']==0){
                    flag[board[i][col]-'0'] = 1;
                    count ++;
                }
            }
        }

        for(int i=0+x_base; i<3+x_base; i++){
            for(int j=0+y_base; j<3+y_base; j++){
                if(board[i][j]!='.'){
                    if(flag[board[i][j]-'0']==0){
                        flag[board[i][col]-'0'] = 1;
                        count ++;
                    }
                }
            }
        }

        if(count == 8){
            for(int i=1; i<10; i++){
                if(flag[i]==0) return i;
            }
        }
        return -1;
    }
};
// @lc code=end

