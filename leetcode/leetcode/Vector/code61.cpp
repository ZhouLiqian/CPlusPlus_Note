//  code61.cpp
//  leetcode
//  数组中出现次数超过一半的数字
//  Created by Qian on 7/10/23.

#include <iostream>
#include <set>
using namespace::std;

/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字*/

class Solution {
public:
    //哈希表
    int majorityElement(vector<int>& nums) {
        multiset<int> set;
        int number = 0;
        for(int element : nums){
            set.insert(element);
            if(set.count(element) > (nums.size()/ 2)){
                number = element;
                break;
            }
        }
        return number;
    }
    
    //众数
    int majorityElement_2(vector<int>& nums){
        sort(nums.begin(), nums.end());
        return nums[nums.size()/ 2];
    }
    
    //摩尔投票
    int majorityElement_3(vector<int>& nums) {
        int x = 0, votes = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        return x;
    }
};
