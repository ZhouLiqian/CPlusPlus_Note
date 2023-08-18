//  leetcode
//  背包问题
//  Created by Qian on 8/11/23.

#include <iostream>
using namespace::std;

//使用动态规划求解0-1背包问题
int knapsack(int num, int capacity, int weight[], int values[]){
    int space, sub_cap, total_value[num + 1][capacity + 1];
    //初始化
    for(int i = 0; i <= num; i++)
        for(int j = 0; j <= capacity; j++)
            total_value[i][j] = 0;
    //做选择
    for(sub_cap = 1; sub_cap <= capacity; sub_cap++){
        for(space = 1; space <= num; space++){
            if(sub_cap >= weight[space - 1])
                total_value[space][sub_cap] = max(total_value[space - 1][sub_cap], total_value[space - 1][sub_cap - weight[space - 1]] + values[space - 1]);
            else
                total_value[space][sub_cap] = total_value[space - 1][sub_cap];
        }
    }
    return total_value[num][capacity];
}
