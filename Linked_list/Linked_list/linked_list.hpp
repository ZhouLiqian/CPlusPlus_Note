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
//初始化
Student::Student(string sNo, string sName, double sc) : score(sc){
    stuNo = sNo;
    stuName = sName;
}
//友元函数
istream & operator >> (istream & is, Student & stu){
    cout << "学号: ";
    is >> stu.stuNo;
    cout << "姓名: ";
    is >> stu.stuName;
    cout << "成绩: ";
    is >> stu.score;
    return is;
}
ostream & operator << (ostream & os, const Student & stu){
    os << "学号: " << stu.stuNo << "\t 姓名: " << stu.stuName << "\t 成绩: " << stu.score;
    return os;
}
#endif /* linked_list_hpp */
