/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include "include.h"

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        //补全前导零
        int len = max(a.length(), b.length());
        if(a.length() < len){
            int alen = len-a.length();
            for(int i=0; i<alen; i++){
                a.insert(a.begin(),'0');
            }
        }
        else if(b.length() < len){
            int blen = len-b.length();
            for(int i=0; i < blen; i++){
                b.insert(b.begin(), '0');
            }
        }

        string ret(len, '0');
        char upper  = '0';
        for(int i=len-1; i>=0; i--){
            if(a.at(i)=='0'&&b.at(i)=='0'){
                ret.at(i) = upper;
                upper = '0';
            }
            else if(a.at(i)=='1'&&b.at(i)=='1'){
                if(i==0){//特殊情况
                    ret.at(i) = upper;
                    upper = '0';
                    ret.insert(ret.begin(), '1');
                    return ret;
                }
                else{
                    ret.at(i) = upper;
                    upper = '1';
                }
            }
            else{
                if(upper == '1'){
                    if(i==0){//特殊情况
                        ret.at(i) = '0';
                        ret.insert(ret.begin(), '1');
                        return ret;
                    }
                    else{
                        ret.at(i) = '0';
                        upper = '1';
                    }
                }
                else{
                    ret.at(i) = '1';
                    upper = '0';
                }
            }
        }
        return ret;
    }
};
// @lc code=end

