//  最低票价
#include <bits/stdc++.h>
using namespace std;

// 这题我不会， 让我再写我也写不出来
class Solution {
    int mp[365] = {0};
    int cost[3];
    int dp[365];
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) { //正着写dp没办法写
        for(auto x : days){
            mp[x] = 1;
        }
        for(size_t i = 0; i < 3; i++){
            cost[i] = costs[i];
        }
        memset(dp, -1, sizeof dp);
        return dfs(1);
    }

    int dfs(int i){
        if(i > 365) return 0;
        if(dp[i] != -1) return dp[i];
        if(mp[i]){
            dp[i] = min(min(dp[i+1] + cost[0], dp[i+7] + cost[1]),dp[i+30]+cost[2]);
        }else {
            dp[i] = dfs(i+1);  //这一步看不懂
        }
        return dp[i];
    }
};