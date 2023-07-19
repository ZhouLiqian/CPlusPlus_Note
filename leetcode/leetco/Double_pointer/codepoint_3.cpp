//  code11.cpp
//  leetcode
//  合并两个排序的链表
//  Created by Qian on 6/19/23.

#include <iostream>
using namespace::std;

/*输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    //方法一
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* result = NULL;
        if(l1->val < l2->val) {
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        }
        else {
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }
        return result;
    }
    
    //方法二
    ListNode *mergeTwoLists_2(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 && l2) {
            if(l1 -> val < l2 -> val){
                p -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                p -> next = l2;
                l2 = l2 -> next;
            }
            p = p -> next;
        }
        while (l1) {
            p -> next = l1;
        }
        while (l2) {
            p -> next = l2;
        }
        return head -> next;
    }
};
