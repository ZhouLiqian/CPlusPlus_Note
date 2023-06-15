//  code7.cpp
//  leetcode
//  回文链表
//  Created by Qian on 6/15/23.

#include <iostream>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 给定一个链表的头节点 head ，请判断其是否为回文链表
 如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //存入数组
        vector<int> empty_vector;
        for(; head; head = head -> next){
            empty_vector.push_back(head -> val);
        }
        //判断回文
        int flag = 0;
        for(int i = 0; i < empty_vector.size(); i++){
            if(empty_vector[i] != empty_vector[empty_vector.size() - i - 1]){
                return false;
                break;
            }
        }
        return true;
    }
};
