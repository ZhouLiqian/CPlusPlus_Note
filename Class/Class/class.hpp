//  class.hpp
//  Class
//  Created by Qian on 6/9/23.

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <istream>
#include <string>
#include <iostream>
using namespace std;

class Sales_data {
//友元可访问非公有成员
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
    
public:
    // constructors
    Sales_data(): units_sold(0), revenue(0.0) { }
    Sales_data(const std::string &s):
               bookNo(s), units_sold(0), revenue(0.0) { }
    Sales_data(const std::string &s, unsigned n, double p):
               bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);

    // operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

class Screen{
public:
    typedef string::size_type pos;
    //构造函数
    Screen() = default;
    //隐式使用类内初始值
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const {return contents[cursor];}
    //内联函数
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    //可变数据成员
    mutable size_t access_ctr;
};

class Window_mgr
{
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

class Account
{
public:
    void calculate(){amount += amount * interestRate;}
    //静态成员变量
    static double rate(){return interestRate;}
    static void rate(double);
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
    //静态成员初始化
    static constexpr int period = 30;
    double daily_tbl[period];
};

class Example{
public:
    static constexpr double profit = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(const int vecSize);
};
#endif
