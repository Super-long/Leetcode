// K 个一组翻转链表
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    pair<ListNode*, ListNode*> Reverse(ListNode* head, ListNode* tail){
        ListNode* prev;
        ListNode* p = head;
        while(prev != tail){
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return make_pair(tail, head);
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* prev = hair;
        while(head){
            ListNode* tail = prev;
            for(size_t i = 0; i < k; i++){
                tail = tail->next;
                if(!tail){ // 余出来的数直接顺序输出
                    return hair->next;
                }
            }
            auto next = tail->next;
            auto item = Reverse(head, tail);
            head = item.first;
            tail = item.second;
            prev->next = head;
            tail->next = next;

            prev = tail;
            head = tail->next;
        }
        return hair->next;
    }
};