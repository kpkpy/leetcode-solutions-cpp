/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // cs(n)= cs(n-1) + cs(n-2);
        if(n==1) return 1;
        if(n==2) return 2;
        else{
// 需优化
//            return climbStairs(n-1) + climbStairs(n-2);
            int tmp;
            int a = 1; int b = 2;
            for(int i = 2; i<n; i++){
                tmp = a+b;
                a = b;
                b = tmp;
            }
            return tmp;
        }
    }

//    int climbStairs_abondonded(int n) {
//        int nWays = 0;
//        dfs(n, nWays);
//        return nWays;
//    }

//    void dfs(int n, int & ret){
//        if(n==0){
//            ret ++;
//            return;
//        }
//        else if(n==1){
//            n-=1;
//            dfs(n, ret);
//            n+=1;
//        }
//        else{
//            n-=1;
//            dfs(n, ret);
//            n+=1;
//            ///////
//            n-=2;
//            dfs(n, ret);
//            n+=2;
//        }
//        return;
//    }
};
// @lc code=end

