//  code32.cpp
//  leetcode
//  数组中重复的数字
//  Created by Qian on 6/29/23.

#include <iostream>
#include <unordered_set>
using namespace::std;

/*
 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内
 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次
 请找出数组中任意一个重复的数字
 解法:哈希表
*/

class Solution{
public:
    int findRepeatNumber(vector<int>& nums){
        unordered_set<int> unique_set;
        for(int num : nums){
            if(unique_set.count(num) > 0){
                return num;
            }
            unique_set.insert(num);
        }
        return -1;
    }
};
