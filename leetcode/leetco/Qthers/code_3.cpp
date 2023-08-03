//  code25.cpp
//  leetcode
//  化栈为队
//  Created by Qian on 6/27/23.

#include <iostream>
#include <stack>
using namespace::std;

/*
 实现一个MyQueue类，该类用两个栈来实现一个队列
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
*/

class MyQueue {
public:
    /* Initialize your data structure here. */
    MyQueue() {

    }
    
    /* Push element x to the back of queue. */
    void push(int x) {
        sta_1.push(x);
    }
    
    /* Removes the element from in front of queue and returns that element. */
    int pop() {
        if(sta_1.empty())
            return NULL;
        else
        {
            while (!sta_1.empty()) {
                sta_2.push(sta_1.top());
                sta_1.pop();
            }
            int top = sta_2.top();
            sta_2.pop();
            while (!sta_2.empty()) {
                sta_1.push(sta_2.top());
                sta_2.pop();
            }
            return top;
        }
    }
    
    /* Get the front element. */
    int peek() {
        if(sta_1.empty())
            return NULL;
        else
        {
            while (sta_1.size() > 1) {
                sta_2.push(sta_1.top());
                sta_1.pop();
            }
            int front = 0;
            if(sta_1.size() == 1)
                front = sta_1.top();
            while (!sta_2.empty()) {
                sta_1.push(sta_2.top());
                sta_2.pop();
            }
            return front;
        }
    }
    
    /* Returns whether the queue is empty. */
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
