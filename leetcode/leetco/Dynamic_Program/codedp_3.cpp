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
        if(prices.empty()) return 0;
        int min_price = prices[0];
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            min_price = min(min_price, prices[i]);
            profit = max(profit, prices[i] - min_price);
        }
        return profit;
    }
};
