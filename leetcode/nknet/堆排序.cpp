//  堆排序.cpp
//  leetcode
//  大根堆
//  Created by Qian on 8/24/23.

#include <iostream>
using namespace::std;

void sift_down(int arr[], int start, int end){
    //计算父节点和子节点的下标
    int parent = start;
    int child = parent * 2 + 1;
    //边界限制
    while(child <= end){
        //比较两子节点的大小
        if(child + 1 <= end && arr[child] < arr[child + 1]) child++;
        //比较父子节点的大小
        if(arr[parent] >= arr[child]) return;
        else{
            //父节点 < 子节点 -> 交换父子节点
            //递归子孙节点
            swap(arr[parent], arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len){
    for(int i = (len - 1 - 1) / 2; i >= 0; i--)
        sift_down(arr, i, len - 1);
    for(int i = len - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        sift_down(arr, 0, i - 1);
    }
}
