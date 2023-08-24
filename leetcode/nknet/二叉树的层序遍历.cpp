//  二叉树的层序遍历.cpp
//  leetcode
//  广度优先搜索
//  Created by Qian on 8/23/23.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> de;
        vector<vector<int>> maxv;
        de.push(root);
        while(!de.empty()){
            vector<int> minv;
            for(int i = int(de.size()); i > 0; i--){
                root = de.front();
                de.pop();
                minv.push_back(root -> val);
                if(root -> left) de.push(root -> left);
                if(root -> right) de.push(root -> right);
            }
            maxv.push_back(minv);
        }
        return maxv;
    }
};
