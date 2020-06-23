// 爬楼梯
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        vector<int> vec(n, 0);
        vec[0] = 1;
        vec[1] = 2;
        for(int i = 2; i < n; ++i){
            vec[i] = vec[i-1] + vec[i-2];
        }
        return vec[n-1];
    }
};
