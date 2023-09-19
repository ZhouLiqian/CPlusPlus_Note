//  code73.cpp
//  leetcode
//  表示数值的字符串
//  Created by Qian on 7/14/23.

#include <iostream>
using namespace::std;

/*请实现一个函数用来判断字符串是否表示数值（包括整数和小数）*/

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        //跳过若干空格
        while (s[i] == ' ') {
            i++;
        }
        size_t found_E = s.find_first_of('E');
        size_t found_e = s.find_first_of('e');
        size_t found = 0;
        if(found_E == string::npos && found_e != string::npos)
            found = found_e;
        else if (found_E != string::npos && found_e == string::npos)
            found = found_E;
        else if (found_E != string::npos && found_e != string::npos)
            return false;
        else{
            size_t space = s.find_first_of(' ', i);
            string middle;
            if(space != string::npos){
                int p = i;
                for(; p < space; p++){
                    middle.push_back(s[p]);
                }
                while (p < s.size()) {
                    if(s[p] != ' ') return false;
                    p++;
                }
            }
            else{
                for(int p = i; p < s.size(); p++){
                    middle.push_back(s[p]);
                }
            }
            if(DecimalNumber(middle) || IntegerNumber(middle))
                return true;
        }
        //存在大小e
        string front;
        for(int j = i; j < found; j++){
            front.push_back(s[j]);
        }
        if(DecimalNumber(front) || IntegerNumber(front)){
            size_t end_index = s.find_first_of(' ', found);
            string end;
            if(end_index != string::npos){
                int k = int(found) + 1;
                for(; k < end_index; k++){
                    end.push_back(s[k]);
                }
                while (k < s.size()) {
                    if(s[k] != ' ') return false;
                    k++;
                }
            }
            else{
                for(int k = int(found) + 1; k < s.size(); k++){
                    end.push_back(s[k]);
                }
            }
            if(IntegerNumber(end))
                return true;
        }
        return false;
    }
    
    //数字
    bool number(char c){
        return c >= '0' && c <= '9';
    }
    
    //小数
    bool DecimalNumber(string s){
        int j = 0;
        int flag = 0;
        //跳过符号位
        if(s[j] == '+' || s[j] == '-') j++;
        if(number(s[j])){//至少一位数字
            j++;
            while (number(s[j])) {
                j++;
            }
            if(s[j] == '.' && j == s.size() - 1)
                return true;
            else if (s[j] == '.' && j < s.size() - 1){
                j++;
                for(int k = j; k < s.size(); k++){
                    if(number(s[k]))
                        flag = 1;
                    else{
                        flag = 0;
                        break;
                    }
                }
            }
            else{
                return false;
            }
        }
        else if (s[j] == '.'){//一个点
            j++;
            for(int k = j; k < s.size(); k++){
                if(number(s[k]))
                    flag = 1;
                else{
                    flag = 0;
                    break;
                }
            }
        }
        //判断
        if(flag == 1)
            return true;
        else
            return false;
    }
    
    //整数
    bool IntegerNumber(string s){
        int j = 0;
        int flag = 0;
        //跳过符号位
        if(s[j] == '+' || s[j] == '-') j++;
        for(int p = j; p < s.size(); p++){
            if(number(s[p]))
                flag = 1;
            else{
                flag = 0;
                break;
            }
        }
        //判断
        if(flag == 1)
            return true;
        else
            return false;
    }
};
