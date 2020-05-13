// 按列翻转得到最大值等行数
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        int res = 0;
        for(auto& item : matrix){
            string Temp;
            int d = 1 ^ item[0];
            for(auto x : item){
                Temp += (d ^ x) + '0';
            }
            ++mp[Temp];
            res = max(res, mp[Temp]);
        }
        return res;
    }
};