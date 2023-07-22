//  code41.cpp
//  leetcode
//  树的子结构
//  Created by Qian on 7/4/23.

#include <iostream>
#include <deque>
using namespace::std;

/*
  输入两棵二叉树 A 和 B ，判断 B 是不是 A 的子结构。
  B 是 A 的子结构， 即 A 中有出现和 B 相同的结构和节点值
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  题解：深度优先搜索
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool recur(TreeNode* A, TreeNode* B){
        if(!B) return true;
        if(!A || A -> val != B -> val) return false;
        return recur(A -> left, B -> left) && recur(A -> right, B -> right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B || !A) return false;
        //先序遍历
        //判断包含
        return recur(A, B) || isSubStructure(A -> left, B) || isSubStructure(A -> right, B);
    }
};
