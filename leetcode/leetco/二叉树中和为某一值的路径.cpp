//  code46.cpp
//  leetcode
//  二叉树中和为某一值的路径
//  Created by Qian on 7/6/23.

#include <iostream>
using namespace::std;

/*
 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有从根节点到叶子节点路径总和等于给定目标和的路径
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  题解：回溯算法
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution {
public:
    vector<vector<int>> arr;
    vector<int> res;
    void backtrack(TreeNode* root, int target){
        if(!root) return;
        res.push_back(root -> val);
        target -= root -> val;
        if(target == 0 && root -> left == nullptr && root -> right == nullptr)
            arr.push_back(res);
        backtrack(root -> left, target);
        backtrack(root -> right, target);
        res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return {};
        backtrack(root, target);
        return arr;
    }
};


