#include <bits/stdc++.h>
using namespace std;

struct node{
    int key;
    int value;
    int frequent;
    node(int key, int value, int frequent) : key(key), value(value), frequent(frequent) {}
};

class LFUCache {
private:
    unordered_map<int, list<node>::iterator> table;
    unordered_map<int, list<node>> frequents;
    int capacity;
    int minfreq;
public:
    explicit LFUCache(int capacity) : capacity(capacity), minfreq(0) {}
    
    int get(int key) {
        if(table.find(key) == table.end() || !capacity) {return -1;}
        auto itera = table[key];
        auto val = itera->value;
        auto fre = itera->frequent;
        frequents[itera->frequent].erase(itera);
        if(frequents[fre].size() == 0 ){
            frequents.erase(fre);
            if(fre == minfreq) minfreq = fre + 1;
        }
        frequents[fre + 1].push_front(node(key, val, fre + 1));
        table[key] = frequents[fre + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if(!capacity) return;
        if(table.find(key) == table.end()) {    // 新插入
            if(frequents.size() + 1 > capacity){
                table.erase(frequents[minfreq].back().key);
                frequents[minfreq].pop_back();
                if(frequents[minfreq].size() == 0) frequents.erase(minfreq);
            }
            minfreq = 1;
            frequents[minfreq].push_front(node(key, value, 1));
            table[key] = frequents[minfreq].begin();
        } else {    // 修改值
            auto itera = table[key];
            auto fre = itera->frequent;
            frequents[itera->frequent].erase(itera);
            if(frequents[fre].size() == 0){
                frequents.erase(fre);
                if(fre == minfreq) minfreq = fre + 1;
            }
            frequents[fre + 1].push_front(node(key, value, fre + 1));
            table[key] = frequents[fre + 1].begin();    // 第一遍忘更新了
        }
    }
};

/*
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
*/

int main(){
    LFUCache sol(2);
    sol.put(1,1);
    sol.put(2,2);
    cout << sol.get(1) << endl;
    sol.put(3,3);
    cout << sol.get(2) << endl;
    cout << sol.get(3) << endl;
    sol.put(4,4);
    cout << sol.get(1) << endl;
    cout << sol.get(3) << endl;
    cout << sol.get(4) << endl;
    return 0;
}