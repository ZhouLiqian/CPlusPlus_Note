//  判断数组无重复.cpp
//  leetcode
//  哈希表
//  Created by Qian on 10/25/23.

#include <iostream>
using namespace::std;

/*给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false */
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[i - 1])
            count++;
        else
            count = 1;

        if(count >= 2) return true;
    }
    return false;
}

/*给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true；否则，返回 false */
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    for(int i = 0; i < nums.size(); i++){
        if(dict.count(nums[i]) > 0 && abs(i - dict[nums[i]]) <= k)
            return true;
        dict[nums[i]] = i;
    }
    return false;
}
