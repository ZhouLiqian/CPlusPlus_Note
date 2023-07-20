//  code45.cpp
//  leetcode
//  机器人的运动范围
//  Created by Qian on 7/5/23.

#include <iostream>
using namespace::std;

/*
 地上有一个 m 行 n 列的方格，从坐标 [0,0] 到坐标 [m-1,n-1]
 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格，不能进入行坐标和列坐标的数位之和大于 k 的格子
 例如，当 k 为 18 时，机器人能够进入方格 [35, 37] ，因为 3+5+3+7=18
 但它不能进入方格 [35, 38]，因为 3+5+3+8=19
 请问该机器人能够到达多少个格子
*/

class Solution {
public:
    //计算总点数
    int movingCount(int m, int n, int k) {
        bool *flag = new bool[m*n];
        for(int i = 0; i < m*n; i++){
            flag[i] = false;
        }
        int count = moving(k, m, n, 0, 0, flag);
        return count;
    }
    //各位求和
    int sum(int n){
        int result = 0;
        while (n) {
            result = result + n % 10;
            n = n / 10;
        }
        return result;
    }
    //满足条件的点数量
    int moving(int threshold, int rows, int cols, int m, int n, bool *flag){
        int count = 0;
        if(m >= 0 && m < rows && n >= 0 && n < cols && sum(m) + sum(n) <= threshold && flag[m*cols+n] == false){
            flag[m*cols+n]=true;
            count = 1 + moving(threshold, rows, cols, m-1, n, flag) + moving(threshold, rows, cols, m+1, n, flag)
            + moving(threshold, rows, cols, m, n-1, flag) + moving(threshold, rows, cols, m, n+1, flag);
        }
        return count;
    }
};
