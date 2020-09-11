#include <bits/stdc++.h>
using namespace std;

class Solution { //这个确实是比较吊的
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(!k) return vector<int>();
        int vis[10000+10];
        memset(vis, 0, sizeof(vis));
        for(auto x : arr){
            vis[x]++;
        }
        vector<int> vec;
        for(int i=0;i<10005;++i){
            if(vis[i]){
                for(int j=0;j<vis[i];++j){
                    vec.push_back(i);
                    --k;
                    if(!k) return vec;
                }
            }
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