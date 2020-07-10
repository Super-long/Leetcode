// 买卖股票的最佳时机 IV
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k > n/2){ // 相当于n等于无穷
            return infinity(prices);
        }
        // 第i天还可以买卖k次，0代表不持有股票 1代表持有股票
        int dp[prices.size()][k+1][2];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < prices.size(); i++){
            for(int j = 1; j <= k; j--){
                if(i == 0){ //基础数据
                    dp[i][j][0] = 0;    //第一天买入j次，当天卖出j次,收入为0
                    dp[i][j][1] = -prices[i];   //甭管第一天买多少次，反正最后少卖一次，持有了股票
                } else {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                }
            }
        }
        return dp[n-1][k][0];
    }

    // 当k视为无穷时使用，防止k太大导致三维dp数组太大
    int infinity(vector<int>& prices) {
        if(!prices.size()) return 0;
        int res = 0;
        for(size_t i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){   
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};