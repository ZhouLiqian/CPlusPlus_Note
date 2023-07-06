//  code48.cpp
//  leetcode
//  二叉搜索树的第k大节点
//  Created by Qian on 7/6/23.

#include <iostream>
using namespace::std;

/*
 给定一棵二叉搜索树，请找出其中第 k 大的节点的值
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
    vector<int> max;
    int kthLargest(TreeNode* root, int k) {
        if(!root) return NULL;
        dfs(root);
        return max[max.size() - k];
    }
    void dfs(TreeNode *root){
        if(!root) return;
        dfs(root -> left);
        max.push_back(root -> val);
        dfs(root -> right);
    }
};

