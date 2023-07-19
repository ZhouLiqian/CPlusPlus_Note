//  code29.cpp
//  leetcode
//  三合一
//  Created by Qian on 6/28/23.

#include <iostream>
#include <vector>
using namespace::std;

/*
 三合一。描述如何只用一个数组来实现三个栈
 实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法
 stackNum表示栈下标，value表示压入的值
 解:二维数组
*/

class TripleInOne {
public:
    //初始化二维数组
    vector<vector<int>> stack = vector<vector<int>> (3, vector<int> (0, 0));
    int maxSize = 0;
    
    //定义各栈尺寸
    TripleInOne(int stackSize) {
        maxSize = stackSize;
    }
    
    //压入元素
    void push(int stackNum, int value) {
        if(stack[stackNum].size() >= maxSize) return;
        else stack[stackNum].push_back(value);
    }
    
    //删除栈顶
    int pop(int stackNum) {
        if(stack[stackNum].empty()) return -1;
        else {
            int temp = stack[stackNum].back();
            stack[stackNum].pop_back();
            return temp;
        }
    }
    
    //栈顶元素
    int peek(int stackNum) {
        if(stack[stackNum].empty()) return -1;
        else {
            return stack[stackNum].back();
        }
    }
    
    //判断空
    bool isEmpty(int stackNum) {
        return stack[stackNum].empty();
    }
};
