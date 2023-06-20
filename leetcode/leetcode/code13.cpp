//  code13.cpp
//  leetcode
//  调整数组顺序使奇数位于偶数前面
//  Created by Qian on 6/20/23.

#include <iostream>
#include <vector>
using namespace::std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        vector<int> new_nums;
        int i, j;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] % 2 != 0){
                new_nums.push_back(nums[i]);
            }
        }
        for(j = 0; j < nums.size(); j++){
            if(nums[j] % 2 == 0){
                new_nums.push_back(nums[j]);
            }
        }
        nums = new_nums;
        return nums;
    }
};
