//  code6.cpp
//  leetcode
//  链表重排
//  Created by Qian on 6/15/23.

#include <iostream>
using namespace::std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*给定一个单链表 L 的头节点 head ，单链表 L 表示为：L0 → L1 → … → Ln-1 → Ln
 请将其重新排列后变为：L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换*/

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* node = head;
        vector<ListNode*> vi;
        while(node != nullptr){
            vi.push_back(node);
            node = node->next;
        }
        node = head;
        unsigned long n = vi.size();
        for(unsigned long i = n - 1; i > n / 2; --i){
            ListNode* temp = vi[i];
            temp->next = node->next;
            node->next = temp;
            node = temp->next;
        }
        if(n & 1){
            node->next = nullptr;
        }
        else{
            node->next->next = nullptr;
        }
    }
};
