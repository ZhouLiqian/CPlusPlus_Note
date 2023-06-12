//  linked_list.hpp
//  Linked_list
//  Created by Qian on 6/12/23.

#ifndef linked_list_hpp
#define linked_list_hpp
#include <iostream>
#include <string>
using namespace::std;
class Student{
    friend istream & operator >> (istream &, Student &);
    friend ostream & operator << (ostream &, const Student &);
public:
    //初始化
    Student(string = "", string = "", double = 0.0);
    //重载运算符
    bool operator != (Student & s){
        return this -> stuNo != s.stuNo;
    }
    friend bool operator > (Student & s1, Student & s2){
        return s1.stuNo > s2.stuNo;
    }
private:
    string stuNo;
    string stuName;
    double score;
};
#endif /* linked_list_hpp */
