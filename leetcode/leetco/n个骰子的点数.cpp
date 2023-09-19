//  codedp_10.cpp
//  leetcode
//  n个骰子的点数
//  Created by Qian on 8/1/23.

#include <iostream>
using namespace::std;

/*把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率 解法：动态规划*/

class Solution {
public:
    vector<double> dicesProbability(int n) {
        if(n == 0) return {};
        //i = 1
        vector<double> dp(6, 1.0/6.0);
        for(int i = 2; i <= n; i++){
            vector<double> temp(i*5+1, 0);
            for(int j = 0; j < dp.size(); j++){
                for(int k = 0; k < 6; k++){
                    //独立事件 P(AB) = P(A) * P(B)
                    temp[j + k] += dp[j] * 1.0/6.0;
                }
            }
            dp = temp;
        }
        return dp;
    }
};
