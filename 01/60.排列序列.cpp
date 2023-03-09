/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<bool> flag(n+1, false);
        string s;
        int tm = k;
        dfs(res, flag, s, n, tm);
        return res;
    }

    void dfs(string & ret,vector<bool> & flag, string perms , int n , int & k){
        if(perms.length()==n){
            ret = perms;
            k--;
            return; 
        }
        if(k>0){
            for(int i=1; i<n+1; i++){
                if(flag[i]==true) continue;
                perms.push_back(i+'0');
                flag[i]= true;
                dfs(ret, flag, perms, n, k);
                perms.pop_back();
                flag[i] = false;
            }
        }
        return ;
    }
};
// @lc code=end

