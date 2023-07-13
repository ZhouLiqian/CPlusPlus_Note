//  code69.cpp
//  leetcode
//  青蛙跳台阶问题
//  Created by Qian on 7/13/23.

#include <iostream>
using namespace::std;

/*一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法*/

class Solution {
public:
    int numWays(int n) {
        if(n == 0 || n == 1) return 1;
        int a = 1, b = 1, c = 0;
        for(int i = 2; i <= n; i++){
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return c;
    }
};
