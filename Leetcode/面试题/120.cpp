// 三角形最小路径和
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(!n) return 0;
        if(n == 1) return triangle[0][0];
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = triangle[n-1][i];
        }
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};