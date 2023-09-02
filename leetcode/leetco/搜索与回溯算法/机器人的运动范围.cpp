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
 解法：回溯算法
*/

class Solution {
public:
//回溯法
    int res = 0;
    vector<vector<bool>> visited;
    //求和
    bool check(int i, int j, int k){
        int sum = 0;
        while(i){
            sum += i % 10;
            i /= 10;
        }
        while(j){
            sum += j % 10;
            j /= 10;
        }
        if(sum > k) return false;
        return true;
    }
    //回溯
    void backtrack(int i, int j, int m, int n, int k){
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j])
            return;
        //选择
        visited[i][j] = true;
        res++;
        //回溯
        if(check(i + 1, j, k)) backtrack(i + 1, j, m, n, k);
        if(check(i, j + 1, k)) backtrack(i, j + 1, m, n, k);
        return;
    }
    int movingCount(int m, int n, int k) {
        visited.resize(m, vector<bool>(n, false));
        backtrack(0, 0, m, n, k);
        return res;
    }
};
