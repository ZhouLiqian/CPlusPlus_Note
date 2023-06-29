//  code30.cpp
//  leetcode
//  无法吃午餐的学生数量
//  Created by Qian on 6/29/23.

#include <iostream>
#include <stack>
#include <queue>
using namespace::std;

/*
 学校的自助午餐提供圆形和方形的三明治，分别用数字 0 和 1 表示
 所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的
 餐厅里三明治的数量与学生的数量相同
 
 所有三明治都放在一个栈里，每一轮：如果队列最前面的学生喜欢栈顶的三明治，那么会拿走它并离开队列
 否则，这名学生会放弃这个三明治并回到队列的尾部, 这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止

 给你两个整数数组 students 和 sandwiches
 其中 sandwiches[i] 是栈里面第 i​​​​​​ 个三明治的类型（i = 0 是栈的顶部）
 students[j] 是初始队列里第 j​​​​​​ 名学生对三明治的喜好（j = 0 是队列的最开始位置）
 请你返回无法吃午餐的学生数量
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;//记录连续未吃到午餐的学生数量
        for(int i = 0; i < students.size(); i++){
            student_queue.push(students[i]);
        }
        reverse(sandwiches.begin(), sandwiches.end());
        for(int j = 0; j < sandwiches.size(); j++){
            sandwiche_stack.push(sandwiches[j]);
        }
        while (1) {
            if(!sandwiche_stack.empty() && !student_queue.empty() && sandwiche_stack.top() == student_queue.front()){
                sandwiche_stack.pop();
                student_queue.pop();
                count = 0;
            }
            if(!student_queue.empty() && sandwiche_stack.top() != student_queue.front()){
                student_queue.push(student_queue.front());
                student_queue.pop();
                count += 1;
            }
            if(student_queue.empty() || count >= student_queue.size())
                break;
        }
        return int(student_queue.size());
    }
private:
    stack<int> sandwiche_stack;
    queue<int> student_queue;
};
