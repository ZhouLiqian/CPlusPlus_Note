//  code16.cpp
//  leetcode
//  用两个栈实现队列
//  Created by Qian on 6/23/23.

#include <iostream>
#include <stack>
using namespace::std;

/*
 用两个栈实现一个队列
 请实现它的两个函数 appendTail 和 deleteHead 分别完成在队列尾部插入整数和在队列头部删除整数的功能
 (若队列中没有元素，deleteHead 操作返回 -1)
*/

class CQueue {
private:
    stack<int> inStack, outStack;

    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    CQueue() {}

    void appendTail(int value) {
        inStack.push(value);
    }

    int deleteHead() {
        if (outStack.empty()) {
            if (inStack.empty()) {
                return -1;
            }
            in2out();
        }
        int value = outStack.top();
        outStack.pop();
        return value;
    }
};
