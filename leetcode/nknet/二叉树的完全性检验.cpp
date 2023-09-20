//  二叉树的完全性检验.cpp
//  leetcode
//
//  Created by Qian on 9/20/23.

#include <iostream>
#include <queue>
using namespace::std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        bool syn = false;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();
            if(cur == NULL)
            {
                syn = true;
                continue;
            }
            else{
                if(syn) return false;
                que.push(cur -> left);
                que.push(cur -> right);
            }
        }
        return true;
    }
};
