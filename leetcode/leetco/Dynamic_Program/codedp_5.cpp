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
        if(grid.empty()) return 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 && j == 0) continue;
                else if(i == 0 && j != 0) grid[i][j] += grid[i][j - 1];
                else if(i != 0 && j == 0) grid[i][j] += grid[i - 1][j];
                else grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
