//  main.cpp
//  MultiProcess
//  多线程实战
//  Created by Qian on 9/18/23.

#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace::std;

void* backtrack(void* arg){
    for(int i = 0; i < 5; i++){
        cout << "子线程：" << i << endl;
    }
    cout << "子线程结束" << endl;
    return NULL;
}

int main() {
    // insert code here...
    pthread_t tid;
    pthread_create(&tid, NULL, backtrack, NULL);
    for(int j = 0; j < 5; j++){
        cout << "主线程：" << j << endl;
    }
    cout << "主线程结束" << endl;
    pthread_exit(NULL);
    return 0;
}
