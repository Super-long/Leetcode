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
    ListNode* GetMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    pair<ListNode*, ListNode*> Reverse(ListNode* head, ListNode* tail){
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while(curr != tail){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        return make_pair(tail, head);
    }

public:
    bool isPalindrome(ListNode* head) {
        if(!head || head->next == nullptr) return true;
        auto middle = GetMiddle(head);
        auto secondStart = middle;
        while(secondStart->next != nullptr) {
            secondStart = secondStart->next;
        }
        auto item = Reverse(middle->next, secondStart);
        while(item.first){
            if(item.first->val != head->val){
                return false;
            }
            head = head->next;
            item.first = item.first->next;
        }
        return true;
    }
};