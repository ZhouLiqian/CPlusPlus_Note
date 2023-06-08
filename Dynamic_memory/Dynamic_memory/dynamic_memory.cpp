//  dynamic_memory.cpp
//  Dynamic_memory
//  Created by Qian on 6/8/23.

#include "dynamic_memory.hpp"

string make_plural(size_t ctr, const string &word, const string &ending){
    return (ctr > 1) ? word + ending : word;
}

//逐行读取文件
TextQuery::TextQuery(ifstream &is) : file(new vector<string>){
    string text;
    while (getline(is, text)) {
        file -> push_back(text);
        // 当前行号
        unsigned long n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

//单词查询方法
QueryResult
TextQuery::query(const string &sought) const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

//打印结果
ostream &print(ostream &os, const QueryResult &qr){
    //cout << qr.lines->size() << endl;
    os << qr.sought << " occurs " << qr.lines->size() << " "
    << make_plural(qr.lines->size(), "time", "s") << endl;
    for(auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}
