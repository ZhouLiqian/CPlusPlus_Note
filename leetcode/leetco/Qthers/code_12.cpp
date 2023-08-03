//  code28.cpp
//  leetcode
//  分割等和子集
//  Created by Qian on 6/28/23.

#include <iostream>
using namespace::std;

/*给定一个非空的正整数数组 nums ，请判断能否将这些数字分成元素和相等的两部分*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0)
            return false;
        sum = sum / 2;
        //动态规划
        vector<vector<bool>> f(nums.size() + 1, vector<bool>(sum + 1, false));
        f[0][0] = true;
        for(int j = 1; j <= nums.size(); j++){
            for(int k = 1; k <= sum; k++){
                if(k >= nums[j - 1]){
                    f[j][k] = f[j - 1][k - nums[j - 1]] | f[j - 1][k];
                }
                else{
                    f[j][k] = f[j - 1][k];
                }
            }
        }
        return f[nums.size()][sum];
    }
};
