/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ret;
        vector<int> fingerprint(26, 0);
        vector<int> fingerprintzero(26, 0);
        vector<string> strsets;
        string s; bool isInsert = false;

        if(strs.size()==0){
            ret.push_back(strs);
            return ret;
        }

        //main loop
        while(strs.size()!=0){
            s = strs[strs.size()-1];
            isInsert = false;
            strs.pop_back();
            for(int i=0; i<ret.size()&&isInsert==false; i++){
                strsets = ret[i];
                if(strsets[0].length()==s.length()){
                    //记录 已有的字符集的 fingerprint 数组
                    for(int i=0; i<strsets[0].length(); i++){
                        fingerprint[strsets[0].at(i)-'a'] ++;
                    }

                    for(int i=0; i<s.length(); i++){
                        fingerprint[s.at(i)-'a'] --;
                    }

                    if(fingerprint == fingerprintzero){
                        isInsert = true;
                        ret[i].push_back(s);
                    }
                    else{
                        fingerprint = fingerprintzero;
                        continue;
                    }
                }
                else continue;
            }
            //如果循环完 一圈 还没有插入, 则新建一条;
            if(isInsert==false){
                strsets.clear();
                strsets.push_back(s);
                ret.push_back(strsets);
            }
        }
        return ret;
    }
};
// @lc code=end

