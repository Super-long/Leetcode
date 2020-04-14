// 两数相加 II
#include <bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        ListNode* temp = l1;
        while(temp){
            s1.push(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while(temp){
            s2.push(temp->val);
            temp = temp->next;
        }
        temp = new ListNode(0);        
        int vis = 0;
        while(!s1.empty() || !s2.empty()){
            int lhs = 0, rhs = 0;
            if(!s1.empty){
                lhs = s1.top(); s1.pop();
            }
            if(!s2.empty()){
                rhs = s2.top(); s2.pop();
            }
            temp->val = (lhs + rhs + vis)%10;
            vis = (lhs + rhs + vis)/10;
            temp->next = new ListNode(0);
        }
        return temp;
    }
};