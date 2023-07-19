//  leetcode
//  明明的随机数
//  Created by Qian on 7/19/23.

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 明明生成了N个1到500之间的随机整数。
 请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，
 然后再把这些数从小到大排序，按照排好的顺序输出
 考点：unique - 删除相邻重复元素
*/

vector<int> DelSame(vector<int> dat_vec){
    vector<int> new_vec;
    for(int data : dat_vec){
        new_vec.push_back(data);
    }
    sort(new_vec.begin(), new_vec.end());
    auto end_iter = unique(new_vec.begin(), new_vec.end());
    new_vec.erase(end_iter, new_vec.end());
    return new_vec;
}
