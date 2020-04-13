// 合并K个排序链表
#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
ListNode* merage(ListNode* lhs, ListNode* rhs){
    if(!lhs) return rhs;
    if(!rhs) return lhs;
    if(lhs->val <= rhs->val){
        lhs->next = merage(lhs->next, rhs);
        return lhs;
    }else {
        rhs->next = merage(lhs, rhs->next);
        return rhs;
    }
}

ListNode* merage(vector<ListNode*>& value, int lhs, int rhs){
    if(lhs == rhs) return value[lhs];
    int mid = (lhs+rhs)/2;
    ListNode* up   = merage(value, lhs, mid);
    ListNode* down = merage(value, mid+1, rhs);
    return merage(up, down); 
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;
        return merage(lists, 0, lists.size() - 1);
    }
};

int main(){

}