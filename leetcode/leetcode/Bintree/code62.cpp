//  code62.cpp
//  leetcode
//  重建二叉树
//  Created by Qian on 7/11/23.

#include <iostream>
#include <unordered_map>
using namespace::std;

/*输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点*/

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
        for(int i = 0; i < inorder.size(); i++){
            dic[inorder[i]] = i;
        }
        return recur(0, 0, int(inorder.size() - 1));
    }
private:
    vector<int> preorder;
    unordered_map<int, int> dic;
    TreeNode* recur(int root, int left, int right){
        if(left > right) return nullptr;//递归终止
        TreeNode* node = new TreeNode(preorder[root]);//建立根节点
        int i = dic[preorder[root]];
        node -> left = recur(root + 1, left, i - 1);//递归左子树
        node -> right = recur(root + i - left + 1, i + 1, right);//递归右子树
        return node;//回溯
    }
};
