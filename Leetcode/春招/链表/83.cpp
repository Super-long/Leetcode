#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {    // 这是去重，不是删重
        if(!head) return nullptr;
        ListNode  hair(INT_MIN);
        hair.next = head;
        ListNode* prev = &hair; // slow的前置指针
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast){
            if(fast->val == slow->val){
                fast = fast->next;
            } else {
                if(slow->next == fast){ // 证明两个元素不等
                    prev = slow;
                    slow = slow->next;
                } else {
                    prev->next = fast;

                    slow = fast;
                }
            }
        }
        if(slow->next != nullptr) prev->next = nullptr; // 预防这种特殊情况
 
        return hair.next;
    }
};