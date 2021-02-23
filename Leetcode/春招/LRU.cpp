#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct ListNode{
        int val;
        int key;
        ListNode* next;
        ListNode* prev;
        ListNode(int val, int key) : val(val), key(key), next(nullptr), prev(nullptr){}
    };
    unordered_map<int, ListNode*> cache;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int Length = 0;
    const int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            auto temp = cache[key];
            if(temp == head) return cache[key]->val;
            if(temp == tail) {// temp是head什么也不需要做
                tail = tail->prev;
            } else {
                auto p = temp->prev;
                auto n = temp->next;
                p->next = n;
                n->prev = p;
            }
        } else {
            return -1;
        }
        auto temp = cache[key];
        temp->next = head;
        head->prev = temp;
        head = temp;
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
            auto node = new ListNode(value, key);
            if(head == nullptr){
                head = node;
                tail = node;
            } else {
                node->next = head;
                head->prev = node;
                head = node;
            }
            cache[key] = node;
            Length++;
        } else {
            get(key);
            cache[key]->val = value;
        }
        while(Length > capacity){
            Length--;
            if(head == tail){
                head == nullptr;
            } else if(head->next == tail){
                head->next = nullptr;
            }
            cache.erase(tail->key);
            auto temp = tail->prev;
            delete(tail);
            tail = temp;
        }
    }
};
/* ["LRUCache","put","put","put","put","get","get"]
[[2],[2,1],[1,1],[2,3],[4,1],[1],[2]] */

int main(){
    LRUCache sol(2);
    sol.put(2,1);
    sol.put(1,1);
    sol.put(2,3);
    sol.put(4,1);
    cout << sol.get(1) << endl;
    cout << sol.get(2) << endl;
    return 0;
}