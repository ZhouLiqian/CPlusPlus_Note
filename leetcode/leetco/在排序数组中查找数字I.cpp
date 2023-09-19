//  code33.cpp
//  leetcode
//  在排序数组中查找数字I
//  Created by Qian on 6/30/23.

#include <iostream>
#include <unordered_set>
using namespace::std;

/*统计一个数字在排序数组中出现的次数 解:二分法/哈希表/遍历*/

class Solution {
public:
    //哈希表
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
        if(nums.empty()) return 0;
        int left = 0, right = int(nums.size()) - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(target <= nums[mid]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        int count = 0;
        int i = left;
        //目标不存在
        if(nums[i] != target) return 0;
        //边界限制
        while(i < nums.size() && nums[i] == target){
            count++;
            i++;
        }
        return count;
    }
    
    //内置函数
    int search_4(vector<int> &nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        return int(r - l);
    }
};
