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
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return ans;
        path.push_back(root -> val);
        //递归函数
        dfs(root, ans, path, target - root -> val);
        return ans;
    }
    void dfs(TreeNode *cur, vector<vector<int>>& ans, vector<int>& path, int target){
        if(target == 0 && !cur -> left && !cur -> right){
            ans.push_back(path);
            return;
        }
        if(cur -> left){
            path.push_back(cur -> left -> val);
            dfs(cur -> left, ans, path, target - cur -> left -> val);
            path.pop_back();
        }
        if(cur -> right){
            path.push_back(cur -> right -> val);
            dfs(cur -> right, ans, path, target - cur -> right -> val);
            path.pop_back();
        }
    }
};


