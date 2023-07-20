//  code39.cpp
//  leetcode
//  从上到下打印二叉树 II
//  Created by Qian on 7/4/23.

#include <iostream>
#include <deque>
using namespace::std;

/*
 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<int> in_vec;
        vector<vector<int>> out_vec;
        deque<TreeNode*> s;
        s.push_back(root);
        int sum = 1, count = 0;
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
                out_vec.push_back(in_vec);
                in_vec.clear();
                sum = count;
                count = 0;
            }
        }
        return out_vec;
    }
};

