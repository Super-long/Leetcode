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

/*
class Solution {
private:
    void reverseLinkedList(ListNode *head) {
        // 也可以使用递归反转一个链表
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode;
        // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
        // 建议写在 for 循环里，语义清晰
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        // 第 3 步：切断出一个子链表（截取链表）
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;

        // 注意：切断链接
        pre->next = nullptr;
        rightNode->next = nullptr;

        // 第 4 步：同第 206 题，反转链表的子区间
        reverseLinkedList(leftNode);

        // 第 5 步：接回到原来的链表中
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }
};
*/