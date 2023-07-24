//  code33.cpp
//  leetcode
//  在排序数组中查找数字I
//  Created by Qian on 6/30/23.

#include <iostream>
#include <unordered_set>
using namespace::std;

/*统计一个数字在排序数组中出现的次数 解:二分法*/

class Solution {
public:
    
    //内置函数
    int search(vector<int>& nums, int target) {
        unordered_multiset<int> set;
        for(int num : nums){
            set.insert(num);
        }
        return int(set.count(target));
    }
    
    //遍历
    int search_2(vector<int>& nums, int target) {
        int count = 0;
        for(int num : nums){
            if (num == target){
                count++;
            }
        }
        return count;
    }
    
    //二分法
    int search_3(vector<int>& nums, int target) {
        /* 搜索右边界 right */
        int i = 0, j = int(nums.size()) - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if(nums[mid] <= target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        int right = i;
        /* 若数组中无 target ，则提前返回 */
        if(j >= 0 && nums[j] != target)
            return 0;
        /* 搜索左边界 left */
        i = 0;
        j = int(nums.size()) - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if(nums[mid] >= target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        int left = j;
        return right - left - 1;
    }
};
