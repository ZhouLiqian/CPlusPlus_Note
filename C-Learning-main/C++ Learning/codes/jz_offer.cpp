//  replacespace.cpp
//  C++ Learning
//  Created by Qian on 5/29/23.

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//s = "We are happy."
string replaceSpace(string s) {
    string::size_type pos = 0;
    while (s.find(" ", pos) != std::string::npos) {
        pos = s.find(" ", pos);
        s.replace(pos , 1, "%20");
        ++pos;
    }
    return s;
}

//s = "lrloseumgh", k = 6
string reverseLeftWords(string s, int n) {
    string s1;
    s1 = s.substr(0, n);
    s.erase(0, n);
    s.append(s1);
    return s;
}

//s = "e"
bool isSign(char c){
    return c == '+' || c == '-';
}
bool isInt(char c){
    return c >= '0' && c <= '9';
}
// check integer
bool isInteger(string& word)
{
    int ptr = 0;
    if(isSign(word[ptr]))
        ptr++;
    if(!isInt(word[ptr]))
        return false;
    while(ptr < word.size() && isInt(word[ptr]))
        ptr++;
    if(ptr == word.size())
        return true;
    return false;
}
//check decimal
bool isDecimal(string& word)
{
    int ptr = 0;
    if(isSign(word[ptr]))
        ptr++;
    if(isInt(word[ptr])){
        while(ptr < word.size() && isInt(word[ptr]))
            ptr++;
        if(word[ptr] != '.'){
            return false;
        }
        else{
            ptr++;
            while(ptr < word.size() && isInt(word[ptr]))
                ptr++;
            if(ptr == word.size())
                return true;
            return false;
        }
    }
    else if(word[ptr] == '.'){
        ptr++;
        if(!isInt(word[ptr])){
            return false;
        }
        while(ptr < word.size() && isInt(word[ptr]))
            ptr++;
        if(ptr == word.size())
            return true;
        return false;
    }
    else{
        return false;
    }
}
bool isNumber(string s) {
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ')
            continue;
        cout << "space back." << endl;
        cout << "i: " << i << endl;
        int j = i + 1;
        while(j < s.size() && (isSign(s[j]) || isInt(s[j]) || s[j] == '.'))
            j++;
        int ed = j - 1;
        //第一个单词
        string word = s.substr(i, ed - i + 1);
        // cout << word << endl;
        if(!isInteger(word) && !isDecimal(word))
            return false;
        if(j == s.size())
            return true;

        //处理第一个单词的后缀
        //后缀为空格
        if(s[j] == ' '){
            while(j < s.size()){
                if(s[j] != ' ')
                    return false;
                j++;
            }
        }
        //后缀为e
        else if(s[j] == 'e' || s[j] == 'E'){
            j++;
            i = j;
            while(j < s.size() && (isSign(s[j]) || isInt(s[j]) || s[j] == '.'))
                j++;
            word = s.substr(i, j - 1 - i + 1);
            //e后面的第二个单词，要求整数
            if(!isInteger(word))
                return false;

            if(j == s.size())
                return true;
            while(j < s.size()){
                if(s[j] != ' ')
                    return false;
                j++;
            }
        }
        //其它后缀
        else
            return false;
        return true;
    }
    return false;
}


int main(){
    string ss = {"She is a girl and he is a boy."};
    string new_ss = replaceSpace(ss);
    string sss = {"lrloseumgh"};
    int k = 6;
    string new_sss = reverseLeftWords(sss, k);
    string ssss = {" e"};
    bool new_ssss = isNumber(ssss);
    cout << "new_ssss: " << new_ssss << endl;
    return 0;
}
