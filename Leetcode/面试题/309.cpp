// 最佳买卖股票时机含冷冻期
#include <bits/stdc++.h>
using namespace std;

class Solution {    
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int dp[10000 + 10][2];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 0;
        dp[1][1] = -prices[0];

        for(size_t i = 2; i <= prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i - 1]);
        }
        return dp[prices.size()][0];        
    }
};