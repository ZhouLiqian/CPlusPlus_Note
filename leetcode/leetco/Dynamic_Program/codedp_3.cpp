//  code70.cpp
//  leetcode
//  股票的最大利润
//  Created by Qian on 7/13/23.

#include <iostream>
using namespace::std;

/*假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？解法：动态规划*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
         状态：股票时间
         选择：是否选择当前股票
        */
        if(prices.empty()) return 0;
        unsigned long N = prices.size();
        //初始化
        int dp[N + 1];
        for(int k = 0; k <= N; k++) dp[k] = 0;
        int min_price = prices[0];
        //做选择
        for(int i = 1; i <= N; i++){
            min_price = min(min_price, prices[i - 1]);
            dp[i] = max(dp[i - 1], prices[i - 1] - min_price);
        }
        return dp[N];
    }
};
