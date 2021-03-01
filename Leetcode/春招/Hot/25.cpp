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
    pair<ListNode*, ListNode*> reverse(ListNode *lhs, ListNode *rhs){    // 后面已经连起来了
        auto prev = rhs->next;
        auto p = lhs;
        while(prev != rhs){
            auto temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        return {rhs, lhs};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int itera = 0;
        ListNode node(0);
        ListNode* hair = &node;
        hair->next = head; 
        auto p = head;
        auto prev = hair;
        while(p){
            itera = k - 1;
            auto start = p;
            while(p->next && itera){
                p = p->next;
                itera--;
            }
            if(itera) return hair->next;
            auto end = p;
            auto res = reverse(start, end);
            
            prev->next = res.first;
            p = res.second->next;
            prev = res.second;
        }
        return hair->next;
    }
};