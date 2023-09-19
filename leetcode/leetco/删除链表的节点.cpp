//  code9.cpp
//  leetcode
//  删除链表的节点
//  Created by Qian on 6/19/23.

#include <iostream>
using namespace::std;

/*
 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点
 返回删除后的链表的头节点
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

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
    
    //自方法
    ListNode* deleteNode_2(ListNode* head, int val){
        //判断空
        if(!head) return head;
        
        //头节点
        if(head -> val == val) return head -> next;
        
        //遍历节点
        ListNode* pre = head;
        ListNode* cur = head -> next;
        while (cur != NULL && cur -> val != val) {
            pre = cur;
            cur = cur -> next;
        }
        if(cur -> val == val){
            pre -> next = cur -> next;
        }
        else{
            return NULL;
        }
        return head;
    }
};
