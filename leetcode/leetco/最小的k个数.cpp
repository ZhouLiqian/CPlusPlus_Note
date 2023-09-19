//  code66.cpp
//  leetcode
//  最小的k个数
//  Created by Qian on 7/12/23.

#include <iostream>
using namespace::std;

/*
 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4
 解法：内置函数/快速排序
*/

class Solution {
public:
    //内置函数
    vector<int> getLeastNumbers_1(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> min_vec;
        for(int i = 0; i < k; i++){
            min_vec.push_back(arr[i]);
        }
        return min_vec;
    }
    
    //快速排序
    void QuickSort(vector<int>& arr, int l, int r){
        if(l >= r) return;
        int i = l, j = r;
        while(i < j){
            while (i < j && arr[j] >= arr[l]) --j;
            while (i < j && arr[i] <= arr[l]) ++i;
            swap(arr[i], arr[j]);
        }
        swap(arr[l], arr[i]);
        QuickSort(arr, l, i - 1);
        QuickSort(arr, i + 1, r);
    }
    vector<int> getLeastNumbers_2(vector<int>& arr, int k) {
        if(arr.empty()) return {};
        QuickSort(arr, 0, int(arr.size()) - 1);
        vector<int> arr_vec;
        for(int i = 0; i < k; i++){
            arr_vec.push_back(arr[i]);
        }
        return arr_vec;
    }
    
    //快速排序-数组划分
    vector<int> quickSort(vector<int>& arr, int k, int l, int r) {
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        if (i > k) return quickSort(arr, k, l, i - 1);
        if (i < k) return quickSort(arr, k, i + 1, r);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
    vector<int> getLeastNumbers_3(vector<int>& arr, int k) {
        if (k >= arr.size()) return arr;
        return quickSort(arr, k, 0, int(arr.size()) - 1);
    }
};
