//  code38.cpp
//  leetcode
//  从上到下打印二叉树
//  Created by Qian on 7/3/23.

#include <iostream>
#include <deque>
#include <vector>
using namespace::std;

/*从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 解法：层序遍历
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> data_tree;
        deque<TreeNode*> s;
        if(!root)
            return data_tree;
        else
            s.push_back(root);
        while (!s.empty()) {
            root = s.front();
            data_tree.push_back(root -> val);
            if(root -> left)
                s.push_back(root -> left);
            if(root -> right)
                s.push_back(root -> right);
            s.pop_front();
        }
        return data_tree;
    }
};
