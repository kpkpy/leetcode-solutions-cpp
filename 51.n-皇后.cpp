/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<char> chessRow(n, '.');
        vector<vector<char> > chess(n, chessRow);
        dfs(chess, n, 0);
        return rets;
    }

    void dfs(vector<vector<char> > & chess, int n, int nRow){
        if(nRow == n){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    retRow.push_back(chess[i][j]);
                }
                ret.push_back(retRow);
                retRow.clear();
            }
            rets.push_back(ret);
            ret.clear();
            return;
        }
        for(int i=0; i<n; i++){
            chess[nRow][i] = 'Q'; // put
            if(isValid(chess, n, nRow, i)) dfs(chess, n, nRow+1);
            chess[nRow][i] = '.';
        }
    }

    bool isValid(vector<vector<char> > & chess, int n, int x, int y){
        //x, y is the pos of the nQ

        //check 90'
        for(int i=0; i<x; i++){
            if(chess[i][y]=='Q') return false;
        }
        
        //check 45'
        for(int i=x-1, j=y-1; i>=0&&j>=0; i--, j--){
            if(chess[i][j]=='Q') return false;
        }

        //check 135'
        for(int i=x-1, j=y+1; i>=0&&j<n; i--, j++){
            if(chess[i][j]=='Q') return false;
        }
        
        return true;
    }
    vector<vector<string> > rets;
    vector<string> ret;
    string retRow;
};
// @lc code=end

