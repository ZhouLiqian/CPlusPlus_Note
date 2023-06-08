//  Container.cpp
//  C++ Learning
//  Created by Qian on 5/26/23.

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <deque>
using namespace std;

class Time_class{

public:
    
    unsigned year, month, day;
    
    Time_class(string time_str) {
        this->time = time_str;
    }
    
    void type_time(){
        if(this->time.find(",") != std::string::npos){
            convert_1(this->time);
        }else if(this->time.find("/") != std::string::npos){
            convert_2(this->time);
        }else{
            convert_3(this->time);
        }
    }
    
private:
    string time;
    
    void convert_1(string &time1){
        // January 1,1900
        day = stoi(time1.substr(time1.find_first_of("123456789"), time1.find(",")-time1.find_first_of(" ")-1));
        string new_time_1 = time1.substr(0, time1.find_first_of(" "));
        month = convert_month(new_time_1);
        year = stoi(time1.substr(time1.find_first_of(",")+1, 4));
    }
    void convert_2(string &time2){
        // 1/1/1990
        day = stoi(time2.substr(time2.find_first_of("123456789"), time2.find_first_of("/")-time2.find_first_of("123456789")));
        month = stoi(time2.substr(time2.find_first_of("/")+1, time2.find_last_of("/")-time2.find_first_of("/")-1));
        year = stoi(time2.substr(time2.find_last_of("/")+1, 4));
    }
    void convert_3(string &time3){
        // Jan 1 1900
        string new_month_3 = time3.substr(0, time3.find_first_of(" "));
        month = convert_month(new_month_3);
        day = stoi(time3.substr(time3.find_first_of(" ")+1, time3.find_first_of(" ")-time3.find_first_of(" ")-1));
        year = stoi(time3.substr(time3.find_last_of(" ")+1, 4));
    }
    unsigned convert_month(string &s){
        if(s.find("Jan") < s.size()) month = 1;
        if(s.find("Feb") < s.size()) month = 2;
        if(s.find("Mar") < s.size()) month = 3;
        if(s.find("Apr") < s.size()) month = 4;
        if(s.find("May") < s.size()) month = 5;
        if(s.find("Jun") < s.size()) month = 6;
        if(s.find("Jul") < s.size()) month = 7;
        if(s.find("Aug") < s.size()) month = 8;
        if(s.find("Sep") < s.size()) month = 9;
        if(s.find("Oct") < s.size()) month = 10;
        if(s.find("Nov") < s.size()) month = 11;
        if(s.find("Dec") < s.size()) month = 12;
        return month;
    }
};

int main()
{
    /*time_class*/
    string time_str = "Feb 4 2023";
    Time_class time = Time_class(time_str);
    time.type_time();
    cout << "year = " << time.year << " month = " << time.month << " day = " << time.day << endl;

    /*define iterator*/
    list<int> gqlist{12,45,8,6};
    list<int>::iterator iter;
    for(iter = gqlist.begin(); iter != gqlist.end(); iter++)
    {
        cout << *iter << endl;
    }
    /*index*/
    string str = {'a','b','c'};
    string::size_type index = 1;
    cout << str[index] << endl;

    /*initialize vector*/
    vector<const char*> v1 = {"She", "is", "a", "girl"};
    vector<const char*> v2(v1);
    vector<const char*> v3 = v1;
    vector<char> v4(4, 'A');
    vector<string> v5(v1.begin(), v1.end());
    vector<char> v6 = {'S','i','a','g'};
    cout << v5[1] << endl;
    vector<int> l1 = {1,2,3,4,5,6,7};
    vector<double> d1(l1.begin(), l1.end());
    cout << "new vector d1[3]: " << d1[3] << endl;

    /*assignment*/
    vector<string> v7{"She" "is" "a" "girl"};
    list<const char*> l2 = {"abc", "ABC", "def", "DEF"};
    v7.assign(l2.begin(), l2.end());
    cout << "new vector v7[1]: " << v7[1] << endl;
    list<const char*> l3 = {"She" "is" "a" "girl"};
    swap(l2, l3);
    list<const char*>::iterator c;
    for(c = l3.begin(); c != l3.end(); c++)
    {
        cout << "changed vector: " << *c << endl;
    }

    /*insert data*/
    string str1;
    list<string> de1;
    list<string>::iterator i;
    int index1 = 0;
    while(index1 < 3)
    {
        if(getline(cin, str1))
        {
            de1.push_back(str1);
        }
        index1 += 1;
    }
    for(i = de1.begin(); i != de1.end(); i++)
    {
        cout << *i << endl;
    }

    /*copy*/
    list<int> new_list = {1,2,3,4,5,6,7,8,9};
    list<int>::iterator new_list_iter;
    deque<int> new_deque_1;
    deque<int> new_deque_2;
    for(new_list_iter = new_list.begin(); new_list_iter != new_list.end(); new_list_iter++)
    {
        if(*new_list_iter % 2 == 0)
        {
            new_deque_1.insert(new_deque_1.begin(), *new_list_iter);
            //cout << "*new_list_iter: " << *new_list_iter << endl;
            //new_deque_1.push_back(*new_list_iter);
        }
        else
        {
            new_deque_2.insert(new_deque_2.begin(), *new_list_iter);
            //cout << "*new_list_iter: " << *new_list_iter << endl;
            //new_deque_2.push_back(*new_list_iter);
        }
    }

    cout << "even queue: " << new_deque_1[0] << "," << new_deque_1[1] << ","
         << new_deque_1[2] << "," << new_deque_1[3] << endl;
    cout << "odd queue: " << new_deque_2[0] << "," << new_deque_2[1] << ","
         << new_deque_2[2] << "," << new_deque_2[3] << "," << new_deque_2[4] << endl;

    /*access element*/
    vector<int> one_element = {2};
    if(!empty(one_element)){
        auto val = *one_element.begin();
        auto last = one_element.end();
        auto val3 = *(--last);
        auto val2 = one_element.front();
        auto val4 = one_element.back();
        cout << "val: " << val << "," << "val3: " << val3 << endl;
        cout << "val2: " << val2 << "," << "val4: " << val4 << endl;
    }

    /*clear element*/
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> empty_vector;
    list<int> empty_list;
    for(int i = 0; i < (sizeof(ia)/sizeof(*ia)); i++){
        empty_vector.push_back(ia[i]);
        empty_list.push_back(ia[i]);
    }
    vector<int>::iterator empty_iter;
    for(empty_iter = empty_vector.begin(); empty_iter != empty_vector.end(); empty_iter++){
        if(*empty_iter % 2 == 0){
            empty_iter = empty_vector.erase(empty_iter);
        }
    }
    cout << "empty_vector: " << empty_vector.back() << endl;
    auto empty_iter1 = empty_list.begin();
    while(empty_iter1 != empty_list.end()){
        if(*empty_iter1 % 2){
            empty_iter1 = empty_list.erase(empty_iter1);
        }else{
            ++empty_iter1;
        }
    }
    cout << "empty_list: " << empty_list.back() << endl;

    /*string*/
    vector<char> char_vector = {'a','b','c','d','e'};
    string new_string;
    /*
    vector<char>::iterator char_iter;
    for(char_iter = char_vector.begin(); char_iter != char_vector.end(); char_iter++){
        new_string.push_back(*char_iter);

    }
    */
    //new_string.assign(char_vector.begin(), char_vector.end());
    new_string.append(char_vector.begin(), char_vector.end());
    cout << "new_string: " << new_string << endl;

    /*find*/
    string::size_type pos = 0;
    string::size_type pos1 = 0;
    string first_string = {"ab2c3d7R4E6"};
    pos = first_string.find_first_of('E', pos);
    cout << "pos: " << pos << endl;
    pos1 = first_string.find_first_not_of("ab2c3d7R46", pos1);
    cout << "pos1: " << pos1 << endl;

    /*time_class*/
    return 0;
}
