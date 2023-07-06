//  code47.cpp
//  leetcode
//  二叉搜索树与双向链表
//  Created by Qian on 7/6/23.

#include <iostream>
#include <stack>
using namespace::std;

/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* head = nullptr;
    Node* pre = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        dfs(root);
        head -> left = pre;
        pre -> right = head;
        return head;
    }
    //中序遍历
    void dfs(Node *root){
        if(!root) return;
        dfs(root -> left);
        if(pre)
            pre -> right = root;
        else
            head = root;
        root -> left = pre;
        pre = root;
        dfs(root -> right);
    }
    //非递归
    void dfs_2(Node *root){
        stack<Node*> s;
        while (root || !s.empty()) {
            if(root != NULL){
                s.push(root);
                root = root -> left;
            }
            else{
                root = s.top();
                s.pop();
                if(pre)
                    pre -> right = root;
                else
                    head = root;
                root -> left = pre;
                pre = root;
                root = root -> right;
            }
        }
    }
};
