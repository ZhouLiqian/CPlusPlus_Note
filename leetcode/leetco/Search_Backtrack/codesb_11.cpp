//  code48.cpp
//  leetcode
//  二叉搜索树的第k大节点
//  Created by Qian on 7/6/23.

#include <iostream>
#include <stack>
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
  解法：深度优先搜索
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一：中序遍历+数组寻值
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
    //方法二：中序遍历倒序+提前返回
    int value, k;
    int kthLargest_2(TreeNode* root, int k){
        if(root == nullptr) return 0;
        this -> k = k;
        dfs_2(root);
        return value;
    }
    void dfs_2(TreeNode* root){
        if(root == nullptr) return;
        dfs_2(root -> right);
        if(k == 0) return;
        if(--k == 0) value = root -> val;
        dfs_2(root -> left);
    }
};

