//  code26.cpp
//  leetcode
//  栈的最小值
//  Created by Qian on 6/27/23.

#include <iostream>
#include <stack>
using namespace::std;

/*
 请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值
 执行push、pop和min操作的时间复杂度必须为O(1)
  * Your MinStack object will be instantiated and called as such:
  * MinStack* obj = new MinStack();
  * obj->push(x);
  * obj->pop();
  * int param_3 = obj->top();
  * int param_4 = obj->getMin();
*/

//方法一-数组
class MinStack_1{
public:
    MinStack_1(){}
    
    void push(int x) {
        stack.push(x);
    }
    
    void pop() {
        if(!stack.empty())
            stack.pop();
    }
    
    int top() {
        if(!stack.empty())
            return stack.top();
        else
            return NULL;
    }
    
    int getMin() {
        if(stack.empty())
            return NULL;
        else
        {
            vector<int> vector_1;
            while (!stack.empty()) {
                vector_1.push_back(stack.top());
                //cout << stack.top() << endl;
                stack.pop();
            }
            int min = *min_element(vector_1.begin(), vector_1.end());
            reverse(vector_1.begin(), vector_1.end());
            vector<int>::iterator iter;
            for(iter = vector_1.begin(); iter != vector_1.end(); iter++){
                stack.push(*iter);
            }
            return min;
        }
    }
private:
    stack<int> stack;
};

//方法二-维护两个栈
class MinStack_2{
public:
    MinStack_2(){}
    
    void push(int x){
        if(sta.empty() && min.empty())
        {
            min.push(x);
            sta.push(x);
        }
        else
        {
            sta.push(x);
            min.push(std::min(min.top(), x));
        }
    }
    
    void pop(){
        if(!sta.empty() && !min.empty()){
            sta.pop();
            min.pop();
        }
    }
    
    int top(){
        if(!sta.empty()){
            return sta.top();
        }
        else
        {
            return NULL;
        }
    }
    
    int getMin(){
        if(!min.empty()){
            return min.top();
        }
        else
        {
            return NULL;
        }
    }
private:
    stack<int> sta;
    stack<int> min;
};
