// 环型链表II
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution { // 弗洛伊德判圈法
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != slow){
            if(fast->next != nullptr && fast->next->next != nullptr){
                fast = fast->next->next;
            } else {
                return nullptr;
                break;
            }
            slow = slow->next;
        }
        cout << slow->val << " " << fast->val << endl;
        fast = head; slow = slow->next;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main(){
    Solution sol;
    ListNode* head = new ListNode(0);
    ListNode* hair = head;
    vector<int> vec = {3,2,0,-4};
    for(size_t i = 0; i < vec.size(); i++){
        head->next = new ListNode(vec[i]);
        head = head->next;
    }
    head->next = hair->next->next;
    ListNode* res = sol.detectCycle(hair->next);
    cout << res->val << endl;
    return 0;
}