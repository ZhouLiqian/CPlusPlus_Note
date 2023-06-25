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
    
    //structure
    MaxQueue() {
    }
    
    // get maxvalue
    int max_value() {
        if(empty(deq)){
            return -1;
        }
        int max = 0;
        vector<int> deq_vector;
        while (!deq.empty()) {
            deq_vector.push_back(deq.front());
            deq.pop_front();
        }
        max = *max_element(deq_vector.begin(), deq_vector.end());
        //恢复原队列
        for(int i = 0; i < deq_vector.size(); i++){
            deq.push_back(deq_vector[i]);
        }
        return max;
    }
    
    //insert element
    void push_back(int value) {
        deq.push_back(value);
    }
    
    //return deleted front
    int pop_front() {
        if(deq.empty()){
            return -1;
        }
        int front_delete = deq.front();
        deq.pop_front();
        return front_delete;
    }
    
private:
    deque<int> deq;
};
