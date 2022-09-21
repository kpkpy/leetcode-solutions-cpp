/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> chessRow(n, false);
        vector<vector<bool> > chess(n, chessRow);
        dfs(chess, n, 0);
        return ret;
    }

    void dfs(vector<vector<bool> > & chess, int n, int nRow){
        if(n==nRow){
            ret++;
            return ;
        }
        for(int i=0; i<n; i++){
            chess[nRow][i] = true;
            if(isValid(chess, n, nRow, i)){
                dfs(chess, n, nRow+1);
            }
            chess[nRow][i] = false;
        }
    }

    bool isValid(vector<vector<bool> > & chess, int n, int x, int y){
        
        //check 90'
        for(int i=0; i<x; i++){
            if(chess[i][y]==true) return false;
        }

        //check 45'
        for(int i=x-1, j=y-1; i>=0&&j>=0; i--, j--){
            if(chess[i][j]==true) return false;
        }

        //check 135'
        for(int i=x-1, j=y+1; i>=0&&j<n; i--, j++){
            if(chess[i][j]==true) return false;
        }
        return true;
    }

    int ret;
};
// @lc code=end

