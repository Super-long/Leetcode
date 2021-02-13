#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {    // 非常经典的一道题，弗洛伊德判圈法
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* target = head;
        while(true){
            if(fast->next == nullptr) return nullptr;
            fast = fast->next;
            if(fast->next == nullptr) return nullptr;
            fast = fast->next;
            slow = slow->next;
            if(slow == fast){
                break;
            }
        }
        while(target != slow){
            target = target->next;
            slow = slow->next;
        }
        return target;
    }
};