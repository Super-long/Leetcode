#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(auto x : nums){
            hash[x]++;
        }
        using pa = pair<int,int>;
        priority_queue<pa,vector<pa>, less<pa>> que;
        for(auto x : hash){
            que.push(make_pair(x.second,x.first));
        }
        vector<int> vec;
        while(k--){
            cout << que.top().first << " " << que.top().second << endl;
            vec.push_back(que.top().second);
            que.pop();
        }
        return vec;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {-1, -1};
    auto x = sol.topKFrequent(vec, 1);
    for(auto item : x){
        cout << item << endl;
    }
    return 0;
}