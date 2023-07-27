//  code67.cpp
//  leetcode
//  数据流中的中位数
//  Created by Qian on 7/12/23.

#include <iostream>
#include <queue>
using namespace::std;

/*
 如何得到一个数据流中的中位数？
 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值
 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
*/

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> max_que;
    priority_queue<int, vector<int>, less<int>> min_que;
    
    /* initialize your data structure here. */
    MedianFinder() {
        
    }
    //维护两个优先队列
    void addNum(int num) {
        if(min_que.empty() || num <= min_que.top()){//中位数所在
            min_que.push(num);
            if(max_que.size() + 1 < min_que.size()){
                max_que.push(min_que.top());
                min_que.pop();
            }
        }
        else{
            max_que.push(num);
            if(max_que.size() > min_que.size()){
                min_que.push(max_que.top());
                max_que.pop();
            }
        }
    }
    //计算中位数
    double findMedian() {
        if(min_que.size() > max_que.size()){
            return min_que.top();
        }
        else{
            return (min_que.top() + max_que.top()) / 2.0;
        }
    }
};
