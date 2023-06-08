//  main.cpp
//  Dynamic_memory
//  Created by Qian on 6/8/23.

#include "dynamic_memory.hpp"

int main() {
    // insert code here...
    ifstream infile("original_file.txt");
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
    return 0;
}
