//  code27.cpp
//  leetcode
//  和为s的连续正数序列
//  Created by Qian on 6/28/23.

#include <iostream>
#include <vector>
using namespace::std;

/*
 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数)
 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列
 解:滑动窗口
*/

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> com_vector;
        for(int sum = 0, left = 1, right = 1; right < target; right++){
            sum = sum + right;
            //求和
            while (sum > target) {
                sum = sum - left;
                left++;
            }
            if(sum == target){
                vector<int> ent_vector;
                for(int value = left; value <= right; value++){
                    ent_vector.push_back(value);
                }
                com_vector.push_back(ent_vector);
            }
        }
        return com_vector;
    }
};
