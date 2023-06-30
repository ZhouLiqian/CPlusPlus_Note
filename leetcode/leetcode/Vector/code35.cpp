//  code35.cpp
//  leetcode
//  二维数组中的查找
//  Created by Qian on 6/30/23.

#include <iostream>
using namespace::std;

/*
 在一个 n * m 的二维数组中，每一行都按照从左到右非递减的顺序排序，每一列都按照从上到下非递减的顺序排序
 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
 解:双指针
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int left = 0, right = int(matrix[0].size()) - 1;
        while (left <= matrix.size() - 1 && right >= 0) {
            if(matrix[left][right] == target)
                return true;
            else if (matrix[left][right] < target)
                left++;
            else
                right--;
        }
        return false;
    }
};

