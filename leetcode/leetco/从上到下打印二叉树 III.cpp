//  code40.cpp
//  leetcode
//  从上到下打印二叉树 III
//  Created by Qian on 7/4/23.

#include <iostream>
#include <deque>
using namespace::std;

/*
  请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
  第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  解法：广度优先搜索
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> data_tree;
        vector<vector<int>> out_data_tree;
        deque<TreeNode*> s;
        int flag = 1;
        if(root)
            s.push_back(root);
        //记录层数及每层个数
        int row = 1, count = 0;
        while (!s.empty()) {
            root = s.front();
            data_tree.push_back(root -> val);
            row--;
            if(root -> left){
                s.push_back(root -> left);
                count++;
            }
            if(root -> right){
                s.push_back(root -> right);
                count++;
            }
            if(!row){
                if(flag){
                    out_data_tree.push_back(data_tree);
                    flag = 0;
                }
                else{
                    reverse(data_tree.begin(), data_tree.end());
                    out_data_tree.push_back(data_tree);
                    flag = 1;
                }
                row = count;
                count = 0;
                data_tree.clear();
            }
            s.pop_front();
        }
        return out_data_tree;
    }
    //方法二
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        if(root!=nullptr) q.push_back(root);
        bool flag = true;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> tmp;
            for(int i=0;i<n;i++)
            {
                TreeNode *node;
                if(flag)
                {
                    node = q.front();
                    q.pop_front();
                    if(node->left!=nullptr) q.push_back(node->left);
                    if(node->right!=nullptr) q.push_back(node->right);
                }
                else
                {
                    node = q.back();
                    q.pop_back();
                    if(node->right!=nullptr) q.push_front(node->right);
                    if(node->left!=nullptr) q.push_front(node->left);
                }
                tmp.push_back(node->val);
            }
            flag = !flag;
            ans.push_back(tmp);
        }
        return ans;
    }
};
