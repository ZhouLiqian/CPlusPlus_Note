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
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool is_contain(TreeNode* A, TreeNode* B){
        if(B == NULL)
            return true;
        if(A == NULL)
            return false;
        if(A -> val == B -> val)
            return is_contain(A -> left, B -> left) && is_contain(A -> right, B -> right);
        else
            return false;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL)
            return false;
        
        if(A -> val == B -> val && is_contain(A, B))
            return true;
        else
            return isSubStructure(A -> left, B) || isSubStructure(A -> right, B);
    }
};
