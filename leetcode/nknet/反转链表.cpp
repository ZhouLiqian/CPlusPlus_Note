//  反转链表.cpp
//  leetcode
//  链表
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
    //双指针
    ListNode* reverseList_1(ListNode* head) {
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr) {
            ListNode* tmp = cur->next; // 暂存后继节点 cur.next
            cur->next = pre;           // 修改 next 引用指向
            pre = cur;                 // pre 暂存 cur
            cur = tmp;                 // cur 访问下一节点
        }
        return pre;
    }
    
    //递归
    ListNode* reverseList_2(ListNode* head) {
        return recur(head, nullptr);
    }
private:
    ListNode* recur(ListNode* cur, ListNode* pre){
        if(cur == nullptr) return pre;
        ListNode* res = recur(cur -> next, cur);
        cur -> next = pre;
        return res;
    }
};
