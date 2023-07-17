//  code10.cpp
//  leetcode
//  链表中倒数第k个节点
//  Created by Qian on 6/19/23.

#include <iostream>
using namespace::std;

/*
 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点
 例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //节点计数
        int sum = 0;
        ListNode *p = head;
        ListNode *q = head;
        for(; head; head = head -> next){
            sum++;
        }
        //返回正向节点
        for(int j = 1; j < sum + 1 - k; j++){
            q = p;
            p = p -> next;
        }
        return p;
    }
    
    //自方法
    ListNode* getKthFromEnd_2(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && k > 0) {
            fast = fast->next;
            k--;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
