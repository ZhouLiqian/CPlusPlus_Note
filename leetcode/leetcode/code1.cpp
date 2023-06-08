//
//  code1.cpp
//  leetcode
//
//  Created by Qian on 5/22/23.
//

#include <iostream>
#include <string>
#define HEAD stack[stack.size() - 1]
using namespace std;


//bool isValid(string s)
//{
//    if (s.length()%2 != 0)
//    {
//        return false;
//    }
//    else
//    {
//        int i;
//        int flag = 1;
//
//        while (true) {
//            string s2 = "";
//            flag = 1;
//            for (i = 0; i<s.length();)
//            {
//                if ((s[i] == '(' && s[i+1] == ')') || (s[i] == '{' && s[i+1] == '}') || (s[i] == '[' && s[i+1] == ']'))
//                {
//                    flag = 0;
//                    i += 2;
//                } else {
//                    s2 += s[i];
//                    i += 1;
//                }
//            }
//
//            if ((flag == 1) && (s2.length() == 0)) {
//                return true;
//                break;
//            } else if ((flag == 1) && (s2.length() != 0)) {
//                return false;
//            }
//            s = s2;
//        }
//        return true;
//    }
//
//}

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

int main()
{
    bool result;
    result = isValid("{}[]}}");
    cout<<result<<endl;
    
}
