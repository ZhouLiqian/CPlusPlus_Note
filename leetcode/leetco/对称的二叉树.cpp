//  code43.cpp
//  leetcode
//  对称的二叉树
//  Created by Qian on 7/4/23.

#include <iostream>
#include <deque>
#include <vector>
using namespace::std;

/*请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的 题解：深度优先搜索*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSame(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right || left -> val != right -> val) return false;
        return isSame(left -> left, right -> right) && isSame(left -> right, right -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSame(root -> left, root -> right);
    }
};
