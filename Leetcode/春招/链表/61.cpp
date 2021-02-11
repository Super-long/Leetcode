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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        if(!k) return head;
        ListNode* tail = nullptr;
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            if(temp->next == nullptr){
                tail = temp;
            }
            temp = temp->next;
        }
        if(count == 1) return head;
        temp = head;
        k %= count;
        if(k == 0) return head;
        count -= k + 1;
        while(count--){
            temp = temp->next;
        }
        ListNode* res = temp-> next;
        temp->next = nullptr;
        tail->next = head;
        
        return res;
    }
};