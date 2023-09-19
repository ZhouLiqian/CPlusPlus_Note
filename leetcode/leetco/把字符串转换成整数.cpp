//  把字符串转换成整数.cpp
//  leetcode
//  Created by Qian on 9/19/23.

#include <iostream>
using namespace::std;

/*数字越界处理*/

class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        while (str[i] == ' ') i++;
        
        int sym = 1;
        if (str[i] == '+') {sym = 1; i++;}
        else if (str[i] == '-') {sym = -1; i++;}
        else if(str[i] >= '0' && str[i] <= '9') i = i;
        else return 0;
        
        int res = 0;
        while(str[i] >= '0' && str[i] <= '9'){
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > 7)){
                if(sym == 1) return INT_MAX;
                else return INT_MIN;
            }
            res = res * 10 + (str[i] - '0');
            i++;
        }
        return sym * res;
    }
};
