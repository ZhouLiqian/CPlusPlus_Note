//  ciostresm.hpp
//  cpp-basic
//  Created by Qian on 5/31/23.

#ifndef ciostresm_hpp
#define ciostresm_hpp

#include <iostream>
#include <string>


class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &readInput(std::istream&, Sales_data&);
public:
    // constructors
    Sales_data(): units_sold(0), revenue(0.0) { }
    Sales_data(const std::string &s):
               bookNo(s), units_sold(0), revenue(0.0) { }
    Sales_data(const std::string &s, unsigned n, double p):
               bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);

    // operations on Sales_data objects
    std::string isbn() const {
        return bookNo;
    }
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
std::istream &readInput(std::istream&, Sales_data&);

// used in future chapters
inline
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

#endif /* ciostresm_hpp */
