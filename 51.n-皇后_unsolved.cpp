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
        this->size = n;
        vector<int> fieldRow(n , 0);
        vector<vector<int> > field(n, fieldRow);
        //0 表示 空置可放, 1表示已经放置, 2表示空置不可放置
        putQatRowN(0, field);

        vector<vector<string> > rets;
        vector<string> ret; 
        string retRow;
        for(int ii=0; ii<retfields.size(); ii++){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if(retfields[ii][i][j]==1) retRow.push_back('Q');
                    else retRow.push_back('.');
                }
                ret.push_back(retRow);
                retRow.clear();
            }
            rets.push_back(ret);
            ret.clear();
        }
        return rets;
    }

    void putQatRowN(int n, vector<vector<int> > field){
        if(n==size){
            //成功
            retfields.push_back(field);
            return;
        }
        for(int i=0; i<size; i++){
            if(field[n][i]==0){
                //put Q
                field[n][i] = 1;

                //更新可放置位置
                for(int j=0; j<size; j++){
                    if(field[j][i]<=0) field[j][i] --;
                }
                int x, y;
                x = n ; y = i;
                if(x>y){
                    x-=y;
                    y=0;
                }
                else{
                    x=0;
                    y-=x;
                }
                for(;(x<size&&x>=0)&&(y<size&&y>=0); x++, y++){
                    
                }

                putQatRowN(n+1, field);

                //回复棋盘
                field[n][i] = 0;
                for(int j=0; j<size; j++){
                    if(field[j][i]<0) field[j][i] ++;
                }
            }
        }
        return;
    }

    int size;
    vector<vector<vector<int> > > retfields;
};

// @lc code=end

