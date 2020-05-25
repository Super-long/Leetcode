// LRU缓存机制
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct DLinkedNode {
        int key, value;
        DLinkedNode* prev;
        DLinkedNode* next;
        DLinkedNode(): key(-1), value(-1), prev(nullptr), next(nullptr) {}
        DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
    };
    int capacity;
    unordered_map<int, DLinkedNode*> Cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int len; //双端链表数据段长度
    void Update(int key){
        DLinkedNode* Temp = Cache[key];

        Temp->prev->next = Temp->next; // 去除这个节点 把前后连接起来
        Temp->next->prev = Temp->prev;

        tail->prev->next = Temp; // 把节点插入到tail之前
        Temp->prev = tail->prev;

        Temp->next = tail;
        tail->prev = Temp;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        len = 0;
    }
    
    int get(int key) {
        if(Cache.find(key) == Cache.end()){
            DLinkedNode* Temp = new DLinkedNode();
            Cache[key] = Temp;
        }
        if(Cache[key]->value != -1){ // 把双端链表中的结点移动在链表尾部
            Update(key);
            return Cache[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        //cout << "kaishi\n";
        if(Cache.find(key) == Cache.end()){
            DLinkedNode* Temp = new DLinkedNode();
            Cache[key] = Temp;
        }
        if(Cache[key]->value == -1){ // 新加入的值 一个默认的构造函数
            //cout << "up\n";    
            len++;
            //DLinkedNode* Temp = new DLinkedNode(key, value);
            DLinkedNode* Temp = Cache[key];
            Temp->key = key; 
            Temp->value = value;

            tail->prev->next = Temp; // 把节点插入到tail之前
            Temp->prev = tail->prev;

            Temp->next = tail;
            tail->prev = Temp;
            //cout << "down\n";
            Cache[key] = Temp; //记录在cache中
        } else {
            Cache[key]->value = value;
            Update(key);
        }

        if(len > capacity){ // 删除链表头部块
            DLinkedNode* Temp = head->next;
            Temp->prev->next = Temp->next; 
            Temp->next->prev = Temp->prev;
            len--;
            Cache[Temp->key]->value = -1; //删除把key变成-1
        }
    }
    ~LRUCache(){ // leetcode中不需要写析构函数,会段错误的
        for(const auto& item : Cache){
            free(item.second);
        }
    }
};

int main(){
    LRUCache cache(2);
    cout << cache.get(0) << endl;
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cout << cache.get(2) << endl;;       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cout << cache.get(1) << endl;       // 返回 -1 (未找到)
    cout << cache.get(3) << endl;       // 返回  3
    cout << cache.get(4) << endl;;       // 返回  4 
    return 0;
}