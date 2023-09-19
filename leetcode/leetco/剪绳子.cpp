//  codem_3.cpp
//  leetcode
//  剪绳子
//  Created by Qian on 8/3/23.

#include <iostream>
using namespace::std;

/*
 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
 请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
 解法：贪心算法
*/

class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        int fin = n % 3;
        if(fin == 0){
            int res = n / 3;
            return pow(3, res);
        }
        else if(fin == 1){
            int res = n / 3;
            return 4 * pow(3, res - 1);
        }
        else if (fin == 2){
            int res = n / 3;
            return 2 * pow(3, res);
        }
        return 0;
    }
};
