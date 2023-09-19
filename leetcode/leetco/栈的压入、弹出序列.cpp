//  code24.cpp
//  leetcode
//  栈的压入、弹出序列
//  Created by Qian on 6/27/23.

#include <iostream>
#include <stack>
using namespace::std;

/*
 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序
 假设压入栈的所有数字均不相等
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty()) return true;
        if(pushed.empty() || popped.empty()) return false;
        stack<int> sta_vec;
        int index = 0;
        for(int i = 0; i < pushed.size(); i++){
            sta_vec.push(pushed[i]);
            while(!sta_vec.empty() && sta_vec.top() == popped[index]){
                sta_vec.pop();
                index++;
            }
        }
        if(sta_vec.empty())
            return true;
        return false;
    }
};
