//  合并两个排序的链表.cpp
//  leetcode
//  创建伪头节点
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 != NULL && l2 != NULL) {
            if(l1 -> val <= l2 -> val){
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else{
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        if(l1 == NULL && l2 != NULL) cur -> next = l2;
        if(l1 != NULL && l2 == NULL) cur -> next = l1;
        return dummy -> next;
    }
};
