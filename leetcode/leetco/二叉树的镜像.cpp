//  code42.cpp
//  leetcode
//  二叉树的镜像
//  Created by Qian on 7/4/23.

#include <iostream>
#include <deque>
using namespace::std;

/*请完成一个函数，输入一个二叉树，该函数输出它的镜像 题解：深度优先搜索*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一：递归
    TreeNode* mirrorTree_1(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        swap(root -> left, root -> right);
        mirrorTree_1(root -> left);
        mirrorTree_1(root -> right);
        return root;
    }
    
    //方法二：迭代
    TreeNode* mirrorTree_2(TreeNode* root) {
        deque<TreeNode*> q;
        if(!root)
            return root;
        else
            q.push_back(root);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop_front();
            if(tmp == NULL)
                continue;
            swap(tmp -> left, tmp -> right);
            if(tmp -> left)
                q.push_back(tmp -> left);
            if(tmp -> right)
                q.push_back(tmp -> right);
        }
        return root;
    }
};
