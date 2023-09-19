//  codem_2.cpp
//  leetcode
//  构建乘积数组
//  Created by Qian on 8/3/23.

#include <iostream>
using namespace::std;

/*
 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
 其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
 不能使用除法
 解法：表格分区
*/

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //left记录该数字左边所有数乘积
        //right记录该数字右边所有数乘积
        int left=1,rigth=1;
        unsigned long n = a.size();
        vector<int> ans(n,1);

        for(int i=0;i<n;i++){
            //此次循环乘了左边乘积，同时对称的右半部乘了右边的连乘积
            //在循环到达n-x-1=i时该数乘了右边的连乘积，得到除自身以外的元素积
            ans[i]*=left;
            ans[n-i-1]*=rigth;

            left*=a[i];
            rigth*=a[n-i-1];
        }
        return ans;
    }
};
