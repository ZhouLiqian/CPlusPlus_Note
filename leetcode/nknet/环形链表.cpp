//  环形链表.cpp
//  leetcode
//  哈希表/双指针
//  Created by Qian on 8/23/23.

#include <iostream>
#include <unordered_map>
using namespace::std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    //哈希表
    ListNode *detectCycle_1(ListNode *head) {
        if(!head) return NULL;
        unordered_map<ListNode*, int> ma;
        ListNode* cur = head;
        int i = 0;
        while (cur) {
            if(ma.count(cur))
                return cur;
            ma[cur] = i;
            i++;
            cur = cur -> next;
        }
        return NULL;
    }
    
    //双指针
    ListNode *detectCycle_2(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (true) {
            if (fast == nullptr || fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
