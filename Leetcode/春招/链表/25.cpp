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
    pair<ListNode*, ListNode*> Reverse(ListNode* lhs, ListNode* rhs){   // 后面的链连上了
        ListNode* prev = rhs->next; // 反转链表标准操作
        ListNode* p = lhs;
        while (prev != rhs) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {rhs, lhs};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode hair(0);   // 其实初值没啥意义
        hair.next = head;
        ListNode* prev = &hair;
        int itear = 1;  // 默认持有head
        ListNode* lhs = head;
        while(head && head->next != nullptr){
            head = head->next;
            itear++;
            if(itear == k){
                ListNode* temp = head->next;
                cout << lhs->val << " " << head->val << endl;
                auto pa = Reverse(lhs, head);
                
                prev->next = pa.first;
                prev = pa.second;
                lhs = temp;
                head = temp;
                itear = 1;
            }
        }
        return hair.next;
    }
};