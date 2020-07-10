// 买卖股票的最佳时机 III
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        vector<int> first(prices.size());
        vector<int> second(prices.size());
        int minpre = prices.front();
        int maxpre = prices.back();
        int maxpri1 = 0;
        int maxpri2 = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] <= minpre){
                minpre = prices[i];
            } else {
                maxpri1 = max(maxpri1, prices[i] - minpre);
            }
            first[i] = maxpri1;

            if(prices[prices.size()-i-1] >= maxpre){
                maxpre = prices[prices.size()-i-1];
            } else {
                maxpri2 = max(maxpri2, maxpre - prices[prices.size()-i-1]);
            }
            second[prices.size()-i-1] = maxpri2;
        }

        int res = first[prices.size() - 1];
        for(size_t i = 0; i < prices.size() - 1; i++){
            res = max(res, first[i] + second[i+1]);
        }
        return res;        
    }
};