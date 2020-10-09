#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        if(head->next == nullptr) return false;
        auto fast = head->next->next;
        auto slow = head->next;
        while(fast != nullptr && fast != slow){
            if(fast->next != nullptr)
                fast = fast->next->next;
            else return false;
            slow = slow->next;
        }
        return fast != nullptr;
    }
};