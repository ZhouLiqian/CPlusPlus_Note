//  code71.cpp
//  leetcode
//  连续子数组的最大和
//  Created by Qian on 7/13/23.

#include <iostream>
using namespace::std;

/*输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值 解法：分治/动态规划*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            nums[i] = (nums[i-1] > 0 ? nums[i]+nums[i-1] : nums[i]);
            res = max(res,nums[i]);
        }
        return res;
    }
};
