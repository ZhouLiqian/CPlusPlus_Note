//  codem_4.cpp
//  leetcode
//  剪绳子 II
//  Created by Qian on 8/4/23.

#include <iostream>
using namespace::std;

/*
 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。
 请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
 解法：贪心算法/大数越界
*/

class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        int fin = n % 3;
        if(fin == 0){
            int res = n / 3;
            long value = 1;
            for(int i = 0; i < res; i++){
                value = value * 3 % 1000000007;
            }
            return (int)value;
        }
        else if(fin == 1){
            int res = n / 3;
            long value = 1;
            for(int i = 0; i < res - 1; i++){
                value = value * 3 % 1000000007;
            }
            value = value * 2 % 1000000007;
            value = value * 2 % 1000000007;
            return (int)value;
        }
        else if (fin == 2){
            int res = n / 3;
            long value = 1;
            for(int i = 0; i < res; i++){
                value = value * 3 % 1000000007;
            }
            value = value * 2 % 1000000007;
            return (int)value;
        }
        return 0;
    }
};
