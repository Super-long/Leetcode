#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex + 1, 0);
        dp[0] = 1;
        for (size_t i = 1; i <= rowIndex; i++){
            int prev = dp[0];
            for (size_t j = 1; j <= i; j++){
                auto temp = dp[j];
                dp[j] = prev + dp[j];
                prev = temp;

            }
        }
        return dp;
    }
};