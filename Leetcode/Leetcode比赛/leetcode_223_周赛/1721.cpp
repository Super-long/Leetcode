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
    ListNode* swapNodes(ListNode* head, int k) {
        auto temp = head;
        size_t len = 0;
        ListNode* lhs = nullptr;
        int count = 0;
        while(temp){
            len++;
            if(len == k) lhs = temp;
            temp = temp->next;
        }

        temp = head;
        count = len - k;
        len = 0;
        ListNode* rhs = nullptr;
        while(temp){
            len++;
            if(len == count) rhs = temp;
            temp = temp->next;
        }
        swap(lhs->val, rhs->val);
        return head;
    }
};