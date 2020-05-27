// 快照数组
#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
private:
    unordered_map<int, map<int, int>> data;
    int id;
public:
    SnapshotArray(int length){
        id = 0;
    }
    
    void set(int index, int val) {
        data[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        cout << "index : " << index << endl;
        auto it = data[index].upper_bound(snap_id);
        if(it == data[index].begin()){ // 蕴含着size == 0 的时候begin==end
            return 0;
        }
        cout << data[index].begin()->first << " " << data[index].begin()->second << endl;
        if(it == data[index].end()){
            cout << "true\n";
        }
        it--;
        return it->second;
    }
};

int main(){
    SnapshotArray snapshotArr(2);
    snapshotArr.set(0,15); 
    cout << snapshotArr.snap() << endl;  
    cout << snapshotArr.snap() << endl;
    cout << snapshotArr.snap() << endl;
    cout << snapshotArr.get(1,2) << endl; 
    cout << snapshotArr.snap() << endl;
    cout << snapshotArr.snap() << endl;
    cout << snapshotArr.get(0,0) << endl;

    return 0;
}