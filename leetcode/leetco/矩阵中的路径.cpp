//  code44.cpp
//  leetcode
//  矩阵中的路径
//  Created by Qian on 7/5/23.

#include <iostream>
using namespace::std;

/*
 给定一个 m*n 二维字符网格 board 和一个字符串单词 word 。
 如果 word 存在于网格中，返回 true ；否则，返回 false
 题解：搜索与回溯
*/

class Solution {
public:
//回溯法
    bool backtrack(vector<vector<char>> &board, int row, int col, const string &word, int idx){
        //终止条件
        if(idx == word.size()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        if(word[idx] != board[row][col]) return false;
        //做选择
        board[row][col] = '*';
        //回溯
        if(backtrack(board, row + 1, col, word, idx + 1) ||
           backtrack(board, row - 1, col, word, idx + 1) ||
           backtrack(board, row, col + 1, word, idx + 1) ||
           backtrack(board, row, col - 1, word, idx + 1))
           return true;
        //撤销选择
        board[row][col] = word[idx];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty())
            return word.empty();
        for(int row = 0; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                if(backtrack(board, row, col, word, 0))
                    return true;
            }
        }
        return false;
    }
};
