#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {    // 这题感觉和双指针不太沾边
public:
    ListNode* partition(ListNode* head, int x) {
        auto before_x = new ListNode(0);
        auto after_x = new ListNode(0);
        auto prev_before = before_x;
        auto prev_after = after_x;

        while(head != nullptr) {
            if(head->val < x){
                prev_before->next = head;
                prev_before = prev_before->next;
            } else {
                prev_after->next = head;
                prev_after = prev_after->next;
            }
            head = head->next;
        }

        // 这里踩了一个大陷阱，就是可能第二条链表中最后一个节点仍指向原来的下一点
        prev_after->next = nullptr;
        prev_before->next = after_x->next;
        return before_x->next;
    }
};

int main(){
    vector<int> vec = {1,4,3,2,5,2};
    ListNode* head = new ListNode(0);
    ListNode* hair = head;
    for (size_t i = 0; i < vec.size(); i++){
        ListNode* node = new ListNode(vec[i]);
        head->next = node;
        head = node;
    }

    Solution sol;
    auto res = sol.partition(hair->next, 3);
    while(res != nullptr){
        cout << res->val << endl;
        res = res->next;
        sleep(1);
    }
    return 0;
}