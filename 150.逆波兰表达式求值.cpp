/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include "include.h"
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk; 
        long long num1, num2;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+"
            || tokens[i]=="-"
            || tokens[i]=="*"
            || tokens[i]=="/"
            ){
                num1 = stk.top();
                stk.pop();
                num2 = stk.top();
                stk.pop();
                if(tokens[i]=="+") stk.push(num2+num1);
                if(tokens[i]=="-") stk.push(num2-num1);
                if(tokens[i]=="*") stk.push(num2*num1);
                if(tokens[i]=="/") stk.push(num2/num1);
            }
            else {
                stk.push(stoll(tokens[i]));
            }
        }
        return stk.top();
    }
};
// @lc code=end

