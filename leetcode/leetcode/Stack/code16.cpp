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
public:
    //initialize
    CQueue(){}
    
    //insert
    void appendTail(int value) {
        s1.push(value);
    }
    
    //delete
    int deleteHead() {
        int x = -1;
        if(empty(s2)){
            if (s1.size() > 0) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            else{
                return x;
            }
            x = s2.top();
            
            s2.pop();
        }
        else{
            x = s2.top();
            s2.pop();
        }
        return x;
    }
private:
    stack<int> s1;
    stack<int> s2;
};