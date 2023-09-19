//  code62.cpp
//  leetcode
//  重建二叉树
//  Created by Qian on 7/11/23.

#include <iostream>
#include <unordered_map>
using namespace::std;

/*输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点 解法：哈希表/回溯*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this -> preorder = preorder;
        //中序遍历序列-索引存字典
        for(int i = 0; i < inorder.size(); i++){
            in_map[inorder[i]] = i;
        }
        TreeNode* root = div_con(0, 0, int(inorder.size()) - 1);
        return root;
    }
private:
    vector<int> preorder;
    unordered_map<int, int> in_map;
    TreeNode* div_con(int root, int left, int right){
        if(left > right) return NULL;
        TreeNode* node = new TreeNode(preorder[root]);
        int i = in_map[preorder[root]];
        node -> left = div_con(root + 1, left, i - 1);
        node -> right = div_con(root + i - left + 1, i + 1, right);
        return node;
    }
};
