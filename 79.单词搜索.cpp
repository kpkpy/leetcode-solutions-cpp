/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "include.h"
// @lc code=start
//class Solution {
//public:
//    bool exist(vector<vector<char>>& board, string word) {
//        auto m = board.size();
//        auto n = board[0].size();
//        for(auto i=0; i<m; i++){
//            for(auto j=0; j<n; j++){
//                if(dfs(board, word, 0, i, j)==true) return true;
//            }
//        }
//        return false;
//    }
//    
//    bool dfs(vector<vector<char> > & board, string word, int cur, int x, int y){
//        if(board[x][y]!=word[cur]) return false;
//        else if(board[x][y]==word[cur]&&cur==word.size()-1) return true;
//        else{
//            if(x-1>=0&&board[x-1][y]==word[cur+1]) return dfs(board, word, cur+1, x-1, y);
//            if(x+1<board.size()&&board[x+1][y]==word[cur+1]) return dfs(board, word, cur+1, x+1, y);
//            if(y-1>=0&&board[x][y-1]==word[cur+1]) return dfs(board, word, cur+1, x, y-1);
//            if(y+1<board[0].size()&&board[x][y+1]==word[cur+1]) return dfs(board, word, cur+1, x, y+1);
//        }
//        return false;
//   }
//};

class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};

//class Solution{
//public:
//    bool exist(vector<vector<char> >& board, string word){
//        int m = board.size(); int n = board[0].size();
//        vector<vector<bool> > visited(n, vector<bool>(m));
//        for(auto i=0; i<m; i++){
//            for(auto j=0; j<n; j++){
//                if(check(board, visited, word, i, j, 0)) return true;
//            }
//        }
//        return false;
//    }
//
//    bool check(vector<vector<char> >& board, vector<vector<bool> >& visited, string &s, int x, int y, int k){
//        if(board[x][y]!=s[k]) return false;
//        else if(k==s.length()-1) return true;
//        visited[x][y] = true;
//        bool result = false;
//        vector<pair<int, int> > directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//        for(const auto & dir: directions){
//            int newi = x + dir.first;
//            int newj = y + dir.second;
//            if(newi>=0&&newi<board.size()&&newj>=0&&newj<board.size()){
//                if(!visited[newi][newj]){
//                    bool flag = check(board, visited, s, newi, newj, k+1);
//                    if(flag){
//                        result = true;
//                        break;
//                    }
//                }
//            
//        }
//        visited[x][y] = false;
//        return result;
//    }
//};
// @lc code=end

