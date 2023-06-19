//  code9.cpp
//  leetcode
//  链表删除节点
//  Created by Qian on 6/19/23.

#include <iostream>
using namespace::std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

/*
 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点
 返回删除后的链表的头节点
 */

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        //空链表
        if(!head)
            return head;
        ListNode *p = head, *q = head;
        //头节点是指定值
        if(p -> val == val){
            p = p -> next;
            return p;
        }
        while (p -> val != val && p -> next != NULL) {
            q = p;
            p = p -> next;
        }
        //其他节点是指定值/无指定值
        if(p -> val == val){
            q -> next = p -> next;
            delete p;
        }
        else
        {
            cout << "no val" << endl;
        }
        return head;
    }
};
