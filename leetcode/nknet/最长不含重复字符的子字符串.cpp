//  最长不含重复字符的子字符串.cpp
//  leetcode
//  DP
//  Created by Qian on 8/23/23.

#include <iostream>
#include <unordered_map>
using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //状态
        int len[s.size() + 1];
        unordered_map<char, int> ma;
        //初始化
        for(int i = 0; i <= s.size(); i++)
            len[i] = 0;
        //做选择
        int temp = 0;
        for(int i = 1; i <= s.size(); i++){
            if(ma.count(s[i-1]) == 0)
                temp = temp + 1;
            else{
                temp = min(temp + 1, i - 1 - ma[s[i - 1]]);
                
            }
            ma[s[i - 1]] = i - 1;
            len[i] = max(len[i - 1], temp);
        }
        return len[s.size()];
    }
};
