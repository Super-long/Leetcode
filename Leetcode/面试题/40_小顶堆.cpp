#include <bits/stdc++.h>
using namespace std;

class Solution { //使用小顶堆 Nlog(N-k) 与大顶堆相比主要看k的值决定
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(!k) return vector<int>();
        priority_queue<int, vector<int>, greater<int>> que;
        for(int i=0;i<arr.size()-k;++i){
            que.push(arr[i]);
        }
        vector<int>vec;
        for(int i=arr.size()-k;i<arr.size();++i){
            que.push(arr[i]);
            vec.push_back(que.top());
            que.pop();
        }
        return vec; 
    }
};

int main(){
    Solution sol; //0,0,0,2,0,5 -> 0
    vector<int> vec={3,2,1};//4,5,1,6,2,3,7,8
    auto pool = sol.getLeastNumbers(vec, 2);
    for(auto x : pool){
        cout << x << " ";
    }
    return 0;
}