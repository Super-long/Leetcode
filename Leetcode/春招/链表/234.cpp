#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* hair;
    bool flag = true;
    int dfs(ListNode* head){   // 初始传入链表的下半段
        if(!head) return -1;    // magic number
        cout << head->val << endl; 
        int sonValue = dfs(head->next);
        cout << "son : " << sonValue << endl;
        if(sonValue == -1) return head->val;
        if(sonValue != hair->val){
            flag = false;
        }
        hair = hair->next;
        return head->val;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode lhs(0), rhs(0);
        ListNode* slow = &lhs;
        ListNode* fast = &rhs;
        slow->next = head;
        fast->next = head;
        while(fast->next){
            fast = fast->next->next;
            if(!fast) break;    // fast为null代表为奇
            slow = slow->next;
        }
        hair = head;
        if(slow->next == nullptr) return true; 
        int sonValue = dfs(fast ? slow->next : slow->next->next);
        if(sonValue != -1 && sonValue != hair->val){
            flag = false;
        }
        return flag;
    }
};

class Solution {    // 这代码丑陋的我想哭
private:
    bool flag = true;
    ListNode* Reverse(ListNode* head, ListNode* tail){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != tail){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cout << curr->val << " - " <<tail->val << endl;
        }
        curr->next = prev;
        return curr;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        ListNode lhs(0), rhs(0);
        ListNode* slow = &lhs;
        ListNode* fast = &rhs;
        slow->next = head;
        fast->next = head;
        while(fast->next){
            fast = fast->next->next;
            if(!fast) break;    // fast为null代表为奇
            slow = slow->next;
        }
        if(slow->next == nullptr) return true; 
        auto second =  fast ? slow->next : slow->next->next;    // 找到后半部分的头结点
        
        auto tail = second;
        if(tail == nullptr) return true;
        while(tail->next) tail = tail->next;
        auto secondhead = Reverse(second, tail);
        tail = secondhead;

        while(tail){
            if(tail->val != head->val){
                flag = false;
                break;
            }
            tail = tail->next;
            head = head->next;
        }
        slow->next = Reverse(secondhead, second);
        return flag;
    }
};
/*
    ListNode* endOfFirstHalf(ListNode* head) {  // 求中点模板
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
*/