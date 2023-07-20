//  code53.cpp
//  leetcode
//  二叉树的最近公共祖先
//  Created by Qian on 7/7/23.

#include <iostream>
#include <unordered_map>
using namespace::std;

/*给定一个二叉树, 找到该树中两个指定节点的最近公共祖先*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //建立父子节点字典
    unordered_map<int, TreeNode*> dict;
    unordered_map<int, bool> che;
    void dfs(TreeNode *root){
        if(root -> left){
            dict[root -> left -> val] = root;
            dfs(root -> left);
        }
        if(root -> right){
            dict[root -> right -> val] = root;
            dfs(root -> right);
        }
    }
    //字典查找
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        dict[root -> val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            che[p -> val] = true;
            p = dict[p -> val];
        }
        while (q != nullptr) {
            if(che.count(q -> val)) return q;
            q = dict[q -> val];
        }
        return nullptr;
    }
};
