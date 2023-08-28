//  删除有序数组中的重复项.cpp
//  leetcode
//  双指针
//  Created by Qian on 8/28/23.

#include <iostream>
using namespace::std;

class Solution {
public:
    //数字出现次数不超过1
    int removeDuplicates_1(vector<int>& nums) {
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            if(right < 1 || nums[right] != nums[left - 1]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
    
    //数字出现次数不超过2
    int removeDuplicates_2(vector<int>& nums) {
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            if(right < 2 || nums[right] != nums[left - 2]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};
