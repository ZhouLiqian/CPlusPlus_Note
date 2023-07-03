//  bintree.hpp
//  BinTree(二叉树)
//  Created by Qian on 7/1/23.

#ifndef bintree_hpp
#define bintree_hpp

#include <iostream>
#include <stack>
#include <deque>
using namespace::std;

struct BinTreeNode{
    int data;
    struct BinTreeNode *left;
    struct BinTreeNode *right;
    
    BinTreeNode() = default;
    explicit BinTreeNode(int d) : data(d){
        left = nullptr;
        right = nullptr;
    }
};

class BinTree{
private:
    BinTreeNode *head;
public:
    void preorder(BinTreeNode *T);
    void inorder(BinTreeNode *T);
    void postorder(BinTreeNode *T);
    void leveorder(BinTreeNode *T);
    void addtree(int data);
    void deltree(int data);
    BinTreeNode* getnode(int data);
};
#endif /* bintree_hpp */
