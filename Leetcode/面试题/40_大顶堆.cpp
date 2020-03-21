#include <bits/stdc++.h>
using namespace std;

class Solution { //使用大顶堆 Nlogk
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(!k) return vector<int>();
        priority_queue<int> que;
        for(int i=0;i<k;++i){
            que.push(arr[i]);
        }
        for(int i=k;i<arr.size();++i){
            if(arr[i] < que.top()){
                que.pop();
                que.push(arr[i]);
            }
        }
        vector<int>vec;
        for (int i = 0; i < k; ++i){
            vec.push_back(que.top());
            que.pop();
        }
        return vec; 
    }
};

int main(){
    Solution sol;
    vector<int> vec={0,0,0,2,0,5};//4,5,1,6,2,3,7,8
    auto pool = sol.getLeastNumbers(vec, 0);
    for(auto x : pool){
        cout << x << " ";
    }
    return 0;
}