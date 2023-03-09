/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include "include.h"

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        p(digits, digits.size()-1);
        return digits;
    }

    void p(vector<int>& digits, int pos){
        if(digits[pos]>=0&digits[pos]<9){
            digits[pos] ++;
            return;
        }
        else{
            digits[pos] = 0;
            if(pos==0){
                digits.insert(digits.begin(), 0);
                p(digits, pos);
            }
            else p(digits, pos-1);
        }
    }
};
// @lc code=end

