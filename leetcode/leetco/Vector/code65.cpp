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
*/

class Solution {
public:
    //参考
    bool isStraight(vector<int>& nums) {//找出这个序列里最大的数字和最小的数字
        int arr[14] = {0};
        int i,min=14,max=0,num0=0,gap=0;//注意min得赋初值大于13，不然会有问题；max同理
        for (i = 0; i < 5; i++) {
            if (nums[i] != 0 && arr[nums[i]])//除了0以外不能有重复的数字
                return false;
            arr[nums[i]] = 1;
            if (nums[i] == 0)
                num0++;
            else {
                if(arr[nums[i]])
                min = min < nums[i] ? min : nums[i];
                max = max > nums[i] ? max : nums[i];
            }
        }
        for (i = min; i <= max; i++)
            if (!arr[i])
                gap++;
        if (gap <= num0)//这个序列min到max直接空着的数字个数要小于等于大小王的个数
            return true;
        return false;
    }
    //自学
    bool isStraight_2(vector<int>& nums){
        set<int> arr;
        int min = 14, max = 0;
        int zero = 0, diff = 0;
        for(int i = 0; i < nums.size(); i++){
            //重复性
            if(nums[i] != 0 && arr.count(nums[i])) return false;
            arr.insert(nums[i]);
            if(nums[i] == 0)
                zero++;
            else{
                if(nums[i] < min)
                    min = nums[i];
                if(nums[i] > max)
                    max = nums[i];
            }
        }
        for(int j = min; j <= max; j++){
            if(!arr.count(j))
                diff++;
        }
        if(diff <= zero) return true;
        return false;
    }
};
