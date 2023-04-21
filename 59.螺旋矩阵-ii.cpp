/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int startx, starty;
        int loop = n/2;
        int mid = n/2;
        int count =1; int offset=1;
        int i, j;
        vector<vector<int> > res(n, vector<int> (n));
        while(loop--){
            i = startx; j = starty;
            for(j = starty; j<n-offset; j++){
                res[startx][j] = count++;
            }
            for(i = startx; i<n-offset; i++){
                res[i][j] = count++;
            }
            for(; j>starty; j--){
                res[i][j] = count++;
            }
            for(; i>startx; i--){
                res[i][j] = count++;
            }

            startx++; starty++;
            offset++;

        }
        if(n%2){
            res[mid][mid]=count;
        }
        return res;
    }
};
// @lc code=end

