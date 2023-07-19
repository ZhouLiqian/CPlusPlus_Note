//  code59.cpp
//  leetcode
//  不用加减乘除做加法
//  Created by Qian on 7/8/23.

#include <iostream>
using namespace::std;

/*写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号*/

class Solution {
public:
    // &+^
    int add(int a, int b) {
        while (b) {
            //进位
            int carry = a & b;
            //本位
            a = a ^ b;
            b = unsigned(carry) << 1;
        }
        return a;
    }
};
