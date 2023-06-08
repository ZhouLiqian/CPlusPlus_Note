//  dynamic_memory.hpp
//  Dynamic_memory
//  Created by Qian on 6/8/23.

#ifndef dynamic_memory_hpp
#define dynamic_memory_hpp
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace::std;

/*用于定义query返回类型*/
class QueryResult;
/*保存输入文件*/
class TextQuery{
public:
    using line_no = vector<string>::size_type;
    //
    TextQuery(ifstream&);
    //
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

/*保存查询结果*/
class QueryResult{
    friend ostream& print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :
    sought(s), lines(p), file(f) {}
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

string make_plural(size_t ctr, const string &word, const string &ending);
#endif
/* dynamic_memory_hpp */
