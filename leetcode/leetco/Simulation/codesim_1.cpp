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
        vector<int> mat_vec;
        if(matrix.empty()) return mat_vec;
        unsigned long row = matrix.size(), column = matrix[0].size();
        int row_start = 0, col_start = 0;
        unsigned long row_end = row - 1, col_end = column - 1;
        while(row_start <= row_end && col_start <= col_end){
            for(int i = col_start; i <= col_end; i++){
                mat_vec.push_back(matrix[row_start][i]);
            }
            row_start++;
            if(row_start > row_end) break;
            for(int j = row_start; j <= row_end; j++){
                mat_vec.push_back(matrix[j][col_end]);
            }
            --col_end;
            if(col_start > col_end) break;
            for(unsigned long k = col_end; k >= col_start; k--){
                mat_vec.push_back(matrix[row_end][k]);
            }
            --row_end;
            if(row_start > row_end) break;
            for(unsigned long p = row_end; p >= row_start; p--){
                mat_vec.push_back(matrix[p][col_start]);
            }
            col_start++;
            if(col_start > col_end) break;
        }
        return mat_vec;
    }
};
