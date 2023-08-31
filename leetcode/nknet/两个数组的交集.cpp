//  两个数组的交集.cpp
//  leetcode
//  array
//  Created by Qian on 8/31/23.

#include <iostream>
using namespace::std;

//不存在重复元素
vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    int a[1001] = {0};//array
    for(auto num1 : nums1){
        a[num1] = 1;
    }
    vector<int> result;
    for(auto num2 : nums2){
        if(a[num2] == 1){
            result.push_back(num2);
            a[num2]++;
        }
    }
    return result;
}

//存在重复元素
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    int hashNums1[1001] = {0};
    int hashNums2[1001] = {0};
    for(int num : nums1) {
        hashNums1[num]++;
    }
    for(int num : nums2) {
        hashNums2[num]++;
    }
    // hash数组下标映射为原数组的值，
    // hash数组中存放的则是值的个数。
    for(int i = 0; i < 1001; i++) {
        if(hashNums1[i] != 0 && hashNums2[i] != 0) {
            int smallNum = hashNums1[i] <= hashNums2[i] ? hashNums1[i] : hashNums2[i];
            while(smallNum--) {
                result.push_back(i);   // 存入sumallNum个i
            }
        }
    }
    return result;
}
