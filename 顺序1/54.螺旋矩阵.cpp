/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int width = matrix[0].size();
        int height = matrix.size();

        int x =0 ; int y = 0;

        while(true){
            for(int i=x; i<width; i++){
                if(matrix[y][i] == 888) break;
                ret.push_back(matrix[y][i]);
                matrix[y][i] = 888; // specfic symbol
                x = i;
            }
            y++;
            if(y>=height||matrix[y][x] == 888) break;
            for(int i = y; i<height; i++){
                if(matrix[i][x] == 888) break;
                ret.push_back(matrix[i][x]);
                matrix[i][x] = 888;
                y = i;
            }
            x--;
            if(x<0||matrix[y][x] == 888) break;
            for(int i=x; i>=0; i--){
                if(matrix[y][i]==888) break;
                ret.push_back(matrix[y][i]);
                matrix[y][i] = 888; // specfic symbol
                x = i;
            }
            y--;
            if(y<0||matrix[y][x] == 888) break;
            for(int i = y; i<height; i--){
                if(matrix[i][x]==888) break;
                ret.push_back(matrix[i][x]);
                matrix[i][x] = 888;
                y = i;
            }
            x++;
            if(x>=width||matrix[y][x] == 888) break;
        }
        return ret;
    }
};
// @lc code=end

