//  code49.cpp
//  leetcode
//  二叉树的深度
//  Created by Qian on 7/6/23.

#include <iostream>
#include <stack>
#include <queue>
using namespace::std;

/*输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //深度优先搜索
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> s;
        stack<int> depth;
        int res_depth = 0;
        //初始化节点栈和深度栈
        if(root != NULL){
            s.push(root);
            depth.push(1);
        }
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            int temp_depth = depth.top();
            depth.pop();
            res_depth = temp_depth > res_depth ? temp_depth : res_depth;
            if(node -> left != NULL){
                s.push(node -> left);
                depth.push(temp_depth + 1);
            }
            if(node -> right != NULL){
                s.push(node -> right);
                depth.push(temp_depth + 1);
            }
        }
        return res_depth;
    }
    //广度优先搜索
    int maxDepth_2(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while (!Q.empty()) {
            int sz = int(Q.size());
            while (sz > 0) {
                TreeNode* node = Q.front();Q.pop();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                sz -= 1;
            }
            ans += 1;
        }
        return ans;
    }
    //递归
    int maxDepth_3(TreeNode* root){
        if(!root)
            return 0;
        int maxLeftDepth = maxDepth_3(root -> left);
        int maxRightDepth = maxDepth_3(root -> right);
        return max(maxLeftDepth, maxRightDepth) + 1;
    }
};
