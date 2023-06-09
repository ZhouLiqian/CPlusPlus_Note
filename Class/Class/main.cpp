//  main.cpp
//  Class
//  Created by Qian on 6/9/23.

#include <iostream>
#include "class.hpp"

int main() {
    /*Sales_data data1, data2;
    double price = 0;
    //读入数据
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    //输出对象和
    if(data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " " << endl;
        if(totalCnt != 0)
            cout << totalRevenue / totalCnt << endl;
        else
            cout << "(no sales)" << endl;
    }
    else
    {
        //两笔交易的ISBN不一样
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }*/
    Sales_data total;
    if(read(cin, total)){
        Sales_data trans;
        while (read(cin, trans)) {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    return 0;
}
