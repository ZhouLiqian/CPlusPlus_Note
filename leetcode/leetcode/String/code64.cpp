//  code64.cpp
//  leetcode
//  把数组排成最小的数
//  Created by Qian on 7/11/23.

#include <iostream>
#include <vector>
#include <string>
using namespace::std;

/*输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个*/

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str_vec;
        for(int num : nums){
            str_vec.push_back(to_string(num));
        }
        sort(str_vec.begin(), str_vec.end(), [](string x, string y){return x+y < y+x;});
        string res;
        for(string str : str_vec){
            res.append(str);
        }
        return res;
    }
};
