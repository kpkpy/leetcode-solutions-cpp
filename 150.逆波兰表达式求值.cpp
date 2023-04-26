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
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                long long num1 = stk.top(); stk.pop();
                long long num2 = stk.top(); stk.pop();
                if(tokens[i]=="+") stk.push(num2+num1);
                else if(tokens[i]=="-") stk.push(num2-num1);
                else if(tokens[i]=="*") stk.push(num2*num1);
                else if(tokens[i]=="/") stk.push(num2/num1);
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
// @lc code=end

