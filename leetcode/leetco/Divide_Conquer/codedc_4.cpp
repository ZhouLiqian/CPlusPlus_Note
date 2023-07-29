//  code57.cpp
//  leetcode
//  打印从1到最大的n位数
//  Created by Qian on 7/8/23.

#include <iostream>
#include <cmath>
#include <string>
using namespace::std;

/*输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999 解法：数学*/

class Solution {
public:
    //暴力
    vector<int> printNumbers_1(int n) {
        vector<int> n_vec;
        for(int i = 1; i < pow(10, n); i++){
            n_vec.push_back(i);
        }
        return n_vec;
    }
    
    //大数问题
    vector<int> res;
    string s;
    void savenum(){
        int p = 0;
        while(s[p] == '0' && p < s.size()) p++;
        if(p < s.size()) res.push_back(stoi(s.substr(p)));

    }
    void dfs(int& n,int index){
        if(index == n){
           savenum();
           return;
        }
        for(int i = 0;i < 10;i++){
           s[index] = '0' + i;
           dfs(n,index+1);
        }
    }
    vector<int> printNumbers(int n) {
        s.resize(n,'0');
        dfs(n,0);
        return res;
    }
};
