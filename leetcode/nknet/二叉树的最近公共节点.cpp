//  二叉树的最近公共节点.cpp
//  leetcode
//  搜索与回溯算法
//  Created by Qian on 8/21/23.

#include <iostream>
#include <unordered_map>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //先序遍历
    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor_2(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor_2(root -> right, p, q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        return root;
    }
};
