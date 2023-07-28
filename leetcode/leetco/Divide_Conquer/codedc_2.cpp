//  code58.cpp
//  leetcode
//  数值的整数次方
//  Created by Qian on 7/8/23.

#include <iostream>
using namespace::std;

/*实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题 解法：递归/数学*/

class Solution {
public:
    //快速幂-递归
    double result = 1;
    double myPow_1(double x, long n) {
        //终止条件
        if(n == 0) return result;
        //判断正负+奇偶
        if (n < 0) {n = - n; x = 1 / x;}
        if(n & 1) result *= x;
        x *= x;
        n >>= 1;
        return myPow_1(x, n);
    }
    
    //快速幂-循环
    double myPow_2(double x, long n) {
        if (!n) return 1;
        if (n < 0) {
            n = - n;
            x = 1 / x;
        }
        double result = 1;
        while (n) {
            if (n & 1) result *= x;
            x *= x;
            n >>= 1;
        }
        return result;
    }
};
