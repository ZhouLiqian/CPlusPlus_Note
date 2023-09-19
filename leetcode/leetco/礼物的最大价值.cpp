//  codedp_5.cpp
//  leetcode
//  礼物的最大价值
//  Created by Qian on 7/31/23.

#include <iostream>
using namespace std;

/*
 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。
 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 解法：动态规划
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        /*
         状态：棋盘的行，列
         选择：上方的礼物/左侧的礼物
        */
        if(grid.empty()) return 0;
        //初始化
        unsigned long row = grid.size(), col = grid[0].size();
        int dp[row + 1][col + 1];
        for(int i = 0; i <= row; i++)
            for(int j = 0; j <= col; j++)
                dp[i][j] = 0;
        //做选择
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                if(i == 1 && j == 1) dp[i][j] = grid[i - 1][j - 1];
                else if(i == 1 && j != 1) dp[i][j] = grid[i - 1][j - 1] + dp[i][j - 1];
                else if(i != 1 && j == 1) dp[i][j] = grid[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[row][col];
    }
};
