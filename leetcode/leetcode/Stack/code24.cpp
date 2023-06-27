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
        if(empty(pushed) && empty(popped))
            return true;
        else if (empty(pushed) && !empty(popped))
            return false;
        else if (!empty(pushed) && empty(popped))
            return false;
        else
        {
            stack<int> stack;
            int j = 0;
            for(int i = 0; i < pushed.size(); i++){
                stack.push(pushed[i]);
                while (!empty(stack) && stack.top() == popped[j]) {
                    stack.pop();
                    j++;
                }
            }
            if(stack.empty())
                return true;
            else
                return false;
        }
    }
};
