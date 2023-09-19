//  和为k的子数组.cpp
//  leetcode
//  前缀和
//  Created by Qian on 9/4/23.

#include <iostream>
using namespace::std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for(auto& x : nums){
            pre += x;
            if(mp.find(pre - k) != mp.end()){
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};
