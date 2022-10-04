/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> matrixRow(n, 0);
        vector<bool> visitedRow(n, false);
        vector<vector<int> > matrix(n, matrixRow);
        vector<vector<bool> > isvisited(n, visitedRow);

        int x=0; int y = 0;
        int curNum = 1;
        if(n==1) return {{1}};
        if(n==2) return {{1,2}, {4, 3}};
        while(1){
            if(isvisited[x+1][y]==true&&isvisited[x-1][y]==true&&isvisited[x][y+1]==true&&isvisited[x][y-1]==true){
                if(isvisited[x][y] == false) matrix[x][y] = curNum;
                break;
            };
            for(int i = y; isvisited[x][i] == false; i++){
                matrix[x][i] = curNum;
                curNum++;
                isvisited[x][i] = true;
                if(i==n-1||isvisited[x][i+1]==true){
                    y = i; 
                    break;
                }
            }
            x++;

            for(int i = x; isvisited[i][y]== false; i++){
                matrix[i][y] = curNum;
                isvisited[i][y] = true;
                curNum ++ ;
                if(i==n-1||isvisited[i+1][y]==true){
                    x = i; 
                    break;
                }
            }
            y--;

            for(int i = y; isvisited[x][i]==false; i--){
                matrix[x][i] = curNum;
                isvisited[x][i] = true;
                curNum ++;
                if(i==0||isvisited[x][i-1]==true){
                    y = i; 
                    break;
                }
            }
            x--;

            for(int i = x; isvisited[i][y]== false; i--){
                matrix[i][y] = curNum;
                isvisited[i][y] = true;
                curNum ++;
                if(i==0||isvisited[i-1][y]==true){
                    x = i; 
                    break;
                }
            }
            y++;
        }
        return matrix;
    }
};
// @lc code=end

