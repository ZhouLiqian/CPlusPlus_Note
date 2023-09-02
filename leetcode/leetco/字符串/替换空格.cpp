//  code0.cpp
//  leetcode
//  替换空格
//  Created by Qian on 7/14/23.

#include <iostream>
using namespace::std;

/*请实现一个函数，把字符串 s 中的每个空格替换成"%20"*/

class Solution {
public:
    string replaceSpace(string s) {
        size_t found = s.find_first_of(" ");
        while (found != string::npos) {
            s.replace(found, 1, "%20");
            found = s.find_first_of(" ", found+1);
        }
        return s;
    }
};
