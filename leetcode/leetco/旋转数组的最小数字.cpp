//  code36.cpp
//  leetcode
//  旋转数组的最小数字
//  Created by Qian on 6/30/23.

#include <iostream>
using namespace::std;

/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转 解法：内置函数/二分法*/

class Solution {
public:
    //内置函数
    int minArray_1(vector<int>& numbers) {
        int min = *min_element(numbers.begin(), numbers.end());
        return min;
    }
    
    //二分法
    int minArray_2(vector<int>& numbers) {
        //判断空
        if(numbers.empty()) return NULL;
        //二分开始
        int left = 0, right = int(numbers.size()) - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(numbers[mid] > numbers[right]) {
                left = mid + 1;
            }else if(numbers[mid] < numbers[right]){
                right = mid;
            }else{
                right--;
            }
        }
        return numbers[left];
    }
};
