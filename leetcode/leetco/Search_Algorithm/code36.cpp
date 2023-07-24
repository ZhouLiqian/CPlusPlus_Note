//  code36.cpp
//  leetcode
//  旋转数组的最小数字
//  Created by Qian on 6/30/23.

#include <iostream>
using namespace::std;

/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转*/

class Solution {
public:
    //内置函数
    int minArray(vector<int>& numbers) {
        int min = *min_element(numbers.begin(), numbers.end());
        return min;
    }
    //二分法
    int minArray_2(vector<int>& numbers) {
        if(numbers.empty())
            return NULL;
        int left = 0, right = int(numbers.size()) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if(numbers[mid] < numbers[right])
                right = mid;
            else if (numbers[mid] > numbers[right])
                left = mid + 1;
            else
                right--;
        }
        return numbers[left];
    }
};
