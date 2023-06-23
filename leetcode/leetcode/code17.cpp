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
    /* initialize your data structure here */
    MinStack() {}
    
    void push(int x) {
        stack_1.push(x);
    }
    
    void pop() {
        if(!stack_1.empty()){
            stack_1.pop();
        }
        else
            throw "stack empty";
    }
    
    int top() {
        if(!stack_1.empty())
            return stack_1.top();
        else
            return NULL;
    }
    
    int min() {
        vector<int> vector_1;
        int min_value = 0;
        if (stack_1.size() > 0) {
            while (!stack_1.empty()) {
                vector_1.push_back(stack_1.top());
                stack_1.pop();
            }
            min_value = *min_element(vector_1.begin(), vector_1.end());
            reverse(vector_1.begin(), vector_1.end());
            //恢复原栈
            for(int i = 0; i < vector_1.size(); i++){
                stack_1.push(vector_1[i]);
            }
        }
        else
        {
            return NULL;
        }
        return min_value;
    }
private:
    stack<int> stack_1;
};
