// LFU缓存
#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    int capacity;
    int offset;
            //操作次数 key  offsset value
    map<pair<int,int>, pair<int,int>> pool; 
    unordered_map<int,int> mp; // key对应最近使用次数 以构造上面的key部分
public:
    LFUCache(int capacity) : offset(0) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int temp = 0;
        if(mp.find(key) != mp.end()){
            temp = mp[key];
        }else{
            return -1;
        }
        pool[make_pair(key,temp)].second=-offset; // 更新版本号
        ++offset;
        return pool[make_pair(key,temp)].first;
    }
    
    void put(int key, int value) { // 插入 超过容量的时候的erase
        if(pool.size() == capacity){
            pool.erase(--pool.end());
        }

    }
};