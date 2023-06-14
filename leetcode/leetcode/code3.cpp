//  code3.cpp
//  leetcode
//  Created by Qian on 6/14/23.

#include <iostream>
using namespace::std;

//结点声明
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> v;
        for(; head; head = head -> next){
            v.push_back(head -> val);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
