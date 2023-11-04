//  堆排序算法.cpp
//  leetcode
//  大顶堆
//  Created by Qian on 10/11/23.

#include <iostream>
using namespace::std;

//堆排序
void sift_down(vector<int>& arr, int start, int end){
    int parent = start;
    int child = parent * 2 + 1;
    while(child <= end){
        if(child + 1 <= end && arr[child] < arr[child + 1]) child++;
        if(arr[parent] >= arr[child]) return;
        else{
            swap(arr[parent], arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

vector<int> sortArray(vector<int>& nums){
    for(int i = (int(nums.size()) - 1 - 1) / 2; i >= 0; i--)
        sift_down(nums, i, int(nums.size()) - 1);
    for(int i = int(nums.size()) - 1; i > 0; i--){
        swap(nums[0], nums[i]);
        sift_down(nums, 0, i - 1);
    }

    return nums;
}
