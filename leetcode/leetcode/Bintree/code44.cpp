//  code44.cpp
//  leetcode
//  矩阵中的路径
//  Created by Qian on 7/5/23.

#include <iostream>
using namespace::std;

/*给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(dfs(board, word, 0, i, j)) return true;
        return false;
    }
    //深度优先搜索
    int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
    bool dfs(vector<vector<char>> &board, string word, int u, int x, int y){
        if(board[x][y] != word[u]) return false;
        if(u == word.size() - 1) return true;
        char t = board[x][y];
        board[x][y] = '.';
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;
            if(dfs(board, word, u + 1, a, b)) return true;
        }
        board[x][y] = t;
        return false;
    }
};
