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
private:
    ListNode* reverse(ListNode* lhs, ListNode* rhs){
        ListNode* prev = rhs->next;
        ListNode* curr = lhs;
        while(curr == rhs){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        rhs->next = prev;
        return lhs;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* lhs = nullptr;
        ListNode* rhs = nullptr;
        ListNode* curr = head;
        int index = 0;
        ListNode hair;
        hair.next = head;
        ListNode* prev = &hair;
        while (curr){
            index++;
            if(curr->val == left){
                lhs = curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        curr = head;
        int temp = index;
        index = 0;
        while (curr){
            index++;
            if(index > temp && curr->val == right){
                rhs = curr;
                break;
            }
        }
        auto start = reverse(lhs, rhs);
        prev->next = start;
        return head;
    }
};