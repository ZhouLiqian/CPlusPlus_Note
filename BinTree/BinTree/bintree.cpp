//  bintree.cpp
//  BinTree
//  Created by Qian on 7/1/23.

#include "bintree.hpp"

//前序遍历
void preorder(BinTreeNode *T){
    stack<BinTreeNode*> s;
    while (T || !s.empty()) {
        if(T != NULL){
            cout << T -> data << endl;
            s.push(T);
            T = T -> left;
        }
        else{
            T = s.top();
            s.pop();
            T = T -> right;
        }
    }
}

//中序遍历
void inorder(BinTreeNode *T){
    stack<BinTreeNode*> s;
    while (T || !s.empty()) {
        if(T != NULL){
            s.push(T);
            T = T -> left;
        }
        else{
            T = s.top();
            s.pop();
            cout << T -> data << endl;
            T = T -> right;
        }
    }
}

//后序遍历
void postorder(BinTreeNode *T){
    BinTreeNode *r = NULL;
    stack<BinTreeNode*> s;
    while (T || !s.empty()) {
        if(T != NULL){
            s.push(T);
            T = T -> left;
        }
        else{
            T = s.top();
            if(T -> right != NULL && T -> right != r){
                T = T -> right;
                s.push(T);
                T = T -> left;
            }
            else{
                s.pop();
                cout << T -> data << endl;
                r = T;
                T = NULL;
            }
        }
    }
}

//层序遍历
void leveorder(BinTreeNode *T){
    deque<BinTreeNode*> d;
    if(T)//根结点不为空时入队
        d.push_back(T);
    while(!d.empty()){//当队不为空时循环
        T=d.front();//取队头元素并访问该点信息
        cout<<T->data;
        if(T->left)//将该结点的左孩子和右孩子纳入队中
            d.push_back(T->left);
        if(T->right)
            d.push_back(T->right);
        d.pop_front();//队头元素出队
    }
}

//增删改查
