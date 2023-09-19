//  合并两个链表.cpp
//  leetcode
//  模拟
//  Created by Qian on 9/19/23.

#include <iostream>
using namespace::std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL){}
    ListNode(int x) : val(x), next(NULL){}
    ListNode(int x, ListNode* next) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* listA = list1;
        for(int i = 0; i < a - 1; i++){
            listA = listA -> next;
        }
        ListNode* listB = listA;
        for(int j = a - 1; j < b + 1; j++){
            listB = listB -> next;
        }
        listA -> next = list2;
        while(list2 -> next != NULL){
            list2 = list2 -> next;
        }
        list2 -> next = listB;
        return list1;
    }
};
