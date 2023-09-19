//  codedp_8.cpp
//  leetcode
//  正则表达式匹配
//  Created by Qian on 8/1/23.

#include <iostream>
using namespace::std;

/*
 请实现一个函数用来匹配包含'. '和'*'的正则表达式。
 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
 解法：动态规划
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = int(s.size()) + 1, n = int(p.size()) + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for(int j = 2; j < n; j += 2)
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = p[j - 1] == '*' ?
                    (dp[i][j - 2] || dp[i - 1][j]) && (s[i - 1] == p[j - 2] || p[j - 2] == '.'):
                    dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
