//  code63.cpp
//  leetcode
//  数组中的逆序对
//  Created by Qian on 7/11/23.

#include <iostream>
using namespace::std;

/*在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数*/

class Solution {
public:
    //暴力遍历
    int reversePairs(vector<int>& nums) {
        int count = 0;
        for(int left = 0; left < nums.size() - 1; left++){
            for(int right = left + 1; right < nums.size(); right++){
                if(nums[right] < nums[left])
                    count++;
            }
        }
        return count;
    }
    //分治算法
    int reversePairs_2(vector<int>& nums){
        vector<int> tmp(nums.size());
        return mergeSort(0, int(nums.size() - 1), nums, tmp);
    }
private:
    int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
        // 终止条件
        if (l >= r) return 0;
        // 递归划分
        int m = (l + r) / 2;
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
        // 合并阶段
        int i = l, j = m + 1;
        for (int k = l; k <= r; k++)
            tmp[k] = nums[k];
        for (int k = l; k <= r; k++) {
            if (i == m + 1)
                nums[k] = tmp[j++];
            else if (j == r + 1 || tmp[i] <= tmp[j])
                nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                res += m - i + 1; // 统计逆序对
            }
        }
        return res;
    }
};
