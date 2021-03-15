#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        vector<int> dp(n, 0);
        if(n <= 1) return 1;
        if(n == 2) return 2;
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++){
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;
        }
        return dp.back();
    }
};