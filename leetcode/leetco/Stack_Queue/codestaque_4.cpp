//  code19.cpp
//  leetcode
//  队列的最大值
//  Created by Qian on 6/25/23.

#include <iostream>
#include <queue>
#include <deque>
using namespace::std;

/*
 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)
 若队列为空，pop_front 和 max_value 需要返回 -1
*/

class MaxQueue {
public:
    MaxQueue() {}
    
    int max_value() {
        if(max_que.empty())
            return -1;
        return max_que.front();
    }
    
    void push_back(int value) {
        ori_que.push(value);
        while(!max_que.empty() && max_que.back() < value){
            max_que.pop_back();
        }
        max_que.push_back(value);
    }
    
    int pop_front() {
        if(ori_que.empty())
            return -1;
        int value = ori_que.front();
        ori_que.pop();
        if(value == max_que.front())
            max_que.pop_front();
        return value;
    }
private:
    queue<int> ori_que;
    deque<int> max_que;
};
