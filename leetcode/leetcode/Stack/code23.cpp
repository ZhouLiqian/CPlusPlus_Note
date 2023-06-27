//  code23.cpp
//  leetcode
//  栈排序
//  Created by Qian on 6/27/23.

#include <iostream>
#include <stack>
#include <queue>
using namespace::std;

/*
 栈排序
 编写程序，对栈进行排序使最小元素位于栈顶
 最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中
 该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
*/

/*方法一
class SortedStack {
public:
    SortedStack() {
        
    }
    void push(int val) {
        if(sta.empty())
        {
            sta.push(val);
        }
        else
        {
            //给定值大于栈顶元素
            int top_value = sta.top();
            while(val > top_value && !sta.empty())
            {
                save_sta.push(top_value);
                sta.pop();
                top_value = sta.top();
            }
            //给定值小于等于栈顶元素
            sta.push(val);
            while (!save_sta.empty()) {
                int top_element = save_sta.top();
                sta.push(top_element);
                save_sta.pop();
            }
        }
    }
    
    void pop() {
        if(!sta.empty())
            sta.pop();
    }
    
    int peek() {
        if(!sta.empty())
            return sta.top();
        else
            return -1;
    }
    
    bool isEmpty() {
        if(sta.empty() && save_sta.empty())
            return true;
        else
            return false;
    }
private:
    stack<int> sta;
    stack<int> save_sta;
};
*/

//方法二
class SortedStack{
public:
    SortedStack(){}
    void push(int val){
        min_que.push(val);
    }
    void pop(){
        if(!min_que.empty())
            min_que.pop();
    }
    int peek(){
        if(!min_que.empty())
            return min_que.top();
        else
            return -1;
    }
    bool isEmpty(){
        if(min_que.empty())
            return true;
        else
            return false;
    }
private:
    priority_queue<int, vector<int>, greater<int>> min_que;
};

int main(){
    SortedStack *obj = new SortedStack();
    obj->push(1);
    obj->push(2);
    int top = obj->peek();
    cout << top << endl; //1
    obj->pop();
    top = obj->peek();
    cout << top << endl; //2
    return 0;
}
