//  code8.cpp
//  leetcode
//  复杂链表的复制
//  Created by Qian on 6/15/23.

#include <iostream>
#include <map>
using namespace::std;

/*
 请实现 copyRandomList 函数，复制一个复杂链表。
 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        //在原链表的每个节点后面拷贝出一个新的节点
        Node *cur = head;
        unordered_map<Node*, Node*> map;
        while (cur) {
            Node *NewCur = new Node(cur -> val);
            map[cur] = NewCur;
            cur = cur -> next;
        }
        //依次给新的节点的随机指针赋值
        cur = head;
        while (cur) {
            Node *nextcur = cur -> next;
            map[cur] -> next = map[nextcur];
            Node *randomcur = cur -> random;
            map[cur] -> random = map[randomcur];
            cur = cur -> next;
        }
        //得到深度拷贝后的新链表
        return map[head];
    }
};
