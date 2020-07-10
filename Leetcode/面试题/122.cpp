// 买卖股票的最佳时机 II

#include <bits/stdc++.h>
using namespace std;

/* class Solution {    // dp
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        vector<int> crash(prices.size());
        vector<int> hold(prices.size());
        // 可以搞成滚动数组
        crash[0] = 0;
        hold[0] = -prices[0];
        for(size_t i = 1; i < prices.size(); i++){
            crash[i] = max(crash[i-1], hold[i-1] + prices[i]);
            hold[i]  = max(hold[i-1], crash[i-1] - prices[i]); 
        }
        return crash[prices.size() - 1];
    }
}; */

// 波峰波谷
// 这算是比较简单的写法，把一个递增的区间看做几个连续的小段
class Solution {    
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int res = 0;
        for(size_t i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){   //也可以看做找到波谷
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};