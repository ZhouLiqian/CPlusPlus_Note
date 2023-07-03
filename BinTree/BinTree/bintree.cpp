//  bintree.cpp
//  BinTree
//  Created by Qian on 7/1/23.

#include "bintree.hpp"

//前序遍历
void BinTree::preorder(BinTreeNode *T){
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
void BinTree::inorder(BinTreeNode *T){
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
void BinTree::postorder(BinTreeNode *T){
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
void BinTree::leveorder(BinTreeNode *T){
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

//增加元素
void BinTree::addtree(int data){
    if(head == NULL){
        head = new BinTreeNode(data);
    }
    else{
        BinTreeNode *n = head;
        while (n != NULL) {
            //向左
            if(data < n -> data){
                if(n -> left != NULL){
                    n = n -> left;
                }
                else{
                    BinTreeNode *l = new BinTreeNode(data);
                    n -> left = l;
                    return;
                }
            }
            else{//向右
                if(n -> right != NULL){
                    n = n -> right;
                }
                else{
                    BinTreeNode *l = new BinTreeNode(data);
                    n -> right = l;
                    return;
                }
            }
        }
    }
}

//删除元素
void BinTree::deltree(int data){
    BinTreeNode *n = head;
    BinTreeNode *parent = nullptr;
    while (n != NULL) {
        if(data > n -> data){//向右
            parent = n;
            n = n -> right;
        }
        else if (data < n -> data){//向左
            parent = n;
            n = n -> left;
        }
        else{//相等
            if(n -> left != NULL && n -> right == NULL){//左非空且右空
                if(parent -> left == n){
                    parent -> left = n -> left;
                    delete(n);
                    return;
                }
                else{
                    parent -> right = n -> left;
                    delete(n);
                    return;
                }
            }
            else if (n -> left == NULL && n -> right != NULL){//右非空且左空
                if(parent -> left == n){
                    parent -> left = n -> right;
                    delete(n);
                    return;
                }
                else{
                    parent -> right = n -> right;
                    delete(n);
                    return;
                }
            }
            else if (n -> left == NULL && n -> right == NULL){//左右均空
                if(parent -> left == n){
                    parent -> left = NULL;
                    delete(n);
                    return;
                }
                else{
                    parent -> right = NULL;
                    delete(n);
                    return;
                }
            }
            else{//左右均非空
                BinTreeNode *sub = n -> right;
                if(sub -> left == NULL){
                    sub -> left = n -> left;
                    if(parent -> left == n){
                        parent -> left = sub;
                        delete(n);
                        return;
                    }
                    else{
                        parent -> right = sub;
                        delete(n);
                        return;
                    }
                }
                else{
                    BinTreeNode *p = sub;
                    while(sub -> left != NULL)
                    {//寻找后继节点
                        p = sub;
                        sub = sub -> left;
                    }
                    p -> left = NULL;
                    if(parent -> left == n){
                        sub -> left = n -> left;
                        sub -> right = n -> right;
                        parent -> left = sub;
                        delete(n);
                        return;
                    }else{
                        sub -> left = n -> left;
                        sub -> right = n -> right;
                        parent -> right = sub;
                        delete(n);
                        return;
                    }
                }
            }
        }
    }
    cout << "没有找到" << endl;
    return;
}

//查找元素
BinTreeNode* BinTree::getnode(int data){
    BinTreeNode *n = head;
    while (n != NULL) {
        if(data < n -> data)
            n = n -> left;
        else if (data > n -> data)
            n = n -> right;
        else
            return n;
    }
    return NULL;
}
