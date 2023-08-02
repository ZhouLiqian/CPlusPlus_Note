//  code60.cpp
//  leetcode
//  二进制中1的个数
//  Created by Qian on 7/10/23.

#include <iostream>
using namespace::std;

/*编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为'1'的个数 解法：位运算*/

class Solution {
public:
    //循环右移
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if(n & 1) count++;
            n >>= 1;
        }
        return count;
    }
    
    //n&(n-1)
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {n = n & (n - 1); count++;}
        return count;
    }
};
