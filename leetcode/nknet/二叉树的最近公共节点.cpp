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
    //哈希表
    unordered_map<int, TreeNode*> tree;
    unordered_map<int, bool> check;
    void dfs(TreeNode* root){
        if(root -> left){
            tree[root -> left -> val] = root;
            dfs(root -> left);
        }
        if(root -> right){
            tree[root -> right -> val] = root;
            dfs(root -> right);
        }
    }
    TreeNode* lowestCommonAncestor_1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        //父子关系建立哈希表
        tree[root -> val] = NULL;
        dfs(root);
        
        //遍历表
        while (p) {
            check[p -> val] = true;
            p = tree[p -> val];
        }
        while (q) {
            if(check[q -> val]) return q;
            q = tree[q -> val];
        }
        return NULL;
    }
    
    //先序遍历
    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor_1(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor_1(root -> right, p, q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        return root;
    }
};
