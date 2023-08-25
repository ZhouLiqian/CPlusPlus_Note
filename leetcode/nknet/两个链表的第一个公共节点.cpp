//  两个链表的第一个公共节点.cpp
//  leetcode
//  双指针
//  Created by Qian on 8/21/23.

#include <iostream>
using namespace::std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //双指针
    ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB){
        ListNode* A = headA;
        ListNode* B = headB;
        while(A != B) {
            A = A != nullptr ? A -> next : headB;
            B = B != nullptr ? B -> next : headA;
        }
        return A;
    }
};
