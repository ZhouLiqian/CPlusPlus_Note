//  main.cpp
//  cpp-basic
//  Created by Qian on 5/31/23.

#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <fstream>
#include "ciostresm.hpp"
using namespace::std;


// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool LT(const string &s1, const string &s2)
{
    return s1 < s2;
}

void printStr(const string &s) {
    cout << s << " ";
}

void print(const vector<string> &words)
{
    for_each(words.begin(), words.end(), printStr);
    cout << endl;
}

bool compareISBN(const Sales_data &isbn1, const Sales_data &isbn2)
{
    return isbn1.isbn() < isbn2.isbn();
}

bool isOverfive(const string &s)
{
    return s.size() >= 5;
}

void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    //print(words);
    auto end_pos = unique(words.begin(), words.end());
    words.erase(end_pos, words.end());
    //print(words);
}

void biggies(vector<string> &word, vector<string>::size_type sz){
    elimDups(word);
    stable_sort(word.begin(), word.end(), [](const string &s1, const string &s2){return s1.size()<s2.size();});
    //print(word);
    auto wc = find_if(word.begin(), word.end(), [sz](const string &a){return a.size()>=sz;});
    //auto count = word.end() - wc;
    //cout << count << " " << sz << endl;
    //for_each(wc, word.end(), [](const string &s){cout << s << endl;});
}

int main(){
    //read-only algorithm
    vector<int> int_list = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,7,8,9,5,4,5,6,7,8};
//    auto times = count(int_list.begin(), int_list.end(), 8);
//    int sum = accumulate(int_list.begin(), int_list.end(), 0);
    vector<double> v = {1.0,2.1,3.3,4.2};
//    double new_sum = accumulate(v.begin(), v.end(), 0.0);
    const char *temp1[] = {"hello", "so long"};
    const char *temp2[] = {"hello", "so long", "tata"};
    //cout << "sizeof(temp1): " << sizeof(temp1) << endl;
    //cout << "sizeof(*temp1): " << sizeof(*temp1) << endl;
    list<const char *> roster1(temp1, temp1 + sizeof(temp1)/sizeof(*temp1));
    vector<const char *> roster2(begin(temp2), end(temp2));
//    bool b = equal(roster1.begin(), roster1.end(), roster2.begin());
    //cout << "roster2: " << roster2.size() << endl;
    
    //write algorithm
    vector<int> lst = {1,2,3,4,5,6,7,8};
    vector<int> vec = {0,0,0,0,0,0,0,0};
    copy(lst.begin(), lst.end(), vec.begin());
    vector<int> vec2 = {0,0,0,0,0,0,0,0,0,0};
    vec2.reserve(10);
    fill_n(vec2.begin(), 10, 0);
    
    /*sorting algorithm-custom operation*/
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    //sort(words.begin(), words.end());
    //vector<string>::iterator it = unique(words.begin(), words.end());
    //words.erase(it, words.end());
    //stable_sort(words.begin(), words.end(), isShorter);
    Sales_data trans;
    vector<Sales_data> file;
    ifstream readlife("book_sales.txt");
    while (readInput(readlife, trans)) {
        file.push_back(trans);
    }
    sort(file.begin(), file.end(), compareISBN);
    /*for (auto f: file) {
        cout << "f: " << f.isbn() << endl;
    }*/
    partition(words.begin(), words.end(), isOverfive);
    //print(words);
    /*for(auto w : words){
        if(w.size() >= 5){
            cout << "element over five: " << w << endl;
        }
    }*/
    
    //lambda.bind
    biggies(words, 5);
    int b = 3;
    //auto sum = [b](const int a){return a + b;};
    int value = 0;
    //auto count = count_if(words.begin(), words.end(), [value](const string &s){return s.size() >= 6;});
    //auto new_value = [value]() mutable { if (value == 0) return true; while (value > 0) value--; return false;};
    //cout << new_value() << endl;
    
    
    return 0;
}
