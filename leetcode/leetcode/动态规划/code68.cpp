//  code68.cpp
//  leetcode
//  斐波那契数列
//  Created by Qian on 7/12/23.

#include <iostream>
using namespace::std;

/*写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）*/

class Solution {
public:
    int fib(int n) {
        int a = 0, b = 0;
        int c = 1;
        if(n == 0)
            c = 0;
        else if(n == 1)
            c = 1;
        else{
            int i = 2;
            while(i <= n){
                a = b;
                b = c;
                c = (a + b) % 1000000007;
                i++;
            }
        }
        return c;
    }
};
