//  code17.cpp
//  leetcode
//  包含min函数的栈
//  Created by Qian on 6/23/23.

#include <iostream>
#include <stack>
#include <vector>
using namespace::std;

/*
 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)
  * Your MinStack object will be instantiated and called as such:
  * MinStack* obj = new MinStack();
  * obj->push(x);
  * obj->pop();
  * int param_3 = obj->top();
  * int param_4 = obj->min();
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        //数据栈
        ori_data.push(x);
        //最小值栈
        if(min_data.empty())
            min_data.push(x);
        else{
           if(x <= min_data.top())
                min_data.push(x);
            else
                min_data.push(min_data.top());
        }
    }
    
    void pop() {
        if(!ori_data.empty())
            ori_data.pop();
        if(!min_data.empty())
            min_data.pop();
    }
    
    int top() {
        if(!ori_data.empty())
            return ori_data.top();
        else
            return NULL;
    }
    
    int min() {
        return min_data.top();
    }
private:
    stack<int> ori_data;
    stack<int> min_data;
};
