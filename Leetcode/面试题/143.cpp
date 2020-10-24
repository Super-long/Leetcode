#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 本地能跑通 oj跑不通
class Solution {    // 这题很好:链表中点，翻转链表，链表合并
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow就是中点

        ListNode* L1 = head;
        ListNode* L2 = slow->next;

        L2 = ReverseList(L2);

        MergeList(L1, L2);
        return;
    }

    ListNode* ReverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current != nullptr){
            auto temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }

    // 链表长度最多相差1
    void MergeList(ListNode* lhs, ListNode* rhs){
        ListNode* tempA = nullptr;
        ListNode* tempB = nullptr;
        // lhs大于等于rhs 且最大为1 直接合并就ok 
        while(lhs != nullptr && rhs != nullptr){
            tempA = lhs->next;
            tempB = rhs->next;

            lhs->next = rhs;
            lhs = tempA;

            rhs->next = lhs;
            rhs = tempB;
        }
    }
};

int main(){
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    Solution sol;
    sol.reorderList(a);
    cout << a->val << a->next->val << a->next->next->val << a->next->next->next->val << endl;
    return 0;
}