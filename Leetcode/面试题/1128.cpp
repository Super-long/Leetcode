#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> vis;
        int sum = 0;
        for(auto x : dominoes){
            if(x[0] > x[1]){
                swap(x[0], x[1]);
            }
            int temp = x[0]*10 + x[1];
            if(vis.find(temp) != vis.end()){
                sum += vis[temp];
            }
            vis[temp]++;
        }
        return sum;
    }
};