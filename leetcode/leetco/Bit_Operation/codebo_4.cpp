//  codebo_4.cpp
//  leetcode
//  数组中数字出现的次数 II
//  Created by Qian on 8/2/23.

#include <iostream>
using namespace::std;

/*在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字 解法：位运算*/

class Solution {
public:
    //哈希表
    int singleNumber_1(vector<int>& nums) {
        unordered_map<int,short> _map;
        for(int f : nums) {
            _map[f]++;

        }
        for(auto [k,v] : _map) {
            if(v==1) return k;
        }
        return -1;
    }
    
    //位运算
    int singleNumber_2(vector<int>& nums) {
        vector<int> binary(32, 0);
        // 统计所有数的二进制表示中各个比特位上 1 的总个数
        for (auto num : nums) {
            for (int i = 0; i < 32; i++) {
                binary[i] += num & 1;
                num >>= 1;
            }
        }
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            res <<= 1;
            res |= binary[i] % 3;
        }
        return res;
    }
};
