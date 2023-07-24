//  code20.cpp
//  leetcode
//  用队列实现栈
//  Created by Qian on 6/26/23.

#include <iostream>
#include <queue>
using namespace::std;

/*请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）*/
/*
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
*/

class MyStack {
public:
    MyStack() {}

    void push(int x) {
        qu_1.push(x);
    }

    int pop() {
        //cout << qu_1.size() <<endl;
        if(qu_1.empty())
            return NULL;
        while (qu_1.size() > 1) {
            qu_2.push(qu_1.front());
            qu_1.pop();
        }
        int element_pop = 0;
        if(qu_1.size() == 1){
            element_pop = qu_1.front();
            qu_1.pop();
        }
        //恢复原队列
        while (!qu_2.empty()) {
            qu_1.push(qu_2.front());
            qu_2.pop();
        }
        cout <<qu_1.size() << endl;
        return element_pop;
    }

    int top() {
        if(qu_1.empty())
            return NULL;
        return qu_1.back();
    }

    bool empty() {
        if (qu_1.empty() && qu_2.empty()) {
            return true;
        }
        else{
            return false;
        }
    }
private:
    queue<int> qu_1;
    queue<int> qu_2;
};

