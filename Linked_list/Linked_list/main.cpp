//  main.cpp
//  Linked_list
//  Created by Qian on 6/12/23.

#include <iostream>
#include "linked_list.hpp"
#include "LinkList.hpp"

int main() {
    // insert code here...
    LinkList<Student> stuList;
    Student x;
    string s,t;
    cout << "插入3个学生信息: " << endl;
    for(int i = 1; i <= 3; i++){
        s.clear();
        t = char(48 + i);
        s.append("第").append(t).append("个学生");
        cout << s << endl;
        cin >> x;
        stuList.Insert(i, x);
        cout << stuList << endl;
    }
    cout << stuList << endl;
    return 0;
}
