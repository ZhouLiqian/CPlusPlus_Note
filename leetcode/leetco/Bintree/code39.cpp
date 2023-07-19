//  code39.cpp
//  leetcode
//  从上到下打印二叉树 II
//  Created by Qian on 7/4/23.

#include <iostream>
#include <deque>
using namespace::std;

/*
 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
     vector<vector<int>> levelOrder(TreeNode* root) {
         vector<int> data_tree;
         vector<vector<int>> out_data_tree;
         deque<TreeNode*> s;
         if(root)
             s.push_back(root);
         //记录层数及每层个数
         int row = 1, count = 0;
         while (!s.empty()) {
             root = s.front();
             data_tree.push_back(root -> val);
             row--;
             if(root -> left){
                 s.push_back(root -> left);
                 count++;
             }
             if(root -> right){
                 s.push_back(root -> right);
                 count++;
             }
             if(!row){
                 out_data_tree.push_back(data_tree);
                 row = count;
                 count = 0;
                 data_tree.clear();
             }
             s.pop_front();
         }
         return out_data_tree;
    }
};

