//  code34.cpp
//  leetcode
//  0～n-1中缺失的数字
//  Created by Qian on 6/30/23.

#include <iostream>
using namespace::std;

/*
 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内
 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字
 解法:二分法/遍历
*/

class Solution {
public:
    //遍历
    int missingNumber_1(vector<int>& nums) {
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
    
    //二分法
    int missingNumber_2(vector<int>& nums) {
        int left = 0, right = int(nums.size()) - 1;
        if(nums[0] != 0) return 0;
        if(nums[right] == right) return int(nums.size());
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == mid){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};
