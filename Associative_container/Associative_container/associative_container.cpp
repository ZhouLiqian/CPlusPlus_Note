//  associative_container.cpp
//  Associative_container
//  Created by Qian on 6/7/23.

#include "associative_container.hpp"

/*转换规则存入map*/
map<string, string> buildMap(ifstream &map_file){
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
        if(value.size() > 1){
            trans_map[key] = value.substr(1);
        }
        else{
            throw runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

/*转换文本*/
const string &transform(const string &s, const map<string, string> &m){
    auto map_it = m.find(s);
    if(map_it != m.end())
        return map_it -> second;
    else
        return s;
}

/*转换输出*/
void word_transform(ifstream &map_life, ifstream &input){
    auto trans_map = buildMap(map_life);
    string text;
    //读取行
    while (getline(input, text)) {
        //读取单词
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if(firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}
