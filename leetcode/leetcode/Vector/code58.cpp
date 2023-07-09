//  code58.cpp
//  leetcode
//  数值的整数次方
//  Created by Qian on 7/8/23.

#include <iostream>
using namespace::std;

/*实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题*/

class Solution {
public:
    double myPow(double x, int n) {
        if(!x) return 0;
        double multiple = 1;
        if(n < 0){
            int m = -n;
            int i = 1;
            while (i <= m) {
                multiple = multiple * x;
                i++;
            }
            multiple =  1 / multiple;
        }
        else{
            int i = 1;
            while (i <= n) {
                multiple = multiple * x;
                i++;
            }
        }
        return multiple;
    }
    
    double myPow_2(double x, long n) {
        if (!n) return 1;
        if (n < 0) {
            n = -n;
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
