/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include "include.h"

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) obstacleGrid[i][j]-=2;
            }
        }

        for(int i=0; i<m && obstacleGrid[i][0] >=0; i++){
            obstacleGrid[i][0] = 1;
        }

        for(int i=0; i<n && obstacleGrid[0][i]>=0; i++){
            obstacleGrid[0][i] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                //og[i][j] = og[i-1][j] + og[i][j-1] 
                //only on og[][] not ob
                if(obstacleGrid[i][j] < 0) continue;
                int x = obstacleGrid[i-1][j] >=0 ? obstacleGrid[i-1][j] : 0;
                int y = obstacleGrid[i][j-1] >=0 ? obstacleGrid[i][j-1] : 0;
                obstacleGrid[i][j] = x + y;
            }
        }
        return obstacleGrid[m-1][n-1]>0? obstacleGrid[m-1][n-1]:0;
    }
};
// @lc code=end

