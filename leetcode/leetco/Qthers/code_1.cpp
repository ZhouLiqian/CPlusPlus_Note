//  code21.cpp
//  leetcode
//  用栈实现队列
//  Created by Qian on 6/26/23.

#include <iostream>
#include <stack>
using namespace::std;

/*请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）*/
/*
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
*/
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        sta_1.push(x);
    }
    
    int pop() {
        if(sta_1.empty()) {
            return NULL;
        }
        while (!sta_1.empty()) {
            sta_2.push(sta_1.top());
            sta_1.pop();
        }
        int element = 0;
        if(!sta_2.empty()){
            element = sta_2.top();
            sta_2.pop();
        }
        else{
            return NULL;
        }
        //恢复原栈
        while (!sta_2.empty()) {
            sta_1.push(sta_2.top());
            sta_2.pop();
        }
        return element;
    }
    
    int peek() {
        if(sta_1.empty()) {
            return NULL;
        }
        while (!sta_1.empty()) {
            sta_2.push(sta_1.top());
            sta_1.pop();
        }
        int element = 0;
        if(!sta_2.empty()){
            element = sta_2.top();
        }
        //恢复原栈
        while (!sta_2.empty()) {
            sta_1.push(sta_2.top());
            sta_2.pop();
        }
        return element;
    }
    
    bool empty() {
        if(sta_1.empty() && sta_2.empty())
            return true;
        else
            return false;
    }
private:
    stack<int> sta_1;
    stack<int> sta_2;
};
