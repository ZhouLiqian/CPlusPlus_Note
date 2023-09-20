#include <iostream>
using namespace::std;

struct xxx{
    double val; //8
    double arg; //8
    double num; //8
    char sym; //1
};

int main(){
    cout << sizeof(xxx) << endl;
    return 0;
}
