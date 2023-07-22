//  main.cpp
//  Test
//  Created by Qian on 7/6/23.

#include <string>
#include <sstream>
#include <iostream>
using namespace::std;

int main(){
    vector<vector<int>> arr;
    vector<int> a;
    string input;
    //读取数据
    while (getline(cin, input)) {
        if (input.size() > 0) {
            stringstream stringin(input);
            int num;
            vector<int> a;
            while (stringin >> num) {
                a.push_back(num);
            }
            arr.push_back(a);
        }
    }
    //输出数据
    for(int i = 0; i < arr.size(); i++){
        for(int data : arr[i]){
            cout << data << endl;
        }
    }
    return 0;
}
