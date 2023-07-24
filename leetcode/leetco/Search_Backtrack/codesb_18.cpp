//  code55.cpp
//  leetcode
//  字符串的排列
//  Created by Qian on 7/7/23.

#include <iostream>
#include <set>
using namespace::std;

/*输入一个字符串，打印出该字符串中字符的所有排列 解法：回溯算法*/

class Solution {
public:
    //方法一：回溯
    vector<string> str_vec;
    void backtrack(string s, int index){
        if(index == s.size() - 1){
            str_vec.push_back(s);
            return;
        }
        set<int> st;
        for(int i = index; i < s.size(); i++){
            if(st.find(s[i]) != st.end())
                continue;
            st.insert(s[i]);
            swap(s[i], s[index]);
            backtrack(s, index + 1);
            swap(s[index], s[i]);
        }
    }
    vector<string> permutation(string s) {
        if(s.empty()) return {};
        backtrack(s, 0);
        return str_vec;
    }
    
    //方法二：内置函数
    vector<string> permutation_2(string s){
        stable_sort(s.begin(), s.end());
        vector<string> vec_str = {s};
        while (next_permutation(s.begin(), s.end())) {
            vec_str.push_back(s);
        }
        return vec_str;
    }
};
