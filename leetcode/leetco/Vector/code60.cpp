//  code60.cpp
//  leetcode
//  二进制中1的个数
//  Created by Qian on 7/10/23.

#include <iostream>
using namespace::std;

/*编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量)*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if(n & 1)
                count++;
            n >>= 1;
        }
        return count;
    }
};
