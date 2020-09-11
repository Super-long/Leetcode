#include <bits/stdc++.h>
using namespace std;

/* class Solution {
private:
    int dfs(vector<int>& nums, int start, int end, int base){
        if(start == end){
            return nums[start] * base;
        }
        int lhs = nums[start]*base + dfs(nums, start + 1, end, -base);
        int rhs = nums[end]*base + dfs(nums, start, end - 1, -base);
        return max(lhs*base, rhs*base)*base;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1, 1) >= 0;
    }
}; */

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n+5][n+5];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }
        for(int i = n-2; i >= 0; --i){
            for (int j = i + 1; j < n; ++j){
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};
