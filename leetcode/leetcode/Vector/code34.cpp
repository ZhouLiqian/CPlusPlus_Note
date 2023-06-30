//  code34.cpp
//  leetcode
//  0～n-1中缺失的数字
//  Created by Qian on 6/30/23.

#include <iostream>
using namespace::std;

/*
 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内
 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字
 解:二分法
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int multi = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != multi){
                break;
            }
            else{
                multi++;
            }
        }
        return multi;
    }
    int missingNumber_2(vector<int>& nums) {
        int left = 0;
        int right = int(nums.size()) - 1;
        int middle = 0;
        while(left <= right){
            middle = (left + right) / 2;
            if(nums[middle] == middle){
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        return left;
    }
};
