//  code70.cpp
//  leetcode
//  股票的最大利润
//  Created by Qian on 7/13/23.

#include <iostream>
using namespace::std;

/*假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff = 0;
        if(prices.empty()) return max_diff;
        for(int i = 0; i < prices.size() - 1; i++){//买入
            int max = *max_element(prices.begin() + (i + 1), prices.end());//卖出
            int diff = max - prices[i];
            if(diff > 0 && diff > max_diff)
                max_diff = diff;//利润
            else{
                continue;
            }
        }
        return max_diff;
    }
    
    //动态规划
    int maxProfit_2(vector<int>& prices){
        int max_profit = 0;
        if(prices.empty()) return max_profit;
        int min_price = prices[0];
        for(int num : prices){
            if(num < min_price) min_price = num;
            int diff = num - min_price;
            if(diff > max_profit) max_profit = diff;
        }
        return max_profit;
    }
};
