//  code31.cpp
//  leetcode
//  顺时针打印矩阵
//  Created by Qian on 6/29/23.

#include <iostream>
using namespace::std;

/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start_row = 0, start_column = 0;
        int end_row = int(matrix.size()) - 1, end_column = int(matrix[0].size()) - 1;
        vector<int> cout_data;
        if (matrix.empty()) {
                return cout_data;
            }
        while (start_row <= end_row && start_column <= end_column) {
            for(int i = start_column; i <= end_column; ++i){
                cout_data.push_back(matrix[start_row][i]);
            }
            ++start_row;
            for(int j = start_row; j <= end_row; ++j){
                cout_data.push_back(matrix[j][end_column]);
            }
            --end_column;
            if(start_row <= end_row){
                for(int k = end_column; k >= start_column; --k){
                    cout_data.push_back(matrix[end_row][k]);
                }
                --end_row;
            }
            if(start_column <= end_column){
                for(int m = end_row; m >= start_row; --m){
                    cout_data.push_back(matrix[m][start_column]);
                }
                ++start_column;
            }
        }
        return cout_data;
    }
};
