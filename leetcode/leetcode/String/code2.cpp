//  code2.cpp
//  leetcode
//  字符串转换成整数
//  Created by Qian on 6/10/23.

#include <string>
#include <iostream>
using namespace::std;

int strToInt(string str) {
    int i = 0;
    int num = 0;
    int last_num = num;

    //跳过空格
    while (str[i] == ' ') {
        i++;
    }
    //判断第一个非空格符是正号
    if(str[i] == '+')
    {
        i++;
        for(int j = i; j < str.size(); j++)
        {
            if(str[j] >= '0' && str[j] <= '9')
            {
                if((num > INT_MAX / 10) || ((num == INT_MAX / 10) && ((str[j] - '0') > (INT_MAX % 10))))
                {
                    num = INT_MAX;
                    break;
                }
                else
                {
                    last_num = num;
                    num = last_num * 10 + (str[j] - '0');
                }
                /*if((num - (str[j] - '0')) / 10 != last_num)
                {
                    num = INT_MAX;
                    break;
                }*/
            }
            else
            {
                break;
            }
        }
    }
    else if (str[i] == '-')//判断第一个非空格符是负号
    {
        i++;
        for(int k = i; k < str.size(); k++)
        {
            if(str[k] >= '0' && str[k] <= '9')
            {
                if((-num < INT_MIN / 10) || ((-num == INT_MIN / 10) && (-(str[k] - '0') < (INT_MIN % 10))))
                {
                    num = -INT_MIN;
                    break;
                }
                else
                {
                    last_num = num;
                    num = last_num * 10 + (str[k] - '0');
                }
                /*if((num - (str[k] - '0')) / 10 != last_num)
                {
                    num = -INT_MIN;
                    break;
                }*/
            }
            else
            {
                break;
            }
        }
        num = -1 * num;
    }
    else//判断第一个非空格符是数字/其他
    {
        for(int pos = i; pos < str.size(); pos++)
        {
            if(str[pos] >= '0' && str[pos] <= '9')
            {
                if((num > INT_MAX / 10) || ((num == INT_MAX / 10) && ((str[pos] - '0') > (INT_MAX % 10))))
                {
                    num = INT_MAX;
                    break;
                }
                else
                {
                    last_num = num;
                    num = last_num * 10 + (str[pos] - '0');
                }
                /*if((num - (str[pos] - '0')) / 10 != last_num)
                {
                    num = INT_MAX;
                    break;
                }*/
            }
            else
            {
                break;
            }
        }
    }
    return num;
}
