#include <bits/stdc++.h>
using namespace std;

//状态转移方程为 dp[i] = (j==cons.size())->min(dp[i-coins[j]],........);

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0; //特殊数据 {1} 0 
        vector<int> dp(amount+1, -1);
        sort(coins.begin(),coins.end());
        int num = coins.size();
        for(size_t i = 0; i < num; i++){
            if(coins[i] <= amount) //第一遍没考虑到
                dp[coins[i]] = 1;
        }
        for(size_t i = 1;i <= amount; i++){
            if(dp[i] == 1) continue; //已是最优解
            int temp = INT_MAX;
            for(size_t j = 0; j < num; j++){
                if(i > coins[j]){
                    if(dp[i-coins[j]] == -1) continue;
                    temp = min(temp, dp[i-coins[j]] + 1);
                }
                else
                    break;    
            }
            if(temp != INT_MAX)
                dp[i] = temp;
        }
        return dp[amount];     
    }
};

int main(){
    vector<int> vec({186,419,83,408});
    Solution sol;
    cout << sol.coinChange(vec,6249) << endl;
    return 0;
}