//  code12.cpp
//  leetcode
//  两个链表的第一个公共节点
//  Created by Qian on 6/20/23.

#include <iostream>
using namespace::std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*输入两个链表，找出它们的第一个公共节点*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q = headB;
        if(!p || !q)
            return NULL;
        int sum_A = 0, sum_B = 0;
        for(; headA; headA = headA -> next) sum_A++;
        for(; headB; headB = headB -> next) sum_B++;
        if(sum_A > sum_B){
            int diff = sum_A - sum_B;
            while (diff--) {
                p = p -> next;
            }
            while (p && q) {
                if(p == q){
                    return q;
                }
                else{
                    p = p -> next;
                    q = q -> next;
                }
            }
        }
        else{
            int diff = sum_B -sum_A;
            while (diff--) {
                q = q -> next;
            }
            while (p && q) {
                if(p == q){
                    return q;
                }
                else{
                    p = p -> next;
                    q = q -> next;
                }
            }
        }
        return NULL;
    }
};
