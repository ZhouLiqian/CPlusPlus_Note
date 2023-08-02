//  codedp_6.cpp
//  leetcode
//  把数字翻译成字符串
//  Created by Qian on 8/1/23.

#include <iostream>
using namespace::std;

/*
 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”
 一个数字可能有多个翻译，请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法
 解法：动态规划
*/

class Solution {
public:
    int translateNum(int num) {
        string num_str = to_string(num);
        unsigned long size = num_str.size();
        if(size == 0 || size == 1) return 1;
        int a = 1, b = 1, c = 0;
        for(int i = 2; i <= size; i++){
            int value = (num_str[i - 2] - '0') * 10 + (num_str[i - 1] - '0');
            if(9 < value && value < 26 )
                c = a + b;
            else
                c = b;
            a = b;
            b = c;
        }
        return c;
    }
};
