//  code43.cpp
//  leetcode
//  对称的二叉树
//  Created by Qian on 7/4/23.

#include <iostream>
#include <deque>
#include <vector>
using namespace::std;

/*请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool check(TreeNode *left, TreeNode *right){
        if(left == nullptr && right == nullptr)
            return true;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right != nullptr)
            return false;
        else{
            return left -> val == right -> val && check(left -> left, right -> right) && check(left -> right, right -> left);
        }
    }
    
    //判断对称
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        if(check(root, root))
            return true;
        else
            return false;
    }
};
