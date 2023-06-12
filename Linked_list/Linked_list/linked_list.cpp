//  linked_list.cpp
//  Linked_list
//  Created by Qian on 6/12/23.

#include "linked_list.hpp"

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
