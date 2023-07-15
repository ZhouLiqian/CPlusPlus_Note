//  code2.cpp
//  leetcode
//  字符串转换成整数
//  Created by Qian on 6/10/23.

#include <string>
#include <iostream>
using namespace::std;

class Solution {
public:
    //整数
    bool Integer(char c){
        return c >= '0' && c <= '9';
    }
    //字符串转整数
    int strToInt(string str) {
        if(str.empty()) return 0;
        int i = 0;
        while(str[i] == ' ') i++;
        int number = 0;
        if(str[i] == '+'){
            i++;
            while(Integer(str[i])){
                if(number < INT_MAX / 10 || (number == INT_MAX / 10 && (str[i] - '0') <= INT_MAX % 10)){
                    number = number * 10 + (str[i] - '0');
                    i++;
                }
                else{
                    return INT_MAX;
                }
            }
        }
        else if(str[i] == '-'){
            i++;
            while(Integer(str[i])){
                if(number > INT_MIN / 10 || (number == INT_MIN / 10 && - (str[i] - '0') >= INT_MIN % 10)){
                    number = number * 10 - (str[i] - '0');
                    i++;
                }
                else{
                    return INT_MIN;
                }
            }
        }
        else{
            if(Integer(str[i])){
                while(Integer(str[i])){
                    if(number < INT_MAX / 10 || (number == INT_MAX / 10 && (str[i] - '0') <= INT_MAX % 10)){
                        number = number * 10 + (str[i] - '0');
                        i++;
                    }
                    else{
                        return INT_MAX;
                    }
                }
            }
            else{
                return 0;
            }
        }
        return number;
    }
    
    //方法二
    int StrToInt_2(string str) {
        if (str.empty()) {
            return 0;
        }

        const int n = int(str.size());
        const char* cstr = str.c_str();  // 获取字符串的字符数组指针
        int result = 0;
        int sign = 1;
        int i = 0;

        // 跳过无效字符
        while (i < n && (cstr[i] == ' ' || cstr[i] == '\t' || cstr[i] == '\n')) {
            i++;
        }

        // 处理符号位
        if (i < n && (cstr[i] == '-' || cstr[i] == '+')) {
            sign = (cstr[i++] == '-') ? -1 : 1;
        }

        // 预先计算字符到数字的映射
        int* digits = new int[10];  // 数字映射表
        for (int j = 0; j < 10; j++) {
            digits[j] = j;
        }

        // 将字符转换为数字，并累加到结果中
        while (i < n && isdigit(cstr[i])) {
            int digit = digits[cstr[i] - '0'];
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                delete[] digits;
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }

        delete[] digits;
        return sign * result;
    }
};
