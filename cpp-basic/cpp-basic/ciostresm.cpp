//  ciostresm.cpp
//  cpp-basic
//  Created by Qian on 5/31/23.

#include <fstream>
#include <vector>
#include "ciostresm.hpp"
using std::istream;
using std::ostream;


Sales_data::Sales_data(std::istream &is)
{
    // read will read a transaction from is into this object
    readInput(is, *this);
}

double
Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

// add the value of the given Sales_data into this object
Sales_data&
Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ``this'' object
    return *this; // return the object on which the function was called
}

// transactions contain ISBN, number of copies sold, and sales price
istream& readInput(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    //item.revenue = price * item.units_sold;
    item.revenue = price;
    return is;
}

ostream& print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

