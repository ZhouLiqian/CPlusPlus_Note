//  反转链表.cpp
//  leetcode
//  链表
//  Created by Qian on 8/23/23.

#include <iostream>
using namespace::std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur -> next;
            cur -> next = dummy -> next;
            dummy -> next = cur;
            cur = next;
        }
        return dummy -> next;
    }
};
