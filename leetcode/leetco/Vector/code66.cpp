//  code66.cpp
//  leetcode
//  最小的k个数
//  Created by Qian on 7/12/23.

#include <iostream>
using namespace::std;

/*输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4*/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> min_vec;
        for(int i = 0; i < k; i++){
            min_vec.push_back(arr[i]);
        }
        return min_vec;
    }
};
