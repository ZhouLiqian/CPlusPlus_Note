//  code1.cpp
//  leetcode
//  判断括号成偶
//  Created by Qian on 5/22/23.

#include <iostream>
#include <string>
#define HEAD stack[stack.size() - 1]
using namespace std;

bool isValid(string s) {
    vector<char>stack;
    for(int i = 0;i < s.size();i++){
        if (stack.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
            return false;
        }
        if(s[i] == '('){
            stack.push_back('(');
        }
        else if(s[i] == '['){
            stack.push_back('[');
        }
        else if(s[i] == '{'){
            stack.push_back('{');
        }
        else if(s[i] == ')'){
            if (HEAD == '('){
                stack.pop_back();
            }else{
                return false;
            }
        }
        else if(s[i] == ']'){
            if (HEAD == '['){
                stack.pop_back();
            }else{
                return false;
            }
        }
        else if(s[i] == '}'){
            if (HEAD == '{'){
                stack.pop_back();
            }else{
                return false;
            }
        }
    }
    return stack.empty();
}
