//  leetcode
//  进制转换
//  Created by Qian on 7/19/23.

#include <iostream>
using namespace std;

/*写出一个程序，接受一个十六进制的数，输出该数值的十进制表示*/

string ChangNum(string s){
    s = s.substr(2);
    int chage_num = 0;
    for(char data : s){
        int value = 0;
        switch(data){
            case '1':
                value = 1;
                break;
            case '2':
                value = 2;
                break;
            case '3':
                value = 3;
                break;
            case '4':
                value = 4;
                break;
            case '5':
                value = 5;
                break;
            case '6':
                value = 6;
                break;
            case '7':
                value = 7;
                break;
            case '8':
                value = 8;
                break;
            case '9':
                value = 9;
                break;
            case 'A':
                value = 10;
                break;
            case 'B':
                value = 11;
                break;
            case 'C':
                value = 12;
                break;
            case 'D':
                value = 13;
                break;
            case 'E':
                value = 14;
                break;
            case 'F':
                value = 15;
                break;
        }
        chage_num = chage_num * 16 + value;
    }
    string result = to_string(chage_num);
    return result;
}
