//  排序算法.cpp
//  leetcode
//  Created by Qian on 9/1/23.

#include <iostream>
using namespace::std;

//快速排序O(nlogn)
void QuickSort(vector<int>& nums, int left, int right){
    if(left >= right) return;
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) j--;
        while (i < j && nums[i] <= nums[left]) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    QuickSort(nums, left, i - 1);
    QuickSort(nums, i + 1, right);
}

//堆排序O(nlogn)
void sift_down(int arr[], int start, int end){
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
void heap_sort(int arr[], int len){
    for(int i = (len - 1 - 1) / 2; i >= 0; i--)
        sift_down(arr, i, len - 1);
    for(int i = len - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        sift_down(arr, 0, i - 1);
    }
}

//插入排序O(n^2)
void InsertSort(vector<int>& nums){
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[i]) swap(nums[j], nums[i]);
        }
    }
}
