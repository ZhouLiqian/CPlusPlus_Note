//  code55.cpp
//  leetcode
//  字符串的排列
//  Created by Qian on 7/7/23.

#include <iostream>
#include <set>
using namespace::std;

/*输入一个字符串，打印出该字符串中字符的所有排列*/

class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
    void dfs(string s, int x){
        if(x == s.size() - 1){
            res.push_back(s);
            return;
        }
        set<int> st;
        for(int i = x; i < s.size(); i++){
            if(st.find(s[i]) != st.end()) continue;
            st.insert(s[i]);
            swap(s[i], s[x]);
            dfs(s, x+1);
            swap(s[i], s[x]);
        }
    }
};
