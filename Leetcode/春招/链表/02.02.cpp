#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* hair = head;
        while(k--){
            head = head->next;
        } 
        while(head){
            hair = hair->next;
            head = head->next;
        }
        return hair->val;
    }
};