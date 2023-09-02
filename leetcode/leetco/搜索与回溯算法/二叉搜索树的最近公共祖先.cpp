//  code52.cpp
//  leetcode
//  二叉搜索树的最近公共祖先
//  Created by Qian on 7/7/23.

#include <iostream>
using namespace::std;

/*给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先 解法：深度优先搜索*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一：迭代
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ptr = root;
        while (true) {
            if(ptr -> val < p -> val && ptr -> val < q -> val)
                ptr = ptr -> right;
            else if (ptr -> val > p -> val && ptr -> val > q -> val)
                ptr = ptr -> left;
            else
                break;
        }
        return ptr;
    }
    //方法二：递归
    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left, p, q);
        else if(p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right, p, q);
        return root;
    }
};
