//  code37.cpp
//  leetcode
//  第一个只出现一次的字符
//  Created by Qian on 7/1/23.

#include <iostream>
#include <unordered_set>
using namespace::std;

/*在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。s 只包含小写字母 解法：哈希表*/

class Solution {
public:
    char firstUniqChar(string s) {
        if(s.empty())
            return char(' ');
        for(char a : s){
            size_t first = s.find_first_of(a);
            size_t end = s.find_last_of(a);
            if(first == end)
                return a;
        }
        return char(' ');
    }
};
