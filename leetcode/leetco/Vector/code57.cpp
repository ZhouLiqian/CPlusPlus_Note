//  code57.cpp
//  leetcode
//  打印从1到最大的n位数
//  Created by Qian on 7/8/23.

#include <iostream>
#include <cmath>
using namespace::std;

/*输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999*/

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> vector_numbers;
        int number = 1;
        while (number < pow(10, n)) {
            vector_numbers.push_back(number);
            number += 1;
        }
        return vector_numbers;
    }
};
