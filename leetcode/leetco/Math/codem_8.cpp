//  codem_8.cpp
//  leetcode
//  数字序列中某一位的数字
//  Created by Qian on 8/4/23.

#include <iostream>
using namespace::std;

/*
 数字以0123456789101112131415…的格式序列化到一个字符序列中。
 在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等
 请写一个函数，求任意第n位对应的数字
 解法：分组求值
*/

class Solution {
public:
    int findNthDigit(int n) {
        int count = 9, digital = 1, start = 1;
        //确定数字所在分组(以数字位数为依据)
        while (n > count) {
            n = n - count;
            start = start * 10;
            digital = digital + 1;
            count = 9 * start * digital;
        }
        //确定数字在分组中的位置
        long long num = start + (n - 1) / 3;
        int idx = (n - 1) % digital + 1;
        string str = to_string(num);
        return str[idx - 1] - '0';
    }
};
