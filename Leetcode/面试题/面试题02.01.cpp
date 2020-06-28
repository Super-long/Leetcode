// 移除重复节点
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* First = head;
        while(First){
            ListNode* Temp = First->next;
            ListNode* pre = First;
            while(Temp){
                if(Temp->val == First->val){
                    pre->next = Temp->next; // 这里pre不变
                    Temp = Temp->next;
                    continue;
                }
                pre = Temp;
                Temp = Temp->next;
            }
            First = First->next;
        }
        return head;
    }
};