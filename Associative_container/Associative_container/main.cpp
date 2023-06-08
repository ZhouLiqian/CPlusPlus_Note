//  main.cpp
//  Associative_container
//  Created by Qian on 6/7/23.

#include <set>
#include "associative_container.hpp"

int main() {
    map<string, size_t> word_count;
    string word;
    set<string> exclude = {"to", "as", "such", "of", "from"};
    /*while (cin >> word) {
        for(auto &c : word){
            c = tolower(c);
            if(ispunct(c))
                word.erase(remove(word.begin(), word.end(), c), word.end());
        }
        ++ word_count[word];
    }*/
    /*while (cin >> word) {
        auto ret = word_count.insert({word, 1});
        if(!ret.second)
            ++ ret.first->second;
    }
    for(const auto &w : word_count){
        if(exclude.find(w.first) == exclude.end()){
            cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " times") << endl;
        }
    }*/
    
    ifstream file1("map_life.txt", std::ifstream::in);
    ifstream file2("input.txt", std::ifstream::in);
    auto trans_map = buildMap(file1);
    string text;
    //读取行
    while (getline(file2, text)) {
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
    file1.close();
    file2.close();
    
    return 0;
}
