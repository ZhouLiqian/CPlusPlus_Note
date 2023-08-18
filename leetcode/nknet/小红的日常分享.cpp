//  小红的日常分享.cpp
//  leetcode
//  动态规划
//  Created by Qian on 8/18/23.

#include <iostream>
using namespace::std;

int maxHappiness(int N, int T, int H, vector<int>& time, vector<int>& energy, vector<int>& hapiness){
    /*
     状态：可选事件，花费时间，消耗精力
     选择：选不选当前事件
    */
    int dp[N + 1][T + 1][H + 1];
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= T; j++)
            for(int k = 0; k <= H; k++)
                dp[i][j][k] = 0;
    //做选择
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= T; j++){
            for(int k = 1; k <= H; k++){
                //处理边界索引
                if(j < time[i - 1] || k < energy[i - 1])
                    dp[i][j][k] = dp[i - 1][j][k];
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - time[i - 1]][k - energy[i - 1]] + hapiness[i - 1]);
            }
        }
    }
    return dp[N][T][H];
}
