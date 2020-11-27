#include <bits/stdc++.h>
using namespace std;

class Solution {    // 这题也不能说是二分
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        int len = A.size();
        for(auto u : A){
            for(auto v : B){
                mp[u+v]++;
            }
        }

        int res = 0;
        for(auto u : C){
            for(auto v : D){
                if(mp.find(-u-v) != mp.end()){
                    res += mp[-u-v];
                }
            }
        }
        
        return res;
    }
};