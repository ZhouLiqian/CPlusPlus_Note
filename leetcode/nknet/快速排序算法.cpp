//  快速排序算法.cpp
//  leetcode
//  递归算法
//  Created by Qian on 10/11/23.

#include <iostream>
using namespace::std;

//快速排序
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

vector<int> Result(vector<int>& nums){
    QuickSort(nums, 0, int(nums.size()) - 1);
    return nums;
}

/*优化*/
/*安全的做法：使用随机数，随机选择一个数作为pivot*/
/*稳定版本：选择left = 0，right = nums.count - 1，(right + left) / 2 三个位置中中间那个数作为pivot*/
