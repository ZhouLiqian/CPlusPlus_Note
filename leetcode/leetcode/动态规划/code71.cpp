//  code71.cpp
//  leetcode
//  连续子数组的最大和
//  Created by Qian on 7/13/23.

#include <iostream>
using namespace::std;

/*输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(max > 0) {
                max += nums[i];
                nums[i] = max;
            }
            else max = nums[i];
        }
        return *max_element(nums.begin(), nums.end());
    }
};
