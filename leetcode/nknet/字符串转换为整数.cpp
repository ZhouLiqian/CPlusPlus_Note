//  字符串转换为整数.cpp
//  leetcode
//  字符串
//  Created by Qian on 10/11/23.

#include <iostream>
using namespace::std;

int myAtoi(string s) {
    if(s.empty()) return NULL;
    
    int index = 0;
    while (s[index] == ' ') {
        index++;
    }
    
    int flag = 1;
    if(s[index] == '+'){
        flag = 1;
        index++;
    }
    else if(s[index] == '-'){
        flag = -1;
        index++;
    }
    
    int value = 0;
    while(s[index] >= '0' && s[index] <= '9'){
        if(flag == 1){
            if(value < INT_MAX / 10 || (value == INT_MAX / 10 && (s[index] - '0') < INT_MAX % 10)){
                value = value * 10 + (s[index] - '0');
                index++;
            }
            else
                return INT_MAX;
        }
        
        if(flag == -1){
            if(-1 * value > INT_MIN / 10 || (-1 * value == INT_MIN / 10 && -1 * (s[index] - '0') > INT_MIN % 10)){
                value = value * 10 + (s[index] - '0');
                index++;
            }
            else
                return INT_MIN;
        }
    }
    
    if(flag == 1) return value;
    else return -1 * value;
}
