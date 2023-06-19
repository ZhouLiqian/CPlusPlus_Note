//  code11.cpp
//  leetcode
//  合并两个排序的链表
//  Created by Qian on 6/19/23.

#include <iostream>
using namespace::std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

/*输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的*/

class Solution {
public:
    //方法一
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //空链表
        if(!l1 && !l2)
            return l1;
        vector<int> list_vector;
        ListNode *head = new ListNode(0);
        
        if(l1 == NULL && l2 != NULL){
            for(; l2; l2 = l2 -> next){
                list_vector.push_back(l2 -> val);
            }
            sort(list_vector.begin(), list_vector.end());
            ListNode *p = head;
            for(auto i = 0; i < list_vector.size(); i++){
                ListNode *s = new ListNode(0);
                s -> val = list_vector[i];
                s -> next = NULL;
                p -> next = s;
                p = s;
            }
        }
        
        if(l1 != NULL && l2 == NULL){
            for(; l1; l1 = l1 -> next){
                list_vector.push_back(l1 -> val);
            }
            sort(list_vector.begin(), list_vector.end());
            ListNode *p = head;
            for(auto i = 0; i < list_vector.size(); i++){
                ListNode *s = new ListNode(0);
                s -> val = list_vector[i];
                s -> next = NULL;
                p -> next = s;
                p = s;
            }
        }
        
        if(l1 != NULL && l2 != NULL){
            //链表合并
            for(; l1; l1 = l1 -> next){
                list_vector.push_back(l1 -> val);
            }
            for(; l2; l2 = l2 -> next){
                list_vector.push_back(l2 -> val);
            }
            sort(list_vector.begin(), list_vector.end());
            ListNode *p = head;
            for(auto i = 0; i < list_vector.size(); i++){
                ListNode *s = new ListNode(0);
                s -> val = list_vector[i];
                s -> next = NULL;
                p -> next = s;
                p = s;
            }
        }
        return head -> next;
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
