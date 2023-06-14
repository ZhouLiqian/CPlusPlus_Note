//  code4.cpp
//  leetcode
//  Created by Qian on 6/14/23.

#include <iostream>
using namespace::std;

//结点声明
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//输入一个链表的头节点，反转该链表并输出反转后链表的头节点
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *dummy = new ListNode(0);
        while (curr) {
            ListNode *next = curr -> next;
            curr -> next = dummy -> next;
            dummy -> next = curr;
            curr = next;
        }
        return dummy -> next;
    }
};
