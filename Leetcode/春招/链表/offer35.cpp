#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> pool;
        auto temp = head;
        while(temp){
            pool[temp] = new Node(temp->val);
            temp = temp->next;
        }
        Node hair(0);
        Node* prev = &hair;
        temp = head;
        while(temp){
            auto item = pool[temp];
            item->next = pool[temp->next];
            item->random = pool[temp->random];
            prev->next = item;
            prev = prev->next;
        }
        return hair.next;
    }
};