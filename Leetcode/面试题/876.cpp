//链表中间节点
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head,*slow;
        ListNode X(0);
        X.next = head; slow=&X;
        bool flag = false;
        while(fast!=NULL){
            fast=fast->next;
            if(!fast) flag = true; //证明链表是奇数
            else fast = fast->next;
            slow=slow->next;
        }
        if(flag) return slow;
        else return slow->next;
    }
};


int main(){

}