/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include "include.h"

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int total = l1+l2;
        if(total%2==1){
            return findKthElementm(nums1, nums2, total/2+1);
        }
        else{
            return((
            double(findKthElementm(nums1, nums2, total+1)) + 
            double(findKthElementm(nums1, nums2, total+2)))
            /2);
        }
    }

    int findKthElementm(vector<int>& arr1, vector<int>& arr2, int k){
        if(arr1.size()==0){
            return arr2.back();
        }
        if(arr2.size()==0){
            return arr1.back();
        }
        if(k==1){
            return min(arr1[0], arr2[0]);
        }
        int i = min(int(arr1.size()), k/2)-1;
        int j = min(int(arr2.size()), k/2)-1;
        if(arr1[i]>arr2[j]){
            arr2.assign(arr2.begin()+j+1, arr2.end());
            return findKthElementm(arr1, arr2, k-j-1);
        }
        else{//arr2[k/2] > arr1[k/2]
            arr1.assign(arr1.begin()+i+1, arr1.end());
            return findKthElementm(arr1, arr2, k-i-1);
        }
    }
};
// @lc code=end

