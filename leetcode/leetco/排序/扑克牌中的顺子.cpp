//  code65.cpp
//  leetcode
//  扑克牌中的顺子
//  Created by Qian on 7/11/23.

#include <iostream>
#include <set>
using namespace::std;

/*
 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。
 A 不能视为 14
 解法：快速排序/哈希表
*/

class Solution {
public:
    //哈希表+遍历
    bool isStraight_1(vector<int>& nums) {
        set<int> num_set;
        int max = 0, min = 14;
        for(int i = 0; i < nums.size(); i++){
            //判断重复+大小王
            if(nums[i] == 0) continue;
            if(num_set.count(nums[i])) return false;
            //最值
            max = nums[i] > max ? nums[i] : max;
            min = nums[i] < min ? nums[i] : min;
            num_set.insert(nums[i]);
        }
        if(max - min < 5) return true;
        return false;
    }
    
    //排序+遍历
    bool isStraight_2(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int max = 0, min = 14;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) continue;
            if(i + 1 < nums.size() && nums[i] == nums[i + 1]) return false;
            //最值
            max = nums[i] > max ? nums[i] : max;
            min = nums[i] < min ? nums[i] : min;
        }
        if(max - min < 5) return true;
        return false;
    }
};
