//  code14.cpp
//  leetcode
//  和为s的两个数字
//  Created by Qian on 6/20/23.

#include <iostream>
using namespace::std;

/*输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可*/

class Solution {
public:
    //方法一
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int> new_nums;
        for(i = 0; i < nums.size() - 1; i++){
            for(j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    new_nums.push_back(nums[i]);
                    new_nums.push_back(nums[j]);
                    return new_nums;
                }
            }
        }
        return new_nums;
    }
    
    //方法二(双指针)
    vector<int> twoSum_2(vector<int>& nums, int target) {
        int i = 0;
        unsigned long j = nums.size() - 1;
        while (i < j) {
            if(nums[i] + nums[j] == target){
                return vector<int> {nums[i], nums[j]};
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }else{
                j--;
            }
        }
        return vector<int> {0,0};
    }
};

