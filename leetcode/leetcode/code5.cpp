//  code5.cpp
//  leetcode
//  Created by Qian on 6/14/23.

#include <iostream>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //返回空
        if(!head || !head -> next)
            return head;
        //插入法
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *last_point = head;//head point
        ListNode *cur = head -> next;
        while(cur){
            //如果排序起点<=当前节点值，说明位置正确
            if(last_point -> val <= cur -> val){
                last_point = last_point -> next;
            }
            else//从开始往后遍历找到插入位置
            {
                ListNode *pre = dummy;
                while (pre -> next -> val <= cur -> val)
                    pre = pre -> next;
                last_point -> next = cur -> next;
                cur -> next = pre -> next;
                pre -> next = cur;
            }
            cur = last_point -> next;
        }
        head = dummy -> next;
        dummy = nullptr;
        delete dummy;
        return head;
    }
};
