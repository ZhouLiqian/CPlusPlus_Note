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
    
    ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
        //分别统计两链表节点个数
        ListNode* cur_A = headA;
        int count_A = 0;
        while(cur_A) {
            count_A++;
            cur_A = cur_A -> next;
        }
        ListNode* cur_B = headB;
        int count_B = 0;
        while(cur_B) {
            count_B++;
            cur_B = cur_B -> next;
        }
        
        //删除多余节点
        if(count_A > count_B){
            int more = count_A - count_B;
            while(more){
                headA = headA -> next;
                more--;
            }
        }
        else if(count_B > count_A){
            int more = count_B - count_A;
            while(more) {
                headB = headB -> next;
                more--;
            }
        }
        
        //遍历节点
        while (headA && headB) {
            if(headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
    
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
