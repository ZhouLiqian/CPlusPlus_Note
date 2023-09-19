//  code49.cpp
//  leetcode
//  二叉树的深度
//  Created by Qian on 7/6/23.

#include <iostream>
#include <stack>
#include <queue>
using namespace::std;

/*
 输入一棵二叉树的根节点，求该树的深度。
 从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度
 解法：深度优先搜索/广度优先搜索
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一：深度优先搜索/迭代
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
    
    //方法二：广度优先搜索/迭代
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        vector<int> in_vec;
        deque<TreeNode*> s;
        s.push_back(root);
        int sum = 1, count = 0, res = 0;
        while (!s.empty()) {
            root = s.front();
            in_vec.push_back(root -> val);
            if(root -> left){
                s.push_back(root -> left);
                count++;
            }
            if(root -> right){
                s.push_back(root -> right);
                count++;
            }
            s.pop_front();
            sum--;
            if(sum == 0){
                in_vec.clear();
                sum = count;
                count = 0;
                res++;
            }
        }
        return res;
    }
    
    //方法三：递归/深度优先搜索
    int maxDepth_3(TreeNode* root){
        if(!root) return 0;
        int maxLeftDepth = maxDepth_3(root -> left);
        int maxRightDepth = maxDepth_3(root -> right);
        return max(maxLeftDepth, maxRightDepth) + 1;
    }
};
