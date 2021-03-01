#include <bits/stdc++.h>
using namespace std;

class LRUCache {
list<pair<int, int>> li;
unordered_map<int, list<pair<int, int>>::iterator > pool;
int capacity;
public:
    LRUCache(int capacity) :capacity(capacity) {}
    
    int get(int key) {
        if(pool.find(key) == pool.end()) return -1;
        auto node = pool[key];
        int value = node->second;
        li.erase(node);
        li.push_front({key, value});
        pool[key] = li.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(pool.find(key) == pool.end()) {  // 需要插入一个新值
            if(pool.size() == capacity) {   // 驱逐一个值
                pool.erase(li.back().first);
                li.pop_back();
            }
            li.push_front({key, value});
            pool[key] = li.begin();
        } else {
            auto node = pool[key];
            li.erase(node);
            li.push_front({key, value});
            pool[key] = li.begin();
        }
    }
};

int main(){
    LRUCache sol(2);
    sol.put(1,1);
    sol.put(2,2);
    cout << sol.get(1) << endl;
    sol.put(3,3);
    cout << sol.get(2) << endl;
    sol.put(4,4);
    cout << sol.get(1) << endl;
    cout << sol.get(3) << endl;
    cout << sol.get(4) << endl;
    return 0;
}