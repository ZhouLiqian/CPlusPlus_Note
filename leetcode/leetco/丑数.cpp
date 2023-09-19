//  codedp_9.cpp
//  leetcode
//  丑数
//  Created by Qian on 8/1/23.

#include <iostream>
using namespace::std;

/*我们把只包含质因子 2、3 和 5 的数称作丑数。求按从小到大的顺序的第 n 个丑数 解法：动态规划*/

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        int dp[n];
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for(int i = 1; i < n; i++){
            dp[i] = min(min(dp[a] * 2, dp[b] * 3), dp[c] * 5);
            if(dp[i] == dp[a] * 2) a++;
            if(dp[i] == dp[b] * 3) b++;
            if(dp[i] == dp[c] * 5) c++;
        }
        return dp[n - 1];
    }
};
