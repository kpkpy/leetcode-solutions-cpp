/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n==1){return "1";}
        else{
            string last = countAndSay(n-1);
            char flag = last.at(0);
            int times = 1;
            string ret = "";
            for(int i=0; i<last.length()-1; i++){
                if(last.at(i)==last.at(i+1)){
                    times++;
                    continue;
                }
                else{
                    ret += times+'0';
                    ret += flag;
                    times = 1;
                    flag = last.at(i+1);
                }
            }
            ret+=times+'0';
            ret+= flag;
            return ret;
        }
    }
private:
};
// @lc code=end

