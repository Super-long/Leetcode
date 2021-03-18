#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> cache;
    static constexpr int base = 1024;
    std::hash<int> hash_fn;
    int Return_hash(int key){
        return hash_fn(key) % base;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        cache.resize(base);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto& List = cache[Return_hash(key)];
        auto item = find_if(List.begin(), List.end(), [&](const pair<int,int>& para){
            return para.first == key;
        });
        if(item != List.end()){
            item->second = value;
        } else {
            List.emplace_back(make_pair(key, value));
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto& List = cache[Return_hash(key)];
        for(auto item : List){
            if(item.first == key){
                return item.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& List = cache[Return_hash(key)];
        auto item = find_if(List.begin(), List.end(), [&](const pair<int,int>& para){
            return para.first == key;
        });
        cout << item->second << endl;
        if(item != List.end()) {
            cout << "jiji\n";
            List.erase(item);
        }
    }
};

int main(){
    MyHashMap mp;
    mp.put(1,2);
    mp.put(2,3);
    mp.remove(1);
    cout << mp.get(2) << endl;
    return 0;
}