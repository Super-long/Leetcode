// 跳水板
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(!k) return {};
        int n = k;
        int m = 0;
        vector<int> vec;
        while(m <= k){
            vec.push_back(shorter*n-- + longer*m++);
        }
        vec.erase(unique(vec.begin(), vec.end()));
        return vec;
    }
};