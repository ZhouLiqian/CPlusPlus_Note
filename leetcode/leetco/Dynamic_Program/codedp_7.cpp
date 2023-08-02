//  codedp_7.cpp
//  leetcode
//  最长不含重复字符的子字符串
//  Created by Qian on 8/1/23.

#include <iostream>
#include <unordered_map>
using namespace::std;

/*请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度 解法：动态规划/双指针*/

class Solution {
public:
    //动态规划
    int lengthOfLongestSubstring_1(string s) {
        if(s.empty()) return 0;
        unordered_map<char, int> s_set;
        int len = 0, temp = 0;
        for(int i = 0; i < s.size(); i++){
            if(s_set.count(s[i]) == 0) temp += 1;
            else temp = min(temp + 1, i - s_set[s[i]]);
            s_set[s[i]] = i;
            len = max(temp, len);
        }
        return len;
    }
    
    //双指针
    int lengthOfLongestSubstring_2(string s) {
        int ret = 0;
        unordered_map<int,int> hash;
        for (int i=0,j=0;i<s.size();++i)
        {
            hash[s[i]]++;
            while (hash[s[i]] > 1) {hash[s[j]]--; j++;}
            ret = max(ret, i - j + 1);
        }
        return ret;
    }
    
    //自方法
    int lengthOfLongestSubstring_3(string s){
        if(s.empty()) return 0;
        unordered_map<char, int> hash_map;
        int len = 0, temp = 0;
        for(int i = 0; i < s.size(); i++){
            if(hash_map.count(s[i]) == 0) temp++;
            else temp = min(temp + 1, i - hash_map[s[i]]);
            hash_map[s[i]] = i;
            len = max(len, temp);
        }
        return len;
    }
};
