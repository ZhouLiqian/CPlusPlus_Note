//  code50.cpp
//  leetcode
//  平衡二叉树
//  Created by Qian on 7/6/23.

#include <iostream>
using namespace::std;

/*
 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
 如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树
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
//求深度
    int maxDepth_3(TreeNode* root){
        if(!root) return 0;
        int maxLeftDepth = maxDepth_3(root -> left);
        int maxRightDepth = maxDepth_3(root -> right);
        return max(maxLeftDepth, maxRightDepth) + 1;
    }
//判断平衡
    bool dfs(TreeNode* root){
        if(root == NULL) return true;
        if(abs(maxDepth_3(root -> left) - maxDepth_3(root -> right)) > 1)
            return false;
        return dfs(root -> left) && dfs(root -> right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(dfs(root)) return true;
        return false;
    }
};
