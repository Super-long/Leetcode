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
    ListNode* swapPairs(ListNode* head) {
        ListNode hair;
        hair.next = head;
        ListNode* prev = &hair; 
        while (head != nullptr){
            ListNode* first = head;
            ListNode* second = nullptr;
            if(first->next){    // 保证两项有效
                second = first->next;
            } else {
                break;          // 仅有一项
            }
            prev->next = second;
            first->next = second->next;
            second->next = first;
            head = first->next;
            prev = first;
        }
        return hair.next;
    }
};